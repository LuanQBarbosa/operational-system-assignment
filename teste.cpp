#include <iostream>
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
    if (reverse) return (lhs.getPico( ) > rhs.getPico( ));
    else return (lhs.getPico( ) < rhs.getPico( ));
  }
};

int main( )
{
    std::priority_queue<Processo,std::vector<Processo>,mycomparison> teste (mycomparison(true));
    Processo processo1( 12, 5 );
    Processo processo2( 10, 2 );
    teste.push( processo1 );
    teste.push( processo2 );

    Processo prioridade = teste.top( );
    std::cout << prioridade.getEntrada( ) << std::endl;
}

