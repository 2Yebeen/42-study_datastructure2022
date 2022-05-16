#include "include/bintree.h"
#include "include/traversal.h"

int main(void)
{
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
	// printf("Check RootNode : [%c]\n", pTree->pRootNode->pLeftChild->pLeftChild->data);
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
	
	deleteBinTree(pTree);
	// system("leaks a.out");
}