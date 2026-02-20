import java.io.*;
import java.util.*;

class Room implements Serializable {
    private static final long serialVersionUID = 1L;
    int roomNumber;
    String type;
    double price;
    boolean isBooked;
    String guestName;

    Room(int rn, String t, double p, boolean b, String g) {
        this.roomNumber = rn;
        this.type = t;
        this.price = p;
        this.isBooked = b;
        this.guestName = g;
    }

    public String toString() {
        return "Room " + roomNumber + " [" + type + "] - $" + price + 
               " | Booked: " + isBooked + " | Guest: " + guestName;
    }
}

public class HotelApp {
    private static final String FILE_NAME = "rooms.ser";

    public static void main(String[] args) {
        List<Room> rooms = new ArrayList<>();
        rooms.add(new Room(101, "Single", 100.0, true, "Alice"));
        rooms.add(new Room(102, "Double", 180.0, false, "None"));

        // 1. Serialize
        saveRooms(rooms);

        // 2. Deserialize & Display
        System.out.println("All Rooms:");
        List<Room> loadedRooms = loadRooms();
        loadedRooms.forEach(System.out::println);

        // 3. Update status (e.g., Room 102)
        updateRoomStatus(102, true, "Bob");
        
        System.out.println("\nAfter Update:");
        loadRooms().forEach(System.out::println);
    }

    public static void saveRooms(List<Room> rooms) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(FILE_NAME))) {
            oos.writeObject(rooms);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @SuppressWarnings("unchecked")
    public static List<Room> loadRooms() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(FILE_NAME))) {
            return (List<Room>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return new ArrayList<>();
        }
    }

    public static void updateRoomStatus(int roomNum, boolean status, String guest) {
        List<Room> rooms = loadRooms();
        for (Room r : rooms) {
            if (r.roomNumber == roomNum) {
                r.isBooked = status;
                r.guestName = guest;
                break;
            }
        }
        saveRooms(rooms); // Re-serialize the whole list
    }
}