#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;



class Date {
protected:
    string nume;
    long long CNP;
public:
    Date(const string &nume, long long cnp);
    virtual ~Date();
    const string &getNume() const;
    void setNume(const string &nume);
    long long int getCnp() const;
    void setCnp(long long int cnp);
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Date& obj);
    friend ostream& operator<<(ostream& out, const Date& obj);
};
Date::Date(const string &nume="", long long cnp=0) : nume(nume), CNP(cnp) {}
Date::~Date() {
    nume="";
    CNP=0;
}
const string &Date::getNume() const {
    return nume;
}

void Date::setNume(const string &nume) {
    this->nume = nume;
}

long long Date::getCnp() const {
    return CNP;
}

void Date::setCnp(long long cnp) {
    this->CNP = cnp;
}
void Date::citire(istream& in) {
    cout<<"Nume participant: ";
    in.get();
    getline(in, nume);
    cout<<"CNP participant: ";
    in>>CNP;
}
void Date::afisare(ostream& out) const {
    out << "Nume participant: "<<nume<<", CNP: "<<CNP;
}
istream& operator>>(istream& in, Date& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Date& obj) {
    obj.afisare(out);
    return out;
}

class Activitate {
protected:
    static int nr_participanti;
    int id_participant;
    string denumire;
    int zi_inc, luna_inc, an_inc;
    vector<Date> date_part;
public:
    Activitate(int idParticipant, const string &denumire, int ziInc, int lunaInc, int anInc,
               const vector<Date> &datePart);
    virtual ~Activitate();
    static int getNrParticipanti() {
        return nr_participanti;
    }
    static void setNrParticipanti(int nrParticipanti) {
        nr_participanti = nrParticipanti;
    }
    int getIdParticipant() const {
        return id_participant;
    }
    void setIdParticipant(int idParticipant) {
        this->id_participant = idParticipant;
    }

    const string &getDenumire() const {
        return denumire;
    }

    void setDenumire(const string &denumire) {
        this->denumire = denumire;
    }

    int getZiInc() const {
        return zi_inc;
    }

    void setZiInc(int ziInc) {
        this->zi_inc = ziInc;
    }

    int getLunaInc() const {
        return luna_inc;
    }

    void setLunaInc(int lunaInc) {
        this->luna_inc = lunaInc;
    }

    int getAnInc() const {
        return an_inc;
    }

    void setAnInc(int anInc) {
        this->an_inc = anInc;
    }
    void AdaugaParticipanti(int n);
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Activitate& obj);
    friend ostream& operator<<(ostream& out, const Activitate& obj);
};
int Activitate::nr_participanti=0;

Activitate::Activitate(int idParticipant=0, const string &denumire="", int ziInc=0, int lunaInc=0, int anInc=0,
                       const vector<Date> &datePart=vector<Date>()) : id_participant(idParticipant), denumire(denumire), zi_inc(ziInc),
                                                       luna_inc(lunaInc), an_inc(anInc)
{
    for(unsigned int i=0;i<datePart.size();i++)
        this->date_part.push_back(datePart[i]);
}
Activitate::~Activitate() {
    id_participant=0;
    denumire="";
    zi_inc=0;
    luna_inc=0;
    an_inc=0;
    date_part.clear();
}
void Activitate::AdaugaParticipanti(int n) {
    for(int i=0;i<n;i++){
        Date dp;
        cin>>dp;
        date_part.push_back(dp);
    }
}

void Activitate::citire(istream& in) {
    ///pentru string
    id_participant=++nr_participanti;
    cout << "Numele activitate: ";
    cin.get();
    getline(in, denumire);
    cout << "Zi inceput: ";
    in >> zi_inc;
    cout << "Luna inceput: ";
    in >> luna_inc;
    cout << "An inceput: ";
    in >> an_inc;
}
void Activitate::afisare(ostream& out) const {
    out << "\nNumele activitatii este: "<<denumire<<", a inceput la data de "<<zi_inc<<'.'<<luna_inc<<'.'<<an_inc;
    out<<" si au participat "<<date_part.size()<<" participanti:";
    for(unsigned int i=0;i<date_part.size();i++)
        cout<<date_part[i];
}
istream& operator>>(istream& in, Activitate& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Activitate& obj) {
    obj.afisare(out);
    return out;
}




class Curs : public Activitate{
    int durata;
    int nr_credite;
public:
    Curs(int idParticipant, const string &denumire, int ziInc, int lunaInc, int anInc,
         const vector<Date> &datePart, int durata, int nrCredite);
    ~Curs();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Curs& obj);
    friend ostream& operator<<(ostream& out, const Curs& obj);
};

Curs::Curs(int idParticipant=0, const string &denumire="", int ziInc=0, int lunaInc=0, int anInc=0,
           const vector<Date> &datePart=vector<Date>(), int durata=0, int nrCredite=0) :
           Activitate(id_participant, denumire, zi_inc, luna_inc, an_inc, datePart), durata(durata), nr_credite(nr_credite){}
Curs::~Curs() {
    durata=0;
    nr_credite=0;
}
void Curs::citire(istream& in) {
    Activitate::citire(in);
    cout<<"Durata activitate ";
    in>>durata;
    cout << "Numar credite ";
    in >> nr_credite;
}
void Curs::afisare(ostream& out) const {
    Activitate::afisare(out);
    out << ", desfasurata pe: "<<durata<<" zile, avand un numar de credite primite de un profesor: " << nr_credite;
}
istream& operator>>(istream& in, Curs& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Curs& obj) {
    obj.afisare(out);
    return out;
}

class Concurs: public Activitate {
    vector<pair <int, Date>> premianti;
public:
    Concurs(int idParticipant, const string &denumire, int ziInc, int lunaInc, int anInc, const vector<Date> &datePart,
            const vector<pair<int, Date>> & premianti);

    ~Concurs();
    void clasament();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Concurs& obj);
    friend ostream& operator<<(ostream& out, const Concurs& obj);
};

Concurs::Concurs(int idParticipant=0, const string &denumire=0, int ziInc=0, int lunaInc=0, int anInc=0,
                 const vector<Date> &datePart=vector<Date>(), const vector<pair<int, Date>> & premianti=vector<pair<int, Date>>()) :
                 Activitate(idParticipant, denumire, ziInc, lunaInc, anInc, datePart)
{
    for(unsigned int i=0;i<premianti.size();i++)
        this->premianti.push_back(premianti[i]);
}

Concurs::~Concurs() {
    premianti.clear();
}
bool sortinrev(const pair<int,Date> &a,
               const pair<int,Date> &b)
{
    return (a.first < b.first);
}
void Concurs::clasament()
{
    sort(premianti.begin(), premianti.end(), sortinrev);;
    unsigned int part=premianti.size(), i;
    for(i=part-1;i>=part-4;i--)
        cout<<premianti[i].second<<" cu un punctaj de "<<premianti[i].first<<" puncte";
}
void Concurs::citire(istream& in) {
    Activitate::citire(in);
    int punctaj;
    pair<int, Date> dpart;
    cout<<"Punctaje obtinute de participanti(in ordine): ";
    for(unsigned int i=0;i<date_part.size();i++) {
        cin >> punctaj;
        dpart.first=punctaj;
        dpart.second=date_part[i];
        premianti.push_back(dpart);
    }
}
void Concurs::afisare(ostream& out) const {
    Activitate::afisare(out);
}
istream& operator>>(istream& in, Concurs& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Concurs& obj) {
    obj.afisare(out);
    return out;
}

class ConcursOnline : public Concurs {
    int durata;
    string site;
public:
    ConcursOnline(int idParticipant, const string &denumire, int ziInc, int lunaInc, int anInc,
                  const vector<Date> &datePart, const vector<pair<int,Date>> &premianti, int durata, string site);

    ~ConcursOnline();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ConcursOnline& obj);
    friend ostream& operator<<(ostream& out, const ConcursOnline& obj);
};

ConcursOnline::ConcursOnline(int idParticipant=0, const string &denumire="", int ziInc=0, int lunaInc=0, int anInc=0,
                             const vector<Date> &datePart=vector<Date>(),
                             const vector<pair<int,Date>> &premianti=vector<pair<int,Date>>(), int durata=0, string site="") : Concurs(
        idParticipant, denumire, ziInc, lunaInc, anInc, datePart, premianti), durata(durata), site(site) {}

ConcursOnline::~ConcursOnline() {
    durata = 0;
    site="";
}
void ConcursOnline::citire(istream& in) {
    Concurs::citire(in);
    cout << "Durata concurs: ";
    in >> durata;
    cout<<"Site concurs: ";
    in.get();
    getline(in, site);
}
void ConcursOnline::afisare(ostream& out) const {
    Concurs::afisare(out);
    out << ", desfasurata pe: "<<durata<<" zile"<<" pe site-ul "<<site;
}
istream& operator>>(istream& in, ConcursOnline& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ConcursOnline& obj) {
    obj.afisare(out);
    return out;
}

class ConcursOffline : public Concurs {
public:
    ConcursOffline(int idParticipant, const string &denumire, int ziInc, int lunaInc, int anInc,
                  const vector<Date> &datePart, const vector<pair<int,Date>> &premianti);
    ~ConcursOffline();
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, ConcursOffline& obj);
    friend ostream& operator<<(ostream& out, const ConcursOffline& obj);
};

ConcursOffline::ConcursOffline(int idParticipant=0, const string &denumire="", int ziInc=0, int lunaInc=0, int anInc=0,
                             const vector<Date> &datePart=vector<Date>(),
                             const vector<pair<int,Date>> &premianti=vector<pair<int,Date>>()) : Concurs(
        idParticipant, denumire, ziInc, lunaInc, anInc, datePart, premianti){}

ConcursOffline::~ConcursOffline() {}
void ConcursOffline::citire(istream& in) {
    Concurs::citire(in);
}
void ConcursOffline::afisare(ostream& out) const {
    Concurs::afisare(out);
}
istream& operator>>(istream& in, ConcursOffline& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const ConcursOffline& obj) {
    obj.afisare(out);
    return out;
}


///----------------------------clasa CABINET-SINGLETON----------------------------

class Organizatie { //SINGLETON
private:
    string numeOrganizatie;
    static Organizatie* instance;
    Organizatie(string = "");
    vector<Activitate*> activitati;

public:
    static Organizatie* getInstance(string);
    Organizatie(const Organizatie& obj);
    ~Organizatie();

    const string &getNumeOrganizatie() const;

    void setNumeOrganizatie(const string &numeOrganizatie);

    void menu_output();
    void citesteActivitati();
    void adaugaParticipanti();
    void afiseazaActivitati();
    void afiseazaParticipantiData(int zi, int luna, int an);
    void afiseazaPremianti();
    Organizatie& operator=(Organizatie& obj);

};
Organizatie* Organizatie::instance = NULL;

Organizatie::Organizatie(string numeDoctor): numeOrganizatie(numeDoctor) {}

Organizatie* Organizatie::getInstance(string numeOrganizatie) {
    if(instance == NULL) {
        instance = new Organizatie(numeOrganizatie);
    }
    return instance;
}
Organizatie::Organizatie(const Organizatie& obj) {
    this->numeOrganizatie= obj.numeOrganizatie;
    for(unsigned int i=0; i < activitati.size(); i++)
        this->activitati.push_back(obj.activitati[i]);
}

Organizatie::~Organizatie() {
    numeOrganizatie="";
    for(unsigned int i=0; i < activitati.size(); i++)
        delete activitati[i];
    activitati.clear();
}
void Organizatie::menu_output() {
    cout << "\nACTIVITATI\n";
    cout << "Organizatie: " << this->numeOrganizatie << "\n";
    cout << "\n\t\tMENIU:";
    cout << "\n===========================================\n";
    cout << "\n1. Citeste activitati --- UPCAST & LATE-BINDING";
    cout << "\n2. Adauga n participanti la o activitate anumita";
    cout << "\n3. Afiseaza participantii";
    cout << "\n4. Afiseaza participantii la toate activitatile care incep intr-o zi data";
    cout << "\n5. Afiseaza premiantii la concursuri si profesorii participanti la cursuri";
    cout << "\n0. Iesire.";
    cout << "\n";
}

const string &Organizatie::getNumeOrganizatie() const {
    return numeOrganizatie;
}

void Organizatie::setNumeOrganizatie(const string &numeOrganizatie) {
    Organizatie::numeOrganizatie = numeOrganizatie;
}


void Organizatie::citesteActivitati() {
    int n;
    cout << "Cate activitati sunt organizate? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout<<"\nActivitatea "<<i+1<<":\n";
        string tip;
        cout << "Mentionati tipul activitatii(Curs/ConcursOnline/ConcursOffline): ";
        cin.get();
        getline(cin, tip);
        try {
            if (tip == "Curs") {
                Activitate* p = new Curs;
                cin >> *p;
                activitati.push_back(p);
            }
            else if (tip == "ConcursOnline") {
                Activitate* p = new ConcursOnline;
                cin >> *p;
                activitati.push_back(p);
            }
            else if (tip == "ConcursOffline") {
                Activitate* p = new ConcursOffline;
                cin >> *p;
                activitati.push_back(p);
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

void Organizatie::afiseazaActivitati() {
    cout << "Organizatia are " << activitati.size() << " activitati";
    for(unsigned int i=0; i < activitati.size(); i++)
        cout<<*activitati[i];
}

Organizatie& Organizatie::operator=(Organizatie& obj) {
    if (this != &obj) {
        this->numeOrganizatie= obj.numeOrganizatie;
        for(unsigned int i=0; i < activitati.size(); i++)
            this->activitati.push_back(obj.activitati[i]);
    }
    return *this;
}


///------------------------------MENIU-----------------------------

void menu() {
    int option;///optiunea aleasa din meniu
    option = 0;
    Organizatie *C = C->getInstance("Popescu Ion");
    do {
        C->menu_output();
        cout << "\nIntroduceti numarul actiunii: ";
        cin >> option;
        if(option == 1) {
            C->citesteActivitati();
        }
        else if(option == 2) {
           /// C->afiseazaPacienti();
        }
        if(option == 3) {
            C->afiseazaActivitati();
        }
        if(option == 4) {
            ///C->afiseazaCopiiRisc();
        }
        if(option == 5) {

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

