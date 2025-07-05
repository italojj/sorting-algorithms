#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include "algoritmos.h"

using namespace std;
// A função main realizará os testes e também ajudará um script python a gerar uma tabela que contém os dados brutos
int main() {
    //Parâmetros do teste, conforme a metodologia
    vector<int> tamanhos = {1000, 5000, 10000, 20000, 40000};
    vector<string> tiposDeVetor = {"Aleatorio", "Quase Ordenado", "Inversamente Ordenado"};

    //Imprime o cabeçalho do CSV
    cout << "Algoritmo,Tipo,Tamanho,Tempo(s),Comparacoes,Trocas\n";

    //Laço principal para percorrer todos os cenários de teste
    for (int tamanho : tamanhos) {
        for (const string& tipo : tiposDeVetor) {
            
            vector<int> vetorOriginal;
            if (tipo == "Aleatorio") {
                gerarVetorAleatorio(vetorOriginal, tamanho);
            } else if (tipo == "Quase Ordenado") {
                gerarVetorQuaseOrdenado(vetorOriginal, tamanho);
            } else {
                gerarVetorInversamenteOrdenado(vetorOriginal, tamanho);
            }

            {
                vector<int> vetorCopia = vetorOriginal;
                int comparacoes = 0, trocas = 0;
                auto inicio = chrono::high_resolution_clock::now();
                ordenacaoPorBolha(vetorCopia, comparacoes, trocas);
                auto fim = chrono::high_resolution_clock::now();
                chrono::duration<double> tempo = fim - inicio;
                cout << "Bubble Sort," << tipo << "," << tamanho << "," << fixed << setprecision(6) << tempo.count() << "," << comparacoes << "," << trocas << '\n';
            }

            {
                vector<int> vetorCopia = vetorOriginal;
                int comparacoes = 0, trocas = 0;
                auto inicio = chrono::high_resolution_clock::now();
                ordenacaoPorSelecao(vetorCopia, comparacoes, trocas);
                auto fim = chrono::high_resolution_clock::now();
                chrono::duration<double> tempo = fim - inicio;
                cout << "Selection Sort," << tipo << "," << tamanho << "," << fixed << setprecision(6) << tempo.count() << "," << comparacoes << "," << trocas << '\n';
            }

            {
                vector<int> vetorCopia = vetorOriginal;
                int comparacoes = 0, trocas = 0;
                auto inicio = chrono::high_resolution_clock::now();
                ordenacaoPorInsercao(vetorCopia, comparacoes, trocas);
                auto fim = chrono::high_resolution_clock::now();
                chrono::duration<double> tempo = fim - inicio;
                cout << "Insertion Sort," << tipo << "," << tamanho << "," << fixed << setprecision(6) << tempo.count() << "," << comparacoes << "," << trocas << '\n';
            }

            {
                vector<int> vetorCopia = vetorOriginal;
                int comparacoes = 0, trocas = 0;
                auto inicio = chrono::high_resolution_clock::now();
                ordenacaoPorIntercalacao(vetorCopia, comparacoes, trocas);
                auto fim = chrono::high_resolution_clock::now();
                chrono::duration<double> tempo = fim - inicio;
                cout << "Merge Sort," << tipo << "," << tamanho << "," << fixed << setprecision(6) << tempo.count() << "," << comparacoes << "," << trocas << '\n';
            }

            {
                vector<int> vetorCopia = vetorOriginal;
                int comparacoes = 0, trocas = 0;
                auto inicio = chrono::high_resolution_clock::now();
                ordenacaoRapida(vetorCopia, comparacoes, trocas);
                auto fim = chrono::high_resolution_clock::now();
                chrono::duration<double> tempo = fim - inicio;
                cout << "Quick Sort," << tipo << "," << tamanho << "," << fixed << setprecision(6) << tempo.count() << "," << comparacoes << "," << trocas << '\n';
            }
        }
    }

    return 0;
}
