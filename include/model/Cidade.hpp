#ifndef CIDADE_HPP
#define CIDADE_HPP

#include <iostream>

using namespace std;

class Cidade
{
private:
    int id;
    string nome;
public:
    Cidade(int id, string nome);
    ~Cidade();
    int getId();
    string getNome();
    void setId(int id);
    void setString(string nome);

};




#endif