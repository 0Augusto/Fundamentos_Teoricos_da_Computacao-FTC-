/*
@author: Henrique Augusto
*/

#include <stdio.h>

// Função não total, mas injetora e sobrejetora: f(x) = |x|
unsigned int functionInjectiveSurjective(int x) {
    return (x < 0) ? -x : x;
}

int main() {
    int input = -3;
    unsigned int result = functionInjectiveSurjective(input);
    printf("f(%d) = %u\n", input, result); // f(-3) = 3
    return 0;
}

