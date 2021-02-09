//Proiect 1 - Tema 7

#ifndef LISTADUBLUINLANTUITA_H
#define LISTADUBLUINLANTUITA_H ///include guard
#include <iostream>

using namespace std;
class Nod;
class Lista_dublu_inlantuita;
class Nod
{
    int info;
    Nod* prev, *next;
    friend class Lista_dublu_inlantuita;
public:
    Nod();
    Nod(int info, Nod* prev, Nod* next);
    ~Nod();
    Nod* GetNext();
    int GetInfo();
    friend Nod* GetPrim();
    friend istream& operator>>(istream& in, Nod& obj);
    friend ostream& operator<<(ostream& out, const Nod& obj);
    friend istream& operator>>(istream& in, Lista_dublu_inlantuita& obj); ///prietenia nu e tranzitiva
    friend ostream& operator<<(ostream& out, const Lista_dublu_inlantuita& obj);
    friend Lista_dublu_inlantuita operator+(Lista_dublu_inlantuita& obj2);
};
class Lista_dublu_inlantuita
{
    Nod* prim, *ultim;
public:
    Nod* GetPrim();
    Lista_dublu_inlantuita();
    ~Lista_dublu_inlantuita();
    void inserare(int info);
    void stergere(int poz);
    Lista_dublu_inlantuita operator=(const Lista_dublu_inlantuita &obj);
    friend istream& operator>>(istream& in, Lista_dublu_inlantuita& obj);
    friend ostream& operator<<(ostream& out, const Lista_dublu_inlantuita& obj); ///const=>nu se poate modifica(altfel crapa)
    // friend Lista_dublu_inlantuita operator+(const Lista_dublu_inlantuita& a, const Lista_dublu_inlantuita& b);
    Lista_dublu_inlantuita operator+(Lista_dublu_inlantuita& obj2);
};

#endif // LISTADUBLUINLANTUITA_H
