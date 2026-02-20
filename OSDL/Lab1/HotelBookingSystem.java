package Lab1;

class Room {
    int roomNumber;
    double baseTariff;

    public Room(int roomNumber, double baseTariff) {
        this.roomNumber = roomNumber;
        this.baseTariff = baseTariff;
    }

    public double calculateTariff() {
        return baseTariff;
    }
}

class StandardRoom extends Room {
    boolean airConditioned;

    public StandardRoom(int roomNumber, double baseTariff, boolean airConditioned) {
        super(roomNumber, baseTariff);
        this.airConditioned = airConditioned;
    }

    public double calculateTariff() {
        if (airConditioned) {
            return baseTariff + 500;
        }
        return baseTariff;
    }
}

class LuxuryRoom extends Room {
    boolean premiumServices;

    public LuxuryRoom(int roomNumber, double baseTariff, boolean premiumServices) {
        super(roomNumber, baseTariff);
        this.premiumServices = premiumServices;
    }

    public double calculateTariff() {
        if (premiumServices) {
            return baseTariff + 2000;
        }
        return baseTariff;
    }
}

public class HotelBookingSystem {
    public static void main(String[] args) {

        Room room;

        room = new StandardRoom(101, 3000, true);
        System.out.println("Standard Room Tariff: " + room.calculateTariff());

        room = new LuxuryRoom(201, 5000, true);
        System.out.println("Luxury Room Tariff: " + room.calculateTariff());
    }
}
