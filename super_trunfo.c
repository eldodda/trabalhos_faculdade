#include <stdio.h>
int main(){
    //Declaração de variáveis:
    char estado1[20], estado2[20];
    char codigo1[4], codigo2[4];
    char cidade1[30], cidade2[30];
    int populacao1, populacao2;
    float areakm1, areakm2;
    float pib1, pib2;
    int tour1, tour2;

    //Entrada dos dados (Carta 1):
    printf("====SUPER  TRUNFO====\n");
    printf("| CADASTRO DA CARTA 1 |\n");
    printf("Digite o NOME DO ESTADO: ");
    fgets(estado1, 20, stdin);
    printf("Digite o CÓDIGO DA CARTA: ");
    scanf("%s", codigo1);
    getchar(); // Limpa o buffer do teclado e evitar que o fgets seja pulado.
    printf("Digite o NOME DA CIDADE: ");
    fgets(cidade1, 30, stdin);
    printf("Digite a POPULAÇÃO: ");
    scanf("%d", &populacao1);
    printf("Digite a ÁREA EM KM²: ");
    scanf("%f", &areakm1);
    printf("Digite o PIB (Produto Interno Bruto) da cidade: ");
    scanf("%f", &pib1);
    printf("Digite quantos PONTOS TURÍSTICOS a cidade tem: ");
    scanf("%d", &tour1);
    getchar(); // Limpa o buffer do teclado novamente antes de ler a próxima entrada.

    //Entrada dos dados (Carta 2):
    printf("\n| CADASTRO DA CARTA 2 |\n");
    printf("Digite o NOME DO ESTADO: ");
    fgets(estado2, 20, stdin);
    printf("Digite o CÓDIGO DA CARTA: ");
    scanf("%s", codigo2);
    getchar();
    printf("Digite o NOME DA CIDADE: ");
    fgets(cidade2, 30, stdin);
    printf("Digite a POPULAÇÃO: ");
    scanf("%d", &populacao2);
    printf("Digite a ÁREA EM KM²: ");
    scanf("%f", &areakm2);
    printf("Digite o PIB (Produto Interno Bruto) da cidade: ");
    scanf("%f", &pib2);
    printf("Digite quantos PONTOS TURÍSTICOS a cidade tem: ");
    scanf("%d", &tour2);

    //Exibição dos dados;
    printf("======SUPER - TRUNFO======\n");
    printf("|====DADOS DA CARTA 1====|\n");
    printf("ESTADO- %s", estado1);
    printf("CÓDIGO DA CARTA- %s\n", codigo1);
    printf("CIDADE- %s", cidade1);
    printf("POPULAÇÃO- %d\n", populacao1);
    printf("ÁREA EM KM²- %.2f\n", areakm1);
    printf("PIB- %.2f\n", pib1);
    printf("PONTOS TURÍSTICOS- %d\n\n", tour1);
    
    printf("|====DADOS DA CARTA 2====|\n");
    printf("ESTADO- %s", estado2);
    printf("CÓDIGO DA CARTA- %s\n", codigo2);
    printf("CIDADE- %s", cidade2);
    printf("POPULAÇÃO- %d\n", populacao2);
    printf("ÁREA EM KM²- %.2f\n", areakm2);
    printf("PIB- %.2f\n", pib2);
    printf("PONTOS TURÍSTICOS- %d\n", tour2);
    return 0;
}