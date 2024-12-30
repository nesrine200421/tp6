#include <iostream>
#include <string>
using namespace std;

class P {
protected:
    string n;
    int a;
    char s;

public:
    P(string nm, int ag, char sx) : n(nm), a(ag), s(sx) {}
    string getP() {
        return "Nom: " + n + ", Age: " + to_string(a) + ", Sexe: " + s;
    }
    void setN(string nm) { n = nm; }
    void setA(int ag) { a = ag; }
    void setS(char sx) { s = sx; }
};

class E : public P {
protected:
    string c; // Charge

public:
    E(string nm, int ag, char sx, string ch) : P(nm, ag, sx), c(ch) {}
    string getP() {
        return P::getP() + ", Charge: " + c;
    }
    void setC(string ch) { c = ch; }
};

class Et : public P {
protected:
    string f; // Filière

public:
    Et(string nm, int ag, char sx, string fl) : P(nm, ag, sx), f(fl) {}
    string getP() {
        return P::getP() + ", Filiere: " + f;
    }
    void setF(string fl) { f = fl; }
};

class C : public E, public Et {
public:
    C(string nm, int ag, char sx, string ch, string fl)
        : P(nm, ag, sx), E(nm, ag, sx, ch), Et(nm, ag, sx, fl) {}
    string getP() {
        return E::getP() + ", Filiere: " + f;
    }
};

int main() {
    E ens("Ali", 40, 'M', "Math");
    Et etd("Sara", 22, 'F', "Informatique");
    C cont("Amine", 25, 'M', "Physique", "Chimie");

    cout << ens.getP() << endl;
    cout << etd.getP() << endl;
    cout << cont.getP() << endl;

    return 0;
}
