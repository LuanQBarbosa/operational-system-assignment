#ifndef PROCESSO_H
#define PROCESSO_H

class Processo {
private:
    int tEntrada;
    int tPico;    

    bool primeiraVez;
    int tSaida;

    double tResposta;
    double tRetorno;
    double tEspera;

public:
    Processo( int entrada, int pico );
    Processo( );
    
    bool checaPrimeiraVez( );
    void setResposta( int time );
    void atualizaEspera( int time );
    void setRetorno( int time );

    void decrementaPico( );
    int getPico( );
    int getEntrada( );

    void atualizaSaida( int time );

    int getResposta( );
    int getRetorno( );
    int getEspera( );
};

#endif // PROCESS_H