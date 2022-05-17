#include "include/binarysearchtree.h"

void displayBinSearchTreeInternal(BSTreeNode *pTreeNode, int level, char type)
{
	if (pTreeNode != NULL) {
		printf("[%i,%c] %i(%c)\n", level, type, pTreeNode->key, pTreeNode->data);

		displayBinSearchTreeInternal(pTreeNode->pLeftChild, level + 1, 'L');
		displayBinSearchTreeInternal(pTreeNode->pRightChild, level + 1, 'R');
	}
}

int main(void)
{
	BSTree *pTree = NULL;
	BSTreeNode *pSearchNode = NULL;
	int key = 0;

	BSTreeNode e1 = {30, 'A'};
	BSTreeNode e2 = {20, 'B'};
	BSTreeNode e3 = {40, 'C'};
	BSTreeNode e4 = {10, 'D'};
	BSTreeNode e5 = {24, 'E'};
	BSTreeNode e6 = {34, 'F'};
	BSTreeNode e7 = {46, 'G'};
	BSTreeNode e8 = {6, 'H'};
	BSTreeNode e9 = {14, 'I'};
	BSTreeNode e10 = {22, 'I'};

	pTree = createBinarySearchTree();
	if (pTree != NULL) 
	{
		printf("\n=======================================================\n");
		printf("\t\t\tinsert\n");
		printf("=======================================================\n");
		insertBSTreeNode(pTree, e1);
		insertBSTreeNode(pTree, e2);
		insertBSTreeNode(pTree, e3);
		insertBSTreeNode(pTree, e4);
		insertBSTreeNode(pTree, e5);
		insertBSTreeNode(pTree, e6);
		insertBSTreeNode(pTree, e7);
		insertBSTreeNode(pTree, e8);
		insertBSTreeNode(pTree, e9);
		insertBSTreeNode(pTree, e10);
		displayBinSearchTreeInternal(pTree->pRootNode, 0, 'R');

		printf("\n=======================================================\n");
		printf("\t\t\tsearch\n");
		printf("=======================================================\n");
		key = 14;
		pSearchNode = searchBSTreeNode(pTree, key);
		if (pSearchNode != NULL) {
			printf("[%d], -[%c]\n", key, pSearchNode->data);
		}

		printf("\n=======================================================\n");
		printf("\t\t\tdelete\n");
		printf("=======================================================\n");
		key = 30;
		printf("[%d]\n", key);
		deleteBSTreeNode(pTree, key);
		displayBinSearchTreeInternal(pTree->pRootNode, 0, 'R');

		printf("\n=======================================================\n");
		printf("\t\t\tsearch\n");
		printf("=======================================================\n");
		pSearchNode = searchBSTreeNode(pTree, key);
		if (pSearchNode != NULL) {
			printf("[%d]-[%c]\n", key, pSearchNode->data);
		}
		else {
			printf("No key [%d]\n", key);
		}


		deleteBinarySearchTree(pTree);
		// system("leaks a.out");
	}

	return 0;
}