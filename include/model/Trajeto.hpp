#ifndef TRAJETO_HPP
#define TRAJETO_HPP

#include "Cidade.hpp"
#include <iostream>
using namespace std;


class Trajeto
{
private:
    Cidade* cidadeOrigem;
    Cidade* cidadeDestino;
    int distancia;
    int tipoTransporte;


public:
    Trajeto(Cidade* cidadeOrigem, Cidade* cidadeDestino, int distancia, int tipoTransporte);
    ~Trajeto();
    
    Cidade* getCidadeOrigem();
    Cidade* getCidadeDestino();
    int getDistancia();
    int getTipoTransporte();

    void setCidadeOrigem(Cidade* cidadeOrigem);
    void setCidadeDestino(Cidade* cidadeDestino);
    void setDistancia(int distancia);
    void setTipoTransporte(int tipoTransporte);
};


#endif