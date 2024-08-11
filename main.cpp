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
    //int idOrigem;
    //int idDestino;
    //int distancia;
    int tipo;
    //set<int> cidades; // Usar set para evitar duplicatas

    //Cadastro direto por enqaunto para adiantar os testes
    vector<Cidade*> cidades;
    Cidade* cidade1 = new Cidade(1, "Natal");
    Cidade* cidade2 = new Cidade(2, "Monte Alegre");
    Cidade* cidade3 = new Cidade(3, "Pipa");
    Cidade* cidade4 = new Cidade(4, "Ceara Mirin");

    cidades.push_back(cidade1);
    cidades.push_back(cidade2);
    cidades.push_back(cidade3);
    cidades.push_back(cidade4);
    

    Trajeto *trajeto1 = new Trajeto(cidade1, cidade2, 15, 1);
    Trajeto *trajeto2 = new Trajeto(cidade2, cidade3, 15, 1);
    Trajeto *trajeto3 = new Trajeto(cidade1, cidade4, 15, 1);
    Trajeto *trajeto4 = new Trajeto(cidade4, cidade3, 15, 1);
    
    vector<Trajeto*> trajetos;

    trajetos.push_back(trajeto1);
    trajetos.push_back(trajeto2);
    trajetos.push_back(trajeto3);
    trajetos.push_back(trajeto4);

    //int opcao = 0;
    /*
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
    */

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
    grafo->dfs(partida, destino, tipo); // Corrigir chamada para incluir tipo

    // Liberação da memória dos trajetos e do grafo
    for (auto t : trajetos)
    {
        delete t;
    }
    delete grafo;

    return 0;
}