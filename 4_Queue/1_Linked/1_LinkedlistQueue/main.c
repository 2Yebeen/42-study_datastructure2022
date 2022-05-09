#include "include/linkedqueue.h"

int main(void) {
    LinkedQueue *pQueue = NULL;
    QueueNode *pNode = NULL;
    QueueNode pElement;

    pQueue = createLinkedQueue();
    if (!pQueue) {
        printf("큐 생성 실패");
        return 0;
    }
    for (char i = 'A'; i <= 'E'; i++) {
        pElement.data = i;
        enqueueLQ(pQueue, pElement);
    }
    displayLinkedQueue(pQueue);
    printf("\n====================================================================\n");
    
    printf("dequeueLQ : %c\n", dequeueLQ(pQueue)->data);
    printf("peakCQ : %c\n", peekLQ(pQueue)->data);
    printf("dequeueLQ : %c\n", dequeueLQ(pQueue)->data);
    displayLinkedQueue(pQueue);
    printf("\n====================================================================\n");

    printf("peakCQ : %c\n", peekLQ(pQueue)->data);
    displayLinkedQueue(pQueue);
    printf("\n====================================================================\n");
    

    pElement.data = 'F';
    enqueueLQ(pQueue, pElement);
    displayLinkedQueue(pQueue);
    printf("\n====================================================================\n");
    
    for (int i = pQueue->currentElementCount - 1; i >= 0; i--){
        pNode = dequeueLQ(pQueue);
        printf("size : %d\tdequeueLQ : %c\n", pQueue->currentElementCount, pNode->data);
        pNode = pNode->pLink;
    }
    free(pNode);
    deleteLinkedQueue(pQueue);

    return 0;
}