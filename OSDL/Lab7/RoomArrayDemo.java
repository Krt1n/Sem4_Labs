import java.util.Scanner;

class RoomArrayDemo {

    public static <T> void printArray(T[] array) {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of rooms: ");
        int n = sc.nextInt();

        Integer[] roomNumbers = new Integer[n];
        String[] roomTypes = new String[n];
        Double[] roomPrices = new Double[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter Room Number " + (i+1) + ": ");
            roomNumbers[i] = sc.nextInt();
            sc.nextLine();  // Consume newline
            System.out.print("Enter Room Type " + (i+1) + ": ");
            roomTypes[i] = sc.nextLine();
            System.out.print("Enter Room Price " + (i+1) + ": ");
            roomPrices[i] = sc.nextDouble();
        }

        printArray(roomNumbers);
        printArray(roomTypes);
        printArray(roomPrices);

        sc.close();
    }
}