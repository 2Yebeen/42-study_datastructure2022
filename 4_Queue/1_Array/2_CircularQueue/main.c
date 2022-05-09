#include "include/Circularqueue.h"

int main (void) {
    CircularQueue *pQueue = NULL;
    CircularQueueNode *pNode = NULL;
    CircularQueueNode pElement;

    // 큐생성
    pQueue = createCircularQueue(9);
    if (!pQueue) {
        printf("큐 생성 실패");
        return 0;
    }
    for (char i = 'A'; i <= 'E'; i++) {
        pElement.data = i;
        enqueueCQ(pQueue, pElement);
    }
    displayCircularQueue(pQueue);
    printf("\n====================================================================\n");
    
    pNode = dequeueCQ(pQueue);
    printf("\ndequeueCQ : %c\n", pNode->data);
    free(pNode);
    printf("\n====================================================================\n");
    displayCircularQueue(pQueue);
    printf("\n====================================================================\n");

    pNode = peekCQ(pQueue);
    printf("peakCQ : %c\n", pNode->data);
    free(pNode);
    printf("\n====================================================================\n");
    displayCircularQueue(pQueue);
    printf("\n====================================================================\n");
    
    pElement.data = 'F';
    enqueueCQ(pQueue, pElement);
    displayCircularQueue(pQueue);
    printf("\n====================================================================\n");
    deleteCircularQueue(pQueue);

    // system("leaks a.out");
    return 0;
}