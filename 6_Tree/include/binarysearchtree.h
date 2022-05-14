#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct BinarySearchTreeNodeType
{
    int key;
	char data;
	BSTreeNode* pLeftChild;
	BSTreeNode* pRightChild;
} BSTreeNode;

typedef struct BinarySearchTreeType
{
	BSTreeNode* pRootNode;
} BSTree;

// 생성
BSTree* createBinarySearchTree();
// 추가
int insertBSTreeNode(BSTree* pBSTree, BSTreeNode element);
// 검색
BSTreeNode* searchBSTreeNode(BSTree* pBSTree, int key);
// 제거
int deleteBSTreeNode(BSTreeNode* pNode, int key);
// 삭제
void deleteBinarySearchTree(BSTree* pBSTree);
void deleteBinarySEarchTreeNode(BSTreeNode* pNode);

#endif // _BINARY_SEARCH_TREE_

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif // _COMMON_TREE_DEF_