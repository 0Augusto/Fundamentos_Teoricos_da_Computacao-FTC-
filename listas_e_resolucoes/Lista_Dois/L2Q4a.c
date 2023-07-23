/*
Para construir o AFD (Autômato Finito Determinístico) que representa o conjunto de strings sobre o alfabeto Σ = {a, b} que não contêm o substring "aaa", precisamos criar os estados, transições e estado(s) final(is) que representam essa condição.

O AFD terá três estados principais:

Estado inicial (q0): Representa o início de qualquer string.
Estado para as strings que não contêm "aaa" (q1): Representa as strings que não contêm o substring "aaa".
Estado para as strings que contêm o substring "aaa" (q2): Representa as strings que contêm o substring "aaa".
Os estados q1 e q2 são finais, pois indicam que a string satisfaz as condições desejadas (não contém "aaa").

Transições do AFD:

De q0 para si mesmo (loop): Para qualquer caractere a ou b.
De q0 para q1: Ao encontrar qualquer caractere diferente de 'a'.
De q0 para q2: Ao encontrar o primeiro 'a'.
De q1 para si mesmo (loop): Para qualquer caractere a ou b.
De q1 para q2: Ao encontrar o primeiro 'a'.
De q2 para si mesmo (loop): Para qualquer caractere a ou b.
Aqui está o AFD completo em forma de tabela:
| Estado Atual | Próximo Estado (a) | Próximo Estado (b) |
|--------------|--------------------|--------------------|
|     q0       |       q1           |       q0           |
|     q1       |       q1           |       q2           |
|     q2       |       q2           |       q2           |

A função isStringValid verifica se a string satisfaz as condições do AFD e retorna true se for válida (não contém "aaa") ou false caso contrário. Os exemplos de strings mostram o resultado para uma string válida e uma inválida de acordo com a condição do AFD.
*/

#include <stdio.h>
#include <stdbool.h>

// Função que verifica se a string satisfaz a condição do AFD
bool isStringValid(char str[]) {
    int currentState = 0; // Estado inicial (q0)

    for (int i = 0; str[i] != '\0'; i++) {
        char currentChar = str[i];

        switch (currentState) {
            case 0: // q0
                if (currentChar == 'a')
                    currentState = 2; // q2 (ao encontrar o primeiro 'a')
                else
                    currentState = 1; // q1
                break;

            case 1: // q1
                if (currentChar == 'a')
                    currentState = 2; // q2 (ao encontrar o primeiro 'a')
                break;

            case 2: // q2
                break; // Permanece em q2 (loop)
        }
    }

    // A string é válida se ela terminar em q1 (não contém "aaa")
    return currentState != 2;
}

int main() {
    char str1[] = "abbab"; // String válida (não contém "aaa")
    char str2[] = "baaab"; // String inválida (contém "aaa")

    if (isStringValid(str1)) {
        printf("%s é uma string válida.\n", str1); // Output: abbab é uma string válida.
    } else {
        printf("%s é uma string inválida.\n", str1);
    }

    if (isStringValid(str2)) {
        printf("%s é uma string válida.\n", str2);
    } else {
        printf("%s é uma string inválida.\n", str2); // Output: baaab é uma string inválida.
    }

    return 0;
}

