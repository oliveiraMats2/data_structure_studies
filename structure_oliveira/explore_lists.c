#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

void criaList(typeList *pList){
    pList->prim = NULL;
	pList->end = NULL;
	pList->count = 0;
}

void insertElementList(typeList *pList, typeStudent *aluno){
    typeNo *aux;
    aux = (typeNo*)malloc(sizeof(typeNo));
	
	aux->data = *aluno;
	aux->prox = pList->prim;
	if (pList->prim==NULL){	
		pList->end = aux;
	}	
	pList->prim = aux;
	pList->count++;   
}

void InvMostraAluno(typeList *students){
	typeNo *aux = students->end;
	while(aux){
		printf("%s \n", aux->data.nome);
		printf("%d \n", aux->data.age);
		aux = aux->prox;
	}
}

void mostraAluno(typeList *students){
    typeNo *aux = students->prim;
    while(aux){
        printf("%s \n", aux->data.nome);
        printf("%d \n", aux->data.age);
        aux = aux->prox;
    }
}

int buscaElementInList(typeList *pList, char *nome, typeStudent *retorno){
	typeNo *aux;

	aux = pList->prim;
	while(aux){
		if(!strcmp(nome, aux->data.nome)){
			*retorno = aux->data;
			return 1;
		}

		aux = aux -> prox;
	}
	return 0;
}

int RemoveElement(typeList *pList, char *nome){

	typeNo *tmp, *aux = pList->prim;

	if(pList->prim){//verify if Plist is empty
		aux = pList->prim;

		if (!strcmp(nome, aux->data.nome)){//remove firt element
			tmp = pList->prim;
			pList->prim = tmp->prox;
			pList->count--;
			free(tmp);
		}

		while(aux->prox){//Going to second Node
			if(!strcmp(nome, aux->prox->data.nome)){
				tmp = aux->prox;
				aux->prox = tmp->prox;
				free(tmp);

				pList->count--;

				return 1;
			}

			aux = aux->prox;
		}
	}
	return 0;
	
}

unsigned frequencyLettersList(typeList *pList, char *letter){

	int count = 0;
	typeNo *aux = pList->prim;

	while(aux!=NULL){
		if (aux->data.nome[0]==letter[0]){
			count++;
		}

		aux = aux->prox;
	}

	return count;
}


int main(){
    typeList l1;
    typeStudent aluno, aluno1, aluno2;
	unsigned frequency;
	char *compare = "M";

    criaList(&l1);

    strcpy(aluno.nome, "fulano");
    aluno.age = 18;
	
	strcpy(aluno1.nome, "Mateus");
    aluno1.age =  25;
	
	strcpy(aluno2.nome, "Maria");
    aluno2.age = 10;
	
    insertElementList(&l1, &aluno);
	insertElementList(&l1, &aluno1);
	insertElementList(&l1, &aluno2);
	
	mostraAluno(&l1);
	printf("===============================\n");
    InvMostraAluno(&l1);

	printf("\n count in list [%d] \n", l1.count);


	printf("\n=================================\n");

	RemoveElement(&l1, "Mateus");

	mostraAluno(&l1);
	
	frequency = frequencyLettersList(&l1, compare);

	printf("\n frequency %d \n", frequency);

	printf("\n count in list [%d] \n", l1.count);
    
    return 0;


}
