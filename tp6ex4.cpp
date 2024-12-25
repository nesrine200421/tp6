#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Piece {
protected:
    string couleur;
    int x, y;

public:
    Piece(string couleur, int x, int y) : couleur(couleur), x(x), y(y) {}

    virtual void afficher() const {
        cout << "Type: " << typeid(*this).name() << ", Couleur: " << couleur 
             << ", Position: (" << x << ", " << y << ")\n";
    }

    virtual void deplacer() = 0; 
};

class Pion : public Piece {
public:
    Pion(string couleur, int x, int y) : Piece(couleur, x, y) {}

    void deplacer() override {
        if (y < 8) {
            y += 1;  // Un pion se déplace d'un pas sur l'axe y
        } else {
            cout << "Le pion a dépassé la limite de l'échiquier.\n";
        }
    }
};

class Roi : public Piece {
public:
    Roi(string couleur, int x, int y) : Piece(couleur, x, y) {}

    void deplacer() override {
       
        if (x < 8) x += 1;
        if (y < 8) y += 1;
    }
};

int main() {
    vector<Piece*> pieces;

    pieces.push_back(new Pion("Blanc", 3, 3));
    pieces.push_back(new Pion("Noir", 4, 6));
    pieces.push_back(new Roi("Blanc", 1, 1));

    cout << "Affichage des pièces avant déplacement :\n";
    for (Piece* p : pieces) {
        p->afficher();
    }

    cout << "\nDéplacement des pièces :\n";
    for (Piece* p : pieces) {
        p->deplacer();
    }

    cout << "\nAffichage des pièces après déplacement :\n";
    for (Piece* p : pieces) {
        p->afficher();
    }

    for (Piece* p : pieces) {
        delete p;
    }

    return 0;
}
