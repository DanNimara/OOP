#include <iostream>
#include <fstream>
#include <string>
#include "biblioteca.h"
using namespace std;
ifstream f("date.in");

int main()
{
    Biblioteca cumva;
    f>>cumva;
    cout<<cumva<<'\n';
    cout<<cumva.CautaInformatie(Numeric("leila",3));
    return 0;
}
