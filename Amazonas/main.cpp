#include <iostream>
#include "Tablero.h"
#include <limits.h>

using namespace std;

int NegaMax(Tablero tablero,int depth,int alpha, int beta, char turno){
    if ((tablero.sigueJugando(turno)==false)or depth==0){
        if (turno=='A')
            int valorJugador=-1;
        else
            int valorJugador=1;
        return /*evaluación_heuristica(T) **/ valorJugador;
        }
    else
        int maxx=INT_MIN;
        ///Para cada jugada válida V del jugador J en el tablero T  ARMAR UN STRUCT LISTA CON TODOS LOS MOVIMIENTOS POSIBLES
        if (tablero.moverPieza(origenA,origenB,destinoA,destinoB,flechaA,flechaB,turno)>0)
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
}



int main()
{
    Tablero tablero;
    tablero.mostrarTablero();
    char turno='A';
    int depth;
    int alpha=INT_MIN;
    int beta=INT_MAX;
    char euristica;
    cout<<"Ingrese Euristica: ";
    cin>>euristica;
    cout<<endl;
    cout<<"Ingrese Profundidad: ";
    cin>>depth;
    cout<<endl;

     while (tablero.sigueJugando(turno)==true){
        char OriX,DesX,FleX;
        int origenB,destinoB,flechaB;
        cout<<"Ingrese coordenada origen [A-J,0-9]: "<<endl;
        cin>>OriX;
        cin>>origenB;
        int origenA = OriX - 65;
        cout<<"Ingrese coordenada destino[A-J,0-9]: "<<endl;
        cin>>DesX;
        cin>>destinoB;
        int destinoA = DesX - 65;
        cout<<"Ingrese coordenada flecha[A-J,0-9]: "<<endl;
        cin>>FleX;
        cin>>flechaB;
        int flechaA = FleX - 65;
        cout<<tablero.moverPieza(origenA,origenB,destinoA,destinoB,flechaA,flechaB,turno)<<endl;
        tablero.mostrarTablero();
        if (turno=='A')
            turno='R';
        else
            turno='A';
    }
    return 0;
}

