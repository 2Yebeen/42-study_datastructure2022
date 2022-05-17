#include "include/bintree.h"
#include "include/traversal.h"
#include "include/arrayheap.h"
#include "include/binarysearchtree.h"


void displayArrayHeap(ArrayMaxHeap* pHeap) {
	int i = 0;
	if (pHeap != NULL) {
		for(i = 1; i <= pHeap->currentElementCount; i++) {
			printf("[%d],%c\n", i, pHeap->pElement[i].data);
		}
	}
}

void displayBinSearchTreeInternal(BSTreeNode *pTreeNode, int level, char type) {
	if (pTreeNode != NULL) {
		printf("[%i,%c] %i(%c)\n", level, type, pTreeNode->key, pTreeNode->data);

		displayBinSearchTreeInternal(pTreeNode->pLeftChild, level + 1, 'L');
		displayBinSearchTreeInternal(pTreeNode->pRightChild, level + 1, 'R');
	}
}

void displayBinTree(BinTree *pTree) {
    printf("\n===========================================================\n");
	printf("\t\tpreorderTraversal");
	printf("\n===========================================================\n");
	preorderTraversal(pTree->pRootNode);
	printf("\n===========================================================\n");
	printf("\t\tpostorderTraversal");
	printf("\n===========================================================\n");
	postorderTraversal(pTree->pRootNode);
	printf("\n===========================================================\n");
	printf("\t\tinorderTraversal");
	printf("\n===========================================================\n");
    inorderTraversal(pTree->pRootNode);
}

void arrayHeap() {
    int maxHeapSize = 20;

	ArrayMaxHeap *pHeap1 = NULL;

	ArrayHeapNode *pNode = NULL;
	ArrayHeapNode e1 = {10};
	ArrayHeapNode e2 = {40};
	ArrayHeapNode e3 = {30};
	ArrayHeapNode e4 = {20};
	ArrayHeapNode e5 = {50};

	pHeap1 = createArrayMaxHeap(maxHeapSize);
	if (pHeap1 != NULL) {
		insertArrayMaxHeapAH(pHeap1, e1);
		insertArrayMaxHeapAH(pHeap1, e2);
		insertArrayMaxHeapAH(pHeap1, e3);
		insertArrayMaxHeapAH(pHeap1, e4);
		insertArrayMaxHeapAH(pHeap1, e5);

		printf("Max Heap:\n");
		displayArrayHeap(pHeap1);
		
		pNode = deleteArrayMaxHeapAH(pHeap1);
		if (pNode != NULL) {
			printf("deleteMaxHeapAH()-[%d]\n", pNode->key);
			free(pNode);
		}

		printf("Max Heap:\n");
		displayArrayHeap(pHeap1);

		deleteArrayMaxHeap(pHeap1);
	}

}

void binSearchTree() {
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
	BSTreeNode e10 = {22, 'J'};

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
	}
}

void binTree() {
    BinTree *pTree;
	BinTreeNode *pRoot;
	BinTreeNode *pBnode;
	BinTreeNode *pCnode;
	BinTreeNode *pNode;
	BinTreeNode *pElement;

	pRoot = makeBinTreeNode('A', 0);

	pTree = makeBinTree(*pRoot);
	// printf("Check RootNode : [%c]\n", pTree->pRootNode->data);

	pElement = makeBinTreeNode('B', 0);
	pBnode = insertLeftChildNodeBT(pTree->pRootNode, *pElement);
	pNode = getLeftChildNodeBT(pTree->pRootNode);
	free(pElement);
	// printf("Check LeftChildNode : [%c]\n", pNode->data);
	// printf("Check LeftChildNode : [%c]\n", pTree->pRootNode->pLeftChild->data);

	pElement = makeBinTreeNode('C', 0);
	pCnode = insertRightChildNodeBT(pTree->pRootNode, *pElement);
	pNode = getRightChildNodeBT(pTree->pRootNode);
	free(pElement);
	// printf("Check RightChildNode : [%c]\n", pNode->data);
	// printf("Check RightChildNode : [%c]\n", pTree->pRootNode->pRightChild->data);

	if (pBnode != NULL) {
		pElement = makeBinTreeNode('D', 0);
		insertLeftChildNodeBT(pBnode, *pElement);
		pNode = getLeftChildNodeBT(pBnode);
		free(pElement);
		// printf("Check B->LeftChildNode : [%c]\n", pNode->data);
	}
	if (pCnode != NULL) {
		pElement = makeBinTreeNode('E', 0);
		insertLeftChildNodeBT(pCnode, *pElement);
		pNode = getLeftChildNodeBT(pCnode);
		free(pElement);
		// printf("Check C->LeftChildNode : [%c]\n", pNode->data);

		pElement = makeBinTreeNode('F', 0);
		insertRightChildNodeBT(pCnode, *pElement);
		pNode = getRightChildNodeBT(pCnode);
		free(pElement);
		// printf("Check C->RightChildNode : [%c]\n", pNode->data);
	}
    displayBinTree(pTree);
	deleteBinTree(pTree);
}

int main(void) {
    // arrayHeap();
    binSearchTree();
    // binTree();

    return 0;
}