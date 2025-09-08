#include <stdio.h>

int main() {
    // Dados da Carta 1
        char cidade1[30] = "Gramado";
            char estado1[3] = "SP";
                int populacao1 = 12300000;

                    // Dados da Carta 2
                        char cidade2[30] = "São José dos Campos";
                            char estado2[3] = "SP";
                                int populacao2 = 6000000;

                                    // Comparação (atributo escolhido: População)
                                        printf("Comparacao de cartas (Atributo: Populacao)\n\n");

                                            printf("Carta 1 - %s (%s): %d\n", cidade1, estado1, populacao1);
                                                printf("Carta 2 - %s (%s): %d\n", cidade2, estado2, populacao2);

                                                    if (populacao1 > populacao2) {
                                                            printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
                                                                } else if (populacao2 > populacao1) {
                                                                        printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
                                                                            } else {
                                                                                    printf("\nResultado: Empate!");
                                                                                        }

                                                                                            return 0;
                                                                                            }