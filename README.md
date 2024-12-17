# Trabalho Prático 3 - Ordenação de Structs

## Introdução

Como estudado na disciplina, existem diversos métodos e algoritmos de ordenação. Neste trabalho, você deve implementar três deles e comparar seu desempenho.

## O que deve ser desenvolvido

Neste trabalho cada grupo (de dois ou três integrantes) deverá implementar três algoritmos:

1. Um método de ordenação simples, como estudado na aula 20.
2. Um método de ordenação ótimo, como apresentado na aula 22.
3. Um método de ordenação em tempo linear, como visto na aula 24.

O código deverá ser desenvolvido em linguagem de programação C, não sendo permitido o uso de bibliotecas externas ou bibliotecas STL do C++.

## Requisitos

O código deverá contabilizar e exibir:

- O tempo de execução (em milissegundos)
- O número de operações de comparação executadas
- O número de operações de troca executadas
- A memória total gasta pelo algoritmo

## Entradas

Será dada uma única instância contendo diversos itens (structs). Esta entrada está disponível neste mesmo diretório e se chama `jogadores.csv`. Este é um arquivo .csv com cinco diferentes colunas:

- Nome
- Posição
- Naturalidade
- Posição
- Idade

Note que cada linha (com exceção da primeira) refere-se a um diferente jogador. A ordenação deverá ser realizada pelo campo nome da struct. Observe que deve-se construir um vetor com a struct completa e ordená-lo com base nesta única chave.

## Parâmetros de Entrada

O código também deverá receber como entrada (passando-se um argumento para a função `main`) um inteiro indicando qual algoritmo será utilizado:

1. Para o método de ordenação simples
2. Para o método de ordenação ótimo
3. Para o método de ordenação em tempo linear

## Saída Esperada

Espera-se que o código imprima a lista de structs ordenada (com todos os campos da struct e não somente o seu nome). Logo após, ele deve imprimir quatro números em ponto flutuante:

- O tempo de execução (em milissegundos)
- O número de operações de comparação executadas
- O número de operações de troca executadas
- A memória total gasta pelo algoritmo

A saída deverá, necessariamente, ser formatada em quatro linhas, seguindo a ordem apresentada acima.

## Código Base

Este terceiro trabalho não possui um código-base. É de responsabilidade de vocês se organizarem e criarem tudo a partir do zero.

## Makefile

O trabalho deverá, obrigatoriamente, compilar com um arquivo Makefile, sendo que um arquivo de exemplo é disponibilizado junto do código-base deste trabalho. Este Makefile pode ser modificado caso o grupo julgue necessário.

O código deve compilar em um ambiente Linux padrão, como o disponível nos laboratórios da UNIFAL. O código deve compilar com o comando:

```bash
make all
