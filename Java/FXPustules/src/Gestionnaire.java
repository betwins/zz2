import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class Gestionnaire extends Application implements EventHandler<ActionEvent>{
	public static void main(String[] args) {
		launch(args);
	}
	
	@Override
	public void handle(ActionEvent arg0) {
		MonBouton btn = new MonBouton();
		int v = Integer.parseInt(btn.getText());
		btn.setText(String.valueOf(v+1));
	}

	@Override
	public void start(Stage arg0) throws Exception {
		Stage primaryStage = new Stage();
		HBox root = new HBox();
		Scene scene = new Scene(root,250,30, Color.DARKBLUE);
		
		MonBouton btn = new MonBouton();
		
		btn.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				btn.incrementer();
			}
		});
		
		MonBouton btn2 = new MonBouton();
		btn2.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				btn2.incrementer();
			}
		});
		
		MonBouton btn3 = new MonBouton();
		btn3.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				btn3.incrementer();
			}
		});
		
		MonBouton btn4 = new MonBouton();
		btn4.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				btn4.incrementer();
			}
		});
		
		MonBouton btn5 = new MonBouton();
		btn5.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				btn5.incrementer();
			}
		});
		
		MonBouton btnexit = new MonBouton("Quitter");
		btnexit.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				System.exit(0);
				
			}			
		});
		
		root.getChildren().add(btn);
		root.getChildren().add(btn2);
		root.getChildren().add(btn3);
		root.getChildren().add(btn4);
		root.getChildren().add(btn5);
		root.getChildren().add(btnexit);
		
		primaryStage.setScene(scene);
		primaryStage.show();
		
	}
}
