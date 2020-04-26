#include "biblioteca.h"
#include <typeinfo>
///--------------------------clasa INFORMATIE------------------------------
Informatie::Informatie()
{
    nume="";
}
Informatie::Informatie(string nume)
{
    this->nume=nume;
}
Informatie::Informatie(const Informatie& obj)
{
    id=obj.id;
    nume=obj.nume;
}
Informatie::~Informatie()
{
    id=0;
    nume="";
}
int Informatie::getID()
{
    return id;
}
string Informatie::getName()
{
    return nume;
}
void Informatie::setID(int id)
{
    this->id=id;
}
void Informatie::setName(string nume)
{
    this->nume=nume;
}
void Informatie::citire(istream& in)
{
    cout<<"Numele informatiei este: ";
    getline(in, nume);
}
void Informatie::afisare(ostream& out) const
{
    out<<"ID-ul este: "<<id<<'\n';
    out<<"Numele este: "<<nume;
}
istream& operator>>(istream& in, Informatie& obj) ///supraincarcare a operatorului >> pt clasa Text
{
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Informatie& obj) ///la fel ca mai sus pentru <<
{
    obj.afisare(out);
    return out;
}



///------------------------------------clasa TEXT -----------------------------------
Text::Text()
{
    text="";
}
Text::Text(string nume, string text): Informatie(nume), text(text) {}
Text::Text(const Text &obj)
{
    id=obj.id;
    nume=obj.nume;
    text=obj.text;
}
Text::~Text()
{
    text="";
}
string Text::getText()
{
    return text;
}
void Text::setText(string text)
{
    this->text=text;
}
void Text::citire(istream& in)
{
    Informatie::citire(in); ///apelez citirea pentru nume din informatie
    cout<<"\nTextul este: ";
    getline(in, text);
}
void Text::afisare(ostream& out) const
{
    Informatie::afisare(out);
    out<<'\n'<<"Textul este: "<<text;
}
istream& operator>>(istream& in, Text& obj) ///supraincarcare a operatorului >> pt clasa Text
{
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Text& obj) ///la fel ca mai sus pentru <<
{
    obj.afisare(out);
    return out;
}
Text& Text::operator=(const Text &obj) ///supraincarcare a op. =
{
    if (&obj == this)
    {
        return *this;
    }
    id=obj.id;
    nume=obj.nume;
    text=obj.text;
    return *this;
}
bool Text::operator==(const Text& obj)
{
    return text==obj.text;
}
///------------------------------------clasa NUMERIC -----------------------------------
Numeric::Numeric()
{
    nr=0;
}
Numeric::Numeric(string nume, int nr): Informatie(nume), nr(nr) {}

Numeric::Numeric(const Numeric& obj)
{
    id=obj.id;
    nume=obj.nume;
    nr=obj.nr;
}
Numeric::~Numeric()
{
    nr=0;
}
int Numeric::getNr()
{
    return nr;
}
void Numeric::setNr(int nr)
{
    this->nr=nr;
}
void Numeric::citire(istream& in)
{
    Informatie::citire(in);
    cout<<"\nNumarul este: ";
    in>>nr;
}
void Numeric::afisare(ostream& out) const
{
    Informatie::afisare(out);
    out<<'\n'<<"Numarul este: "<<nr;
}
istream& operator>>(istream& in, Numeric& obj) ///supraincarcare a operatorului >> pt clasa Text
{
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Numeric& obj) ///la fel ca mai sus pentru <<
{
    obj.afisare(out);
    return out;
}
Numeric& Numeric::operator=(const Numeric& obj) ///supraincarcare a op. =
{
    if (&obj == this)
    {
        return *this;
    }
    id=obj.id;
    nume=obj.nume;
    nr=obj.nr;
    return *this;
}
bool Numeric::operator==(const Numeric& obj)
{
    return nr==obj.nr;
}
///------------------------------------clasa MATEMATIC -----------------------------------
Matematic::Matematic()
{
    re=0;
    im=0;
}
Matematic::Matematic(string nume, double re, double im): Informatie(nume), re(re), im(im) {}
Matematic::Matematic(const Matematic& obj)
{
    id=obj.id;
    nume=obj.nume;
    re=obj.re;
    im=obj.im;
}
Matematic::~Matematic()
{
    re=0;
    im=0;
}
double Matematic::getRe()
{
    return re;
}
void Matematic::setRe(double re)
{
    this->re=re;
}
double Matematic::getIm()
{
    return im;
}
void Matematic::setIm(double im)
{
    this->im=im;
}
void Matematic::citire(istream& in)
{
    Informatie::citire(in);
    cout<<"\nPartea reala este: ";
    in>>re;
    cout<<"\nPartea imaginara este: ";
    in>>im;
}
void Matematic::afisare(ostream& out) const
{
    Informatie::afisare(out);
    out<<'\n'<<"Partea reala este: "<<re;
    out<<'\n'<<"Partea imaginara este: "<<im;
}
istream& operator>>(istream& in, Matematic& obj) ///supraincarcare a operatorului >> pt clasa Text
{
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Matematic& obj) ///la fel ca mai sus pentru <<
{
    obj.afisare(out);
    return out;
}
Matematic& Matematic::operator=(const Matematic &obj) ///supraincarcare a op. =
{
    if (&obj == this)
    {
        return *this;
    }
    id=obj.id;
    nume=obj.nume;
    re=obj.re;
    im=obj.im;
    return *this;
}
bool Matematic::operator==(const Matematic& obj)
{
    return re==obj.re&&im==obj.im;
}
///------------------------------------clasa ADRESA -----------------------------------
Adresa::Adresa()
{
    tara="";
    judet="";
    oras="";
    strada="";
    nr_adresa=0;
}
Adresa::Adresa(string nume, string tara, string judet, string oras, string strada, int nr_adresa): Informatie(nume),
    tara(tara), judet(judet), oras(oras), strada(strada), nr_adresa(nr_adresa) {}
Adresa::Adresa(const Adresa &obj)
{
    id=obj.id;
    nume=obj.nume;
    tara=obj.tara;
    judet=obj.judet;
    oras=obj.oras;
    strada=obj.strada;
    nr_adresa=obj.nr_adresa;
}
Adresa::~Adresa()
{
    tara="";
    judet="";
    oras="";
    strada="";
    nr_adresa=0;
}
string Adresa::getTara()
{
    return tara;
}
void Adresa::setTara(string tara)
{
    this->tara=tara;
}
string Adresa::getJudet()
{
    return judet;
}
void Adresa::setJudet(string judet)
{
    this->judet=judet;
}
string Adresa::getOras()
{
    return oras;
}
void Adresa::setOras(string oras)
{
    this->oras=oras;
}
string Adresa::getStrada()
{
    return strada;
}
void Adresa::setStrada(string strada)
{
    this->strada=strada;
}
int Adresa::getNr_adresa()
{
    return nr_adresa;
}
void Adresa::setNr_adresa(int nr_adresa)
{
    this->nr_adresa=nr_adresa;
}
void Adresa::citire(istream& in)
{
    Informatie::citire(in);
    cout<<"\nTara este: ";
    getline(in, tara);
    cout<<"\nJudetul este: ";
    getline(in, judet);
    cout<<"\nOrasul este: ";
    getline(in, oras);
    cout<<"\nStrada este: ";
    getline(in, strada);
    cout<<"\nNumarul este: ";
    in>>nr_adresa;
}
void Adresa::afisare(ostream& out) const
{
    Informatie::afisare(out);
    out<<'\n'<<"Tara este: "<<tara;
    out<<'\n'<<"Judetul este: "<<judet;
    out<<'\n'<<"Orasul este: "<<oras;
    out<<'\n'<<"Strada este: "<<strada;
    out<<'\n'<<"Numarul este: "<<nr_adresa;
}
istream& operator>>(istream& in, Adresa& obj) ///supraincarcare a operatorului >> pt clasa Adresa
{
    obj.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Adresa& obj) ///la fel ca mai sus pentru <<
{
    obj.afisare(out);
    return out;
}
Adresa& Adresa::operator=(const Adresa& obj) ///supraincarcare a op. =, redundanta
{
    if (&obj == this)
    {
        return *this;
    }
    id=obj.id;
    nume=obj.nume;
    tara=obj.tara;
    judet=obj.judet;
    oras=obj.oras;
    strada=obj.strada;
    nr_adresa=obj.nr_adresa;
    return *this;
}
bool Adresa::operator==(const Adresa& obj)
{
    return tara==obj.tara&&judet==obj.judet&&oras==obj.oras&&strada==obj.strada&&nr_adresa==obj.nr_adresa;
}
///------------------------------------clasa BIBLIOTECA --------------------------------


Biblioteca::Biblioteca()
{
    nr_ord=0;
    informatie=nullptr;
}
Biblioteca::Biblioteca(int n, Informatie** informatie) ///nu utilizez acest constructor, doar pentru completitudine
{
    nr_ord=n;
    if(n==0)
        informatie=nullptr;
    else
    {
        this->informatie=new Informatie*[n];
        for(int i=0; i<n; i++)
        {
            if(informatie[i]!=nullptr)
            {
                if(typeid(*informatie[i])==typeid(Text))
                {
                    this->informatie[i]=new Text(*(Text*)(informatie[i])); ///conversie din pointer catre informatie in pointer catre text
                }
                else if(typeid(*informatie[i])==typeid(Numeric))
                {
                    this->informatie[i]=new Numeric(*(Numeric*)(informatie[i]));
                }
                else if(typeid(*informatie[i])==typeid(Matematic))
                {
                    this->informatie[i]=new Matematic(*(Matematic*)(informatie[i]));
                }
                else if(typeid(*informatie[i])==typeid(Adresa))
                {
                    this->informatie[i]=new Adresa(*(Adresa*)(informatie[i]));
                }
                this->informatie[i]->setID(i);
            }
            else this->informatie[i]=nullptr;
        }
    }
}
Biblioteca::Biblioteca(const Biblioteca& obj)
{
    this->nr_ord=obj.nr_ord;
    delete[] this->informatie;
    if(nr_ord==0)
    {
        this->informatie=nullptr;
    }
    else
    {
        this->informatie=new Informatie*[nr_ord];
        for(int i=0; i<nr_ord; i++)
        {
            if(obj.informatie[i]!=nullptr)
            {
                if(typeid(*obj.informatie[i])==typeid(Text))
                {
                    this->informatie[i]=new Text(*(Text*)(obj.informatie[i])); ///conversie din pointer catre informatie in pointer catre text
                }
                else if(typeid(*obj.informatie[i])==typeid(Numeric))
                {
                    this->informatie[i]=new Numeric(*(Numeric*)(obj.informatie[i]));
                }
                else if(typeid(*obj.informatie[i])==typeid(Matematic))
                {
                    this->informatie[i]=new Matematic(*(Matematic*)(obj.informatie[i]));
                }
                else if(typeid(*obj.informatie[i])==typeid(Adresa))
                {
                    this->informatie[i]=new Adresa(*(Adresa*)(obj.informatie[i]));
                }
                this->informatie[i]->setID(i);
            }
            else this->informatie[i]=nullptr;
        }
    }
}
Biblioteca::~Biblioteca()
{
    for(int i=0; i<nr_ord; i++)
        delete informatie[i];
    delete[] informatie;
    nr_ord=0;
}
int Biblioteca::getNr_ord()
{
    return nr_ord;
}
void Biblioteca::setNr_ord(int nr_ord)
{
    this->nr_ord=nr_ord;
}
void Biblioteca::redimensionare(int dim)
{
    Informatie** redim = new Informatie*[dim]; ///aloc memoria necesara pentru vectorul de noua dimensiune
    for(int i=0; i<min(nr_ord, dim); i++) ///copiez informatia in noul vector
    {
        if(this->informatie[i]!=nullptr)
        {
            if(typeid(*informatie[i])==typeid(Text))
            {
                redim[i]=new Text(*(Text*)(this->informatie[i])); ///conversie din pointer catre informatie in pointer catre text
            }
            else if(typeid(*informatie[i])==typeid(Numeric))
            {
                redim[i]=new Numeric(*(Numeric*)(this->informatie[i]));
            }
            else if(typeid(*informatie[i])==typeid(Matematic))
            {
                redim[i]=new Matematic(*(Matematic*)(this->informatie[i]));
            }
            else if(typeid(*informatie[i])==typeid(Adresa))
            {
                redim[i]=new Adresa(*(Adresa*)(this->informatie[i]));
            }
        }
        else break;
    }
    if(dim>nr_ord)          ///daca adaug informatii, dezaloc memoria vechiului vector
    {
        delete[] informatie;
    }
    if(dim<nr_ord)              ///daca sterg o informatie, dezaloc memoria doar pentru ultimul element, datorita shiftarii
    {
        delete informatie[nr_ord-1];
    }
    informatie=redim;
    nr_ord=dim;
}
void Biblioteca::AdaugareInformatie(string tip)
{
    ///M-am gandit ca adaugarea de informatii sa o fac pentru cate o informatie(pentru mai multe intervenea doar un for si alocarea de mai multa memorie odata)
    ///Altfel se putea citii initial un numar indeajuns de mare de informatii
    redimensionare(nr_ord+1); ///aloc spatiu pentru o noua informatie
    int idnou=informatie[nr_ord-2]->getID()+1; ///Ma asigur ca ID-ul informatiei nu se regaseste in cele anterioare
    ///dandu-i ID-ul informatiei anterioare+1
    if(tip=="Text")
    {
        informatie[nr_ord-1] = new Text;
        informatie[nr_ord-1]->setID(idnou);
        cin>>*(informatie[nr_ord-1]);
        int j = CautaNume(informatie[nr_ord-1]->getName());
        if(j>-1 && j<nr_ord-1)  ///In cazul in care informatia cu numele respectiv se gaseste deja in biblioteca
        {
            ///concatenez noul text la cel vechi
            ((Text*)(informatie[j]))->setText(((Text*)(informatie[j]))->getText() + ((Text*)(informatie[nr_ord-1]))->getText());
            Stergere_ID(idnou, 1);  ///dezaloc memoria pentru elementul citit
        }
    }
    else if(tip=="Numeric")
    {
        informatie[nr_ord-1] = new Numeric;
        informatie[nr_ord-1]->setID(idnou);
        cin>>*(informatie[nr_ord-1]);
        int j = CautaNume(informatie[nr_ord-1]->getName());
        if(j>-1 && j<nr_ord-1)
        {
            ///Adun numarul nou la cel vechi
            ((Numeric*)(informatie[j]))->setNr(((Numeric*)(informatie[j]))->getNr() + ((Numeric*)(informatie[nr_ord-1]))->getNr());
            Stergere_ID(idnou, 1);
        }
    }
    else if(tip=="Matematic")
    {
        informatie[nr_ord-1]=new Matematic;
        informatie[nr_ord-1]->setID(idnou);
        cin>>*(informatie[nr_ord-1]);
        int j = CautaNume(informatie[nr_ord-1]->getName());
        if(j>-1 && j<nr_ord-1)
        {
            ///Adun partea reala la cea veche, la fel si cu partea imaginara
            ((Matematic*)(informatie[j]))->setRe(((Matematic*)(informatie[j]))->getRe() + ((Matematic*)(informatie[nr_ord-1]))->getRe());
            ((Matematic*)(informatie[j]))->setIm(((Matematic*)(informatie[j]))->getIm() + ((Matematic*)(informatie[nr_ord-1]))->getIm());
            Stergere_ID(idnou, 1);
        }
    }
    else if(tip=="Adresa")
    {
        informatie[nr_ord-1]=new Adresa;
        informatie[nr_ord-1]->setID(idnou);
        cin>>*(informatie[nr_ord-1]);
        int j = CautaNume(informatie[nr_ord-1]->getName());
        if(j>-1 && j<nr_ord-1)
        {
            ///Eroare, afisez mesaj
            cout<<"Adresa exista deja in sistem, nu ne tragem de sireturi aici.\n";
            Stergere_ID(idnou, 1);
        }
    }
}
bool Biblioteca::CautaInformatie(const Text& obj) ///Cautare informatie de tip Text
{
    for(int i=0; i<nr_ord; i++)
    {
        if(typeid(*informatie[i])==typeid(Text))
        {
            if(*(Text*)(informatie[i])==obj)
                return true;
        }
    }
    return false;
}
bool Biblioteca::CautaInformatie(const Numeric& obj)    ///Cautare informatie de tip Numeric
{
    for(int i=0; i<nr_ord; i++)
    {
        if(typeid(*informatie[i])==typeid(Numeric))
        {
            if(*(Numeric*)(informatie[i])==obj)
                return true;
        }
    }
    return false;
}
bool Biblioteca::CautaInformatie(const Matematic& obj)  ///Cautare informatie de tip Matematic
{
    for(int i=0; i<nr_ord; i++)
    {
        if(typeid(*informatie[i])==typeid(Matematic))
        {
            if(*(Matematic*)(informatie[i])==obj)
                return true;
        }
    }
    return false;
}
bool Biblioteca::CautaInformatie(const Adresa& obj)     ///Cautare informatie de tip Adresa
{
    for(int i=0; i<nr_ord; i++)
    {
        if(typeid(*informatie[i])==typeid(Adresa))
        {
            if(*(Adresa*)(informatie[i])==obj)
                return true;
        }
    }
    return false;
}
void Biblioteca::Stergere_ID(int ID, int apel)
{
    int poz=CautaID(ID);        ///Caut pozitia din vector la care se gaseste ID-ul
    if(poz!=-1)         ///Daca ID-ul se gaseste, o sterg
    {
        if(apel==1)
            informatie[poz]=nullptr;    ///Apel 1 daca sterg sigur de la final (in cazul adaugarii de informatii), nu mai are loc shiftarea
        else
        {
            for(int i=poz; i<nr_ord-1; i++) ///fac shiftarea
            {
                informatie[i]=nullptr;
                if(typeid(*informatie[i+1])==typeid(Text))
                {
                    this->informatie[i]=new Text(*(Text*)(informatie[i+1]));
                }
                else if(typeid(*informatie[i+1])==typeid(Numeric))
                {
                    this->informatie[i]=new Numeric(*(Numeric*)(informatie[i+1]));
                }
                else if(typeid(*informatie[i+1])==typeid(Matematic))
                {
                    this->informatie[i]=new Matematic(*(Matematic*)(informatie[i+1]));
                }
                else if(typeid(*informatie[i+1])==typeid(Adresa))
                {
                    this->informatie[i]=new Adresa(*(Adresa*)(informatie[i+1]));
                }
                this->informatie[i]=this->informatie[i+1];
            }
        }
        redimensionare(nr_ord-1);     ///Dezaloc memoria pentru un element(l-am sters)
    }
    else cout<<"Informatia cu ID-ul "<<ID<<" nu se afla in sistem.";
}
void Biblioteca::Stergere_Nume(string nume)   ///Principiul e la fel ca la metoda Stergere_ID
{
    int poz=CautaNume(nume);
    if(poz!=-1)
    {
        for(int i=poz; i<nr_ord-1; i++)
        {
            informatie[i]=nullptr;
            if(typeid(*informatie[i+1])==typeid(Text))
            {
                this->informatie[i]=new Text(*(Text*)(informatie[i+1]));
            }
            else if(typeid(*informatie[i+1])==typeid(Numeric))
            {
                this->informatie[i]=new Numeric(*(Numeric*)(informatie[i+1]));
            }
            else if(typeid(*informatie[i+1])==typeid(Matematic))
            {
                this->informatie[i]=new Matematic(*(Matematic*)(informatie[i+1]));
            }
            else if(typeid(*informatie[i+1])==typeid(Adresa))
            {
                this->informatie[i]=new Adresa(*(Adresa*)(informatie[i+1]));
            }
            this->informatie[i]=this->informatie[i+1];
        }
        redimensionare(nr_ord-1);
    }
    else cout<<"Informatia cu numele "<<nume<<" nu se afla in sistem.";
}
int Biblioteca::CautaID(int ID)
{
    for(int i=0; i<nr_ord; i++)
        if(informatie[i]->getID()==ID)
            return i;
    return -1;
}
int Biblioteca::CautaNume(string Nume)
{
    for(int i=0; i<nr_ord; i++)
        if(informatie[i]->getName()==Nume)
            return i;
    return -1;
}
istream& operator>>(istream& in, Biblioteca& obj)
{
    ///Am considerat ca doar la adaugare de informatii pot fi informatii cu nume care se regasesc deja in biblioteca, caz in care fac lucrurile precizate in enunt
    ///Aceasta reprezinta crearea sistemului bibliotecii
    ///Citesc, memorez n informatii
    int n;
    string tip;
    cout<<"Buna ziua! Cate informatii doriti sa retin? "<<'\n';
    in>>n;
    cout<<n;
    obj.nr_ord=n;
    delete[] obj.informatie;
    if(obj.nr_ord==0) obj.informatie=nullptr;   ///Daca se citeste 0, nu se adauga nicio informatie
    else
    {
        obj.informatie= new Informatie*[n];
        for(int i=0; i<n; i++)
        {
            cout<<"\nDe ce tip este aceasta informatie? ";
            in>>tip;
            cout<<tip<<'\n';
            in.ignore();    ///Nu imi permitea sa citesc mai tarziu numele unei informatii fara aceasta linie
            if(tip=="Text")
            {
                obj.informatie[i]=new Text;
                obj.informatie[i]->setID(i+1);
                in>>*(obj.informatie[i]);
            }
            else if(tip=="Numeric")
            {
                obj.informatie[i]=new Numeric;
                obj.informatie[i]->setID(i+1);
                in>>*(obj.informatie[i]);
            }
            else if(tip=="Matematic")
            {
                obj.informatie[i]=new Matematic;
                obj.informatie[i]->setID(i+1);
                in>>*(obj.informatie[i]);
            }
            else if(tip=="Adresa")
            {
                obj.informatie[i]=new Adresa;
                obj.informatie[i]->setID(i+1);
                in>>*(obj.informatie[i]);
            }
        }
    }
    cout<<'\n';
    return in;
}
ostream& operator<<(ostream& out, const Biblioteca& obj)
{
    ///Afisarea a n informatii
    for(int i=0; i<obj.nr_ord; i++)
    {
        out<<*(obj.informatie[i])<<'\n';
    }
    return out;
}
Biblioteca& Biblioteca::operator=(const Biblioteca& obj)
{
    if(this==&obj)
        return *this;
    this->nr_ord=obj.nr_ord;
    delete[] this->informatie;
    if(obj.nr_ord==0)
    {
        this->informatie=nullptr;
    }
    else
    {
        this->informatie=new Informatie*[nr_ord];
        for(int i=0; i<nr_ord; i++)
        {
            if(obj.informatie[i]!=nullptr)
            {
                if(typeid(*obj.informatie[i])==typeid(Text))
                {
                    this->informatie[i]=new Text(*(Text*)(obj.informatie[i])); ///conversie din pointer catre informatie in pointer catre text
                }
                else if(typeid(*obj.informatie[i])==typeid(Numeric))
                {
                    this->informatie[i]=new Numeric(*(Numeric*)(obj.informatie[i]));
                }
                else if(typeid(*obj.informatie[i])==typeid(Matematic))
                {
                    this->informatie[i]=new Matematic(*(Matematic*)(obj.informatie[i]));
                }
                else if(typeid(*obj.informatie[i])==typeid(Adresa))
                {
                    this->informatie[i]=new Adresa(*(Adresa*)(obj.informatie[i]));
                }
                this->informatie[i]->setID(i);
            }
            else break;
        }
    }
    return *this;
}
