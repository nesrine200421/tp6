class Vehicule {
    private static int numeroSerie = 1;
    private int numeroVehicule;
    private int anneeModele;
    private double prix;

    public Vehicule(int anneeModele, double prix) {
        this.numeroVehicule = (numeroSerie % 10000) + 1;
        this.anneeModele = anneeModele;
        this.prix = prix;
        numeroSerie++;
    }

    public void accelerer() {
        System.out.println("Un véhicule accélère.");
    }

    // Affichage des informations du véhicule
    public void afficher() {
        System.out.println(this.numeroSerie + " TUN " + this.numeroVehicule + "l’année du modèle " + this.anneeModele + "prix:  " + this.prix);
    }
}

class Voiture extends Vehicule {
    private int nombrePlaces;

    public Voiture(int anneeModele, double prix, int nombrePlaces) {
        super(anneeModele, prix);
        this.nombrePlaces = nombrePlaces;
    }

    @Override
    public void accelerer() {
        System.out.println("Je peux atteindre 200 km/h.");
    }
}

class Camion extends Vehicule {
    private double chargeMaximale;

    public Camion(int anneeModele, double prix, double chargeMaximale) {
        super(anneeModele, prix);
        this.chargeMaximale = chargeMaximale;
    }

    @Override
    public void accelerer() {
        System.out.println("Je peux atteindre 120 km/h.");
    }
}

public class Main {
    public static void main(String[] args) {
        Vehicule voiture1 = new Voiture(2023, 15000, 5);
        Vehicule camion1 = new Camion(2022, 30000, 5000);

        voiture1.afficher();
        camion1.afficher();

        voiture1.accelerer();
        camion1.accelerer();
    }
}
