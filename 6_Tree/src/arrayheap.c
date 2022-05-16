#include "../include/arrayheap.h"

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount) {
    ArrayMaxHeap *pHeap = NULL;
    
    if (maxElementCount <= 0) return NULL;
    pHeap = (ArrayMaxHeap *)calloc(1, sizeof(ArrayMaxHeap));
    pHeap->maxElementCount = maxElementCount;
    pHeap->pElement = (ArrayHeapNode *)calloc(1, sizeof(ArrayHeapNode));

    return pHeap;
}

int insertArrayMaxHeapAH(ArrayMaxHeap* pHeap, ArrayHeapNode element) {
    int i = 0;
    int ret = FALSE;
    if (pHeap != NULL && (pHeap->currentElementCount > pHeap->maxElementCount)) {
        // 트리의 마지막 자리에 임시 저장
        pHeap->currentElementCount++;
        i = pHeap->currentElementCount;
        // 부모 노드와 키 값 비교 및 이동
        while ((i != 1) && (element.key > pHeap->pElement[i/2].key)) {
            pHeap->pElement[i] = pHeap->pElement[i/2];
            i/=2;
        }
        pHeap->pElement[i] = element;
        
        ret = TRUE;
    }
    return ret;
}

ArrayHeapNode* deleteArrayMaxHeapAH(ArrayMaxHeap* pHeap) {
    int parent = 1, child = 2;
    ArrayHeapNode *pDelNode = (ArrayHeapNode *)calloc(1, sizeof(ArrayHeapNode));
    ArrayHeapNode *pNode = NULL;

    if (pHeap == NULL || pHeap->currentElementCount <= 0 || pDelNode == NULL) return NULL;
    // 루트 노드 삭제
    pDelNode = &(pHeap->pElement[1]);
    // 트리 마지막 자리 노드의 임시 이동
    pNode = &(pHeap->pElement[pHeap->currentElementCount]);
    pHeap->currentElementCount--;
    // 자식 노드와 키 값 비교 및 이동
    while(child <= pHeap->currentElementCount) {
        if ((child < pHeap->currentElementCount)
            && pHeap->pElement[child].key < pHeap->pElement[child+1].key) {
                child++;
        }
        if (pNode->key >= pHeap->pElement[child].key) break;
        pHeap->pElement[parent] = pHeap->pElement[child];
        parent = child;
        child *= 2;
    }
    pHeap->pElement[parent] = *pNode;

    return pDelNode;
}

void deleteArrayMaxHeap(ArrayMaxHeap* pHeap) {
    if (pHeap != NULL) {
        if (pHeap->pElement != NULL) {
            free (pHeap->pElement);
            pHeap->pElement = NULL;
        }
        free (pHeap);
        pHeap = NULL;
    }
}