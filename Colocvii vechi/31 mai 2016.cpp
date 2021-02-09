#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


///----------------------------clasa INGREDIENT--------------------------

class Ingredient {
    string denIng;
    double pretIng;
    int cantIng;
    string masIng;
public:
    Ingredient(string="", double=0, int=0, string="");
    Ingredient(const Ingredient& obj);
    virtual ~Ingredient();
    double getPretIng(){return pretIng;}
    int getCantIng(){return cantIng;}
    string getMasIng(){return masIng;}
    void del();
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Ingredient& obj);
    friend ostream& operator<<(ostream& out, const Ingredient& obj);
    Ingredient& operator+(int cant);
    Ingredient operator++(int dummy);
    Ingredient& operator-=(double pret);
    bool operator==(const Ingredient& obj);
    Ingredient& operator=(const Ingredient& obj);
};

Ingredient::Ingredient(string denIng, double pretIng, int cantIng, string masIng) : denIng(denIng), pretIng(pretIng), cantIng(cantIng), masIng(masIng) {}
Ingredient::Ingredient(const Ingredient& obj) {
    this->denIng=obj.denIng;
    this->pretIng=obj.pretIng;
    this->cantIng=obj.cantIng;
    this->masIng=obj.masIng;
}
Ingredient::~Ingredient() {
    denIng="";
    pretIng=0;
    cantIng=0;
    masIng="";
}
void Ingredient::citire(istream& in) {
    cout << "Nume ingredient: ";
    in.get();
    getline(in, denIng);
    cout << "Pret: ";
    in >> pretIng;
    cout << "Cantitate: ";
    in >> cantIng;
    cout<<"Unitate de masura(kg, felii, gram): ";
    in>>masIng;
}
void Ingredient::afisare(ostream& out) const {
    out << "\nIngredient "<<denIng<<" pret: "<<pretIng<<" Cantitate "<<cantIng<<' '<<masIng;
}
istream& operator>>(istream& in, Ingredient& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Ingredient& obj) {
    obj.afisare(out);
    return out;
}
Ingredient& Ingredient::operator+(int cant)
{
    cantIng++;
    return *this;
}
Ingredient Ingredient::operator++(int dummy)
{
    Ingredient temp=*this;
    cantIng++;
    return temp;
}
Ingredient& Ingredient::operator-=(double pret)
{
    pretIng=pretIng-pret;
    return *this;
}
bool Ingredient::operator==(const Ingredient& obj)
{
    return denIng==obj.denIng&&pretIng==obj.pretIng&&cantIng==obj.cantIng&&masIng==obj.masIng;
}
Ingredient& Ingredient::operator=(const Ingredient& obj) {
    if (this != &obj) {
        this->denIng=obj.denIng;
        this->pretIng=obj.pretIng;
        this->cantIng=obj.cantIng;
        this->masIng=obj.masIng;
    }
    return *this;
}

///-----------------------------------------clasa PIZZA-----------------------------------

class Pizza {
protected:
    static int ID;
    int codPizza;
    string denPizza;
    vector<Ingredient> ingPizza;
    int nringPizza;
    bool vegPizza;
    double pretPizza;
public:
    Pizza(string="", vector<Ingredient> ingPizza=vector<Ingredient>(), int=0, bool=false);
    Pizza(const Pizza& obj);
    virtual ~Pizza();
    void calculPret();
    int getNringPizza(){return nringPizza;}
    double getPretPizza(){return pretPizza;}
    string getDenPizza(){return denPizza;}
    string nume();
    void nume(string nume){this->denPizza=nume;}
    double pret();
    Ingredient getIngredient(int i){return ingPizza[i];}
    double getPretIngredient(int i){return ingPizza[i].getPretIng();}
    int getCantIngredient(int i){return ingPizza[i].getCantIng();}
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Pizza& obj);
    friend ostream& operator<<(ostream& out, const Pizza& obj);
    Pizza& operator-(const Ingredient& ingr);
    Pizza& operator+(const Ingredient& ingr);
    Pizza& operator=(const Pizza& obj);
};
int Pizza::ID=0;
Pizza::Pizza(string denPizza, vector<Ingredient> ingPizza, int nringPizza, bool vegPizza) :
            denPizza(denPizza), nringPizza(nringPizza), vegPizza(vegPizza)
{
    this->ingPizza.clear();
    for(unsigned int i=0; i<ingPizza.size();i++)
        this->ingPizza.push_back(ingPizza[i]);
}
Pizza::Pizza(const Pizza& obj) {
    this->codPizza=obj.codPizza;
    this->denPizza=obj.denPizza;
    for(unsigned int i=0; i<ingPizza.size();i++)
        this->ingPizza.push_back(ingPizza[i]);
    this->nringPizza=obj.nringPizza;
    this->vegPizza=obj.vegPizza;
}
Pizza::~Pizza() {
    codPizza=0;
    denPizza="";
    ingPizza.clear();
    nringPizza=0;
    vegPizza=false;
}
void Pizza::calculPret()
{
    for(unsigned int i=0;i<ingPizza.size();i++){
        pretPizza=pretPizza+ingPizza[i].getCantIng()*ingPizza[i].getPretIng()*1.5;
    }
}
string Pizza::nume()
{
    return denPizza;
}
double Pizza::pret()
{
    return pretPizza;
}
void Pizza::citire(istream& in) {
    codPizza=++ID;
    cout << "Nume pizza: ";
    in.get();
    getline(in, denPizza);
    cout << "Cate ingrediente are pizza? ";
    in >> nringPizza;
    cout<<"Enumerati ingredientele: ";
    for(int i=0;i<nringPizza;i++){
        Ingredient ingr;
        cin>>ingr;
        ingPizza.push_back(ingr);
    }
    string rasp;
    cout<<"Pizza vegana?(DA/NU)";
    cin>>rasp;
    if(rasp=="DA")
        vegPizza=true;
    else if(rasp=="NU")
        vegPizza=false;
}
void Pizza::afisare(ostream& out) const {
    out<<"\nPizza "<<denPizza<<" are codul "<<codPizza;
    if(vegPizza==true)
    out <<", este vegetariana si are "<<nringPizza<<" ingrediente: ";
    else out <<", nu este vegetariana si are "<<nringPizza<<" ingrediente: ";
    for(int i=0;i<nringPizza;i++)
        cout<<ingPizza[i];
}
istream& operator>>(istream& in, Pizza& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Pizza& obj) {
    obj.afisare(out);
    return out;
}
Pizza& Pizza::operator-(const Ingredient& ingr)
{
    for(int i=0;i<nringPizza;i++)
        if(ingPizza[i]==ingr)
            ingPizza.erase(ingPizza.begin()+i);
    return *this;
}
Pizza& Pizza::operator+(const Ingredient& ingr)
{
    ingPizza.push_back(ingr);
    return *this;
}
Pizza& Pizza::operator=(const Pizza& obj) {
    if (this != &obj) {
        this->codPizza=obj.codPizza;
        this->denPizza=obj.denPizza;
        for(unsigned int i=0; i<ingPizza.size();i++)
            this->ingPizza.push_back(ingPizza[i]);
        this->nringPizza=obj.nringPizza;
        this->vegPizza=obj.vegPizza;
    }
    return *this;
}

///-------------------------clasa PIZZASPEC---------------------------

class PizzaSpec : public Pizza {
    vector<Ingredient> ingPizzaSup;
    int nringPizzaSup;
  public:
    PizzaSpec(string="", vector<Ingredient> ingPizza=vector<Ingredient>(), int=0, bool=false, vector<Ingredient> ingPizzaSup=vector<Ingredient>(),
              int=0);
    PizzaSpec(const PizzaSpec& obj);
    ~PizzaSpec();
    double getPretIngredientSup(int i){return ingPizzaSup[i].getPretIng();}
    int getCantIngredientSup(int i){return ingPizzaSup[i].getCantIng();}
    int getNringPizzaSup(){return nringPizzaSup;}
    void citire(istream&);
    void afisare(ostream&) const;
    friend istream& operator>>(istream& in, PizzaSpec& obj);
    friend ostream& operator<<(ostream& out, const PizzaSpec& obj);
    PizzaSpec& operator=(const PizzaSpec& obj);
};

PizzaSpec::PizzaSpec(string denPizza, vector<Ingredient> ingPizza, int nringPizza, bool vegPizza, vector<Ingredient> ingPizzaSup, int nringPizzaSup) :
            Pizza(denPizza, ingPizza, nringPizza, vegPizza), nringPizzaSup(nringPizzaSup)
{
    this->ingPizzaSup.clear();
    for(unsigned int i=0; i<ingPizzaSup.size();i++)
        this->ingPizzaSup.push_back(ingPizzaSup[i]);
}
PizzaSpec::PizzaSpec(const PizzaSpec& obj): Pizza(obj)
{
    this->ingPizzaSup.clear();
    for(unsigned int i=0; i<obj.ingPizzaSup.size();i++)
        this->ingPizzaSup.push_back(obj.ingPizzaSup[i]);
    this->nringPizzaSup=obj.nringPizzaSup;
}
PizzaSpec::~PizzaSpec() {
    ingPizzaSup.clear();
    nringPizzaSup=0;
}
void PizzaSpec::citire(istream& in) {
    Pizza::citire(in);
    try{
        if(vegPizza==true) throw 1;
        cout << "Cate ingrediente suplimentare are pizza? ";
        in >> nringPizzaSup;
        cout<<"Enumerati ingredientele suplimentare: ";
        for(int i=0;i<nringPizzaSup;i++){
            Ingredient ingr;
            cin>>ingr;
            ingPizzaSup.push_back(ingr);
        }
    }
    catch(int i)
    {
        cout<<"\nPizza vegetariana nu poate fi folosita pentru a face sortimente speciale de pizza!";
    }
}
void PizzaSpec::afisare(ostream& out) const {
    Pizza::afisare(out);
    out << "\nPizza are "<<nringPizzaSup<<" ingrediente suplimentare:\n";
    for(int i=0;i<nringPizzaSup;i++)
        cout<<ingPizzaSup[i];
}
istream& operator>>(istream& in, PizzaSpec& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const PizzaSpec& obj) {
    obj.afisare(out);
    return out;
}
PizzaSpec& PizzaSpec::operator=(const PizzaSpec& obj) {
    if (this != &obj) {
        Pizza::operator=(obj) ;
        this->ingPizzaSup.clear();
        for(unsigned int i=0; i<obj.ingPizzaSup.size();i++)
            this->ingPizzaSup.push_back(obj.ingPizzaSup[i]);
        this->nringPizzaSup=obj.nringPizzaSup;
    }
    return *this;
}

///---------------------clasa BAUTURA-----------------------

class Bautura {
    string denBaut;
    double pretBaut;
public:
    Bautura(string="", double=0);
    Bautura(const Bautura& obj);
    virtual ~Bautura();
    double getPretBaut(){return pretBaut;}
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, Bautura& obj);
    friend ostream& operator<<(ostream& out, const Bautura& obj);
    Bautura& operator=(const Bautura& obj);
};

Bautura::Bautura(string denBaut, double pretBaut) : denBaut(denBaut), pretBaut(pretBaut) {}
Bautura::Bautura(const Bautura& obj) {
    this->denBaut=obj.denBaut;
    this->pretBaut=obj.pretBaut;
}
Bautura::~Bautura() {
    denBaut="";
    pretBaut=0;
}
void Bautura::citire(istream& in) {
    cout<<"Nume bautura: ";
    in.get();
    getline(in, denBaut);
    cout<<"Pret bautura: ";
    in>>pretBaut;
}
void Bautura::afisare(ostream& out) const {
    out << "\nBautura este "<<denBaut<<" si costa "<<pretBaut;
}
istream& operator>>(istream& in, Bautura& obj) {
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Bautura& obj) {
    obj.afisare(out);
    return out;
}
Bautura& Bautura::operator=(const Bautura& obj) {
    if (this != &obj) {
        this->denBaut=obj.denBaut;
        this->pretBaut=obj.pretBaut;
    }
    return *this;
}

///--------------------clasa OFSPEC---------------------------
class OfSpec {
protected:
    Pizza* pizza;
    Bautura* bautura;
    double pretMeniu;
public:
    OfSpec(Pizza* pizza=NULL, Bautura* bautura=NULL, double=0);
    OfSpec(const OfSpec& obj);
    virtual ~OfSpec();
    void calculMeniu();
    double calculCastig();
    virtual void citire(istream&, string);
    virtual void afisare(ostream&) const;
    friend istream& operator>>(istream& in, OfSpec& obj);
    friend ostream& operator<<(ostream& out, const OfSpec& obj);
    OfSpec& operator=(const OfSpec& obj);
};

OfSpec::OfSpec(Pizza* pizza, Bautura* bautura, double pretMeniu)
{
    this->pizza=pizza;
    this->bautura=bautura;
    this->pretMeniu=pretMeniu;
}
OfSpec::OfSpec(const OfSpec& obj) {
    this->pizza=obj.pizza;
    this->bautura=obj.bautura;
    this->pretMeniu=obj.pretMeniu;
}
OfSpec::~OfSpec() {
    delete pizza;
    delete bautura;
    pretMeniu=0;
}
void OfSpec::calculMeniu()
{
    pretMeniu=0.75*(pizza->getPretPizza()+bautura->getPretBaut());
}
double OfSpec::calculCastig()
{
    double castig=pretMeniu;
    Pizza* p1=dynamic_cast<Pizza*>(pizza);
    PizzaSpec* p2=dynamic_cast<PizzaSpec*>(pizza);
    if(p1||p2){
        for(int i=0;i<p1->getNringPizza();i++)
            castig=castig-p1->getCantIngredient(i)*p1->getPretIngredient(i);
    }
    if(p2){
        for(int i=0;i<p2->getNringPizzaSup();i++)
        castig=castig-p2->getCantIngredientSup(i)*p2->getPretIngredientSup(i);
    }
    castig-=bautura->getPretBaut();
    return castig;
}
void OfSpec::citire(istream& in, string tip) {
    if(tip=="Standard"){
        pizza=new Pizza;
        cin>>*pizza;
    }
    else if(tip=="Speciala"){
        pizza=new PizzaSpec;
        cin>>*pizza;
    }
    bautura=new Bautura;
    cin>>*bautura;
    calculMeniu();
}
void OfSpec::afisare(ostream& out) const {
    out << "\nMeniul este format din: ";
    out<<*pizza<<*bautura<<"\nCosta in total: "<<pretMeniu;
}
istream& operator>>(istream& in, OfSpec& obj) {
    cout<<"Ce pizza doriti la meniu?(Standard/Speciala) ";
    string tip;
    cin>>tip;
    obj.citire(in, tip);
    return in;
}
ostream& operator<<(ostream& out, const OfSpec& obj) {
    obj.afisare(out);
    return out;
}
OfSpec& OfSpec::operator=(const OfSpec& obj) {
    if (this != &obj) {
        this->pizza=obj.pizza;
        this->bautura=obj.bautura;
        this->pretMeniu=obj.pretMeniu;
    }
    return *this;
}

///----------------------------clasa PIZZERIE-SINGLETON----------------------------

class Pizzerie { //SINGLETON
  private:
    string numePizzerie1;
    static Pizzerie* instance;
    Pizzerie(string = "");
    vector<Pizza*> pizze;
    vector<Ingredient> ingrediente;
    vector<OfSpec> oferte;
  public:
    static Pizzerie* getInstance(string);
    Pizzerie(const Pizzerie& obj);
    ~Pizzerie();
    string getNumePizzerie();
    void setNumePizzerie(string);
    void menu_output();
    void citestePizze();
    void citesteOferteSpeciale();
    void vectIngrediente();
    void afiseazaIngrediente();
    void afiseazaPizze();
    void afiseazaPizza(string);
    void afiseazaOferte();
    Pizzerie& operator=(Pizzerie& obj);

};
Pizzerie* Pizzerie::instance = NULL;

Pizzerie::Pizzerie(string numePizzerie1): numePizzerie1(numePizzerie1) {}

Pizzerie* Pizzerie::getInstance(string numePizzerie1) {
    if(instance == NULL) {
        instance = new Pizzerie(numePizzerie1);
    }
    return instance;
}
Pizzerie::Pizzerie(const Pizzerie& obj) {
    this->numePizzerie1= obj.numePizzerie1;
    for(unsigned int i=0; i<pizze.size(); i++)
        this->pizze.push_back(obj.pizze[i]);
    for(unsigned int i=0;i<ingrediente.size();i++)
        this->ingrediente.push_back(obj.ingrediente[i]);
    for(unsigned int i=0;i<oferte.size();i++)
        this->oferte.push_back(obj.oferte[i]);
}

Pizzerie::~Pizzerie() {
    numePizzerie1="";
    for(unsigned int i=0; i<pizze.size(); i++)
        delete pizze[i];
    pizze.clear();
    ingrediente.clear();
    oferte.clear();
}
void Pizzerie::menu_output() {
    cout << "\nPIZZERIE\n";
    cout << "Nume pizzerie: " << this->numePizzerie1 << "\n";
    cout << "\n\t\tMENIU:";
    cout << "\n===========================================\n";
    cout << "\n1. Citeste pizze --- UPCAST & LATE-BINDING";
    cout << "\n2. Citeste oferte speciale";
    cout << "\n3. Afiseaza pizze";
    cout << "\n4. Afiseaza ingredientele unei pizze";
    cout << "\n5. Afiseaza ofertele speciale si castigul obtinut din vanzare";
    cout << "\n0. Iesire.";
    cout << "\n";
}
void Pizzerie::citestePizze() {
    int n;
    cout << "Cate pizze are pizzeria? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout<<"\nPizza "<<i+1<<":\n";
        string tip;
        cout << "Mentionati tipul pizzei(Standard/Speciala): ";
        cin.get();
        getline(cin, tip);
        try {
            if (tip == "Standard") {
                Pizza* p = new Pizza;
                cin >> *p;
                pizze.push_back(p);
            }
            else if (tip == "Speciala") {
                Pizza* p = new PizzaSpec;
                cin >> *p;
                pizze.push_back(p);
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
void Pizzerie::citesteOferteSpeciale()
{
    int n;
    cout<<"Cate oferte speciale exista? ";
    cin>>n;
    cout<<"Enumerati ofertele: \n";
    for(int i=0;i<n;i++){
        OfSpec oferta;
        cin>>oferta;
        oferte.push_back(oferta);
    }
}
void Pizzerie::afiseazaPizze() {
    cout<<"Pizzeria are "<<pizze.size()<<" pizze";
    for(unsigned int i=0; i<pizze.size(); i++) {
        cout<<*pizze[i];
    }
}

void Pizzerie::afiseazaIngrediente()
{
    ///neimplementat
}

void Pizzerie::afiseazaPizza(string numePizza) {
    for(unsigned int i=0; i<pizze.size(); i++) {
        if(pizze[i]->getDenPizza()==numePizza)
            cout<<*pizze[i];
    }
}

void Pizzerie::afiseazaOferte() {
    for(unsigned int i=0;i<oferte.size();i++){
        cout<<oferte[i];
        cout<<"\nCastigul obtinut la acesta oferta: "<<oferte[i].calculCastig();
    }
}

Pizzerie& Pizzerie::operator=(Pizzerie& obj) {
    if (this != &obj) {
        this->numePizzerie1= obj.numePizzerie1;
        for(unsigned int i=0; i<pizze.size(); i++)
            this->pizze.push_back(obj.pizze[i]);
        for(unsigned int i=0;i<ingrediente.size();i++)
            this->ingrediente.push_back(obj.ingrediente[i]);
        for(unsigned int i=0;i<oferte.size();i++)
            this->oferte.push_back(obj.oferte[i]);
    }
    return *this;
}


///------------------------------MENIU-----------------------------

void menu() {
    int option;///optiunea aleasa din meniu
    option = 0;
    Pizzerie *C = C->getInstance("X");
    do {
        C->menu_output();
        cout << "\nIntroduceti numarul actiunii: ";
        cin >> option;
        if(option == 1) {
            C->citestePizze();
        }
        else if(option == 2) {
            C->citesteOferteSpeciale();
        }
        if(option == 3) {
            C->afiseazaPizze();
        }
        if(option == 4) {
            cout<<"Numele pizzei: ";
            string nume;
            cin.get();
            getline(cin, nume);
            C->afiseazaPizza(nume);
        }
        if(option == 5) {
            C->afiseazaOferte();
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
