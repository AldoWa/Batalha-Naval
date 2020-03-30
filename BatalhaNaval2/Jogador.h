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
	int getQuantidadePT();
	int getQuantidadeNT();
	int getQuantidadeS();
	int getQuantidadeC();
	void setQuantidadePT(int novoTamanho);
	void setQuantidadeNT(int novoTamanho);
	void setQuantidadeS(int novoTamanho);
	void setQuantidadeC(int novoTamanho);
	bool getAcertou();
private:
	void mostrarBarcos(Jogador* jogador);
	int quantidadePT = 1;
	int quantidadeNT = 1;
	int quantidadeS = 2;
	int quantidadeC = 2;
	int contador = 6;
	void inserirVeiculos();
	std::string nome;
	ArrayList<ArrayList<Veiculo*>*>* criarTabuleiro();
	bool acertou;
};


