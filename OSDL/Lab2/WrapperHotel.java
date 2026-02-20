package Lab2;

class wrapper {
    int numberOfDays;
    double roomTariff;
    double serviceCharge;
    Integer numberOfDaysObj;
    Double roomTariffObj;
    Double serviceChargeObj;
    
    wrapper(int numberOfDays, double roomTariff, double serviceCharge) {
        this.numberOfDays = numberOfDays;
        this.roomTariff = roomTariff;
        this.serviceCharge = serviceCharge; 

        numberOfDaysObj = numberOfDays;      
        roomTariffObj = roomTariff;          
        serviceChargeObj = serviceCharge;    
    }

    double calc() {
        double roomTotal = roomTariffObj * numberOfDaysObj; 
        return roomTotal + serviceChargeObj;                 
    }

    void displayBill() {
        double total = calc();
        System.out.println("Days: " + numberOfDaysObj);
        System.out.println("Room Tariff: " + roomTariffObj);
        System.out.println("Service: " + serviceChargeObj);
        System.out.println("Total Bill: " + total);
    }
}

public class WrapperHotel {
    public static void main(String[] args) {
        wrapper guest = new wrapper(3, 2500, 800);
        guest.displayBill();
    }
}

