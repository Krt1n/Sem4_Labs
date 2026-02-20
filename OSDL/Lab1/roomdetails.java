package Lab1;
class Room {
    int roomNumber;
    String roomType;
    double basePrice;

    public Room(int roomNumber, String roomType) {
        this.roomNumber = roomNumber;
        this.roomType = roomType;
        this.basePrice = 0.0;
    }

    public Room(int roomNumber, String roomType, double basePrice) {
        this.roomNumber = roomNumber;
        this.roomType = roomType;
        this.basePrice = basePrice;
    }

    public void displayRoomDetails() {
        System.out.println("Room Number : " + roomNumber);
        System.out.println("Room Type   : " + roomType);
        System.out.println("Base Price  : " + basePrice);
    }
}

class DeluxeRoom extends Room {
    boolean freeWifi;
    boolean complimentaryBreakfast;

    public DeluxeRoom(int roomNumber, String roomType,
                      boolean freeWifi, boolean complimentaryBreakfast) {
        super(roomNumber, roomType);
        this.freeWifi = freeWifi;
        this.complimentaryBreakfast = complimentaryBreakfast;
    }

    public DeluxeRoom(int roomNumber, String roomType, double basePrice,
                      boolean freeWifi, boolean complimentaryBreakfast) {
        super(roomNumber, roomType, basePrice);
        this.freeWifi = freeWifi;
        this.complimentaryBreakfast = complimentaryBreakfast;
    }

    public void displayRoomDetails() {
        super.displayRoomDetails();
        System.out.println("Free Wi-Fi  : " + freeWifi);
        System.out.println("Breakfast  : " + complimentaryBreakfast);
    }
}

public class roomdetails {
    public static void main(String[] args) {

        Room r1 = new Room(101, "Standard");
        Room r2 = new Room(102, "Standard", 2500);

        DeluxeRoom d1 = new DeluxeRoom(201, "Deluxe", true, true);
        DeluxeRoom d2 = new DeluxeRoom(202, "Deluxe", 4500, true, false);

        System.out.println("---- Room 1 ----");
        r1.displayRoomDetails();

        System.out.println("\n---- Room 2 ----");
        r2.displayRoomDetails();

        System.out.println("\n---- Deluxe Room 1 ----");
        d1.displayRoomDetails();

        System.out.println("\n---- Deluxe Room 2 ----");
        d2.displayRoomDetails();
    }
}
