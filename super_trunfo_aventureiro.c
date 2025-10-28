#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma cidade
struct Cidade {
    char nome[50];
    int populacao;
    float area;
    float pib; // em bilhoes
    int pontosTuristicos;
};

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char estado[50];
    char codigo[4];
    struct Cidade cidade;
    float densidade;    // populacao / area
    float pibPerCapita; // PIB / populacao
};

// Funcao para ler os dados de uma carta
void lerCarta(struct Carta *carta, int numeroCarta) {
    printf("\n=== Cadastro da Carta %d ===\n", numeroCarta);

    printf("Digite o nome do Estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Digite o codigo da carta (ex: A01): ");
    scanf(" %s", carta->codigo);

    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", carta->cidade.nome);

    printf("Digite a populacao: ");
    scanf("%d", &carta->cidade.populacao);

    printf("Digite a area em km2: ");
    scanf("%f", &carta->cidade.area);

    printf("Digite o PIB em bilhoes: ");
    scanf("%f", &carta->cidade.pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->cidade.pontosTuristicos);

    // Calcula atributos derivados
    carta->densidade = carta->cidade.populacao / carta->cidade.area;
    carta->pibPerCapita = (carta->cidade.pib * 1000000000) / carta->cidade.populacao;
}

// Funcao para exibir os dados de uma carta
void exibirCarta(struct Carta carta, int numeroCarta) {
    printf("\n=== Carta %d ===\n", numeroCarta);
    printf("Estado: %s\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade.nome);
    printf("Populacao: %d\n", carta.cidade.populacao);
    printf("Area: %.2f km2\n", carta.cidade.area);
    printf("PIB: %.2f bilhoes\n", carta.cidade.pib);
    printf("Pontos Turisticos: %d\n", carta.cidade.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidade);
    printf("PIB per Capita: %.2f R$\n", carta.pibPerCapita);
}

// Funcao para comparar duas cartas com base em um atributo
void compararCartas(struct Carta c1, struct Carta c2) {
    // Aqui escolhemos o atributo a ser comparado
    // Opcoes: "populacao", "area", "pib", "densidade", "pibPerCapita"
    char atributo[20] = "populacao"; // troque aqui se quiser outro atributo

    printf("\n=== Comparacao de cartas (Atributo: %s) ===\n", atributo);

    if (strcmp(atributo, "populacao") == 0) {
        printf("Carta 1 - %s: %d\n", c1.cidade.nome, c1.cidade.populacao);
        printf("Carta 2 - %s: %d\n", c2.cidade.nome, c2.cidade.populacao);
        if (c1.cidade.populacao > c2.cidade.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade.nome);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade.nome);
        }
    } else if (strcmp(atributo, "area") == 0) {
        printf("Carta 1 - %s: %.2f\n", c1.cidade.nome, c1.cidade.area);
        printf("Carta 2 - %s: %.2f\n", c2.cidade.nome, c2.cidade.area);
        if (c1.cidade.area > c2.cidade.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade.nome);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade.nome);
        }
    } else if (strcmp(atributo, "pib") == 0) {
        printf("Carta 1 - %s: %.2f\n", c1.cidade.nome, c1.cidade.pib);
        printf("Carta 2 - %s: %.2f\n", c2.cidade.nome, c2.cidade.pib);
        if (c1.cidade.pib > c2.cidade.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade.nome);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade.nome);
        }
    } else if (strcmp(atributo, "densidade") == 0) {
        printf("Carta 1 - %s: %.2f\n", c1.cidade.nome, c1.densidade);
        printf("Carta 2 - %s: %.2f\n", c2.cidade.nome, c2.densidade);
        if (c1.densidade < c2.densidade) { // menor vence
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade.nome);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade.nome);
        }
    } else if (strcmp(atributo, "pibPerCapita") == 0) {
        printf("Carta 1 - %s: %.2f\n", c1.cidade.nome, c1.pibPerCapita);
        printf("Carta 2 - %s: %.2f\n", c2.cidade.nome, c2.pibPerCapita);
        if (c1.pibPerCapita > c2.pibPerCapita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade.nome);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade.nome);
        }
    } else {
        printf("Atributo invalido!\n");
    }
}

int main() {
    struct Carta carta1, carta2;

    printf("=== Super Trunfo - Nivel Novato ===\n");

    // Cadastro das cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibicao das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparacao das cartas
    compararCartas(carta1, carta2);

    return 0;
}