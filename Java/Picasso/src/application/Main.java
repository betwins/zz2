package application;
	
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.MenuBar;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;


public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			primaryStage.setTitle("Picasso 1.0");
			BorderPane root = new BorderPane();
			MenuBar menuBar = new MenuBar();
			root.setTop(menuBar);
			//Group root = new Group();
			Scene scene = new Scene(root);
			
			CanvasPerso canv = new CanvasPerso(450,300);
			GraphicsContext gc = canv.getGraphicsContext2D();
			
			
			for (int i = 0; i<50000; i++) {
				canv.dessiner(gc);
			}
			
			root.getChildren().add(canv);
			
			primaryStage.setScene(scene);
			primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
