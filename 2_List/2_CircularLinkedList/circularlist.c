#include "../include/circularlist.h"

// list 생성
CircularList	*createCircularList() {
	CircularList	*lst;

	lst = calloc(1, sizeof(CircularList)); // list 초기화
	return (lst);
}

// 원소 추가
int	addCLElement(CircularList *pList, int position, CircularListNode element) {
	CircularListNode	*buf;
	CircularListNode	*new;

	if (!pList || !(position >= 0 && position <= pList->currentElementCount))
		return (FALSE);
	
	new = calloc(1, sizeof(CircularListNode));
	new->data = element.data;
    // node가 없는 경우
	if ((pList->currentElementCount) == 0) {
		pList->headerNode.pRLink = new;         	// header 지정
		new->pRLink = pList->headerNode.pRLink; 	// pRlink를 자기 자신으로 하여 순회할 수 있게 한다.
	}
    // node가 있는 경우
	else {
		buf = getCLElement(pList, position - 1);    // 삽입할 포지션 전의 것을 지정한다.
		new->pRLink = buf->pRLink;                  // node 간 연결
		buf->pRLink = new;
		if (position == pList->currentElementCount) // 만약 position이 맨 끝일 경우 header 로 지정한다.
			pList->headerNode.pRLink = new;
	}
	pList->currentElementCount += 1;                // node 개수를 늘려준다.
	return (TRUE);
}

// 길이 반환
int getCircularListLength(CircularList *pList) {
	return (pList->currentElementCount);
}

// node 반환
CircularListNode *getCLElement(CircularList *pList, int position) {
	CircularListNode	*head;

    // if (!pList || !(position >= 0 && position <= pList->currentElementCount))
	// 	return (FALSE);
	head = pList->headerNode.pRLink->pRLink; // header 는 tail이므로 0 index는 header의 다음이 된다.
	// position 만큼 이동한다.
    while (position > 0) {
		head = head->pRLink;
		position--;
	}
	return (head);
}

// 개별 node 삭제
int	removeCLElement(CircularList *pList, int position) {
	CircularListNode	*buf;
	CircularListNode	*delNode;

    // postion이 0 이라면
	if (position == 0) {
		delNode = pList->headerNode.pRLink->pRLink; // 삭제할 node
		buf = pList->headerNode.pRLink;             // header
		buf->pRLink = delNode->pRLink;              // header의 다음을 delnode의 다음으로 지정한다.
	}
    // position이 0이 아니라면
	else {
		buf = getCLElement(pList, position - 1);    // position 전의 node
		delNode = getCLElement(pList, position);    // position node
		buf->pRLink = delNode->pRLink;              // 이어준다.
	}
	free(delNode);
	delNode = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

// 내부 node 전체 삭제
void clearCircularList(CircularList *pList) {
	CircularListNode	*head;
	CircularListNode	*next;
	int					idx;

	head = pList->headerNode.pRLink->pRLink;    // 0번째 node는 header 다음이다.
	while (idx < pList->currentElementCount) {  // 개수만큼 삭제한다.
		next = head->pRLink;
		head->pRLink = NULL;
		free(head);
		head = next;
		idx++;
	}
	head = NULL;
	next = NULL;
	pList->currentElementCount = 0;
}

// node와 list를 삭제한다.
void deleteCircularList(CircularList *pList) {
	clearCircularList(pList);
	free(pList);
	pList = NULL;
}

// 모든 node를 보여준다.
void displayCircularList(CircularList *pList) {
	CircularListNode	*head;
	int					idx;

	head = pList->headerNode.pRLink->pRLink; // 0번째 node는 header 다음 node이다.
	idx = 0;
	while (idx < pList->currentElementCount) {
		printf("pList[%d] = %d\n", idx++, head->data);
		head = head->pRLink;
	}
}
