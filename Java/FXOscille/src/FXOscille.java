//import java.util.Random;
import java.util.Optional;

import javafx.application.Application;
//import javafx.collections.FXCollections;
//import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonBar.ButtonData;
import javafx.scene.control.ButtonType;
import javafx.stage.Stage;

public class FXOscille extends Application {
	
	public static void main(String [] args) {
		launch(args);
	}
	
	@Override
	public void start(Stage fenetre) throws Exception {
//		Random rand = new Random();
		fenetre.setTitle("FXOscilleSimple 0.1");
		Group root = new Group();
		MonCanvas canvas = new MonCanvas(400,300);
		Scene scene = new Scene(root); // on laisse la scène calculée la bonne taille.
		GraphicsContext gc = canvas.getGraphicsContext2D();
		
		//liste traitant les valeurs
//		ListView<Double> listing = new ListView<Double>();
//		//objet stockant les données de la liste
//		ObservableList<Double> olist =FXCollections.observableArrayList();
		
		
		
		// Bouton de tracé aléatoire
		Button randomBtn = new Button("Random");
		randomBtn.setLayoutX(320);
		randomBtn.setLayoutY(15);
		randomBtn.minHeight(20);
		randomBtn.minWidth(75);
		
		randomBtn.setOnAction((ActionEvent e) -> {
			int x1=0, y1=0, x2=0, y2=0;
			gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
			canvas.dessinerRand(gc, x1, y1, x2, y2);
			//}
		});
		
		// Bouton effacer tout
		Button clearAll = new Button("Clear all");
		clearAll.setLayoutX(320);
		clearAll.setLayoutY(45);
		clearAll.minHeight(20);
		clearAll.minWidth(75);
		
		clearAll.setOnAction((ActionEvent e) -> {
			gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		});
		
		// Bouton exit
		Button exitBtn =new Button("Quitter");
		exitBtn.setLayoutX(320);
		exitBtn.setLayoutY(75);
		exitBtn.minHeight(20);
		exitBtn.minWidth(75);
		// Fenêtre de confirmation
		exitBtn.setOnAction((ActionEvent e) -> {
			Alert confirm =new Alert(AlertType.CONFIRMATION);
			confirm.setTitle("Confirmation Dialog");
			confirm.setHeaderText("");
			confirm.setContentText("Êtes-vous certain de vouloir quitter ?");
			
			ButtonType oui = new ButtonType("Oui");
			ButtonType non = new ButtonType("Non", ButtonData.CANCEL_CLOSE);
			
			confirm.getButtonTypes().setAll(oui, non);
			
			Optional<ButtonType> choice = confirm.showAndWait();
			if (choice.get() == oui) System.exit(0);
			
		});
		
		root.getChildren().add(canvas);
		root.getChildren().add(randomBtn);
		root.getChildren().add(clearAll);
		root.getChildren().add(exitBtn);
		
		fenetre.setScene(scene);
		fenetre.show();
	}

}
