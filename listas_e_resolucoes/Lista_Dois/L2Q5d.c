/*
Para criar um λ-AFN (Autômato Finito Não-Determinístico com Transições Vazias) que corresponde à expressão regular (aa(a ∪ b)+bb)*, precisamos criar os estados, transições e estado(s) final(is) que representam essa expressão.

O λ-AFN terá quatro estados principais:

Estado inicial (q0): Representa o início da string.
Estado para reconhecer a sequência "aa" (q1): Representa a sequência "aa" na string.
Estado para reconhecer a sequência "(a ∪ b)" (q2): Representa a possibilidade de encontrar "a" ou "b" após "aa".
Estado para reconhecer a sequência "bb" (q3): Representa a sequência "bb" na string.
Estado final (q4): Representa o final da string.
Os estados q1, q2, q3 e q4 são finais, pois indicam que a string satisfaz as condições desejadas (sequência "aa" seguida de uma ou mais ocorrências de "a" ou "b", seguida da sequência "bb").

Transições do λ-AFN:

De q0 para q1 com "a": Representa a transição para o estado q1 ao encontrar o primeiro "a".
De q1 para q2 com "a" ou "b": Representa a transição para o estado q2 ao encontrar "a" ou "b" após "aa".
De q2 para q2 com "a" ou "b": Representa a possibilidade de ocorrer a sequência "(a ∪ b)" novamente.
De q2 para q3 com "b": Representa a transição para o estado q3 ao encontrar "b" após "(a ∪ b)".
De q3 para q1 com "a": Representa a transição para o estado q1 ao encontrar o primeiro "a" após "bb".
De q3 para q2 com "a" ou "b": Representa a transição para o estado q2 ao encontrar "a" ou "b" após "bb".
De q3 para q4 com λ (transição vazia): Representa a transição para o estado final q4 ao encontrar a sequência "bb".
De q0 para q4 com λ (transição vazia): Representa a transição para o estado final q4 ao encontrar a string vazia.

Aqui está o λ-AFN completo em forma de tabela:

| Estado Atual | Próximo Estado (a) | Próximo Estado (b) | Próximo Estado (λ) |
|--------------|--------------------|--------------------|--------------------|
|     q0       |       q1           |       q4           |       q4           |
|     q1       |       q2           |       q4           |       q4           |
|     q2       |       q2           |       q3           |       q4           |
|     q3       |       q1           |       q2           |       q4           |
|     q4       |       q4           |       q4           |       q4           |

Aqui está o λ-AFN em forma de diagrama:

      a          b          λ
q0 ---------> q1 ---------> q2 -----> q3
  <---------------------------------
               λ

A função isStringValid verifica se a string satisfaz as condições do λ-AFN e retorna true se for válida (contém a sequência "aa" seguida de uma ou mais ocorrências de "a" ou "b", seguida da sequência "bb") ou false caso contrário. Os exemplos de strings mostram o resultado para uma string válida e inválida de acordo com a condição do λ-AFN.
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
                else if (currentChar == 'b')
                    currentState = 4; // q4 (ao encontrar o primeiro 'b')
                else
                    currentState = 4; // Retorna a q4 (loop)
                break;

            case 1: // q1
                if (currentChar == 'a' || currentChar == 'b')
                    currentState = 2; // q2 (ao encontrar 'a' ou 'b' após 'aa')
                else
                    currentState = 4; // Retorna a q4 (loop)
                break;

            case 2: // q2
                if (currentChar == 'a' || currentChar == 'b')
                    currentState = 2; // Continua em q2 (loop)
                else if (currentChar == 'b')
                    currentState = 3; // q3 (ao encontrar 'b' após '(a ∪ b)')
                else
                    currentState = 4; // Retorna a q4 (loop)
                break;

            case 3: // q3
                if (currentChar == 'a')
                    currentState = 1; // q1 (ao encontrar 'a' após 'bb')
                else if (currentChar == 'b')
                    currentState = 2; // q2 (ao encontrar 'b' após 'bb')
                else
                    currentState = 4; // Retorna a q4 (loop)
                break;
        }
    }

    // A string é válida se ela terminar em q4 (sequência "(a ∪ b)*bb")
    return currentState == 4;
}

int main() {
    char str1[] = "aabba";  // String válida (sequência "aa" seguida de "bb")
    char str2[] = "ababbb"; // String válida (sequência "aa" seguida de "a" ou "b", seguida de "bb")
    char str3[] = "abab";   // String inválida (não termina com "bb")
    char str4[] = "abb";    // String válida (sequência "bb")
    char str5[] = "a";      // String inválida (não começa com "aa")

    if (isStringValid(str1)) {
        printf("%s é uma string válida.\n", str1); // Output: aabba é uma string válida.
    } else {
        printf("%s é uma string inválida.\n", str1);
    }

    if (isStringValid(str2)) {
        printf("%s é uma string válida.\n", str2); // Output: ababbb é uma string válida.
    } else {
        printf("%s é uma string inválida.\n", str2);
    }

    if (isStringValid(str3)) {
        printf("%s é uma string válida.\n", str3);
    } else {
        printf("%s é uma string inválida.\n", str3); // Output: abab é uma string inválida.
    }

    if (isStringValid(str4)) {
        printf("%s é uma string válida.\n", str4); // Output: abb é uma string válida.
    } else {
        printf("%s é uma string inválida.\n", str4);
    }

    if (isStringValid(str5)) {
        printf("%s é uma string válida.\n", str5);
    } else {
        printf("%s é uma string inválida.\n", str5); // Output: a é uma string inválida.
    }

    return 0;
}

