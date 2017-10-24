#include "Tablero.h"
#include <iostream>
#include <stdlib.h>

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

void Tablero::mostrarTablero(){
cout<<"    0 1 2 3 4 5 6 7 8 9 "<<endl;
cout<<"    ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ";
char Letra='A';
for (int i=0;i<10;i++){

    cout<<" "<<endl;
cout<<Letra<<" | ";
    Letra++;
    for (int j=0;j<10;j++)
        cout << this->tablero[i][j] << " ";
        }
cout<<" "<<endl;
cout<<" "<<endl;
}

int Tablero::moverPieza(char origenA,int origenB,char destinoA,int destinoB,char flechaA,int flechaB){
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
                        //Destino=Origen                                                Destino ocupado                                 flecha ocupada                          Color jugador
if (((this->tablero[destinoA][destinoB])==(this->tablero[origenA][origenB])) or (this->tablero[destinoA][destinoB]!='-') or (this->tablero[flechaA][flechaB]=='R') or (this->tablero[origenA][origenB]!='A')){
    cout<<"Movimiento invalido"<<endl;
    return -1; //costo invalido
}
else {                //movimiento horizontal                            movimiento vertical                        movimiento oblicuo
        if (((origenA==destinoA) and (origenB!=destinoB)) or ((origenA!=destinoA) and (origenB==destinoB)) or(abs(destinoA-origenA)==abs(destinoB-origenB))){

                for (int x=origenB+1;x<destinoB;x++)
                    if (this->tablero[origenA][x]!='-'){        //interseccion movimiento derecha
                        cout<<"entro"<<endl;
                        return -3;
                }
                 for (int x=origenB-1;x>destinoB;x--)
                    if (this->tablero[origenA][x]!='-'){        //interseccion movimiento izquierda
                        cout<<"entro"<<endl;
                        return -3;
                }

                 for (int x=origenA+1;x<destinoA;x++)
                    if (this->tablero[x][origenB]!='-'){        //interseccion movimiento abajo
                        cout<<"entro"<<endl;
                        return -3;

                }
                 for (int x=origenA-1;x>destinoA;x--)
                    if (this->tablero[x][origenB]!='-'){        //interseccion movimiento arriba
                        cout<<"entro"<<endl;
                        return -3;
                }

            this->tablero[destinoA][destinoB]=this->tablero[origenA][origenB];
            this->tablero[origenA][origenB]='-';
            this->tablero[flechaA][flechaB]='X';
        return 3; ///Coste movimiento
        }
        else{
            cout<<"Movimiento invalido segundo tipo"<<endl;
            return -2;
        }
    }
}

//bool Tablero::sigueJugando(){


unsigned int Tablero::verificaEntorno(int origenA, int origenB, char turno){  //bool, agregar int % numero de movimientos disponibles
    int acum=0;
    for (int i=origenA-1;i<=origenA+1;i++)
        for (int j=origenB-1;j<=origenB+1; j++){
            if (((i>=0) and (i<=9)) and ((j>=0) and (j<=9)))
                if ((this->tablero[i][j]!=turno /* A o R */ ) and (this->tablero[i][j]!='-')){ ///opciones que aun me dejan mover
                    acum++; ///acumulo los caminos cerrados

            }
    }

    return acum;

}

/*int Tablero::AislaReinas(Tablero & tablero){


}
*/
