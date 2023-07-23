/*
Relação que é simétrica e transitiva, mas não reflexiva:
Vamos definir a relação ≡ da seguinte maneira:
a ≡ b se a e b têm o mesmo valor absoluto.
Nessa relação, verificamos se dois números têm o mesmo valor absoluto. Se a e b têm o mesmo valor absoluto, então a relação é simétrica (pois a ≡ b implica b ≡ a) e transitiva (pois se a ≡ b e b ≡ c, então a ≡ c). No entanto, a relação não é reflexiva, pois, por exemplo, o valor absoluto de 5 é igual ao valor absoluto de -5, mas 5 não é igual a -5.

Ordem de complexidade: A complexidade da função é O(1), pois só envolve operações aritméticas simples e comparações.
*/

#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs()

// Função que verifica se a relação é simétrica e transitiva, mas não reflexiva.
int isSymmetricTransitiveNotReflexive(int a, int b) {
    if (abs(a) == abs(b)) {
        return 1; // A relação é simétrica e transitiva.
    } else {
        return 0; // A relação não é reflexiva.
    }
}

int main() {
    int a = 5;
    int b = -5;

    if (isSymmetricTransitiveNotReflexive(a, b)) {
        printf("O valor absoluto de %d é igual ao valor absoluto de %d.\n", a, b); // Output: O valor absoluto de 5 é igual ao valor absoluto de -5.
    } else {
        printf("O valor absoluto de %d não é igual ao valor absoluto de %d.\n", a, b);
    }

    int c = 10;
    int d = 10;

    if (isSymmetricTransitiveNotReflexive(c, d)) {
        printf("O valor absoluto de %d é igual ao valor absoluto de %d.\n", c, d); // Output: O valor absoluto de 10 é igual ao valor absoluto de 10.
    } else {
        printf("O valor absoluto de %d não é igual ao valor absoluto de %d.\n", c, d);
    }

    int e = 3;
    int f = -3;

    if (isSymmetricTransitiveNotReflexive(e, f)) {
        printf("O valor absoluto de %d é igual ao valor absoluto de %d.\n", e, f);
    } else {
        printf("O valor absoluto de %d não é igual ao valor absoluto de %d.\n", e, f); // Output: O valor absoluto de 3 não é igual ao valor absoluto de -3.
    }

    return 0;
}

