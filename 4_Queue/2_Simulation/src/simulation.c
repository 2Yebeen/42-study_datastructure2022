#include <stdio.h>
#include <stdlib.h>
#include "../include/simulation.h"
#include "../include/linkedqueue.h"

// 고객 도착 큐에 고객 추가
void insertCutomer(int arrivalTime, int serviceTime, LinkedQueue *pQueue) {
	if (pQueue != NULL) {
		QueueNode node={0,};
		node.data.status = arrival;
		node.data.arrivalTime = arrivalTime;
		node.data.serviceTime = serviceTime;
		node.data.startTime = 0;
		node.data.endTime = 0;
		enqueueLQ(pQueue, node);
	}
}

// 고객 도착 처리
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue) {
	QueueNode* pArrivalNode = NULL;
	int isEmpty = 0;

	isEmpty = isLinkedQueueEmpty(pArrivalQueue);
	while(isEmpty == FALSE) {
		pArrivalNode = peekLQ(pArrivalQueue);
		if (pArrivalNode->data.arrivalTime == currentTime) {
			enqueueLQ(pWaitQueue, *pArrivalNode);
			printSimCustomer(currentTime, pArrivalNode->data);

			free(dequeueLQ(pArrivalQueue));
		}
		else {
			break;
		}
		isEmpty = isLinkedQueueEmpty(pArrivalQueue);
	}
}

// 서비스 시작 처리
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime) {
	int endTime = 0;
	int waitTime = 0;
	QueueNode *pReturn = NULL;

	if (pServiceNode == NULL || pServiceUserCount == NULL || pTotalWaitTime == NULL) return NULL;

	endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
    // 서비스가 종료되었으면
	if (endTime <= currentTime) {
        // 대기시간 구하기 (시작시간 - 도착시간)
		waitTime = pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
		(*pServiceUserCount)++;
		(*pTotalWaitTime) += waitTime;

		pServiceNode->data.status = end;
		pServiceNode->data.endTime = currentTime;
		printSimCustomer(currentTime, pServiceNode->data);

		free(pServiceNode);
		pReturn = NULL;
	}
	else {
		pReturn = pServiceNode;
	}

	return pReturn;
}

// 서비스 종료 처리 : 새로운 서비스 시작
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode* pReturn = NULL;
	QueueNode* pServiceNode = NULL;
	int isEmpty = 0;

	if (pWaitQueue == NULL) {
		return NULL;
	}

	isEmpty = isLinkedQueueEmpty(pWaitQueue);
	if (isEmpty == FALSE) {
		pServiceNode = dequeueLQ(pWaitQueue);
		if (pServiceNode != NULL) {
			pServiceNode->data.status = start;
			pServiceNode->data.startTime = currentTime;
			printSimCustomer(currentTime, pServiceNode->data);

			pReturn = pServiceNode;
		}
	}
	return pReturn;
}

// 고객의 상태 출력
void printSimCustomer(int currentTime, SimCustomer customer) {
	printf("[%d]\t", currentTime);

	if (customer.status == arrival)
		printf("Arrive Customer\n");
	else if (customer.status == start)
		printf("Start Service\t| arrive time %d| wait time %d |\n", customer.arrivalTime, (customer.startTime - customer.arrivalTime));
	else if (customer.status == end) {
		printf("End Service\t| arrive time-%d | start time-%d | wait time-%d | service time-%d |\n", 
						customer.arrivalTime, customer.startTime
						, customer.startTime - customer.arrivalTime
						, customer.endTime - customer.startTime);
	}
}

// 대기 열의 상태 출력
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue) {
	printf("[%d]\tCurrent waiting customer count: %d\n", currentTime, pWaitQueue->currentElementCount);
}

// 최종 시뮬레이션 결과 출력
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime) {
	printf("\nREPORT\n");
	printf("Service user count: %d\n", serviceUserCount);
	if (serviceUserCount > 0) {
		printf("Avlage wating time: %f\n", ((float)totalWaitTime / (float)serviceUserCount));
	}
	printf("Current Wating customer count: %d\n", pWaitQueue->currentElementCount);

}