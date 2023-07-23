/*
Para definir recursivamente o conjunto de strings sobre o alfabeto {a, b} que contém um número par de b's, podemos usar a abordagem de construção recursiva. Podemos dividir o conjunto em duas partes: aquelas que começam com "a" e as que começam com "b".
Definição recursiva:
A string vazia ε (epsilon) faz parte do conjunto, pois não possui "b"s (número par de "b"s).
Se w pertence ao conjunto, então aw e abw também pertencem ao conjunto, pois adicionamos "a"s ou "ab"s na frente de w sem alterar o número de "b"s.
Nada mais faz parte do conjunto além das strings definidas nas regras 1 e 2.
Nesta implementação, a função hasEvenNumberOfBs verifica se a string tem um número par de "b"s. Ela faz isso chamando a si mesma recursivamente enquanto verifica cada caractere da string. Se encontrar um "b", remove-o e verifica o restante da string.
Ordem de complexidade: A ordem de complexidade desta função é O(n), onde n é o tamanho da string. Isso ocorre porque a função é chamada uma vez para cada caractere na string e, em cada chamada, um caractere é removido. Portanto, o número total de chamadas recursivas é proporcional ao tamanho da string.
*/

#include <stdio.h>
#include <string.h>

// Função que verifica se uma string tem número par de b's (recursivamente)
int hasEvenNumberOfBs(char str[], int len) {
    if (len == 0) {
        return 1; // Caso base: a string vazia ε tem número par de b's
    } else if (str[0] == 'b') {
        return !hasEvenNumberOfBs(str + 1, len - 1); // Caso 2: remover o primeiro b e verificar o restante
    } else {
        return hasEvenNumberOfBs(str + 1, len - 1); // Caso 1: não altera o número de b's
    }
}

int main() {
    char str1[] = "ababbab"; // Número par de b's
    char str2[] = "aaabb";   // Número ímpar de b's

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (hasEvenNumberOfBs(str1, len1)) {
        printf("%s tem um número par de b's.\n", str1); // Output: ababbab tem um número par de b's.
    } else {
        printf("%s não tem um número par de b's.\n", str1);
    }

    if (hasEvenNumberOfBs(str2, len2)) {
        printf("%s tem um número par de b's.\n", str2);
    } else {
        printf("%s não tem um número par de b's.\n", str2); // Output: aaabb não tem um número par de b's.
    }

    return 0;
}

