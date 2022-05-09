#include "include/LinkedDeque.h"

int main(void) {
    LinkedDeque *pDeque = NULL;
    DequeNode *pNode = NULL;
    DequeNode pElement;

    pDeque = createLinkedDeque();
    if (!pDeque) {
        printf("큐 생성 실패");
        return 0;
    }
    for (char i = 'A'; i <= 'C'; i++) {
        pElement.data = i;
        insertFrontLD(pDeque, pElement);
    }
    for (char i = 'D'; i <= 'F'; i++) {
        pElement.data = i;
        insertRearLD(pDeque, pElement);
    }
    displayLinkedDeque(pDeque);
    printf("\n====================================================================\n");
    
    printf("deleteFrontLD : %c\n", deleteFrontLD(pDeque)->data);
    printf("peekFrontLD : %c\n", peekFrontLD(pDeque)->data);
    printf("deleteFrontLD : %c\n", deleteFrontLD(pDeque)->data);
    displayLinkedDeque(pDeque);
    printf("\n====================================================================\n");

    printf("deleteRearLD : %c\n", deleteRearLD(pDeque)->data);
    printf("peekRearLD : %c\n", peekRearLD(pDeque)->data);
    printf("deleteRearLD : %c\n", deleteRearLD(pDeque)->data);
    printf("peekRearLD : %c\n", peekRearLD(pDeque)->data);
    printf("deleteRearLD : %c\n", deleteRearLD(pDeque)->data);
    displayLinkedDeque(pDeque);
    printf("\n====================================================================\n");
    

    pElement.data = 'G';
    insertFrontLD(pDeque, pElement);
    pElement.data = 'H';
    insertRearLD(pDeque, pElement);
    displayLinkedDeque(pDeque);
    printf("\n====================================================================\n");
    
    while (pDeque->currentElementCount) {
        pNode = deleteFrontLD(pDeque);
        printf("size : %d\tDequeDQ : %c\n", pDeque->currentElementCount, pNode->data);
    }
    free(pNode);

    printf("\n====================================================================\n");

    for (char i = 'I'; i <= 'N'; i++) {
        pElement.data = i;
        insertRearLD(pDeque, pElement);
    }
    displayLinkedDeque(pDeque);
    printf("\n====================================================================\n");

    while (pDeque->currentElementCount) {
        pNode = deleteRearLD(pDeque);
        printf("size : %d\tDequeDQ : %c\n", pDeque->currentElementCount, pNode->data);
    }
    free(pNode);
    deleteLinkedDeque(pDeque);

    return 0;
}