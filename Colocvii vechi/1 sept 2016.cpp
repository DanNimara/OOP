#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

class Cerere {
public:
    Cerere();
    Cerere(const Cerere& obj);
    virtual ~Cerere()=0;
    virtual void citire(istream&)=0;
    virtual void afisare(ostream&) const=0;
    Cerere& operator=(const Cerere& obj);
};

Cerere::Cerere() {}
Cerere::Cerere(const Cerere& obj) {}
Cerere::~Cerere() {}
Cerere& Cerere::operator=(const Cerere& obj) {
    return *this;
}

class Home : public Cerere {
    int proiector;
    int ecran;
    int tabla;
public:
    Home(int=0, int=0, int=0); ///constructor cu param default (apel pt baza)
    Home(const Home& obj);
    ~Home();

    int getProiector() const;

    void setProiector(int proiector);

    int getEcran() const;

    void setEcran(int ecran);

    int getTabla() const;

    void setTabla(int tabla);
    void Home_Opreste(string param);
    string Home_verificare();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Home& obj);
    friend ostream& operator<<(ostream& out, const Home& obj);
    Home& operator+(int val);
    Home& operator+(char lit);
    Home& operator=(const Home& obj);
};


Home::Home(int proiector, int ecran, int tabla): Cerere(), proiector(proiector), ecran(ecran), tabla(tabla) {

}
Home::Home(const Home& obj) : Cerere(obj) {
    this->proiector = obj.proiector;
    this->ecran=obj.ecran;
    this->tabla=obj.tabla;
}
Home::~Home() {
    proiector=0;
    ecran=0;
    tabla=0;
}

int Home::getProiector() const {
    return proiector;
}

void Home::setProiector(int proiector) {
    this->proiector = proiector;
}

int Home::getEcran() const {
    return ecran;
}

void Home::setEcran(int ecran) {
    this->ecran = ecran;
}

int Home::getTabla() const {
    return tabla;
}

void Home::setTabla(int tabla) {
    this->tabla = tabla;
}

void Home::citire(istream& in) {
    cout << "Este pornit proiectorul?(0-off/1-on) ";
    in >> proiector;
    cout << "Este lasat ecranul?(0-up/1-down) ";
    in >> ecran;
    cout << "Este pornita tabla?(0-off/1-on) ";
    in >> tabla;
}
void Home::afisare(ostream& out) const {
    out<<"Proiectorul este ";
    if(proiector==0) out<<"oprit";
    else out<<"pornit";
    out<<", ecranul este ";
    if(ecran==0) out<<"sus";
    else out<<"jos";
    out<<", tabla este ";
    if(tabla==0) out<<"oprita";
    else out<<"pornita";
}
istream& operator>>(istream& in, Home& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Home& obj) {
    obj.afisare(out);
    return out;
}
Home& Home::operator=(const Home& obj) {
    if (this != &obj) {
        this->proiector = obj.proiector;
        this->ecran=obj.ecran;
        this->tabla=obj.tabla;
    }
    return *this;
}

void Home::Home_Opreste(string param) {
    if(param=="tabla")
        tabla=0;
}

string Home::Home_verificare() {
    string verif;
    if((proiector==1&&ecran==1&&tabla==0)||(proiector==0&&ecran==1&&tabla==1)||(proiector==0&&ecran==0&&tabla==0))
        verif="OK";
    else verif="Nu am inteles cerinta!";
    return verif;
}

Home& Home::operator+(int val) {
    proiector=1;
    return *this;
}

Home& Home::operator+(char lit) {
    try{
        if(lit=='E') ecran=1;
        else throw 1;
    }
    catch(int i){
        cout<<"Nu se poate face operatiunea pe dispozitivul resp";
    }
    return *this;
}


class Education : public Home {
public:
    Education(int=0, int=0, int=0);
    Education(const Education& obj);
    ~Education();
    string Edu_Lectie(string materie, int nr_curs);
    string Edu_Trivia(string cautare);
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Education& obj);
    friend ostream& operator<<(ostream& out, const Education& obj);
    Education& operator=(const Education& obj);
};

Education::Education(int proiector, int ecran, int tabla) : Home(proiector, ecran, tabla) {}
Education::Education(const Education& obj) : Home(obj) {
}
Education::~Education() {
}

string Education::Edu_Lectie(string materie, int nr_curs) {
    string rez;
    if(this->getTabla()==0&&this->getEcran()==1&&this->getProiector()==1) {
        rez = "Download - "+materie+" - Curs "+to_string(nr_curs);
    }
    else rez="Eroare componenta hardware";
    return rez;
}

string Education::Edu_Trivia(string cautare) {
    string rez;
    if(this->getTabla()==0&&this->getEcran()==1&&this->getProiector()==1) {
        rez = "Cautare "+cautare;
    }
    else rez="Eroare componenta hardware";
    return rez;
}

void Education::citire(istream& in) {
    Home::citire(in);
}
void Education::afisare(ostream& out) const {
    Home::afisare(out);
}
istream& operator>>(istream& in, Education& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Education& obj) {
    obj.afisare(out);
    return out;
}
Education& Education::operator=(const Education& obj) {
    if (this != &obj) {
        Home::operator=(obj) ;
    }
    return *this;
}

class User : public Education{
    static int ID;
    int id_user;
    string rol;
    int zi_ses, luna_ses, an_ses;
public:
    User(int proiector=0, int ecran=0, int tabla=0, int idUser=0, const string &rol="", int ziSes=0, int lunaSes=0,
         int anSes=0);

    User(const User& obj);
    ~User();

    static int getId();

    static void setId(int id);

    int getIdUser() const;

    void setIdUser(int idUser);

    int getZiSes() const;

    void setZiSes(int ziSes);

    int getLunaSes() const;

    void setLunaSes(int lunaSes);

    int getAnSes() const;

    void setAnSes(int anSes);
    const string &getRol() const;
    void setRol(const string &rol);
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, User& obj);
    friend ostream& operator<<(ostream& out, const User& obj);
    User& operator=(const User& obj);

};
int User::ID=0;

User::User(const User& obj) : Education(obj) {
    this->id_user=obj.id_user;
    this->rol=obj.rol;
    this->zi_ses=obj.zi_ses;
    this->luna_ses=obj.luna_ses;
    this->an_ses=obj.an_ses;
}
User::~User() {
    ///md1 = 0;
}
User::User(int proiector, int ecran, int tabla, int idUser, const string &rol, int ziSes, int lunaSes,
           int anSes) : Education(proiector, ecran, tabla), id_user(idUser), rol(rol), zi_ses(ziSes),
                        luna_ses(lunaSes), an_ses(anSes) {}

int User::getId() {
    return ID;
}

void User::setId(int id) {
    ID = id;
}

int User::getIdUser() const {
    return id_user;
}

void User::setIdUser(int idUser) {
    this->id_user = idUser;
}

int User::getZiSes() const {
    return zi_ses;
}

void User::setZiSes(int ziSes) {
    this->zi_ses = ziSes;
}

int User::getLunaSes() const {
    return luna_ses;
}

void User::setLunaSes(int lunaSes) {
    this->luna_ses = lunaSes;
}

int User::getAnSes() const {
    return an_ses;
}

void User::setAnSes(int anSes) {
    this->an_ses = anSes;
}

const string &User::getRol() const {
    return rol;
}

void User::setRol(const string &rol) {
    User::rol = rol;
}

void User::citire(istream& in) {
    Home::citire(in);
    id_user=++ID;
    cout << "Care este rolul utilizatorului?(student/profesor) ";
    in >> rol;
    cout<<"Ziua activarii ";
    in>>zi_ses;
    cout<<"Luna activarii";
    in>>luna_ses;
    cout<<"Anul activarii";
    in>>an_ses;
}
void User::afisare(ostream& out) const {
    Home::afisare(out);
    out << "\nId user"<<id_user<<", rol user " << rol<<", data activare "<<zi_ses<<'.'<<luna_ses<<'.'<<an_ses;
}
istream& operator>>(istream& in, User& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const User& obj) {
    obj.afisare(out);
    return out;
}
User& User::operator=(const User& obj) {
    if (this != &obj) {
        Education::operator=(obj) ;
        this->id_user=obj.id_user;
        this->rol=obj.rol;
        this->zi_ses=obj.zi_ses;
        this->luna_ses=obj.luna_ses;
        this->an_ses=obj.an_ses;
    }
    return *this;
}

///----------------------------clasa SOFT-SINGLETON----------------------------

class Soft { //SINGLETON
private:
    string numeFacultate;
    static Soft* instance;
    Soft(string = "", int=0, int=0);
    vector<User> utilizatori;
    int nr_moodle;
    vector<int> max_trivia;
    int comenzi;
public:
    static Soft* getInstance(string);
    Soft(const Soft& obj);
    ~Soft();

    const string &getNumeFacultate() const {
        return numeFacultate;
    }

    void setNumeFacultate(const string &numeFacultate) {
        this->numeFacultate = numeFacultate;
    }

    void menu_output();
    void citesteUtilizatori();
    void descarcare();
    void componente();
    void trivia();
    void afiseazaUtilizatori();
    void afiseazaSesiuni();
    void afiseazaActivari();
    void afiseazaElev();
    void afiseazaComenziTabla();
    Soft& operator=(Soft& obj);

};
Soft* Soft::instance = NULL;

Soft::Soft(string numeFacultate, int nr_moodle, int comenzi): numeFacultate(numeFacultate), nr_moodle(nr_moodle),
comenzi(comenzi){}

Soft* Soft::getInstance(string numeFacultate) {
    if(instance == NULL) {
        instance = new Soft(numeFacultate);
    }
    return instance;
}
Soft::Soft(const Soft& obj) {
    this->numeFacultate= obj.numeFacultate;
    for(unsigned int i=0; i < utilizatori.size(); i++)
        this->utilizatori.push_back(obj.utilizatori[i]);
}

Soft::~Soft() {
    numeFacultate="";
    utilizatori.clear();
    max_trivia.clear();
    nr_moodle=0;
    comenzi=0;
}
void Soft::menu_output() {
    cout << "\nSOFT\n";
    cout << "Facultate: " << this->numeFacultate << "\n";
    cout << "\n\t\tMENIU:";
    cout << "\n===========================================\n";
    cout << "\n1. Citeste utilizatori";
    cout << "\n2. Descarca de pe moodle";
    cout << "\n3. Foloseste Trivia";
    cout << "\n4. Utilizeaza componente";
    cout << "\n5. Afiseaza utilizatori";
    cout << "\n6. Afiseaza sesiuni prelucrare pe 1.9.2016";
    cout << "\n7. Afiseaza activari moodle";
    cout << "\n8. Afiseaza elevul care a folosit cel mai des Trivia";
    cout << "\n9. Afiseaza numarul de comenzi care au utilizat tabletele Smart";
    cout << "\n0. Iesire.";
    cout << "\n";
}

void Soft::afiseazaUtilizatori() {
    cout << "Softul are " << utilizatori.size() << " utilizatori";
    for(unsigned int i=0;i<utilizatori.size();i++)
        cout<<utilizatori[i];
}

Soft& Soft::operator=(Soft& obj) {
    if (this != &obj) {
        this->numeFacultate= obj.numeFacultate;
        for(unsigned int i=0; i < utilizatori.size(); i++)
            this->utilizatori.push_back(obj.utilizatori[i]);
        this->comenzi=obj.comenzi;
        this->nr_moodle=obj.nr_moodle;
    }
    return *this;
}

void Soft::citesteUtilizatori() {
    int n;
    cout << "Cati utilizatori are softul? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        User utilizator;
        cin>>utilizator;
        utilizatori.push_back(utilizator);
    }
}

void Soft::descarcare() {
    unsigned int id;
    cout<<"Ce utilizator doreste sa descarce de pe moodle?";
    cin>>id;
    try{
        if(id>0&&id<=utilizatori.size()){
            if(utilizatori[id].getRol()=="profesor"){
                ++nr_moodle;
                string materie;
                int nr_curs;
                cout<<"Ce materie va intereseaza? ";
                cin.get();
                getline(cin, materie);
                cout<<"Care curs? ";
                cin>>nr_curs;
                utilizatori[id].Edu_Lectie(materie, nr_curs);
            }
            else cout<<"Studentii nu pot descarca materiale";
        }
        else throw 1;
    }
    catch(int i) {
        cout << "Nu exista utilizatorul cu id-ul respectiv.";
    }
}

void Soft::componente() {
    unsigned int id;
    cout<<"Ce utilizator doreste sa utilizeze componentele?";
    cin>>id;
    try{
        if(id>0&&id<=utilizatori.size()){
            ++comenzi;
            cout<<"Ce doriti sa utilizati? ";
        }
        else throw 1;
    }
    catch(int i) {
        cout << "Nu exista utilizatorul cu id-ul respectiv.";
    }
}

void Soft::trivia() {

}

void Soft::afiseazaSesiuni() {

}

void Soft::afiseazaActivari() {

}

void Soft::afiseazaElev() {

}

void Soft::afiseazaComenziTabla() {

}


///------------------------------MENIU-----------------------------

void menu() {
    int option;///optiunea aleasa din meniu
    option = 0;
    Soft *C = C->getInstance("Popescu Ion");
    do {
        C->menu_output();
        cout << "\nIntroduceti numarul actiunii: ";
        cin >> option;
        if(option == 1) {
            C->citesteUtilizatori();
        }
        else if(option == 2) {
            C->descarcare();
        }
        if(option == 3) {
            C->trivia();
        }
        if(option == 4) {
            C->componente();
        }
        if(option == 5) {
            C->afiseazaUtilizatori();
        }
        if(option == 6) {
            C->afiseazaSesiuni();
        }
        if(option == 7) {
            C->afiseazaActivari();
        }
        if(option == 8) {
            C->afiseazaElev();
        }
        if(option == 9) {
            C->afiseazaComenziTabla();
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