package application;

import javafx.scene.Parent;
import javafx.scene.effect.Reflection;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;
import javafx.scene.shape.Rectangle;

public class Clavier extends Parent {
	private Touche[] touches;
	
	public Clavier() {
		
		// FOND DU CLAVIER
		Rectangle fond_clavier = new Rectangle();
		fond_clavier.setHeight(150);
		fond_clavier.setWidth(300);
		fond_clavier.setArcHeight(30);
		fond_clavier.setArcWidth(30);
		
		fond_clavier.setFill(
			new LinearGradient(0f, 0f, 0f, 1f, true, CycleMethod.NO_CYCLE, 
				new Stop[] {
						new Stop(0, Color.web("#000000")),
						new Stop(1, Color.DARKGRAY)
				}
			)
		);
		
		Reflection r = new Reflection();
		r.setFraction(0.25);
		r.setBottomOpacity(0);
		r.setTopOpacity(0.5);
		fond_clavier.setEffect(r);
		
		// TOUCHES DU CLAVIER
		
		touches = new Touche[] {
		new Touche("U", 50, 20, 60),
		new Touche("I", 50, 20, 60),
		new Touche("O", 50, 20, 60),
		new Touche("P", 50, 20, 60),
		new Touche("J", 50, 20, 60),
		new Touche("K", 50, 20, 60),
		new Touche("L", 50, 20, 60),
		new Touche("M", 50, 20, 60),
		};
		
		this.setTranslateX(50); // c'est mieux de déplacer le groupe plutôt 
		this.setTranslateY(200); // que de déplacer chaque objet individuellement
		this.getChildren().add(fond_clavier);
		for (Touche touche: touches) {
			this.getChildren().add(touche);
		}
	}
}
