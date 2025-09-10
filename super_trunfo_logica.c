#include <stdio.h>
#include <string.h>

const char* nomeAtributo(int op) {
    switch(op) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos turisticos";
        case 5: return "Densidade";
        default: return "Desconhecido";
    }
}

double valorAtributo(int op, int pop, double area, double pib, int pontos, double dens) {
    switch(op) {
        case 1: return (double) pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (double) pontos;
        case 5: return dens;
        default: return 0.0;
    }
}

int vencedorPorAtributo(int op, double v1, double v2) {
    if (v1 == v2) return 0;
    if (op == 5) { 
        return (v1 < v2) ? 1 : 2;
    } else {      
        return (v1 > v2) ? 1 : 2;
    }
}

int main() {
    char cidade1[40] = "Gramado";
    char estado1[4] = "RS";
    int populacao1 = 123000;
    double area1 = 200.5;
    double pib1 = 1555000.0;
    int pontos1 = 20;

    char cidade2[40] = "São José dos Campos";
    char estado2[4] = "SP";
    int populacao2 = 600000;
    double area2 = 2000.0;
    double pib2 = 1555000.0;
    int pontos2 = 20;

    double densidade1 = (area1 != 0.0) ? (double)populacao1 / area1 : 0.0;
    double densidade2 = (area2 != 0.0) ? (double)populacao2 / area2 : 0.0;

    int op1, op2;

    printf("Escolha o 1o atributo:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos turisticos\n5 - Densidade demografica\n");
    printf("Opcao: ");
    if (scanf("%d", &op1) != 1 || op1 < 1 || op1 > 5) {
        printf("Opcao invalida. Encerrando.\n");
        return 1;
    }

    printf("\nEscolha o 2o atributo (diferente do %s):\n", nomeAtributo(op1));
    for (int i = 1; i <= 5; i++) {
        if (i != op1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Opcao: ");
    if (scanf("%d", &op2) != 1 || op2 < 1 || op2 > 5 || op2 == op1) {
        printf("Opcao invalida (deve ser diferente do primeiro). Encerrando.\n");
        return 1;
    }

    double v1a = valorAtributo(op1, populacao1, area1, pib1, pontos1, densidade1);
    double v2a = valorAtributo(op1, populacao2, area2, pib2, pontos2, densidade2);
    double v1b = valorAtributo(op2, populacao1, area1, pib1, pontos1, densidade1);
    double v2b = valorAtributo(op2, populacao2, area2, pib2, pontos2, densidade2);

    double soma1 = v1a + v1b;
    double soma2 = v2a + v2b;

    printf("\n=== Comparacao ===\n");
    printf("%s (%s)\n  %s = %.2f, %s = %.2f  -> Soma = %.2f\n\n",
           cidade1, estado1,
           nomeAtributo(op1), v1a,
           nomeAtributo(op2), v1b, soma1);

    printf("%s (%s)\n  %s = %.2f, %s = %.2f  -> Soma = %.2f\n\n",
           cidade2, estado2,
           nomeAtributo(op1), v2a,
           nomeAtributo(op2), v2b, soma2);

    int winA = vencedorPorAtributo(op1, v1a, v2a);
    int winB = vencedorPorAtributo(op2, v1b, v2b);

    if (winA == 1) printf("Vencedor do atributo '%s': %s\n", nomeAtributo(op1), cidade1);
    else if (winA == 2) printf("Vencedor do atributo '%s': %s\n", nomeAtributo(op1), cidade2);
    else printf("Empate no atributo '%s'\n", nomeAtributo(op1));

    if (winB == 1) printf("Vencedor do atributo '%s': %s\n", nomeAtributo(op2), cidade1);
    else if (winB == 2) printf("Vencedor do atributo '%s': %s\n", nomeAtributo(op2), cidade2);
    else printf("Empate no atributo '%s'\n", nomeAtributo(op2));

    const char *resultadoFinal = (soma1 == soma2) ? "Empate!" : (soma1 > soma2 ? cidade1 : cidade2);
    if (soma1 == soma2) printf("\nResultado final: Empate!\n");
    else printf("\nVencedor final: %s\n", resultadoFinal);

    return 0;
}
