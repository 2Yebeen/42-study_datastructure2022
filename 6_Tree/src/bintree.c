#include "../include/bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *newTree = (BinTree *)calloc(1, sizeof(BinTree));
	newTree->pRootNode = makeBinTreeNode(rootNode.data, rootNode.visited);
	return (newTree);
}
BinTreeNode* makeBinTreeNode(char data, int visited)
{
	BinTreeNode *newNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	newNode->data = data;
	newNode->visited = visited;
	return (newNode);
}
BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	return (pBinTree->pRootNode);
}
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *newNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	newNode->data = element.data;
	newNode->visited = element.visited;
	if (pParentNode->pLeftChild == NULL)
	{
		pParentNode->pLeftChild = newNode;
	}
	else
	{
		BinTreeNode *oldNode;
		oldNode = getLeftChildNodeBT(pParentNode);
		pParentNode->pLeftChild = newNode;
		newNode->pLeftChild = oldNode;
	}
	return (newNode);
}
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *newNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	newNode->data = element.data;
	newNode->visited = element.visited;
	if (pParentNode->pRightChild == NULL)
	{
		pParentNode->pRightChild = newNode;
	}
	else
	{
		BinTreeNode *oldNode;
		oldNode = getRightChildNodeBT(pParentNode);
		pParentNode->pRightChild = newNode;
		newNode->pRightChild = oldNode;
	}
	return (newNode);
}
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	return (pNode->pLeftChild);
}
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	return (pNode->pRightChild);
}
void deleteBinTree(BinTree* pBinTree)
{
	if (pBinTree != NULL) {
		deleteBinTreeNode(pBinTree->pRootNode);
		free(pBinTree);
		pBinTree = NULL;
	}
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode != NULL) {
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
		free(pNode);
		pNode = NULL;
	}
}