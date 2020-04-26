#include <iostream>
#include <fstream>
#include <string>
#include "biblioteca.h"
using namespace std;
ifstream f("date.in");

int main()
{
    string tip, rasp1, rasp2, raspst, nume;
    int ID;
    Biblioteca sistem;
    cin>>sistem;
    cout<<"Vrei sa adaugi o informatie?(DA/NU)";
    cin>>rasp1;
    while(rasp1=="DA"){
        cin>>tip;
        sistem.AdaugareInformatie(tip);
        cout<<"Vrei sa adaugi o alta informatie?(DA/NU)";
        cin>>rasp1;
    }
    cout<<"Vrei sa stergi o informatie?(DA/NU)";
    cin>>rasp2;
    while(rasp2=="DA"){
        cout<<"Dupa ID sau dupa nume?(ID/Nume)";
        cin>>raspst;
        if(raspst=="ID")
        {
            cin>>ID;
            sistem.Stergere_ID(ID, 2);
        }
        else if(raspst=="Nume")
        {
            cin>>nume;
            sistem.Stergere_Nume(nume);
        }
        cout<<"Vrei sa stergi o alta informatie?(DA/NU)";
        cin>>rasp2;
    }
    cout<<sistem.CautaInformatie(Numeric("Info2",3));
    return 0;
}

///Exemplu date de intrare pe care am lucrat:
/*
7
Matematic
Info1
10
2.53
Numeric
Info2
3
Text
Titlu Poezie
Ala bala
Numeric
Info4
1567
Text
Titlu Poezi
de doua ori
Adresa
Info6
USA
pl
New York
Strada da
15
Numeric
Info7
150
*/
