import java.util.Scanner;

class Pair<T, U> {
    private T roomNumber;
    private U guestName;

    public Pair(T roomNumber, U guestName) {
        this.roomNumber = roomNumber;
        this.guestName = guestName;
    }

    public void display() {
        System.out.println("Room Number: " + roomNumber);
        System.out.println("Guest Name: " + guestName);
        System.out.println();
    }
}

public class BookingDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Room Number: ");
        int roomNumber1 = sc.nextInt();
        sc.nextLine();  // Consume newline
        System.out.print("Enter Guest Name for Room " + roomNumber1 + ": ");
        String guestName1 = sc.nextLine();

        System.out.print("Enter Another Room Number: ");
        int roomNumber2 = sc.nextInt();
        sc.nextLine();  // Consume newline
        System.out.print("Enter Guest Name for Room " + roomNumber2 + ": ");
        String guestName2 = sc.nextLine();

        Pair<Integer, String> booking1 = new Pair<>(roomNumber1, guestName1);
        Pair<Integer, String> booking2 = new Pair<>(roomNumber2, guestName2);

        booking1.display();
        booking2.display();

        sc.close();
    }
}