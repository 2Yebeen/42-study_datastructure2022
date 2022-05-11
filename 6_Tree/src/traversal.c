#include "../include/traversal.h"

void preorderTraversal(BinTreeNode *binTreeNode)
{
    if (binTreeNode != NULL) {
        preorderTraversal(binTreeNode->pLeftChild);
        printf("%c\t", binTreeNode->data);
        preorderTraversal(binTreeNode->pRightChild);
    }
}

void postorderTraversal(BinTreeNode *binTreeNode)
{
    if (binTreeNode != NULL) {
        postorderTraversal(binTreeNode->pLeftChild);
        postorderTraversal(binTreeNode->pRightChild);
        printf("%c\t", binTreeNode->data);
    }
}

void inorderTraversal(BinTreeNode *binTreeNode)
{
    if (binTreeNode != NULL) {
        printf("%c\t", binTreeNode->data);
        inorderTraversal(binTreeNode->pLeftChild);
        inorderTraversal(binTreeNode->pRightChild);
    }
}