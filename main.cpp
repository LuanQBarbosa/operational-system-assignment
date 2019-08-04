#define QUANTUM 2

#include <iostream>
#include <fstream>
#include <queue>

#include "cpu.h"

int main( int argc, char** argv )
{
    std::ifstream file( argv[1],  std::ifstream::in );
    std::queue<Processo> processos1;
    std::queue<Processo> processos2;
    std::queue<Processo> processos3;
        
    int tEntrada, tPico;
    bool first = true;
    while ( file >> tEntrada >> tPico ) {
        Processo processo1( tEntrada, tPico );
        Processo processo2( tEntrada, tPico );
        Processo processo3( tEntrada, tPico );
        processos1.push( processo1 );
        processos2.push( processo2 );
        processos3.push( processo3 );
    }

    file.close( );

    CPU cpu1( 0, processos1, 0 );
    cpu1.executa( );
    cpu1.printaResultados( );

    CPU cpu2( 1, processos2, 2 );
    cpu2.executa( );
    cpu2.printaResultados( );

    CPU cpu3( 2, processos3, 2 );
    cpu3.executa( );
    cpu3.printaResultados( );
}