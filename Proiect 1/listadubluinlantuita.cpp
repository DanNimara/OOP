#include "listadubluinlantuita.h"

using namespace std;

Nod::Nod() ///constructor pt clasa nod fara parametrii
{
    info=0;
    prev=nullptr;
    next=nullptr;
}
Nod::Nod(int info, Nod* prev, Nod* next) ///constructor cu parametrii
{
    this->info=info;
    this->prev=prev;
    this->next=next;
    prev->next=this;
    next->prev=this;
}
Nod::~Nod() ///destructor
{
    info=0;
    if(prev!=nullptr)
    {
        if(next!=nullptr)
        {
            prev->next=next;
            next->prev=prev;
        }
        else
        {
            prev->next=nullptr;
        }
    }
    else
    {
        if(next!=nullptr)
        {
            next->prev=nullptr;
        }
    }
    prev=nullptr;
    next=nullptr;
}
istream& operator>>(istream& in, Nod& obj) ///supraincarcare a operatorului >> pt clasa Nod, desi nu era necesar
{
    in>>obj.info;
    return in;
}
ostream& operator<<(ostream& out, const Nod& obj) ///la fel ca mai sus pentru <<
{
    out<<obj.info;
    return out;
}
Lista_dublu_inlantuita::Lista_dublu_inlantuita() ///constructor fara parametrii pentru clasa Lista_dublu_inlantuita
{
    prim=nullptr;
    ultim=nullptr;
}
Lista_dublu_inlantuita::~Lista_dublu_inlantuita() ///destructor pentru clasa Lista_dublu_inlantuita
{
	Nod *curr=prim;
	while(curr!=nullptr)
	{
		Nod* aux=curr;
		curr=curr->next;
		aux->next=nullptr;
		delete aux;
		prim=curr;
	}
	prim=nullptr;
	ultim=nullptr;
}
Nod* Lista_dublu_inlantuita::GetPrim()
{
    return prim;
}
Nod* Nod::GetNext()
{
    return next;
}
int Nod::GetInfo()
{
    return info;
}
void Lista_dublu_inlantuita::inserare(int info) ///metoda de inserare a unui element intr-o lista(la final)
{
    Nod* nodnou=new Nod;
    nodnou->info=info;
    nodnou->prev=nullptr;
    nodnou->next=nullptr;
    if(prim==nullptr)
    {
        prim=nodnou;
        ultim=nodnou;
        return;
    }
    nodnou->prev=ultim;
    ultim->next=nodnou;
    ultim=nodnou;
    return;
}
void Lista_dublu_inlantuita::stergere(int poz) ///metoda de stergere a unui element de pe o anumita pozitie dintr-o lista db. inl.
{
    Nod* sters;
    if(poz==1){ ///se sterge elementul de pe prima pozitie
        sters=prim;
        prim=prim->next;
        delete sters;
        return;
    }
    Nod* curr=prim->next;
    int k=2;
    while(curr!=nullptr){
        if(poz==k&&curr->next!=nullptr){ ///se sterge elementul din interiorul listei
            sters=curr;
            curr->next->prev=curr->prev;
            curr->prev->next=curr->next;
            delete sters;
            return;
        }
        else if(poz==k&&curr->next==nullptr){ ///se sterge elementul de la capatul listei
                sters=curr;
                curr->prev->next=nullptr;
                delete sters;
                return;
        }
        k++;
        curr=curr->next;
    }
    return;
}
istream& operator>>(istream& in, Lista_dublu_inlantuita& obj) ///supraincarcare a operatorului citire pt un obiect de tip l_db_inl
{
    int n, val;
    cout<<"Cate elemente are lista? ";
    in>>n;
    cout<<"Enumerati valorile din lista: ";
    for (int i=0; i<n; i++)
    {
        in>>val;
        obj.inserare(val);
    }
    return in;
}
ostream& operator<<(ostream& out, const Lista_dublu_inlantuita& obj) ///supraincarcare a operatorului afisare pt un obiect de tip l_db_inl
{
    Nod* curr=obj.prim;
    out<<"Lista afisata in sens normal este: ";
    while(curr!=nullptr)
    {
        out<<*curr<<' '; ///afiseaza direct valoarea din curr, fiind pointer
        curr = curr->next;
    }
    out<<'\n';
    out<<"Lista afisata in sens invers este: ";
    curr=obj.ultim;
    while(curr!=nullptr)
    {
        out<<*curr<<' ';
        curr = curr->prev;
    }
    return out;
}
Lista_dublu_inlantuita Lista_dublu_inlantuita::operator=(const Lista_dublu_inlantuita &obj) ///supraincarcare a op. =
{
    if (&obj == this) {
        return *this;
    }
    if (prim!=nullptr) {
        Nod *curr=prim;
        while(curr!=nullptr)
        {
            Nod* aux=curr;
            curr=curr->next;
            aux->next=nullptr;
            delete aux;
            prim=curr;
        }
        prim=nullptr;
        ultim=nullptr;
    }
    Nod *curr = obj.prim;
    while (curr!=nullptr) {
        inserare(curr->info);
        curr=curr->next;
    }
    return *this;
}
Lista_dublu_inlantuita Lista_dublu_inlantuita::operator+(Lista_dublu_inlantuita& obj2) /// returneaza o noua lista, obtinuta prin concatenarea listelor primite ca parametrii(primul fiind implicit)
{
    Lista_dublu_inlantuita rez;
    Nod* curr=prim;
    while(curr!=nullptr){
        rez.inserare(curr->info);
        curr=curr->next;
    }
    curr=obj2.prim;
    while(curr!=nullptr){
        rez.inserare(curr->info);
        curr=curr->next;
    }
    return rez;
}
