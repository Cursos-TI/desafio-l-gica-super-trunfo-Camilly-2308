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
    float densidade;   // populacao / area
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

// Funcao para exibir uma carta
void exibirCarta(struct Carta carta, int numeroCarta) {
    printf("\n--- Carta %d ---\n", numeroCarta);
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

// Funcao para retornar valor do atributo escolhido
float valorAtributo(struct Carta carta, int atributo) {
    switch(atributo) {
        case 1: return carta.cidade.populacao;
        case 2: return carta.cidade.area;
        case 3: return carta.cidade.pib;
        case 4: return carta.cidade.pontosTuristicos;
        case 5: return carta.densidade;
        case 6: return carta.pibPerCapita;
        default: return 0;
    }
}

// Funcao para retornar nome do atributo
const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "";
    }
}

// Funcao para mostrar menu de atributos
void mostrarMenu(int atributoExcluido) {
    printf("\nEscolha o atributo para comparar:\n");
    if(atributoExcluido != 1) printf("1 - Populacao\n");
    if(atributoExcluido != 2) printf("2 - Area\n");
    if(atributoExcluido != 3) printf("3 - PIB\n");
    if(atributoExcluido != 4) printf("4 - Pontos Turisticos\n");
    if(atributoExcluido != 5) printf("5 - Densidade Populacional\n");
    if(atributoExcluido != 6) printf("6 - PIB per Capita\n");
}

int main() {
    struct Carta carta1, carta2;
    int atributo1, atributo2;
    float valor1_1, valor1_2, valor2_1, valor2_2;
    float soma1, soma2;

    printf("=== Super Trunfo - Nivel Mestre ===\n");

    // Cadastro das cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibir cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Menu atributo 1
    mostrarMenu(0);
    printf("Escolha o primeiro atributo (numero): ");
    scanf("%d", &atributo1);

    // Menu atributo 2 (sem repetir o 1)
    mostrarMenu(atributo1);
    printf("Escolha o segundo atributo (numero, diferente do primeiro): ");
    scanf("%d", &atributo2);

    // Valores dos atributos
    valor1_1 = valorAtributo(carta1, atributo1);
    valor2_1 = valorAtributo(carta2, atributo1);
    valor1_2 = valorAtributo(carta1, atributo2);
    valor2_2 = valorAtributo(carta2, atributo2);

    // Mostrar comparacao de cada atributo
    printf("\n=== Comparacao de Atributos ===\n");

    // Atributo 1
    printf("\nAtributo 1: %s\n", nomeAtributo(atributo1));
    printf("Carta 1: %.2f\n", valor1_1);
    printf("Carta 2: %.2f\n", valor2_1);
    if(atributo1 == 5) { // densidade menor vence
        if(valor1_1 < valor2_1)
            printf("Resultado: Carta 1 venceu!\n");
        else if(valor1_1 > valor2_1)
            printf("Resultado: Carta 2 venceu!\n");
        else
            printf("Resultado: Empate!\n");
    } else {
        if(valor1_1 > valor2_1)
            printf("Resultado: Carta 1 venceu!\n");
        else if(valor1_1 < valor2_1)
            printf("Resultado: Carta 2 venceu!\n");
        else
            printf("Resultado: Empate!\n");
    }

    // Atributo 2
    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("Carta 1: %.2f\n", valor1_2);
    printf("Carta 2: %.2f\n", valor2_2);
    if(atributo2 == 5) { // densidade menor vence
        if(valor1_2 < valor2_2)
            printf("Resultado: Carta 1 venceu!\n");
        else if(valor1_2 > valor2_2)
            printf("Resultado: Carta 2 venceu!\n");
        else
            printf("Resultado: Empate!\n");
    } else {
        if(valor1_2 > valor2_2)
            printf("Resultado: Carta 1 venceu!\n");
        else if(valor1_2 < valor2_2)
            printf("Resultado: Carta 2 venceu!\n");
        else
            printf("Resultado: Empate!\n");
    }

    // Soma dos atributos
    soma1 = valor1_1 + valor1_2;
    soma2 = valor2_1 + valor2_2;

    printf("\n=== Resultado Final ===\n");
    printf("Carta 1 (%.2f) vs Carta 2 (%.2f)\n", soma1, soma2);

    if(soma1 > soma2)
        printf("Carta 1 venceu!\n");
    else if(soma2 > soma1)
        printf("Carta 2 venceu!\n");
    else
        printf("Empate!\n");

    return 0;
}