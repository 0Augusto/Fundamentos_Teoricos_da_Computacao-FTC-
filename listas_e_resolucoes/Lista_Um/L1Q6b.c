/*
Relação que é reflexiva e transitiva, mas não simétrica:
Vamos definir a relação ≡ da seguinte maneira:
a ≡ b se a é divisível por b.
Nessa relação, verificamos se um número é divisível por outro. Se a for divisível por b, então a relação é reflexiva (pois a é sempre divisível por si mesmo) e transitiva (pois se a é divisível por b e b é divisível por c, então a é divisível por c). No entanto, a relação não é simétrica, pois, por exemplo, 6 é divisível por 2, mas 2 não é divisível por 6.

Ordem de complexidade: A complexidade da função é O(1), pois só envolve operações aritméticas simples e comparações.
*/
#include <stdio.h>

// Função que verifica se a relação é reflexiva e transitiva, mas não simétrica.
int isReflexiveTransitiveNotSymmetric(int a, int b) {
    if (a % b == 0) {
        return 1; // A relação é reflexiva e transitiva.
    } else {
        return 0; // A relação não é simétrica.
    }
}

int main() {
    int a = 6;
    int b = 2;

    if (isReflexiveTransitiveNotSymmetric(a, b)) {
        printf("%d é divisível por %d.\n", a, b); // Output: 6 é divisível por 2.
    } else {
        printf("%d não é divisível por %d.\n", a, b);
    }

    int c = 8;
    int d = 4;

    if (isReflexiveTransitiveNotSymmetric(c, d)) {
        printf("%d é divisível por %d.\n", c, d); // Output: 8 é divisível por 4.
    } else {
        printf("%d não é divisível por %d.\n", c, d);
    }

    int e = 4;
    int f = 6;

    if (isReflexiveTransitiveNotSymmetric(e, f)) {
        printf("%d é divisível por %d.\n", e, f);
    } else {
        printf("%d não é divisível por %d.\n", e, f); // Output: 4 não é divisível por 6.
    }

    return 0;
}

