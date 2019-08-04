#include "processo.h"

Processo::Processo( int entrada, int pico ) : tEntrada( entrada ),
                                              tSaida( entrada ),
                                              tPico( pico ),
                                              primeiraVez( true )
{ }

Processo::Processo( )
{ }

void Processo::setResposta( int time )
{
    tResposta = time - tEntrada;
    primeiraVez = false;
}

bool Processo::checaPrimeiraVez( )
{
    return primeiraVez;
}

void Processo::atualizaEspera( int time )
{
    if ( time >= tSaida )
        tEspera += time - tSaida;
}

void Processo::setRetorno( int time )
{
    tRetorno = time - tEntrada;
}

void Processo::decrementaPico( )
{
    tPico--;
}

int Processo::getPico( )
{
    return tPico;
}

int Processo::getEntrada( )
{
    return tEntrada;
}

void Processo::atualizaSaida( int time )
{
    tSaida = time;
}

int Processo::getResposta( )
{
    return tResposta;
}

int Processo::getRetorno( )
{
    return tRetorno;
}

int Processo::getEspera( )
{
    return tEspera;
}