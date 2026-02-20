import java.io.*;

public class HotelManagementRAF {
    private static final int RECORD_SIZE = 53; // 4 + 40 + 8 + 1
    private static final String FILE_NAME = "hotel_rooms.dat";

    public static void main(String[] args) {
        // Example Usage
        addRoom(1, "Deluxe", 150.0, false);
        addRoom(2, "Suite", 300.0, true);
        
        System.out.println("--- Reading Room 2 ---");
        displayRoom(2);

        System.out.println("\n--- Updating Room 1 Status to Booked ---");
        updateStatus(1, true);
        displayRoom(1);
    }

    public static void addRoom(int id, String type, double price, boolean status) {
        try (RandomAccessFile raf = new RandomAccessFile(FILE_NAME, "rw")) {
            raf.seek(raf.length()); // Go to end of file
            raf.writeInt(id);
            
            // Ensure fixed length for String (20 chars = 40 bytes in UTF-16)
            StringBuilder sb = new StringBuilder(type);
            sb.setLength(20); 
            raf.writeChars(sb.toString());
            
            raf.writeDouble(price);
            raf.writeBoolean(status);
            System.out.println("Room " + id + " added.");
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public static void displayRoom(int roomNum) {
        try (RandomAccessFile raf = new RandomAccessFile(FILE_NAME, "r")) {
            boolean found = false;
            while (raf.getFilePointer() < raf.length()) {
                int id = raf.readInt();
                if (id == roomNum) {
                    String type = "";
                    for(int i=0; i<20; i++) type += raf.readChar();
                    double price = raf.readDouble();
                    boolean status = raf.readBoolean();
                    
                    System.out.println("Room: " + id + " | Type: " + type.trim() + 
                                       " | Price: $" + price + " | Booked: " + status);
                    found = true;
                    break;
                }
                raf.skipBytes(RECORD_SIZE - 4); // Jump to next record
            }
            if (!found) System.out.println("Room not found.");
        } catch (IOException e) {
            System.out.println("Read Error: " + e.getMessage());
        }
    }

    public static void updateStatus(int roomNum, boolean newStatus) {
        try (RandomAccessFile raf = new RandomAccessFile(FILE_NAME, "rw")) {
            while (raf.getFilePointer() < raf.length()) {
                long pos = raf.getFilePointer();
                int id = raf.readInt();
                if (id == roomNum) {
                    // Skip type (40 bytes) and price (8 bytes) to reach status
                    raf.seek(pos + 4 + 40 + 8); 
                    raf.writeBoolean(newStatus);
                    System.out.println("Status updated for Room " + roomNum);
                    return;
                }
                raf.skipBytes(RECORD_SIZE - 4);
            }
        } catch (IOException e) {
            System.out.println("Update Error: " + e.getMessage());
        }
    }
}