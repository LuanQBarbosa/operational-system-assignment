#define QUANTUM 2

#include <iostream>
#include <fstream>
#include <queue>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/stdc++.h>

#include "cpu.h"

char *parameters[64];

void split(char cmd[], char **params) {
    int i = 0, len = strlen(cmd);
    if(cmd[len-1] == '\n') {
        cmd[len-1] = '\0';
    }
    while(i < 5) {
        params[i] = strsep(&cmd, " ");
        if(params[i] == NULL) {
            break;
        }
        i++;
    }
}

int main( int argc, char** argv )
{
    std::ifstream file;
    file.open( argv[1] );
    std::queue<Processo> processos1;
    std::queue<Processo> processos2;
    std::queue<Processo> processos3;

    int tEntrada, tPico;
    while ( file >> tEntrada >> tPico ) {
        Processo processo1( tEntrada, tPico );
        Processo processo2( tEntrada, tPico );
        Processo processo3( tEntrada, tPico );
        processos1.push( processo1 );
        processos2.push( processo2 );
        processos3.push( processo3 );
    }

    file.close( );

    if ( !strcmp( argv[2], "0" ) ) {
        CPU cpu1( 0, processos1, 0 );
        cpu1.executa( );
        cpu1.printaResultados( );
    } else if ( !strcmp( argv[2], "1" ) ) {
        CPU cpu2( 2, processos2, 0 );
        cpu2.executa( );
        cpu2.printaResultados( );
    } else if ( !strcmp( argv[2], "2" ) ) {
        CPU cpu3( 1, processos3, QUANTUM );
        cpu3.executa( );
        cpu3.printaResultados( );
    }

    int status, counter;
    if ( !strcmp( argv[2], "0" ) ) {
        if ( fork( ) != 0 ) {
            waitpid( -1, &status, 0 );
            if( fork( ) != 0 ) {
                waitpid( -1, &status, 0 );
            } else {
                std::string caminho( "./cpu " + std::string(argv[1]) + " 2");
                char command[100];

                for ( int i = 0; i < sizeof( command ); i++ ) {
                    command[i] = caminho[i];                    
                }

                // char command[100] = "./cpu teste2.txt 2";
                split(command, parameters);
                execvp(command, parameters);
            }           
        } else {
            std::string caminho = std::string( "./cpu " + std::string(argv[1]) + " 1");
            char command[100];            

            int i;
            for ( i = 0; i < sizeof( command ); i++ ) {
                command[i] = caminho[i];
                std::cout << i;
            }

            // char command[100]  = "./cpu teste2.txt 1";
            split(command, parameters);
            execvp(command, parameters);
        }
    }
    
}
