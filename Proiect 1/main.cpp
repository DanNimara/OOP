#include <iostream>
#include "listadubluinlantuita.h"

using namespace std;
int i, n, val, nre, j;
Lista_dublu_inlantuita lista[1001];
int main()
{
    ///citire a n liste
    cout<<"Numar de liste dublu inlantuite: ";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"Numar de elemente al listei curente: ";
        cin>>nre;
        cout<<"Elementele listei sunt: ";
        for(j=0;j<nre;j++){
            cin>>val;
            lista[i].inserare(val);
        }
    }
    ///afisarea celor n liste
    for(i=0;i<n;i++){
        Nod* curr=lista[i].GetPrim();
        while(curr!=nullptr){
            cout<<curr->GetInfo()<<" ";
            curr=curr->GetNext();
        }
        cout<<'\n';
    }
    /// exemplu pentru supraincarcarea operatorului +
    Lista_dublu_inlantuita L=lista[0]+lista[1];
    Nod* curr=L.GetPrim();
    while(curr!=nullptr){
        cout<<curr->GetInfo()<<" ";
        curr=curr->GetNext();
    }
    Lista_dublu_inlantuita lista_ex;
    cin>>lista_ex; /// citire a listei prin supraincarcarea operatorului >> (cerinta comuna obligatorie)
    cout<<lista_ex; /// afisare a listei prin supraincarcarea operatorului << (cerinta comuna obligatorie)
    return 0;
}
