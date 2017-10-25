#include <iostream>
#include "Tablero.h"

using namespace std;

/*int NegaMax(Tablero tablero,int depth,int alpha, int beta, Jugador J){
if tablero
}*/



int main()
{
    Tablero tablero;
    tablero.mostrarTablero();
    int opcion;
    cout<<"ingrese opcion ";
    cin>>opcion;
     while (opcion!=1) {
        char OriX,DesX,FleX;
        int OriY,DesY,FleY;
        cout<<"Ingrese coordenada origen [A-J,0-9]: "<<endl;
        cin>>OriX;
        cin>>OriY;
        /*cout<<"Ingrese coordenada destino[A-J,0-9]: "<<endl;
        cin>>DesX;
        cin>>DesY;
        cout<<"Ingrese coordenada flecha[A-J,0-9]: "<<endl;
        cin>>FleX;
        cin>>FleY;*/
        cout<<tablero.verificaEntorno(OriX,OriY,'A',0)<<endl;
        //cout<< tablero.moverPieza(OriX,OriY,DesX,DesY,FleX,FleY)<<endl;
        int a = DesX - 64;
        tablero.mostrarTablero();
        cin>>opcion;
    }
    return 0;
}

