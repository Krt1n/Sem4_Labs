//Q1

class Room<T, U> {
    private T roomId;
    private U attribute;

    public Room(T roomId, U attribute) {
        this.roomId = roomId;
        this.attribute = attribute;
    }

    public void display() {
        System.out.println("Room ID: " + roomId);
        System.out.println("Attribute: " + attribute);
        System.out.println();
    }
}

public class RoomDemo {
    public static void main(String[] args) {

        Room<Integer, String> r1 = new Room<>(101, "Deluxe");
        Room<String, Double> r2 = new Room<>("A102", 4500.75);

        r1.display();
        r2.display();
    }
}