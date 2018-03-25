import java.util.Random;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class MonCanvas extends Canvas {
	
	public MonCanvas() {
		super(800, 600);
	}
	
	public MonCanvas(int ht, int wd) {
		super(ht, wd);
	}
	
	public void dessiner(GraphicsContext gc, int x1, int y1, int x2, int y2) {
		Random rand = new Random();
		gc.setStroke(Color.BLUE);
		gc.setLineWidth(1);
		x1 = 15;
		y1 = 50;
		x2 = rand.nextInt(100)+1;
		y2 = rand.nextInt(100)+1;
		gc.strokeLine(x1, y1, x2, y2);
	}
	
	public void dessinerRand(GraphicsContext gc, int x1, int y1, int x2, int y2) {
		Random rand = new Random();
		gc.setStroke(Color.BLUE);
		gc.setLineWidth(1);
		
		// première ligne
		x1 = 15;
		y1 = 125;
		x2 = x1+2;
		y2 = rand.nextInt(250)+1;
		gc.strokeLine(x1, y1, x2, y2);
		
		for (int i = 0; i<150; i++) {
			x1 = x2;
			y1 = y2;
			x2 = 2+x1;
			y2 = rand.nextInt(250)+1;
			gc.strokeLine(x1, y1, x2, y2);
		}
	}
}
