#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include <list>
using namespace std;

struct estado {
    int origenA;
    int origenB;
    int destinoA;
    int destinoB;
    int flechaA;
    int flechaB;
};

class Tablero {
public:
    Tablero();
    void mostrarTablero();
    bool moverPieza(int origenA,int origenB,int destinoA,int destinoB,int flechaA,int flechaB,char turno);
    bool sigueJugando(char turno);
    void generarMovimientosValidos(char turno,list<estado>& movimientos);
    void moverflecha(int x,int y,estado aux,list<estado>& movimientos);
    int negaMax(int depth,int alpha, int beta, char turno,int tipoHeuristica,estado & movimiento,int & tamanio);
    void movimientoValido(int origenA,int origenB,int destinoA,int destinoB,int flechaA,int flechaB,char turno);
    void deshacerUltimoMovimiento(int origenA,int origenB,int destinoA,int destinoB,int flechaA,int flechaB,char turno);
    int heuristicas(int variable);
    bool verificaEntorno(int origenA, int origenB, char turno,int & ady);
private:

    char tablero[10][10];
    estado coordenadas;
    pair<int,int> arregloAzul[4];
    pair<int,int> arregloRojo[4];

};
#endif // TABLERO_H_INCLUDED
