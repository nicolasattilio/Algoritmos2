#include <iostream>
#include "Tablero.h"

using namespace std;

/*int NegaMax(Tablero tablero,int depth,int alpha, int beta, Jugador J){
if tablero
}*/



int main()
{
    char OriX,DesX,FleX;
    int OriY,DesY,FleY;
    cin>>OriX;
    cin>>OriY;
    cin>>DesX;
    cin>>DesY;
    cin>>FleX;
    cin>>FleY;
    Tablero tablero;
    tablero.mostrarTablero(tablero);
    cout<< tablero.moverPieza(tablero,OriX,OriY,DesX,DesY,FleX,FleY);
    tablero.mostrarTablero(tablero);
    return 0;
}

