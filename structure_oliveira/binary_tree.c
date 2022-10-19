#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

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
