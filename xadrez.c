#include <stdio.h>
void torre_move(int casas){
    if (casas < 5){             
        printf("|Direita|\n");
        torre_move(casas + 1);
    }
}

void bispo_move(int casas){
    if (casas < 5){
        for (int x = 0; x < 1; x++){        // Loop externo controlando a vertical
            printf("|Cima|\n");
            for (int y = 0; y < 1; y++){    // Loop interno controlando a horizontal
                printf("|Direita|\n");
            }
        }
        bispo_move(casas + 1);
    }
}

void rainha_move(int casas){
    if (casas > 0){
        printf("|Esquerda|\n");
        rainha_move(casas - 1);
    }
}

void cavalo_move(){
    for (int x = 0; x < 3; x++){    // Vai contar até 3
        if (x < 2){
            printf("|Cima|\n");
            continue;               // Imprime no 2 e avança para o 3
        }
        printf("|Direita|\n");      // No 3 anda para a direita
        break;                      // E fim
    }
}
int main(){
    printf("|MOVIMENTOS DE XADREZ|\n");
    printf("|====================|\n");
    printf("|Movimento da TORRE: |\n");
    torre_move(0);
    
    
    printf("|====================|\n");
    printf("|Movimento do BISPO: |\n");
    bispo_move(0);
    
    
    printf("|====================|\n");
    printf("|Movimento da RAINHA:|\n");
    rainha_move(8);

    printf("|====================|\n");
    printf("|Movimento do CAVALO:|\n");
    cavalo_move();
    return 0;
}