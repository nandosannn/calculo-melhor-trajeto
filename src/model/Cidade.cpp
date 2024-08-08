#include "../../include/model/Cidade.hpp"

Cidade::Cidade(int id, string nome){
    this->id = id;
    this->nome=nome;
}
Cidade::~Cidade(){

}
int Cidade::getId(){
    return id;
}
string Cidade::getNome(){
    return nome;
}
void Cidade::setId(int id){
    this->id=id;
}
void Cidade::setString(string nome){
    this->nome=nome;
}