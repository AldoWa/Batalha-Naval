// BatalhaNaval2.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "Jogador.h"
#include <time.h>
bool checarGanhador(Jogador *jogador);
bool checarLimite(Jogador* jogador, int linha, int coluna);
int main()
{
    std::string nome;
    std::cout << "Digite o nome do player 1 vs a CPU: " << std::endl;
    std::cin >> nome;
    Jogador* j1 = new Jogador(nome);
    Jogador* j2 = new Jogador("CPU");
    srand(time(NULL));
    int jogador = 1;
    while (true) {
        if (checarGanhador(j1) == false || checarGanhador(j2) == false) {
            break;
        }
        else {
            if (jogador == 1) {
                j1->printarMatriz();  
                std::cout << "Jogador 1 atacando Jogador 2" << std::endl;
                int linha; 
                int coluna;
                
                    std::cout << "Digite a linha: " << std::endl;
                    std::cin >> linha;
                    std::cout << "Digite a coluna: " << std::endl;
                    std::cin >> coluna;
                if (checarLimite(j2, linha, coluna) == true) {
                    j1->atacar(j2, linha, coluna);
                    while (true) {
                        if (j1->getAcertou() == true) {
                            std::cout << "Digite a linha: " << std::endl;
                            std::cin >> linha;
                            std::cout << "Digite a coluna: " << std::endl;
                            std::cin >> coluna;
                            j1->atacar(j2, linha, coluna);
                            
                        }
                        else {
                            jogador = jogador + 1;
                            break;
                        }
                    }
                }
                else {
                    std::cout << "fora dos limites do mapa, tente novamente" << std::endl;
                }
               
               
            }
            else if(jogador == 2) {
                std::cout << "------------- CPU ATACANDO ----------" << std::endl;
                std::cout << "Jogador 2 atacando Jogador 1" << std::endl;
                int linha = rand() % 9 + 1;
                int coluna = rand() % 9 + 1;
                j2->atacar(j1, linha, coluna);
                while (true) {
                    if (j2->getAcertou() == true) {
                        linha = rand() % 9 + 1;
                        coluna = rand() % 9 + 1;
                        j2->atacar(j1, linha, coluna);
                    }
                    else {
                        jogador = jogador - 1;
                        break;
                    }
                }
                
                std::cout << "------------- ------------ ----------" << std::endl;
                
            }
        }
    }
    delete j1;
    delete j2;
}

bool checarGanhador(Jogador *jogador)
{
    if (jogador->getContador() == 0) {
        std::cout << "Ganhador foi = " << jogador->getNome();
        return false;
    }
    else {
        return true;
    }
}

bool checarLimite(Jogador *jogador, int linha, int coluna)
{

    if (jogador->tabuleiroJogador->size() <= linha || jogador->tabuleiroJogador->get(linha)->size() <= coluna) {
        return false;
    }
    else {
        return true;
    }
}
