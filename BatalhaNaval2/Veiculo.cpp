#include "Veiculo.h"

Veiculo::Veiculo(std::string nome, int celula)
{
	this->nome = nome;
	this->tamanho = celula;
	this->tamanhoReal = celula;
}

Veiculo::Veiculo()
{
}


std::string Veiculo::getNome()
{
	return this->nome;
}

void Veiculo::setCelula(int tamanho)
{
	this->tamanho = tamanho;
}

int Veiculo::getCelulaAntesFim()
{
	return this->tamanhoReal;
}

int Veiculo::getCelula()
{
	return this->tamanho;
}
