//Q2

import java.util.Scanner;

class RoomDataDisplay {

    public static <T> void display(T data) {
        System.out.println("Data: " + data);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Room Number (Integer): ");
        int roomNumber = sc.nextInt();
        sc.nextLine();  // Consume newline
        System.out.print("Enter Room Type (String): ");
        String roomType = sc.nextLine();
        System.out.print("Enter Price per night (Double): ");
        double price = sc.nextDouble();
        System.out.print("Enter Booking Status (Boolean): ");
        boolean status = sc.nextBoolean();

        display(roomNumber);
        display(roomType);
        display(price);
        display(status);

        sc.close();
    }
}