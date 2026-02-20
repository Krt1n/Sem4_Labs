package Lab1;

interface RoomAmenities {
    void provideWifi();
    void provideBreakfast();
}

abstract class HotelRoom {
    protected int roomNumber;
    protected double basePrice;

    public HotelRoom(int roomNumber, double basePrice) {
        this.roomNumber = roomNumber;
        this.basePrice = basePrice;
    }

    public abstract double calculateTariff();

    public void displayRoomDetails() {
        System.out.println("Room Number : " + roomNumber);
        System.out.println("Base Price  : " + basePrice);
    }
}

class StandardHotelRoom extends HotelRoom implements RoomAmenities {

    public StandardHotelRoom(int roomNumber, double basePrice) {
        super(roomNumber, basePrice);
    }

    public double calculateTariff() {
        return basePrice;
    }

    public void provideWifi() {
        System.out.println("WiFi : Available (Standard)");
    }

    public void provideBreakfast() {
        System.out.println("Breakfast : Not Included");
    }
}

class LuxuryHotelRoom extends HotelRoom implements RoomAmenities {

    public LuxuryHotelRoom(int roomNumber, double basePrice) {
        super(roomNumber, basePrice);
    }

    public double calculateTariff() {
        return basePrice + (basePrice * 0.40);
    }


    public void provideWifi() {
        System.out.println("WiFi : High Speed");
    }

    public void provideBreakfast() {
        System.out.println("Breakfast : Complimentary");
    }
}


public class HotelAbstractionDemo {
    public static void main(String[] args) {

        HotelRoom r1 = new StandardHotelRoom(301, 2000);
        HotelRoom r2 = new LuxuryHotelRoom(401, 5000);

        System.out.println("---- Standard Hotel Room ----");
        r1.displayRoomDetails();
        System.out.println("Tariff : " + r1.calculateTariff());
        ((RoomAmenities) r1).provideWifi();
        ((RoomAmenities) r1).provideBreakfast();

        System.out.println("\n---- Luxury Hotel Room ----");
        r2.displayRoomDetails();
        System.out.println("Tariff : " + r2.calculateTariff());
        ((RoomAmenities) r2).provideWifi();
        ((RoomAmenities) r2).provideBreakfast();
    }
}
