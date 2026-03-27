import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.*;
import javafx.stage.Stage;

public class HotelManagementFX extends Application {

    // Room class
    public static class Room {
        private int roomNumber;
        private String type;
        private double price;
        private boolean available;

        public Room(int roomNumber, String type, double price, boolean available) {
            this.roomNumber = roomNumber;
            this.type = type;
            this.price = price;
            this.available = available;
        }

        public int getRoomNumber() { return roomNumber; }
        public String getType() { return type; }
        public double getPrice() { return price; }
        public boolean isAvailable() { return available; }

        public void setAvailable(boolean available) { this.available = available; }
    }

    // List to store rooms
    private ObservableList<Room> roomList = FXCollections.observableArrayList();

    @Override
    public void start(Stage stage) {

        // ----------- TABLE VIEW -----------
        TableView<Room> table = new TableView<>();

        TableColumn<Room, Integer> colNumber = new TableColumn<>("Room No");
        colNumber.setCellValueFactory(new PropertyValueFactory<>("roomNumber"));

        TableColumn<Room, String> colType = new TableColumn<>("Type");
        colType.setCellValueFactory(new PropertyValueFactory<>("type"));

        TableColumn<Room, Double> colPrice = new TableColumn<>("Price");
        colPrice.setCellValueFactory(new PropertyValueFactory<>("price"));

        TableColumn<Room, Boolean> colAvailable = new TableColumn<>("Available");
        colAvailable.setCellValueFactory(new PropertyValueFactory<>("available"));

        table.getColumns().addAll(colNumber, colType, colPrice, colAvailable);
        table.setItems(roomList);

        // ----------- ROOM INPUT -----------
        TextField txtRoomNo = new TextField();
        TextField txtPrice = new TextField();
        ComboBox<String> cmbType = new ComboBox<>();
        cmbType.getItems().addAll("Single", "Double", "Deluxe");

        Button btnAddRoom = new Button("Add Room");

        // Add Room Event
        btnAddRoom.setOnAction(e -> {
            try {
                int number = Integer.parseInt(txtRoomNo.getText());
                double price = Double.parseDouble(txtPrice.getText());
                String type = cmbType.getValue();

                roomList.add(new Room(number, type, price, true));

                txtRoomNo.clear();
                txtPrice.clear();
                cmbType.setValue(null);

            } catch (Exception ex) {
                showAlert("Error", "Invalid input!");
            }
        });

        // ----------- BOOKING SECTION -----------
        TextField txtCustomer = new TextField();
        TextField txtContact = new TextField();
        TextField txtBookRoom = new TextField();

        Button btnBook = new Button("Book Room");

        btnBook.setOnAction(e -> {
            int roomNo = Integer.parseInt(txtBookRoom.getText());

            for (Room r : roomList) {
                if (r.getRoomNumber() == roomNo) {
                    if (r.isAvailable()) {
                        r.setAvailable(false);
                        table.refresh();
                        showAlert("Success", "Room booked for " + txtCustomer.getText());
                    } else {
                        showAlert("Error", "Room already booked!");
                    }
                    return;
                }
            }
            showAlert("Error", "Room not found!");
        });

        // ----------- CHECKOUT -----------
        TextField txtCheckout = new TextField();
        Button btnCheckout = new Button("Checkout");

        btnCheckout.setOnAction(e -> {
            int roomNo = Integer.parseInt(txtCheckout.getText());

            for (Room r : roomList) {
                if (r.getRoomNumber() == roomNo) {
                    r.setAvailable(true);
                    table.refresh();
                    showAlert("Success", "Room checked out!");
                    return;
                }
            }
            showAlert("Error", "Room not found!");
        });

        // ----------- LAYOUTS -----------

        GridPane roomForm = new GridPane();
        roomForm.setHgap(10);
        roomForm.setVgap(10);

        roomForm.add(new Label("Room No:"), 0, 0);
        roomForm.add(txtRoomNo, 1, 0);
        roomForm.add(new Label("Type:"), 0, 1);
        roomForm.add(cmbType, 1, 1);
        roomForm.add(new Label("Price:"), 0, 2);
        roomForm.add(txtPrice, 1, 2);
        roomForm.add(btnAddRoom, 1, 3);

        GridPane bookingForm = new GridPane();
        bookingForm.setHgap(10);
        bookingForm.setVgap(10);

        bookingForm.add(new Label("Customer Name:"), 0, 0);
        bookingForm.add(txtCustomer, 1, 0);
        bookingForm.add(new Label("Contact:"), 0, 1);
        bookingForm.add(txtContact, 1, 1);
        bookingForm.add(new Label("Room No:"), 0, 2);
        bookingForm.add(txtBookRoom, 1, 2);
        bookingForm.add(btnBook, 1, 3);

        HBox checkoutBox = new HBox(10, new Label("Checkout Room No:"), txtCheckout, btnCheckout);

        VBox root = new VBox(15,
                new Label("Room Management"),
                roomForm,
                new Label("Booking"),
                bookingForm,
                checkoutBox,
                new Label("Room Details"),
                table
        );

        root.setPadding(new Insets(15));

        Scene scene = new Scene(root, 600, 600);
        stage.setTitle("Hotel Management System");
        stage.setScene(scene);
        stage.show();
    }

    // Alert method
    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setContentText(message);
        alert.showAndWait();
    }

    public static void main(String[] args) {
        launch();
    }
}

// javac --module-path "D:\240911550\openjfx-21.0.10_windows-x64_bin-sdk\javafx-sdk-21.0.10\lib" --add-modules javafx.controls HotelManagementFX.java
// java --module-path "D:\240911550\openjfx-21.0.10_windows-x64_bin-sdk\javafx-sdk-21.0.10\lib" --add-modules javafx.controls HotelManagementFX