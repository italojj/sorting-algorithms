#include "algoritmos.h"
#include <random>
#include <algorithm> // É usado para std::swap em gerarVetorQuaseOrdenado

//Implementação dos algoritmos

void ordenacaoPorSelecao(vector<int>& vetor, int& comparacoes, int& trocas) {
    int tamanho = vetor.size();
    for (int i = 0; i < tamanho - 1; ++i) {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; ++j) {
            comparacoes++;
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if (i != indiceMenor) {
            trocas++;
            int temp = vetor[i];
            vetor[i] = vetor[indiceMenor];
            vetor[indiceMenor] = temp;
        }
    }
}

void ordenacaoPorBolha(vector<int>& vetor, int& comparacoes, int& trocas) {
    int tamanho = vetor.size();
    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = 0; j < tamanho - i - 1; ++j) {
            comparacoes++;
            if (vetor[j] > vetor[j + 1]) {
                trocas++;
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void ordenacaoPorInsercao(vector<int>& vetor, int& comparacoes, int& trocas) {
    int tamanho = vetor.size();
    for (int i = 1; i < tamanho; ++i) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && (comparacoes++, vetor[j] > chave)) {
            trocas++;
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void intercalar(vector<int>& vetor, int inicio, int meio, int fim, int& comparacoes, int& trocas) {
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;
    vector<int> esquerda(tamanhoEsquerda);
    vector<int> direita(tamanhoDireita);
    for (int i = 0; i < tamanhoEsquerda; ++i) esquerda[i] = vetor[inicio + i];
    for (int j = 0; j < tamanhoDireita; ++j) direita[j] = vetor[meio + 1 + j];
    int i = 0, j = 0, k = inicio;
    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        comparacoes++;
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i]; i++;
        } else {
            vetor[k] = direita[j]; j++;
        }
        trocas++; k++;
    }
    while (i < tamanhoEsquerda) {
        vetor[k] = esquerda[i]; trocas++; i++; k++;
    }
    while (j < tamanhoDireita) {
        vetor[k] = direita[j]; trocas++; j++; k++;
    }
}
void ordenacaoPorIntercalacaoRecursiva(vector<int>& vetor, int inicio, int fim, int& comparacoes, int& trocas) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        ordenacaoPorIntercalacaoRecursiva(vetor, inicio, meio, comparacoes, trocas);
        ordenacaoPorIntercalacaoRecursiva(vetor, meio + 1, fim, comparacoes, trocas);
        intercalar(vetor, inicio, meio, fim, comparacoes, trocas);
    }
}
void ordenacaoPorIntercalacao(vector<int>& vetor, int& comparacoes, int& trocas) {
    if (vetor.empty()) return;
    ordenacaoPorIntercalacaoRecursiva(vetor, 0, vetor.size() - 1, comparacoes, trocas);
}

int particionar(vector<int>& vetor, int inicio, int fim, int& comparacoes, int& trocas) {
    int pivo = vetor[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; ++j) {
        comparacoes++;
        if (vetor[j] < pivo) {
            i++;
            trocas++;
            int temp = vetor[i]; vetor[i] = vetor[j]; vetor[j] = temp;
        }
    }
    trocas++;
    int temp = vetor[i + 1]; vetor[i + 1] = vetor[fim]; vetor[fim] = temp;
    return i + 1;
}
void ordenacaoRapidaAuxiliar(vector<int>& vetor, int inicio, int fim, int& comparacoes, int& trocas) {
    if (inicio < fim) {
        int indicePivo = particionar(vetor, inicio, fim, comparacoes, trocas);
        ordenacaoRapidaAuxiliar(vetor, inicio, indicePivo - 1, comparacoes, trocas);
        ordenacaoRapidaAuxiliar(vetor, indicePivo + 1, fim, comparacoes, trocas);
    }
}
void ordenacaoRapida(vector<int>& vetor, int& comparacoes, int& trocas) {
    if (vetor.empty()) return;
    ordenacaoRapidaAuxiliar(vetor, 0, vetor.size() - 1, comparacoes, trocas);
}

//Implementação das funções para gerar os dados

void gerarVetorAleatorio(vector<int>& vetor, int tamanho) {
    vetor.resize(tamanho);
    random_device rd;
    mt19937 gerador(rd());
    uniform_int_distribution<> distribuicao(1, tamanho * 10);
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = distribuicao(gerador);
    }
}

void gerarVetorQuaseOrdenado(vector<int>& vetor, int tamanho) {
    vetor.resize(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = i;
    }
    random_device rd;
    mt19937 gerador(rd());
    uniform_int_distribution<> distribuicao(0, tamanho - 1);
    int numTrocas = tamanho * 0.1;
    for (int i = 0; i < numTrocas; ++i) {
        int idx1 = distribuicao(gerador);
        int idx2 = distribuicao(gerador);
        swap(vetor[idx1], vetor[idx2]);
    }
}

void gerarVetorInversamenteOrdenado(vector<int>& vetor, int tamanho) {
    vetor.resize(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = tamanho - i;
    }
}
