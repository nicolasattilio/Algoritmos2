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

int Tablero::moverPieza(Tablero tablero,char origenA,int origenB,char destinoA,int destinoB,char flechaA,int flechaB){
    switch (origenA) {
    case 'A':
        origenA=0;
        break;
     case 'B':
        origenA=1;
        break;
     case 'C':
        origenA=2;
        break;
     case 'D':
        origenA=3;
        break;
     case 'E':
        origenA=4;
        break;
     case 'F':
        origenA=5;
        break;
     case 'G':
        origenA=6;
        break;
     case 'H':
        origenA=7;
        break;
     case 'I':
        origenA=8;
        break;
     case 'J':
        origenA=9;
        break;
    }

    switch (destinoA) {
    case 'A':
        destinoA=0;
        break;
     case 'B':
        destinoA=1;
        break;
     case 'C':
        destinoA=2;
        break;
     case 'D':
        destinoA=3;
        break;
     case 'E':
        destinoA=4;
        break;
     case 'F':
        destinoA=5;
        break;
     case 'G':
        destinoA=6;
        break;
     case 'H':
        destinoA=7;
        break;
     case 'I':
        destinoA=8;
        break;
     case 'J':
        destinoA=9;
        break;
    }

    switch (flechaA) {

    case 'A':
        flechaA=0;
        break;
     case 'B':
        flechaA=1;
        break;
     case 'C':
        flechaA=2;
        break;
     case 'D':
        flechaA=3;
        break;
     case 'E':
        flechaA=4;
        break;
     case 'F':
        flechaA=5;
        break;
     case 'G':
        flechaA=6;
        break;
     case 'H':
        flechaA=7;
        break;
     case 'I':
        flechaA=8;
        break;
     case 'J':
        flechaA=9;
        break;
    }
this->tablero[destinoA][destinoB]=this->tablero[origenA][origenB];
this->tablero[origenA][origenB]='-';
this->tablero[flechaA][flechaB]='X';

return 3; ///Coste movimiento y desplazamientos nulos
}


/*int Tablero::AislaReinas(Tablero & tablero){


}
*/
