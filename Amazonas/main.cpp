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
        int origenB,destinoB,flechaB;
        cout<<"Ingrese coordenada origen [A-J,0-9]: "<<endl;
        cin>>OriX;
        cin>>origenB;
        int origenA = OriX - 65;
        /*cout<<"Ingrese coordenada destino[A-J,0-9]: "<<endl;
        cin>>DesX;
        cin>>destinoB;
        int destinoA = DesX - 65;
        cout<<"Ingrese coordenada flecha[A-J,0-9]: "<<endl;
        cin>>FleX;
        cin>>flechaB;
        int flechaA = FleX - 65;*/
        cout<<tablero.verificaEntorno(origenA,origenB,'A',0)<<endl;
        //cout<< tablero.moverPieza(origenA,origenB,destinoA,destinoB,flechaA,flechaB)<<endl;

        tablero.mostrarTablero();
        cin>>opcion;
    }
    return 0;
}

