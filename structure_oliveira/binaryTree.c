#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

void CreateTree(typeNodeTree **root){
	*root = NULL;
}


typeNodeTree* NodeBegin(typeTree T){
	typeNodeTree *tmp = T.tree;
	if(tmp){
		while(tmp->left){
			tmp = tmp->left;
		}
	}
	return tmp;
}

typeNodeTree* NodeFinish(typeTree T){
	typeNodeTree *tmp = T.tree;
	if(tmp){
		while(tmp->right){
			tmp = tmp->right;
		}
	}

	return tmp;
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


