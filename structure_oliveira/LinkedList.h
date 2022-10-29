#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct typeStudent{
    char nome[30];
    int age;
}typeStudent;

typedef struct typeNo{
    typeStudent data;
    struct typeNo *prox;
}typeNo;

typedef struct typeList{
    typeNo *prim;
	typeNo *end;
	unsigned count;
}typeList;

void criaList(typeList *pList);

void insertElementList(typeList *pList, typeStudent *aluno);

void InvMostraAluno(typeList *students);

void mostraAluno(typeList *students);

int buscaElementInList(typeList *pList, char *nome, typeStudent *retorno);

int RemoveElement(typeList *pList, char *nome);

unsigned frequencyLettersList(typeList *pList, char *letter);

#endif
