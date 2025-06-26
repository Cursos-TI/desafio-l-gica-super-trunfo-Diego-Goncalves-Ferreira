#include <stdio.h>
#include <string.h>

// Função auxiliar para exibir o nome do atributo
const char* nome_atributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função auxiliar para pegar valor do atributo
float get_valor(int atributo, unsigned long int pop, float area, float PIB, int pt, float dens) {
    switch (atributo) {
        case 1: return (float)pop;
        case 2: return area;
        case 3: return PIB;
        case 4: return (float)pt;
        case 5: return dens;
        default: return 0;
    }
}

int main() {
    char buffer[100];

    // --- Cadastro da Carta 1 ---
    char nome_cidade_1[50];
    unsigned long int populacao_1;
    float area_1, PIB_1, densidade_1;
    int pontos_turisticos_1;

    printf("Cadastro da Carta 1:\n");

    printf("Nome do país: ");
    fgets(nome_cidade_1, 50, stdin);
    nome_cidade_1[strcspn(nome_cidade_1, "\n")] = '\0';

    printf("População: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lu", &populacao_1);

    printf("Área (km²): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &area_1);

    printf("PIB: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &PIB_1);

    printf("Pontos turísticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &pontos_turisticos_1);

    densidade_1 = populacao_1 / area_1;

    // --- Cadastro da Carta 2 ---
    char nome_cidade_2[50];
    unsigned long int populacao_2;
    float area_2, PIB_2, densidade_2;
    int pontos_turisticos_2;

    printf("\nCadastro da Carta 2:\n");

    printf("Nome do país: ");
    fgets(nome_cidade_2, 50, stdin);
    nome_cidade_2[strcspn(nome_cidade_2, "\n")] = '\0';

    printf("População: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lu", &populacao_2);

    printf("Área (km²): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &area_2);

    printf("PIB: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &PIB_2);

    printf("Pontos turísticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &pontos_turisticos_2);

    densidade_2 = populacao_2 / area_2;

    // --- Menu de Escolha de Atributos ---
    int atributo1 = 0, atributo2 = 0;

    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade demográfica (vence o menor)\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida para o primeiro atributo!\n");
        return 1;
    }

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            printf("%d - %s\n", i, nome_atributo(i));
        }
    }
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida para o segundo atributo!\n");
        return 1;
    }

    // --- Comparação e Soma ---
    float valor1_c1 = get_valor(atributo1, populacao_1, area_1, PIB_1, pontos_turisticos_1, densidade_1);
    float valor1_c2 = get_valor(atributo1, populacao_2, area_2, PIB_2, pontos_turisticos_2, densidade_2);
    float valor2_c1 = get_valor(atributo2, populacao_1, area_1, PIB_1, pontos_turisticos_1, densidade_1);
    float valor2_c2 = get_valor(atributo2, populacao_2, area_2, PIB_2, pontos_turisticos_2, densidade_2);

    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    // --- Exibição do Resultado ---
    printf("\n--- COMPARAÇÃO ENTRE %s e %s ---\n", nome_cidade_1, nome_cidade_2);

    printf("\nAtributo 1: %s\n", nome_atributo(atributo1));
    printf("%s: %.2f\n", nome_cidade_1, valor1_c1);
    printf("%s: %.2f\n", nome_cidade_2, valor1_c2);
    int v1 = (atributo1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : (valor1_c2 < valor1_c1 ? 2 : 0))
                              : (valor1_c1 > valor1_c2 ? 1 : (valor1_c2 > valor1_c1 ? 2 : 0));
    printf("Resultado: %s\n", v1 == 1 ? nome_cidade_1 : v1 == 2 ? nome_cidade_2 : "Empate");

    printf("\nAtributo 2: %s\n", nome_atributo(atributo2));
    printf("%s: %.2f\n", nome_cidade_1, valor2_c1);
    printf("%s: %.2f\n", nome_cidade_2, valor2_c2);
    int v2 = (atributo2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : (valor2_c2 < valor2_c1 ? 2 : 0))
                              : (valor2_c1 > valor2_c2 ? 1 : (valor2_c2 > valor2_c1 ? 2 : 0));
    printf("Resultado: %s\n", v2 == 1 ? nome_cidade_1 : v2 == 2 ? nome_cidade_2 : "Empate");

    printf("\nSOMA DOS ATRIBUTOS:\n");
    printf("%s: %.2f\n", nome_cidade_1, soma_c1);
    printf("%s: %.2f\n", nome_cidade_2, soma_c2);

    printf("VENCEDOR FINAL: ");
    if (soma_c1 > soma_c2)
        printf("%s\n", nome_cidade_1);
    else if (soma_c2 > soma_c1)
        printf("%s\n", nome_cidade_2);
    else
        printf("Empate!\n");

    return 0;
}
