#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
class Proprietate {
protected:
    string adresa;
    double sloc;
    double chirie;
    string stadiu;
public:
    Proprietate(const string &adresa, double sloc, double chirie, const string &stadiu);
    virtual ~Proprietate();

    const string &getAdresa() const;

    void setAdresa(const string &adresa);

    double getSloc() const;

    void setSloc(double sloc);

    double getChirie() const;

    void setChirie(double chirie);

    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Proprietate& obj);
    friend ostream& operator<<(ostream& out, const Proprietate& obj);
};

Proprietate::Proprietate(const string &adresa="", double sloc=0, double chirie=0, const string &stadiu="") : adresa(adresa), sloc(sloc),
                                                                                    chirie(chirie) {}


Proprietate::~Proprietate() {
    adresa = "";
    sloc = 0;
    chirie = 0;
    stadiu="";
}

const string &Proprietate::getAdresa() const {
    return adresa;
}

void Proprietate::setAdresa(const string &adresa) {
    this->adresa = adresa;
}

double Proprietate::getSloc() const {
    return sloc;
}

void Proprietate::setSloc(double sloc) {
    this->sloc = sloc;
}

double Proprietate::getChirie() const {
    return chirie;
}

void Proprietate::setChirie(double chirie) {
    this->chirie = chirie;
}

void Proprietate::citire(istream& in) {
    cout << "Care este adresa proprietatii? ";
    in.get();
    getline(in, adresa);
    cout << "Suprafata locuibila: ";
    in >> sloc;
    cout << "Chirie: ";
    in >> chirie;
    stadiu="libera";
}
void Proprietate::afisare(ostream& out) const {
    out << "\nAdresa: " << adresa<<", suprafata locuibila: "<<sloc<<" mp, chirie: "<<chirie<<"/mp";
}
istream& operator>>(istream& in, Proprietate& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Proprietate& obj) {
    obj.afisare(out);
    return out;
}



class Casa :public Proprietate {
protected:
    int nivele;
    double scurte;
public:
    Casa(const string &adresa, double sloc, double chirie, const string &stadiu, int nivele, double scurte);
    ~Casa();

    int getNivele() const;

    void setNivele(int nivele);

    double getScurte() const;

    void setScurte(double scurte);

    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Casa& obj);
    friend ostream& operator<<(ostream& out, const Casa& obj);
};

Casa::Casa(const string &adresa="", double sloc=0, double chirie=0, const string &stadiu="", int nivele=0, double scurte=0) : Proprietate(
        adresa, sloc, chirie, stadiu), nivele(nivele), scurte(scurte) {}
Casa::~Casa() {
    nivele=0;
    scurte=0;
}


int Casa::getNivele() const {
    return nivele;
}

void Casa::setNivele(int nivele) {
    Casa::nivele = nivele;
}

double Casa::getScurte() const {
    return scurte;
}

void Casa::setScurte(double scurte) {
    Casa::scurte = scurte;
}
void Casa::citire(istream& in) {
    Proprietate::citire(in);
    cout << "Nivele: ";
    in >> nivele;
    cout<< "Suprafata curte: ";
    in>>scurte;
}
void Casa::afisare(ostream& out) const {
    Proprietate::afisare(out);
    out << ", numar nivele: "<<nivele<<", suprafata curte: "<<scurte<<" mp";
}
istream& operator>>(istream& in, Casa& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Casa& obj) {
    obj.afisare(out);
    return out;
}




class Apartament :public Proprietate {
    int etaj;
    int nrcamere;
public:
    Apartament(const string &adresa, double sloc, double chirie, const string &stadiu, int etaj, int nrcamere);
    ~Apartament();

    int getEtaj() const;

    void setEtaj(int etaj);

    int getNrcamere() const;

    void setNrcamere(int nrcamere);

    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Apartament& obj);
    friend ostream& operator<<(ostream& out, const Apartament& obj);
};

Apartament::Apartament(const string &adresa="", double sloc=0, double chirie=0, const string &stadiu="",
        int etaj=0, int nrcamere=0) : Proprietate(adresa,
        sloc, chirie, stadiu), etaj(etaj), nrcamere(nrcamere) {}

Apartament::~Apartament() {
    etaj=0;
    nrcamere=0;
}
int Apartament::getEtaj() const {
    return etaj;
}

void Apartament::setEtaj(int etaj) {
    this->etaj = etaj;
}

int Apartament::getNrcamere() const {
    return nrcamere;
}

void Apartament::setNrcamere(int nrcamere) {
    this->nrcamere = nrcamere;
}

void Apartament::citire(istream& in) {
    Proprietate::citire(in);
    cout << "Etaj(0-Parter/1/...): ";
    in >> etaj;
    cout<<"Numar camere: ";
    in>>nrcamere;
}
void Apartament::afisare(ostream& out) const {
    Proprietate::afisare(out);
    out << ", etaj: " << etaj<<", numar camere: "<<nrcamere;
}
istream& operator>>(istream& in, Apartament& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Apartament& obj) {
    obj.afisare(out);
    return out;
}


class Contract {
protected:
    string client;
    double discount;
    Proprietate* prop=NULL;
public:
    Contract(const string &client, double discount);

   double getDiscount() const {
        return discount;
    }

    void setDiscount(double discount) {
        this->discount = discount;
    }

    const string &getClient() const;

    void setClient(const string &client);

    virtual ~Contract();
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Contract& obj);
    friend ostream& operator<<(ostream& out, const Contract& obj);
};
Contract::Contract(const string &client="", double discount=0) : client(client), discount(discount) {}

Contract::~Contract() {
    client="";
    discount=0;
    prop=NULL;
}
const string &Contract::getClient() const {
    return client;
}

void Contract::setClient(const string &client) {
    this->client = client;
}
void Contract::citire(istream& in) {
    cout << "Nume client: ";
    in.get();
    getline(in, client);
}
void Contract::afisare(ostream& out) const {
    out << "\nNume client: "<<client;
}
istream& operator>>(istream& in, Contract& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Contract& obj) {
    obj.afisare(out);
    return out;
}




class ContractInchiriere : public Contract {
protected:
    int luna_inc, an_inc;
    int luna_fin, an_fin;
    double chlunara;
public:
    ContractInchiriere(const string &client, double discount, int lunaInc, int anInc, int lunaFin, int anFin,
                       double chlunara);

    ~ContractInchiriere();
    virtual void calculChirie()=0;
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ContractInchiriere& obj);
    friend ostream& operator<<(ostream& out, const ContractInchiriere& obj);
};
ContractInchiriere::ContractInchiriere(const string &client="", double discount=0, int lunaInc=0, int anInc=0, int lunaFin=0,
                                       int anFin=0, double chlunara=0) : Contract(client, discount), luna_inc(lunaInc),
                                                                         an_inc(anInc), luna_fin(lunaFin), an_fin(anFin),
                                                                         chlunara(chlunara) {}
ContractInchiriere::~ContractInchiriere() {
    luna_inc=0;
    luna_fin=0;
    an_inc=0;
    an_fin=0;
    chlunara=0;
}
void ContractInchiriere::citire(istream& in) {
    Contract::citire(in);
    cout << "Luna incepere contract: ";
    in >> luna_inc;
    cout << "An incepere contract: ";
    in >> an_inc;
    cout << "Luna terminare contract: ";
    in >> luna_fin;
    cout << "An terminare contract: ";
    in >> an_fin;
}
void ContractInchiriere::afisare(ostream& out) const {
    Contract::afisare(out);
    out << ", perioada contract: " << luna_inc<<'.'<<an_inc<<"-"<<luna_fin<<'.'<<an_fin<<", chirie lunara: "<<chlunara;
    out<<" RON";
}
istream& operator>>(istream& in, ContractInchiriere& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ContractInchiriere& obj) {
    obj.afisare(out);
    return out;
}

class ContractCumparare : public Contract {
protected:
    int luna_tranz, an_tranz;
    int luna_fin, an_fin;
    double pretPropr;
public:
    ContractCumparare(const string &client, double discount, int lunaTranz, int anTranz, int lunaFin, int anFin,
                      double pretPropr);

    ~ContractCumparare();
    virtual void calculPret()=0;
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ContractCumparare& obj);
    friend ostream& operator<<(ostream& out, const ContractCumparare& obj);
};

ContractCumparare::ContractCumparare(const string &client="", double discount=0, int lunaTranz=0, int anTranz=0, int lunaFin=0,
                                     int anFin=0, double pretPropr=0) : Contract(client, discount), luna_tranz(lunaTranz),
                                                                    an_tranz(anTranz), luna_fin(lunaFin), an_fin(anFin),
                                                                    pretPropr(pretPropr) {}
ContractCumparare::~ContractCumparare() {
    luna_fin=0;
    luna_tranz=0;
    an_fin=0;
    an_tranz=0;
    pretPropr=0;
}
void ContractCumparare::citire(istream& in) {
    Contract::citire(in);
    cout << "Luna tranzactie: ";
    in >> luna_tranz;
    cout << "An tranzactie: ";
    in >> an_tranz;
    cout << "Luna plata finala: ";
    in >> luna_fin;
    cout << "An plata finala: ";
    in >> an_fin;
}
void ContractCumparare::afisare(ostream& out) const {
    Contract::afisare(out);
    out << ", perioada achitare: " << luna_tranz<<'.'<<an_tranz<<"-"<<luna_fin<<'.'<<an_fin<<", pret proprietate: "<<pretPropr;
    out<<" RON";
}
istream& operator>>(istream& in, ContractCumparare& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ContractCumparare& obj) {
    obj.afisare(out);
    return out;
}

class Inchiriere : public ContractInchiriere {
public:
    Inchiriere(const string &client, double discount, int lunaInc, int anInc, int lunaFin, int anFin, double chlunara);
    ~Inchiriere();
    void calculChirie();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Inchiriere& obj);
    friend ostream& operator<<(ostream& out, const Inchiriere& obj);
};
Inchirierea::Inchiriere(const string &client="", double discount=0, int lunaInc=0, int anInc=0, int lunaFin=0, int anFin=0,
                               double chlunara=0) : ContractInchiriere(client, discount, lunaInc, anInc, lunaFin, anFin,
                                                                       chlunara) {}
Inchiriere::~Inchiriere() {
}
void Inchiriere::calculChirie() {
    double disc=0;
    if(an_inc<an_fin){
        if(an_fin-an_inc>2) disc=0.1;
        else if(an_fin-an_inc==2){
            if(luna_inc<=luna_fin) disc=0.1;
            else disc=0.05;
        }
        else if(an_fin-an_inc==1){
            if(luna_inc<=luna_fin) disc=0.05;
        }
    }
    discount=disc;
    chlunara=prop->getChirie()*(prop->getSloc()+0.2*prop->getScurte())*(1-discount);
}
void Inchiriere::citire(istream& in) {
    ContractInchiriere::citire(in);
    Casa::citire(in);
    calculChirie();
}
void Inchiriere::afisare(ostream& out) const {
    ContractInchiriere::afisare(out);
    Casa::afisare(out);
}
istream& operator>>(istream& in, Inchiriere& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Inchiriere& obj) {
    obj.afisare(out);
    return out;
}




class InchiriereApartament : public Apartament, public ContractInchiriere {
public:
    InchiriereApartament(const string &adresa, double sloc, double chirie, int etaj, int nrcamere, const string &client,
                         double discount, int lunaInc, int anInc, int lunaFin, int anFin, double chlunara);

    ~InchiriereApartament();
    void calculChirie();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, InchiriereApartament& obj);
    friend ostream& operator<<(ostream& out, const InchiriereApartament& obj);
};

InchiriereApartament::InchiriereApartament(const string &adresa="", double sloc=0, double chirie=0, int etaj=0, int nrcamere=0,
                                           const string &client="", double discount=0, int lunaInc=0, int anInc=0, int lunaFin=0,
                                           int anFin=0, double chlunara=0) : Apartament(adresa, sloc, chirie, etaj,
                                                                                    nrcamere),
                                                                         ContractInchiriere(client, discount, lunaInc,
                                                                                            anInc, lunaFin, anFin,
                                                                                            chlunara) {}

InchiriereApartament::~InchiriereApartament() {
}
void InchiriereApartament::calculChirie() {
    double disc=0;
    if(an_inc<an_fin){
        if(an_fin-an_inc>2) disc=0.1;
        else if(an_fin-an_inc==2){
            if(luna_inc<=luna_fin) disc=0.1;
            else disc=0.05;
        }
        else if(an_fin-an_inc==1){
            if(luna_inc<=luna_fin) disc=0.05;
        }
    }
    discount=disc;
    chlunara=chirie*sloc*(1-discount);
}
void InchiriereApartament::citire(istream& in) {
    ContractInchiriere::citire(in);
    Apartament::citire(in);
    calculChirie();
}
void InchiriereApartament::afisare(ostream& out) const {
    ContractInchiriere::afisare(out);
    Apartament::afisare(out);
}
istream& operator>>(istream& in, InchiriereApartament& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const InchiriereApartament& obj) {
    obj.afisare(out);
    return out;
}

class CumparareCasa : public Casa, public ContractCumparare {
public:
    CumparareCasa(const string &adresa, double sloc, double chirie, int nivele, double scurte, const string &client,
                  double discount, int lunaTranz, int anTranz, int lunaFin, int anFin, double pretPropr);

    ~CumparareCasa();
    void calculPret();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, CumparareCasa& obj);
    friend ostream& operator<<(ostream& out, const CumparareCasa& obj);
};
CumparareCasa::CumparareCasa(const string &adresa="", double sloc=0, double chirie=0, int nivele=0, double scurte=0,
                             const string &client="", double discount=0, int lunaTranz=0, int anTranz=0, int lunaFin=0, int anFin=0,
                             double pretPropr=0) : Casa(adresa, sloc, chirie, nivele, scurte),
                                                 ContractCumparare(client, discount, lunaTranz, anTranz, lunaFin, anFin,
                                                                   pretPropr) {}
CumparareCasa::~CumparareCasa() {
}
void CumparareCasa::calculPret() {
    double disc=0;
    int rate=0;
    if(luna_fin==luna_tranz&&an_tranz==an_fin) rate=0;
    else{
        if(an_tranz==an_fin) rate=luna_fin-luna_tranz;
        else rate=12-luna_tranz+an_fin-an_tranz-1+luna_fin;
    }
    if(rate==0) disc=0.1;
    else if(rate<=60) disc=0.07;
    else if(rate<=120) disc=0.05;
    try{
        if(rate>240)
            throw 1;
    }
    catch(int i){
        cout<<"Prea multe rate, nu ti-o dau.";
    }
    discount=disc;
    pretPropr=240*(chirie*(sloc+0.2*scurte))*(1-discount);
}
void CumparareCasa::citire(istream& in) {
    ContractCumparare::citire(in);
    Casa::citire(in);
    calculPret();
}
void CumparareCasa::afisare(ostream& out) const {
    ContractCumparare::afisare(out);
    Casa::afisare(out);
}
istream& operator>>(istream& in, CumparareCasa& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const CumparareCasa& obj) {
    obj.afisare(out);
    return out;
}

class CumparareApartament : public Apartament, public ContractCumparare {
public:
    CumparareApartament(const string &adresa, double sloc, double chirie, int etaj, int nrcamere, const string &client,
                        double discount, int lunaTranz, int anTranz, int lunaFin, int anFin, double pretPropr);

    ~CumparareApartament();
    void calculPret();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, CumparareApartament& obj);
    friend ostream& operator<<(ostream& out, const CumparareApartament& obj);
};

CumparareApartament::CumparareApartament(const string &adresa="", double sloc=0, double chirie=0, int etaj=0, int nrcamere=0,
        const string &client="", double discount=0, int lunaTranz=0, int anTranz=0, int lunaFin=0,
        int anFin=0, double pretPropr=0) : Apartament(adresa, sloc, chirie, etaj, nrcamere),
        ContractCumparare(client, discount, lunaTranz, anTranz, lunaFin, anFin,pretPropr) {}

CumparareApartament::~CumparareApartament() {
}
void CumparareApartament::calculPret() {
    double disc=0;
    int rate=0;
    if(luna_fin==luna_tranz&&an_tranz==an_fin) rate=0;
    else{
        if(an_tranz==an_fin) rate=luna_fin-luna_tranz;
        else rate=12-luna_tranz+an_fin-an_tranz-1+luna_fin;
    }
    if(rate==0) disc=0.1;
    else if(rate<=60) disc=0.07;
    else if(rate<=120) disc=0.05;
    try{
        if(rate>240)
            throw 1;
    }
    catch(int i){
        cout<<"Prea multe rate, nu ti-o dau.";
    }
    discount=disc;
    pretPropr=240*chirie*sloc*(1-discount);
}
void CumparareApartament::citire(istream& in) {
    ContractCumparare::citire(in);
    Apartament::citire(in);
    calculPret();
}
void CumparareApartament::afisare(ostream& out) const {
    ContractCumparare::afisare(out);
    Apartament::afisare(out);
}
istream& operator>>(istream& in, CumparareApartament& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const CumparareApartament& obj) {
    obj.afisare(out);
    return out;
}


///----------------------------clasa PROPRIETATI-SINGLETON----------------------------

class Agentie { //SINGLETON
private:
    string numeAgentie;
    static Agentie* instance;
    Agentie(string = "");
    vector<Proprietate*> proprietati;
    vector<Contract*> contracte;
public:
    static Agentie* getInstance(string);
    Agentie(const Agentie& obj);
    ~Agentie();

    const string &getNumeAgentie() const;

    void setNumeAgentie(const string &numeAgentie);

    void menu_output();
    void citesteProprietati();
    void citesteContracte();
    void afiseazaProprietati();
    void afiseazaContracte();
    void afiseazaProprietati(int luna, int an);
    void afiseazaSuma();
    Agentie& operator=(Agentie& obj);

};
Agentie* Agentie::instance = NULL;

Agentie::Agentie(string numeDoctor): numeAgentie(numeDoctor) {}

Agentie* Agentie::getInstance(string numeDoctor) {
    if(instance == NULL) {
        instance = new Agentie(numeDoctor);
    }
    return instance;
}
Agentie::Agentie(const Agentie& obj) {
    this->numeAgentie= obj.numeAgentie;
    for(unsigned int i=0; i < proprietati.size(); i++)
        this->proprietati.push_back(obj.proprietati[i]);
    for(unsigned int i=0; i < contracte.size(); i++)
        this->contracte.push_back(obj.contracte[i]);
}

Agentie::~Agentie() {
    numeAgentie="";
    for(unsigned int i=0; i < proprietati.size(); i++)
        delete proprietati[i];
    for(unsigned int i=0; i < contracte.size(); i++)
        delete contracte[i];
    proprietati.clear();
    contracte.clear();
}
void Agentie::menu_output() {
    cout << "\nPROPRIETATI\n";
    cout << "Agentie: " << this->numeAgentie << "\n";
    cout << "\n\t\tMENIU:";
    cout << "\n===========================================\n";
    cout << "\n1. Citeste proprietati --- UPCAST & LATE-BINDING";
    cout << "\n2. Citeste contracte --- UPCAST & LATE-BINDING";
    cout << "\n3. Afiseaza proprietati";
    cout << "\n4. Afiseaza contracte";
    cout << "\n5. Afiseaza proprietati la o anumita data";
    cout << "\n6. Afiseaza suma de incasat la o anumita data de la proprietati";
    cout << "\n0. Iesire.";
    cout << "\n";
}
const string &Agentie::getNumeAgentie() const {
    return numeAgentie;
}

void Agentie::setNumeAgentie(const string &numeAgentie) {
    this->numeAgentie = numeAgentie;
}
/*
    cout << "\n3. Afiseaza proprietati";
    cout << "\n4. Afiseaza contracte";
    cout << "\n5. Afiseaza proprietati la o anumita data";
    cout << "\n6. Afiseaza suma de incasat la o anumita data de la proprietati";*/
void Agentie::citesteProprietati() {
    int n;
    cout << "Cate proprietati are agentia? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout<<"\nProprietatea "<<i+1<<":\n";
        string tip;
        cout << "Mentionati tipul proprietatii(Casa/Apartament): ";
        cin.get();
        getline(cin, tip);
        try {
            if (tip == "Casa") {
                Proprietate* p = new Casa;
                cin >> *p;
                proprietati.push_back(p);
            }
            else if (tip == "Apartament") {
                Proprietate* p = new Apartament;
                cin >> *p;
                proprietati.push_back(p);
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


void Agentie::citesteContracte() {
    int n;
    cout << "Cate contracte are agentia? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout<<"\nContract "<<i+1<<":\n";
        string tip;
        cout << "Mentionati tipul contractului(InchiriereCasa/InchiriereApartament/CumparareCasa/CumparareApartament): ";
        cin.get();
        getline(cin, tip);
        try {
            if (tip == "InchiriereCasa") {
                Contract* p = new InchiriereCasa;
                cin >> *p;
                contracte.push_back(p);
            }
            else if (tip == "InchiriereApartament") {
                Contract* p = new InchiriereApartament;
                cin >> *p;
                contracte.push_back(p);
            }
            else if (tip == "CumparareCasa") {
                Contract* p = new CumparareCasa;
                cin >> *p;
                contracte.push_back(p);
            }
            else if (tip == "CumparareApartament") {
                Contract* p = new CumparareApartament;
                cin >> *p;
                contracte.push_back(p);
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

void Agentie::afiseazaProprietati() {
    cout << "Agentia are " << proprietati.size() << " proprietati";
    cout<<"\nCase: ";
    for(unsigned int i=0; i < proprietati.size(); i++) {
        Casa* p=dynamic_cast<Casa*>(proprietati[i]);
        if(p)
            cout<<*proprietati[i];
    }
    cout<<"\nApartamente: ";
    for(unsigned int i=0; i < proprietati.size(); i++) {
        Apartament* p=dynamic_cast<Apartament*>(proprietati[i]);
        if(p)
            cout<<*proprietati[i];
    }
}

void Agentie::afiseazaContracte() {
    cout << "Agentia are " << contracte.size() << " contracte";
    cout<<"\nInchiriere: ";
    for(unsigned int i=0; i < contracte.size(); i++) {
        InchiriereCasa* p1=dynamic_cast<InchiriereCasa*>(contracte[i]);
        InchiriereApartament* p2= dynamic_cast<InchiriereApartament*>(contracte[i]);
        if(p1||p2)
            cout<<*contracte[i];
    }
    cout<<"\nCumparare: ";
    for(unsigned int i=0; i < contracte.size(); i++) {
        CumparareCasa* p1=dynamic_cast<CumparareCasa*>(contracte[i]);
        CumparareApartament* p2= dynamic_cast<CumparareApartament*>(contracte[i]);
        if(p1||p2)
            cout<<*contracte[i];
    }
}

void Agentie::afiseazaProprietati(int luna, int an) {

}

void Agentie::afiseazaSuma() {

}


Agentie& Agentie::operator=(Agentie& obj) {
    if (this != &obj) {
        this->numeAgentie= obj.numeAgentie;
        for(unsigned int i=0; i < proprietati.size(); i++)
            this->proprietati.push_back(obj.proprietati[i]);
        for(unsigned int i=0; i < contracte.size(); i++)
            this->contracte.push_back(obj.contracte[i]);
    }
    return *this;
}




///------------------------------MENIU-----------------------------

void menu() {
    int option;///optiunea aleasa din meniu
    option = 0;
    Agentie *C = C->getInstance("Popescu Ion");
    do {
        C->menu_output();
        cout << "\nIntroduceti numarul actiunii: ";
        cin >> option;
        if(option == 1) {
            C->citesteProprietati();
        }
        else if(option == 2) {
            C->citesteContracte();
        }
        if(option == 3) {
            C->afiseazaProprietati();
        }
        if(option == 4) {
            C->afiseazaContracte();
        }
        if(option == 5) {
            int luna, an;
            cout<<"\nLuna respectiva: ";
            cin>>luna;
            cout<<"Anul respectiv: ";
            cin>>an;
            C->afiseazaProprietati(luna, an);
        }
        if(option == 6) {
            C->afiseazaSuma();
        }
        if (option == 0) {
            cout << "\nEXIT!\n";
        }
        if (option < 0 || option>6) {
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