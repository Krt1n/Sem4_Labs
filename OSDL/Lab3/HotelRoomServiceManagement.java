class RoomServiceTask implements Runnable {

    private String serviceType;
    private String roomNumber;

    RoomServiceTask(String serviceType, String roomNumber) {
        this.serviceType = serviceType;
        this.roomNumber = roomNumber;
    }

    // run() method
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(serviceType + " for " + roomNumber +
                               " - Step " + i + " in progress");
            try {
                Thread.sleep(500); // Simulate processing time
            } catch (InterruptedException e) {
                System.out.println(serviceType + " interrupted for " + roomNumber);
            }
        }
        System.out.println(serviceType + " completed for " + roomNumber);
    }
}

public class HotelRoomServiceManagement {

    public static void main(String[] args) {

        // Creating service tasks
        RoomServiceTask cleaning = new RoomServiceTask("Room Cleaning", "Room 101");
        RoomServiceTask foodDelivery = new RoomServiceTask("Food Delivery", "Room 102");
        RoomServiceTask maintenance = new RoomServiceTask("Maintenance", "Room 103");

        // Creating threads
        Thread t1 = new Thread(cleaning);
        Thread t2 = new Thread(foodDelivery);
        Thread t3 = new Thread(maintenance);

        // Starting all threads simultaneously
        t1.start();
        t2.start();
        t3.start();

        System.out.println("All hotel service requests have started.");
    }
}
