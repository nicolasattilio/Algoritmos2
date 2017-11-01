#include <iostream>
#include "Tablero.h"
#include <limits.h>
#include <stdlib.h>

using namespace std;


int main() {
    Tablero tablero;

    int depth;
    int alpha=INT_MIN;
    int beta=INT_MAX;
    int heuristicas;
    int tamanio=0;
    estado movimiento;
    int puntaje=0;
    cout<<"Ingrese heuristica[0,1]: ";
    cin>>heuristicas;
    cout<<endl;
    cout<<"Ingrese Profundidad[1,10]: ";
    cin>>depth;
    cout<<endl;
    char OriX,DesX,FleX;
    int origenB,destinoB,flechaB;
    system("cls");
    tablero.mostrarTablero();
    while (tablero.sigueJugando('A')and tablero.sigueJugando('R') ) {
        cout<<"Ingrese coordenada origen [A-J,0-9]: "<<endl;
        cin>>OriX;
        cin>>origenB;
        int origenA = OriX - 65;
        cout<<"Ingrese coordenada destino[A-J,0-9]: "<<endl;
        cin>>DesX;
        cin>>destinoB;
        int destinoA = DesX - 65;
        cout<<"Ingrese coordenada flecha[A-J,0-9]: "<<endl;
        cin>>FleX;
        cin>>flechaB;
        int flechaA = FleX - 65;
        if (tablero.moverPieza(origenA,origenB,destinoA,destinoB,flechaA,flechaB,'A')) {
            system("cls");
            tablero.movimientoValido(origenA,origenB,destinoA,destinoB,flechaA,flechaB,'A');
            puntaje=puntaje+tablero.negaMax(depth,alpha,beta,'R',heuristicas,movimiento,tamanio);
            tablero.movimientoValido(movimiento.origenA,movimiento.origenB,movimiento.destinoA,movimiento.destinoB,movimiento.flechaA,movimiento.flechaB,'R');
            tablero.mostrarTablero();
            cout<<"Anterior movimiento: "<<OriX<<origenB<<" "<<DesX<<destinoB<<" "<<FleX<<flechaB<<endl;
            cout<<"Puntaje total: "<<puntaje<<endl;
            cout<<"Cantidad de estados: "<<tamanio<<endl;
            char rivalOrigenA=movimiento.origenA+65;
            char rivalDestinoA=movimiento.destinoA+65;
            char rivalFlechaA=movimiento.flechaA+65;
            cout<<"Movimiento Rival: "<<rivalOrigenA<<movimiento.origenB<<" "<<rivalDestinoA<<movimiento.destinoB<<" "<<rivalFlechaA<<movimiento.flechaB<<endl;

        } else {
            system("cls");
            tablero.mostrarTablero();
            cout<<"Reintente coordenadas"<<endl;
        }
    }
    if (!tablero.sigueJugando('R'))
        cout<<"GANASTE!!    ---   Y tu puntaje fue: "<<puntaje<<endl;
    else
        cout<<"Perdiste, suerte para la proxima!!"<<endl;
    return 0;
}
