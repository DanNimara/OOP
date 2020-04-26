#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <string>
using namespace std;

class Informatie
{
    protected:
    int id;
    string nume;
    public:
        Informatie();
        Informatie(string nume);
        Informatie(const Informatie& obj);
        virtual ~Informatie();
        virtual void afisare(ostream&) const;
        virtual void citire(istream&);
        int getID();
        string getName();
        void setID(int id);
        void setName(string nume);
        friend istream& operator>>(istream& in, Informatie& obj);
        friend ostream& operator<<(ostream& out, const Informatie& obj);
};


class Text: public Informatie
{
    string text;
    public:
        Text();
        Text(string nume, string text);
        Text(const Text& obj);
        ~Text();
        string getText();
        void setText(string text);
        void citire(istream&);
        void afisare(ostream&) const;
        bool operator==(const Text& obj);
        friend istream& operator>>(istream& in, Text& obj);
        friend ostream& operator<<(ostream& out, const Text& obj);
        Text& operator=(const Text &obj);
        void afisare();
};


class Numeric: public Informatie
{
    int nr;
    public:
        Numeric();
        Numeric(string nume, int nr);
        Numeric(const Numeric& obj);
        ~Numeric();
        int getNr();
        void setNr(int nr);
        void citire(istream&);
        void afisare(ostream&) const;
        bool operator==(const Numeric& obj);
        friend istream& operator>>(istream& in, Numeric& obj);
        friend ostream& operator<<(ostream& out, const Numeric& obj);
        Numeric& operator=(const Numeric &obj);
        void afisare();
};


class Matematic: public Informatie
{
    double re, im;
    public:
        Matematic();
        Matematic(string nume, double re, double im);
        Matematic(const Matematic& obj);
        ~Matematic();
        double getRe();
        void setRe(double re);
        double getIm();
        void setIm(double im);
        void citire(istream&);
        void afisare(ostream&) const;
        bool operator==(const Matematic& obj);
        friend istream& operator>>(istream& in, Matematic& obj);
        friend ostream& operator<<(ostream& out, const Matematic& obj);
        Matematic& operator=(const Matematic &obj);
        void afisare();
};


class Adresa: public Informatie
{
    string tara, judet, oras, strada;
    int nr_adresa;
    public:
        Adresa();
        Adresa(string nume, string tara, string judet, string oras, string strada, int nr_adresa);
        Adresa(const Adresa& obj);
        ~Adresa();
        string getTara();
        void setTara(string tara);
        string getJudet();
        void setJudet(string judet);
        string getOras();
        void setOras(string oras);
        string getStrada();
        void setStrada(string strada);
        int getNr_adresa();
        void setNr_adresa(int nr_adresa);
        void citire(istream&);
        void afisare(ostream&) const;
        bool operator==(const Adresa& obj);
        friend istream& operator>>(istream& in, Adresa& obj);
        friend ostream& operator<<(ostream& out, const Adresa& obj);
        Adresa& operator=(const Adresa &obj);
        void afisare();
};


class Biblioteca{
    Informatie** informatie = nullptr;
    int nr_ord;
    public:
        Biblioteca();
        Biblioteca(int n, Informatie** informatie);
        Biblioteca(const Biblioteca& obj);
        ~Biblioteca();
        int getNr_ord();
        void setNr_ord(int nr_ord);
        void redimensionare(int dim);
        void AdaugareInformatie(string tip);
        bool CautaInformatie(const Text& obj);
        bool CautaInformatie(const Numeric& obj);
        bool CautaInformatie(const Matematic& obj);
        bool CautaInformatie(const Adresa& obj);
        void Stergere_ID(int ID, int apel);
        void Stergere_Nume(string nume);
        int CautaID(int ID);
        int CautaNume(string Nume);
        friend istream& operator>>(istream& in, Biblioteca& obj);
        friend ostream& operator<<(ostream& out, const Biblioteca& obj);
        Biblioteca& operator=(const Biblioteca &obj);
};
#endif // BIBLIOTECA_H
