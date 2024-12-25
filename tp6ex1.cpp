#include <iostream>
class Vecteur {
protected:
    float x, y;

public:
    Vecteur() : x(0.0), y(0.0) {}
    Vecteur(float x, float y) {
        this->x = x; 
        this->y = y;
    }
    void afficher() const {
        std::cout << "(" << x << " , " << y << ")" << std::endl;
    }
    void deplacer(float dx, float dy) {
        x += dx; 
        y += dy; 
    }
};

class Vecteur3D : public Vecteur {
private:
    float z;

public:
    Vecteur3D() : Vecteur(), z(0.0) {}

    Vecteur3D(float x, float y, float z) : Vecteur(x, y), z(z) {}
    void afficher() const {
        std::cout << "(" << x << " , " << y << " , " << z << ")" << std::endl;
    }
    void deplacer(float dx, float dy, float dz) {
        Vecteur::deplacer(dx, dy);
        z += dz;
    }
};

int main() {
    Vecteur v1;
    std::cout << "Vecteur nul : ";
    v1.afficher();
    v1.deplacer(2.5, 3.5);
    std::cout << "Vecteur après déplacement : ";
    v1.afficher();
    Vecteur v2(3.0, 4.0);
    std::cout << "Vecteur créé avec paramètres : ";
    v2.afficher();
    Vecteur3D* v3D = new Vecteur3D(1.0, 2.0, 3.0);
    std::cout << "Vecteur3D créé dynamiquement : ";
    v3D->afficher();
    v3D->deplacer(1.0, -1.0, 2.0);
    std::cout << "Vecteur3D après déplacement : ";
    v3D->afficher();
    Vecteur3D v3D_static(5.0, 6.0, 7.0);
    std::cout << "Vecteur3D statique créé avec paramètres : ";
    v3D_static.afficher();
    delete v3D;

    return 0;
}
