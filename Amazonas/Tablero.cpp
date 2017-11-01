#include "Tablero.h"
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <list>
using namespace std;

Tablero::Tablero() {
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            this->tablero[i][j]='-';

    this->tablero[0][3]='A';
    this->tablero[0][6]='A';
    this->tablero[3][0]='A';
    this->tablero[3][9]='A';
    this->tablero[6][0]='R';
    this->tablero[6][9]='R';
    this->tablero[9][3]='R';
    this->tablero[9][6]='R';


    arregloAzul[0]=make_pair(0,3);
    arregloAzul[1]=make_pair(0,6);
    arregloAzul[2]=make_pair(3,0);
    arregloAzul[3]=make_pair(3,9);

    arregloRojo[0]=make_pair(6,0);
    arregloRojo[1]=make_pair(6,9);
    arregloRojo[2]=make_pair(9,3);
    arregloRojo[3]=make_pair(9,6);




}

void Tablero::mostrarTablero() {
    cout<<"    0 1 2 3 4 5 6 7 8 9 "<<endl;
    cout<<"    ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ";
    char Letra='A';
    for (int i=0; i<10; i++) {

        cout<<" "<<endl;
        cout<<Letra<<" | ";
        Letra++;
        for (int j=0; j<10; j++)
            cout << this->tablero[i][j] << " ";
    }
    cout<<" "<<endl;
    cout<<" "<<endl;
}

bool Tablero::moverPieza(int origenA,int origenB,int destinoA,int destinoB,int flechaA,int flechaB,char turno) {
    if ((origenA>=0) and (origenA<=9) and (origenB>=0) and (origenB<=9) and (destinoA>=0) and (destinoA<=9) and (destinoB>=0) and (destinoB<=9) and (flechaA>=0) and (flechaA<=9) and (flechaB>=0) and (flechaB<=9)) {
        //Destino=Origen                                                Destino ocupado                                 flecha ocupada                          Color jugador
        if (((this->tablero[destinoA][destinoB])==(this->tablero[origenA][origenB])) or (this->tablero[destinoA][destinoB]!='-') or (this->tablero[flechaA][flechaB]==turno) or (this->tablero[origenA][origenB]!=turno)) {
            return false; //costo invalido
        } else {              //movimiento horizontal                            movimiento vertical                        movimiento oblicuo
            if (((origenA==destinoA) and (origenB!=destinoB)) or ((origenA!=destinoA) and (origenB==destinoB)) or(abs(destinoA-origenA)==abs(destinoB-origenB))) {
                if (((flechaA==destinoA) and (flechaB!=destinoB)) or ((flechaA!=destinoA) and (flechaB==destinoB)) or(abs(destinoA-flechaA)==abs(destinoB-flechaB))) {
                    for (int x=origenB+1; x<destinoB; x++)
                        if (this->tablero[origenA][x]!='-')        //interseccion movimiento derecha
                            return false;
                    for (int x=origenB-1; x>destinoB; x--)
                        if (this->tablero[origenA][x]!='-')        //interseccion movimiento izquierda
                            return false;
                    for (int x=origenA+1; x<destinoA; x++)
                        if (this->tablero[x][origenB]!='-')       //interseccion movimiento abajo
                            return false;
                    for (int x=origenA-1; x>destinoA; x--)
                        if (this->tablero[x][origenB]!='-')        //interseccion movimiento arriba
                            return false;
                    for (int x=destinoB+1; x<flechaB; x++)
                        if (this->tablero[destinoA][x]!='-')       //interseccion movimiento derecha
                            return false;
                    for (int x=destinoB-1; x>flechaB; x--)
                        if (this->tablero[destinoA][x]!='-')        //interseccion movimiento izquierda
                            return false;
                    for (int x=destinoA+1; x<flechaA; x++)
                        if (this->tablero[x][destinoB]!='-')        //interseccion movimiento abajo
                            return false;
                    for (int x=destinoA-1; x>flechaA; x--)
                        if (this->tablero[x][destinoB]!='-')       //interseccion movimiento arriba
                            return false;;

                    return true;
                } else
                    return false;
            } else
                return false;
        }
    } else
        return false;
}

bool Tablero::sigueJugando(char turno){
    int ady=0;
    bool valor=true;
    for (int i=0;i<=9;i++)
        for (int j=0;j<=9;j++)
            if (this->tablero[i][j]==turno){
                if (verificaEntorno(i,j,turno,ady)==true)
                    return true;
                else{
                    ady=0;
                    valor=false;
                    }
            }
    return valor;
}

void Tablero::generarMovimientosValidos(char turno,list<estado>& movimientos) {
    estado aux;
    int i,j,reina;
    for (reina=0; reina<=3; reina++) {
        if (turno=='A') {
            aux.origenA=arregloAzul[reina].first;
            aux.origenB=arregloAzul[reina].second;
        } else {
            aux.origenA=arregloRojo[reina].first;
            aux.origenB=arregloRojo[reina].second;
        }
        i=aux.origenA;
        j=aux.origenB;
        while ((i<=9) and (this->tablero[i+1][j]=='-')) {
            i++;
            moverflecha(i,j,aux,movimientos);
        }
        i=aux.origenA;
        while ((i>=0) and (this->tablero[i-1][j]=='-')) {
            i--;
            moverflecha(i,j,aux,movimientos);
        }
        i=aux.origenA;
        while ((j<=9) and (this->tablero[i][j+1]=='-')) {
            j++;
            moverflecha(i,j,aux,movimientos);
        }
        j=aux.origenB;
        while ((j>=0) and (this->tablero[i][j-1]=='-')) {
            j--;
            moverflecha(i,j,aux,movimientos);
        }
        j=aux.origenB;
        while ((i>=0) and (j>=0) and (this->tablero[i-1][j-1]=='-')) {
            i--;
            j--;
            moverflecha(i,j,aux,movimientos);
        }
        i=aux.origenA;
        j=aux.origenB;
        while ((i<=9) and (j>=0) and (this->tablero[i+1][j-1]=='-')) {
            i++;
            j--;
            moverflecha(i,j,aux,movimientos);
        }
        i=aux.origenA;
        j=aux.origenB;
        while ((i>=0) and (j<=9) and (this->tablero[i-1][j+1]=='-')) {
            i--;
            j++;
            moverflecha(i,j,aux,movimientos);
        }
        i=aux.origenA;
        j=aux.origenB;
        while ((i<=9) and (j<=9) and (this->tablero[i+1][j+1]=='-')) {
            i++;
            j++;
            moverflecha(i,j,aux,movimientos);
        }
    }
}

void Tablero::moverflecha(int x,int y,estado aux,list<estado>& movimientos) {
    int i,j;
    i=x;
    j=y;
    while ((i<=9) and (this->tablero[i+1][j]=='-')) {
        i++;
        aux.destinoA=x;
        aux.destinoB=y;
        aux.flechaA=i;
        aux.flechaB=j;
        movimientos.push_back(aux);
    }
    i=aux.origenA;
    while ((i>=0) and (this->tablero[i-1][j]=='-')) {
        i--;
        aux.destinoA=x;
        aux.destinoB=y;
        aux.flechaA=i;
        aux.flechaB=j;
        movimientos.push_back(aux);
    }
    i=aux.origenA;
    while ((j<=9) and (this->tablero[i][j+1]=='-')) {
        j++;
        aux.destinoA=x;
        aux.destinoB=y;
        aux.flechaA=i;
        aux.flechaB=j;
        movimientos.push_back(aux);
    }
    j=aux.origenB;
    while ((j>=0) and (this->tablero[i][j-1]=='-')) {
        j--;
        aux.destinoA=x;
        aux.destinoB=y;
        aux.flechaA=i;
        aux.flechaB=j;
        movimientos.push_back(aux);
    }
    j=aux.origenB;
    while ((i>=0) and (j>=0) and (this->tablero[i-1][j-1]=='-')) {
        i--;
        j--;
        aux.destinoA=x;
        aux.destinoB=y;
        aux.flechaA=i;
        aux.flechaB=j;
        movimientos.push_back(aux);
    }
    i=aux.origenA;
    j=aux.origenB;
    while ((i<=9) and (j>=0) and (this->tablero[i+1][j-1]=='-')) {
        i++;
        j--;
        aux.destinoA=x;
        aux.destinoB=y;
        aux.flechaA=i;
        aux.flechaB=j;
        movimientos.push_back(aux);
    }
    i=aux.origenA;
    j=aux.origenB;
    while ((i>=0) and (j<=9) and (this->tablero[i-1][j+1]=='-')) {
        i--;
        j++;
        aux.destinoA=x;
        aux.destinoB=y;
        aux.flechaA=i;
        aux.flechaB=j;
        movimientos.push_back(aux);
    }
    i=aux.origenA;
    j=aux.origenB;
    while ((i<=9) and (j<=9) and (this->tablero[i+1][j+1]=='-')) {
        i++;
        j++;
        aux.destinoA=x;
        aux.destinoB=y;
        aux.flechaA=i;
        aux.flechaB=j;
        movimientos.push_back(aux);
    }
}

int Tablero::negaMax(int depth,int alpha, int beta, char turno,int tipoHeuristica,estado & movimiento) {
    int valorJugador;
    if ((!this->sigueJugando(turno)) or (depth==0)) {
        if (turno=='A')
            valorJugador=-1;
        else
            valorJugador=1;
        return (this->heuristicas(tipoHeuristica)) * valorJugador;
    } else {
        int maxx=INT_MIN;
        list <estado> movimientos;
        this->generarMovimientosValidos(turno,movimientos);
        list <estado>:: iterator it=movimientos.begin();
        cout<<"Cantidad de estados: "<<movimientos.size()<<endl;
        estado contrario;
        while(it!=movimientos.end()) {
            this->movimientoValido(it->origenA,it->origenB,it->destinoA,it->destinoB,it->flechaA,it->flechaB,turno);
            if (turno=='A')
                turno='R';
            else
                turno='A';
            int valor =-(negaMax(depth-1,-beta,-alpha,turno,tipoHeuristica,contrario));
            if (turno=='A')
                turno='R';
            else
                turno='A';
            this->deshacerUltimoMovimiento(it->origenA,it->origenB,it->destinoA,it->destinoB,it->flechaA,it->flechaB,turno);
            if (valor > maxx)
                maxx = valor;
            if (valor > alpha) {
                alpha = valor;
                movimiento=*it;
            }
            if (alpha >= beta)
                return alpha;
            it++;
        }
        return alpha;
    }
}

void Tablero::movimientoValido(int origenA,int origenB,int destinoA,int destinoB,int flechaA,int flechaB,char turno) {
    int i=0;
    if ((this->moverPieza(origenA,origenB,destinoA,destinoB,flechaA,flechaB,turno))){
        this->tablero[destinoA][destinoB]=turno;
        this->tablero[origenA][origenB]='-';
        this->tablero[flechaA][flechaB]='X';
        std::pair<int,int> pares;
        pares=make_pair(origenA,origenB);
        if (turno=='A'){
            while ((i<=3) and (pares!=arregloAzul[i]))
                i++;
            arregloAzul[i]=make_pair(destinoA,destinoB);
        } else {
            while ((i<=3) and (pares!=arregloRojo[i]))
                i++;
            arregloRojo[i]=make_pair(destinoA,destinoB);
        }
    }
}

void Tablero::deshacerUltimoMovimiento(int origenA,int origenB,int destinoA,int destinoB,int flechaA,int flechaB,char turno) {
    int i=0;
    this->tablero[flechaA][flechaB]='-';
    this->tablero[destinoA][destinoB]='-';
    this->tablero[origenA][origenB]=turno;
    std::pair<int,int> pares;
    pares=make_pair(destinoA,destinoB);
    if (turno=='A') {
        while ((i<=3) and (pares!=arregloAzul[i]))
            i++;
        arregloAzul[i]=make_pair(origenA,origenB);
    } else {
        while ((i<=3) and (pares!=arregloRojo[i]))
            i++;
        arregloRojo[i]=make_pair(origenA,origenB);
    }
}

int Tablero::heuristicas(int variable) {
    int debil=0;
    int ady=0;
    if (variable==1) {
        for (int i=0; i<=9; i++)
            for (int j=0; j<=9; j++)
                if (this->tablero[i][j]=='A') {
                    if (this->verificaEntorno(i,j,'A',ady)==true) {
                        if (debil<ady) {
                            debil=ady;

                        }
                    }
                }
        return debil;
    } if (variable==0)
        for (int i=0; i<=9; i++)
            for (int j=0; j<=9; j++)
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
