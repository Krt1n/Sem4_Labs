package Lab2;

// Enum with constructor and methods
enum RoomType {

STANDARD(2000),
DELUXE(3500),
SUITE(5000);

private int pricePerNight;

RoomType(int pricePerNight) {
this.pricePerNight = pricePerNight;
}

public int getPricePerNight() {
return pricePerNight;
}

public int calculateCost(int nights) {
return pricePerNight * nights;
}
}

public class EnumHotel {
    public static void main(String[] args) {
RoomType room = RoomType.DELUXE;
int nights = 3;
System.out.println("Room Type :" + room);
System.out.println("Price per Night : " + room.getPricePerNight());
System.out.println("Number of Nights: " + nights);
System.out.println("Total Cost : "+ room.calculateCost(nights));
}
}

