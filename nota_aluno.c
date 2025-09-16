#include <stdio.h>

int main(){
    int index;
    char *nomeAlunos[3][3]= {
        {"Aluno 1", "PT: 30", "MAT: 90"},
        {"Aluno 2", "PT: 60", "MAT: 60"},
        {"Aluno 3", "`PT: 90", "MAT: 30"}
    };

    printf("Digite o número do aluno que quer ver a notass...\n");
    printf("Para Aluno 0, digite 0\n");
    printf("Para Aluno 1, digite 1\n");
    printf("Para Aluno 2, digite 2\n");

    scanf("%d", &index);
    printf("As notas do %s são: %s %s\n", nomeAlunos[index][0], nomeAlunos[index][1], nomeAlunos[index][2]);

    return 0;
}