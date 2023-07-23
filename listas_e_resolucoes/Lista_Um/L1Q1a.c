#include <stdio.h>

// Função total e injetora, mas não sobrejetora: f(x) = 2x
int functionTotalInjective(int x) {
    return 2 * x;
}

int main() {
    int input = 5;
    int result = functionTotalInjective(input);
    printf("f(%d) = %d\n", input, result); // f(5) = 10
    return 0;
}

