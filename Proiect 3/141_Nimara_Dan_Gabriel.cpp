#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
using namespace std;

///------------------------------clasa CONT-----------------------------

class Cont {
protected:
    string detinator;
    int zi_d, luna_d, an_d;
    double sold;
public:
    Cont();
    Cont(string detinator, int zi_d, int luna_d, int an_d, double sold);
    Cont(const Cont& obj);
    virtual ~Cont();
    string getDetinator() {
        return detinator;
    }
    void setDetinator(string detinator) {
        this->detinator = detinator;
    }
    int getZi_d() {
        return zi_d;
    }
    void setZi_d(int zi_d) {
        this->zi_d = zi_d;
    }
    int getLuna_d() {
        return luna_d;
    }
    void setLuna_d(int luna_d) {
        this->luna_d = luna_d;
    }
    int getAn_d() {
        return an_d;
    }
    void setAn_d(int an_d) {
        this->an_d = an_d;
    }
    double getSold() {
        return sold;
    }
    void setSold(double sold) {
        this->sold = sold;
    }
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Cont& obj);
    friend ostream& operator<<(ostream& out, const Cont& obj);
    Cont& operator=(const Cont& obj);
};

Cont::Cont() {
    detinator = "";
    zi_d = 0;
    luna_d = 0;
    an_d = 0;
    sold = 0;
}
Cont::Cont(string detinator, int zi_d, int luna_d, int an_d, double sold) : detinator(detinator), zi_d(zi_d), luna_d(luna_d), an_d(an_d), sold(sold) {}
Cont::Cont(const Cont& obj) {
    this->detinator = obj.detinator;
    this->zi_d = obj.zi_d;
    this->luna_d = obj.luna_d;
    this->an_d = obj.an_d;
    this->sold = obj.sold;
}
Cont::~Cont() {
    detinator = "";
    zi_d = 0;
    luna_d = 0;
    an_d = 0;
    sold = 0;
}
void Cont::citire(istream& in) {
    in.get();
    cout << "Care este numele detinatorului? ";
    getline(in, detinator);
    cout << "Care este ziua deschiderii contului? ";
    in >> zi_d;
    cout << "Care este luna deschiderii contului? ";
    in >> luna_d;
    cout << "Care este anul deschiderii contului? ";
    in >> an_d;
    cout << "Care este soldul contului? ";
    in >> sold;
}
void Cont::afisare(ostream& out) const {
    out << "\nNumele detinatorului este " << detinator;
    out << "\nData deschiderii contului este " << zi_d << "." << luna_d << "." << an_d;
    out << "\nSoldul curent al contului este " << sold << " lei";
}
istream& operator>>(istream& in, Cont& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Cont& obj) {
    obj.afisare(out);
    return out;
}
Cont& Cont::operator=(const Cont& obj) {
    if (this != &obj) {
        this->detinator = obj.detinator;
        this->zi_d = obj.zi_d;
        this->luna_d = obj.luna_d;
        this->an_d = obj.an_d;
        this->sold = obj.sold;
    }
    return *this;
}

///------------------------------clasa ISTORIC-----------------------------

class Istoric {
    static int nr_actualizari;
    int zi_act, luna_act, an_act;
    double sold_act;
public:
    Istoric();
    Istoric(int zi_act, int luna_act, int an_act, double sold_act);
    Istoric(const Istoric& obj);
    ~Istoric();
    int getNr_actualizari() {
        return nr_actualizari;
    }
    void setNr_actualizari(int nr_actualizari) {
        this->nr_actualizari = nr_actualizari;
    }
    int getZi_act() {
        return zi_act;
    }
    void setZi_act(int zi_act) {
        this->zi_act = zi_act;
    }
    int getLuna_act() {
        return luna_act;
    }
    void setLuna_act(int luna_act) {
        this->luna_act = luna_act;
    }
    int getAn_act() {
        return an_act;
    }
    void setAn_act(int an_act) {
        this->an_act = an_act;
    }
    double getSold_Act() {
        return sold_act;
    }
    void setSold_Act(double sold_act) {
        this->sold_act = sold_act;
    }
    void afisare(ostream&) const;
    friend ostream& operator<<(ostream& out, const Istoric& obj);
    Istoric& operator=(const Istoric& obj);
};
int Istoric::nr_actualizari = 0;

Istoric::Istoric() {
    zi_act = 0;
    luna_act = 0;
    an_act = 0;
    sold_act = 0;
}
Istoric::Istoric(int zi_act, int luna_act, int an_act, double sold_act) : zi_act(zi_act), luna_act(luna_act), an_act(an_act), sold_act(sold_act) {}
Istoric::Istoric(const Istoric& obj) {
    this->nr_actualizari = nr_actualizari;
    this->zi_act = zi_act;
    this->luna_act = luna_act;
    this->an_act = an_act;
    this->sold_act = sold_act;
}
Istoric::~Istoric() {
    zi_act = 0;
    luna_act = 0;
    an_act = 0;
    sold_act = 0;
}
void Istoric::afisare(ostream& out) const {
    cout << "Data actualizarii este " << zi_act << "." << luna_act << "." << an_act;
    cout << "\nSold-ul este " << sold_act << " lei";
}
ostream& operator<<(ostream& out, const Istoric& obj) {
    obj.afisare(out);
    return out;
}
Istoric& Istoric::operator=(const Istoric& obj) {
    if (this != &obj) {
        this->zi_act = obj.zi_act;
        this->luna_act = obj.luna_act;
        this->an_act = obj.an_act;
        this->sold_act = obj.sold_act;
    }
    return *this;
}

///------------------------------clasa ECONOMII-----------------------------

class ContEconomii : public Cont {
    string tip_rata;                    ///3 luni 6 luni 1 an
    double rata_dobanda;
    Istoric* actualizari;
public:
    ContEconomii();
    ContEconomii(string detinator, int zi_d, int luna_d, int an_d, double sold, string tip_rata, double rata_dobanda, Istoric* actualizari);
    ContEconomii(const ContEconomii& obj);
    ~ContEconomii();
    string getTip_rata() {
        return tip_rata;
    }
    void setTip_rata(string tip_rata) {
        this->tip_rata = tip_rata;
    }
    double getRata_dobanda() {
        return rata_dobanda;
    }
    void setRata_dobanda(double rata_dobanda) {
        this->rata_dobanda = rata_dobanda;
    }
    Istoric* calcul(string tip_rata, double rata_dobanda);
    void PrintIstoric();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ContEconomii& obj);
    friend ostream& operator<<(ostream& out, const ContEconomii& obj);
    ContEconomii& operator=(const ContEconomii& obj);
};

ContEconomii::ContEconomii() {
    tip_rata = "";
    rata_dobanda = 0;
    actualizari = NULL;
}
ContEconomii::ContEconomii(string detinator, int zi_d, int luna_d, int an_d, double sold, string tip_rata, double rata_dobanda, Istoric* actualizari) :
    Cont(detinator, zi_d, luna_d, an_d, sold), tip_rata(tip_rata), rata_dobanda(rata_dobanda), actualizari(actualizari) {}
ContEconomii::ContEconomii(const ContEconomii& obj) : Cont(obj) {
    this->tip_rata = obj.tip_rata;
    this->rata_dobanda = obj.rata_dobanda;
    if (obj.actualizari->getNr_actualizari() == 0) {
        this->actualizari = NULL;
        this->actualizari->setNr_actualizari(0);
    }
    else {
        int act = obj.actualizari->getNr_actualizari();
        this->actualizari = new Istoric[act];
        for (int i = 0; i < act; i++)
            this->actualizari[i] = obj.actualizari[i];
        this->actualizari->setNr_actualizari(act);
    }
}
ContEconomii::~ContEconomii() {
    tip_rata = "";
    rata_dobanda = 0;
    actualizari = NULL;
}
Istoric* ContEconomii::calcul(string tip_rata, double rata_dobanda) { ///Metoda care creeaza un vector de tip istoric pentru fiecare actualizare a soldului
    ///Calculeaza nr de actualizari pana in prezent, soldul actualizat si ziua/luna/anul in care s-a actualizat
    Istoric* istoric_curent = NULL;
    ///am considerat ca data din prezent fiind 01/01/2020
    int zi = zi_d, luna = luna_d, an = an_d;
    double soldnou = sold;
    double rata = rata_dobanda / 100;
    if (tip_rata == "3 luni") {
        int act = (2020 - an_d - 1) * 4 + (12 - luna_d) / 3 + 1;
        istoric_curent->setNr_actualizari(act);
        istoric_curent = new Istoric[act];
        for (int i = 0; i < act; i++) {
            istoric_curent[i].setZi_act(zi);
            istoric_curent[i].setLuna_act(luna);
            istoric_curent[i].setAn_act(an);
            istoric_curent[i].setSold_Act(soldnou);
            if (luna <= 9) luna += 3;
            else {
                luna = luna + 3 - 12;
                ++an;
            }
            soldnou += soldnou * rata;
        }
    }
    else if (tip_rata == "6 luni") {
        int act = (2020 - an_d - 1) * 2 + (12 - luna_d) / 6 + 1;
        istoric_curent->setNr_actualizari(act);
        istoric_curent = new Istoric[act];
        for (int i = 0; i < act; i++) {
            istoric_curent[i].setZi_act(zi);
            istoric_curent[i].setLuna_act(luna);
            istoric_curent[i].setAn_act(an);
            istoric_curent[i].setSold_Act(soldnou);
            if (luna <= 6) luna += 6;
            else {
                luna = luna + 6 - 12;
                ++an;
            }
            soldnou += soldnou * rata;
        }
    }
    else {
        int act = 2020 - an_d;
        istoric_curent->setNr_actualizari(act);
        istoric_curent = new Istoric[act];
        for (int i = 0; i < act; i++) {
            istoric_curent[i].setZi_act(zi);
            istoric_curent[i].setLuna_act(luna);
            istoric_curent[i].setAn_act(an);
            istoric_curent[i].setSold_Act(soldnou);
            ++an;
            soldnou += soldnou * rata;
        }
    }
    return istoric_curent;
}
void ContEconomii::citire(istream& in) {
    Cont::citire(in);
    cout << "Ce tip de rata are acest cont?(3 luni/6 luni/1 an) ";
    in.get();
    getline(in, tip_rata);
    cout << "Ce rata are acest cont?(0-100) ";
    in >> rata_dobanda;
    try {
        if (rata_dobanda < 0 || rata_dobanda>100)
            throw 1;
    }
    catch (int i) {
        cout << "Eroare la setarea ratei. Rata trebuie sa reprezinte un procent intre 0% si 100%.\n";
        exit(EXIT_FAILURE);
    }
    actualizari = ContEconomii::calcul(tip_rata, rata_dobanda);
}
void ContEconomii::PrintIstoric() {
    int x = actualizari->getNr_actualizari();
    cout << "Soldul a fost actualizat de: " << x << " ori\n";
    for (int i = 0; i < x; i++)
        cout << actualizari[i] << '\n';
}
void ContEconomii::afisare(ostream& out) const {
    Cont::afisare(out);
    cout << "\nTipul ratei este " << tip_rata;
    cout << "\nRata dobanzii este " << rata_dobanda<<"%";
    cout << "\nSoldul curent este " << actualizari[actualizari->getNr_actualizari() - 1].getSold_Act()<<" lei";
}
istream& operator>>(istream& in, ContEconomii& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ContEconomii& obj) {
    obj.afisare(out);
    return out;
}
ContEconomii& ContEconomii::operator=(const ContEconomii& obj) {
    if (this != &obj) {
        this->detinator = obj.detinator;
        this->zi_d = obj.zi_d;
        this->luna_d = obj.luna_d;
        this->an_d = obj.an_d;
        this->sold = obj.sold;
        this->tip_rata = obj.tip_rata;
        this->rata_dobanda = obj.rata_dobanda;
        delete[] this->actualizari;
        if (obj.actualizari->getNr_actualizari() == 0) {
            this->actualizari = NULL;
        }
        else {
            int act = obj.actualizari->getNr_actualizari();
            this->actualizari = new Istoric[act];
            for (int i = 0; i < act; i++)
                this->actualizari[i] = obj.actualizari[i];
            this->actualizari->setNr_actualizari(act);
        }
    }
    return *this;
}

///------------------------------clasa CURENT-----------------------------

class ContCurent : public Cont {
    int tranzactii_gratuite;
    double cost_retragere;
    static const int cump_online;
public:
    ContCurent();
    ContCurent(string detinator, int zi_d, int luna_d, int an_d, int sold, int tranzactii_gratuite, int cost_retragere);
    ContCurent(const ContCurent& obj);
    ~ContCurent();
    int getTranzactii_gratuite() {
        return tranzactii_gratuite;
    }
    void setTranzactii_gratuite(int tranzactii_gratuite) {
        this->tranzactii_gratuite = tranzactii_gratuite;
    }
    void setCost_retragere(double cost_retragere) {
        this->tranzactii_gratuite = tranzactii_gratuite;
    }
    double getCost_retragere() {
        return cost_retragere;
    }
    static const int getCump_online() {
        return cump_online;
    }
    void depunere(double suma);
    void retragere(string bancomat, double suma);
    void cumparare(string modCumparat, double suma);
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ContCurent& obj);
    friend ostream& operator<<(ostream& out, const ContCurent& obj);
    ContCurent& operator=(const ContCurent& obj);
};
const int ContCurent::cump_online = 5;

ContCurent::ContCurent() {
    tranzactii_gratuite = 0;
    cost_retragere = 0;
}
ContCurent::ContCurent(string detinator, int zi_d, int luna_d, int an_d, int sold, int tranzactii_gratuite, int cost_retragere) :
    Cont(detinator, zi_d, luna_d, an_d, sold), tranzactii_gratuite(tranzactii_gratuite), cost_retragere(cost_retragere) {}
ContCurent::ContCurent(const ContCurent& obj) : Cont(obj) {
    this->tranzactii_gratuite = obj.tranzactii_gratuite;
    this->cost_retragere = obj.cost_retragere;
}
ContCurent::~ContCurent() {
    tranzactii_gratuite = 0;
    cost_retragere = 0;
}
void ContCurent::depunere(double suma) {
    cout<<"Soldul inainte de depunere este de "<<sold<<" lei";
    sold += suma;
    cout<<"\nSoldul dupa depunere este de "<<sold<<" lei";
}
void ContCurent::retragere(string bancomat, double suma) {
    cout<<"Soldul inainte de retragere este de "<<sold<<" lei";
    double suma_curr=sold;
    if(sold){
        if (bancomat == "X") {
            if (tranzactii_gratuite) {
                --tranzactii_gratuite;
                sold -= suma;
            }
            else {
                double cost = (cost_retragere/100) * suma;
                sold = sold - suma - cost;
                cout<<"\nVi s-a perceput o taxa de "<<cost<<" lei deoarece nu mai aveti tranzactii gratuite.";
            }
        }
        else {
            double cost = (cost_retragere/100) * suma;
            sold = sold - suma - cost;
            cout<<"\nVi s-a perceput o taxa de "<<cost<<" lei reprezentand "<<cost_retragere<<"% din suma deoarece retrageti bani de la bancomatul altei banci in cazul unei tranzactii reusite.";
        }
    }
    try{
        if(sold>=0){
            cout<<"\nSoldul dupa retragere este de "<<sold<<" lei";
        }
        else{
            sold=suma_curr;
            throw 1;
        }
    }
    catch(int i)
    {
        cout<<"\nNu mai ai bani, saracule.";
    }
}
void ContCurent::cumparare(string modCumparat, double suma) {
    cout<<"Soldul inainte de cumparare este de "<<sold<<" lei";
    double suma_curr=sold;
    if(sold){
        if (modCumparat == "Online") {
            sold=sold-suma-cump_online;
            cout<<"\nVi s-a perceput o taxa de "<<cump_online<<" lei asociata cumparaturilor online in cazul unei tranzactii reusite";
        }
        else sold -= suma;
    }
    try{
        if(sold>=0){
            cout<<"\nSoldul dupa cumparaturi este de "<<sold<<" lei";
        }
        else{
            sold=suma_curr;
            throw 1;
        }
    }
    catch(int i)
    {
        cout<<"\nNu mai ai bani, saracule.";
    }
}
void ContCurent::citire(istream& in) {
    Cont::citire(in);
    cout << "De cate tranzactii gratuite beneficiaza contul curent? ";
    in >> tranzactii_gratuite;
    cout << "Ce cost de retragere se poate aplica contului?(0-100) ";
    in >> cost_retragere;
    try {
        if (cost_retragere < 0 || cost_retragere>100)
            throw 1;
    }
    catch (int i) {
        cout << "Eroare la setarea costului de retragere. Costul trebuie sa reprezinte un procent intre 0% si 100%.\n";
        exit(EXIT_FAILURE);
    }
}
void ContCurent::afisare(ostream& out) const {
    Cont::afisare(out);
    cout << "\nTranzactiile gratuite pentru cont sunt " << tranzactii_gratuite;
    cout << "\nCostul de retragere aplicat contului este " << cost_retragere << "%";
    cout << "\nCostul platilor online aplicat contului este " << cump_online << " lei";
}
istream& operator>>(istream& in, ContCurent& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ContCurent& obj) {
    obj.afisare(out);
    return out;
}
ContCurent& ContCurent::operator=(const ContCurent& obj) {
    if (this != &obj) {
        this->detinator = obj.detinator;
        this->zi_d = obj.zi_d;
        this->luna_d = obj.luna_d;
        this->an_d = obj.an_d;
        this->sold = obj.sold;
        this->tranzactii_gratuite = obj.tranzactii_gratuite;
        this->cost_retragere = obj.cost_retragere;
    }
    return *this;
}

///------------------------------clasa TEMPLATE-----------------------------

template <class T>
class GestionareConturi {
    int nr;
    static int id_cont;
    unordered_map<int, T> sistem;
public:
    GestionareConturi();
    GestionareConturi(int nr, unordered_map<int, T> sistem);
    GestionareConturi(const GestionareConturi& obj);
    ~GestionareConturi();
    static int getId_cont() {
        return id_cont;   ///metoda statica
    }
    GestionareConturi<T>& operator+=(T cont) {
        this->sistem.insert({ ++id_cont, cont });
        return *this;
    }
    void afisare(ostream& out) {
        out << "Numarul de conturi este: " << nr;
        class unordered_map <int, T>::iterator i;
        for (i = sistem.begin(); i != sistem.end(); i++) {
            out << "\n--------------------------------------------------\n";
            out << i->first << ' ' << i->second << '\n';
        }
    }
    friend istream& operator>>(istream& in, GestionareConturi<T>& obj) {
        cout << "Introduceti numarul de conturi: ";
        in >> obj.nr;
        T cont;
        cout << "Introduceti datele conturilor: \n";
        for (int i = 0; i < obj.nr; i++) {
            in >> cont;
            obj += cont;
            cout << '\n';
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, GestionareConturi<T>& obj) {
        obj.afisare(out);
        return out;
    }
    GestionareConturi<T>& operator=(const GestionareConturi<T>& obj) {
        if (this != &obj) {
            this->nr = obj.nr;
            this->sistem.clear();
            this->sistem.insert(obj.sistem.begin(), obj.sistem.end());
        }
        return *this;
    }
};
template <class T>
int GestionareConturi<T>::id_cont = 0;

template <class T>
GestionareConturi<T>::GestionareConturi() {
    nr = 0;
    sistem.clear();
}
template <class T>
GestionareConturi<T>::GestionareConturi(int nr, unordered_map<int, T> sistem) {
    this->nr = nr;
    this->sistem.clear();
    this->sistem.insert(sistem.begin(), sistem.end());
}
template <class T>
GestionareConturi<T>::GestionareConturi(const GestionareConturi& obj) {
    this->nr = obj.nr;
    this->sistem.clear();
    this->sistem.insert(obj.sistem.begin(), obj.sistem.end());
}

template <class T>
GestionareConturi<T>::~GestionareConturi() {
    nr = 0;
    sistem.clear();
}

///------------------------------specializare TEMPLATE-----------------------------

template <> class GestionareConturi <ContEconomii> {
    int nr;
    int conturi_rata_1an;
    static int id_cont;
    unordered_map<int, ContEconomii> sistem;
public:
    GestionareConturi();
    GestionareConturi(int nr, unordered_map<int, ContEconomii> sistem);
    GestionareConturi(const GestionareConturi& obj);
    ~GestionareConturi();
    static int getId_cont() {
        return id_cont;   ///metoda statica
    }
    GestionareConturi<ContEconomii>& operator+=(ContEconomii cont) {
        this->sistem.insert({ ++id_cont, cont });
        return *this;
    }
    void afisare(ostream& out) {
        out << "Numarul de conturi este: " << nr;
        unordered_map <int, ContEconomii>::iterator i;
        for (i = sistem.begin(); i != sistem.end(); i++) {
            out << "\n--------------------------------------------------\n";
            out << i->first << ' ' << i->second << '\n';
        }
        out << "Numarul conturilor de economii care au rata dobanzii la un an sunt " << conturi_rata_1an;
    }
    friend istream& operator>>(istream& in, GestionareConturi<ContEconomii>& obj) {
        cout << "Introduceti numarul de conturi: ";
        in >> obj.nr;
        ContEconomii cont;
        cout << "Introduceti datele conturilor: \n";
        for (int i = 0; i < obj.nr; i++) {
            in >> cont;
            if (cont.getTip_rata() == "1 an")
                obj.conturi_rata_1an += 1;
            obj += cont;
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, GestionareConturi<ContEconomii>& obj) {
        obj.afisare(out);
        return out;
    }
    GestionareConturi<ContEconomii>& operator=(const GestionareConturi<ContEconomii>& obj) {
        if (this != &obj) {
            this->nr = obj.nr;
            this->conturi_rata_1an = obj.conturi_rata_1an;
            this->sistem.clear();
            this->sistem.insert(obj.sistem.begin(), obj.sistem.end());
        }
        return *this;
    }
};
int GestionareConturi<ContEconomii>::id_cont = 0;

GestionareConturi<ContEconomii>::GestionareConturi() {
    conturi_rata_1an = 0;
    nr = 0;
    sistem.clear();
}
GestionareConturi<ContEconomii>::GestionareConturi(int nr, unordered_map<int, ContEconomii> sistem) {
    this->conturi_rata_1an = 0;
    this->nr = nr;
    this->sistem.clear();
    this->sistem.insert(sistem.begin(), sistem.end());
}
GestionareConturi<ContEconomii>::GestionareConturi(const GestionareConturi& obj) {
    conturi_rata_1an = 0;
    this->nr = obj.nr;
    this->sistem.clear();
    sistem.insert(obj.sistem.begin(), obj.sistem.end());
}
GestionareConturi<ContEconomii>::~GestionareConturi() {
    conturi_rata_1an = 0;
    nr = 0;
    sistem.clear();
}

///------------------------------MENIU-----------------------------

void menu_output() {
    cout << "\nGestionare Conturi\n";
    cout << "\n\t\tMENIU:";
    cout << "\n===========================================\n";
    cout << "\n1. Citeste conturile --- UPCAST & LATE-BINDING";
    cout << "\n2. GestionareConturi --- TEMPLATE (ContEconomii-SPECIALIZARE).";
    cout << "\n3. GestionareConturi --- TEMPLATE (ContCurent).";
    cout << "\n4. Afiseaza istoricul reactualizarilor soldurilor unui cont de economii";
    cout << "\n5. Depune bani intr-un cont curent";
    cout << "\n6. Retrage bani dintr-un cont curent";
    cout << "\n7. Cumpara";
    cout << "\n8. Contorizare conturi --- DYNAMIC_CAST (DOWNCAST).";
    cout << "\n9. Afiseaza conturile";
    cout << "\n10. Sterge conturile";
    cout << "\n0. Iesire.";
    cout << "\n";
}

void menu() {
    int option;///optiunea aleasa din meniu
    option = 0;
    int n = 0;
    vector <Cont*> sistem;
    do {
        menu_output();
        cout << "\nIntroduceti numarul actiunii: ";
        cin >> option;
        if (option == 1) {
            cout << "Cate conturi sunt deschise la banca? ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout<<"\nContul "<<i+1<<":\n";
                string tip;
                cout << "Introduceti tipul contului(Economii/Curent): ";
                cin >> tip;
                try {
                    if (tip == "Economii") {

                        ContEconomii* p = new ContEconomii;
                        cin >> *p;
                        sistem.push_back(p);
                    }
                    else if (tip == "Curent") {
                        ContCurent* p = new ContCurent;
                        cin >> *p;
                        sistem.push_back(p);
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
        if (option == 2) {
            GestionareConturi <ContEconomii> str;
            cin >> str;
            cout << str;
        }
        if (option == 3) {
            GestionareConturi <ContCurent> str;
            cin >> str;
            cout << str;
        }
        if (option == 4) {
            int nrcont;
            cout<<"Care este numarul contului? ";
            cin>>nrcont;
            if(n>0){
                ContEconomii* p=dynamic_cast<ContEconomii*>(sistem[nrcont-1]);
                if(p)
                {
                    p->PrintIstoric();

                }
                else cout<<"Acela este un cont curent.";
            }
            else cout<<"Nu s-au citit conturi. Recomandam actiunea 1.\n";
        }
        if (option == 5) {
            ///depunere
            int nrcont;
            double suma;
            cout<<"Care este numarul contului? ";
            cin>>nrcont;
            if(n>0){
                cout<<"Care este suma pe care doriti sa o depuneti? ";
                cin>>suma;
                ContCurent* p=dynamic_cast<ContCurent*>(sistem[nrcont-1]);
                if(p)
                {
                    p->depunere(suma);
                }
                else cout<<"Acela este un cont de economii.";
            }
            else cout<<"Nu s-au citit conturi. Recomandam actiunea 1.\n";
        }
        if (option == 6) {
            ///retragere
            int nrcont;
            double suma;
            string bancomat;
            cout<<"Care este numarul contului? ";
            cin>>nrcont;
            if(n>0){
                cout<<"De la ce bancomat doriti sa retrageti bani? ";
                cin.get();
                getline(cin, bancomat);
                cout<<"Ce suma doriti sa retrageti? ";
                cin>>suma;
                ContCurent* p=dynamic_cast<ContCurent*>(sistem[nrcont-1]);
                if(p)
                {
                    p->retragere(bancomat, suma);
                }
                else cout<<"Acela este un cont de economii.";
            }
            else cout<<"Nu s-au citit conturi. Recomandam actiunea 1.\n";
        }
        if (option == 7) {
            ///cumparare
            int nrcont;
            double suma;
            string mod;
            cout<<"Care este numarul contului? ";
            cin>>nrcont;
            if(n>0){
                cout<<"Cum doriti sa faceti cumparaturile?(Online/Ramburs) ";
                ///Doar la cumparaturi online se aplica un cost, in orice alt caz nu se percepe nicio taxa.
                cin.get();
                getline(cin, mod);
                cout<<"Cat costa produsele? ";
                cin>>suma;
                ContCurent* p=dynamic_cast<ContCurent*>(sistem[nrcont-1]);
                if(p)
                {
                    p->cumparare(mod, suma);

                }
                else cout<<"Acela este un cont de economii.";
            }
            else cout<<"Nu s-au citit conturi. Recomandam actiunea 1.\n";
        }
        if (option == 8) {
            ///Contorizare conturi
            int Nr_eco=0, Nr_cur=0;
            if (n>0){
            for(int i=0;i<n;i++)
            {
                ContEconomii *p1=dynamic_cast<ContEconomii*>(sistem[i]);
                ContCurent *p2=dynamic_cast<ContCurent*>(sistem[i]);
                ///daca sunt nenuli atunci incrementez corespunzator
                if (p1)
                    Nr_eco++;
                if (p2)
                    Nr_cur++;
            }
            cout<<"\nNumarul de conturi de economii: "<<Nr_eco;
            cout<<"\nNumarul de conturi curente: "<<Nr_cur;
            }
            else{
                cout<<"Nu s-au citit conturi. Recomandam actiunea 1.\n";
            }
        }
        if (option == 9) {
            cout << "La banca X sunt deschise " << n << " conturi";
            for (int i = 0; i < n; i++) {
                cout << "\n--------------------------------------------------\n";
                cout << *sistem[i];
            }
        }
        if (option == 10)
        {
            for (int i = 0; i < n; i++)
                delete sistem[i];
            n = 0;
            sistem.clear();
        }
        if (option == 0) {
            cout << "\nEXIT!\n";
        }
        if (option < 0 || option>10) {
            cout << "\nSelectie invalida\n";
        }
        cout << '\n';
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    } while (option != 0);
}
int main() {
    menu();
    return 0;
}

/*

Economii
David Tennant
20
05
2012
1230
6 luni
4
Curent
Matt Smith
1
11
2000
385
10
3.5

*/
