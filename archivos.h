#ifndef ARCHIVOS_H
#define ARCHIVOS_H
using namespace std;
#include <iostream>
#include <fstream>
#include <string.h>
#include <map>
#include <list>
#include <stdio.h>
#include <time.h>
#include <string>
#include <ctime>
using namespace std;
class Archivos
{
    string autom;
    string hora;
    string tipo;
    string celda;
    string piso;
    string placa;
    string nivel;
    ifstream fileread;
    ofstream filewrite;
public:
    Archivos(  string autom, string hora, string tipo, string celda , string piso , string placa);
    void escribir();
    void leer();

};

#endif // ARCHIVOS_H
