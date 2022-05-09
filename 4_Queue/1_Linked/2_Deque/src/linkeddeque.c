#include "../include/linkeddeque.h"

LinkedDeque* createLinkedDeque() {
    LinkedDeque *pDeque = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
    if (!pDeque) return NULL;
    return pDeque;
}

DequeNode* createLinkedDequeNode(char data) {
    DequeNode *pNewNode;

    pNewNode = (DequeNode *)calloc(1, sizeof(DequeNode));
    if (!pNewNode) return NULL;
    pNewNode->data = data;
    return pNewNode;
}

// Front에 추가
int insertFrontLD(LinkedDeque* pDeque, DequeNode element) {
    DequeNode *pNode = createLinkedDequeNode(element.data);
    if (!pDeque || !pDeque) return FALSE;
    if (isLinkedDequeEmpty(pDeque) == TRUE) {
        pDeque->pFrontNode = pNode;
        pDeque->pRearNode = pNode;
   } else {
       pDeque->pFrontNode->pLLink = pNode;
       pNode->pRLink = pDeque->pFrontNode;
       pDeque->pFrontNode = pNode;
   }
   pDeque->currentElementCount++;
   return TRUE;
}

// Rear에 추가
int insertRearLD(LinkedDeque* pDeque, DequeNode element) {
    DequeNode *pNode = createLinkedDequeNode(element.data);
    if (!pDeque || !pDeque) return FALSE;
    if (isLinkedDequeEmpty(pDeque) == TRUE) {
        // insertFrontLD(pDeque, element);
        pDeque->pFrontNode = pNode;
        pDeque->pRearNode = pNode;
    } else {
        pDeque->pRearNode->pRLink = pNode;
        pNode->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = pNode;
    }
    pDeque->currentElementCount++;
    return TRUE;

}

// Front 제거 : front는 다음 노드를 가리키고 처음 노드 연결 끊음
DequeNode* deleteFrontLD(LinkedDeque* pDeque) {
    DequeNode *pNode = peekFrontLD(pDeque);
    if (pNode != NULL) {
        if (pDeque->currentElementCount == 1)
            pDeque->pRearNode = NULL;
        else
            pDeque->pFrontNode->pLLink = NULL;
    }
    pDeque->pFrontNode = pNode->pRLink;
    pNode->pRLink = NULL;
    pDeque->currentElementCount--;
    return pNode;
}

// Rear 제거 : rear는 이전 노드를 가리키고 마지막 노드 연결 끊음
DequeNode* deleteRearLD(LinkedDeque* pDeque) {
    DequeNode *pNode = peekRearLD(pDeque);
    if (pNode != NULL) {
        if (pDeque->currentElementCount == 1)
            pDeque->pFrontNode = NULL;
        else
            pDeque->pRearNode->pRLink = NULL;
    }
    pDeque->pRearNode = pNode->pLLink;
    pNode->pLLink = NULL;
    pDeque->currentElementCount--;
    return pNode;
}

DequeNode* peekFrontLD(LinkedDeque* pDeque) {
    return pDeque->pFrontNode;
}

DequeNode* peekRearLD(LinkedDeque* pDeque) {
    return pDeque->pRearNode;
}

void deleteLinkedDeque(LinkedDeque* pDeque) {
    DequeNode *pDelNode;
    DequeNode *pNode = pDeque->pFrontNode;
    size_t len = pDeque->currentElementCount;

    for (size_t i = 0; i < len; i++) {
        pDelNode = pNode;
        free(pDelNode);
        pNode->pRLink;
    }
    free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque) {
    return (pDeque->currentElementCount == 0 ? TRUE : FALSE);
}

void displayLinkedDeque(LinkedDeque *pDeQue) {
    size_t len = pDeQue->currentElementCount;
    DequeNode *pNode = pDeQue->pFrontNode;
    printf("current count : %ld\n", len);
    for (size_t i = 0; i < len; i++) {
        printf("Deque[%ld] = %c\n", i, pNode->data);
        pNode = pNode->pRLink;
    }
    free(pNode);
}