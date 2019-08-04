#ifndef CPU_H
#define CPU_H

#include <queue>

#include "escalonador.h"
#include "processo.h"

class CPU {
private:
    Escalonador escalonador;
    Processo processoAtual;
    volatile bool executando;
    volatile int tempoAtual;

    std::queue<Processo> processos;

public:
    CPU( int modo, std::queue<Processo> nProcessos, int quantum=0 );

    void executa( );
    void printaResultados( );

};

#endif // CPU_H