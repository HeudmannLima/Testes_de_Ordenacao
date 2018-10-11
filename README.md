# Testes_de_Ordenacao
Teste de performance entre algoritmos de Ordenação;
Trabalho acadêmico - Disciplina P.O.T.A (Pesquisa, Ordenação e Técnicas de Armazenamento) - Engenharia da Computação

Foram testados os seguintes algoritmos de ordenação: Selection Sort, Insertion Sort, Bubble Sort, Shell Sort, Heap Sort, Merge Sort e Quick Sort, com o intuito de obter a média entre comparações e trocas.

# Setup
Vetor inicial: 10 posições;
Aumento do vetor: +50;
Rodadas: 50;

# Procedimento
1. Na primeira rodada, é gerado um vetor inicial com X posições, preenchido com números aleatórios;
2. O mesmo vetor passa por cada um dos 7 algoritmos de ordenação, registrando em acumuladores as TROCAS e COMPARAÇÕES de cada ordenação;
3. A cada rodada, o vetor aumenta de tamanho X vezes, até o limite máximo de rodadas;

4. Ao fim de todas as rodadas, o programa imprime um relatório com as médias de TROCAS e COMPARAÇÕES de cada ordenação, mostrando o desempenho de cada algoritmo em cada uma das rodadas. OK 01

