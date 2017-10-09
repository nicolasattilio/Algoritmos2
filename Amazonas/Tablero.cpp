#include "Tablero.h"
#include <iostream>

using namespace std;

Tablero::Tablero(){
for (int i=0;i<10;i++)
    for (int j=0;j<10;j++)
        this->tablero[i][j]='-';

this->tablero[0][3]='A';
this->tablero[0][6]='A';
this->tablero[3][0]='A';
this->tablero[3][9]='A';
this->tablero[6][0]='R';
this->tablero[6][9]='R';
this->tablero[9][3]='R';
this->tablero[9][6]='R';
}

void Tablero::mostrarTablero(Tablero tablero){
for (int i=0;i<10;i++){
    cout<<" "<<endl;

    for (int j=0;j<10;j++)
        cout << this->tablero[i][j] << " ";
        }
cout<<" "<<endl;
}

void Tablero::moverPieza(Tablero tablero,int origenA,int origenB,int destinoA,int destinoB,int flechaA,int flechaB){
this->tablero[destinoA][destinoB]=this->tablero[origenA][origenB];
this->tablero[origenA][origenB]='-';
this->tablero[flechaA][flechaB]='X';
}
