import javafx.scene.control.Button;

public class MonBouton extends Button {
	public int compteur;
	
	public MonBouton() {
		super("0");
	}
	public MonBouton(String texteBtn) {
		super(texteBtn);
		compteur++;
	}
	public void incrementer() {
		compteur++;
		setText(String.valueOf(compteur));
	}
}
