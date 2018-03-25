package application;

import java.util.ArrayList;

public class WhoswhoApplication {
	public static void main(String[] args) {
		ArrayList<Personne> tabP = new ArrayList<Personne>();
		Personne p = new Personne();
		System.out.println(tabP.isEmpty()? "Il n'y a personne":"Il y a du monde ! Attention !");
		tabP.add(p);
		System.out.println(tabP.isEmpty()? "Il n'y a personne":"Il y a du monde ! Attention !");
		System.out.println(p.toString());
	}
}