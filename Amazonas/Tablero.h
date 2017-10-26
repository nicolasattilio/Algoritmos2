#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
class Tablero {
public:
        Tablero();
        int moverPieza(int origenA,int origenB,int destinoA,int destinoB,int flechaA,int flechaB,char turno);
        void mostrarTablero();
        bool sigueJugando(char turno);
        bool verificaEntorno(int origenA, int origenB, char turno,int & ady);
        int euristicas(int variable);
        int NegaMax(int depth,int alpha, int beta, char turno,int euristicas);

private:
        char tablero[10][10];


};
#endif // TABLERO_H_INCLUDED
