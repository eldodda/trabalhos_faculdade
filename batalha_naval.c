#include <stdio.h>      // Biblioteca base da linguagem C/C++. Contém funções básicas como "printf" e "scanf".
#include <stdlib.h>     // Biblioteca de uso geral que contém funções úteis como geração de números aleatórios.
#include <time.h>       // Cabeçalho que contém funções e tipos para manipulação de data e hora.

      // Função declarada em int porque retorna um valor inteiro.
    int lugarDisponivel(int tab[10][10], int row, int col, int size, char dir) {
        int i;

        if (dir == 'H') {   // Checagem HORIZONTAL
            if (col + size > 10) return 0;  // Se a quantidade de COLUNAS + o tamanho do navio excederer 10,
            for (i = 0; i < size; i++){     // retorna 0, pois passa do limite.
                if (tab[row][col + i] != 0) return 0;   // Se alguma parte do navio cair onde não é água (0),
            }                                           // retorna 0, pois já tem outro navio.
        } else if (dir == 'V') {    // Checagem vertical
            if (row + size > 10) return 0;  // Se a quantidade de LINHAS + o tamanho do navio excederer 10,
            for (i = 0; i < size; i++){     // retorna 0, pois passa do limite.
                if (tab[row + i][col] != 0) return 0;   // Se alguma parte do navio cair onde não é água (0),
            }                                           // retorna 0, pois já tem outro navio.
        }
        return 1;       // Se nenhuma das intercorrências previstas acontecer, o posicionamento é válido e liberado.
    }

    void posicionarNavio(int tab[10][10], int row, int col, int size, char dir, int id){
        int i;
        if (dir == 'H'){
            for (i = 0; i < size; i++){
                tab[row][col + i] = id;
            }
        } else if (dir == 'V'){
            for (i = 0; i < size; i++){
                tab[row + i][col] = id;
            }
        }
    }

int main(){
    int agua[10][10] = {0};
    int linha, coluna;
    srand(time(NULL));

    // Posicionar navio HORIZONTAL
    do {linha = rand() % 10;
        coluna = rand() % 10;
    } while (!lugarDisponivel(agua, linha, coluna, 3, 'H'));
    posicionarNavio(agua, linha, coluna, 3, 'H', 3);

    // Posicionar navio  VERTICAL
    do {linha = rand() % 10;
        coluna = rand() % 10;
    } while (!lugarDisponivel(agua, linha, coluna, 3, 'V'));
    posicionarNavio(agua, linha, coluna, 3, 'V', 3);

    // Imprimir cabeçalho (ABCs e 123s)
    printf("   ");
    for (coluna = 0; coluna < 10; coluna++){
        printf(" %c", 'A' + coluna);
    }
    printf("\n");

    // Imprimir tabuleiro
    for (linha = 0; linha <10; linha++){
        printf("%2d ", linha + 1);
        for (coluna = 0; coluna < 10; coluna++){
            printf(" %d", agua[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}