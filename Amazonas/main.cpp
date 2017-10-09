#include <iostream>
#include "Tablero.h"

using namespace std;

/*int NegaMax(Tablero tablero,int depth,int alpha, int beta, Jugador J){
if tablero
}*/

int main()
{
    Tablero tablero;
    //tablero.mostrarTablero(tablero);
    tablero.moverPieza(tablero,0,3,5,5,5,6);
    tablero.mostrarTablero(tablero);
    return 0;
}
