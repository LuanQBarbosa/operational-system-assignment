#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include <iostream>
#include <stdlib.h>

#include "cpu.h"

CPU::CPU( int modo, std::queue<Processo> mProcessos, int quantum ) : processos( mProcessos ),
                                                                     executando ( false ),
                                                                     escalonador( Escalonador( modo, quantum ) )
{ }

void CPU::executa( )
{
    while ( !processos.empty( ) && processos.front( ).getEntrada( ) == 0 ) {
            escalonador.insereProcesso( processos.front( ) );
            escalonador.incrementaProcessos( );
            processos.pop( );            
    }

    while ( !processos.empty( ) || executando || escalonador.temProcessos( ) ) {
        if ( !executando && escalonador.temProcessos( ) ) {
            processoAtual = escalonador.proximoProcesso( );
            executando = true;
            if ( processoAtual.checaPrimeiraVez( ) ) {
                processoAtual.setResposta( tempoAtual );
            }

            processoAtual.atualizaEspera( tempoAtual );
        }

        tempoAtual++;
        
        while ( !processos.empty( ) && processos.front( ).getEntrada( ) == tempoAtual ) {
            escalonador.insereProcesso( processos.front( ) );
            escalonador.incrementaProcessos( );
            processos.pop( );            
        }

        if ( executando ) {
            processoAtual.decrementaPico( );
            if ( processoAtual.getPico( ) == 0 ) {
                processoAtual.setRetorno( tempoAtual );
                escalonador.atualizaTempos( processoAtual );
                executando = false;
            } else if ( escalonador.possuiQuantum( ) && escalonador.incrementaContador( ) ) {                
                processoAtual.atualizaSaida( tempoAtual );
                escalonador.insereProcesso( processoAtual );
                executando = false;

                escalonador.resetaContador( );
            }
        }
    }
}

void CPU::printaResultados( )
{
    escalonador.printaResultados( );
}