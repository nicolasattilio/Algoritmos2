#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
class Tablero {
public:
        Tablero();
        void moverPieza(Tablero tablero,int origenA,int origenB,int destinoA,int destinoB,int flechaA,int flechaB);
        void mostrarTablero(Tablero tablero);
private:
        char tablero[10][10];


};
#endif // TABLERO_H_INCLUDED
