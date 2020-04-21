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
    cout<<nume;
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
    Informatie::citire(in);
    cout<<"\nTextul este: ";
    getline(in, text);
    cout<<text;
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
Text& Text::operator=(const Text &obj) ///supraincarcare a op. =, redundanta
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
    cout<<nr;
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
Numeric& Numeric::operator=(const Numeric& obj) ///supraincarcare a op. =, redundanta
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
    cout<<re;
    cout<<"\nPartea imaginara este: ";
    in>>im;
    cout<<im;
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
Matematic& Matematic::operator=(const Matematic &obj) ///supraincarcare a op. =, redundanta
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
    cout<<tara<<"\nJudetul este: ";
    getline(in, judet);
    cout<<judet<<"\nOrasul este: ";
    getline(in, oras);
    cout<<oras<<"\nStrada este: ";
    getline(in, strada);
    cout<<strada<<"\nNumarul este: ";
    in>>nr_adresa;
    cout<<nr_adresa;
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
Biblioteca::Biblioteca(int n, Informatie** informatie)
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
    Informatie** redim = nullptr;
    redim=new Informatie*[dim];
    for(int i=0;i<min(nr_ord, dim);i++)
    {
        if(this->informatie[i]!=nullptr)
            {
                if(typeid(this->informatie[i])==typeid(Text))
                {
                    redim[i]=new Text(*(Text*)(this->informatie[i])); ///conversie din pointer catre informatie in pointer catre text
                }
                else if(typeid(this->informatie[i])==typeid(Numeric))
                {
                    redim[i]=new Numeric(*(Numeric*)(this->informatie[i]));
                }
                else if(typeid(this->informatie[i])==typeid(Matematic))
                {
                    redim[i]=new Matematic(*(Matematic*)(this->informatie[i]));
                }
                else if(typeid(this->informatie[i])==typeid(Adresa))
                {
                    redim[i]=new Adresa(*(Adresa*)(this->informatie[i]));
                }
                redim[i]->setID(i);
            }
            else this->informatie[i]=nullptr;
    }
    delete[] informatie;
    if(dim<nr_ord)
        this->setNr_ord(dim);
    informatie=redim;
}
void Biblioteca::AdaugareInformatie(string tip)
{
    redimensionare(++nr_ord);
    informatie[nr_ord]->setID(nr_ord+1);
    if(tip=="Text")
    {
        informatie[nr_ord] = new Text;
        informatie[nr_ord]->setID(nr_ord+1);
        cin>>*(informatie[nr_ord]);
        int j = CautaNume(informatie[nr_ord]->getName());
        if(j>-1 && j<nr_ord){
            ((Text*)(informatie[j]))->setText(((Text*)(informatie[j]))->getText() + ((Text*)(informatie[nr_ord]))->getText());
            Stergere_ID(nr_ord+1);
        }
    }
    else if(tip=="Numeric")
    {
        informatie[nr_ord] = new Numeric;
        informatie[nr_ord]->setID(nr_ord+1);
        cin>>*(informatie[nr_ord]);
        int j = CautaNume(informatie[nr_ord]->getName());
        if(j>-1 && j<nr_ord){
            ((Numeric*)(informatie[j]))->setNr(((Numeric*)(informatie[j]))->getNr() + ((Numeric*)(informatie[nr_ord]))->getNr());
            Stergere_ID(nr_ord+1);
        }
    }
    else if(tip=="Matematic")
    {
        informatie[nr_ord]=new Matematic;
        informatie[nr_ord]->setID(nr_ord+1);
        cin>>*(informatie[nr_ord]);
        int j = CautaNume(informatie[nr_ord]->getName());
        if(j>-1 && j<nr_ord){
            ((Matematic*)(informatie[nr_ord]))->setRe(((Matematic*)(informatie[nr_ord]))->getRe() + ((Matematic*)(informatie[nr_ord]))->getRe());
            ((Matematic*)(informatie[nr_ord]))->setIm(((Matematic*)(informatie[nr_ord]))->getIm() + ((Matematic*)(informatie[nr_ord]))->getIm());
            Stergere_ID(nr_ord+1);
        }
    }
    else if(tip=="Adresa")
    {
        informatie[nr_ord]=new Adresa;
        informatie[nr_ord]->setID(nr_ord+1);
        cin>>*(informatie[nr_ord]);
        int j = CautaNume(informatie[nr_ord]->getName());
        if(j>-1 && j<nr_ord){
            cout<<"Adresa exista deja in sistem, nu ne tragem de sireturi aici.";
            Stergere_ID(nr_ord+1);
        }
    }
}
bool Biblioteca::CautaInformatie(const Text& obj)
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
bool Biblioteca::CautaInformatie(const Numeric& obj)
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
bool Biblioteca::CautaInformatie(const Matematic& obj)
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
bool Biblioteca::CautaInformatie(const Adresa& obj)
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
void Biblioteca::Stergere_ID(int ID)
{
    int poz=CautaID(ID);
    if(poz!=-1)
    {
        delete informatie[poz];
        for(int i=poz;i<nr_ord-1;i++)
            informatie[i]=informatie[i+1];
        redimensionare(nr_ord-1);
    }
    else cout<<"Informatia cu ID-ul "<<ID<<" nu se afla in sistem.";
}
void Biblioteca::Stergere_Nume(string nume)
{
    int poz=CautaNume(nume);
    if(poz!=-1)
    {
        delete informatie[poz];
        for(int i=poz;i<nr_ord-1;i++)
            informatie[i]=informatie[i+1];
        redimensionare(nr_ord-1);
    }
    else cout<<"Informatia cu numele "<<nume<<" nu se afla in sistem.";
}
int Biblioteca::CautaID(int ID)
{
    for(int i=0;i<nr_ord;i++)
        if(informatie[i]->getID()==ID)
            return i;
    return -1;
}
int Biblioteca::CautaNume(string Nume)
{
    for(int i=0;i<nr_ord;i++)
        if(informatie[i]->getName()==Nume)
            return i;
    return -1;
}
istream& operator>>(istream& in, Biblioteca& obj)
{
    int n;
    string tip;
    cout<<"Buna ziua! Cate informatii doriti sa retin? "<<'\n';
    in>>n;
    cout<<n;
    obj.nr_ord=n;
    delete[] obj.informatie;
    if(obj.nr_ord==0) obj.informatie=nullptr;
    else
    {
        obj.informatie= new Informatie*[n];
        for(int i=0; i<n; i++)
        {
            cout<<"\nDe ce tip este aceasta informatie? ";
            in>>tip;
            cout<<tip<<'\n';
            in.ignore();
            if(tip=="Text")
            {
                obj.informatie[i]=new Text;
                obj.informatie[i]->setID(i+1);
                in>>*(obj.informatie[i]);
                int j = obj.CautaNume(obj.informatie[i]->getName());
                if(j>-1 && j<i){
                    ((Text*)(obj.informatie[j]))->setText(((Text*)(obj.informatie[j]))->getText() + ((Text*)(obj.informatie[i]))->getText());
                    obj.Stergere_ID(i);
                    --i;
                    --n;
                }
            }
            else if(tip=="Numeric")
            {
                obj.informatie[i]=new Numeric;
                obj.informatie[i]->setID(i+1);
                in>>*(obj.informatie[i]);
                int j = obj.CautaNume(obj.informatie[i]->getName());
                if(j>-1 && j<i){
                    ((Numeric*)(obj.informatie[j]))->setNr(((Numeric*)(obj.informatie[j]))->getNr() + ((Numeric*)(obj.informatie[i]))->getNr());
                    obj.Stergere_ID(i);
                    --i;
                    --n;
                }
            }
            else if(tip=="Matematic")
            {
                obj.informatie[i]=new Matematic;
                obj.informatie[i]->setID(i+1);
                in>>*(obj.informatie[i]);
                int j = obj.CautaNume(obj.informatie[i]->getName());
                if(j>-1 && j<i){
                    ((Matematic*)(obj.informatie[i]))->setRe(((Matematic*)(obj.informatie[j]))->getRe() + ((Matematic*)(obj.informatie[i]))->getRe());
                    ((Matematic*)(obj.informatie[i]))->setIm(((Matematic*)(obj.informatie[j]))->getIm() + ((Matematic*)(obj.informatie[i]))->getIm());
                    obj.Stergere_ID(i);
                    --i;
                    --n;
                }
            }
            else if(tip=="Adresa")
            {
                obj.informatie[i]=new Adresa;
                obj.informatie[i]->setID(i+1);
                in>>*(obj.informatie[i]);
                int j = obj.CautaNume(obj.informatie[i]->getName());
                if(j>-1 && j<i){
                    cout<<"Adresa exista deja in sistem, nu ne tragem de sireturi aici.";
                    obj.Stergere_ID(i);
                    --i;
                    --n;
                }
            }
        }
    }
    cout<<'\n';
    return in;
}
ostream& operator<<(ostream& out, const Biblioteca& obj)
{
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
    return *this;
}
