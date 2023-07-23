/*
Para criar um λ-AFN (Autômato Finito Não-Determinístico com Transições Vazias) que corresponde à expressão regular (ab)(ba), precisamos criar os estados, transições e estado(s) final(is) que representam essa expressão.

O λ-AFN terá quatro estados principais:

Estado inicial (q0): Representa o início da string.
Estado para reconhecer a sequência "ab" (q1): Representa a sequência "ab" na string.
Estado para reconhecer a sequência "ba" (q2): Representa a sequência "ba" na string.
Estado final (q3): Representa o final da string.
Os estados q1, q2 e q3 são finais, pois indicam que a string satisfaz as condições desejadas (0 ou mais ocorrências de "ab", seguido de 0 ou mais ocorrências de "ba").

Transições do λ-AFN:

De q0 para q1 com "a": Representa a transição para o estado q1 ao encontrar um "a".
De q1 para q2 com "b": Representa a transição para o estado q2 ao encontrar um "b" após o "a".
De q2 para q1 com "a": Representa a possibilidade de ocorrer a sequência "ab" novamente após a sequência "ba".
De q2 para q3 com λ (transição vazia): Representa a transição para o estado final q3 ao encontrar a sequência "ba".
De q3 para q1 com "b": Representa a possibilidade de ocorrer a sequência "ba" novamente após a sequência "ab".
De q3 para q3 com λ (transição vazia): Representa a transição para o estado final q3 para permitir repetições de "ba" no final da string.
De q0 para q3 com λ (transição vazia): Representa a transição para o estado final q3 ao encontrar a string vazia.

Aqui está o λ-AFN completo em forma de tabela:

| Estado Atual | Próximo Estado (a) | Próximo Estado (b) | Próximo Estado (λ) |
|--------------|--------------------|--------------------|--------------------|
|     q0       |       q1           |       q3           |       q3           |
|     q1       |       q1           |       q2           |       q3           |
|     q2       |       q1           |       q3           |       q1           |
|     q3       |       q1           |       q3           |       q3           |

Aqui está o λ-AFN em forma de diagrama:

      a          b          λ
q0 ---------> q1 ---------> q2 -----> q3
  <---------------------------------
               λ

A função isStringValid verifica se a string satisfaz as condições do λ-AFN e retorna true se for válida (contém a sequência "ab" seguida de "ba") ou false caso contrário. Os exemplos de strings mostram o resultado para uma string válida e inválida de acordo com a condição do λ-AFN.
*/

#include <stdio.h>
#include <stdbool.h>

// Função que verifica se a string satisfaz a condição do λ-AFN
bool isStringValid(char str[]) {
    int currentState = 0; // Estado inicial (q0)

    for (int i = 0; str[i] != '\0'; i++) {
        char currentChar = str[i];

        switch (currentState) {
            case 0: // q0
                if (currentChar == 'a')
                    currentState = 1; // q1 (ao encontrar o primeiro 'a')
                else
                    currentState = 3; // q3 (transição vazia)
                break;

            case 1: // q1
                if (currentChar == 'b')
                    currentState = 2; // q2 (ao encontrar o 'b' após o 'a')
                else if (currentChar == 'a')
                    currentState = 1; // Continua em q1 (loop)
                else
                    currentState = 3; // q3 (transição vazia)
                break;

            case 2: // q2
                if (currentChar == 'a')
                    currentState = 1; // Retorna a q1 (loop)
                else if (currentChar == 'b')
                    currentState = 3; // Retorna a q3 (loop)
                else
                    currentState = 3; // q3 (transição vazia)
                break;

            case 3: // q3
                if (currentChar == 'b')
                    currentState = 3; // Continua em q3 (loop)
                else
                    currentState = 1; // Retorna a q1
                break;
        }
    }

    // A string é válida se ela terminar em q3 (sequência "ba")
    return currentState == 3;
}

int main() {
    char str1[] = "ababba"; // String válida (sequência "ab" seguida de "ba")
    char str2[] = "abbba";  // String válida (sequência "ab" seguida de "ba" repetidas)
    char str3[] = "ababab"; // String válida (sequência "ab" repetida)
    char str4[] = "babab";  // String inválida (não começa com "ab")
    char str5[] = "aabab";  // String inválida (não termina com "ba")

    if (isStringValid(str1)) {
        printf("%s é uma string válida.\n", str1); // Output: ababba é uma string válida.
    } else {
        printf("%s é uma string inválida.\n", str1);
    }

    if (isStringValid(str2)) {
        printf("%s é uma string válida.\n", str2); // Output: abbba é uma string válida.
    } else {
        printf("%s é uma string inválida.\n", str2);
    }

    if (isStringValid(str3)) {
        printf("%s é uma string válida.\n", str3); // Output: ababab é uma string válida.
    } else {
        printf("%s é uma string inválida.\n", str3);
    }

    if (isStringValid(str4)) {
        printf("%s é uma string válida.\n", str4);
    } else {
        printf("%s é uma string inválida.\n", str4); // Output: babab é uma string inválida.
    }

    if (isStringValid(str5)) {
        printf("%s é uma string válida.\n", str5);
    } else {
        printf("%s é uma string inválida.\n", str5); // Output: aabab é uma string inválida.
    }

    return 0;
}

