#ifndef _SIMULATION_
#define _SIMULATION_

#include "linkedqueue.h"

void        insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue);											// 고객 도착 큐에 고객 추가
void        processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);							// 고객 도착 처리
QueueNode*  processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);												// 서비스 시작 처리
QueueNode*  processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);	// 서비스 종료 처리
void        printSimCustomer(int currentTime, SimCustomer customer);														// 고객의 상태 출력
void        printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);													// 대기 열의 상태 출력
void        printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);									// 최종 시뮬레이션 결과 출력

#endif	//_SIMULATION_