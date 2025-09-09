#include <stdio.h>
int main(){
    printf("|MOVIMENTOS DE XADREZ|\n");
    printf("|Movimento da TORRE: |\n");
    for (int torre = 0; torre < 5; torre++){
        printf("|Direita|\n");
    }
    
    
    printf("|====================|\n");
    printf("|Movimento do BISPO: |\n");
    int bispo = 0;
    while (bispo < 5){
        printf("|Cima + Direita|\n");
        bispo++;
    }
    
    
    printf("|====================|\n");
    printf("|Movimento da RAINHA:|\n");
    int rainha = 0;
    do {
        printf("|Esquerda|\n");
        rainha++;
    } while (rainha < 8);
    return 0;
}