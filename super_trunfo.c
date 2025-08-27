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

    // Processando a comparação dos dados das duas cartas:
    resPop = populacao1 > populacao2;
    resArea = areakm1 > areakm2;
    resPib = pib1 > pib2;
    resTour = tour1 > tour2;
    resDenPop = denPop1 < denPop2;
    resPibCap = pibCap1 > pibCap2;
    resSuper = super1 > super2;

    //Exibindo a comparação dos dados das duas cartas:
    printf("======SUPER - TRUNFO======\n");
    printf("====BATALHA DE CARTAS====\n");
    printf("1 = VITÓRIA DE %s!! 0 = VITÓRIA DE %s!!\n", cidade1, cidade2);
    printf("População: %d: \n", resPop);
    printf("Área em km²: %d\n", resArea);
    printf("PIB (Produto Interno Bruto): %d\n", resPib);
    printf("Pontos turísticos: %d\n", resTour);
    printf("Densidade Populacional: %d\n", resDenPop);
    printf("PIB per capta: %d\n", resPibCap);
    printf("Super-Poder: %d\n\n", resSuper);
    return 0;
}