package application;

import javafx.scene.Parent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

public class Touche extends Parent {
	public String lettre; //lettre publique pour qu'elle soit lue par les autres classes.
	private int positionX = 0;
	private int positionY = 0;
	private int note = 0; //note correspondant au numéro MIDI de la note qui doit être jouée.
	
	public Touche(String le, int posX, int posY, int n) {
		lettre = new String(le);
		positionX = posX;
		positionY = posY;
		note = n;
		
		Rectangle fond_touche = new Rectangle(75, 75, Color.WHITE);
		fond_touche.setArcHeight(10);
		fond_touche.setArcWidth(10);
		this.getChildren().add(fond_touche);
		
		Text img_lettre_touche = new Text(lettre);
		img_lettre_touche.setFont(new Font(25));
		img_lettre_touche.setTranslateX(positionX);
		img_lettre_touche.setTranslateY(positionY);
		this.getChildren().add(img_lettre_touche);
		
	}
}
