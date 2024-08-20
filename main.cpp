#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <limits> // Incluir a biblioteca <limits> para std::numeric_limits
#include "include/model/Trajeto.hpp"
#include "include/model/Cidade.hpp"
#include "include/model/Grafo.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    string nomeCidadeOrigem;
    string nomeCidadeDestino;
    int idOrigem;
    int idDestino;
    int distancia;
    int tipo;
    Trajeto *trajeto;
    vector<Trajeto *> trajetos;
    set<int> cidades; // Usar set para evitar duplicatas
    vector<Trajeto *> melhorTrajeto;

    int opcao = 0;

    do
    {
        // Cidade Origem
        cout << "Escreva o nome da cidade origem: ";
        getline(cin, nomeCidadeOrigem);
        cout << "Escreva o id da cidade origem: ";
        cin >> idOrigem;

        if (cidades.find(idOrigem) != cidades.end())
        {
            cout << "Cidade já existe" << endl;
        }
        else
        {
            cidades.insert(idOrigem);
        }

        cin.ignore();

        // Cidade Destino
        cout << "Escreva o nome da cidade Destino: ";
        getline(cin, nomeCidadeDestino);
        cout << "Escreva o id da cidade Destino: ";
        cin >> idDestino;

        if (cidades.find(idDestino) != cidades.end())
        {
            cout << "Cidade já existe" << endl;
        }
        else
        {
            cidades.insert(idDestino);
        }

        Cidade *cidadeOrigem = new Cidade(idOrigem, nomeCidadeOrigem);
        Cidade *cidadeDestino = new Cidade(idDestino, nomeCidadeDestino);

        cout << "Escreva a distancia entre as cidades (em km): ";
        cin >> distancia;

        cout << "Escreva o tipo do Transporte (1 para Terrestre, 2 para Aquático, 3 para Aéreo): ";
        cin >> tipo;

        trajeto = new Trajeto(cidadeOrigem, cidadeDestino, distancia, tipo);
        trajetos.push_back(trajeto);

        cout << "Trajeto cadastrado com sucesso" << endl;
        cout << "Aperte 1 para fazer um novo cadastro ou 0 para finalizar!" << endl;
        cin >> opcao;

        cin.ignore();

    } while (opcao == 1);

    // Cadastro Viagem
    int partida;
    int destino;

    cout << "Escreva o id da cidade que vai partir: ";
    cin >> partida;
    cout << "Escreva o id da cidade destino: ";
    cin >> destino;
    cout << "Escreva o tipo de transporte: ";
    cin >> tipo;

    int tamanho = static_cast<int>(cidades.size() + 1);
    cout << "Tamanho: " << tamanho << endl;

    Grafo *grafo = new Grafo(tamanho);
    grafo->adicionarAresta(trajetos);
    melhorTrajeto = grafo->dfs(partida, destino, tipo, trajetos); // Corrigir chamada para incluir tipo

    if (melhorTrajeto.empty())
    {
        cout << "Nenhum trajeto encontrado!" << endl;
        for (auto t : trajetos)
        {
            delete t;
        }
        delete grafo;

        return 0;
    }

    // Liberação da memória dos trajetos e do grafo
    for (auto t : melhorTrajeto)
    {
        delete t;
    }

    for (auto t : trajetos)
    {
        delete t;
    }
    delete grafo;
    

    return 0;
}