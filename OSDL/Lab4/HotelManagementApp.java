class Hotel {
    private int totalRooms;
    private int availableRooms;

    public Hotel(int totalRooms) {
        this.totalRooms = totalRooms;
        this.availableRooms = totalRooms;
    }

    public synchronized void bookRoom(String customerName) {
        while (availableRooms == 0) {
            try {
                System.out.println(customerName + " is waiting for a room...");
                wait(); // wait until a room is released
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        availableRooms--;
        System.out.println(customerName + " booked a room. Rooms left: " + availableRooms);
    }

    public synchronized void releaseRoom(String customerName) {
        availableRooms++;
        System.out.println(customerName + " released a room. Rooms left: " + availableRooms);
        notifyAll(); // notify waiting threads that a room is available
    }
}

class CustomerThread extends Thread {
    private Hotel hotel;
    private String customerName;

    public CustomerThread(Hotel hotel, String customerName) {
        this.hotel = hotel;
        this.customerName = customerName;
    }

    public void run() {
        hotel.bookRoom(customerName);

        try {
            // Simulate stay duration
            Thread.sleep((long) (Math.random() * 3000));
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        hotel.releaseRoom(customerName);
    }
}

// Main class
public class HotelManagementApp {
    public static void main(String[] args) {
        Hotel hotel = new Hotel(3); // Hotel with 3 rooms

        // Multiple customers trying to book simultaneously
        for (int i = 1; i <= 6; i++) {
            CustomerThread customer = new CustomerThread(hotel, "Customer-" + i);
            customer.start();
        }
    }
}
