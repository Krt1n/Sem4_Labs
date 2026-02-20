package Lab2;


// Enum
enum fruits {
    // Attributes associated to enum
    Apple(120),
    Kiwi(60),
    Banana(20),
    Orange(80);

    // internal data
    private int price;

    // Constructor
    fruits(int pr) { price = pr; }

    // Method
    int totalPrice() { return price; }
}


// Main class
class Testing {

    // main driver method
    public static void main(String[] args)
    {
        // Print statement
        System.out.println("Total price of fruits : ");

        // Iterating using enhanced for each loop
        for (fruits f : fruits.values())

            // Print and display the cost and per kg cost of
            // fruits
            System.out.println(f + " costs " + f.totalPrice() + " rupees per kg.");
    }
}
