#ifndef ESCALONADOR_H
#define ESCALONADOR_H

#include <queue>

#include "processo.h"

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (Processo& lhs, Processo &rhs) const
  {
    if (reverse) return (lhs.getPico( ) < rhs.getPico( ));
    else return (lhs.getPico( ) > rhs.getPico( ));
  }
};

class Escalonador {
private:
    std::queue<Processo> FCFS;
    std::priority_queue<Processo,std::vector<Processo>,mycomparison> SJF;

    int modo;
    int quantum;
    int contador;

    int respostaTotal;
    int retornoTotal;
    int esperaTotal;
    int nProcessos;

public:
    Escalonador( int nModo, int nQuantum );

    void insereProcesso( Processo processo );
    bool temProcessos( );
    Processo proximoProcesso( );

    bool possuiQuantum( );
    void resetaContador( );
    bool incrementaContador( );

    void atualizaTempos( Processo processo );
    int getRespostaTotal( );
    int getRetornoTotal( );
    int getEsperaTotal( );
    void incrementaProcessos( );

    void printaResultados( ); 

};

#endif // ESCALONADOR_H