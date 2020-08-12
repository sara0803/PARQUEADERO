#include <iostream>
#include <fstream>
#include <string.h>
#include <map>
#include <list>
#include <stdio.h>
#include <time.h>
#include <string>
#include <archivos.h>

//Se crean variables para manejar las tarifas del parqueadero
int CH=1450,MH=1000,BH=560,CM=135000,MM=85000,BM=38000;
//Se crea un mapa para cada nivel
std::map<string, list<string>>nivel1;
std::map<string, list<string> >nivel2;
std::map<string, list<string> >nivel3;
std::map<string, list<string> >nivel4;
std::map<string, list<string> >nivel5;
//Se crea in iterador de mapa
std::map<string, list<string>>::iterator r;
list<string>::iterator l;

using namespace std;
unsigned long long int valor(string valor);
string metodo1(string copia);
string palabras(string binario);
string decodificar (string binario);
string  enteropalabras(unsigned long long int total);
void convertir (int numero,string &numeroS, string aux);
void actualizar(){//Actualizar el archivo de texto una vez el usuario retira un vehiculo
    string linea="";
    //Eliminamos el archivo de texto actual para escribir uno nuevo
    remove("registro.txt");
    ofstream k("registro.txt",ios::app);
    //Verificamos que cada nivel tenga carros, de lo contrario este sera ingorado
    if(nivel1.size()!=0){
        for(r=nivel1.begin();r!=nivel1.end();r++){
            //Escribimos en el archivo la informacion de un vehiculo
            linea="";
            l=r->second.begin();
            linea="1 "+r->first+" "+*l+" ";
            l++;
            linea=linea+*l+" ";
            l++;
            l++;
            linea=linea+*l+" ";
            l--;
            linea=linea+*l+"\n";
            k<<linea;
        }
    }
    if(nivel2.size()!=0){
        for(r=nivel2.begin();r!=nivel2.end();r++){
            //Escribimos en el archivo la informacion de un vehiculo
            linea="";
            l=r->second.begin();
            linea="2 "+r->first+" "+*l+" ";
            l++;
            linea=linea+*l+" ";
            l++;
            l++;
            linea=linea+*l+" ";
            l--;
            linea=linea+*l+"\n";
            k<<linea;
        }
    }
    if(nivel3.size()!=0){
        for(r=nivel3.begin();r!=nivel3.end();r++){
            //Escribimos en el archivo la informacion de un vehiculo
            linea="";
            l=r->second.begin();
            linea="3 "+r->first+" "+*l+" ";
            l++;
            linea=linea+*l+" ";
            l++;
            l++;
            linea=linea+*l+" ";
            l--;
            linea=linea+*l+"\n";
            k<<linea;
        }
    }
    if(nivel4.size()!=0){
        for(r=nivel4.begin();r!=nivel4.end();r++){
            //Escribimos en el archivo la informacion de un vehiculo
            linea="";
            l=r->second.begin();
            linea="4 "+r->first+" "+*l+" ";
            l++;
            linea=linea+*l+" ";
            l++;
            l++;
            linea=linea+*l+" ";
            l--;
            linea=linea+*l+"\n";
            k<<linea;
        }
    }
    if(nivel5.size()!=0){
        for(r=nivel5.begin();r!=nivel5.end();r++){
            //Escribimos en el archivo la informacion de un vehiculo
            linea="";
            l=r->second.begin();
            linea="5 "+r->first+" "+*l+" ";
            l++;
            linea=linea+*l+" ";
            l++;
            l++;
            linea=linea+*l+" ";
            l--;
            linea=linea+*l+"\n";
            k<<linea;
        }
    }
    k.close();
}
bool pagar(int valor){
    int din[10]={50000,20000,10000,5000,2000,1000,500,200,100,50},cant[10]={},dine=0,num;
    for(int i=0;i<=9;i++){//el usuario ingresa los billetes
        cout<<"Ingrese la cantidad de billetes de "<<din[i]<<" que desea ingresar: ";cin>>num;
        dine=dine+(din[i]*num);
    }
    dine=dine-valor;//resto el dinero ingresado del usuario con el costo del combo
    if (dine>=0){//si el dinero si fue sufiente, hace lo siguiente
        cout<<"Sus vueltos son los siguientes."<<endl;//simula una maquina dispensadora dando vueltos
        for (int i=0;i<=9;i++){
            cant[i]=dine/din[i];
            dine=dine%din[i];
            cout<<din[i]<<": "<<cant[i]<<endl;
        }
        return 0;//retorna false si realizo el pago correctamente
    }
    else{

        return 1;//retorna true si el dinero ingresado no fue suficiente
    }
}
void factura(string hora,string valor){
    //calculamos la hora actual para mostrar la hora en que un vehiculo es retirado del parqueadero
    time_t rawTime;
       tm *TimeInfo;
       char Buffer[80];

       time(&rawTime);
       TimeInfo = localtime(&rawTime);

       // I = 12H format   H = 24H format %H:%M:%S Con segundos
       strftime(Buffer, sizeof(Buffer), "%H:%M %d-%m-%Y", TimeInfo);
       std::string Str(Buffer);
       string horas=Str;
       string horac="";
       //Iteramos para sacar unicamente la hora y no la fecha
       for(int i=0;i<=4;i++)horac=horac+horas[i];
       //Imprimimos en consola el recibo
    cout<<endl<<endl<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"|-----          PARQUEADERO          -----"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"|-----          HORA INGRESO         -----"<<endl;
    cout<<"|-----                               -----"<<endl;
    cout<<"|-----             "<<hora<<"             -----"<<endl;
    cout<<"|-----                               -----"<<endl;
    cout<<"|-----          HORA SALIDA          -----"<<endl;
    cout<<"|-----                               -----"<<endl;
    cout<<"|-----             "<<horac<<"             -----"<<endl;
    cout<<"|-----         VALOR A PAGAR         -----"<<endl;
    cout<<"|-----                               -----"<<endl;
    cout<<"|-----             "<<valor<<"             "<<endl;
    cout<<"|-----                               -----"<<endl;
    cout<<"|-----                               -----"<<endl;
    cout<<"|-----                               -----"<<endl;
    cout<<"|-----          GRACIAS POR          -----"<<endl;
    cout<<"|-----          SU VISITA!           -----"<<endl;
    cout<<"=========================================="<<endl;
    cout<<endl<<endl<<endl;


}
void a_tarifa(){//Esta funcion va a cargar los costos del parqueadero
    string a;
    ifstream k("tarifas.txt");
    //Se verifica que el archivo exista
    if(k.good()){
        while(!k.eof()){
            //Le damos un valor a cada variable
            k>>a;
            CH=stoi(a);
            k>>a;
            MH=stoi(a);
            k>>a;
            BH=stoi(a);
            k>>a;
            CM=stoi(a);
            k>>a;
            MM=stoi(a);
            k>>a;
            BM=stoi(a);
        }
        k.close();
    }
}
void mostrar_registro(string nivel){//Esta funcion va a permitir mostrar los vehiculos de un nivel especifico
    string linea;
    ifstream k("registro.txt");
    //Se verifica que el archivp exista
    if(k.good()){
        while(!k.eof()){
            //Obtenemos en una linea la informacion de un vehiculo
            string celda="",placa="",hora="",tipo="",piso="";
            int n=0;
            getline(k,linea);
            piso=linea[0];
            for(int i=0;linea[i]!='\0';i++){
                //Iteramos para sacar por separado la informacion del vehiculo estacionado
                if(linea[i]==' ')n+=1;
                else if(n==1)celda=celda+linea[i];
                else if(n==2)placa=placa+linea[i];
                else if(n==3)hora=hora+linea[i];
                else if(n==5)tipo=tipo+linea[i];
            }
            //Mostramos el registro del piso seleccionado
            if(nivel==piso){
                cout<<"CELDA:"<<celda<<" PLACA:"<<placa<<" HORA INGRESO:"<<hora<<" TIPO:"<<tipo<<endl;
            }
        }
        k.close();
    }
}
void leer()//Esta funcion nos permite obtener la informacion del archivo de texto
{
    list <string> lista;
    string linea;
    ifstream k("registro.txt");
    //Se verifica que el archivo exista
    if(k.good()){
        while(!k.eof()){
            //Limpiamos la lista para evitar errores
            lista.clear();
            string celda="",placa="",hora="",tipo="",dia="";
            int n=0;
            getline(k,linea);
            for(int i=0;linea[i]!='\0';i++){
                //Iteramos sobre la linea de texto para obtener la informacion de las variables
                if(linea[i]==' ')n+=1;
                else if(n==1)celda=celda+linea[i];
                else if(n==2)placa=placa+linea[i];
                else if(n==3)hora=hora+linea[i];
                else if(n==4)dia=dia+linea[i];
                else if(n==5)tipo=tipo+linea[i];
            }
            //Agregamos a la lista la informacion de cada vehiculo estacionado
            lista.push_back(placa);
            lista.push_back(hora);
            lista.push_back(tipo);
            lista.push_back(dia);

            //Dependiendo del nivel en que se encuentre estacionado agregamos la lista al mapa correspondiente
            if(linea[0]=='1'){
                nivel1[celda]=lista;
            }
            else if(linea[0]=='2'){
                nivel2[celda]=lista;
            }
            else if(linea[0]=='3'){
                nivel3[celda]=lista;
            }
            else if(linea[0]=='4'){
                nivel4[celda]=lista;
            }
            else if(linea[0]=='5'){
                nivel5[celda]=lista;
            }
        }
        k.close();
    }
}
string posicion(string nivel,string celda,string placa,string autom,string tipo)//Esta funcion nos permite guardar la informacion de nuevo vehiculo
{
    //calculamos la hora en que este sera guardado
    time_t rawTime;
       tm *TimeInfo;
       char Buffer[80];

       time(&rawTime);
       TimeInfo = localtime(&rawTime);

       // I = 12H format   H = 24H format %H:%M:%S Con segundos
       strftime(Buffer, sizeof(Buffer), "%H:%M %d-%m-%Y", TimeInfo);
       std::string Str(Buffer);
       string hora=Str;
       string horac="",dia="";
       for(int i=0;i<=4;i++)horac=horac+hora[i];
       for(int i=6;hora[i]!='\0';i++)dia=dia+hora[i];
    list<string> lista;
    //Agregamos a la lista toda la informacuion importante
    lista.push_back(placa);
    lista.push_back(horac);
    lista.push_back(autom+tipo);
    lista.push_back(dia);
    //Depediendo del nivel se verifica que la casilla seleccionada no este ocupada, de lo contratio esta sera guardada
    if(nivel=="1"){
        r=nivel1.find(celda);
        while(r!=nivel1.end()){
            if(stoi(celda)==70)celda="1";
            celda=to_string(stoi(celda)+1);
            r=nivel1.find(celda);
        }
        nivel1[celda]=lista;
    }
    else if(nivel=="2"){
        r=nivel2.find(celda);
        while(r!=nivel2.end()){
            if(stoi(celda)==70)celda="1";
            celda=to_string(stoi(celda)+1);
            r=nivel2.find(celda);
        }
        nivel2[celda]=lista;
    }
    else if(nivel=="3"){
        r=nivel3.find(celda);
        while(r!=nivel3.end()){
            if(stoi(celda)==70)celda="1";
            celda=to_string(stoi(celda)+1);
            r=nivel3.find(celda);
        }
        nivel3[celda]=lista;
    }
    else if(nivel=="4"){
        r=nivel4.find(celda);
        while(r!=nivel4.end()){
            if(stoi(celda)==70)celda="1";
            celda=to_string(stoi(celda)+1);
            r=nivel4.find(celda);
        }
        nivel4[celda]=lista;
    }
    else if(nivel=="5"){
        r=nivel5.find(celda);
        while(r!=nivel5.end()){
            if(stoi(celda)==70)celda="1";
            celda=to_string(stoi(celda)+1);
            r=nivel5.find(celda);
        }
        nivel5[celda]=lista;
    }
    return celda;
}
int main()
{
    srand(time(NULL));

    Archivos *archi;
    //VARIABLES PARA ADMINISTRADOR
    //_---------------------------------------
    string user;
    int cantidad;
    char  pass[100];
    int caracter=0;
    int temp;
    string numeroS;
    string aux;
    string compararclave="";
    string archivo="";
    int longitud;
    int opcion3;


    //VARIABLES PARA AGREGAR USUARIO
    //----------------------------------------
    string archivousuario;
    string cedulaU;
    string addc;
    string claveU;
    string binario;
    string saldoU;
    string salc;
    string datosuser;
    string agregar;
    int caracter2=0;
    int total;
    string nombreA;
    string copiC;
    ifstream sudoread;
    ofstream sudowrite;
    int tarifa;
    ifstream fileread;
    ofstream filewrite;
    ifstream pisos;
    ofstream celdas;


    //VARIABLES PARA INGRESAR COMO USUARIO
    //--------------------------------------------
    int opcion2;
    string cedula;
    string clave;
    int retiro;
    string saldototal;
    string mostrarsaldo;
    bool ban=false;
    int opcion1;
    string PLACA;
    list<string>DATOS;
    //map<string,string>PARQUEADERO;
    //std::map<string, list<string> >PARQUEADERO;
    //std::map<string, string>ocupacion;
    //Leemos la informacion del archivo de texto
    leer();




    ofstream ESTACIONAMIENTO;
    ifstream ESTACIONAMIENTO1;

    //CREANDO SUDO
    //--------------------------------------------
    string sudo="10110100001111010001011010011011";
    sudowrite.open("sudo.txt" );
    sudowrite<<sudo<<endl;
    sudowrite.close();

    //Ejecutamos el menu principal en un cicla infinito para que no se salga del programa
    while (ban==false)
    {
        //Leemos del archivo de texto las tarifas dadas por el administrador
       a_tarifa();
       //Mostramos el menu principal
    cout<<endl;
    cout<<"SI ESTA REGISTRADO PRESIONE (1): "<<endl;
    cout<<endl;
    cout<<"PARA ACCEDER COMO ADMINISTRADOR PRESIONE (2)"<<endl;
    cout<<endl;
    cout<<"PARA REGISTRARSE PRESIONE (3)"<<endl;
    cout<<endl;
    cin>>opcion1;



//---------------------------USUARIO REGISTRADO----------------
    if (opcion1==1)
    {
        cout<<"Ingrese su nombre:  "<<endl;
        cin>>cedula;
        cout<<"Ingrese su clave:  "<<endl;
        cin>>clave;

        //VERIFICAR QUE EL USUARIO ESTÉ REGISTRADO Y SI SEA CORECTO
        //-----------------------------------------------------------------------------------
            ifstream leyendo;
            string codigoUser;
            //leyendo el archivo
            string abrir=cedula+".txt";
            leyendo.open(abrir);
            leyendo.seekg(0);

            while (leyendo.good())
            {
                char temp= leyendo.get();

                if (leyendo.good())
                {
                    codigoUser.push_back(temp);

                }


            }
            leyendo .close();
            //codificamos la informacion
            string bin=decodificar(codigoUser);
            string info=palabras(bin);

            int lendatosuser=info.size();
            int comas=0;
            string mostrarclave;

            for (int i=0;i<lendatosuser;i++)
            {
                if (info[i]==',')
                {
                    comas=comas+1;
                }
                if (comas==1)
                {   if (info[i]==',')
                    {

                    }
                    else
                    {
                    mostrarclave+=info[i];
                    }
                }
                if (comas==2)
                {
                    break;

                }
            }


        //--------------------------------------------------------------------------
            if (mostrarclave==clave)
            {
                cout<<endl;
                cout<<"BIENVENIDO "<<endl;
                cout<<endl;

               cout<<"Para ver las tarifas disponibles presione (1): "<<endl;
                cout<<endl;
                cout<<"Para retirar el vehiculo presione (2): "<<endl;
                cout<<endl;
                cout<<"Para volver al menu anterior presione (3): "<<endl;
                cout<<endl;
                cout<<"Para salir del programa presione (4): "<<endl;
                cout<<endl;

                cin>>opcion2;



              if (opcion2==1)
              {
                  //MOstramos la tarifa dadas por el administrador al usuario
                cout<<"------------------------------------------------------------------------------"<<endl;
                cout<<endl;
                cout<<"TIPO DE VEHICULO"<<"     "; cout<<"TARIFA POR HORA"<<"           "; cout<<"TARIFA POR MES"<<endl;
                cout<<endl;
                cout<<"AUTOMOVIL"<<"            "; cout<<"(1) "; cout<<CH<<"                "; cout<<"(4) ";cout<<CM<<endl;
                cout<<endl;
                cout<<"MOTOCICLETA"<<"          "; cout<<"(2) ";cout<<MH<<"                "; cout<<"(5) ";cout<<MM<<endl;
                cout<<endl;
                cout<<"BICICLETA"<<"            "; cout<<"(3) ";cout<<BH<<"                 "; cout<<"(6) ";cout<<BM<<endl;

                cout<<endl;
                cout<<"------------------------------------------------------------------------------"<<endl;

                cout<<"Elija una opción: "<<endl;
                 cout<<endl;
                 cin >>tarifa;
                string autom;
                string hora;
                string tipo;
                //string celda="6";
                //string piso="2";


                //Se verifica que tipo de vehiculo sera guardado y si es mensual o temporal
                if (tarifa==1)
                { autom="CARRO";  hora="H";  tipo="H";}
                if (tarifa==2)
                { autom="MOTO";  hora="H";  tipo="H";}
                if (tarifa==3)
                { autom="BICICLETA";  hora="H"; tipo="H";}
                if (tarifa==4)
                { autom="CARRO";  hora="M"; tipo="M";}
                if (tarifa==5)
                { autom="MOTO";  hora="M"; tipo="M";}
                if (tarifa==6)
                { autom="BICICLETA";  hora="M"; tipo="M";}

                //le damos una casilla y nivel al azar, este no se repetira
                string celda=to_string(1+rand()%(71-1));
                string piso=to_string(1+rand()%(6-1));

                cout<<"Ingrese la placa del vehículo : "<<endl;
                cout<<endl;
                cin>>PLACA;
                //Verificamos que la posicion no este ocupada por otro vehiculo
                celda=posicion(piso,celda,PLACA,autom,tipo);
                //Guardamos la informacion en un archivo de texto
                archi=new Archivos (autom, hora, tipo, celda, piso,PLACA );
                archi->escribir();
                cout<<"REGISTRO EXITOSO, ESTACIONE EN EL NIVEL "<<piso<<" Y CELDA "<<celda<<endl;
                cout<<endl;

            }
              if(opcion2==2){
                  map<string,list<string>>::iterator re;
                  string placa,nivel,hora,tipo;
                  //Verificamos la informacion para poder sacar el vehiculo del parqueadero
                  cout<<"Ingrese la placa de su vehiculo: ";
                  cin>>placa;
                  cout<<"Ingrese el nivel donde estaciono su vehiculo: ";
                  cin>>nivel;
                  bool n=1;
                  //Dependiendo del nivel obtenemos el resto de informacion para poder mostrar el recibo
                  if(nivel=="1"){
                      for(r=nivel1.begin();(r!=nivel1.end() and n);r++){
                          //Obtenemos la hora de ingreso y que tarifa sera aplicada
                          l=r->second.begin();
                          if(placa==*l){
                              l++;
                              hora=*l;
                              l++;
                              tipo=*l;
                              n=0;
                              re=r;
                          }
                      }
                      //Si no hubo ningun problema para retirar el vehiculo este lo eliminamos de nuesyto mapa
                      if(!n)nivel1.erase(re);
                  }
                  else if(nivel=="2"){
                      for(r=nivel2.begin();(r!=nivel2.end() and n);r++){
                          l=r->second.begin();
                          if(placa==*l){
                              l++;
                              hora=*l;
                              l++;
                              tipo=*l;
                              n=0;
                              re=r;
                          }
                      }
                      if(!n)nivel2.erase(re);
                  }
                  else if(nivel=="3"){
                      for(r=nivel3.begin();(r!=nivel3.end() and n);r++){
                          l=r->second.begin();
                          if(placa==*l){
                              l++;
                              hora=*l;
                              l++;
                              tipo=*l;
                              n=0;
                              re=r;
                          }
                      }
                      if(!n)nivel3.erase(re);
                  }
                  else if(nivel=="4"){
                      for(r=nivel4.begin();(r!=nivel4.end() and n);r++){
                          l=r->second.begin();
                          if(placa==*l){
                              l++;
                              hora=*l;
                              l++;
                              tipo=*l;
                              n=0;
                              re=r;
                          }
                      }
                      if(!n)nivel4.erase(re);
                  }
                  else if(nivel=="5"){
                      for(r=nivel5.begin();(r!=nivel5.end() and n);r++){
                          l=r->second.begin();
                          if(placa==*l){
                              l++;
                              hora=*l;
                              l++;
                              tipo=*l;
                              n=0;
                              re=r;
                          }
                      }
                      if(!n)nivel5.erase(re);
                  }
                  //Obetenemos la hora en que el vehiculo se retira
                  time_t rawTime;
                     tm *TimeInfo;
                     char Buffer[80];

                     time(&rawTime);
                     TimeInfo = localtime(&rawTime);

                     // I = 12H format   H = 24H format %H:%M:%S Con segundos
                     strftime(Buffer, sizeof(Buffer), "%H:%M %d-%m-%Y", TimeInfo);
                     std::string Str(Buffer);
                     string horas=Str;
                  string he="",hs="";
                  int valor;
                  for(int i=0;i<=1;i++)he=he+hora[i];
                  for(int i=0;i<=1;i++)hs=hs+horas[i];
                  //Dependiendo de la tarifa calculamos el valor que debera ser cobradpo
                  if(tipo=="CARROH")valor=(stoi(hs)-stoi(he))*CH;
                  else if(tipo=="MOTOH")valor=(stoi(hs)-stoi(he))*MH;
                  else if(tipo=="BICILETAH")valor=(stoi(hs)-stoi(he))*BH;
                  else if(tipo=="MOTOM")valor=MM;
                  else if(tipo=="CARROM")valor=CM;
                  else if(tipo=="BICICLETAM")valor=BM;
                  if(!n){
                      //Mostramos la factura en consola
                      factura(hora,to_string(valor));
                      //Se procede a realizar el pago
                      while(pagar(valor)){//mientras que el pago sea insufienciete se repite la funcion pagar
                          cout<<"No es suficiente dinero."<<endl;
                      }
                      //Creamos un nuevo archivo de texto con la informacion necesaria
                      actualizar();
                  }
                  else cout<<"Esta placa no se encuentra en este nivel o parqueadero";
              }

              if (opcion2==3)
              {
                  //Regresamos al menu anterior
                 ban=false;
              }

              if (opcion2==4)
              {
                  //Cerramos el programa
                  cout<<"Cerrando.... "<<endl;
                  ban=true;
              }


}
            else
            {
                //Si no se logro ingresar correctamente no permite realozar ninguan funcion
                cout<<endl;
                cout<<"LA CLAVE ES INCORRECTA O EL USUARIO NO EXISTE"<<endl;
                cout<<endl;
            }
    }


    //----------------------OPCION PARA ENTRAR POR ADMINISTRADOR
        if (opcion1==2)
        {

            cout<<"Ingrese su contrasena de administrador: "<<endl;
            cin>>pass;
            caracter=0;
            compararclave="";
            //CONVIERTO LA CONTRASEÑA DE ADMINISTRADOR A BINARIO
            while (pass[caracter]!='\0')
            {
                char temp=pass[caracter];

                convertir (temp,numeroS,aux);
                longitud=numeroS.size();
                 if (longitud<8)
                {   cantidad=8-longitud;
                    for (int w=0;w<cantidad;w++)
                    {
                    compararclave+='0';

                    }
                    compararclave+=numeroS;
                }
                else{
                compararclave+=numeroS;
                }
                numeroS="";
                compararclave+=numeroS;
                caracter=caracter+1;

            }

            //SE APLICA EL METODO DE CODIFICACION A LA CLAVE EN BINARIO
            compararclave=metodo1( compararclave);

            //LEYENDO SUDO.TXT
            sudoread.open ("sudo.txt");
            sudoread.seekg(0);
            archivo="";
            while(sudoread.good())
            {
                char resc= sudoread.get();

                if (sudoread.good())
                {
                    archivo+=resc;

                }
            }
            sudoread.close();



                int larch=archivo.size();

                string archadmin="";
                for (int i=0;i<larch-1;i++)
                {
                    archadmin+=archivo[i];

                }



                // SI EL USUARIO SI ES ADMINISTRADOR
                if (compararclave==archadmin)
                {
                    cout<<endl;
                    cout<<"VALIDACION CORRECTA DE ADMINISTRADOR"<<endl;
                    cout<<endl;
                    cout<<"VER PORCENTAJE DE OCUPACION POR PISO (1)"<<endl;
                    cout<<endl;
                    cout<<"PRESENTAR REGISTRO DE VEHICULOS (2) "<<endl;
                    cout<<endl;
                    cout<<"CREAR TABLA DE TARIFAS (3) "<<endl;
                    cout<<endl;
                    cout<<"MOSTRAR HISTORIAL DEL PARQUEADERO (4) "<<endl;
                    cout<<endl;
                    cout<<"MOSTRAR HISTORIAL DE UN NIVEL (5) "<<endl;
                    cout<<endl;
                    cout<<"Para volver al menu anterior presione (6): "<<endl;
                    cout<<endl;
                    cout<<"Para salir del programa presione (7): "<<endl;
                    cout<<endl;
                    cin>>opcion3;

                    if(opcion3==5){//Si desea mostrar el historial de un nivel
                        string nivel;
                        cout<<"INGRESE EL NIVEL DEL ESTACIONAMIENTO  "<<endl;
                        cin>>nivel;
                        string linea;
                        ifstream k("historial.txt");
                        //Se verifica que el archivo exista
                        if(k.good()){
                            while(!k.eof()){
                                string celda="",placa="",hora="",tipo="",piso="";
                                int n=0;
                                getline(k,linea);
                                piso=linea[0];
                                for(int i=0;linea[i]!='\0';i++){
                                    //Iteramos sobre cada linea para obtener la informacion sobre el historial de un nivel especifico
                                    if(linea[i]==' ')n+=1;
                                    else if(n==1)celda=celda+linea[i];
                                    else if(n==2)placa=placa+linea[i];
                                    else if(n==3)hora=hora+linea[i];
                                    else if(n==5)tipo=tipo+linea[i];
                                }
                                if(nivel==piso){
                                    //Dependiendo del nivel lo mostramos en consola
                                    cout<<"CELDA:"<<celda<<" PLACA:"<<placa<<" HORA INGRESO:"<<hora<<" TIPO:"<<tipo<<endl;
                                }
                            }
                            k.close();
                        }
                    }
                    if(opcion3==4){//SE muestra el historial de todo el parqueadero
                        string linea;
                        ifstream k("historial.txt");
                        //Se verifica que el archivo exista
                        if(k.good()){
                            while(!k.eof()){
                                string celda="",placa="",hora="",tipo="",piso="";
                                int n=0;
                                getline(k,linea);
                                piso=linea[0];
                                for(int i=0;linea[i]!='\0';i++){
                                    //Iteramos para obtener la informacion necesario
                                    if(linea[i]==' ')n+=1;
                                    else if(n==1)celda=celda+linea[i];
                                    else if(n==2)placa=placa+linea[i];
                                    else if(n==3)hora=hora+linea[i];
                                    else if(n==5)tipo=tipo+linea[i];
                                }
                                //Esta infromacion es mostrada en consola
                                cout<<"NIVEL:"<<linea[0]<<" CELDA:"<<celda<<" PLACA:"<<placa<<" HORA INGRESO:"<<hora<<" TIPO:"<<tipo<<endl;
                            }
                            k.close();
                        }
                    }
                    if(opcion3==3){
                        //Se le pide al administrador que ingrese las nuevas tarifas
                        cout<<"Ingrese una tarifa por hora de carro: ";
                        cin>>CH;
                        cout<<"Ingrese una tarifa por hora de moto: ";
                        cin>>MH;
                        cout<<"Ingrese una tarifa por hora de bicicleta: ";
                        cin>>BH;
                        cout<<"Ingrese una tarifa por mes de carro: ";
                        cin>>CM;
                        cout<<"Ingrese una tarifa por mes de moto: ";
                        cin>>MM;
                        cout<<"Ingrese una tarifa por mes de bicicleta: ";
                        cin>>BM;
                        ofstream k("tarifas.txt");
                        //Esta es guardad en un archivo de textp
                        string linea=to_string(CH)+" "+to_string(MH)+" "+to_string(BH)+" "+to_string(CM)+" "+to_string(MM)+" "+to_string(BM);
                        k<<linea;
                        k.close();
                    }
                    if (opcion3==6)//Regresamos al menu principal
                    {
                        ban=false;
                    }
                    if (opcion3==7)//Salimos del programa
                    {
                        ban=true;
                    }

                    if (opcion3==1)//se muestra la tabla del porcentaje ocupado en el parqueadero
                    {
                        double celdas=0;
//                        for(r=nivel1.begin();r!=nivel1.end();r++){
//                            cout<<"aca";
//                            celdas+=1;
//                        }
                        //hallamos el tamaño de cada mapa y con este scamos el porcentaje
                        celdas=nivel1.size();
                        cout<<"NIVEL 1 "<<"C.OCUPADAS:"<<celdas<<" C.TOTALES:70 %OCUPACION:"<<double((celdas*100)/70)<<"%"<<endl;
                        celdas=nivel2.size();
                        cout<<"NIVEL 2 "<<"C.OCUPADAS:"<<celdas<<" C.TOTALES:70 %OCUPACION:"<<double((celdas*100)/70)<<"%"<<endl;
                        celdas=nivel3.size();
                        cout<<"NIVEL 3 "<<"C.OCUPADAS:"<<celdas<<" C.TOTALES:70 %OCUPACION:"<<double((celdas*100)/70)<<"%"<<endl;
                        celdas=nivel4.size();
                        cout<<"NIVEL 4 "<<"C.OCUPADAS:"<<celdas<<" C.TOTALES:70 %OCUPACION:"<<double((celdas*100)/70)<<"%"<<endl;
                        celdas=nivel5.size();
                        cout<<"NIVEL 5 "<<"C.OCUPADAS:"<<celdas<<" C.TOTALES:70 %OCUPACION:"<<double((celdas*100)/70)<<"%"<<endl;
                    }

                    if (opcion3==2)//Mostramos la informacion de un nivel seleccionado por el administrador
                    {
                        int nivel;
                        cout<<"INGRESE EL NIVEL DEL ESTACIONAMIENTO  "<<endl;
                        cin>>nivel;
                        //Dependiendo del nivel mostranos en consola la informacion de este
                        if(nivel==1){
                            mostrar_registro("1");
                        }
                        else if(nivel==2){
                            mostrar_registro("2");
                        }
                        else if(nivel==3){
                            mostrar_registro("3");
                        }
                        else if(nivel==4){
                            mostrar_registro("4");
                        }
                        else if(nivel==5){
                            mostrar_registro("5");
                        }
                    }
                }
            else
            {
                    //Si la contraseña ingresada es incorrecta no se permite realizar ninguna funcion de administrador
              cout<<"USTED NO ES ADMINISTRADOR"<<endl;
              ban=false;
               }
            }


    //------------------PARA REGISTRAR AL USUARIO---------------
        if (opcion1==3)
        {
            cout<<"INGRESE SU NOMBRE: "<<endl;
            cin>>cedulaU;
            cout<<endl;
            copiC=cedulaU;
            cout<<"INGRESE SU CONTRASENA: "<<endl;
            cin>>claveU;
            cout<<endl;
            /*cout<<"INGRESE EL SALDO DEL USUARIO: "<<endl;
            cin>>saldoU;*/
           // cout<<endl;

            //AGREGANDO A STRING LOS DATOS

            agregar+=cedulaU;
            agregar+=",";
            agregar+=claveU;
            agregar+=",";
            agregar+=saldoU;

            cout<<"REGISTRO EXITOSO"<<endl;
            cout<<endl;
            //GUARDANDO LOS DATOS EN BINARIO

            numeroS="";
            while (agregar[caracter2]!='\0')
            {

            temp=agregar[caracter2];

            convertir (temp,numeroS,aux);
            longitud=numeroS.size();
             if (longitud<8)
            {   cantidad=8-longitud;
                for (int w=0;w<cantidad;w++)
                {
                binario+='0';

                }
                binario+=numeroS;
            }
            else{
            binario+=numeroS;
            }
            numeroS="";
            binario+=numeroS;
            caracter2=caracter2+1;

        }

            //TRANSFORMANDO LOS DATOS EN BINARIO AL MÉTODO DE CODIFICACIÓN

             binario=metodo1(binario);

            //CREANDO ARCHIVO CON LA CÉDULA DEL USUARIO

            copiC+=".txt";
            ofstream k(copiC.c_str(),ios::binary);
            k<<binario<<endl;
            k.close();
        }



}

}
//FUNCION PARA CONVERTIR EN BINARIO

void convertir (int numero,string &numeroS, string aux)
{
    while (numero>0)
    {
        if (numero%2==0)
        {
            numeroS=numeroS+"0";
        }
        else
        {
            numeroS=numeroS+"1";
        }
        numero=numero/2;
    }
    for (int i=numeroS.length()-1;i>=0;i--)
    {
        aux=aux+numeroS.at(i);
    }
    numeroS=aux;
}

//FUNCIÓN DE METODO DE CODIFICACIÓN
string metodo1(string copia)
{
    // VARIABLES PARA CODIFICAR POR EL PRIMER METODO
    //-------------------------------
    int k=0;
    int j=0;
    bool ban;
    int a=0;
    int uno=0;
    int cero=0;
    int longitud1;
    string binario;
    int semilla=4;
    //-------------------------------

        binario=copia;
        if (semilla%2==0)
                {
                    ban=true;
                }
                else
                {
                    ban=false;
                }
                longitud1=binario.size();
                //CAMBIA EL PRIMER BLOQUE, LOS 1S POR 0S

                //PRIMER BLOQUE DE BITS

                for (int j=0;j<semilla;j++)
                {
                    if (binario[j]==49)
                    {


                        binario[j]=48;

                    }
                    else
                    {
                        binario[j]=49;
                    }
                }


            //PARA LOS SIGUEINTES GRUPOS DE BITS
            //-----------------------------------



            while (semilla<=longitud1)
            {

                //REVISA EL BLOQUE ANTERIOR
                for (int i=a;i<(semilla+semilla)/2;i++)
                {
                    if (copia[i]==48)
                    {
                    cero+=+1;
                    }
                    else
                    {
                      uno+=1;
                    }

                }

                //CAMBIA LOS BLOQUES SIGUIENTES DEPENDIENDO DE LA CANTIDAD DE 0S Y 1S ANTERIORES
                //------------------------------------------------------------------------------


                //CASO 1
                if (uno==cero)
                {    for (int j=semilla;j<semilla+4;j++)
                    {

                        if (binario[j]==49)
                        {
                            binario[j]=48;


                        }
                        else
                        {
                            binario[j]=49;

                        }

                    }
                }

                    //CASO 2

                    if (cero>uno)
                    {

                        j=semilla+1;
                        if (ban==true)
                        {



                            while  (j<=semilla+4 and j<=longitud1)
                            {



                                if (j%2==0)
                                {
                                    if (copia[j-1]==48)
                                    {

                                        binario[j-1]=49;

                                    }
                                    else
                                    {
                                        binario[j-1]=48;

                                    }


                                }
                           j=j+1;

                            }
                        }


                    }
                    //CASO 3
                        if (uno>cero)
                        {   k=semilla+2;
                            while (k<semilla+4)
                            {
                                if (copia[k]==48)
                                {

                                    binario[k]=49;

                                }
                                else
                                {
                                    binario[k]=48;

                                }
                                k=k+2;
                            }
                        }




            a=a+4;
            cero=0;
            uno=0;
            semilla=semilla+4;

            }

        return binario;

}

//CONVIERTE BINARIO A NUMERO Y LUEGO A LETRAS


string palabras (string original)
{
    char letra;
    int longitud=original.size();
    string str;
    int digito2;
    int posicion=0;
    int resultado=0;
    string palabra;
    int contador=0;
    int vector []={1,2,4,8,16,32,64,128,256};
        while (contador<longitud)
        {
            for (int j=0;j<=7;j++)
            {
                str[j]=original[contador];

                contador=contador+1;

            }

        for (int i=8-1;i>=0;i--)
        {
            digito2=str[i];

            if (digito2==49)
            {
                resultado=resultado+vector[posicion];

            }
            posicion++;


        }


        letra=resultado;
        posicion=0;
        palabra+=letra;

        resultado=0;


        }
        return palabra;
}

//FUNCIÓN PARA DECODIFICAR EL MÉTODO

string decodificar(string stri)
{



    int q=0;
    int l=0;
    bool bandera;
    int b=0;
    int semillaa=4;
    int u=0;
    int c=0;
    int longi;



        if (semillaa%2==0)
        {
            bandera=true;
        }
        else
        {
            bandera=false;
        }
        longi=stri.size();

        for (int j=0;j<semillaa;j++)
        {

            if (stri[j]==49)
            {

                stri[j]=48;

            }
            else
            {
                stri[j]=49;
            }
        }

    while (semillaa<=longi)
    {

        for (int i=b;i<(semillaa+semillaa)/2;i++)
        {
            if (stri[i]==48)
            {
            c+=+1;
            }
            else
            {
              u+=1;
            }

        }
        if (u==c)
        {    for (int j=semillaa;j<semillaa+4;j++)
            {

                if (stri[j]==49)
                {
                    stri[j]=48;


                }
                else
                {
                    stri[j]=49;

                }

            }
        }
            if (c>u)
            {

                l=semillaa+1;
                if (bandera==true)
                {



                    while  (l<=semillaa+4 and l<=longi)
                    {
                        if (l%2==0)
                        {
                            if (stri[l-1]==48)
                            {

                                stri[l-1]=49;

                            }
                            else
                            {
                                stri[l-1]=48;

                            }
                        }
                   l=l+1;

                    }
                }


            }
                if (u>c)
                {   q=semillaa+2;
                    while (q<semillaa+4)
                    {
                        if (stri[q]==48)
                        {

                            stri[q]=49;

                        }
                        else
                        {
                            stri[q]=48;

                        }
                        q=q+2;
                    }
                }

    b=b+4;
    c=0;
    u=0;
    semillaa=semillaa+4;
    }


    return stri;

}

//CONVIERTE UN NÚMERO EN STRING A ENTERO
unsigned long long int valor (string valor)
{
    int b, d=1, c=0, longitud;
    longitud=valor.length();
    for (int i=longitud-1;i>=0;i--)
    {
        b=valor[i]-48;
        c+=b*d;
        d*=10;
    }
    return c;
}

//CONVIERTE UN NÚMERO ENTERO A STRING
string  enteropalabras(unsigned long long int total)
{
    int c=0,i=1;
    char e;
    string b;
    for (;(total/i);i=i*10)
        c++;
    for (int j=0; j<c;j++)
    {
        i/=10;
        e=(total/i)+48;
        b.push_back(e);
        total-=(total/i)*i;
    }
    return b;
    }
