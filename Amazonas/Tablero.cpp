#include "Tablero.h"
#include <iostream>
#include <stdlib.h>
#include <limits.h>

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

int Tablero::moverPieza(int origenA,int origenB,int destinoA,int destinoB,int flechaA,int flechaB,char turno){
if ((origenA>=0) and (origenA<=9) and (origenB>=0) and (origenB<=9) and (destinoA>=0) and (destinoA<=9) and (destinoB>=0) and (destinoB<=9) and (flechaA>=0) and (flechaA<=9) and (flechaB>=0) and (flechaB<=9)){
                   //Destino=Origen                                                Destino ocupado                                 flecha ocupada                          Color jugador
    if (((this->tablero[destinoA][destinoB])==(this->tablero[origenA][origenB])) or (this->tablero[destinoA][destinoB]!='-') or (this->tablero[flechaA][flechaB]==turno) or (this->tablero[origenA][origenB]!=turno)){
        cout<<"Movimiento invalido"<<endl;
        return -1; //costo invalido
    }
    else {                //movimiento horizontal                            movimiento vertical                        movimiento oblicuo
            if (((origenA==destinoA) and (origenB!=destinoB)) or ((origenA!=destinoA) and (origenB==destinoB)) or(abs(destinoA-origenA)==abs(destinoB-origenB))){
                    if (((flechaA==destinoA) and (flechaB!=destinoB)) or ((flechaA!=destinoA) and (flechaB==destinoB)) or(abs(destinoA-flechaA)==abs(destinoB-flechaB))){
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

                     for (int x=destinoB+1;x<flechaB;x++)
                        if (this->tablero[destinoA][x]!='-'){        //interseccion movimiento derecha
                            cout<<"entro"<<endl;
                            return -3;
                    }
                     for (int x=destinoB-1;x>flechaB;x--)
                        if (this->tablero[destinoA][x]!='-'){        //interseccion movimiento izquierda
                            cout<<"entro"<<endl;
                            return -3;
                    }
                    for (int x=destinoA+1;x<flechaA;x++)
                        if (this->tablero[x][destinoB]!='-'){        //interseccion movimiento abajo
                            cout<<"entro"<<endl;
                            return -3;
                    }
                     for (int x=destinoA-1;x>flechaA;x--)
                        if (this->tablero[x][destinoB]!='-'){        //interseccion movimiento arriba
                            cout<<"entro"<<endl;
                            return -3;
                    }

                this->tablero[destinoA][destinoB]=this->tablero[origenA][origenB];
                this->tablero[origenA][origenB]='-';
                this->tablero[flechaA][flechaB]='X';
            return 3; ///Coste movimiento
            }
            else return -2;
            }
            else{
                cout<<"Movimiento invalido segundo tipo"<<endl;
                return -2;
            }
        }
        }
    else
        return 0;
}

bool Tablero::sigueJugando(char turno){
    int ady=0;
    bool valor=true;
    for (int i=0;i<=9;i++)
        for (int j=0;j<=9;j++)
            if (this->tablero[i][j]==turno)
                if (verificaEntorno(i,j,turno,ady)==true)
                    return true;
                else
                    valor=false;
    return valor;

}

/*int Tablero::NegaMax(int depth,int alpha, int beta, char turno,int euristicas){
    if ((this->sigueJugando(turno)==false) or (depth==0)){
        return (this->euristicas(euristicas)) /** valorJugador**//*;
        }
    else
        int maxx=INT_MIN;
        ///Para cada jugada válida V del jugador J en el tablero T  ARMAR UN STRUCT LISTA CON TODOS LOS MOVIMIENTOS POSIBLES
        if (this->moverPieza(origenA,origenB,destinoA,destinoB,flechaA,flechaB,turno)>0)
            ///Generar el tablero T' resultante al realizar V
            ///Asignar valor =-NegaMax(T', depth-1, -beta, -alpha, J.adversario())
            if (turno=='A')
                turno='R';
            else
                turno='A';
            valor =-NegaMax(tablero, depth-1,-beta,-alpha,turno);
            Si (valor > maxx)
                 maxx = valor;
            Si (valor > alpha)
                 alpha = valor;
            Si (alpha >= beta)
                return alpha;
    return alpha;
}*/



int Tablero::euristicas(int variable){
    int debil=0;
    int ady=0;
    if (variable=1){
        int coordx,coordy;
        for (int i=0;i<=9;i++)
            for (int j=0;j<=9;j++)
                if (this->tablero[i][j]=='A'){
                    if (this->verificaEntorno(i,j,'A',ady)==true){
                        if (debil<ady){
                            debil=ady;

                        }
                    }
                }
        return debil;
        }
    else
        for (int i=0;i<=9;i++)
            for (int j=0;j<=9;j++)
                if (this->tablero[i][j]=='A')
                    return ady+1;
}


 bool Tablero::verificaEntorno(int origenA, int origenB, char turno,int & ady){
    if ((origenA>0) and (origenA<9) and (origenB>0) and (origenB<9)){
        for (int i=origenA-1;i<=origenA+1;i++)
            for (int j=origenB-1;j<=origenB+1; j++)
                    if ((this->tablero[i][j]!=turno /* A o R */ ) and (this->tablero[i][j]!='-')) ///opciones que aun me dejan mover
                        ady++; ///acumulo los caminos cerrados
    if (ady==8)
        return false;
    else
        return true;
    }
    else{
        if (origenA==0){
            if (origenB==0){
                for (int i=origenA;i<=origenA+1;i++)
                    for (int j=origenB;j<=origenB+1; j++)
                        if ((this->tablero[i][j]!=turno /* A o R */ ) and (this->tablero[i][j]!='-'))
                         ady++;
            if (ady==3)
                return false;
            else
                return true;
            }
            if (origenB==9){
                for (int i=origenA;i<=origenA+1;i++)
                    for (int j=origenB-1;j<=origenB; j++)
                        if ((this->tablero[i][j]!=turno /* A o R */ ) and (this->tablero[i][j]!='-'))
                         ady++;
            if (ady==3)
                return false;
            else
                return true;
            }
            if (origenB>0 and origenB<9){
                for (int i=origenA;i<=origenA+1;i++)
                    for (int j=origenB-1;j<=origenB+1; j++)
                        if ((this->tablero[i][j]!=turno /* A o R */ ) and (this->tablero[i][j]!='-'))
                         ady++;
            if (ady==5)
                return false;
            else
                return true;
            }
        }

        if (origenA==9){
            if (origenB==0){
                for (int i=origenA-1;i<=origenA;i++)
                    for (int j=origenB;j<=origenB+1; j++)
                        if ((this->tablero[i][j]!=turno /* A o R */ ) and (this->tablero[i][j]!='-'))
                         ady++;
            if (ady==3)
                return false;
            else
                return true;
            }
            if (origenB==9){
                 for (int i=origenA-1;i<=origenA;i++)
                    for (int j=origenB-1;j<=origenB; j++)
                        if ((this->tablero[i][j]!=turno /* A o R */ ) and (this->tablero[i][j]!='-'))
                         ady++;
            if (ady==3)
                return false;
            else
                return true;
            }
            if (origenB>0 and origenB<9){
                 for (int i=origenA-1;i<=origenA;i++)
                    for (int j=origenB-1;j<=origenB+1; j++)
                        if ((this->tablero[i][j]!=turno /* A o R */ ) and (this->tablero[i][j]!='-'))
                         ady++;
            if (ady==5)
                return false;
            else
                return true;
            }

        }
        if (origenA>0 and origenA<9){
            if (origenB==0){
                for (int i=origenA-1;i<=origenA+1;i++)
                    for (int j=origenB;j<=origenB+1; j++)
                        if ((this->tablero[i][j]!=turno /* A o R */ ) and (this->tablero[i][j]!='-'))
                         ady++;
            if (ady==5)
                return false;
            else
                return true;
            }
            if (origenB==9){
                for (int i=origenA-1;i<=origenA+1;i++)
                    for (int j=origenB-1;j<=origenB; j++)
                    if ((this->tablero[i][j]!=turno /* A o R */ ) and (this->tablero[i][j]!='-'))
                         ady++;
            if (ady==5)
                return false;
            else
                return true;
            }
        }
    }


}

/*int Tablero::AislaReinas(Tablero & tablero){


}
*/
