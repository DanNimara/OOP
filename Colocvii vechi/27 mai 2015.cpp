#include <iostream>
#include <vector>
using namespace std;

///---------------------clasa LOT-----------------------------

class Lot {
    int nr_loturi;
    int cant;
    int zi_prim, luna_prim, an_prim;
    double pret;
  public:
    Lot(int, int, int, int, int, double);
    Lot(const Lot& obj);
    virtual ~Lot();
    int getNr_loturi() {
        return nr_loturi;
    }
    void setNr_loturi(int nr_loturi) {
        this->nr_loturi=nr_loturi;
    }
    int getCant() const{
        return cant;
    }
    void setCant(int cant){this->cant=cant;}
    int getZi_prim() const {
        return zi_prim;
    }
    void setZi_prim(int zi_prim) {
        this->zi_prim = zi_prim;
    }
    int getLuna_prim() const {
        return luna_prim;
    }
    void setLuna_prim(int luna_prim) {
        this->luna_prim = luna_prim;
    }
    int getAn_prim() const {
        return an_prim;
    }
    void setAn_prim(int an_prim) {
        this->an_prim = an_prim;
    }
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Lot& obj);
    friend ostream& operator<<(ostream& out, const Lot& obj);
    Lot& operator=(const Lot& obj);
};

Lot::Lot(int nr_loturi=0, int cant=0, int zi_prim=0, int luna_prim=0, int an_prim=0, double pret=0) : nr_loturi(nr_loturi), cant(cant),
        zi_prim(zi_prim), luna_prim(luna_prim), an_prim(an_prim), pret(pret) {}
Lot::Lot(const Lot& obj) {
    this->nr_loturi=obj.nr_loturi;
    this->zi_prim=obj.zi_prim;
    this->cant=obj.cant;
    this->luna_prim=obj.luna_prim;
    this->an_prim=obj.an_prim;
    this->pret=obj.pret;
}
Lot::~Lot() {
    nr_loturi=0;
    zi_prim=0;
    cant=0;
    luna_prim=0;
    an_prim=0;
    pret=0;
}
void Lot::citire(istream& in) {
    cout<<"\nCare este cantitatea primita de magazin? ";
    in>>cant;
    cout << "Care este ziua primirii lotului? ";
    in>>zi_prim;
    cout << "Care este luna primirii lotului? ";
    in>>luna_prim;
    cout << "Care este anul primirii lotului? ";
    in>>an_prim;
    cout << "Care este pretul la care trebuie vandut produsul? ";
    in>>pret;
}
void Lot::afisare(ostream& out) const {
    out<<"pe data de "<<zi_prim<<'.'<<luna_prim<<'.'<<an_prim<<", magazinul primeste un lot de "<<cant;
}
istream& operator>>(istream& in, Lot& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Lot& obj) {
    obj.afisare(out);
    return out;
}
Lot& Lot::operator=(const Lot& obj) {
    if (this != &obj) {
        this->nr_loturi=obj.nr_loturi;
        this->cant=obj.cant;
        this->zi_prim=obj.zi_prim;
        this->luna_prim=obj.luna_prim;
        this->an_prim=obj.an_prim;
        this->pret=obj.pret;
    }
    return *this;
}

///--------------------------------clasa PRODUS--------------------------

class Produs {
  protected:
    string denumire;
    string unit_mas;
    vector <Lot> produse;
  public:
    Produs(string, string);
    Produs(const Produs& obj);
    virtual ~Produs();
    string getDenumire() {
        return denumire;
    }
    void setDenumire(string denumire) {
        this->denumire=denumire;
    }
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Produs& obj);
    friend ostream& operator<<(ostream& out, const Produs& obj);
    Produs& operator=(const Produs& obj);
};

Produs::Produs(string denumire="", string unit_mas="") : unit_mas(unit_mas), denumire(denumire) {
}
Produs::Produs(const Produs& obj) {
    this->denumire=obj.denumire;
    this->unit_mas=obj.unit_mas;
    for (int i=0; i<obj.produse.size(); i++)
        this->produse.push_back(obj.produse[i]);
}
Produs::~Produs() {
    denumire="";
    unit_mas="";
    produse.clear();
}
void Produs::citire(istream& in) {
    cout << "Care este numele produsului? ";
    in.get();
    getline(in, denumire);
    cout << "Care este unitatea de masura a produsului?(bucata, greutate, volum) ";
    in >> unit_mas;
    Lot prod;
    cin>>prod;
    prod.setNr_loturi(1);
    produse.push_back(prod);
}
void Produs::afisare(ostream& out) const {
        if(unit_mas=="greutate")
            out<<unit_mas<<" kg de "<<denumire;
        else if(unit_mas=="bucata")
            out<<unit_mas<<" bucati de "<<denumire;
        else if(unit_mas=="volum")
            out<<unit_mas<<" de litri de "<<denumire;
}
istream& operator>>(istream& in, Produs& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Produs& obj) {
    obj.afisare(out);
    return out;
}
Produs& Produs::operator=(const Produs& obj) {
    if (this != &obj) {
        this->denumire=obj.denumire;
        this->unit_mas=obj.unit_mas;
        for (int i=0; i<obj.produse.size(); i++)
        this->produse.push_back(obj.produse[i]);
    }
    return *this;
}

class ProdusPerisabil : public Produs {
    int zile_valab;
  public:
    ProdusPerisabil(string, string, int); ///constructor cu param default (apel pt baza)
    ProdusPerisabil(const ProdusPerisabil& obj);
    ~ProdusPerisabil();
    void calculValab();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ProdusPerisabil& obj);
    friend ostream& operator<<(ostream& out, const ProdusPerisabil& obj);
    ProdusPerisabil& operator=(const ProdusPerisabil& obj);
};

ProdusPerisabil::ProdusPerisabil(string denumire="", string unit_mas="", int zile_valab=0) : Produs(unit_mas, denumire), zile_valab(zile_valab)
{
}
ProdusPerisabil::ProdusPerisabil(const ProdusPerisabil& obj) : Produs(obj) {
    this->zile_valab = obj.zile_valab;
}
ProdusPerisabil::~ProdusPerisabil() {
    zile_valab=0;
}
void ProdusPerisabil::citire(istream& in) {
    Produs::citire(in);
    cout << "Care este termenul de valabilitate?(in zile) ";
    in >> zile_valab;
}
void ProdusPerisabil::afisare(ostream& out) const {
    for(int i=0;i<produse.size();i++){
        cout<<produse[i];

        out << ", cu termen de valabilitate de "<< zile_valab<<" zile, la pretul de "<<pret<<" pe ";
        if(unit_mas=="greutate")
            out<<"kg";
        else if(unit_mas=="bucata")
            out<<"bucata";
        else if(unit_mas=="volum")
        out<<"volum";
    }
}
istream& operator>>(istream& in, ProdusPerisabil& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ProdusPerisabil& obj) {
    obj.afisare(out);
    return out;
}
ProdusPerisabil& ProdusPerisabil::operator=(const ProdusPerisabil& obj) {
    if (this != &obj) {
        Produs::operator=(obj) ;
        this->zile_valab = obj.zile_valab;
    }
    return *this;
}

/*
class Derived : public Base {
    ///int md1;
  public:
    Derived(); ///constructor cu param default (apel pt baza)
    Derived(const Derived& obj);
    ~Derived();

    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Derived& obj);
    friend ostream& operator<<(ostream& out, const Derived& obj);
    Derived& operator=(const Derived& obj);
};

Derived::Derived() : Base(), md1(md1) {}
Derived::Derived(const Derived& obj) : Base(obj) {
    ///this->md1 = obj.md1;
}
Derived::~Derived() {
    ///md1 = 0;
}
void Derived::citire(istream& in) {
    Base::citire(in);
    cout << "Care este membrul derivat 1? ";
    in >> md1;
}
void Derived::afisare(ostream& out) const {
    Base::afisare(out);
    out << "\nMembrul derivat 1 este " << md1;
}
istream& operator>>(istream& in, Derived& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Derived& obj) {
    obj.afisare(out);
    return out;
}
Derived& Derived::operator=(const Derived& obj) {
    if (this != &obj) {
        Base::operator=(obj) ;
        ///this->md1 = obj.md1;
    }
    return *this;
}
*/
int main() {

    return 0;
}
