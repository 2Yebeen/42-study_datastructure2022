#include "../include/circularqueue.h"

CircularQueue* createCircularQueue(int maxElementCount) {
    CircularQueue *pQueue = (CircularQueue *)calloc(1, sizeof(CircularQueue));
    if (!pQueue || maxElementCount <= 0) return NULL;
    pQueue->pElement = (CircularQueueNode *)calloc(maxElementCount, sizeof(CircularQueueNode));
    if (!pQueue->pElement) {
        free(pQueue);
        return NULL;
    }
    pQueue->maxElementCount = maxElementCount;
    // pQueue->front = -1;
    // pQueue->rear = -1;
    return pQueue;
}

// 삽입 - rear = (rear + 1) % maxElementCount, 원소 추가 가능 여부 판단 : isCircularQueueFull
int enqueueCQ(CircularQueue* pQueue, CircularQueueNode element) {
    int ret = FALSE;
    if (pQueue != NULL) {
        // 빈 공간이 있을 경우 삽입 가능
        // printf("%d\n", (pQueue->rear+1) % pQueue->maxElementCount);
        if (isCircularQueueFull(pQueue) == FALSE) {
            pQueue->rear = (pQueue->rear+1)%pQueue->maxElementCount;
            pQueue->pElement[pQueue->rear].data = element.data;
            pQueue->currentElementCount++;
            ret = TRUE;
        }
    }
    return ret;
}

// 삭제 - front = (front + 1) % maxElementCount, 공백 큐인지 판단 : isCircularQueueEmpty
CircularQueueNode *dequeueCQ(CircularQueue* pQueue) {
    CircularQueueNode *pNode = (CircularQueueNode *)calloc(1, sizeof(CircularQueueNode));

    if (pQueue != NULL || pNode != NULL) {
        if (isCircularQueueEmpty(pQueue) == FALSE) {
            pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
            pNode->data = pQueue->pElement[pQueue->front].data;
            pQueue->pElement[pQueue->front].data = 0;
            pQueue->currentElementCount--;
        }
    }
    return pNode;
}

// 선택
CircularQueueNode *peekCQ(CircularQueue* pQueue) {
    int i;
    CircularQueueNode *pNode = (CircularQueueNode *)calloc(1, sizeof(CircularQueueNode));

    if (pQueue != NULL || pNode != NULL) {
        if (isCircularQueueEmpty(pQueue) == FALSE) {
            i = (pQueue->front + 1) % pQueue->maxElementCount;
            pNode->data = pQueue->pElement[i].data;
        }
    }
    return pNode;
}

// 전체 큐 삭제
void deleteCircularQueue(CircularQueue* pQueue) {
    free(pQueue->pElement);
    free(pQueue);
    pQueue = NULL;
}

// 다 찼는지 확인 
int isCircularQueueFull(CircularQueue* pQueue) {
    return ((pQueue->front == ((pQueue->rear + 1) % pQueue->maxElementCount)) ? TRUE : FALSE);
}

// 비어있는지 확인
int isCircularQueueEmpty(CircularQueue* pQueue) {
    return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}

void displayCircularQueue(CircularQueue *pQueue) {
    if (pQueue != NULL) {
        // int i = (pQueue->front + 1)%pQueue->maxElementCount;
        int i = pQueue->front;

        printf("CircularQueue\nmax count : %d\tcurrent count : %d\n", pQueue->maxElementCount, pQueue->currentElementCount);
        printf("front : %d, rear : %d\n", pQueue->front, pQueue->rear);
        while (i != pQueue->rear) {
            i = (i + 1)%pQueue->maxElementCount;
            printf("CircularQueue[%d] = %c\n", i, pQueue->pElement[i].data);
            if (i == pQueue->rear) break;
        }
    }
}
