#include <stdio.h>    // Biblioteca base da linguagem C/C++. Contém funções básicas como "printf" e "scanf".
#include <stdlib.h>   // Biblioteca de uso geral que contém funções úteis como geração de números aleatórios e a função abs().
#include <time.h>     // Cabeçalho que contém funções e tipos para manipulação de data e hora.

// --- INÍCIO DA SEÇÃO DE HABILIDADES ---

// Define o tamanho padrão das matrizes de habilidade (ex: 5x5)
#define HABILIDADE_TAM 5

// Funções das habilidades:
void criarHabilidadeCone(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    int i, j;
    int centro = HABILIDADE_TAM / 2; // Ponto central (2 para uma matriz 5x5)

    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            // Lógica do Cone (apontando para baixo, com origem no centro):
            // 1. A linha (i) deve estar no centro ou abaixo dele.
            // 2. A distância horizontal da coluna (j) ao centro deve ser
            //    menor ou igual à distância vertical da linha (i) ao centro.
            if (i >= centro && abs(j - centro) <= (i - centro)) {
                matriz[i][j] = 1; // 1 = Área afetada
            } else {
                matriz[i][j] = 0; // 0 = Área não afetada
            }
        }
    }
}

void criarHabilidadeCruz(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    int i, j;
    int centro = HABILIDADE_TAM / 2; // Ponto central (2)

    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            // Lógica da Cruz:
            // Afeta se a posição estiver na linha central (i == centro)
            // OU na coluna central (j == centro).
            if (i == centro || j == centro) {
                matriz[i][j] = 1; // Afetado
            } else {
                matriz[i][j] = 0; // Não afetado
            }
        }
    }
}

void criarHabilidadeOctaedro(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    int i, j;
    int centro = HABILIDADE_TAM / 2; // Ponto central (2)

    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            // Lógica do Octaedro/Losango (Distância de Manhattan):
            // A soma das distâncias absolutas (vertical e horizontal)
            // da posição (i, j) até o centro (centro, centro)
            // deve ser menor ou igual ao raio (centro).
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1; // Afetado
            } else {
                matriz[i][j] = 0; // Não afetado
            }
        }
    }
}

void aplicarHabilidade(int tab[10][10], int habilidade[HABILIDADE_TAM][HABILIDADE_TAM], int origemLin, int origemCol) {
    int i, j;
    int centro = HABILIDADE_TAM / 2; // Centro da matriz de habilidade (2)

    // Itera sobre a matriz de habilidade 5x5
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            
            // Verifica se esta parte da habilidade (habilidade[i][j]) afeta uma área (valor 1)
            if (habilidade[i][j] == 1) {
                // Calcula a posição correspondente no tabuleiro principal
                // O cálculo (i - centro) e (j - centro) obtém o "offset"
                // em relação ao centro da habilidade.
                int boardLin = origemLin + (i - centro);
                int boardCol = origemCol + (j - centro);

                // --- Verificação de Limites ---
                // Garante que a habilidade não "saia" do tabuleiro 10x10
                if (boardLin >= 0 && boardLin < 10 && boardCol >= 0 && boardCol < 10) {
                    
                    // --- Aplicação da Habilidade ---
                    // Marca a área de efeito (1) apenas se for água (0)
                    // Isso preserva a visualização dos navios (3)
                    if (tab[boardLin][boardCol] == 0) {
                        tab[boardLin][boardCol] = 1; // 1 = Área de efeito
                    }
                }
            }
        }
    }
}

// --- FIM DA SEÇÃO DE HABILIDADES ---

// Função para evitar sobreposição de navios.
int lugarDisponivel(int tab[10][10], int row, int col, int size, char dir) {
    int i;

    if (dir == 'H') {    // Checagem HORIZONTAL
        if (col + size > 10) return 0;  // Se a quantidade de COLUNAS + o tamanho do navio exceder 10,
        for (i = 0; i < size; i++) {    // retorna 0, pois passa do limite.
            if (tab[row][col + i] != 0) return 0;   // Se alguma parte do navio cair onde não é água (0),
        }                                           // retorna 0, pois já tem outro navio.
    } else if (dir == 'V') {    // Checagem vertical
        if (row + size > 10) return 0;  // Se a quantidade de LINHAS + o tamanho do navio exceder 10,
        for (i = 0; i < size; i++) {    // retorna 0, pois passa do limite.
            if (tab[row + i][col] != 0) return 0;   // Se alguma parte do navio cair onde não é água (0),
        }                                           // retorna 0, pois já tem outro navio.
    } else if (dir == 'D') {
        if (row + size > 10 || col + size > 10) return 0; // Corrigido: checar ambos os limites para diagonal D
        for (i = 0; i < size; i++) {
            if (tab[row + i][col + i] != 0) return 0;
        }
    } else if (dir == 'S') {
        if (row + size > 10 || col - (size - 1) < 0) return 0;
        for (i = 0; i < size; i++) {
            if (tab[row + i][col - i] != 0) return 0;
        }
    }
    return 1;   // Se nenhuma das intercorrências previstas acontecer, o posicionamento é válido e liberado.
}

void posicionarNavio(int tab[10][10], int row, int col, int size, char dir, int id) {
    int i;
    if (dir == 'H') {
        for (i = 0; i < size; i++) {
            tab[row][col + i] = id;
        }
    } else if (dir == 'V') {
        for (i = 0; i < size; i++) {
            tab[row + i][col] = id;
        }
    } else if (dir == 'D') {
        for (i = 0; i < size; i++) {
            tab[row + i][col + i] = id;
        }
    } else if (dir == 'S') {
        for (i = 0; i < size; i++) {
            tab[row + i][col - i] = id;
        }
    }
}

int main() {
    int agua[10][10] = {0};
    int linha, coluna;
    srand(time(NULL));  // Inicializa o gerador de números aleatórios com a seed baseada no horário atual do sistema.

    // Posicionar navio HORIZONTAL
    do {
        linha = rand() % 10;    // %10 garante que os números sorteados estarão entre 0 e 9.
        coluna = rand() % 10;
    } while (!lugarDisponivel(agua, linha, coluna, 3, 'H'));    // Enquanto o lugar não(!) for disponível, vai continuar rodando números aleatórios.
    posicionarNavio(agua, linha, coluna, 3, 'H', 3);

    // Posicionar navio  VERTICAL
    do {
        linha = rand() % 10;
        coluna = rand() % 10;
    } while (!lugarDisponivel(agua, linha, coluna, 3, 'V'));
    posicionarNavio(agua, linha, coluna, 3, 'V', 3);

    // Posicionar navios DIAGONAIS
    do {
        linha = rand() % 10;
        coluna = rand() % 10;
    } while (!lugarDisponivel(agua, linha, coluna, 3, 'D'));
    posicionarNavio(agua, linha, coluna, 3, 'D', 3);
    do {
        linha = rand() % 10;
        coluna = rand() % 10;
    } while (!lugarDisponivel(agua, linha, coluna, 3, 'S'));
    posicionarNavio(agua, linha, coluna, 3, 'S', 3);

    // --- INÍCIO DA APLICAÇÃO DAS HABILIDADES ---

    // 1. Declarar as matrizes de habilidade
    int matCone[HABILIDADE_TAM][HABILIDADE_TAM];
    int matCruz[HABILIDADE_TAM][HABILIDADE_TAM];
    int matOcta[HABILIDADE_TAM][HABILIDADE_TAM];

    // 2. Preencher as matrizes com suas formas
    criarHabilidadeCone(matCone);
    criarHabilidadeCruz(matCruz);
    criarHabilidadeOctaedro(matOcta);

    // 3. Aplicar as habilidades no tabuleiro 'agua' em diferentes quadrantes
    
    // Aplica o Cone no quadrante superior esquerdo (Origem em 0, 2)
    aplicarHabilidade(agua, matCone, 0, 2); 
    
    // Aplica a Cruz no quadrante superior direito (Origem em 2, 7)
    aplicarHabilidade(agua, matCruz, 2, 7);
    
    // Aplica o Octaedro no quadrante inferior esquerdo (Origem em 7, 2)
    aplicarHabilidade(agua, matOcta, 7, 2);

    // --- FIM DA APLICAÇÃO DAS HABILIDADES ---


    // Imprimir cabeçalho (ABCs e 123s)
    printf("    ");
    for (coluna = 0; coluna < 10; coluna++) {
        printf(" %c", 'A' + coluna);
    }
    printf("\n");

    // Imprimir tabuleiro
    // Este loop agora imprimirá 0 (água), 3 (navio) e 1 (efeito de habilidade)
    for (linha = 0; linha < 10; linha++) {
        printf("%2d ", linha + 1);
        for (coluna = 0; coluna < 10; coluna++) {
            printf(" %d", agua[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
} 