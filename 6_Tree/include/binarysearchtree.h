#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct BinarySearchTreeNodeType
{
    int key;
	char data;
	struct BinarySearchTreeNodeType *pLeftChild;
	struct BinarySearchTreeNodeType *pRightChild;
} BSTreeNode;

typedef struct BinarySearchTreeType
{
	struct BinarySearchTreeNodeType *pRootNode;
} BSTree;

// 생성
BSTree* createBinarySearchTree();
// 추가
int insertBSTreeNode(BSTree* pBSTree, BSTreeNode element);
// 검색
BSTreeNode* searchBSTreeNode(BSTree* pBSTree, int key);
BSTreeNode* searchBSTreeParentNode(BSTree* pBSTree, int key);
// 제거
int deleteBSTreeNode(BSTree* pBSTree, int key);
// 삭제
void deleteBinarySearchTree(BSTree* pBSTree);
void deleteBinarySearchTreeNode(BSTreeNode* pNode);

#endif // _BINARY_SEARCH_TREE_

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif // _COMMON_TREE_DEF_