Copyright 2015 @Xus72

Este programa gestiona la plantilla y la carta de un bar. Además contiene un menú para los camareros en el que llevan el control
de la cuenta de las mesas del bar.
     
Ha sido desarollado en el entorno gráfico Dev C++, aunque también puede ser diseñado en entornos compatibles con C++

#include <conio.h>
#include <iostream>
#include <windows.h>//para usar la función de espera Sleep
#include <locale.h>
#include <string.h>
using namespace std;

/*Función que imprime una línea de 30 símbolos con caracater que se le pasa*/
void imprimeLinea(char simbolo);
/*Función que imprime el menú principal*/
void menuPrincipal();
/*Función que imprime el menú Gerente*/
void menuGerente();

/*Función que imprime los camareros de la plantilla*/
void mostrarCamareros(string camarero1,string camarero2,string camarero3,string clave1,string clave2,string clave3,int totalCamareros);

/*Función que imprime los productos que están registrados*/
void mostrarProductos(string producto1,string producto2,string producto3,string producto4,string producto5,double precio1,double precio2,double precio3,double precio4,double precio5,string codigo1,string codigo2,string codigo3,string codigo4,string codigo5,int totalProductos);

/*Función que imprime el menú para eliminar camareros*/
void eliminarCamareros(string &camarero1,string &camarero2,string &camarero3,string &camareroAux,int &totalCamareros,string &clave1,string &clave2,string &clave3);

/*Función que imprime el menú para eliminar productos*/
void eliminarProductos(string &producto1,string &producto2,string &producto3,string &producto4,string &producto5,string &codigo1,string &codigo2,string &codigo3,string &codigo4,string &codigo5,string &codigoAux,double &precio1,double &precio2,double &precio3,double &precio4,double &precio5,int &totalProductos);

/*Función que imprime el menú de Camarero1*/
void menuCamarero(string claveCamarero,string clave1,string clave2,string clave3,string camarero1,string camarero2,string camarero3);

/*Función para eliminar productos de la cuenta*/
void eliminarProductosCamareros(string &producto1,string &producto2,string &producto3,string &producto4,string &producto5,string &codigo1,string &codigo2,string &codigo3,string &codigo4,string &codigo5,string &codigoAux,double &precio1,double &precio2,double &precio3,double &precio4,double &precio5,int totalProductos,double cuenta);

/*Función que muestra la cuenta*/
void mostrarCuenta(double cuenta);

/*Función que muestra la vuelta*/
void mostrarVuelta(double pago,double vuelta,double cuenta);

/*Función que reinicia la cuenta*/
void reiniciarCuenta(double cuenta);

/*Función que cambia la clave del camarero*/
void cambiarClave(string &clave1,string &clave2,string &clave3,string &claveCamarero,string camareroAux,string camarero1,string camarero2,string camarero3)

/*Función que comprueba la clave del gerente*/
void compruebaClave(int claveGerente1,int claveGerente2);
void compruebaClaveCamarero(string clave1,string clave2,string clave3,string claveCamarero,string &camareroAux,string &camarero1,string &camarero2,string &camarero3);


/*PROGRAMA PRINCIPAL*/
int main(){
char perfil;
int opGerente=0;/*valor no incluido en menú*/ int claveGerente;
string claveCamarero;
char opCamarero='z';//valor no incluido en menú
char opModCamarero='z', opModProducto='z';
string camarero, camarero1, camarero2, camarero3, camareroAux; //Camareros
string clave, clave1, clave2, clave3, claveAux, comprobarClave; //Clave de los camareros
string codigo, codigo1, codigo2, codigo3, codigo4, codigo5, codigoAux; //Código de los productos
int totalCamareros=0, totalProductos=0;
double cuenta=0, vuelta, pago;
string producto1, producto2, producto3, producto4, producto5, productoAux; //Productos
double precio1, precio2, precio3, precio4, precio5, precioAux; //Precio de los productos
setlocale(LC_CTYPE, "Spanish");

while (perfil!='s' && perfil!='S'){
      menuPrincipal();
      cin>>perfil;
      switch (perfil){
             case 'G':
             case 'g':
                  opGerente=0;//valor que no esté en menú
                  system("cls");
                  cout<<"Acceso Menú Gerente";
                  imprimeLinea('*');
                  cout<<"Introduzca su clave"<<endl;
                  cin>>claveGerente;
                  compruebaClave (007,claveGerente);
                  while(opGerente!=9){
                                        menuGerente();
                                        cin>>opGerente;

                                          switch(opGerente){
                                           case 1:
                                                system("cls");
                                                if(totalCamareros>=3)
                                                                     cout<<"Su plantilla está completa"<<endl;
                                                else{
                                                     //Inserta nombre del camarero
                                                     cout<<"Inserte el nombre del camarero"<<endl;
                                                     cin>>camarero;
                                                     system("cls");
                                                     while (camarero.size()!=5){//la función size devuelve el tamaño de un string
                                                     cout<<"Nombre no valido, inserte un nombre de 5 caracteres"<<endl;
                                                     cin>>camarero;
                                                     system("cls");
                                                     }
                                                     if(totalCamareros==0) camarero1=camarero;
                                                     if(totalCamareros==1) camarero2=camarero;
                                                     if(totalCamareros==2) camarero3=camarero;
                                                     //Inserta clave del camarero
                                                     cout<<"Inserte clave del camarero"<<endl;
                                                     cin>>clave;
                                                     system("cls");
                                                     while (clave.size()!=3){//la función size devuelve el tamaño de un string
                                                     cout<<"Clave no válida, inserte una clave de 3 caracteres"<<endl;
                                                     cin>>clave;
                                                     system("cls");
                                                     }
                                                     if(totalCamareros==0) clave1=clave;
                                                     if(totalCamareros==1) clave2=clave;
                                                     if(totalCamareros==2) clave3=clave;
                                                     //Indica los datos del camarero
                                                     if(totalCamareros==0) cout<<"Se ha introducido el camarero "<<camarero1<<" con clave "<<clave1;
                                                     if(totalCamareros==1) cout<<"Se ha introducido el camarero "<<camarero2<<" con clave "<<clave2;
                                                     if(totalCamareros==2) cout<<"Se ha introducido el camarero "<<camarero3<<" con clave "<<clave3;
                                                     }
                                                     totalCamareros++;
                                                     Sleep(2000);
                                                break;
                                           case 2:
                                                eliminarCamareros(camarero1,camarero2,camarero3,camareroAux,totalCamareros,clave1,clave2,clave3);
                                                break;
                                           case 3:
                                                system("cls");
                                                if(totalProductos>=5)
                                                                     cout<<"No se pueden añadir más productos"<<endl;
                                                else{
                                                //Introduce el nombre del producto
                                                cout<<"Introduzca un producto"<<endl;
                                                if(totalProductos==0) cin>>producto1;
                                                if(totalProductos==1) cin>>producto2;
                                                if(totalProductos==2) cin>>producto3;
                                                if(totalProductos==3) cin>>producto4;
                                                if(totalProductos==4) cin>>producto5;
                                                system("cls");
                                                //Introduce el precio
                                                cout<<"Inserte el precio del producto"<<endl;
                                                if(totalProductos==0) cin>>precio1;
                                                if(totalProductos==1) cin>>precio2;
                                                if(totalProductos==2) cin>>precio3;
                                                if(totalProductos==3) cin>>precio4;
                                                if(totalProductos==4) cin>>precio5;
                                                system("cls");
                                                //Introduce el código
                                                cout<<"Inserte el código del producto"<<endl;
                                                cin>>codigo;
                                                     while (codigo.size()!=2){//la función size devuelve el tamaño de un string
                                                     cout<<"Codigo no valido, inserte un código de 2 caracteres"<<endl;
                                                     cin>>codigo;
                                                     system("cls");
                                                     }
                                                if(totalProductos==0) codigo1=codigo;
                                                if(totalProductos==1) codigo2=codigo;
                                                if(totalProductos==2) codigo3=codigo;
                                                if(totalProductos==3) codigo4=codigo;
                                                if(totalProductos==4) codigo5=codigo;
                                                system("cls");
                                                //Muestra los datos del producto registrado
                                                if(totalProductos==0) cout<<"Se ha introducido el producto "<<producto1<<" cuyo precio es "<<precio1<<" euros y su codigo es "<<codigo1;
                                                if(totalProductos==1) cout<<"Se ha introducido el producto "<<producto2<<" cuyo precio es "<<precio2<<" euros y su codigo es "<<codigo2;
                                                if(totalProductos==2) cout<<"Se ha introducido el producto "<<producto3<<" cuyo precio es "<<precio3<<" euros y su codigo es "<<codigo3;
                                                if(totalProductos==3) cout<<"Se ha introducido el producto "<<producto4<<" cuyo precio es "<<precio4<<" euros y su codigo es "<<codigo4;
                                                if(totalProductos==4) cout<<"Se ha introducido el producto "<<producto5<<" cuyo precio es "<<precio5<<" euros y su codigo es "<<codigo5;
                                                }
                                                totalProductos++;
                                                Sleep(2000);
                                                break;
                                           case 4:
                                                mostrarProductos(producto1,producto2,producto3,producto4,producto5,precio1,precio2,precio3,precio4,precio5,codigo1,codigo2,codigo3,codigo4,codigo5,totalProductos);
                                                Sleep(3000);
                                                eliminarProductos(producto1,producto2,producto3,producto4,producto5,codigo1,codigo2,codigo3,codigo4,codigo5,codigoAux,precio1,precio2,precio3,precio4,precio5,totalProductos);
                                                break;
                                           case 5:
                                                imprimeLinea('-');
                                                mostrarCamareros(camarero1,camarero2,camarero3,clave1,clave2,clave3,totalCamareros);
                                                imprimeLinea('-');
                                                if(totalCamareros==0) cout<<"No hay camareros registrados";
                                                else{
                                                     opModCamarero='z';
                                                     while(opModCamarero!='c' && opModCamarero!='C'){
                                                                              cout<<endl;
                                                                              imprimeLinea('-');
                                                                              cout<<"¿Qué desea modificar?"<<endl;
                                                                              cout<<"A) Nombre"<<endl;
                                                                              cout<<"B) Clave"<<endl;
                                                                              cout<<"C) Salir"<<endl;
                                                                              imprimeLinea('-');
                                                                              cin>>opModCamarero;
                                                                              system("cls");
                                                                              switch(opModCamarero){
                                                                                                    case'A':
                                                                                                    case'a':
                                                                                                            system("cls");
                                                                                                            cout<<"Introduzca el nombre del camarero que quiere modificar"<<endl;
                                                                                                            cin>>camareroAux;
                                                                                                            system("cls");
                                                                                                            if(camareroAux==camarero1) {
                                                                                                                                       cout<<"Introduzca el nuevo nombre del camarero"<<endl;
                                                                                                                                       cin>>camareroAux;
                                                                                                                                       while (camareroAux.size()!=5){//la función size devuelve el tamaño de un string
                                                                                                                                       cout<<"Nombre no válido, inserte un nombre de 5 caracteres"<<endl;
                                                                                                                                       cin>>camareroAux;
                                                                                                                                       }
                                                                                                                                       camarero1=camareroAux;
                                                                                                                                       cout<<"Realizando cambios..."<<endl;
                                                                                                                                       Sleep(2000);
                                                                                                                                       system("cls");
                                                                                                                                       cout<<"Se ha modificado el nombre del camarero";
                                                                                                                                       }
                                                                                                            if(camareroAux==camarero2) {
                                                                                                                                       cout<<"Introduzca el nuevo nombre del camarero"<<endl;
                                                                                                                                       cin>>camareroAux;
                                                                                                                                       while (camareroAux.size()!=5){//la función size devuelve el tamaño de un string
                                                                                                                                       cout<<"Nombre no válido, inserte un nombre de 5 caracteres"<<endl;
                                                                                                                                       cin>>camareroAux;
                                                                                                                                       }
                                                                                                                                       camarero2=camareroAux;
                                                                                                                                       cout<<"Realizando cambios..."<<endl;
                                                                                                                                       Sleep(2000);
                                                                                                                                       system("cls");
                                                                                                                                       cout<<"Se ha modificado el nombre del camarero";
                                                                                                                                       }
                                                                                                            if(camareroAux==camarero3) {
                                                                                                                                       cout<<"Introduzca el nuevo nombre del camarero"<<endl;
                                                                                                                                       cin>>camareroAux;
                                                                                                                                       while (camarero.size()!=5){//la función size devuelve el tamaño de un string
                                                                                                                                       cout<<"Nombre no válido, inserte un nombre de 5 caracteres"<<endl;
                                                                                                                                       cin>>camareroAux;
                                                                                                                                       }
                                                                                                                                       camarero3=camareroAux;
                                                                                                                                       cout<<"Realizando cambios..."<<endl;
                                                                                                                                       system("cls");
                                                                                                                                       Sleep(2000);
                                                                                                                                       cout<<"Se ha modificado el nombre del camarero";
                                                                                                                                       }
                                                                                                                                       Sleep(2000);
                                                                                                                                       system("cls");

                                                                                                            break;
                                                                                                     case'B':
                                                                                                     case'b':

                                                                                                              system("cls");
                                                                                                             cout<<"Introduzca el nombre del camarero que quiere modificar"<<endl;
                                                                                                             cin>>camareroAux;
                                                                                                             system("cls");

                                                                                                             if(camareroAux==camarero1) {
                                                                                                                                        cout<<"Introduzca la nueva clave del camarero"<<endl;
                                                                                                                                        cin>>claveAux;
                                                                                                                                        while (clave.size()!=3){//la función size devuelve el tamaño de un string
                                                                                                                                        cout<<"Clave no válida, inserte una clave de 3 caracteres"<<endl;
                                                                                                                                        cin>>claveAux;
                                                                                                                                        }
                                                                                                                                        clave1=claveAux;
                                                                                                                                        cout<<"Realizando cambios..."<<endl;
                                                                                                                                        Sleep(2000);
                                                                                                                                        system("cls");
                                                                                                                                        cout<<"Se ha modificado la clave del camarero";
                                                                                                                                        }
                                                                                                             if(camareroAux==camarero2) {
                                                                                                                                        cout<<"Introduzca la nueva clave del camarero"<<endl;
                                                                                                                                        cin>>claveAux;
                                                                                                                                        while (clave.size()!=3){//la función size devuelve el tamaño de un string
                                                                                                                                        cout<<"Clave no válida, inserte una clave de 3 caracteres"<<endl;
                                                                                                                                        cin>>claveAux;
                                                                                                                                        }
                                                                                                                                        clave2=claveAux;
                                                                                                                                        cout<<"Realizando cambios..."<<endl;
                                                                                                                                        Sleep(2000);
                                                                                                                                        cout<<"Se ha modificado la clave del camarero";
                                                                                                                                        }
                                                                                                             if(camareroAux==camarero3) {
                                                                                                                                        cout<<"Introduzca la nueva clave del camarero"<<endl;
                                                                                                                                        cin>>claveAux;
                                                                                                                                        while (clave.size()!=3){//la función size devuelve el tamaño de un string
                                                                                                                                        cout<<"Clave no válida, inserte una clave de 3 caracteres"<<endl;
                                                                                                                                        cin>>claveAux;
                                                                                                                                        }
                                                                                                                                        clave3=claveAux;
                                                                                                                                        cout<<"Realizando cambios..."<<endl;
                                                                                                                                        Sleep(2000);
                                                                                                                                        cout<<"Se ha modificado la clave del camarero";
                                                                                                                                        }
                                                                                                                                        Sleep(2000);
                                                                                                                                        system("cls");
                                                                                                             break;
                                                                                                     case'C':
                                                                                                     case'c':
                                                                                                             system("cls");
                                                                                                             cout<<"Volviendo al menú del gerente...";
                                                                                                             Sleep(2000);
                                                                                                             break;
                                                                                                     default:
                                                                                                             cout<<"Opción incorrecta";
                                                                                                             Sleep(2000);

                                                                                                    }
                                                                                                    }
                                                     }
                                                break;
                                           case 6:

                                                system("cls");
                                                imprimeLinea('_');
                                                mostrarProductos(producto1,producto2,producto3,producto4,producto5,precio1,precio2,precio3,precio4,precio5,codigo1,codigo2,codigo3,codigo4,codigo5,totalProductos);
                                                imprimeLinea('_');
                                                if(totalProductos==0) cout<<"No hay productos registrados";
                                                else{
                                                     opModProducto='z';
                                                     while(opModProducto!='d' && opModProducto!='D'){
                                                                              cout<<"¿Qué desea modificar?"<<endl;
                                                                              cout<<"A) Nombre del producto"<<endl;
                                                                              cout<<"B) Clave del producto"<<endl;
                                                                              cout<<"C) Código del producto"<<endl;
                                                                              cout<<"D) Salir"<<endl;
                                                                              cin>>opModProducto;
                                                                              system("cls");
                                                                              switch(opModProducto){
                                                                                                    case'A':
                                                                                                    case'a':

                                                                                                            cout<<"Introduzca el nombre del producto que quiere modificar"<<endl;
                                                                                                            cin>>productoAux;
                                                                                                            system("cls");

                                                                                                            if(productoAux==producto1) {
                                                                                                                                       cout<<"Introduzca el nuevo nombre del producto"<<endl;
                                                                                                                                       cin>>productoAux; producto1=productoAux;
                                                                                                                                       system("cls");
                                                                                                                                       cout<<"Realizando cambios..."<<endl;
                                                                                                                                       Sleep(2000);
                                                                                                                                       system("cls");
                                                                                                                                       cout<<"Se ha modificado el nombre del producto";
                                                                                                                                       }
                                                                                                            if(productoAux==producto2) {
                                                                                                                                       cout<<"Introduzca el nuevo nombre del camarero"<<endl;
                                                                                                                                       cin>>productoAux; producto2=productoAux;
                                                                                                                                       cout<<"Realizando cambios..."<<endl;
                                                                                                                                       Sleep(2000);
                                                                                                                                       system("cls");
                                                                                                                                       cout<<"Se ha modificado el nombre del producto";
                                                                                                                                       }
                                                                                                            if(productoAux==producto3) {
                                                                                                                                       cout<<"Introduzca el nuevo nuevo del producto"<<endl;
                                                                                                                                       cin>>productoAux; producto3=productoAux;
                                                                                                                                       cout<<"Realizando cambios..."<<endl;
                                                                                                                                       Sleep(2000);
                                                                                                                                       system("cls");
                                                                                                                                       cout<<"Se ha modificado el nombre del prodcuto";
                                                                                                                                       }
                                                                                                                                       Sleep(2000);
                                                                                                            break;
                                                                                                     case'B':
                                                                                                     case'b':

                                                                                                             cout<<"Introduzca el nombre del producto que quiere modificar"<<endl;
                                                                                                             cin>>productoAux;
                                                                                                             system("cls");

                                                                                                             if(productoAux==producto1) {
                                                                                                                                        cout<<"Introduzca el nuevo precio del producto"<<endl;
                                                                                                                                        cin>>precioAux; precio1=precioAux;
                                                                                                                                        system("cls");
                                                                                                                                        cout<<"Realizando cambios..."<<endl;
                                                                                                                                        Sleep(2000);
                                                                                                                                        system("cls");
                                                                                                                                        cout<<"Se ha modificado el precio del producto";
                                                                                                                                        }
                                                                                                             if(productoAux==producto2) {
                                                                                                                                        cout<<"Introduzca el nuevo precio del producto"<<endl;
                                                                                                                                        cin>>precioAux; precio2=precioAux;
                                                                                                                                        system("cls");
                                                                                                                                        cout<<"Realizando cambios..."<<endl;
                                                                                                                                        Sleep(2000);
                                                                                                                                        system("cls");
                                                                                                                                        cout<<"Se ha modificado el precio del producto";
                                                                                                                                        }
                                                                                                             if(productoAux==producto3) {
                                                                                                                                        cout<<"Introduzca el nuevo precio del producto"<<endl;
                                                                                                                                        cin>>precioAux; precio3=precioAux;
                                                                                                                                        system("cls");
                                                                                                                                        cout<<"Realizando cambios..."<<endl;
                                                                                                                                        Sleep(2000);
                                                                                                                                        system("cls");
                                                                                                                                        cout<<"Se ha modificado el precio del producto";
                                                                                                                                        }
                                                                                                                                        Sleep(2000);

                                                                                                             break;
                                                                                                     case'C':
                                                                                                     case'c':

                                                                                                            system("cls");
                                                                                                             cout<<"Introduzca el nombre del producto que quiere modificar"<<endl;
                                                                                                            cin>>productoAux;
                                                                                                              system("cls");
                                                                                                            if(productoAux==producto1) {
                                                                                                                                       cout<<"Introduzca el nuevo código del producto"<<endl;
                                                                                                                                       cin>>codigoAux;
                                                                                                                                       while (codigoAux.size()!=2){//la función size devuelve el tamaño de un string
                                                                                                                                       system("cls");
                                                                                                                                       cout<<"Código no válido, inserte un código de 2 caracteres"<<endl;
                                                                                                                                       cin>>codigoAux;
                                                                                                                                       system("cls");
                                                                                                                                       }
                                                                                                                                       codigo1=codigoAux;
                                                                                                                                       cout<<"Realizando cambios..."<<endl;
                                                                                                                                       Sleep(2000);
                                                                                                                                       system("cls");
                                                                                                                                       cout<<"Se ha modificado el código del producto";
                                                                                                                                       }
                                                                                                            if(productoAux==producto2) {
                                                                                                                                       cout<<"Introduzca el nuevo código del producto"<<endl;
                                                                                                                                       cin>>codigoAux;
                                                                                                                                       system("cls");
                                                                                                                                       while (codigoAux.size()!=2){//la función size devuelve el tamaño de un string
                                                                                                                                       cout<<"Código no válido, inserte un código de 2 caracteres"<<endl;
                                                                                                                                       cin>>codigoAux;
                                                                                                                                       system("cls");
                                                                                                                                       }
                                                                                                                                       codigo2=codigoAux;
                                                                                                                                       cout<<"Realizando cambios..."<<endl;
                                                                                                                                       Sleep(2000);
                                                                                                                                       system("cls");
                                                                                                                                       cout<<"Se ha modificado el código del producto";
                                                                                                                                       }
                                                                                                            if(productoAux==producto3) {
                                                                                                                                       cout<<"Introduzca el nuevo código del producto"<<endl;
                                                                                                                                       cin>>codigoAux;
                                                                                                                                       system("cls");
                                                                                                                                       while (codigoAux.size()!=2){//la función size devuelve el tamaño de un string
                                                                                                                                       cout<<"Código no válido, inserte un código de 2 caracteres"<<endl;
                                                                                                                                       cin>>codigoAux;
                                                                                                                                       system("cls");
                                                                                                                                       }
                                                                                                                                       codigo3=codigoAux;
                                                                                                                                       cout<<"Realizando cambios..."<<endl;
                                                                                                                                       Sleep(2000);
                                                                                                                                       system("cls");
                                                                                                                                       cout<<"Se ha modificado el código del prodcuto";
                                                                                                                                       }
                                                                                                                                       Sleep(2000);
                                                                                                            break;
                                                                                                     case'D':
                                                                                                     case'd':
                                                                                                             cout<<"Volviendo al menú principal...";
                                                                                                             Sleep(2000);
                                                                                                             break;
                                                                                                     default:
                                                                                                             cout<<"Opción incorrecta";
                                                                                                             Sleep(2000);
                                                                                                             break;
                                                                                                    }
                                                                                                    }
                                                     }
                                                break;
                                           case 7:
                                                mostrarProductos(producto1,producto2,producto3,producto4,producto5,precio1,precio2,precio3,precio4,precio5,codigo1,codigo2,codigo3,codigo4,codigo5,totalProductos);
                                                Sleep(2000);
                                                break;
                                           case 8:
                                                mostrarCamareros(camarero1,camarero2,camarero3,clave1,clave2,clave3,totalCamareros);
                                                Sleep(2000);
                                                break;
                                           case 9:
                                                cout<<"Volviendo a menu principal..."<<endl;
                                                Sleep(2000);//esperar dos segundos
                                                break;
                                           default:
                                                   cout<<"operacion incorrecta..."<<endl;
                                                   Sleep(2000);//esperar dos segundos
                                           }
                                           }
             break;
             case 'C':
             case 'c':
                  opCamarero='z';//opción que no esté en menú camarero
                  system("cls");
                  if(totalCamareros==0) {cout<<"No hay camareros registrados"<<endl; Sleep(3000);}
                  else{
                  cout<<"Acceso Menú Camarero";
                  imprimeLinea('*');
                  cout<<"Introduzca su clave"<<endl;
                  cin>>claveCamarero;
                  system("cls");
                  compruebaClaveCamarero(clave1,clave2,clave3,claveCamarero,camareroAux,camarero1,camarero2,camarero3);
                  while (opCamarero!='h' && opCamarero!='H'){
                        menuCamarero(claveCamarero,clave1,clave2,clave3,camarero1,camarero2,camarero3);
                        cin>>opCamarero;
                        system("cls");

                        switch(opCamarero){
                                           case 'a':
                                           case 'A':
                                                mostrarProductos(producto1,producto2,producto3,producto4,producto5,precio1,precio2,precio3,precio4,precio5,codigo1,codigo2,codigo3,codigo4,codigo5,totalProductos);
                                                if(totalProductos==0) cout<<"No hay ningún producto en la carta"<<endl;
                                                else{
                                                     cout<<"Introduzcas el código del producto que quiere añandir"<<endl;
                                                     cin>>codigoAux;
                                                     system("cls");
                                                     if(codigoAux==codigo1) cout<<"Se ha añadido a la cuenta el producto"<<endl;
                                                     if(codigoAux==codigo2) cout<<"Se ha añadido a la cuenta el producto"<<endl;
                                                     if(codigoAux==codigo3) cout<<"Se ha añadido a la cuenta el producto"<<endl;
                                                     if(codigoAux==codigo4) cout<<"Se ha añadido a la cuenta el producto"<<endl;
                                                     if(codigoAux==codigo5) cout<<"Se ha añadido a la cuenta el producto"<<endl;
                                                     Sleep(2000);
                                                     system("cls");
                                                     if(codigoAux==codigo1) cuenta=cuenta+precio1;
                                                     if(codigoAux==codigo2) cuenta=cuenta+precio2;
                                                     if(codigoAux==codigo3) cuenta=cuenta+precio3;
                                                     if(codigoAux==codigo4) cuenta=cuenta+precio4;
                                                     if(codigoAux==codigo5) cuenta=cuenta+precio5;
                                                     cout<<"Cuenta: "<<cuenta<<" euros";
                                                     Sleep(2000);
                                                     }
                                                break;
                                           case 'b':
                                           case 'B':
                                                eliminarProductosCamareros(producto1,producto2,producto3,producto4,producto5,codigo1,codigo2,codigo3,codigo4,codigo5,codigoAux,precio1,precio2,precio3,precio4,precio5,totalProductos,cuenta);
                                                break;
                                           case 'c':
                                           case 'C':
                                                mostrarCuenta(cuenta);
                                                break;
                                           case 'd':
                                           case 'D':
                                                mostrarVuelta(pago,vuelta,cuenta);
                                                break;
                                           case 'e':
                                           case 'E':
                                                cambiarClave(clave1,clave2,clave3,claveCamarero,camareroAux,camarero1,camarero2,camarero3);
                                                break;
                                           case 'f':
                                           case 'F':
                                                mostrarProductos(producto1,producto2,producto3,producto4,producto5,precio1,precio2,precio3,precio4,precio5,codigo1,codigo2,codigo3,codigo4,codigo5,totalProductos);
                                                Sleep(2000);
                                                break;
                                           case 'G':
                                           case 'g':
                                                reiniciarCuenta(cuenta);
                                                break;
                                           case 'h':
                                           case 'H':
                                                cout<<"Volviendo a menu principal..."<<endl;
                                                Sleep(2000);
                                                break;
                                           default:
                                           cout<<"operacion incorrecta..."<<endl;
                                           Sleep(2000);//esperar dos segundos
                                           break;
                                           }
}
                                           }
                  break;
             case 's':
             case 'S':
                  cout<<"Cerrando aplicacion......";
                  Sleep(2000);
                  break;
             default:
                     cout<<"Perfil incorrecto, seleccione otro...."<<endl;
             }



      }



    getch();
    }

void menuPrincipal(){
     system("cls");//permite borrar la pantalla
     cout<<"Bienvenido al BAR VEIDER,seleccione su perfil..."<<endl;
     imprimeLinea('*');
     cout<<"G) Gerente"<<endl<<"C) Camarero"<<endl<<"S) Salir";
     imprimeLinea('*');
     }

void imprimeLinea(char simbolo){
     cout<<endl;
     for (int i=1; i<=30; i++)
         cout<<simbolo;
     cout<<endl;
     }

void menuGerente(){
     system("cls");//permite borrar la pantalla
     cout<<"Seleccione operacion..."<<endl;
     imprimeLinea('-');
     cout<<"1)Camarero Nuevo      2)Eliminar Camarero"<<endl<<"3)Producto Nuevo      4)Eliminar Producto"<<endl;
     cout<<"5)Modificar Camarero  6)Modificar Producto"<<endl<<"7)Mostrar Productos   8)Mostrar Camareros"<<endl;
     cout<<"9)Volver al menu principal";
     imprimeLinea('-');
     }

void mostrarCamareros(string camarero1,string camarero2,string camarero3,string clave1,string clave2,string clave3,int totalCamareros){
     system("cls");
     if(totalCamareros==0) cout<<"No tiene camareros registrados"<<endl;
     if(totalCamareros==1) {cout<<"Nombre     Clave"<<endl<<camarero1<<"     "<<clave1<<endl;}
     if(totalCamareros==2) {cout<<"Nombre     Clave"<<endl<<camarero1<<"     "<<clave1<<endl<<camarero2<<"     "<<clave2<<endl;}
     if(totalCamareros==3) {cout<<"Nombre     Clave"<<endl<<camarero1<<"     "<<clave1<<endl<<camarero2<<"     "<<clave2<<endl<<camarero3<<"     "<<clave3<<endl;}
     }

void mostrarProductos(string producto1,string producto2,string producto3,string producto4,string producto5,double precio1,double precio2,double precio3,double precio4,double precio5,string codigo1,string codigo2,string codigo3,string codigo4,string codigo5,int totalProductos){
     system("cls");
     imprimeLinea('*');
     if(totalProductos==0) cout<<"No dispone de ningún producto"<<endl;
     if(totalProductos==1) {cout<<"Dispone de los siguientes productos:"<<endl; cout<<"Código: "<<codigo1<<" "<<"Producto: "<<producto1<<" "<<"Precio: "<<precio1<<endl;}
     if(totalProductos==2) {cout<<"Dispone de los siguientes productos:"<<endl; cout<<"Código: "<<codigo1<<" "<<"Producto: "<<producto1<<" "<<"Precio: "<<precio1<<endl;cout<<"Código: "<<codigo2<<" "<<"Producto: "<<producto2<<" "<<"Precio: "<<precio2<<endl;}
     if(totalProductos==3) {cout<<"Dispone de los siguientes productos:"<<endl; cout<<"Código: "<<codigo1<<" "<<"Producto: "<<producto1<<" "<<"Precio: "<<precio1<<endl;cout<<"Código: "<<codigo2<<" "<<"Producto: "<<producto2<<" "<<"Precio: "<<precio2<<endl;cout<<"Código: "<<codigo3<<" "<<"Producto: "<<producto3<<" "<<"Precio: "<<precio3<<endl;}
     if(totalProductos==4) {cout<<"Dispone de los siguientes productos:"<<endl; cout<<"Código: "<<codigo1<<" "<<"Producto: "<<producto1<<" "<<"Precio: "<<precio1<<endl;cout<<"Código: "<<codigo2<<" "<<"Producto: "<<producto2<<" "<<"Precio: "<<precio2<<endl;cout<<"Código: "<<codigo3<<" "<<"Producto: "<<producto3<<" "<<"Precio: "<<precio3<<endl;cout<<"Código: "<<codigo4<<" "<<"Producto: "<<producto4<<" "<<"Precio: "<<precio4<<endl;}
     if(totalProductos==5) {cout<<"Dispone de los siguientes productos:"<<endl; cout<<"Código: "<<codigo1<<" "<<"Producto: "<<producto1<<" "<<"Precio: "<<precio1<<endl;cout<<"Código: "<<codigo2<<" "<<"Producto: "<<producto2<<" "<<"Precio: "<<precio2<<endl;cout<<"Código: "<<codigo3<<" "<<"Producto: "<<producto3<<" "<<"Precio: "<<precio3<<endl;cout<<"Código: "<<codigo4<<" "<<"Producto: "<<producto4<<" "<<"Precio: "<<precio4<<endl;cout<<"Código: "<<codigo5<<" "<<"Producto: "<<producto5<<" "<<"Precio: "<<precio5<<endl;}
     imprimeLinea('*');
}

void eliminarCamareros(string &camarero1,string &camarero2,string &camarero3,string &camareroAux,int &totalCamareros,string &clave1,string &clave2,string &clave3){
     system("cls");
     if(totalCamareros==0) cout<<"No hay camareros registrados";
     else{
     cout<<endl;
     cout<<"Inserte el nombre del camarero quieres eliminar"<<endl;
     cin>>camareroAux;
     if(camareroAux==camarero3) totalCamareros--;
     if(camareroAux==camarero2) {camarero2=camarero3; clave2=clave3; totalCamareros--;}
     if(camareroAux==camarero1) {camarero1=camarero2; clave1=clave2;  camarero2=camarero3; clave2=clave3; totalCamareros--;}
     system("cls");
     cout<<"Eliminando camarero..."<<endl;
     cout<<endl;
     Sleep(2000);
     system("cls");
     cout<<"El camarero ha sido eleminado";
     Sleep(2000);
     }
     Sleep(3000);
     }

void eliminarProductos(string &producto1,string &producto2,string &producto3,string &producto4,string &producto5,string &codigo1,string &codigo2,string &codigo3,string &codigo4,string &codigo5,string &codigoAux,double &precio1,double &precio2,double &precio3,double &precio4,double &precio5,int &totalProductos){
     system("cls");
     if(totalProductos==0)cout<<"No hay productos registrados";
     else{
          cout<<endl;
          cout<<"Inserte el código del producto que quieres eliminar"<<endl;
          cin>>codigoAux;
          if(codigoAux==codigo5) totalProductos--;
          if(codigoAux==codigo4) {producto4=producto5; codigo4=codigo5; precio4=precio5; totalProductos--;}
          if(codigoAux==codigo3) {producto3=producto4; codigo3=codigo4; precio3=precio4; producto4=producto5; codigo4=codigo5; precio4=precio5; totalProductos--;}
          if(codigoAux==codigo2) {producto2=producto3; codigo2=codigo3; precio2=precio3; producto3=producto4; codigo3=codigo4; precio3=precio4; producto4=producto5; codigo4=codigo5; precio4=precio5; totalProductos--;}
          if(codigoAux==codigo1) {producto1=producto2; codigo1=codigo2; precio1=precio2; producto2=producto3; codigo2=codigo3; precio2=precio3; producto3=producto4; codigo3=codigo4; precio3=precio4; producto4=producto5; codigo4=codigo5; precio4=precio5; totalProductos--;}
     system("cls");
     cout<<"Eliminando producto..."<<endl;
     Sleep(2000);
     cout<<"El producto ha sido eliminado";
     Sleep(2000);
     }
     Sleep(3000);
     }

void menuCamarero(string claveCamarero,string clave1,string clave2,string clave3,string camarero1,string camarero2,string camarero3){
     system("cls");//permite borrar la pantalla
     if(claveCamarero==clave1)cout<<"Camarero: "<<camarero1<<endl;
     if(claveCamarero==clave2)cout<<"Camarero: "<<camarero2<<endl;
     if(claveCamarero==clave3)cout<<"Camarero: "<<camarero3<<endl;
     cout<<"Seleccione operacion..."<<endl;
     imprimeLinea('+');
     cout<<"a)Anadir producto a la cuenta    b)Quitar producto de la cuenta"<<endl;
     cout<<"c)Obtener cuenta                 d)Obtener vuelta"<<endl;
     cout<<"e)Cambiar clave                  f)Mostrar productos"<<endl;
     cout<<"g)Reiniciar cuenta               h)Volver al menu principal";
     imprimeLinea('+');
     }

void eliminarProductosCamareros(string &producto1,string &producto2,string &producto3,string &producto4,string &producto5,string &codigo1,string &codigo2,string &codigo3,string &codigo4,string &codigo5,string &codigoAux,double &precio1,double &precio2,double &precio3,double &precio4,double &precio5,int totalProductos,double cuenta){
     system("cls");
     imprimeLinea('*');
     mostrarProductos(producto1,producto2,producto3,producto4,producto5,precio1,precio2,precio3,precio4,precio5,codigo1,codigo2,codigo3,codigo4,codigo5,totalProductos);
     imprimeLinea('*');
     if(totalProductos==0) cout<<"No hay ningún producto en la carta"<<endl;
     else{
          cout<<"Introduzca el código del producto que quiere eliminar"<<endl;
          cin>>codigoAux;
          system("cls");
          if(codigoAux==codigo1) cout<<"Se ha eliminado el producto de la cuenta"<<endl;
          if(codigoAux==codigo2) cout<<"Se ha eliminado el producto de la cuenta"<<endl;
          if(codigoAux==codigo3) cout<<"Se ha eliminado el producto de la cuenta"<<endl;
          if(codigoAux==codigo4) cout<<"Se ha eliminado el producto de la cuenta"<<endl;
          if(codigoAux==codigo5) cout<<"Se ha eliminado el producto de la cuenta"<<endl;
          Sleep(2000);
          system("cls");
          if(codigoAux==codigo1) cuenta=cuenta-precio1;
          if(codigoAux==codigo2) cuenta=cuenta-precio2;
          if(codigoAux==codigo3) cuenta=cuenta-precio3;
          if(codigoAux==codigo4) cuenta=cuenta-precio4;
          if(codigoAux==codigo5) cuenta=cuenta-precio5;
          cout<<"Cuenta: "<<cuenta<<" euros";
          Sleep(2000);
          }
}

void eliminarProductosCamareros(string &producto1,string &producto2,string &producto3,string &producto4,string &producto5,string &codigo1,string &codigo2,string &codigo3,string &codigo4,string &codigo5,string &codigoAux,double &precio1,double &precio2,double &precio3,double &precio4,double &precio5,int totalProductos,double cuenta){
     system("cls");
     imprimeLinea('*');
     mostrarProductos(producto1,producto2,producto3,producto4,producto5,precio1,precio2,precio3,precio4,precio5,codigo1,codigo2,codigo3,codigo4,codigo5,totalProductos);
     imprimeLinea('*');
     if(totalProductos==0) cout<<"No hay ningún producto en la carta"<<endl;
     else{
          cout<<"Introduzca el código del producto que quiere eliminar"<<endl;
          cin>>codigoAux;
          system("cls");
          if(codigoAux==codigo1) cout<<"Se ha eliminado el producto de la cuenta"<<endl;
          if(codigoAux==codigo2) cout<<"Se ha eliminado el producto de la cuenta"<<endl;
          if(codigoAux==codigo3) cout<<"Se ha eliminado el producto de la cuenta"<<endl;
          if(codigoAux==codigo4) cout<<"Se ha eliminado el producto de la cuenta"<<endl;
          if(codigoAux==codigo5) cout<<"Se ha eliminado el producto de la cuenta"<<endl;
          Sleep(2000);
          system("cls");
          if(codigoAux==codigo1) cuenta=cuenta-precio1;
          if(codigoAux==codigo2) cuenta=cuenta-precio2;
          if(codigoAux==codigo3) cuenta=cuenta-precio3;
          if(codigoAux==codigo4) cuenta=cuenta-precio4;
          if(codigoAux==codigo5) cuenta=cuenta-precio5;
          cout<<"Cuenta: "<<cuenta<<" euros";
          Sleep(2000);
          }
}

void mostrarCuenta(double cuenta){
     system("cls");
     cout<<"La cuenta es: "<<cuenta<<" euros";
     Sleep(2000);
}

void mostrarVuelta(double pago,double vuelta,double cuenta){
     system("cls");
     cout<<"¿Cuánto ha dado el cliente?"<<endl;
     cin>>pago;
     system("cls");
     while(pago<cuenta){
     cout<<"No es sufiente para pagar";
     cin>>pago;
     }
     vuelta=pago-cuenta;
     cout<<"La vuelta es: "<<vuelta<<" euros";
     Sleep(3000);
     cuenta=0;
     Sleep(2000);
}

void reiniciarCuenta(double cuenta){
     system("cls");
     cuenta=0;
     cout<<"La cuenta ha sido reinicida";
     Sleep(2000);
}

void cambiarClave(string &clave1,string &clave2,string &clave3,string &claveCamarero,string camareroAux,string camarero1,string camarero2,string camarero3){
     system("cls");
     if(camareroAux==camarero1){
                                   cout<<"Inserte su clave actual"<<endl;
                                   cin>>claveCamarero;
                                   system("cls");
                                   while(claveCamarero!=clave1){
                                                                cout<<"Clave incorrecta, insertela de nuevo"<<endl;
                                                                cin>>claveCamarero;
                                                                system("cls");
                                                                }
                                   cout<<"Inserte su nueva clave"<<endl;
                                   cin>>clave1;
                                   while (clave1.size()!=3){//la función size devuelve el tamaño de un string
                                                     cout<<"Clave no válida, inserte una clave de 3 caracteres"<<endl;
                                                     cin>>clave1;
                                                     }
                                   system("cls");
                                   cout<<"Se ha cambiado la clave con éxito"<<endl;
                                   }
     if(camareroAux==camarero2){
                                   cout<<"Inserte su clave actual"<<endl;
                                   cin>>claveCamarero;
                                   system("cls");
                                   while(claveCamarero!=clave2){
                                                                cout<<"Clave incorrecta, insertela de nuevo"<<endl;
                                                                cin>>claveCamarero;
                                                                system("cls");
                                                                }
                                   cout<<"Inserte su nueva clave"<<endl;
                                   cin>>clave2;
                                   while (clave2.size()!=3){//la función size devuelve el tamaño de un string
                                                     cout<<"Clave no válida, inserte una clave de 3 caracteres"<<endl;
                                                     cin>>clave2;
                                                     }
                                   system("cls");
                                   cout<<"Se ha cambiado la clave con éxito"<<endl;
                                   }
     if(camareroAux==camarero3){
                                   cout<<"Inserte su clave actual"<<endl;
                                   cin>>claveCamarero;
                                   system("cls");
                                   while(claveCamarero!=clave3){
                                                                cout<<"Clave incorrecta, insertela de nuevo"<<endl;
                                                                cin>>claveCamarero;
                                                                system("cls");
                                                                }
                                   cout<<"Inserte su nueva clave"<<endl;
                                   cin>>clave3;
                                   while (clave3.size()!=3){//la función size devuelve el tamaño de un string
                                                     cout<<"Clave no válida, inserte una clave de 3 caracteres"<<endl;
                                                     cin>>clave3;
                                                     }
                                   system("cls");
                                   cout<<"Se ha cambiado la clave con éxito"<<endl;
                                   }
                                   Sleep(3000);

}

void compruebaClave(int claveGerente1,int claveGerente2){
     while(claveGerente1!=claveGerente2){
     cout<<"La clave no es correcta, insertela de nuevo por favor"<<endl;
     cin>>claveGerente2;
     }
     }

void compruebaClaveCamarero(string clave1,string clave2,string clave3,string claveCamarero,string &camareroAux,string &camarero1,string &camarero2,string &camarero3){
     while(claveCamarero!=clave1 && claveCamarero!=clave2 && claveCamarero!=clave3){
     cout<<"La clave no es correcta, insertela de nuevo por favor"<<endl;
     cin>>claveCamarero;
     }
     if(claveCamarero==clave1)camareroAux=camarero1;
     if(claveCamarero==clave2)camareroAux=camarero2;
     if(claveCamarero==clave3)camareroAux=camarero3;
     }
