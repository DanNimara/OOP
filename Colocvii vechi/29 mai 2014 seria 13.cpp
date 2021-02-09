#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Pacient {
protected:
    string nume, prenume;
    int varsta;
    string adresa;
    int colesterol;
    int tens_art;
    int zi_col, luna_col, an_col;
    int zi_ta, luna_ta, an_ta;
    string risc_cardiovascular;

public:
    Pacient(string, string, int, string, int, int, int, int, int, int, int, int, string);
    Pacient(const Pacient& obj);
    virtual ~Pacient();
    virtual void calculRisc()=0;
    string getRisc_cardiovascular(){return risc_cardiovascular;}
    void setRisc_cardiovascular(string risc_cardiovascular){this->risc_cardiovascular=risc_cardiovascular;}
    string getNume(){return nume;}
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Pacient& obj);
    friend ostream& operator<<(ostream& out, const Pacient& obj);
    Pacient& operator=(const Pacient& obj);
};

Pacient::Pacient(string nume="", string prenume="", int varsta=0, string adresa="", int colesterol=0, int tens_art=0,
                 int zi_col=0, int luna_col=0, int an_col=0, int zi_ta=0, int luna_ta=0, int an_ta=0, string risc_cardiovascular="") : nume(nume), prenume(prenume), varsta(varsta),
                 adresa(adresa), colesterol(colesterol), tens_art(tens_art), zi_col(zi_col), luna_col(luna_col), an_col(an_col), zi_ta(zi_ta),
                 luna_ta(luna_ta), an_ta(an_ta), risc_cardiovascular(risc_cardiovascular) {}
Pacient::Pacient(const Pacient& obj) {
    this->nume=obj.nume;
    this->prenume=obj.prenume;
    this->varsta=obj.varsta;
    this->adresa=obj.adresa;
    this->colesterol=obj.colesterol;
    this->tens_art=obj.tens_art;
    this->zi_col=obj.zi_col;
    this->luna_col=obj.luna_col;
    this->an_col=obj.an_col;
    this->zi_ta=obj.zi_ta;
    this->luna_ta=obj.luna_ta;
    this->an_ta=obj.an_ta;
    this->risc_cardiovascular=obj.risc_cardiovascular;
}
Pacient::~Pacient() {
    nume="";
    prenume="";
    varsta=0;
    adresa="";
    colesterol=0;
    tens_art=0;
    zi_col=0;
    luna_col=0;
    an_col=0;
    zi_ta=0;
    luna_ta=0;
    an_ta=0;
    risc_cardiovascular="";
}
void Pacient::citire(istream& in) {
    cout << "Care este numele? ";
    in>>nume;
    cout << "Care este prenumele? ";
    in.get();
    getline(in, prenume);
    cout << "Care este varsta? ";
    in >> varsta;
    cout << "Care este adresa? ";
    in.get();
    getline(in, adresa);
    cout << "Care este ziua analizelor de colesterol? ";
    in>>zi_col;
    cout << "Care este luna analizelor de colesterol? ";
    in>>luna_col;
    cout << "Care este anul analizelor de colesterol? ";
    in>>an_col;
    cout << "Care este valoarea colesterolului? ";
    in>>colesterol;
    cout << "Care este ziua analizelor de tensiune arteriala? ";
    in>>zi_ta;
    cout << "Care este luna analizelor de tensiune arteriala? ";
    in>>luna_ta;
    cout << "Care este anul analizelor de tensiune arteriala? ";
    in>>an_ta;
    cout << "Care este valoarea tensiunii arteriale? ";
    in>>tens_art;
}
void Pacient::afisare(ostream& out) const {
    out << '\n'<<nume<<' '<<prenume<<": Risc cardiovascular - "<<risc_cardiovascular<<"; Colesterol(";
    out<<zi_col<<'.'<<luna_col<<'.'<<an_col<<"): "<<colesterol<<" mg/dl; TA ("<<zi_ta<<'.'<<luna_ta<<'.'<<an_ta<<"): "<<tens_art;
}
istream& operator>>(istream& in, Pacient& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Pacient& obj) {
    obj.afisare(out);
    return out;
}
Pacient& Pacient::operator=(const Pacient& obj) {
    if (this != &obj) {
        this->nume=obj.nume;
        this->prenume=obj.prenume;
        this->varsta=obj.varsta;
        this->adresa=obj.adresa;
        this->colesterol=obj.colesterol;
        this->tens_art=obj.tens_art;
        this->zi_col=obj.zi_col;
        this->luna_col=obj.luna_col;
        this->an_col=obj.an_col;
        this->zi_ta=obj.zi_ta;
        this->luna_ta=obj.luna_ta;
        this->an_ta=obj.an_ta;
        this->risc_cardiovascular=obj.risc_cardiovascular;
    }
    return *this;
}

///---------------------------------------clasa SUB40DEANI----------------------------

class Sub40 : public Pacient{
  public:
    Sub40(string, string, int, string, int, int, int, int, int, int, int, int, string);
    Sub40(const Sub40& obj);
    ~Sub40();
    void calculRisc();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Sub40& obj);
    friend ostream& operator<<(ostream& out, const Sub40& obj);
    Sub40& operator=(const Sub40& obj);
};

Sub40::Sub40(string nume="", string prenume="", int varsta=0, string adresa="", int colesterol=0, int tens_art=0,
                 int zi_col=0, int luna_col=0, int an_col=0, int zi_ta=0, int luna_ta=0, int an_ta=0, string risc_cardiovascular="") :
            Pacient(nume, prenume, varsta, adresa, colesterol, tens_art, zi_col, luna_col, an_col, zi_ta, luna_ta, an_ta, risc_cardiovascular){}
Sub40::Sub40(const Sub40& obj) : Pacient(obj) {}
Sub40::~Sub40() {}
void Sub40::calculRisc()
{
    if(colesterol>240&&tens_art>139)
        risc_cardiovascular="RIDICAT";
    else if(colesterol>240||tens_art>139)
        risc_cardiovascular="DA";
    else risc_cardiovascular="NU";
}
void Sub40::citire(istream& in) {
    Pacient::citire(in);
    calculRisc();
}
void Sub40::afisare(ostream& out) const {
    Pacient::afisare(out);
}
istream& operator>>(istream& in, Sub40& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Sub40& obj) {
    obj.afisare(out);
    return out;
}
Sub40& Sub40::operator=(const Sub40& obj) {
    if (this != &obj) {
        Pacient::operator=(obj) ;
    }
    return *this;
}

///----------------------------------------------clasa PESTE40----------------------

class Peste40 : public Pacient {
    string fumator;
    string sedentarism;
  public:
    Peste40(string, string, int, string, int, int, int, int, int, int, int, int, string, string, string);
    Peste40(const Peste40& obj);
    ~Peste40();
    void calculRisc();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Peste40& obj);
    friend ostream& operator<<(ostream& out, const Peste40& obj);
    Peste40& operator=(const Peste40& obj);
};

Peste40::Peste40(string nume="", string prenume="", int varsta=0, string adresa="", int colesterol=0, int tens_art=0,
                 int zi_col=0, int luna_col=0, int an_col=0, int zi_ta=0, int luna_ta=0, int an_ta=0, string risc_cardiovascular="",
                 string fumator="", string sedentarism="") : Pacient(nume, prenume, varsta, adresa, colesterol, tens_art, zi_col,
                luna_col, an_col, zi_ta, luna_ta, an_ta, risc_cardiovascular), fumator(fumator), sedentarism(sedentarism){}
Peste40::Peste40(const Peste40& obj) : Pacient(obj) {
    this->fumator = obj.fumator;
    this->sedentarism = obj.sedentarism;
}
Peste40::~Peste40() {
    fumator="";
    sedentarism="";
}
void Peste40::calculRisc()
{
    int combo=0;
    if(colesterol>240)
       combo++;
    if(tens_art>139)
        combo++;
    if(fumator=="da"&&sedentarism=="ridicat")
        combo++;
    if(combo>=2)
        risc_cardiovascular="RIDICAT";
    else if(combo==1)
        risc_cardiovascular="DA";
    else if(combo==0)
        risc_cardiovascular="NU";
}
void Peste40::citire(istream& in) {
    Pacient::citire(in);
    cout << "Pacientul este fumator?(da/nu) ";
    in>>fumator;
    cout << "Ce tip de sedentarism are pacientul?(scazut, mediu, ridicat) ";
    in >> sedentarism;
    calculRisc();
}
void Peste40::afisare(ostream& out) const {
    Pacient::afisare(out);
    out << "; Fumator: " << fumator<<"; Sedentarism: "<<sedentarism<<'.';
}
istream& operator>>(istream& in, Peste40& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Peste40& obj) {
    obj.afisare(out);
    return out;
}
Peste40& Peste40::operator=(const Peste40& obj) {
    if (this != &obj) {
        Pacient::operator=(obj) ;
        this->fumator = obj.fumator;
    this->sedentarism = obj.sedentarism;
    }
    return *this;
}

///-----------------------------COPIL------------------------------------

class Copil : public Pacient {
    string antecedente;
    string nume_m, prenume_m, nume_t, prenume_t;
    int zi_prot, luna_prot, an_prot;
    double proteinaC;
  public:
    Copil(string, string, int, string, int, int, int, int, int, int, int, int, string, string, string, string, string, string, int, int, int, double);
    Copil(const Copil& obj);
    ~Copil();
    void calculRisc();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Copil& obj);
    friend ostream& operator<<(ostream& out, const Copil& obj);
    Copil& operator=(const Copil& obj);
};

Copil::Copil(string nume="", string prenume="", int varsta=0, string adresa="", int colesterol=0, int tens_art=0,
            int zi_col=0, int luna_col=0, int an_col=0, int zi_ta=0, int luna_ta=0, int an_ta=0, string risc_cardiovascular="",
            string antecedente="", string nume_m="", string prenume_m="", string nume_t="", string prenume_t="", int zi_prot=0,
            int luna_prot=0, int an_prot=0, double proteinaC=0) :
            Pacient(nume, prenume, varsta, adresa, colesterol, tens_art, zi_col, luna_col, an_col, zi_ta, luna_ta, an_ta, risc_cardiovascular),
            antecedente(antecedente), nume_m(nume_m), prenume_m(prenume_m), nume_t(nume_t), prenume_t(prenume_t), zi_prot(zi_prot), luna_prot(luna_prot),
            an_prot(an_prot), proteinaC(proteinaC){}
Copil::Copil(const Copil& obj) : Pacient(obj) {
    this->antecedente = obj.antecedente;
    this->nume_m = obj.nume_m;
    this->prenume_m = obj.prenume_m;
    this->nume_t = obj.nume_t;
    this->prenume_t = obj.prenume_t;
    this->zi_prot = obj.zi_prot;
    this->luna_prot = obj.luna_prot;
    this->an_prot = obj.an_prot;
    this->proteinaC = obj.proteinaC;
}
Copil::~Copil() {
    antecedente="";
    nume_m="";
    prenume_m="";
    nume_t="";
    prenume_t="";
    zi_prot=0;
    luna_prot=0;
    an_prot=0;
    proteinaC=0;
}
void Copil::calculRisc()
{
    int combo=0;
    if(proteinaC>0.6) combo++;
    if(antecedente=="da") combo++;
    if(combo==2) risc_cardiovascular="RIDICAT";
    else if(combo==1) risc_cardiovascular="DA";
    else if(combo==0) risc_cardiovascular="NU";
}
void Copil::citire(istream& in) {
    Pacient::citire(in);
    cout<<"Are antecedente in familie?(da/nu) ";
    in >> antecedente;
    cout<<"Care este numele mamei? ";
    in.get();
    getline(in, nume_m);
    cout<<"Care este prenumele mamei? ";
    getline(in, prenume_m);
    cout<<"Care este numele tatalui? ";
    getline(in, nume_t);
    cout<<"Care este prenumele tatalui? ";
    getline(in, prenume_t);
    cout << "Care este ziua analizelor de proteina C? ";
    in>>zi_prot;
    cout << "Care este luna analizelor de proteina C? ";
    in>>luna_prot;
    cout << "Care este anul analizelor de proteina C? ";
    in>>an_prot;
    cout << "Care este valoarea proteinei C? ";
    in>>proteinaC;
    calculRisc();
}
void Copil::afisare(ostream& out) const {
    Pacient::afisare(out);
    out << "; Proteina C reactiva (" << zi_prot<<'.'<<luna_prot<<'.'<<an_prot<<"): "<<proteinaC<<" mg/dl; Antecedente familie: "<<antecedente<<'.';
}
istream& operator>>(istream& in, Copil& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Copil& obj) {
    obj.afisare(out);
    return out;
}
Copil& Copil::operator=(const Copil& obj) {
    if (this != &obj) {
        Pacient::operator=(obj) ;
        this->antecedente = obj.antecedente;
        this->nume_m = obj.nume_m;
        this->prenume_m = obj.prenume_m;
        this->nume_t = obj.nume_t;
        this->prenume_t = obj.prenume_t;
        this->zi_prot = obj.zi_prot;
        this->luna_prot = obj.luna_prot;
        this->an_prot = obj.an_prot;
        this->proteinaC = obj.proteinaC;
    }
    return *this;
}

///------------------------------MENIU-----------------------------

void menu_output() {
    cout << "\nCABINET\n";
    cout << "\n\t\tMENIU:";
    cout << "\n===========================================\n";
    cout << "\n1. Citeste pacient --- UPCAST & LATE-BINDING";
    cout << "\n2. Afiseaza pacientii";
    cout << "\n3. Afiseaza pacientii adulti cu factor de risc cardiovascular ridicat";
    cout << "\n4. Afiseaza pacientii copii cu risc cardiovascular";
    cout << "\n5. Afiseaza pacientii care au numele de familie egal cu un nume dat";
    cout << "\n0. Iesire.";
    cout << "\n";
}

void menu() {
    int option;///optiunea aleasa din meniu
    option = 0;
    int n = 0;
    vector <Pacient*> cabinet;
    do {
        menu_output();
        cout << "\nIntroduceti numarul actiunii: ";
        cin >> option;
        if (option == 1) {
            ///citit de n obiecte
            cout << "Cati pacienti are cabinetul? ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout<<"\nPacientul "<<i+1<<":\n";
                string tip;
                cout << "Mentionati tipul pacientului(Sub40/Peste40/Copil): ";
                cin.get();
                getline(cin, tip);
                try {
                    if (tip == "Sub40") {
                        Sub40* p = new Sub40;
                        cin >> *p;
                        cabinet.push_back(p);
                    }
                    else if (tip == "Peste40") {
                        Peste40* p = new Peste40;
                        cin >> *p;
                        cabinet.push_back(p);
                    }
                    else if (tip == "Copil") {
                        Copil* p = new Copil;
                        cin >> *p;
                        cabinet.push_back(p);
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
            for(int it=0;it<3;it++){
                if(it==0){
                    Peste40* p;
                    cout<<"Adulti\nAdulti peste 40 de ani";
                    for(int i=0;i<n;i++){
                        p=dynamic_cast<Peste40*>(cabinet[i]);
                        if(p)
                            cout<<*cabinet[i];
                    }

                }
                else if(it==1){
                    cout<<"\nAdulti sub 40 de ani";
                    Sub40* p;
                    for(int i=0;i<n;i++){
                        p=dynamic_cast<Sub40*>(cabinet[i]);
                        if(p)
                            cout<<*cabinet[i];
                    }
                }
                else if(it==2){
                    cout<<"\nCopii";
                    Copil* p;
                    for(int i=0;i<n;i++){
                        p=dynamic_cast<Copil*>(cabinet[i]);
                        if(p)
                            cout<<*cabinet[i];
                    }
                }
            }
        }
        if (option == 3) {
            cout<<"Pacientii adulti cu factor de risc cardiovascular ridicat sunt: ";
            for(int it=0;it<2;it++){
                if(it==0){
                    Peste40* p;
                    for(int i=0;i<n;i++){
                        p=dynamic_cast<Peste40*>(cabinet[i]);
                        if(p&&p->getRisc_cardiovascular()=="RIDICAT")
                            cout<<*cabinet[i];
                    }

                }
                else if(it==1){
                    Sub40* p;
                    for(int i=0;i<n;i++){
                        p=dynamic_cast<Sub40*>(cabinet[i]);
                        if(p&&p->getRisc_cardiovascular()=="RIDICAT")
                            cout<<*cabinet[i];
                    }
                }
            }
        }
        if (option == 4) {
            cout<<"Pacientii copii cu risc cardiovascular sunt: ";
            Copil* p;
            for(int i=0;i<n;i++){
                p=dynamic_cast<Copil*>(cabinet[i]);
                if(p&&(p->getRisc_cardiovascular()=="DA"||p->getRisc_cardiovascular()=="RIDICAT"))
                    cout<<*cabinet[i];
            }
        }
        if (option == 5) {
            string nume;
            cout<<"Care este numele de familie pe care vreti sa il cautam? ";
            cin.get();
            getline(cin, nume);
            for(int it=0;it<3;it++){
                if(it==0){
                    ///ContEconomii* p=dynamic_cast<ContEconomii*>(sistem[nrcont-1]);
                    Peste40* p;
                    for(int i=0;i<n;i++){
                        p=dynamic_cast<Peste40*>(cabinet[i]);
                        if(p&&p->getNume()==nume)
                            cout<<*cabinet[i];
                    }

                }
                else if(it==1){
                    Sub40* p;
                    for(int i=0;i<n;i++){
                        p=dynamic_cast<Sub40*>(cabinet[i]);
                        if(p&&p->getNume()==nume)
                            cout<<*cabinet[i];
                    }
                }
                else if(it==2){
                    Copil* p;
                    for(int i=0;i<n;i++){
                        p=dynamic_cast<Copil*>(cabinet[i]);
                        if(p&&p->getNume()==nume)
                            cout<<*cabinet[i];
                    }
                }
            }
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
    }
    while (option != 0);
}
int main() {
    menu();
    return 0;
}
