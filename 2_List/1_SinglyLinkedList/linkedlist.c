#include "linkedlist.h"

// Linked list 생성
LinkedList* createLinkedList() {
	LinkedList	*pList;

	pList = (LinkedList *)calloc(1, sizeof(LinkedList));
	return (pList);
}

// Node 추가
int addLLElement(LinkedList* pList, int position, ListNode element) {
	int		i;
	ListNode	*pNode;
	ListNode	*curr;
	ListNode	*prev;
	
	if (position < 0)
		return (FALSE);
	if(position == 0) {
		// Header Node가 없을 때
		if (pList->currentElementCount == 0) {
			pList->headerNode = element;
			pList->currentElementCount = 1;
			pList->headerNode.pLink = NULL;
		}
		// Header Node가 있을 때
		else {
			curr = malloc(sizeof(ListNode)); // 원래 header 의 데이터 복사
			curr->data = pList->headerNode.data;
			curr->pLink = pList->headerNode.pLink;
			element.pLink = curr; // 새로 들어온 element를 헤더로 바꾸기 위해 복사한 포인터를 next로 지칭
			pList->headerNode = element; // 새로 들어온 element를 헤더로 바꿔준다.
			pList->currentElementCount += 1;
		}
		return (TRUE);
	}
	pNode = &(pList->headerNode);
	i = 0;
	while(pNode && i < position) {
		if (i + 1 == position) // 새로 들어올 node를 위해 position 이전의 node의 주소를 저장한다.
			prev = pNode;
		pNode = pNode->pLink;
		i++;
	}
	// Node 추가
	if (position == i) {
		curr = malloc(sizeof(ListNode)); // node 추가를 위한 데이터 복사
		curr->data = element.data;
		curr->pLink = pNode; // 원래 위치의 node를 밀어내로
		prev->pLink = curr; // 원래 node 전의 node 의 next로 연결한다.
		pList->currentElementCount += 1;
		return (TRUE);
	}
	else
		return (FALSE);
}

// node를 지운다.
int removeLLElement(LinkedList* pList, int position) {
	size_t		i;
	ListNode	*pNode;
	ListNode	*prev;
	ListNode	*next;

	if (!(position >= 0 && position < pList->currentElementCount))
		return (FALSE);
	i = 0;
	pNode = &(pList->headerNode);
	// Header Node일 때
	if (position == 0) {
		// Header Node 의 Next가 없을 때
		if (!(pNode->pLink)) {
			pNode->data = 0x00;
			pNode->pLink = NULL;
			pList->currentElementCount -= 1;
		}
		// Header Node 의 Next가 있을 때
		else {
			pNode->data = 0x00;
			next = pNode->pLink;
			pList->headerNode = *next; // Header Node Next로 교체한다.
			next = NULL;
			pList->currentElementCount -= 1;
		}
		return (TRUE);
	}
	while (pNode != NULL && i < position) {
		if (i + 1 == position)
			prev = pNode;
		pNode = pNode->pLink;
		i++;
	}
	// Header Node가 아닐 때
	if (pNode && i == position) {
		next = pNode->pLink; // 현재 위치 다음 것을
		prev->pLink = next; // 현재 위치 전의 것에 연결해준다.
		pNode->data = 0x00;
		pNode->pLink = NULL;
		free(pNode);
		pList->currentElementCount -= 1;
		return (TRUE);
	}
	else
		return (FALSE);
}

// 원하는 위치의 Node를 얻는다.
ListNode* getLLElement(LinkedList* pList, int position) {
	ListNode *pNode;

	// 위치가 음수인 것과 현재 엘리먼트 갯수보다 큰 위치의 노드는 없다!
    if (!(position >= 0 && position <= pList->currentElementCount))
        return (FALSE);
	pNode = &(pList->headerNode);
	while(position--) // position 만큼 이동한다.
		pNode = pNode->pLink;
    return (pNode);
}

// 내부 Node를 전부 없애준다.
void clearLinkedList(LinkedList* pList) {
	ListNode *pNode;
	ListNode *next;

	pNode = pList->headerNode.pLink;
	while(pNode) {
		next = pNode->pLink;
		pNode->data = 0x00;
		free(pNode);
        pNode = NULL;
		pNode = next;
	}
	pList->headerNode.data = 0x00;
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
}

// list 내부 Node의 개수 return
int getLinkedListLength(LinkedList* pList) {
	
	return (pList->currentElementCount);
}

// List와 Node를 제거한다.
void deleteLinkedList(LinkedList* pList) {
	clearLinkedList(pList);
	free(pList);
    pList = NULL;
}	
