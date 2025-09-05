#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int numeroJog, numeroComp, result;
    char tipoCompara;

    // Gerar número aleatório
    srand(time(0));
    numeroComp = rand() % 100 + 1; // Número entre 1 e 100

    // Início do jogo
    printf("Bem vindo ao jogo de Maior, menor ou igual!\n");
    printf("Você precisa escolher um tipo de comparação e um número.\n");
    printf("Escolha um tipo de comparação: \n");
    printf("M. Maior\n");
    printf("N. Menor\n");
    printf("I. Igual\n");
    scanf("%c", tipoCompara);

    printf("Digite seu número: \n");
    scanf("%d", numeroJog);

    //Menu com lógica de comparação
    switch(tipoCompara){
        case 'm':
        case 'M':
            result = (numeroJog > numeroComp) ? "Parabéns! Você venceu!!\n" : "Que pena! você perdeu.\n";
            break;
        case 'n':
        case 'N':
            result = (numeroJog < numeroComp) ? "Parabéns! Você venceu!!\n" : "Que pena! você perdeu.\n";
            break;
        case 'i':
        case 'I':
            result = (numeroJog = numeroComp) ? "Parabéns! Você venceu!!\n" : "Que pena! você perdeu.\n";
            break;
        default:
            "Entrada inválida. Tente novamente."
    }

    // Exibir o número do computador
    printf("O número do computador é %d\n", numeroComp);


    return 0;
}