#include <stdio.h>
#include <stdlib.h>

typedef struct typeData{
	int value;
}typeData;

typedef struct typeNodeTree{
	typeData data;
	struct typeNodeTree *left, *right;
}typeNodeTree;

void CreateTree(typeNodeTree **root){
	*root = NULL;
}

void insertOnTreeRecursive(typeNodeTree **root, int value){
	
	typeNodeTree *temp = NULL;

	if(*root==NULL){
		temp = malloc(sizeof(typeNodeTree));
		temp->data.value = value;
		temp->right = NULL;
		temp->left = NULL;
		*root = temp;
		return;

		}
	if(value < (*root)->data.value){
		/*
		Primeiro eu acesso a variavel root por ponteiro duplo na direção left, depois eu passo o endereco do left por meio da &.
		*/
		insertOnTreeRecursive(&(*root)->left, value);

	}else{
		insertOnTreeRecursive(&(*root)->right, value);
	}

}

void insert(typeNodeTree **root, int value){

	typeNodeTree *tmp = *root;

	while(tmp){
		if(value > (tmp)->data.value){
			root = &((tmp)->right);
		}
		else{
			root = &((tmp)->left);
		}
		tmp = *root;
	}
	tmp = malloc(sizeof(typeNodeTree));
	tmp->data.value = value;
	tmp->right = NULL;
	tmp->left = NULL;
	*root = tmp;
}

void PrintPosOrder(typeNodeTree *tree){
	if(tree){
		PrintPosOrder(tree->left);
		PrintPosOrder(tree->right);
		printf("%d \n", tree->data.value);
	}

}

int FindElementOnTree(typeNodeTree *tree, int value){
	while(tree){
		if(value > tree->data.value){
			tree = tree->right;
		}
		else if(value < tree->data.value){
			tree = tree->left;
		}
		else{
			return 1;
		}


	}
	return 0;
}


int main(){
	typeNodeTree *tree1;

	CreateTree(&tree1);

	unsigned flag;

	for(int i = 0; i < 1000; i++){
		insertOnTreeRecursive(&tree1, i);
		//insert(&tree1, i);
	}

	PrintPosOrder(tree1);
	flag = FindElementOnTree(tree1, 5);
	if(flag){
		printf("\nachei");
	}else{
		printf("\n not found \n");
	}
}
