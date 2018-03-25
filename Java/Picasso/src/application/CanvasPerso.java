package application;

import java.util.concurrent.ThreadLocalRandom;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class CanvasPerso extends Canvas{
	// Attributs
	public final int MAX_LARGEUR;
	public final int MAX_HAUTEUR;
	
	// Méthodes
	public CanvasPerso() {
		super(800, 600);
		MAX_LARGEUR=800;
		MAX_HAUTEUR=600;
	}
	public CanvasPerso(int wd, int hd) {
		super(wd, hd);
		MAX_LARGEUR=wd;
		MAX_HAUTEUR=hd;
	}
	public void dessiner(GraphicsContext gc) {
//		Random rand = new Random();
//		int longueur=rand.nextInt(150)+1;
//		int largeur=rand.nextInt(150)+1;
//		
//		int randCol1=rand.nextInt(256);
//		int randCol2=rand.nextInt(256);
//		int randCol3=rand.nextInt(256);
//		
//		int posXrand=rand.nextInt(MAX_LARGEUR);
//		int posYrand=rand.nextInt(MAX_HAUTEUR);
		int longueur=ThreadLocalRandom.current().nextInt(2,150);
		int largeur=ThreadLocalRandom.current().nextInt(2,150);
		
		int randCol1 = ThreadLocalRandom.current().nextInt(0, 256); 
		int randCol2 = ThreadLocalRandom.current().nextInt(0, 256);
		int randCol3 = ThreadLocalRandom.current().nextInt(0, 256);
		
		int posXrand=ThreadLocalRandom.current().nextInt(0,MAX_LARGEUR);
		int posYrand=ThreadLocalRandom.current().nextInt(0, MAX_HAUTEUR);
//		Rectangle rect = new Rectangle(longueur, largeur, Color.rgb(randCol1, randCol2, randCol3, 0.25));
		//rect.setOpacity(0.25);
//		rect.setLayoutX(posXrand);
//		rect.setLayoutY(posYrand);
		gc.setFill(Color.rgb(randCol1, randCol2, randCol3, 0.45));
		gc.fillRect(longueur, largeur, posXrand, posYrand);
	}
}
