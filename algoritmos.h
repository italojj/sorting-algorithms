#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include <vector>
#include <string>
using namespace std;

//Funções de ordenação(declaração)
void ordenacaoPorSelecao(vector<int>& vetor, int& comparacoes, int& trocas);
void ordenacaoPorBolha(vector<int>& vetor, int& comparacoes, int& trocas);
void ordenacaoPorInsercao(vector<int>& vetor, int& comparacoes, int& trocas);
void ordenacaoPorIntercalacao(vector<int>& vetor, int& comparacoes, int& trocas);
void ordenacaoRapida(vector<int>& vetor, int& comparacoes, int& trocas);

//Funções de geração de dados(declaração)
void gerarVetorAleatorio(vector<int>& vetor, int tamanho);
void gerarVetorQuaseOrdenado(vector<int>& vetor, int tamanho);
void gerarVetorInversamenteOrdenado(vector<int>& vetor, int tamanho);

#endif // ALGORITMOS_H
