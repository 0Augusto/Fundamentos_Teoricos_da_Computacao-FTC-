/*
Para definir recursivamente a operação de multiplicação sobre os números naturais (N) usando sucessor e a operação de adição, podemos adotar a seguinte abordagem:

A ideia é que a multiplicação de dois números naturais, a e b, pode ser definida como a adição de a com o resultado da multiplicação de a e (b-1). O caso base para a recursão é quando b é igual a 0, onde qualquer número multiplicado por 0 é igual a 0.

Na função multiply, utilizamos a estrutura de controle if...else para definir o caso base quando b é igual a 0, retornando 0. Nos outros casos, retornamos a soma de a com o resultado da multiplicação entre a e (b-1).

Ordem de complexidade: A ordem de complexidade dessa função recursiva de multiplicação é O(b), pois a função é chamada b vezes em cada chamada recursiva, onde b é o segundo argumento da multiplicação. Portanto, a complexidade aumenta linearmente com o valor de b.
*/

#include <stdio.h>

// Função de multiplicação recursiva usando sucessor e adição
int multiply(int a, int b) {
    if (b == 0) {
        return 0; // Caso base: qualquer número multiplicado por 0 é 0.
    } else {
        return a + multiply(a, b - 1); // Recursão: a * b = a + a * (b - 1)
    }
}

int main() {
    int num1 = 5;
    int num2 = 3;

    int result = multiply(num1, num2);
    printf("%d * %d = %d\n", num1, num2, result); // Output: 5 * 3 = 15

    return 0;
}

