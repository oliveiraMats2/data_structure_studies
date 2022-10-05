#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoAluno{
    char nome[30];
    char pibic; //true or false
    char curso[30];
    float coeficiente_rendimento;
}tipoAluno;

void view_v1(tipoAluno *t){
    printf("Nome: %s\n", t->nome);
    printf("Curso: %s\n", t->curso);
    if(t->pibic == 1){
        printf("É aluno de PIBIC \n");
    }
    else{
        printf("Não é aluno de PIBIC \n");
    }
}

void view_v2(tipoAluno *t){
    printf("Nome: %s\n", (*t).nome);
    printf("Curso: %s\n", (*t).curso);
    if(t->pibic == 1){
        printf("É aluno de PIBIC \n");
    }
    else{
        printf("Não é aluno de PIBIC \n");
    }
}

int main(){
    tipoAluno aluno;

    strcpy(aluno.nome, "FASDASDAS");
    strcpy(aluno.curso, "ciencia");
    aluno.coeficiente_rendimento = 8.0;
    aluno.pibic = 1;


    view_v1(&aluno);
    printf("============================\n");
    view_v2(&aluno);

    return 0;
}
