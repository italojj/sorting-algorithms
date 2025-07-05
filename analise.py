import pandas as pd
import os
import csv

nome_arquivo_csv = 'resultados.csv'

if not os.path.exists(nome_arquivo_csv):
    print(f"Erro: O arquivo '{nome_arquivo_csv}' não foi encontrado.")
    exit()

dados = []
try:
    with open(nome_arquivo_csv, mode='r') as arquivo_csv:
        leitor_csv = csv.reader(arquivo_csv)
        
        cabecalho = next(leitor_csv)
    
        cabecalho = [nome.strip() for nome in cabecalho]
        
        for linha in leitor_csv:
            linha_dict = dict(zip(cabecalho, linha))
            dados.append(linha_dict)

    dados_brutos = pd.DataFrame(dados)

    colunas_numericas = ['Tamanho', 'Tempo(s)', 'Comparacoes', 'Trocas']
    for col in colunas_numericas:
        dados_brutos[col] = pd.to_numeric(dados_brutos[col])

    tipos_de_vetor = ["Aleatorio", "Quase Ordenado", "Inversamente Ordenado"]

    for tipo in tipos_de_vetor:

        print(f" TTabela de resultados para o cenario: {tipo.upper()}")
        
        dados_do_cenario = dados_brutos[dados_brutos['Tipo'] == tipo]
        
        if dados_do_cenario.empty:
            print(f"Nenhum dado encontrado para o cenário '{tipo}'. Pulando.")
            continue

        tabela_tempo = dados_do_cenario.pivot_table(index='Algoritmo', columns='Tamanho', values='Tempo(s)')
        tabela_comparacoes = dados_do_cenario.pivot_table(index='Algoritmo', columns='Tamanho', values='Comparacoes')
        tabela_trocas = dados_do_cenario.pivot_table(index='Algoritmo', columns='Tamanho', values='Trocas')
        
        print("\nTempo de Execução (em segundos)\n")
        print(tabela_tempo.to_string(float_format="%.6f"))
        
        print("\n\nNúmero de Comparações\n")
        print(tabela_comparacoes.to_string(float_format="%.0f"))
        
        print("\n\nNúmero de Trocas\n")
        print(tabela_trocas.to_string(float_format="%.0f"))
        
        print("\n")

except Exception as e:
    print(f"Ocorreu um erro inesperado durante a análise: {e}")

