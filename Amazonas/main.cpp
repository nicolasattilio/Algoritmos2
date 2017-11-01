#include <iostream>
#include "Tablero.h"
#include <limits.h>


using namespace std;


int main() {
    Tablero tablero;

    char turno='A';
    int depth;
    int alpha=INT_MIN;
    int beta=INT_MAX;
    int heuristicas;
    estado movimiento;
    cout<<"Ingrese heuristica[0,1]: ";
    cin>>heuristicas;
    cout<<endl;
    cout<<"Ingrese Profundidad[1,10]: ";
    cin>>depth;
    cout<<endl;
    char OriX,DesX,FleX;
    int origenB,destinoB,flechaB;
    tablero.mostrarTablero();
       while (tablero.sigueJugando(turno)==true){

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
        tablero.movimientoValido(origenA,origenB,destinoA,destinoB,flechaA,flechaB,'A');
        cout<<"puntaje: "<<tablero.negaMax(depth,alpha,beta,'R',heuristicas,movimiento)<<endl;
        tablero.movimientoValido(movimiento.origenA,movimiento.origenB,movimiento.destinoA,movimiento.destinoB,movimiento.flechaA,movimiento.flechaB,'R');
        tablero.mostrarTablero();
}
    return 0;
}
