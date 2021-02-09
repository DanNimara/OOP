#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Zbor {
protected:
    string IDzbor;
    string oras;
    int zi_plecare;
    string destinatie;
    int durata;
public:
    ///generate constructor
    virtual ~Zbor();

    Zbor(const string &iDzbor="", const string &oras="", int zi_plecare=0, const string &destinatie="", int durata=0);

    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Zbor& obj);
    friend ostream& operator<<(ostream& out, const Zbor& obj);

    const string &getIDzbor() const;

    void setIDzbor(const string &iDzbor);

    const string &getOras() const;

    void setOras(const string &oras);

    int getZiPlecare() const;

    void setZiPlecare(int ziPlecare);

    const string &getDestinatie() const;

    void setDestinatie(const string &destinatie);

    int getDurata() const;

    void setDurata(int durata);
};
Zbor::Zbor(const string &iDzbor, const string &oras, int zi_plecare, const string &destinatie, int durata) : IDzbor(
        iDzbor), oras(oras), zi_plecare(zi_plecare), destinatie(destinatie), durata(durata) {}
Zbor::~Zbor() {
    IDzbor="";
    oras="";
    zi_plecare=0;
    destinatie="";
    durata=0;
}

const string &Zbor::getIDzbor() const {
    return IDzbor;
}
void Zbor::setIDzbor(const string &iDzbor) {
    this->IDzbor = iDzbor;
}
const string &Zbor::getOras() const {
    return oras;
}
void Zbor::setOras(const string &oras) {
    this->oras = oras;
}
int Zbor::getZiPlecare() const {
    return zi_plecare;
}
void Zbor::setZiPlecare(int ziPlecare) {
    this->zi_plecare = ziPlecare;
}
const string &Zbor::getDestinatie() const {
    return destinatie;
}

void Zbor::setDestinatie(const string &destinatie) {
    this->destinatie = destinatie;
}

int Zbor::getDurata() const {
    return durata;
}

void Zbor::setDurata(int durata) {
    this->durata = durata;
}

void Zbor::citire(istream& in) {
    cout<<"\nID zbor: ";
    in.get();
    getline(in, IDzbor);
    cout<<"Oras plecare: ";
    getline(in, oras);
    cout<<"Zi plecare: ";
    in>>zi_plecare;
    cout<<"Destinatie: ";
    in.get();
    getline(in, destinatie);
    cout<<"Durata(zile): ";
    in>>durata;
}
void Zbor::afisare(ostream& out) const {
    out << "\nID zbor: "<<IDzbor<<", oras plecare: "<<oras<<", zi plecare"<<zi_plecare<<", destinatie: "<<destinatie;
    out<<", durata: "<<durata;
}
istream& operator>>(istream& in, Zbor& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Zbor& obj) {
    obj.afisare(out);
    return out;
}


class ZborNormal : virtual public Zbor {

public:
    ZborNormal(string IDzbor="", string oras="", int zi_plecare=0, string destinatie="", int durata=0);
    ~ZborNormal();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ZborNormal& obj);
    friend ostream& operator<<(ostream& out, const ZborNormal& obj);
};

ZborNormal::ZborNormal(string IDzbor, string oras, int zi_plecare, string destinatie, int durata):
        Zbor(IDzbor, oras, zi_plecare, destinatie, durata){}

ZborNormal::~ZborNormal() {}

void ZborNormal::citire(istream& in) {
    Zbor::citire(in);
}
void ZborNormal::afisare(ostream& out) const {
    Zbor::afisare(out);
}
istream& operator>>(istream& in, ZborNormal& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ZborNormal& obj) {
    obj.afisare(out);
    return out;
}


class ZborTemporar : public Zbor {
protected:
    int per_activa;
    string sarbatoare;
public:
    ZborTemporar(const string &iDzbor="", const string &oras="", int zi_plecare=0, const string &destinatie="", int durata=0,
            int perActiva=0, const string &sarbatoare="");

    ~ZborTemporar();
    int getPerActiva() const;
    void setPerActiva(int perActiva);
    const string &getSarbatoare() const;
    void setSarbatoare(const string &sarbatoare);
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ZborTemporar& obj);
    friend ostream& operator<<(ostream& out, const ZborTemporar& obj);


};
ZborTemporar::ZborTemporar(const string &iDzbor, const string &oras, int zi_plecare, const string &destinatie, int durata,
                int perActiva, const string& sarbatoare) :
        Zbor(IDzbor, oras, zi_plecare, destinatie, durata),
        per_activa(perActiva), sarbatoare(sarbatoare) {}

ZborTemporar::~ZborTemporar() {
   per_activa=0;
   sarbatoare="";
}

int ZborTemporar::getPerActiva() const {
    return per_activa;
}

void ZborTemporar::setPerActiva(int perActiva) {
    this->per_activa = perActiva;
}

const string &ZborTemporar::getSarbatoare() const {
    return sarbatoare;
}

void ZborTemporar::setSarbatoare(const string &sarbatoare) {
    this->sarbatoare = sarbatoare;
}

void ZborTemporar::citire(istream& in) {
    Zbor::citire(in);
    cout << "Care este perioada activa a zborului? ";
    try {
        in >> per_activa;
        if (per_activa > 90)
            throw 1;
    }
    catch(int i){
        cout<<"\nPerioada activa nu poate fi mai mare de 3 luni!";
    }
    string verif;
    cout<<"Este temporara cu ocazia unei sarbatori?(nu/da) ";
    cin>>verif;
    if(verif=="da"){
        cout<<"Care este sarbatoarea?(Halloween/Thanksgiving/Craciun): ";
        in>>sarbatoare;
    }
    else sarbatoare="nu";

}
void ZborTemporar::afisare(ostream& out) const {
    Zbor::afisare(out);
    out << ", cursa temporara ";
    if(sarbatoare!="nu")
        out<<"de "<<sarbatoare;
    out<<", cu o perioada activa de "<<per_activa<<" zile";
}
istream& operator>>(istream& in, ZborTemporar& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ZborTemporar& obj) {
    obj.afisare(out);
    return out;
}


class ZborNormalRedus : public ZborNormal {
    double discount;
public:
    ZborNormalRedus(const string &iDzbor="", const string &oras="", int zi_plecare=0, const string &destinatie="", int durata=0,
            double discount=0);
    ~ZborNormalRedus();
    double getDiscount() const {
        return discount;
    }
    void setDiscount(double discount) {
        this->discount = discount;
    }
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ZborNormalRedus& obj);
    friend ostream& operator<<(ostream& out, const ZborNormalRedus& obj);
};

ZborNormalRedus::ZborNormalRedus(const string &iDzbor, const string &oras, int zi_plecare, const string &destinatie, int durata,
                     double discount)
        : ZborNormal(iDzbor, oras, zi_plecare, destinatie, durata), discount(discount) {}

ZborNormalRedus::~ZborNormalRedus() {
    discount=0;
}
void ZborNormalRedus::citire(istream& in) {
    ZborNormal::citire(in);
    cout<<"Discount(procent): ";
    in >> discount;
    try {
        if (discount < 0 || discount>100)
            throw 1;
    }
    catch (int i) {
        cout << "Eroare la setarea discountului. Discountul trebuie sa reprezinte un procent intre 0% si 100%.\n";
        exit(EXIT_FAILURE);
    }
}
void ZborNormalRedus::afisare(ostream& out) const {
    ZborNormal::afisare(out);
    out << " zborului i se aplica un discount de "<<discount<<"%";
}
istream& operator>>(istream& in, ZborNormalRedus& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ZborNormalRedus& obj) {
    obj.afisare(out);
    return out;
}

class ZborTemporarRedus : public ZborTemporar {
    double discount;
public:
    ZborTemporarRedus(const string &iDzbor="", const string &oras="", int zi_plecare=0, const string &destinatie="", int durata=0,
                      int perActiva=0, const string &sarbatoare="", double discount=0);
    ~ZborTemporarRedus();
    double getDiscount() const {
        return discount;
    }
    void setDiscount(double discount) {
        this->discount = discount;
    }
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ZborTemporarRedus& obj);
    friend ostream& operator<<(ostream& out, const ZborTemporarRedus& obj);
};

ZborTemporarRedus::ZborTemporarRedus(const string &iDzbor, const string &oras, int zi_plecare, const string &destinatie, int durata,
                                     int perActiva, const string& sarbatoare, double discount)
        : ZborTemporar(iDzbor, oras, zi_plecare, destinatie, durata, perActiva, sarbatoare), discount(discount) {}

ZborTemporarRedus::~ZborTemporarRedus() {
    discount=0;
}
void ZborTemporarRedus::citire(istream& in) {
    ZborTemporar::citire(in);
    cout<<"Discount(procent): ";
    in >> discount;
    try {
        if (discount < 0 || discount>100)
            throw 1;
    }
    catch (int i) {
        cout << "Eroare la setarea discountului. Discountul trebuie sa reprezinte un procent intre 0% si 100%.\n";
        exit(EXIT_FAILURE);
    }
}
void ZborTemporarRedus::afisare(ostream& out) const {
    ZborTemporar::afisare(out);
    out << " zborului i se aplica un discount de "<<discount<<"%";
}
istream& operator>>(istream& in, ZborTemporarRedus& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ZborTemporarRedus& obj) {
    obj.afisare(out);
    return out;
}

class Container {
protected:
    string ruta;
    int nrCurse;
    double pretBilet;
public:
    Container(const string &ruta="", int nrCurse=0, double pretBilet=0);

    virtual ~Container();
    const string &getRuta() const {
        return ruta;
    }
    void setRuta(const string &ruta) {
        this->ruta = ruta;
    }
    int getNrCurse() const {
        return nrCurse;
    }

    void setNrCurse(int nrCurse) {
        this->nrCurse = nrCurse;
    }

    double getPretBilet() const {
        return pretBilet;
    }

    void setPretBilet(double pretBilet) {
        this->pretBilet = pretBilet;
    }
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Container& obj);
    friend ostream& operator<<(ostream& out, const Container& obj);
};

Container::Container(const string &ruta, int nrCurse, double pretBilet) :
                ruta(ruta), nrCurse(nrCurse), pretBilet(pretBilet){}
Container::~Container() {
    ruta="";
    nrCurse=0;
    pretBilet=0;
}
void Container::citire(istream& in) {
    cout<<"Care este ruta zborului? ";
    in.get();
    getline(in, ruta);
    cout<<"Cate curse efectueaza ruta? ";
    in>>nrCurse;
    cout<<"Care este pretul unui bilet Economic? ";
    in>>pretBilet;
}
void Container::afisare(ostream& out) const {
    out << "\nRuta zbor: "<<ruta<<" efectuata de "<<nrCurse<<", iar un bilet costa "<<pretBilet<<" dolari";
}
istream& operator>>(istream& in, Container& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Container& obj) {
    obj.afisare(out);
    return out;
}

class ContainerSpecial : public Container {
public:
    ContainerSpecial(const string &ruta="", int nrCurse=0, double pretBilet=0);

    ~ContainerSpecial();
    void calculareData();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ContainerSpecial& obj);
    friend ostream& operator<<(ostream& out, const ContainerSpecial& obj);
};
ContainerSpecial::ContainerSpecial(const string &ruta, int nrCurse, double pretBilet) : Container(ruta, nrCurse, pretBilet) {}
ContainerSpecial::~ContainerSpecial() {
}
void ContainerSpecial::citire(istream& in) {
    Container::citire(in);
}
void ContainerSpecial::afisare(ostream& out) const {
    Container::afisare(out);
}
istream& operator>>(istream& in, ContainerSpecial& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ContainerSpecial& obj) {
    obj.afisare(out);
    return out;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
