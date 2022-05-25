#include "../include/linkedlistgraph.h"

// 그래프 생성
LinkedList* createLinkedList(){
    LinkedList *pGraph = (LinkedList *)calloc(1, sizeof(LinkedList));

    if (!pGraph) return NULL;
    return pGraph;
}
// ListNode *addLNElement(ListNode *pNode, )

// 그래프 노드 추가
int addLLElement(LinkedList* pList, int position, ListNode element){
    ListNode *pPreNode = NULL;
    ListNode *pNewNode = NULL;

    if (!pList || position < 0 || position > pList->currentElementCount) return FALSE;
    
    pNewNode = (ListNode *)calloc(1, sizeof(ListNode));
    pNewNode->data = element.data;
    pPreNode = getLLElement(pList, position-1);
    pNewNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNewNode;
    pList->currentElementCount++;
    
    return TRUE;
}

ListNode* getLLElement(LinkedList* pList, int position){
    ListNode *pNode = NULL;

    if (!pList || position < 0 || position > pList->currentElementCount) return NULL;
    pNode = &(pList->headerNode);
    for (int i = 0; i <= position; i++) {
        pNode = pNode->pLink;
    }

    return pNode;
}

int getLinkedListLength(LinkedList* pList){
    return (pList != NULL ? pList->currentElementCount : FALSE);
}

// 그래프 노드 삭제
int removeLLElement(LinkedList* pList, int position){
    int cnt = 0;
    ListNode *pNode = NULL;
    ListNode *pDelNode = NULL;

    if (!pList || position < 0 || position > pList->currentElementCount) return FALSE;
    cnt = getLinkedListLength(pList);
    pNode = getLLElement(pList, position - 1);
    pDelNode = getLLElement(pList, position);
    pDelNode = pNode->pLink;
    pNode->pLink = pDelNode->pLink;
    free(pDelNode);
    pDelNode = NULL;
    pList->currentElementCount--;

    return TRUE;
}

void clearLinkedList(LinkedList* pList){
    if (pList != NULL) {
        removeLLElement(pList, 0);
    }
}

void deleteLinkedList(LinkedList* pList){
    if (pList != NULL) {
        clearLinkedList(pList);
        free(pList);
        pList = NULL;
    }
}