#include <stdio.h>
#include <string.h> // Pois o console do Codespaces estava acusando um problema na linha 25 e 45, onde resolvi o problema do \n inserido pelo fgets.
int main(){
    // Declaração de variáveis:
    char estado1[20], estado2[20];
    char codigo1[4], codigo2[4];
    char cidade1[30], cidade2[30];
    int populacao1, populacao2;
    float areakm1, areakm2;
    float pib1, pib2, pibCap1, pibCap2, denPop1, denPop2;
    int tour1, tour2;
    int resPop, resTour, resArea, resPib, resPibCap, resDenPop, resSuper;
    double super1, super2;

    // Entrada dos dados (Carta 1):
    printf("====SUPER  TRUNFO====\n");
    printf("| CADASTRO DA CARTA 1 |\n");
    printf("Digite o NOME DO ESTADO: ");
    fgets(estado1, 20, stdin);
    estado1[strcspn(estado1, "\n")] = 0; // Remove o '\n' que o fgets recebe da entrada.
    printf("Digite o CÓDIGO DA CARTA: ");
    scanf("%s", codigo1);
    getchar(); // Limpa o buffer do teclado e evita que o fgets seja pulado.
    printf("Digite o NOME DA CIDADE: ");
    fgets(cidade1, 30, stdin);
    cidade1[strcspn(cidade1, "\n")] = 0; // Remove o '\n' que o fgets recebe da entrada.
    printf("Digite a POPULAÇÃO: ");
    scanf("%d", &populacao1);
    printf("Digite a ÁREA EM KM²: ");
    scanf("%f", &areakm1);
    printf("Digite o PIB (Produto Interno Bruto) da cidade: ");
    scanf("%f", &pib1);
    printf("Digite quantos PONTOS TURÍSTICOS a cidade tem: ");
    scanf("%d", &tour1);
    getchar(); // Limpa o buffer do teclado novamente antes de ler a próxima entrada.

    // Entrada dos dados (Carta 2):
    printf("\n| CADASTRO DA CARTA 2 |\n");
    printf("Digite o NOME DO ESTADO: ");
    fgets(estado2, 20, stdin);
    estado2[strcspn(estado2, "\n")] = 0;
    printf("Digite o CÓDIGO DA CARTA: ");
    scanf("%s", codigo2);
    getchar();
    printf("Digite o NOME DA CIDADE: ");
    fgets(cidade2, 30, stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;
    printf("Digite a POPULAÇÃO: ");
    scanf("%d", &populacao2);
    printf("Digite a ÁREA EM KM²: ");
    scanf("%f", &areakm2);
    printf("Digite o PIB (Produto Interno Bruto) da cidade: ");
    scanf("%f", &pib2);
    printf("Digite quantos PONTOS TURÍSTICOS a cidade tem: ");
    scanf("%d", &tour2);

    // Processamento dos dados:
    denPop1 = populacao1 / areakm1;
    pibCap1 = (pib1 * 1000000000) / populacao1;
    denPop2 = populacao2 / areakm2;
    pibCap2 = (pib2 * 1000000000) / populacao2;
    super1 = populacao1+areakm1+pib1+tour1-denPop1+pibCap1;
    super2 = populacao2+areakm2+pib2+tour2-denPop2+pibCap2;

    // Exibição dos dados;
    printf("======SUPER - TRUNFO======\n");
    printf("|====DADOS DA CARTA 1====|\n");
    printf("ESTADO- %s\n", estado1);
    printf("CÓDIGO DA CARTA- %s\n", codigo1);
    printf("CIDADE- %s\n", cidade1);
    printf("POPULAÇÃO- %d\n", populacao1);
    printf("ÁREA EM KM²- %.2f\n", areakm1);
    printf("PIB- %.2f bilhões de reais\n", pib1);
    printf("PONTOS TURÍSTICOS- %d\n", tour1);
    printf("DENSIDADE POPULACIONAL- %.2f hab/km²\n", denPop1);
    printf("PIB PER CAPITA- %.2f reais\n", pibCap1);
    printf("SUPER PODER- %.2f\n\n", super1);

    printf("|====DADOS DA CARTA 2====|\n");
    printf("ESTADO- %s\n", estado2);
    printf("CÓDIGO DA CARTA- %s\n", codigo2);
    printf("CIDADE- %s\n", cidade2);
    printf("POPULAÇÃO- %d\n", populacao2);
    printf("ÁREA EM KM²- %.2f\n", areakm2);
    printf("PIB- %.2f bilhões de reais\n", pib2);
    printf("PONTOS TURÍSTICOS- %d\n", tour2);
    printf("DENSIDADE POPULACIONAL- %.2f hab/km²\n", denPop2);
    printf("PIB PER CAPITA- %.2f reais\n", pibCap2);
    printf("SUPER PODER- %.3f\n\n", super2);

    // Estrutura condicional para comparação de um atributo de duas cartas
    printf("=====COMPARAÇÃO DAS CARTAS======\n");
    printf("ATRIBUTO: DENSIDADE POPULACIONAL\n");
    printf("Carta 1 - %s (%s): %.2f hab/km²\n", cidade1, estado1, denPop1);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", cidade2, estado2, denPop2);
    if (denPop1 < denPop2) {
        printf("Resultado: Carta 1 (%s) venceu!!\n", cidade1);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!!\n", cidade2);
    }
    return 0;
}