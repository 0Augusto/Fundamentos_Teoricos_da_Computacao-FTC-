#include <stdio.h>

int main() {
    int opcao;

    do {
        // Exibindo o menu
        printf("\nEscolha uma opcao:\n");
        printf("1. Σ = {a, b} de tamanho >= 2, no qual todos os a’s precedem todos os b’s.\n");
        printf("2. Σ = {a, b} que contém o substring aa.\n");
        printf("3. Σ = {a, b} que possui exatamente um par aa.\n");
        printf("4. Σ = {a, b, c} que começa com a, contém exatamente dois b’s e termina com cc.\n");
        printf("5. Σ = {a, b} que contém o substring ab e o substring ba.\n");
        printf("6. Σ = {a, b, c} que contém o substring aa, bb e cc.\n");
        printf("7. Σ = {a, b, c} no qual cada b é imediatamente seguido por pelo menos um c.\n");
        printf("8. Σ = {a, b, c} de tamanho 3.\n");
        printf("9. Σ = {a, b, c} com tamanho menor que 3.\n");
        printf("10. Σ = {a, b, c} com tamanho maior que 3.\n");
        printf("11. Σ = {a, b} com um número par de a’s e ímpar de b’s.\n");
        printf("0. Sair\n");

        scanf("%d", &opcao);

        // Executando a opção escolhida pelo usuário
        switch (opcao) {
            case 1:
                printf("Expressao regular: a*b+\n");
                break;
            case 2:
                printf("Expressao regular: (a|b)*aa(a|b)*\n");
                break;
            case 3:
                printf("Expressao regular: (a|b)*aa(a|b)*aa(a|b)*\n");
                break;
            case 4:
                printf("Expressao regular: ab*b*cc\n");
                break;
            case 5:
                printf("Expressao regular: (a|b)*(ab|ba)(a|b)*\n");
                break;
            case 6:
                printf("Expressao regular: (a|b|c)*aa(a|b|c)*bb(a|b|c)*cc(a|b|c)*\n");
                break;
            case 7:
                printf("Expressao regular: a*ba+c*\n");
                break;
            case 8:
                printf("Expressao regular: (a|b|c)(a|b|c)(a|b|c)\n");
                break;
            case 9:
                printf("Expressao regular: (a|b|c)?(a|b|c)?(a|b|c)?\n");
                break;
            case 10:
                printf("Expressao regular: (a|b|c)(a|b|c)(a|b|c)+\n");
                break;
            case 11:
                printf("Expressao regular: b*(aa)*a*\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

