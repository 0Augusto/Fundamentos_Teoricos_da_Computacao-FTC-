#include <stdio.h>

// Função total e sobrejetora, mas não injetora: f(x) = x % 3
int functionTotalSurjective(int x) {
    return x % 3;
}

int main() {
    int input = 5;
    int result = functionTotalSurjective(input);
    printf("f(%d) = %d\n", input, result); // f(5) = 2
    return 0;
}

