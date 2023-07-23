/*
Para fornecer relações que atendam às condições especificadas, vamos considerar X como um conjunto de números inteiros.

Relação que é reflexiva e simétrica, mas não transitiva:
Vamos definir a relação ≡ da seguinte maneira:
a ≡ b se a e b possuírem a mesma paridade (ambos são pares ou ambos são ímpares).
Nessa relação, verificamos se dois números têm a mesma paridade. Se tiverem, a relação é reflexiva e simétrica, pois a ≡ a para todo a e, se a ≡ b, então b ≡ a. No entanto, a relação não é transitiva, pois, por exemplo, 2 ≡ 4 e 4 ≡ 6, mas 2 não ≡ 6.

Ordem de complexidade: A complexidade da função é O(1), pois só envolve operações aritméticas simples e comparações.
*/
#include <stdio.h>

// Função que verifica se a relação é reflexiva e simétrica, mas não transitiva.
int isReflexiveSymmetricNotTransitive(int a, int b) {
    if (a % 2 == b % 2) {
        return 1; // A relação é reflexiva e simétrica.
    } else {
        return 0; // A relação não é transitiva.
    }
}

int main() {
    int a = 2;
    int b = 4;

    if (isReflexiveSymmetricNotTransitive(a, b)) {
        printf("%d e %d possuem a mesma paridade.\n", a, b); // Output: 2 e 4 possuem a mesma paridade.
    } else {
        printf("%d e %d não possuem a mesma paridade.\n", a, b);
    }

    int c = 3;
    int d = 5;

    if (isReflexiveSymmetricNotTransitive(c, d)) {
        printf("%d e %d possuem a mesma paridade.\n", c, d); // Output: 3 e 5 possuem a mesma paridade.
    } else {
        printf("%d e %d não possuem a mesma paridade.\n", c, d);
    }

    int e = 2;
    int f = 3;

    if (isReflexiveSymmetricNotTransitive(e, f)) {
        printf("%d e %d possuem a mesma paridade.\n", e, f);
    } else {
        printf("%d e %d não possuem a mesma paridade.\n", e, f); // Output: 2 e 3 não possuem a mesma paridade.
    }

    return 0;
}

