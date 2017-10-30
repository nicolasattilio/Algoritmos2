#include <iostream>
#include "Tablero.h"
#include <limits.h>


using namespace std;


int main()
{
    Tablero tablero;
    tablero.mostrarTablero();
    char turno='A';
    int depth;
    int alpha=INT_MIN;
    int beta=INT_MAX;
    int heuristicas;
    cout<<"Ingrese heuristica[0,1]: ";
    cin>>heuristicas;
    cout<<endl;
    cout<<"Ingrese Profundidad[0,10]: ";
    cin>>depth;
    cout<<endl;
    char OriX,DesX,FleX;
    int origenB,destinoB,flechaB;
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
        tablero.movimientoValido(origenA,origenB,destinoA,destinoB,flechaA,flechaB,turno,heuristicas);
        //cout<<tablero.negaMax(depth,alpha,beta,turno,heuristicas);
        tablero.mostrarTablero();
        }
    return 0;
}
