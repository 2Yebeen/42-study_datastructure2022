#include "../include/arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount) {
    ArrayQueue *pQueue = (ArrayQueue *)calloc(1, sizeof(ArrayQueue));
    if (!pQueue || maxElementCount <= 0) return NULL;
    pQueue->pElement = (ArrayQueueNode *)calloc(maxElementCount, sizeof(ArrayQueueNode));
    if (!pQueue->pElement) {
        free(pQueue);
        return NULL;
    }
    pQueue->maxElementCount = maxElementCount;
    pQueue->front = -1;
    pQueue->rear = -1;

    return pQueue;
}

// 삽입 - Overflow, 원소 추가 가능 여부 판단 : isArrayQueueFull
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element) {
    int ret = FALSE;
    if (pQueue != NULL) {
        // 빈 공간이 있을 경우 삽입 가능
        if (isArrayQueueFull(pQueue) == FALSE) {
            // 마지막 인덱스 위치 이동후 데이터 삽입
            pQueue->rear++;
            pQueue->pElement[pQueue->rear].data = element.data;
            pQueue->currentElementCount++;
            ret = TRUE;
        }
    }
    return ret;
}

// 삭제 - Underflow, 공백 큐인지 판단 : isArrayQueueEmpty
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue) {
    ArrayQueueNode *pNode = (ArrayQueueNode *)calloc(1, sizeof(ArrayQueueNode));

    if (pQueue != NULL || pNode != NULL) {
        if (isArrayQueueEmpty(pQueue) == FALSE) {
            pQueue->front++;
            pNode->data = pQueue->pElement[pQueue->front].data;
            pQueue->pElement[pQueue->front].data = 0;
            pQueue->currentElementCount--;
        }
    }
    return pNode;
}

// 선택
ArrayQueueNode *peekAQ(ArrayQueue* pQueue) {
    ArrayQueueNode *pNode = (ArrayQueueNode *)calloc(1, sizeof(ArrayQueueNode));

    if (pQueue != NULL || pNode != NULL) {
        if (isArrayQueueEmpty(pQueue) == FALSE) {
            pNode->data = pQueue->pElement[pQueue->front + 1].data;
        }
    }
    return pNode;
}

// 전체 큐 삭제
void deleteArrayQueue(ArrayQueue* pQueue) {
    free(pQueue->pElement);
    free(pQueue);
    pQueue = NULL;
}

// 다 찼는지 확인
int isArrayQueueFull(ArrayQueue* pQueue) {
    return ((pQueue->currentElementCount == pQueue->maxElementCount 
            || pQueue->rear == pQueue->maxElementCount - 1) ? TRUE : FALSE);
}

// 비어있는지 확인
int isArrayQueueEmpty(ArrayQueue* pQueue) {
    return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}

void displayArrayQueue(ArrayQueue *pQueue) {
    if (pQueue != NULL) {
        printf("ArrayQueue\nmax count : %d\tcurrent count : %d\n", pQueue->maxElementCount, pQueue->currentElementCount);
        printf("front : %d, rear : %d\n", pQueue->front, pQueue->rear);
        for (int i = pQueue->front + 1; i <= pQueue->rear; i++) {
            printf("ArrayQueue[%d] = %c\n", i, pQueue->pElement[i].data);
        }
    }
}
