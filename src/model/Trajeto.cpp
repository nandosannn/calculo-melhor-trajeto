#include "../../include/model/Trajeto.hpp"

Trajeto::Trajeto(Cidade* cidadeOrigem, Cidade* cidadeDestino, int distancia, int tipoTransporte){
    this->cidadeOrigem = cidadeOrigem;
    this->cidadeDestino = cidadeDestino;
    this->distancia = distancia;
    this->tipoTransporte = tipoTransporte;
}

Trajeto:: ~Trajeto(){

}

Cidade* Trajeto::getCidadeOrigem(){
    return cidadeOrigem;
}

Cidade* Trajeto::getCidadeDestino()
{
    return cidadeDestino;
}

int Trajeto::getDistancia()
{
    return distancia;
}

int Trajeto::getTipoTransporte(){
    return tipoTransporte;
}

void Trajeto::setCidadeOrigem(Cidade* cidadeOrigem){
    this->cidadeOrigem = cidadeOrigem;
}
void Trajeto::setCidadeDestino(Cidade* cidadeDestino){
    this->cidadeDestino=cidadeDestino;
}
void Trajeto::setDistancia(int distancia){
    this->distancia=distancia;
}
void Trajeto::setTipoTransporte(int tipoTransporte){
    this->tipoTransporte = tipoTransporte;
}
