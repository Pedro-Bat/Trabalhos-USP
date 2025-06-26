# Trabalhos - IC - USP  
**Trabalhos desenvolvidos na disciplina de Introdução à Computação**

---

## 📘 IC1 — Trabalhos

### 1. Programa de Cálculos com 5 Números
Faça um programa que:

- Leia 5 números
- Mostre um menu com as opções:
  - Média aritmética simples
  - Média ponderada (com pesos informados pelo usuário)
  - Desvio padrão
  - Maior valor
  - Menor valor
  - Releitura dos 5 valores

---

### 2. Jogo de Adivinhação
Desenvolva um jogo onde:

- O computador sorteia um número entre 0 e 100
- O usuário tenta adivinhar o número
- O computador informa se o palpite é maior ou menor que o número sorteado
- O programa termina quando o usuário acerta, mostrando uma mensagem de parabéns e o número de tentativas

---

### 3. Interseção de Vetores
O programa deve:

- Ler dois números `n` e `m`
- Ler dois vetores de tamanho `n` e `m`
- Criar um vetor com a interseção dos dois vetores (sem elementos repetidos)

---

## 📗 IC2 — Tarefas

### 4. Estrutura de Estudante
Programa em C++ que:

- Define a estrutura `estudante`:
  ```cpp
  struct Estudante {
      int numeroUSP;
      float nota1;
      float nota2;
      float mediaFinal;
  };
  ```

- Mostra menu com as opções:
  1. Inserir dados de um estudante
  2. Mostrar dados de um estudante
  3. Calcular média e desvio padrão das médias finais
  4. Sair

---

### 5. Teste de Desempenho com `ctime`
- Utilize a biblioteca `ctime` para medir o tempo de execução de funções que calculam a média de dois vetores.
- Plote os tempos de execução em gráfico.

---

### 6. Busca por Índice
- Implemente uma função que, dado um vetor `v` de inteiros e uma chave `x`, retorne o índice da **primeira ocorrência** de `x` ou `-1` se não existir.
- A função deve ter:
  - Melhor caso: tempo constante
  - Pior caso: tempo linear

---

### 7. Pesquisa Domiciliar
Dados coletados:
- Renda média mensal
- Número de ocupantes
- Endereço
- Ocupantes em idade escolar

#### a) Parte 1:
- Ordenar os dados por endereço (inserção direta)
- Salvar em arquivo

#### b) Parte 2:
Programa com menu:
1. Listar todos os domicílios  
2. Buscar por endereço (utilizar busca binária)  
3. Sair

---

### 8. QuickSort com Registros
- Estrutura: `nome (string)` e `número de inscrição (int)`
- Implementar QuickSort com ordenação por número de inscrição
- Contabilizar:
  - Comparações
  - Movimentações
  - Chamadas recursivas
- Testar com:
  - `45 56 12 43 95 19 8 67`
  - `8 12 19 43 45 56 67 95`
  - `95 67 56 45 43 19 12 8`

---

### 9. Comparação de Algoritmos de Ordenação
Algoritmos:

- Inserção direta  
- Inserção binária  
- Seleção  
- BubbleSort  
- HeapSort  
- MergeSort (fusão)  
- QuickSort  

#### Tarefas:

a) Implementar os algoritmos  
b) Medir comparações e movimentações em 5 tamanhos `n`, com entradas:
- Ordem crescente
- Ordem decrescente
- Aleatória

c) Analisar os gráficos  
d) Concluir quais algoritmos são mais adequados para cada cenário

---

### 10. Manipulação de Matrizes
Funções com matrizes quadradas (n x n):

1. Soma de duas matrizes A + B  
2. Multiplicação A × B  
3. Soma dos traços de A e B

#### a) Implemente as funções  
#### b) Faça a análise assintótica (notação O)

---

## 📙 Trabalho Final — AED

### Descrição
Criação de um programa para manipular **registros** com um menu contendo:

- Inserção de um registro
- Remoção de um registro
- Consulta baseada em chave

### Etapas:

1. Descrever resumidamente o problema  
2. Implementar em C++ com:
   - **Tabelas Hash com endereçamento encadeado**
3. Implementar em C++ com:
   - **Árvores Binárias de Busca** ou **Árvores AVL**

---

## ⚛️ Trabalho Fisica 1
Criação de uma Simulação de Movimento Circular em 3D
- Código feito em python com o uso das seguintes libs:
   1. Vpython
   2. numpy
#Output
![image](https://github.com/user-attachments/assets/7653061c-0749-4f5b-bf34-c1fbe8dbad9c)

