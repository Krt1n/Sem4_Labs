class OrderTask implements Runnable {

    private String orderId;

    OrderTask(String orderId) {
        this.orderId = orderId;
    }

    public void run() {

        try {
            System.out.println(orderId + " - Order validation started");
            Thread.sleep(500);

            System.out.println(orderId + " - Payment processing started");
            Thread.sleep(500);

            System.out.println(orderId + " - Order shipment started");
            Thread.sleep(500);

            System.out.println(orderId + " - Order completed successfully");

        } catch (InterruptedException e) {
            System.out.println(orderId + " - Order processing interrupted");
        }
    }
}

public class OnlineOrderProcessingSystem {

    public static void main(String[] args) {

        OrderTask order1 = new OrderTask("Order #1001");
        OrderTask order2 = new OrderTask("Order #1002");
        OrderTask order3 = new OrderTask("Order #1003");

        Thread t1 = new Thread(order1);
        Thread t2 = new Thread(order2);
        Thread t3 = new Thread(order3);

        t1.start();
        t2.start();
        t3.start();

        System.out.println("All orders are being processed concurrently.");
    }
}
