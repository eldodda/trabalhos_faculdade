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
    int opcao;

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
    printf("Qual atributo vamos comparar?\n");
    printf("1. POPULAÇÃO\n");
    printf("2. ÁREA EM km²\n");
    printf("3. PIB\n");
    printf("4. PONTOS TURÍSTICOS\n");
    printf("5. DENSIDADE POPULACIONAL\n");
    printf("6. PIB PER CAPITA\n");
    printf("7. SUPER PODER\n");
    scanf("%d", &opcao);
    printf("==HORA DA BATALHA==\n");
    printf("%s VS %s\n", cidade1, cidade2);
    printf("ATRIBUTO ESCOLHIDO:\n");

    // Uso do switch para formar o menu e separar as comparações de cada atributo
    switch(opcao){
        case 1:
            printf("=====POPULAÇÃO=====\n");
            printf("%s: %d\n", cidade1, populacao1);
            printf("%s: %d\n", cidade2, populacao2);
            if (populacao1 > populacao2){
                printf("%s venceu!", cidade1);
            } else if (populacao1 < populacao2) {
                printf("%s venceu!", cidade2);
            } else {
                printf("EMPATE!");
            } break;
        case 2:
            printf("====ÁREA EM km²====\n");
            printf("%s: %.2f\n", cidade1, areakm1);
            printf("%s: %.2f\n", cidade2, areakm2);
            if (areakm1 > areakm2){
                printf("%s venceu!", cidade1);
            } else if(areakm1 < areakm2){
                printf("%s venceu!", cidade2);
            } else {
                printf("EMPATE!");
            } break;
        case 3:
            printf("========PIB========\n");
            printf("%s: %.2f\n", cidade1, pib1);
            printf("%s: %.2f\n", cidade2, pib2);
            if (pib1 > pib2){
                printf("%s venceu!", cidade1);
            } else if (pib1 < pib2){
                printf("%s venceu!", cidade2);
            } else {
                printf("EMPATE!");
            } break;
        case 4:
            printf("=PONTOS TURÍSTICOS=\n");
            printf("%s: %d\n", cidade1, tour1);
            printf("%s: %d\n", cidade2, tour2);
            if (tour1 > tour2){
                printf("%s venceu!", cidade1);
            } else if (tour1 < tour2){
                printf("%s venceu!", cidade2);
            } else {
                printf("EMPATE!");
            } break;
        case 5:
            printf("DENSIDADE POPULACIONAL\n");
            printf("%s: %.2f\n", cidade1, denPop1);
            printf("%s: %.2f\n", cidade2, denPop2);
            if (denPop1 < denPop2){
                printf("%s venceu!", cidade1);
            } else if (denPop1 > denPop2){
                printf("%s venceu!", cidade2);
            } else {
                printf("EMPATE!");
            } break;
        case 6:
            printf("===PIB PER CAPITA==\n");
            printf("%s: %.2f\n", cidade1, pibCap1);
            printf("%s: %.2f\n", cidade2, pibCap2);
            if (pibCap1 > pibCap2){
                printf("%s venceu!", cidade1);
            } else if (pibCap1 < pibCap2){
                printf("%s venceu!", cidade2);
            } else {
                printf("EMPATE!");
            } break;
        case 7:
            printf("====SUPER PODER====\n");
            printf("%s: %.2f\n", cidade1, super1);
            printf("%s: %.2f\n", cidade2, super2);
            if (super1 > super2){
                printf("%s venceu!", cidade1);
            } else if (super1 < super2){
                printf("%s venceu!", cidade2);
            } else {
                printf("EMPATE!");
            } break;
            default:
            printf("Entrada inválida");
    }

    return 0;
}