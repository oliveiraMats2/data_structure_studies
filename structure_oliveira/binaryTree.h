#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

typedef struct typeData{
	int value;
}typeData;

typedef struct typeNodeTree{
	typeData data;
	struct typeNodeTree *left, *right;
	struct typeNodeTree *dad;
}typeNodeTree;


typedef struct typeTree{
	typeNodeTree *tree;
	typeNodeTree *begin;
	typeNodeTree *cursor;
}typeTree;


void CreateTree(typeNodeTree **root);

typeNodeTree* NodeBegin(typeTree T);

typeNodeTree* NodeFinish(typeTree T);

void insertOnTreeRecursive(typeNodeTree **root, int value);

void insert(typeNodeTree **root, int value);

void PrintPosOrder(typeNodeTree *tree);

int FindElementOnTree(typeNodeTree *tree, int value);

#endif
