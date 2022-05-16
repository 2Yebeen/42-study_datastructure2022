#include <stdio.h>
#include <stdlib.h>
#include "include/arrayheap.h"

void displayArrayHeap(ArrayMaxHeap* pHeap)
{
	int i = 0;
	if (pHeap != NULL) {
		for(i = 1; i <= pHeap->currentElementCount; i++) {
			printf("[%d],%d\n", i, pHeap->pElement[i]);
		}
	}
}

int main(int argc, char *argv[])
{
	int maxHeapSize = 20;

	ArrayMaxHeap *pHeap1 = NULL;

	ArrayHeapNode *pNode = NULL;
	ArrayHeapNode e1 = {10};
	ArrayHeapNode e2 = {40};
	ArrayHeapNode e3 = {30};
	ArrayHeapNode e4 = {20};
	ArrayHeapNode e5 = {50};

	pHeap1 = createArrayMaxHeap(maxHeapSize);
	if (pHeap1 != NULL) {
		insertArrayMaxHeapAH(pHeap1, e1);
		insertArrayMaxHeapAH(pHeap1, e2);
		insertArrayMaxHeapAH(pHeap1, e3);
		insertArrayMaxHeapAH(pHeap1, e4);
		insertArrayMaxHeapAH(pHeap1, e5);

		printf("Max Heap:\n");
		displayArrayHeap(pHeap1);
		
		pNode = deleteArrayMaxHeapAH(pHeap1);
		if (pNode != NULL) {
			printf("deleteMaxHeapAH()-[%d]\n", pNode->key);
			free(pNode);
		}

		printf("Max Heap:\n");
		displayArrayHeap(pHeap1);

		deleteArrayMaxHeap(pHeap1);
	}

	return 0;
}
