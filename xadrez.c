#include <stdio.h>
int main(){
    printf("|MOVIMENTOS DE XADREZ|\n");
    printf("|====================|\n");
    printf("|Movimento da TORRE: |\n");
    for (int torre = 0; torre < 5; torre++){  // Torre se move 5 casas à direita
        printf("|Direita|\n");
    }
    
    
    printf("|====================|\n");
    printf("|Movimento do BISPO: |\n");
    int bispo = 0;
    while (bispo < 5){             // Bispo se move 5 casas na diagonal cima + direita
        printf("|Cima + Direita|\n");
        bispo++;
    }
    
    
    printf("|====================|\n");
    printf("|Movimento da RAINHA:|\n");
    int rainha = 0;
    do {
        printf("|Esquerda|\n");
        rainha++;
    } while (rainha < 8);          // Rainha se move 8 casas à esquerda


    int cavalo2 = 0;
    printf("|====================|\n");
    printf("|Movimento do CAVALO:|\n");
    for (int cavalo1 = 0; cavalo1 == 0; cavalo1++){
        while (cavalo2 < 2){       // Cavalo se move 2 casas para baixo...
            printf("|Baixo|\n");
            cavalo2++;
        }        
        printf("|Esquerda|\n");    // ..e uma casa à esquerda
    }
    return 0;
}