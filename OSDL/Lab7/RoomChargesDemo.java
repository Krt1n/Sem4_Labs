import java.util.Scanner;

class RoomCharges<T extends Number> {
    private T price;
    private T discount;

    public RoomCharges(T price, T discount) {
        this.price = price;
        this.discount = discount;
    }

    public double totalPrice() {
        return price.doubleValue();
    }

    public double discountedPrice() {
        return price.doubleValue() - discount.doubleValue();
    }
}

public class RoomChargesDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Room Price (Double): ");
        double price = sc.nextDouble();
        System.out.print("Enter Discount (Double): ");
        double discount = sc.nextDouble();

        RoomCharges<Double> room = new RoomCharges<>(price, discount);

        System.out.println("Total Price: " + room.totalPrice());
        System.out.println("Discounted Price: " + room.discountedPrice());

        sc.close();
    }
}