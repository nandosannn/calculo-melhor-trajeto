#include "../../include/model/Grafo.hpp"
#include <tuple>
#include <vector>
#include <iostream>

using namespace std;

// Implementação da classe Grafo
Grafo::Grafo(int V)
{
	this->V = V;  // Atribui o número de vértices (cidades cadastradas)
	adj = new list<tuple<int, int, int>>[V]; // Corrigido para usar tuplas
}

Grafo::~Grafo()
{
	delete[] adj;  // Libera a memória alocada
}

void Grafo::adicionarAresta(vector<Trajeto*> trajetos)
{
	// Adiciona vértice v2 à lista de vértices adjacentes de v1 com a distância e tipo de transporte
	for (size_t i = 0; i < trajetos.size(); i++)
	{
		int origem = trajetos[i]->getCidadeOrigem()->getId();
		int destino = trajetos[i]->getCidadeDestino()->getId();
		int distancia = trajetos[i]->getDistancia();
		int tipoTransporte = trajetos[i]->getTipoTransporte(); // Assumindo que você tem este método

		// Adiciona o destino, a distância, e o tipo de transporte na lista de adjacência
		adj[origem].push_back(make_tuple(destino, distancia, tipoTransporte));
	}
}

void Grafo::dfs(int v, int w, int tipoTransporte)
{
	stack<tuple<int, int, int>> pilha; // Corrigido para usar tuplas

	// Vetor de visitados
	vector<bool> visitados(V, false);  // Usar vector<bool> para simplificar a inicialização

	// Adiciona o vértice inicial na pilha
	pilha.push(make_tuple(v, 0, tipoTransporte));

	while (!pilha.empty())
	{
		tuple<int, int, int> p = pilha.top(); // Pega o topo da pilha
		pilha.pop();						  // Remove o topo da pilha

		int verticeAtual = get<0>(p);
		int distanciaAcumulada = get<1>(p);
		int tipoAtual = get<2>(p);

		// Marca o vértice como visitado se ainda não foi
		if (!visitados[verticeAtual])
		{
			cout << "Visitando vértice " << verticeAtual << " com distância acumulada " << distanciaAcumulada << " e tipo de transporte " << tipoAtual << "...\n";
			visitados[verticeAtual] = true;
		}

		// Percorre os vizinhos
		for (auto& it : adj[verticeAtual])
		{
			int vizinho = get<0>(it);
			int distancia = get<1>(it);
			int tipo = get<2>(it);

			// Se o vizinho é o destino e o tipo de transporte é o desejado, imprime a distância e termina
			if (vizinho == w && tipo == tipoTransporte)
			{
				cout << "Destino " << w << " encontrado com distância total " << distanciaAcumulada + distancia << " e tipo de transporte " << tipo << "!\n";
				return;
			}

			// Se não visitado, adiciona na pilha com a distância acumulada
			if (!visitados[vizinho])
			{
				pilha.push(make_tuple(vizinho, distanciaAcumulada + distancia, tipo));
			}
		}
	}

	cout << "Caminho para o destino " << w << " não encontrado com o tipo de transporte " << tipoTransporte << ".\n";
}
