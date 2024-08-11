#include "../../include/model/Grafo.hpp"
#include <tuple>
#include <vector>
#include <iostream>

using namespace std;

// Implementação da classe Grafo
Grafo::Grafo(int V)
{
	this->V = V;							 // Atribui o número de vértices (cidades cadastradas)
	adj = new list<tuple<int, int, int>>[V]; // Corrigido para usar tuplas
}

Grafo::~Grafo()
{
	delete[] adj; // Libera a memória alocada
}

void Grafo::adicionarAresta(vector<Trajeto *> trajetos)
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
	vector<tuple<int, int, int>> pilha; // Usar vector em vez de stack
	bool visitando[V];
	vector<int> distancia;
	bool regrediu = false;
	vector<tuple<vector<tuple<int, int, int>>, int>> conexoes; // Corrigido o tipo
	// Vetor de visitados
	for (int i = 0; i < V; i++)
	{
		visitando[i] = false;
	}

	// Adiciona o vértice inicial na pilha
	tuple<int, int, int> tupla;
	int distanciaAcumulada = 0;
	while (true)
	{
		cout << "Valor de v no inicio de While: " << v << endl;
		
		//Visitando os vizinhos não visitados
		if (!visitando[v])
		{
			cout << "Visitando vertice " << v << ", distancia acumulada: " << distanciaAcumulada << ", tipo do trajeto: " << tipoTransporte << endl;
			//marcar como visitado
			visitando[v] = true;	
			pilha.push_back(make_tuple(v, distanciaAcumulada, tipoTransporte)); // insere "v" na pilha
		}

		bool achou = false;
		bool achouDestino = false;
		list<tuple<int, int, int>>::iterator it;

		if (v == w)
		{
			cout << "Valor de v dentro de if(v==w): " << v << endl;
			achouDestino = true;
		}
		else
		{
			// Percorre os vizinhos
			for (it = adj[v].begin(); it != adj[v].end(); it++)
			{
				list<tuple<int, int, int>>::iterator vz;
				if (regrediu == false)
				{
					//Verificar se algum dos vizinho é o destino já visitado
					for (vz = adj[v].begin(); vz != adj[v].end(); vz++)
					{
						if (visitando[get<0>(*vz)] == true && get<0>(*vz) == w)
						{
							cout << "Um dos vizinhos é o destino colocar no vector" << endl;
							break;
						}
						
					}
				}

				//Resetar regrediu
				if (regrediu)
				{
					cout << "Passando na cidade " << v << " de novo."<< endl;
					regrediu = false;
				}
				
				//Verufucar se o próximo vizinho não foi visitado
				cout << "Valor de *ït: " << get<0>(*it) << " - Valor de visitando[get<0>(*it)]: " <<  visitando[get<0>(*it)] << " - Valor visitando[v]: " << visitando[v] << endl;
				if (!visitando[get<0>(*it)] && get<2>(*it) == tipoTransporte)
				{
					achou = true;
					break;
				}
				
			}
		}

		//Se algum vizinho não tiver sido visitado, visita-lo.
		if (achou)
		{
			v = get<0>(*it);
			distanciaAcumulada += get<1>(*it);
			tipoTransporte = get<2>(*it);
			distancia.push_back(get<1>(*it));
		}

		//Se não, voltar para cidade anterior e, assim, fazer uma nova busca por um vizinho não visitado
		else
		{	
			//Sinalizar quando o primeiro destino não visitador for encontrado
			if (achouDestino)
			{
				conexoes.push_back(make_tuple(pilha, distanciaAcumulada)); // Armazena a pilha e a distância acumulada
			}
			

			if (!distancia.empty())
			{
				distanciaAcumulada -= distancia.back();
				distancia.pop_back();
				regrediu = true;
			}
			
			pilha.pop_back();
			
			if (pilha.empty())
			{
				
				for (size_t i = 0; i < conexoes.size(); i++)
				{
					cout << "Conexão #" << i + 1 << endl;
					vector<tuple<int, int, int>> caminho = get<0>(conexoes[i]);
					for (size_t j = 0; j < caminho.size(); j++)
					{
						cout << "Cidade: " << get<0>(caminho[j]) << " - Distancia: " << get<1>(caminho[j]) << " - Tipo Transporte: " << get<2>(caminho[j]) << endl;
					}
					cout << "Distância Acumulada: " << get<1>(conexoes[i]) << endl;
				}
				

				break;
			}
			tupla = pilha.back();
			v = get<0>(tupla);
			tipoTransporte = get<2>(tupla);
		}
	}
}
