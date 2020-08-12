#include "archivos.h"
#include <string>
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

Archivos::Archivos(string autom_, string hora_, string tipo_, string celda_, string piso_, string placa_)
{
    autom=autom_;
    hora=hora_;
    tipo=tipo_;
    celda=celda_;
    placa=placa_;
    nivel=piso_;

    time_t rawTime;
       tm *TimeInfo;
       char Buffer[80];

       time(&rawTime);
       TimeInfo = localtime(&rawTime);

       // I = 12H format   H = 24H format %H:%M:%S Con segundos
       strftime(Buffer, sizeof(Buffer), "%H:%M %d-%m-%Y", TimeInfo);
       std::string Str(Buffer);
        hora=Str;

}


void Archivos::escribir()
{
    //ESTACIONAMIENTO.open("ESTACIONAMIENTO.txt");



    // PARQUEADERO[PLACA]=DATOS;

      string add;

     add+=nivel;
     add+=" ";
     add+=celda;
     add+=" ";
     add+=placa;
     add+=" ";
     add+=hora;
     add+=" ";
     add+=autom;
     add+=tipo;
     ofstream registro("registro.txt",ios::app);
     registro<<add<<endl;
     registro.close();
     ofstream historial("historial.txt",ios::app);
     historial<<add<<endl;
     historial.close();

}

void Archivos::leer()
{

    fileread.open("registro.txt" );
    char cadena1[15];

     fileread.seekg(0);
    int i=0;
    while (fileread.good())
    {
        char temp= fileread.get();
        //sacando caracter por caracter
        if (fileread.good())
        {
            cadena1[i]=temp;


        i++;
        }
        cout<<cadena1<<endl;
    }

}
