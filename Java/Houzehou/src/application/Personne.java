package application;

public class Personne extends Object {
	private String nom;
	private String prenom;
	private String langage;
	private String annee;
	static int compteur = 0;

	// constructeurs
	public Personne() {
		compteur++;
		nom = "pas de nom donn�";
		prenom = "pas de pr�nom donn�";
		langage = "pas de langage associ�";
		annee = "pas d'ann�e remplie";
		System.out.println(this.nbPersonnes());
	}
	public Personne(String name, String fName, String langage2, String year) {
		nom = name;
		prenom = fName;
		langage = langage2;
		annee = year;
		compteur++;
	}
	
	// getters
	public int nbPersonnes() {
		return compteur;
	}
	public String getNom() {
		return this.nom;
	}
	public String getPrenom() {
		return this.prenom;
	}
	public String getLangage() {
		return this.langage;
	}
	public String getAnnee() {
		return this.annee;
	}
	
	/*
	 * getDeclaredFields() : retourne une liste des attributs de la classe courante qu'importe la visibilit�.
	 * getFields() : retourne une liste de tous les attributs publics de la classe courante.
	 */
	
	@Override
	public String toString() {
//		Field[] fields = getDeclaredFields();
//		Iterator<Field> iter = new Iterator<Field>();
//		String[] result = ;
		StringBuilder attributs = new StringBuilder();
		attributs.append(this.getNom());
		attributs.append(":");
		attributs.append(this.getPrenom());
		attributs.append(":");
		attributs.append(this.getLangage());
		attributs.append(":");
		attributs.append(this.getAnnee());
		return attributs.toString();
	}
	
}
