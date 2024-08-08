#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include "Trajeto.hpp"
#include <stack>

using namespace std;

class Grafo {
private:
    int V;  // Número de vértices
    list<std::tuple<int, int, int>>* adj; // Lista de adjacências, corrigido para usar tuplas

public:
    Grafo(int V);
    ~Grafo();  // Destrutor para liberar memória

    void adicionarAresta(std::vector<Trajeto*> trajetos);

    // Ajuste na assinatura do método dfs para incluir destino e tipo de transporte
    void dfs(int partida, int destino, int tipoTransporte);
};

#endif // GRAFO_HPP

