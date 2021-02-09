#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include<sstream>
using namespace std;

class Bilet {
protected:
    static int nr;
    int nrOrd;
    string serie;
    string plecare;
    string sosire;
    int zip, lunap, anp;
    string codtren;
    string clasa;
    int durata;
    int distanta;
    double pret;
public:
    Bilet(const string &serie, const string &plecare, const string &sosire, int zip, int lunap, int anp,
          const string &codtren, const string& clasa, int durata, int distanta, double pret);

    static int getNr();

    static void setNr(int nr);

    int getNrOrd() const;

    void setNrOrd(int nrOrd);

    const string &getSerie() const;

    void setSerie(const string &serie);

    const string &getPlecare() const;

    void setPlecare(const string &plecare);

    const string &getSosire() const;

    void setSosire(const string &sosire);

    int getZip() const;

    void setZip(int zip);

    int getLunap() const;

    void setLunap(int lunap);

    int getAnp() const;

    void setAnp(int anp);

    const string &getCodtren() const;

    void setCodtren(const string &codtren);

    const string &getClasa() const;

    void setClasa(const string &clasa);

    int getDurata() const;

    void setDurata(int durata);

    int getDistanta() const;

    void setDistanta(int distanta);

    double getPret() const;

    void setPret(double pret);
    virtual void PretBilet()=0;
    virtual ~Bilet();
    virtual void SerieBilet()=0;
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Bilet& obj);
    friend ostream& operator<<(ostream& out, const Bilet& obj);
};
int Bilet::nr=0;
Bilet::Bilet(const string &serie="", const string &plecare="", const string &sosire="", int zip=0, int lunap=0, int anp=0,
             const string &codtren="",const string &clasa="", int durata=0, int distanta=0, double pret=0) : serie(serie), plecare(plecare),
                                                                                                             sosire(sosire), zip(zip), lunap(lunap),
                                                                                                             anp(anp), codtren(codtren), clasa(clasa), durata(durata),
                                                                                                             distanta(distanta), pret(pret) {}
Bilet::~Bilet() {
    serie="";
    plecare="";
    sosire="";
    zip=0;
    lunap=0;
    anp=0;
    codtren="";
    clasa="";
    durata=0;
    distanta=0;
    pret=0;
}
int Bilet::getNr() {
    return nr;
}
void Bilet::setNr(int nr) {
    Bilet::nr = nr;
}
int Bilet::getNrOrd() const {
    return nrOrd;
}
void Bilet::setNrOrd(int nrOrd) {
    this->nrOrd = nrOrd;
}
const string &Bilet::getSerie() const {
    return serie;
}
void Bilet::setSerie(const string &serie) {
    this->serie = serie;
}
const string &Bilet::getPlecare() const {
    return plecare;
}
void Bilet::setPlecare(const string &plecare) {
    this->plecare = plecare;
}
const string &Bilet::getSosire() const {
    return sosire;
}
void Bilet::setSosire(const string &sosire) {
    this->sosire = sosire;
}
int Bilet::getZip() const {
    return zip;
}
void Bilet::setZip(int zip) {
    this->zip = zip;
}
int Bilet::getLunap() const {
    return lunap;
}
void Bilet::setLunap(int lunap) {
    this->lunap = lunap;
}
int Bilet::getAnp() const {
    return anp;
}
void Bilet::setAnp(int anp) {
    this->anp = anp;
}
const string &Bilet::getCodtren() const {
    return codtren;
}
void Bilet::setCodtren(const string &codtren) {
    this->codtren = codtren;
}
const string &Bilet::getClasa() const {
    return clasa;
}
void Bilet::setClasa(const string &clasa) {
    this->clasa = clasa;
}
int Bilet::getDurata() const {
    return durata;
}
void Bilet::setDurata(int durata) {
    this->durata = durata;
}
int Bilet::getDistanta() const {
    return distanta;
}
void Bilet::setDistanta(int distanta) {
    this->distanta = distanta;
}
double Bilet::getPret() const {
    return pret;
}
void Bilet::setPret(double pret) {
    this->pret = pret;
}
void Bilet::citire(istream& in) {
    nrOrd=++nr;
    cout << "Statie plecare: ";
    in.get();
    getline(in, plecare);
    cout << "Statie sosire: ";
    getline(in, sosire);
    cout << "Zi: ";
    in >> zip;
    cout<<"Luna: ";
    in>>lunap;
    cout<<"An: ";
    in>>anp;
    cout<<"Durata deplasare(in minute): ";
    in>>durata;
    cout<<"Distanta deplasare(in km): ";
    in>>distanta;
}
void Bilet::afisare(ostream& out) const {
    out << "\nSerie bilet: "<<serie<<"\nStatie plecare: "<<plecare<<", statie sosire: "<<sosire<<", la data de: "<<zip<<'.'<<lunap<<'.'<<anp;
    out<<", durata calatorie(in minute): "<<durata<<", distanta parcursa: "<<distanta<<", pret bilet: "<<pret;
}
istream& operator>>(istream& in, Bilet& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Bilet& obj) {
    obj.afisare(out);
    return out;
}

class BiletClasaII : public Bilet{
public:
    BiletClasaII(const string &serie, const string &plecare, const string &sosire, int zip, int lunap, int anp,
                 const string &codtren, const string &clasa, int durata, int distanta, double pret);

    ~BiletClasaII();
    void SerieBilet();
    void PretBilet();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, BiletClasaII& obj);
    friend ostream& operator<<(ostream& out, const BiletClasaII& obj);
};
BiletClasaII::BiletClasaII(const string &serie="", const string &plecare="", const string &sosire="", int zip=0, int lunap=0,
                           int anp=0, const string &codtren="", const string &clasa="", int durata=0,
                           int distanta=0, double pret=0)
        : Bilet(serie, plecare, sosire, zip, lunap, anp, codtren, clasa, durata, distanta, pret) {}
BiletClasaII::~BiletClasaII() {
}
void BiletClasaII::SerieBilet() {
    stringstream ss;
    ss<<nrOrd;
    string s;
    ss>>s;
    serie="RII-"+s;
}

void BiletClasaII::PretBilet() {
    pret=0.39*distanta;
}
void BiletClasaII::citire(istream& in) {
    Bilet::citire(in);
    codtren="R";
}
void BiletClasaII::afisare(ostream& out) const {
    Bilet::afisare(out);
}
istream& operator>>(istream& in, BiletClasaII& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const BiletClasaII& obj) {
    obj.afisare(out);
    return out;
}


class BiletInterRegio : virtual public Bilet {
protected:
    int locRez;
public:
    BiletInterRegio(const string &serie, const string &plecare, const string &sosire, int zip, int lunap, int anp,
                    const string &codtren, const string &clasa, int durata, int distanta, double pret, int locRez);
    void SerieBilet();
    void PretBilet();
    ~BiletInterRegio();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, BiletInterRegio& obj);
    friend ostream& operator<<(ostream& out, const BiletInterRegio& obj);

    int getLocRez() const;

    void setLocRez(int locRez);
};
BiletInterRegio::BiletInterRegio(const string &serie="", const string &plecare="", const string &sosire="",
                                 int zip=0, int lunap=0, int anp=0, const string &codtren="", const string &clasa="",
                                 int durata=0, int distanta=0, double pret=0, int locRez=0) : Bilet(serie, plecare,
                                                                                                    sosire, zip, lunap, anp, codtren, clasa, durata, distanta, pret), locRez(locRez) {}
BiletInterRegio::~BiletInterRegio() {
    locRez=0;
}

int BiletInterRegio::getLocRez() const {
    return locRez;
}

void BiletInterRegio::setLocRez(int locRez) {
    this->locRez = locRez;
}

void BiletInterRegio::SerieBilet() {
    stringstream ss;
    ss<<nrOrd;
    string s;
    ss>>s;
    serie="IRII-"+s;
}

void BiletInterRegio::PretBilet() {
    pret=0.7*distanta;
}

void BiletInterRegio::citire(istream& in) {
    Bilet::citire(in);
    cout << "Loc rezervat: ";
    in >> locRez;
    codtren="IR";
}
void BiletInterRegio::afisare(ostream& out) const {
    Bilet::afisare(out);
    out << ", cu locul rezervat: " << locRez;
}
istream& operator>>(istream& in, BiletInterRegio& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const BiletInterRegio& obj) {
    obj.afisare(out);
    return out;
}


class BiletClasaI : virtual public Bilet {
protected:
    string felI, felII, desert;
public:
    BiletClasaI(const string &serie, const string &plecare, const string &sosire, int zip, int lunap, int anp,
                const string &codtren, const string &clasa, int durata, int distanta, double pret, const string &felI,
                const string &felII, const string &desert);

    const string &getFelI() const;

    void setFelI(const string &felI);

    const string &getFelIi() const;

    void setFelII(const string &felII);

    const string &getDesert() const;

    void setDesert(const string &desert);
    void SerieBilet();
    void PretBilet();
    ~BiletClasaI();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, BiletClasaI& obj);
    friend ostream& operator<<(ostream& out, const BiletClasaI& obj);
};
BiletClasaI::BiletClasaI(const string &serie="", const string &plecare="", const string &sosire="", int zip=0,
                         int lunap=0, int anp=0, const string &codtren="", const string &clasa="", int durata=0, int distanta=0, double pret=0,
                         const string &felI="", const string &felII="", const string &desert="") : Bilet(serie, plecare, sosire,
                                                                                                         zip, lunap, anp,
                                                                                                         codtren, clasa, durata,
                                                                                                         distanta, pret),
                                                                                                   felI(felI), felII(felII),
                                                                                                   desert(desert) {}

BiletClasaI::~BiletClasaI() {
    felI="";
    felII="";
    desert="";
}
const string &BiletClasaI::getFelI() const {
    return felI;
}

void BiletClasaI::setFelI(const string &felI) {
    this->felI = felI;
}

const string &BiletClasaI::getFelIi() const {
    return felII;
}

void BiletClasaI::setFelII(const string &felII) {
    this->felII = felII;
}

const string &BiletClasaI::getDesert() const {
    return desert;
}

void BiletClasaI::setDesert(const string &desert) {
    this->desert = desert;
}
void BiletClasaI::SerieBilet() {
    stringstream ss;
    ss<<nrOrd;
    string s;
    ss>>s;
    serie="RI-"+s;
}

void BiletClasaI::PretBilet() {
    pret=0.39*distanta;
    pret=0.2*pret;
}

void BiletClasaI::citire(istream& in) {
    Bilet::citire(in);
    cout << "Felul I: ";
    in.get();
    getline(in, felI);
    cout<<"Felul II: ";
    getline(in, felII);
    cout<<"Desert: ";
    getline(in, desert);
}
void BiletClasaI::afisare(ostream& out) const {
    Bilet::afisare(out);
    out << "\nPasagerul beneficiaza si de un meniu format din " << felI<<", "<<felII<<"si desert: "<<desert;
}
istream& operator>>(istream& in, BiletClasaI& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const BiletClasaI& obj) {
    obj.afisare(out);
    return out;
}


class BiletInterRegioClasaI : public BiletInterRegio, public BiletClasaI {


public:
    BiletInterRegioClasaI(const string &serie, const string &plecare, const string &sosire, int zip, int lunap, int anp,
                          const string &codtren, const string &clasa, int durata, int distanta, double pret, int locRez,
                          const string &serie1, const string &plecare1, const string &sosire1, int zip1, int lunap1,
                          int anp1, const string &codtren1, const string &clasa1, int durata1, int distanta1,
                          double pret1, const string &felI, const string &felIi, const string &desert);
    ~BiletInterRegioClasaI();
    void SerieBilet();
    void PretBilet();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, BiletInterRegioClasaI& obj);
    friend ostream& operator<<(ostream& out, const BiletInterRegioClasaI& obj);
};
BiletInterRegioClasaI::BiletInterRegioClasaI(const string &serie="", const string &plecare="", const string &sosire="",
                                             int zip=0, int lunap=0, int anp=0, const string &codtren="", const string &clasa="", int durata=0, int distanta=0,
                                             double pret=0, int locRez=0, const string &serie1="", const string &plecare1="", const string &sosire1="",
                                             int zip1=0, int lunap1=0, int anp1=0, const string &codtren1="", const string &clasa1="", int durata1=0, int distanta1=0,
                                             double pret1=0, const string &felI="", const string &felIi="", const string &desert="") :
        BiletInterRegio(serie, plecare, sosire, zip, lunap, anp, codtren, clasa, durata, distanta, pret, locRez),
        BiletClasaI(serie1, plecare1, sosire1, zip1, lunap1, anp1, codtren1, clasa1, durata1, distanta1, pret1, felI, felIi,
                    desert) {}
BiletInterRegioClasaI::~BiletInterRegioClasaI() {}
void BiletInterRegioClasaI::SerieBilet() {
    stringstream ss;
    ss<<nrOrd;
    string s;
    ss>>s;
    serie="IRI-"+s;
}

void BiletInterRegioClasaI::PretBilet() {
    BiletInterRegio::PretBilet();
    pret=0.2*pret;
}

void BiletInterRegioClasaI::citire(istream& in) {
    BiletClasaI::citire(in);
    cout << "Loc rezervat: ";
    in >>locRez;
}
void BiletInterRegioClasaI::afisare(ostream& out) const {
    BiletClasaI::afisare(out);
    out << ", cu locul rezervat: " << locRez;
}
istream& operator>>(istream& in, BiletInterRegioClasaI& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const BiletInterRegioClasaI& obj) {
    obj.afisare(out);
    return out;
}


///----------------------------clasa AGENTIE-SINGLETON----------------------------

class Agentie { //SINGLETON
private:
    string numeAgentie;
    static Agentie* instance;
    Agentie(string = "");
    vector<Bilet*> bilete;

public:
    static Agentie* getInstance(string);
    Agentie(const Agentie& obj);
    ~Agentie();

    const string &getNumeAgentie() const;

    void setNumeAgentie(const string &numeAgentie);

    void menu_output();
    void citesteBilete();
    void afiseazaBilete();
    void afiseazaCod(string cod);
    void afiseazaDistanta(int distanta);
    void anulareBilet(string serie);
    ///celelalte metode
    Agentie& operator=(Agentie& obj);

};
Agentie* Agentie::instance = NULL;

Agentie::Agentie(string numeAgentie): numeAgentie(numeAgentie) {}

Agentie* Agentie::getInstance(string numeAgentie) {
    if(instance == NULL) {
        instance = new Agentie(numeAgentie);
    }
    return instance;
}
Agentie::Agentie(const Agentie& obj) {
    this->numeAgentie= obj.numeAgentie;
    for(unsigned int i=0; i < bilete.size(); i++)
        this->bilete.push_back(obj.bilete[i]);
}

Agentie::~Agentie() {
    numeAgentie="";
    for(unsigned int i=0; i < bilete.size(); i++)
        delete bilete[i];
    bilete.clear();
}

void Agentie::menu_output() {
    cout << "\nAGENTIE\n";
    cout << "Agentie: " << this->numeAgentie << "\n";
    cout << "\n\t\tMENIU:";
    cout << "\n===========================================\n";
    cout << "\n1. Elibereaza bilet";
    cout << "\n2. Listare bilete";
    cout << "\n3. Listare bilete dupa cod";
    cout << "\n4. Listare bilete pentru o distanta mai mare decat una data";
    cout << "\n5. Anulare bilet dupa serie";
    cout << "\n0. Iesire.";
    cout << "\n";
}

const string &Agentie::getNumeAgentie() const {
    return numeAgentie;
}

void Agentie::setNumeAgentie(const string &numeAgentie) {
    Agentie::numeAgentie = numeAgentie;
}
void Agentie::citesteBilete() {
    int n;
    cout << "Cate bilete doriti? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout<<"\nBilet "<<i+1<<":\n";
        string tip;
        cout << "Mentionati tipul biletului(RegioClasaI/RegioClasaII/IRegioClasaI/IRegioClasaII): ";
        cin.get();
        getline(cin, tip);
        try {
            if (tip == "RegioClasaI") {
                Bilet* p = new BiletClasaI;
                cin >> *p;
                p->PretBilet();
                p->SerieBilet();
                bilete.push_back(p);
            }
            else if (tip == "RegioClasaII") {
                Bilet* p = new BiletClasaII;
                cin >> *p;
                p->PretBilet();
                p->SerieBilet();
                bilete.push_back(p);
            }
            else if (tip == "IRegioClasaI") {
                Bilet* p = new BiletInterRegioClasaI;
                cin >> *p;
                p->PretBilet();
                p->SerieBilet();
                bilete.push_back(p);
            }
            else if (tip == "IRegioClasaII") {
                Bilet* p = new BiletInterRegio;
                cin >> *p;
                p->PretBilet();
                p->SerieBilet();
                bilete.push_back(p);
            }
            else
                throw 10;
        }
        catch (bad_alloc var) {
            cout << "Allocation Failure\n";
            exit(EXIT_FAILURE);
        }
    }
}

void Agentie::afiseazaBilete() {
    cout << "Agentia a eliberat " << bilete.size() << " bilete:";
    for(unsigned int i=0; i < bilete.size(); i++) {
        cout<<*bilete[i];
    }
}

void Agentie::afiseazaCod(string cod) {
    for(unsigned int i=0;i<bilete.size();i++)
        if(bilete[i]->getCodtren()==cod)
            cout<<*bilete[i];
}

void Agentie::afiseazaDistanta(int distanta) {
    for(unsigned int i=0;i<bilete.size();i++)
        if(bilete[i]->getDistanta()>distanta)
            cout<<*bilete[i];
}

void Agentie::anulareBilet(string serie) {
    for(unsigned int i=0;i<bilete.size();i++)
        if(bilete[i]->getSerie()==serie)
            bilete.erase(remove(bilete.begin(), bilete.end(), bilete[i]), bilete.end());
}

Agentie& Agentie::operator=(Agentie& obj) {
    if (this != &obj) {
        this->numeAgentie= obj.numeAgentie;
        for(unsigned int i=0; i < bilete.size(); i++)
            this->bilete.push_back(obj.bilete[i]);
    }
    return *this;
}



///------------------------------MENIU-----------------------------

void menu() {
    int option;///optiunea aleasa din meniu
    option = 0;
    Agentie *C = C->getInstance("CFR");
    do {
        C->menu_output();
        cout << "\nIntroduceti numarul actiunii: ";
        cin >> option;
        if(option == 1) {
            C->citesteBilete();
        }
        else if(option == 2) {
            C->afiseazaBilete();
        }
        if(option == 3) {
            cout<<"Cod tren(R/IR): ";
            string cod;
            cin>>cod;
            C->afiseazaCod(cod);
        }
        if(option == 4) {
            cout<<"Distanta: ";
            int dist;
            cin>>dist;
            C->afiseazaDistanta(dist);
        }
        if(option == 5) {
            cout<<"Serie bilet: ";
            string serie;
            cin.get();
            getline(cin, serie);
            C->anulareBilet(serie);
        }
        if (option == 0) {
            cout << "\nEXIT!\n";
        }
        if (option < 0 || option>5) {
            cout << "\nSelectie invalida\n";
        }
        cout << '\n';
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while (option != 0);
}
int main() {
    menu();
    return 0;
}
