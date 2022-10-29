#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

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
