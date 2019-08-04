#include <iostream>

#include "escalonador.h"

Escalonador::Escalonador( int nModo, int nQuantum ) : modo( nModo ),
                                                      quantum( nQuantum )
{ 
    contador = 0;

    respostaTotal = 0;
    retornoTotal = 0;
    esperaTotal = 0;
    nProcessos = 0;
}

void Escalonador::insereProcesso( Processo processo )
{
    if ( modo == 2 ) {
        SJF.push( processo );
    } else {
        FCFS.push( processo );
    }    
}

bool Escalonador::temProcessos( )
{
    if ( modo == 2) {
        return !SJF.empty( );
    } else {
        return !FCFS.empty( );
    }
}

Processo Escalonador::proximoProcesso( )
{
    if ( modo == 2 ) {
        Processo retorno = SJF.top( );
        SJF.pop( );
        return retorno;
    } else {        
        Processo retorno = FCFS.front( );
        FCFS.pop( );
        return retorno;        
    }
}
    
bool Escalonador::possuiQuantum( )
{
    if ( modo == 1 ) {
        return true;
    } else {
        return false;
    }
}

void Escalonador::resetaContador( )
{
    contador = 0;
}

bool Escalonador::incrementaContador( )
{
    contador++;
    if ( contador == quantum ) {
        return true;
    }

    return false;
}

void Escalonador::atualizaTempos( Processo processo )
{
    respostaTotal += processo.getResposta( );
    retornoTotal += processo.getRetorno( );
    esperaTotal += processo.getEspera( );

    if ( modo == 1 )
        contador = 0;
}

int Escalonador::getRespostaTotal( )
{
    return respostaTotal;
}

int Escalonador::getRetornoTotal( )
{
    return retornoTotal;
}

int Escalonador::getEsperaTotal( )
{
    return esperaTotal;
}

void Escalonador::printaResultados( )
{
    if ( modo == 0 )
        std::cout << "FCFS: ";
    else if ( modo == 2 )
        std::cout << "SJF: ";
    else
        std::cout << "RR: ";

    float fRetorno = (float)retornoTotal/nProcessos;
    float fResposta = (float)respostaTotal/nProcessos;
    float fEspera = (float)esperaTotal/nProcessos;

    std::cout << fRetorno << " " << fResposta << " " << fEspera << std::endl;
}

void Escalonador::incrementaProcessos( )
{
    nProcessos++;
}