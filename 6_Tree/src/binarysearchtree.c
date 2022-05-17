#include "../include/binarysearchtree.h"

BSTree* createBinarySearchTree() {
    BSTree *pTree = (BSTree *)calloc(1, sizeof(BSTree));
    if (pTree != NULL) pTree->pRootNode = NULL;

    return pTree;
}

int insertBSTreeNode(BSTree* pBSTree, BSTreeNode element) {
    BSTreeNode *pParentNode = pBSTree->pRootNode;
    BSTreeNode *pNode = (BSTreeNode *)calloc(1, sizeof(BSTreeNode));
    // 검색 연산 성공 : 자료 추가 불가능
    if (searchBSTreeNode(pBSTree, element.key) != NULL || pNode == NULL) return FALSE;
    // 검색 연산 실패 : 자료 추가 가능
    while (pParentNode != NULL) {
        if (element.key < pParentNode->key) {
            if (pParentNode->pLeftChild == NULL) break;
            else pParentNode = pParentNode->pLeftChild;
        } else {
            if (pParentNode->pRightChild == NULL) break;
            else pParentNode = pParentNode->pRightChild;
        }
    }
    *pNode = element;
    if (pParentNode == NULL) {
        pBSTree->pRootNode = pNode;
    } else {
        if (pNode->key < pParentNode->key) {
            pParentNode->pLeftChild = pNode;
        } else {
            pParentNode->pRightChild = pNode;
        }
    }
    return TRUE;
}

BSTreeNode* searchBSTreeNode(BSTree* pBSTree, int key) {
    BSTreeNode *pNode = NULL;
    if (pBSTree == NULL) return NULL;
    pNode = pBSTree->pRootNode;
    while (pNode != NULL) {
        if (key == pNode->key) break;
        else if (key < pNode->key) pNode = pNode->pLeftChild;
        else pNode = pNode->pRightChild;
    }
    return pNode;
}

BSTreeNode* searchBSTreeParentNode(BSTree* pBSTree, int key) {
    BSTreeNode *pNode = NULL;
    BSTreeNode *pPatentNode = NULL;

    if (pBSTree == NULL) return NULL;
    pNode = pBSTree->pRootNode;
    while (pNode != NULL) {
        if (key == pNode->key) break;
        pPatentNode = pNode;
        if (key < pNode->key) pNode = pNode->pLeftChild;
        else pNode = pNode->pRightChild;
    }
    return pPatentNode;
}

int deleteBSTreeNode(BSTree* pBSTree, int key) {
    int ret = FALSE;
    BSTreeNode *pParentNode = searchBSTreeParentNode(pBSTree, key);
    BSTreeNode *pDelNode = searchBSTreeNode(pBSTree, key);
    BSTreeNode *pNode = NULL, *pPre = NULL;
    // 삭제하려는 노드가 없는 경우,
    if (pDelNode == NULL) return ret;
    // 삭제 하려는 노드의 자식 노드가 없는 경우,
    if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
        if (pParentNode != NULL) {
            // 삭제 하려는 노드가 왼쪽노드일 경우
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pNode;
            } else {
                pParentNode->pRightChild = pNode;
            }
        } else {
            pBSTree->pRootNode = pNode;
        }
    } // 삭제 하려는 노드의 자식 노드가 2개인 경우,
    else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
        pPre = pDelNode;
        pNode = pDelNode->pLeftChild;
        // 왼쪽 서브 트리에서 찾기
        while (pNode->pRightChild != NULL) {
            pPre = pNode;
            pNode = pNode->pRightChild;
        }
        if (pPre->pLeftChild == pNode) pPre->pLeftChild = pNode->pLeftChild;
        else pPre->pRightChild = pNode->pLeftChild;
        pDelNode->key = pNode->key;
        pDelNode->data = pNode->data;
        pDelNode = pNode;
        
    } // 삭제 하려는 노드의 자식 노드가 1개인 경우,
    else {
        if (pDelNode->pLeftChild != NULL) pNode = pDelNode->pLeftChild;
        else pNode = pDelNode->pRightChild;
        if (pParentNode != NULL) {
            // 삭제 하려는 노드가 왼쪽노드일 경우
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pNode;
            } else {
                pParentNode->pRightChild = pNode;
            }
        } else {
            pBSTree->pRootNode = pNode;
        }
    }
    free (pDelNode);
    pDelNode = NULL;
    return ret;
}

void deleteBinarySearchTree(BSTree* pBSTree) {
    if (pBSTree != NULL) {
        deleteBinarySearchTreeNode(pBSTree->pRootNode);
        free(pBSTree);
        pBSTree = NULL;
    }    
}

void deleteBinarySearchTreeNode(BSTreeNode* pNode) {
    if (pNode != NULL) {
        deleteBinarySearchTreeNode(pNode->pLeftChild);
        deleteBinarySearchTreeNode(pNode->pRightChild);
        free(pNode);
        pNode = NULL;
    }
}
