#include <stdio.h>
int main(){
    // Declarando variáveis:
    // Nomes dos produtos:
    char produtoA[30] = "Produto A";
    char produtoB[30] = "Produto B";

    // Quantidades em estoque:
    unsigned int estoqueA = 1000; // Utilizamos "unsigned" aqui pois o estoque não pode ser negativo.
    unsigned int estoqueB = 2000;

    // Valor pela unidade:
    float valorA = 10.50;
    float valorB = 20.40;

    // Estoque mínimo:
    unsigned int estoqueMinimoA = 500;
    unsigned int estoqueMinimoB = 2500;

    // Valor total de cada produto:
    double valorTotalA;
    double valorTotalB;

    int comparacaoA, comparacaoB;
    // Exibir as informações dos produtos:
    printf("Produto %s tem estoque %u e o valor unitário é R$%.2f\n", produtoA, estoqueA, valorA);
    printf("Produto %s tem estoque %u e o valor unitário é R$%.2f\n", produtoB, estoqueB, valorB);

    // Comparações com o mínimo de estoque:
    comparacaoA = estoqueA > estoqueMinimoA;
    comparacaoB = estoqueB > estoqueMinimoB;
    printf("O produto %s tem estoque mínimo de %d\n", produtoA, comparacaoA);
    printf("O produto %s tem estoque mínimo de %d\n", produtoB, comparacaoB);

    // Comparações dos valores totais dos produtos:
    printf("O valor total de A (R$ %.2f) é maior que o valor total de B (R$ %.2f): %d\n",estoqueA*valorA, estoqueB*valorB, (estoqueA * valorA) > (estoqueB * valorB));
}