import java.util.*;

class Room {
    int roomNumber;
    String roomType;
    double price;
    boolean available;

    Room(int roomNumber, String roomType, double price) {
        this.roomNumber = roomNumber;
        this.roomType = roomType;
        this.price = price;
        this.available = true;
    }

    void displayRoom() {
        System.out.println("Room No: " + roomNumber +
                " | Type: " + roomType +
                " | Price: " + price +
                " | Available: " + available);
    }
}

class Customer {
    int customerId;
    String name;
    String contact;
    int roomNumber;

    Customer(int customerId, String name, String contact, int roomNumber) {
        this.customerId = customerId;
        this.name = name;
        this.contact = contact;
        this.roomNumber = roomNumber;
    }

    void displayCustomer() {
        System.out.println("Customer ID: " + customerId +
                " | Name: " + name +
                " | Contact: " + contact +
                " | Room No: " + roomNumber);
    }
}

public class HotelSystem {

    static ArrayList<Room> rooms = new ArrayList<>();
    static ArrayList<Customer> customers = new ArrayList<>();
    static HashMap<Integer, Customer> bookings = new HashMap<>();

    static Scanner sc = new Scanner(System.in);

    static void addRoom() {
        System.out.print("Enter Room Number: ");
        int number = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Room Type: ");
        String type = sc.nextLine();

        System.out.print("Enter Price per Day: ");
        double price = sc.nextDouble();

        rooms.add(new Room(number, type, price));
        System.out.println("Room added successfully!");
    }

    static void displayAvailableRooms() {
        System.out.println("\nAvailable Rooms:");
        Iterator<Room> itr = rooms.iterator();

        while (itr.hasNext()) {
            Room r = itr.next();
            if (r.available) {
                r.displayRoom();
            }
        }
    }

    static void addCustomer() {
        System.out.print("Enter Customer ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Contact Number: ");
        String contact = sc.nextLine();

        customers.add(new Customer(id, name, contact, 0));
        System.out.println("Customer added successfully!");
    }

    static void bookRoom() {
        System.out.print("Enter Customer ID: ");
        int id = sc.nextInt();

        System.out.print("Enter Room Number: ");
        int roomNo = sc.nextInt();

        Room selectedRoom = null;

        for (Room r : rooms) {
            if (r.roomNumber == roomNo && r.available) {
                selectedRoom = r;
                break;
            }
        }

        if (selectedRoom == null) {
            System.out.println("Room not available!");
            return;
        }

        for (Customer c : customers) {
            if (c.customerId == id) {
                c.roomNumber = roomNo;
                selectedRoom.available = false;
                bookings.put(roomNo, c);
                System.out.println("Room booked successfully!");
                return;
            }
        }

        System.out.println("Customer not found!");
    }

    static void checkoutCustomer() {
        System.out.print("Enter Room Number: ");
        int roomNo = sc.nextInt();

        if (bookings.containsKey(roomNo)) {
            bookings.remove(roomNo);

            for (Room r : rooms) {
                if (r.roomNumber == roomNo) {
                    r.available = true;
                }
            }

            System.out.println("Checkout successful!");
        } else {
            System.out.println("No booking found for this room.");
        }
    }

    static void displayCustomers() {
        System.out.println("\nCustomer List:");
        Iterator<Customer> itr = customers.iterator();

        while (itr.hasNext()) {
            Customer c = itr.next();
            c.displayCustomer();
        }
    }

    public static void main(String[] args) {

        int choice;

        do {
            System.out.println("\n===== HOTEL MANAGEMENT MENU =====");
            System.out.println("1. Add Room");
            System.out.println("2. Display Available Rooms");
            System.out.println("3. Add Customer");
            System.out.println("4. Book Room");
            System.out.println("5. Checkout Customer");
            System.out.println("6. Display All Customers");
            System.out.println("7. Exit");

            System.out.print("Enter Choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addRoom();
                    break;
                case 2:
                    displayAvailableRooms();
                    break;
                case 3:
                    addCustomer();
                    break;
                case 4:
                    bookRoom();
                    break;
                case 5:
                    checkoutCustomer();
                    break;
                case 6:
                    displayCustomers();
                    break;
                case 7:
                    System.out.println("Exiting system...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 7);
    }
}
