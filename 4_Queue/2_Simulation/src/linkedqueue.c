#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedqueue.h"
#include "../include/simulation.h"

LinkedQueue* createLinkedQueue()
{
	LinkedQueue *pQueue = NULL;
	pQueue = (LinkedQueue *)calloc(1, sizeof(LinkedQueue));

	return pQueue;
}

int enqueueLQ(LinkedQueue* pQueue, QueueNode element)
{
	int ret = FALSE;
	QueueNode *pNode = NULL;

	if (pQueue != NULL) {
		pNode = (QueueNode *)calloc(1, sizeof(QueueNode));
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLink = NULL;
			if (isLinkedQueueEmpty(pQueue) == TRUE)
				pQueue->pFrontNode = pNode;
			else
				pQueue->pRearNode->pLink = pNode;
			pQueue->pRearNode = pNode;
			pQueue->currentElementCount++;
			ret = TRUE;
		}
	}
	return ret;
}

QueueNode* dequeueLQ(LinkedQueue* pQueue)
{
	QueueNode* pNode = NULL;
	if (pQueue != NULL) {
		if (isLinkedQueueEmpty(pQueue) == FALSE) {
			pNode = pQueue->pFrontNode;
			pQueue->pFrontNode = pQueue->pFrontNode->pLink;
			pNode->pLink = NULL;
			// 노드가 1개일 때 마지막 노드의 연결을 제거한다.
			pQueue->currentElementCount--;
			if (isLinkedQueueEmpty(pQueue) == TRUE) {
				pQueue->pRearNode = NULL;
			}
		}
	}
	return pNode;
}

QueueNode* peekLQ(LinkedQueue* pQueue)
{
	QueueNode* pReturn = NULL;
	if (pQueue != NULL) {
		if (isLinkedQueueEmpty(pQueue) == FALSE) {
			pReturn = pQueue->pFrontNode;
		}
	}
	return pReturn;
}

void deleteLinkedQueue(LinkedQueue* pQueue)
{
	QueueNode *pNode = NULL;
	QueueNode *pDelNode = NULL;

	if (pQueue != NULL) {
		pNode = pQueue->pFrontNode;
		while(pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;
			free(pDelNode);
		}
		free(pQueue);
	}	
}

int isLinkedQueueFull(LinkedQueue* pQueue)
{
	int ret = FALSE;
	return ret;
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	int ret = FALSE;

	if (pQueue != NULL) {
		if (pQueue->currentElementCount == 0) {
			ret = TRUE;
		}
	}
	return ret;
}
