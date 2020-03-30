#pragma once
#include <string>

class Veiculo
{
private:
	std::string nome;
	int tamanho;
	int tamanhoReal; 
public:
	Veiculo(std::string nome, int celula);
	Veiculo();
	std::string getNome();
	void setCelula(int tamanho);
	int getCelulaAntesFim();
	int getCelula();
};

