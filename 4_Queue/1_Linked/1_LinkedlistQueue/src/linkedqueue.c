#include "../include/linkedqueue.h"

LinkedQueue* createLinkedQueue() {
    LinkedQueue *pQueue = (LinkedQueue *)calloc(1, sizeof(LinkedQueue));
    if (!pQueue) return NULL;
    return pQueue;
}

int enqueueLQ(LinkedQueue* pQueue, QueueNode element) {
    QueueNode *pNode = (QueueNode *)calloc(1, sizeof(QueueNode));
    if (!pQueue || !pNode) return FALSE;
    pNode->data = element.data;
    if (isLinkedQueueEmpty(pQueue) == TRUE)
        pQueue->pFrontNode = pNode;
    else
        pQueue->pRearNode->pLink = pNode;
    pQueue->pRearNode = pNode;
    pQueue->currentElementCount++;
    return TRUE;
}

QueueNode* dequeueLQ(LinkedQueue* pQueue) {
    QueueNode *pNode = pQueue->pFrontNode;
    if (isLinkedQueueEmpty(pQueue) == TRUE || !pQueue) return NULL;
    // 노드가 1개일 때 마지막 노드의 연결을 제거한다.
    if (pQueue->currentElementCount == 1) pQueue->pRearNode = NULL;
    pQueue->pFrontNode = pNode->pLink;
    pQueue->currentElementCount--;
    return pNode;
}

QueueNode* peekLQ(LinkedQueue* pQueue) {
    return pQueue->pFrontNode;
}

void deleteLinkedQueue(LinkedQueue* pQueue) {
    size_t len = pQueue->currentElementCount;
    QueueNode *pNode = pQueue->pFrontNode;
    QueueNode *pDelNode;

    for (int i = 0; i < len; i++) {
        pDelNode = pNode;
        free(pDelNode);
        pNode = pNode->pLink;
    }
    free(pQueue);
}

int isLinkedQueueEmpty(LinkedQueue* pQueue) {
    return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}

void displayLinkedQueue(LinkedQueue *pQueue) {
    if (!pQueue) {
        printf("Queue is NULL");
        return ;
    }
    QueueNode *pNode = pQueue->pFrontNode;
    printf("current count : %d\n", pQueue->currentElementCount);
    for (int i = 0; i < pQueue->currentElementCount; i++) {
        printf("Queue[%d] = %c\n", i, pNode->data);
        pNode = pNode->pLink;
    }
    free(pNode);
}
