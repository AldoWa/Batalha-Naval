#include "Jogador.h"
#include <iostream>
#include <time.h>
Jogador::Jogador(std::string nome)
{

	this->nome = nome;
	this->tabuleiroJogador = this->criarTabuleiro();
	this->inserirVeiculos();
}

void Jogador::printarMatriz()
{
	std::cout << "Mar do jogador = " << this->getNome() << std::endl;
	int tamanho = this->tabuleiroJogador->size();
	for (int i = 0; i < tamanho; i++)
	{
		ArrayList<Veiculo*>* vetorVeiculos = tabuleiroJogador->get(i);
		int tamanhoColuna = vetorVeiculos->size();
		for (int j = 0; j < tamanhoColuna; j++)
		{
			if (vetorVeiculos->get(j) == NULL) {
				std::cout << 0 << "  ";
			}
			else {
				if (vetorVeiculos->get(j)->getNome() == "Porta") {
					std::cout << "P-T" << "  ";
				}
				if (vetorVeiculos->get(j)->getNome() == "NavioTanque") {
					std::cout << "NT" << "  ";
				}
				if (vetorVeiculos->get(j)->getNome() == "ContraPort") {
					std::cout << "CP" << "  ";
				}
				if (vetorVeiculos->get(j)->getNome() == "Submarino") {
					std::cout << "S" << "  ";
				}
			}



		}
		std::cout << std::endl;
	}
}

std::string Jogador::getNome()
{
	return this->nome;
}

void Jogador::atacar(Jogador *jogador, int linha, int coluna)
{ 
	
	
		Veiculo* veiculo = jogador->tabuleiroJogador->get(linha)->get(coluna);
		if (veiculo == nullptr) {
			std::cout << "Errou atingiu agua" << std::endl;
		}
		else {
			jogador->tabuleiroJogador->get(linha)->remove(coluna);
			std::cout << "Acertou" << std::endl;
			int novoTamanho = (veiculo->getCelula() - 1);
			veiculo->setCelula(novoTamanho);
			
			if (veiculo->getCelula() == 0) {
				std::cout << "Barco Destruido , nome = " << veiculo->getNome() << "/ Tamanho = " << veiculo->getCelulaAntesFim()<< std::endl;
				this->contador = this->contador - 1;
			}
		}

	
	
}

int Jogador::getContador()
{
	return this->contador;
}






void Jogador::inserirVeiculos()
{
	srand(time(NULL));

	int i = rand() % 2;
	Veiculo* portaAvioes = new Veiculo("Porta", 5);
	Veiculo* navioTanque = new Veiculo("NavioTanque", 4);
	Veiculo* contraPort = new Veiculo("ContraPort", 3);
	Veiculo* submarino = new Veiculo("Submarino", 3);
	if (this->getNome() == "CPU") {
		switch (i)
		{
		case 0:
			
			this->tabuleiroJogador->get(0)->remove(0);
			this->tabuleiroJogador->get(0)->addPassandoIndice(portaAvioes, 0);
			this->tabuleiroJogador->get(1)->remove(0);
			this->tabuleiroJogador->get(1)->addPassandoIndice(portaAvioes, 0);
			this->tabuleiroJogador->get(2)->remove(0);
			this->tabuleiroJogador->get(2)->addPassandoIndice(portaAvioes, 0);
			this->tabuleiroJogador->get(3)->remove(0);
			this->tabuleiroJogador->get(3)->addPassandoIndice(portaAvioes, 0);
			this->tabuleiroJogador->get(4)->remove(0);
			this->tabuleiroJogador->get(4)->addPassandoIndice(portaAvioes, 0);
			
			this->tabuleiroJogador->get(1)->remove(3);
			this->tabuleiroJogador->get(1)->addPassandoIndice(navioTanque, 3);
			this->tabuleiroJogador->get(1)->remove(4);
			this->tabuleiroJogador->get(1)->addPassandoIndice(navioTanque, 4);
			this->tabuleiroJogador->get(1)->remove(5);
			this->tabuleiroJogador->get(1)->addPassandoIndice(navioTanque, 5);
			this->tabuleiroJogador->get(1)->remove(6);
			this->tabuleiroJogador->get(1)->addPassandoIndice(navioTanque, 6);
			
			this->tabuleiroJogador->get(4)->remove(3);
			this->tabuleiroJogador->get(4)->addPassandoIndice(contraPort, 3);
			this->tabuleiroJogador->get(4)->remove(4);
			this->tabuleiroJogador->get(4)->addPassandoIndice(contraPort, 4);
			this->tabuleiroJogador->get(4)->remove(5);
			this->tabuleiroJogador->get(4)->addPassandoIndice(contraPort, 5);
			this->tabuleiroJogador->get(9)->remove(3);
			this->tabuleiroJogador->get(9)->addPassandoIndice(contraPort, 3);
			this->tabuleiroJogador->get(9)->remove(4);
			this->tabuleiroJogador->get(9)->addPassandoIndice(contraPort, 4);
			this->tabuleiroJogador->get(9)->remove(5);
			this->tabuleiroJogador->get(9)->addPassandoIndice(contraPort, 5);
			
			this->tabuleiroJogador->get(0)->remove(8);
			this->tabuleiroJogador->get(0)->addPassandoIndice(submarino, 8);
			this->tabuleiroJogador->get(1)->remove(8);
			this->tabuleiroJogador->get(1)->addPassandoIndice(submarino, 8);
			this->tabuleiroJogador->get(2)->remove(8);
			this->tabuleiroJogador->get(2)->addPassandoIndice(submarino, 8);
			this->tabuleiroJogador->get(7)->remove(1);
			this->tabuleiroJogador->get(7)->addPassandoIndice(submarino, 1);
			this->tabuleiroJogador->get(7)->remove(2);
			this->tabuleiroJogador->get(7)->addPassandoIndice(submarino, 2);
			this->tabuleiroJogador->get(7)->remove(3);
			this->tabuleiroJogador->get(7)->addPassandoIndice(submarino, 3);
			break;
		case 1:
			
			this->tabuleiroJogador->get(0)->remove(0);
			this->tabuleiroJogador->get(0)->addPassandoIndice(portaAvioes, 0);
			this->tabuleiroJogador->get(0)->remove(1);
			this->tabuleiroJogador->get(0)->addPassandoIndice(portaAvioes, 1);
			this->tabuleiroJogador->get(0)->remove(2);
			this->tabuleiroJogador->get(0)->addPassandoIndice(portaAvioes, 2);
			this->tabuleiroJogador->get(0)->remove(3);
			this->tabuleiroJogador->get(0)->addPassandoIndice(portaAvioes, 3);
			this->tabuleiroJogador->get(0)->remove(4);
			this->tabuleiroJogador->get(0)->addPassandoIndice(portaAvioes, 4);
			
			this->tabuleiroJogador->get(0)->remove(3);
			this->tabuleiroJogador->get(0)->addPassandoIndice(navioTanque, 3);
			this->tabuleiroJogador->get(0)->remove(4);
			this->tabuleiroJogador->get(0)->addPassandoIndice(navioTanque, 4);
			this->tabuleiroJogador->get(0)->remove(5);
			this->tabuleiroJogador->get(0)->addPassandoIndice(navioTanque, 5);
			this->tabuleiroJogador->get(0)->remove(6);
			this->tabuleiroJogador->get(0)->addPassandoIndice(navioTanque, 6);
			
			this->tabuleiroJogador->get(2)->remove(5);
			this->tabuleiroJogador->get(2)->addPassandoIndice(contraPort, 5);
			this->tabuleiroJogador->get(2)->remove(6);
			this->tabuleiroJogador->get(2)->addPassandoIndice(contraPort, 6);
			this->tabuleiroJogador->get(2)->remove(7);
			this->tabuleiroJogador->get(4)->addPassandoIndice(contraPort, 7);
			this->tabuleiroJogador->get(6)->remove(5);
			this->tabuleiroJogador->get(6)->addPassandoIndice(contraPort, 5);
			this->tabuleiroJogador->get(7)->remove(5);
			this->tabuleiroJogador->get(7)->addPassandoIndice(contraPort, 5);
			this->tabuleiroJogador->get(8)->remove(5);
			this->tabuleiroJogador->get(8)->addPassandoIndice(contraPort, 5);
			
			this->tabuleiroJogador->get(4)->remove(7);
			this->tabuleiroJogador->get(4)->addPassandoIndice(submarino, 7);
			this->tabuleiroJogador->get(5)->remove(7);
			this->tabuleiroJogador->get(5)->addPassandoIndice(submarino, 7);
			this->tabuleiroJogador->get(6)->remove(7);
			this->tabuleiroJogador->get(6)->addPassandoIndice(submarino, 7);
			this->tabuleiroJogador->get(7)->remove(9);
			this->tabuleiroJogador->get(7)->addPassandoIndice(submarino, 9);
			this->tabuleiroJogador->get(8)->remove(9);
			this->tabuleiroJogador->get(8)->addPassandoIndice(submarino, 9);
			this->tabuleiroJogador->get(9)->remove(9);
			this->tabuleiroJogador->get(9)->addPassandoIndice(submarino, 9);
			break;
		}
		
	}
	else {
		Veiculo* portaAvioes = new Veiculo("Porta", 5);
		this->tabuleiroJogador->get(5)->remove(0);
		this->tabuleiroJogador->get(5)->addPassandoIndice(portaAvioes, 0);
		this->tabuleiroJogador->get(6)->remove(0);
		this->tabuleiroJogador->get(6)->addPassandoIndice(portaAvioes, 0);
		this->tabuleiroJogador->get(7)->remove(0);
		this->tabuleiroJogador->get(7)->addPassandoIndice(portaAvioes, 0);
		this->tabuleiroJogador->get(8)->remove(0);
		this->tabuleiroJogador->get(8)->addPassandoIndice(portaAvioes, 0);
		this->tabuleiroJogador->get(9)->remove(0);
		this->tabuleiroJogador->get(9)->addPassandoIndice(portaAvioes, 0);
		Veiculo* navioTanque = new Veiculo("NavioTanque", 4);
		this->tabuleiroJogador->get(3)->remove(3);
		this->tabuleiroJogador->get(3)->addPassandoIndice(navioTanque, 3);
		this->tabuleiroJogador->get(3)->remove(4);
		this->tabuleiroJogador->get(3)->addPassandoIndice(navioTanque, 4);
		this->tabuleiroJogador->get(3)->remove(5);
		this->tabuleiroJogador->get(3)->addPassandoIndice(navioTanque, 5);
		this->tabuleiroJogador->get(3)->remove(6);
		this->tabuleiroJogador->get(3)->addPassandoIndice(navioTanque, 6);
		Veiculo* contraPort = new Veiculo("ContraPort", 3);
		this->tabuleiroJogador->get(0)->remove(1);
		this->tabuleiroJogador->get(0)->addPassandoIndice(contraPort, 1);
		this->tabuleiroJogador->get(1)->remove(1);
		this->tabuleiroJogador->get(1)->addPassandoIndice(contraPort, 1);
		this->tabuleiroJogador->get(2)->remove(1);
		this->tabuleiroJogador->get(2)->addPassandoIndice(contraPort, 1);
		this->tabuleiroJogador->get(7)->remove(2);
		this->tabuleiroJogador->get(7)->addPassandoIndice(contraPort, 2);
		this->tabuleiroJogador->get(7)->remove(3);
		this->tabuleiroJogador->get(7)->addPassandoIndice(contraPort, 3);
		this->tabuleiroJogador->get(7)->remove(4);
		this->tabuleiroJogador->get(7)->addPassandoIndice(contraPort, 4);
		Veiculo* submarino = new Veiculo("Submarino", 3);
		this->tabuleiroJogador->get(4)->remove(8);
		this->tabuleiroJogador->get(4)->addPassandoIndice(submarino, 8);
		this->tabuleiroJogador->get(5)->remove(8);
		this->tabuleiroJogador->get(5)->addPassandoIndice(submarino, 8);
		this->tabuleiroJogador->get(6)->remove(8);
		this->tabuleiroJogador->get(6)->addPassandoIndice(submarino, 8);
		this->tabuleiroJogador->get(9)->remove(7);
		this->tabuleiroJogador->get(9)->addPassandoIndice(submarino, 7);
		this->tabuleiroJogador->get(9)->remove(8);
		this->tabuleiroJogador->get(9)->addPassandoIndice(submarino, 8);
		this->tabuleiroJogador->get(9)->remove(9);
		this->tabuleiroJogador->get(9)->addPassandoIndice(submarino, 9);
		this->tabuleiroJogador->get(9)->add(submarino);
	}


}

ArrayList<ArrayList<Veiculo*>*>* Jogador::criarTabuleiro()
{
	ArrayList<ArrayList<Veiculo*>*>* matriz = new ArrayList<ArrayList<Veiculo*>*>();

	for (int i = 0; i < 10; i++)
	{

		ArrayList<Veiculo*>* veiculoVetor = new ArrayList<Veiculo*>();


		for (int j = 0; j < 10; j++)
		{
			Veiculo* veiculo = nullptr;
			veiculoVetor->add(veiculo);

		}

		matriz->add(veiculoVetor);
	}


	return matriz;
}




