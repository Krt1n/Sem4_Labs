import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

public class TestFX extends Application {
    public void start(Stage stage) {
        Button btn = new Button("JavaFX Working!");
        Scene scene = new Scene(btn, 300, 200);
        stage.setScene(scene);
        stage.setTitle("Test");
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}