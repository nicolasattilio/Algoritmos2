#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
class Tablero {
public:
        Tablero();
        int moverPieza(Tablero tablero,char origenA,int origenB,char destinoA,int destinoB,char flechaA,int flechaB);
        void mostrarTablero(Tablero tablero);

private:
        char tablero[10][10];


};
#endif // TABLERO_H_INCLUDED
