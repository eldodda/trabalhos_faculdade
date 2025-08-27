#include <stdio.h>
int main() {
    // Declaração de variáveis:
    float nota1, nota2, nota3, media;

    // Entrada de dados:
    printf("Insira a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    // Processamento de dados:
    media = (nota1 + nota2 + nota3) / 3;

    // Saída de dados:
    printf("A média das notas é %.2f", media);
}