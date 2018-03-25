public class Zoo{
	static final int NB_ANI = 50;
	Animal[] animaux;
	
	public Zoo() {
		animaux = new Animal[NB_ANI];
	}
	
	public void setAnimal(int i, Animal a) {
		animaux[i] = a;
	}
	
	public Animal getAnimal(int i) {
		return animaux[i];
	}
	
	public static void main(String[] chaines) {
		Zoo zoo =  new Zoo();
		zoo.setAnimal(0, new Animal("lion"));
		zoo.getAnimal(0).afficher(); // c'est bon
		// c'est la même chose qu'écrire zoo.animaux[0].nom si animaux et nom sont publics.
		zoo.getAnimal(1).afficher(); //NullPointer
		zoo.getAnimal(60).afficher(); //ArrayOutOfBounds
	}
}

class Animal{
	String nom;
	
	public Animal(String nom) {
		this.nom = nom;
	}
	
	public void afficher() {
		System.out.println(nom);
	}
}