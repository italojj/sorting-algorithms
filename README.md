Este projeto implementa algoritmos de ordenação em C++ e utiliza um script em Python para analisar os resultados de performance.
Este repositório contém o código-fonte de algoritmos implementados em C++ e um script de análise de dados em Python. O csv presente é
fruto da execução da função main e da execução do script .py, essa tabela foi usada posteriormente por mim para gerar gráficos para melhor
visualização das métricas e dos testes feitos.

Para compilar (caso necessário)

C++:
para compilar, "g++ Main.cpp algoritmos.cpp -o programa_teste"
para executar, "programa_teste.exe"

Python:
Necessário instalar as bibliotecas necessárias, logo, "pip install pandas matplotlib seaborn"
para executar o script, "python analise.py"

Descrição dos Arquivos

algoritmos.h: Arquivo de cabeçalho que declara as funções e estruturas dos algoritmos.

algoritmos.cpp: Arquivo de implementação com a lógica dos algoritmos.

Main.cpp: O programa principal que organiza e executa os testes.

analise.py: Script em Python que lê os resultados e gera a análise.
