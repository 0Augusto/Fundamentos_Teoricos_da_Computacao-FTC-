/*
Para construir o AFD (Autômato Finito Determinístico) que representa o conjunto de strings sobre o alfabeto Σ = {a, b, c} que começa com "a", tem exatamente dois "b"s e termina com exatamente "cc", precisamos criar os estados, transições e estado(s) final(is) que representam essa condição.
O AFD terá quatro estados principais:
Estado inicial (q0): Representa o início de qualquer string.
Estado para strings com o primeiro caractere "a" (q1): Representa o estado após encontrar o primeiro caractere "a".
Estado para strings com exatamente dois "b"s (q2): Representa o estado após encontrar os dois "b"s.
Estado final para strings que terminam com "cc" (q3): Representa o estado após encontrar os caracteres "cc" no final da string.
Os estados q2 e q3 são finais, pois indicam que a string satisfaz as condições desejadas (duas ocorrências de "b" e "cc" no final).

Transições do AFD:
De q0 para q1: Ao encontrar o primeiro caractere "a".
De q1 para q2: Ao encontrar um "b".
De q2 para q3: Ao encontrar outro "b".
De q3 para si mesmo (loop): Ao encontrar "c". Qualquer outro caractere retorna ao estado q0.

Aqui está o AFD completo em forma de tabela:
| Estado Atual | Próximo Estado (a) | Próximo Estado (b) | Próximo Estado (c) |
|--------------|--------------------|--------------------|--------------------|
|     q0       |       q1           |       q0           |       q0           |
|     q1       |       q0           |       q2           |       q0           |
|     q2       |       q0           |       q3           |       q0           |
|     q3       |       q0           |       q0           |       q0           |

*/

#include <stdio.h>
#include <stdbool.h>

// Função que verifica se a string satisfaz a condição do AFD
bool isStringValid(char str[]) {
    int currentState = 0; // Estado inicial (q0)
    int bCount = 0; // Contador de ocorrências de 'b'

    for (int i = 0; str[i] != '\0'; i++) {
        char currentChar = str[i];

        switch (currentState) {
            case 0: // q0
                if (currentChar == 'a')
                    currentState = 1; // q1 (ao encontrar o primeiro 'a')
                else
                    currentState = 0; // Continua em q0
                break;

            case 1: // q1
                if (currentChar == 'b') {
                    currentState = 2; // q2 (ao encontrar o primeiro 'b')
                    bCount = 1;
                } else if (currentChar == 'a')
                    currentState = 1; // Continua em q1 (loop)
                else
                    currentState = 0; // Retorna a q0
                break;

            case 2: // q2
                if (currentChar == 'b') {
                    currentState = 3; // q3 (ao encontrar o segundo 'b')
                    bCount = 2;
                } else if (currentChar == 'a')
                    currentState = 1; // Retorna a q1
                else
                    currentState = 0; // Retorna a q0
                break;

            case 3: // q3
                if (currentChar == 'c')
                    currentState = 3; // Continua em q3 (loop)
                else
                    currentState = 0; // Retorna a q0
                break;
        }
    }

    // A string é válida se ela terminar em q3 (dois 'b's e termina com 'cc')
    return currentState == 3 && bCount == 2;
}

int main() {
    char str1[] = "abcbcc"; // String válida (começa com 'a', dois 'b's e termina com 'cc')
    char str2[] = "abbcc";  // String inválida (não começa com 'a')
    char str3[] = "abbcbcc"; // String inválida (começa com 'a', mas tem três 'b's)
    char str4[] = "acc";    // String inválida (começa com 'a', mas não tem 'b's)
    char str5[] = "abcb";   // String inválida (começa com 'a', mas não tem 'cc' no final)

    if (isStringValid(str1)) {
        printf("%s é uma string válida.\n", str1); // Output: abcbcc é uma string válida.
    } else {
        printf("%s é uma string inválida.\n", str1);
    }

    if (isStringValid(str2)) {
        printf("%s é uma string válida.\n", str2);
    } else {
        printf("%s é uma string inválida.\n", str2); // Output: abbcc é uma string inválida.
    }

    if (isStringValid(str3)) {
        printf("%s é uma string válida.\n", str3);
    } else {
        printf("%s é uma string inválida.\n", str3); // Output: abbcbcc é uma string inválida.
    }

    if (isStringValid(str4)) {
        printf("%s é uma string válida.\n", str4);
    } else {
        printf("%s é uma string inválida.\n", str4); // Output: acc é uma string inválida.
    }

    if (isStringValid(str5)) {
        printf("%s é uma string válida.\n", str5);
    } else {
        printf("%s é uma string inválida.\n", str5); // Output: abcb é uma string inválida.
    }

    return 0;
}

/*
A função isStringValid verifica se a string satisfaz as condições do AFD e retorna true se for válida ou false caso contrário. Os exemplos de strings mostram o resultado para uma string válida e inválida de acordo com a condição do AFD.
*/
