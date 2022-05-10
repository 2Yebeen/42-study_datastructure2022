#include <stdio.h>
#include <stdlib.h>

#include "../include/bintree.h"

// tree 생성
BinTree* makeBinTree(BinTreeNode rootNode) {
    BinTree *pTree = (BinTree *)calloc(1, sizeof(BinTree));
    if (pTree == NULL || rootNode == NULL) return NULL;
    pTree->pRootNode = rootNode;
    return pTree;
}

// 루트노드 반환
BinTreeNode* getRootNodeBT(BinTree* pBinTree) {
    if (pBinTree == NULL) return NULL;
    return pBinTree->pRootNode;
}

// 자식 노드 삽입(왼쪽)
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
    if (pParentNode)

}

// 자식 노드 삽입(오른쪽)
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {

}

// 자식 노드 반환(왼쪽)
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode) {

}

// 자식 노드 반환(오른쪽)
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode) {

}

// 노드 삭제
void deleteBinTreeNode(BinTreeNode* pNode) {

}

// 트리 삭제
void deleteBinTree(BinTree* pBinTree) {

}

