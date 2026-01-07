*This project has been created as part of the 42 curriculum by Henrique Reis / hemaciel*

# push_swap

## 📌 Description

O **push_swap** é um projeto cujo objetivo é ordenar uma sequência de
números inteiros utilizando **duas stacks (A e B)** e um conjunto
**limitado de operações**, produzindo a menor quantidade possível de
instruções.

O programa recebe números como argumentos, valida completamente a
entrada (formato, intervalo e duplicatas), constrói a stack inicial e
escolhe dinamicamente o algoritmo de ordenação mais eficiente de acordo
com o tamanho da entrada.

A solução combina algoritmos específicos para entradas pequenas com
**Radix Sort binário** para entradas maiores, utilizando uma **indexação
prévia dos valores** para tornar a ordenação eficiente e previsível.

O projeto explora conceitos fundamentais como: - estruturas de dados
(listas ligadas) - manipulação de memória - algoritmos de ordenação -
operações bitwise - análise de complexidade - programação defensiva em C

------------------------------------------------------------------------

## ⚙️ Instructions

### 🔧 Compilação

``` bash
make
```

O comando acima gera o executável `push_swap`.

------------------------------------------------------------------------

### ▶️ Execução

``` bash
./push_swap 3 2 1
./push_swap "3 2 1"
```

------------------------------------------------------------------------

### ✅ Checker

``` bash
ARG="3 2 1"
./push_swap $ARG | ./checker_OS $ARG
```

------------------------------------------------------------------------

## 🔀 Gerador de argumentos aleatórios

``` bash
ARG=$(shuf -i 0-999 -n 500 | tr '\n' ' ')
./push_swap $ARG | ./checker_OS $ARG

ARG=$(seq -1000 1000 | shuf -n 500 | tr '\n' ' ')
./push_swap $ARG | ./checker_OS $ARG

ARG=$(seq -1000 1000 | shuf -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_OS $ARG
```
------------------------------------------------------------------------

## 👁️ Visualização gráfica

https://github.com/Niimphu/push_swap_visualiser

------------------------------------------------------------------------

## 🧠 Escolhas técnicas

-   Parsing robusto e seguro
-   Indexação para Radix Sort
-   Algoritmos dedicados para casos pequenos

------------------------------------------------------------------------

## 📚 Resources

-   https://projects.intra.42.fr/projects/push_swap
-   https://www.geeksforgeeks.org/radix-sort/
-   https://en.cppreference.com/w/c/language/operator_arithmetic
-   https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm
-   https://github.com/Niimphu/push_swap_visualiser

## 🏁 Conclusão

Projeto focado em eficiência algorítmica, organização de código e boas
práticas em C.
