#include <stdio.h>
#include <string.h> // Pois o console do Codespaces estava acusando um problema na linha 25 e 45, onde resolvi o problema do \n inserido pelo fgets.
int main(){
    // Declaração de variáveis:
    char estado1[20]="A", estado2[20]="B";
    char codigo1[4]="A01", codigo2[4]="B02";
    char cidade1[30]="São Paulo", cidade2[30]="Rio de Janeiro";
    int populacao1=12325000, populacao2=6748000;
    float areakm1=1521.11, areakm2=1200.25;
    float pib1=699.28, pib2=300.50, pibCap1, pibCap2, denPop1, denPop2;
    int tour1=50, tour2=30;
    int resPop, resTour, resArea, resPib, resPibCap, resDenPop, resSuper;
    double super1, super2;
    int opcao1, opcao2;
    float atriA1, atriA2, atriB1, atriB2;
    char *atributo1, *atributo2;
    

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
    
    printf("Escolha o PRIMEIRO ATRIBUTO para comparar:\n");
    printf("1. POPULAÇÃO\n");
    printf("2. ÁREA EM km²\n");
    printf("3. PIB\n");
    printf("4. PONTOS TURÍSTICOS\n");
    printf("5. DENSIDADE POPULACIONAL\n");
    printf("6. PIB PER CAPITA\n");
    printf("7. SUPER PODER\n");
    scanf("%d", &opcao1);
    
    printf("Escolha o SEGUNDO ATRIBUTO para comparar:\n");
    printf("1. POPULAÇÃO\n");
    printf("2. ÁREA EM km²\n");
    printf("3. PIB\n");
    printf("4. PONTOS TURÍSTICOS\n");
    printf("5. DENSIDADE POPULACIONAL\n");
    printf("6. PIB PER CAPITA\n");
    printf("7. SUPER PODER\n");
    scanf("%d", &opcao2);

    // Evita que o usuário escolha o mesmo atributo duas vezes.
    if (opcao1 == opcao2){
        printf("Você não pode escolher os mesmos dois atributos para comparar! Tente novamente!");
        return 0;
    } else{

    printf("==HORA DA BATALHA==\n");
    printf("%s VS %s\n", cidade1, cidade2);
    printf("ATRIBUTOS ESCOLHIDOS:\n");

    // Uso do switch para formar o menu e apontar os atributos para as variáveis de comparação
    switch(opcao1){
        case 1:
            atributo1 = "População";
            atriA1 = populacao1;
            atriA2 = populacao2;
            break;
        case 2:
            atributo1 = "Área em km²";
            atriA1 = areakm1;
            atriA2 = areakm2;
            break;
        case 3:
            atributo1 = "PIB";
            atriA1 = pib1;
            atriA2 = pib2;
            break;
        case 4:
            atributo1 = "Pontos turísticos";
            atriA1 = tour1;
            atriA2 = tour2;
            break;
        case 5:
            atributo1 = "Densidade populacional";
            atriA1 = -denPop1;
            atriA2 = -denPop2;
            break;
        case 6:
            atributo1 = "PIB per capita";
            atriA1 = pibCap1;
            atriA2 = pibCap2;
            break;
        case 7:
            atributo1 = "Super-poder";
            atriA1 = super1;
            atriA2 = super2;
            break;
        default:
            printf("Entrada inválida");
    }
    switch(opcao2){
        case 1:
            atributo2 = "População";
            atriB1 = populacao1;
            atriB2 = populacao2;
            break;
        case 2:
            atributo2 = "Área em km²";
            atriB1 = areakm1;
            atriB2 = areakm2;
            break;
        case 3:
            atributo2 = "PIB";
            atriB1 = pib1;
            atriB2 = pib2;
            break;
        case 4:
            atributo2 = "Pontos turísticos";
            atriB1 = tour1;
            atriB2 = tour2;
            break;
        case 5:
            atributo2 = "Densidade populacional";
            atriB1 = -denPop1;
            atriB2 = -denPop2;
            break;
        case 6:
            atributo2 = "PIB per capita";
            atriB1 = pibCap1;
            atriB2 = pibCap2;
            break;
        case 7:
            atributo2 = "Super-poder";
            atriB1 = super1;
            atriB2 = super2;
            break;
        default:
            printf("Entrada inválida");
    }
    
    // Variávei dos totais de cada carta para comparação.
    float total1 = atriA1 + atriB1;
    float total2 = atriA2 + atriB2;

    printf("%s:\n%s: %.2f\n%s: %.2f\n", atributo1, cidade1, atriA1, cidade2, atriA2);
    printf("%s:\n%s: %.2f\n%s: %.2f\n", atributo2, cidade1, atriB1, cidade2, atriB2);
    printf("==========================\n");
    printf("Total de pontos:\n");
    printf("%s: %.2f\n", cidade1, total1);
    printf("%s: %.2f\n", cidade2, total2);

    // Comparação para declarar o vencedor.
    if (total1 > total2){
        printf("%s venceu!!\n", cidade1);
    } else if (total1 < total2){
        printf("%s venceu!!\n", cidade2);
    } else{
        printf("EMPATE!!!\n");
    }
    }
    return 0;
}