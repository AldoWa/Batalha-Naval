#pragma once
#include <string>
#include "Veiculo.h"
#include "array.h"
class Jogador
{
public:
	Jogador(std::string nome);
	~Jogador() {
		delete tabuleiroJogador;
	};
	void printarMatriz();
	std::string getNome();
    void atacar(Jogador* jogador, int linha, int coluna);
	ArrayList<ArrayList<Veiculo*>*>* tabuleiroJogador;
	int getContador();
private:
	int contador = 6;
	void inserirVeiculos();
	std::string nome;
	ArrayList<ArrayList<Veiculo*>*>* criarTabuleiro();
	
};


