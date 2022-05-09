#include "include/arrayqueue.h"

int main (void) {
    ArrayQueue *pQueue = NULL;
    ArrayQueueNode *pNode = NULL;
    ArrayQueueNode pElement;

    // 큐생성
    pQueue = createArrayQueue(5);
    if (!pQueue) {
        printf("큐 생성 실패");
        return 0;
    }
    for (char i = 'A'; i <= 'D'; i++) {
        pElement.data = i;
        enqueueAQ(pQueue, pElement);
    }
    // pElement.data = 'E';
    // enqueueAQ(pQueue, pElement);
    displayArrayQueue(pQueue);
    printf("\n====================================================================\n");
    
    printf("\ndequeueAQ : %c\n", dequeueAQ(pQueue)->data);
    displayArrayQueue(pQueue);
    printf("\n====================================================================\n");

    printf("peakAQ : %c\n", peekAQ(pQueue)->data);
    displayArrayQueue(pQueue);
    printf("\n====================================================================\n");
    
    pElement.data = 'F';
    enqueueAQ(pQueue, pElement);
    displayArrayQueue(pQueue);
    printf("\n====================================================================\n");
    
    pNode = dequeueAQ(pQueue);
    printf("\ndequeueAQ : %c\n", pNode->data);
    free(pNode);
    pQueue->front = 4;
    pQueue->rear = 2;
    displayArrayQueue(pQueue);
    printf("\n====================================================================\n");
    deleteArrayQueue(pQueue);

    // system("leaks a.out");
    return 0;
}