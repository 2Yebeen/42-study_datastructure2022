#include "linkedlist.h"

LinkedList* createLinkedList() // Linked list 생성
{
	LinkedList	*pList;

	pList = (LinkedList *)calloc(1, sizeof(LinkedList));
	return (pList);
}

int addLLElement(LinkedList* pList, int position, ListNode element) // Node 추가
{
	int		i;
	ListNode	*pNode;
	ListNode	*curr;
	ListNode	*prev;
	
	if (position < 0)
		return (FALSE);
	if(position == 0)
	{
		if (pList->currentElementCount == 0) // Header Node가 없을 때
		{
			pList->headerNode = element;
			pList->currentElementCount = 1;
			pList->headerNode.pLink = NULL;
		}
		else // Header Node가 있을 때
		{
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
	while(pNode && i < position)
	{
		if (i + 1 == position) // 새로 들어올 node를 위해 position 이전의 node의 주소를 저장한다.
			prev = pNode;
		pNode = pNode->pLink;
		i++;
	}
	if (position == i) // Node 추가
	{
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

int removeLLElement(LinkedList* pList, int position) // node를 지운다.
{
	size_t		i;
	ListNode	*pNode;
	ListNode	*prev;
	ListNode	*next;

	if (!(position >= 0 && position < pList->currentElementCount))
		return (FALSE);
	i = 0;
	pNode = &(pList->headerNode);
	if (position == 0) // Header Node일 때
	{
		if (!(pNode->pLink)) // Header Node 의 Next가 없을 때
		{
			pNode->data = 0x00;
			pNode->pLink = NULL;
			pList->currentElementCount -= 1;
		}
		else // Header Node 의 Next가 있을 때
		{
			pNode->data = 0x00;
			next = pNode->pLink;
			pList->headerNode = *next; // Header Node Next로 교체한다.
			next = NULL;
			pList->currentElementCount -= 1;
		}
		return (TRUE);
	}
	while (pNode != NULL && i < position)
	{
		if (i + 1 == position)
			prev = pNode;
		pNode = pNode->pLink;
		i++;
	}
	if (pNode && i == position) // Header Node가 아닐 때
	{
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

ListNode* getLLElement(LinkedList* pList, int position) // 원하는 위치의 Node를 얻는다.
{
	ListNode *pNode;

	// 위치가 음수인 것과 현재 엘리먼트 갯수보다 큰 위치의 노드는 없다!
    if (!(position >= 0 && position <= pList->currentElementCount))
        return (FALSE);
	pNode = &(pList->headerNode);
	while(position--) // position 만큼 이동한다.
		pNode = pNode->pLink;
    return (pNode);
}

void clearLinkedList(LinkedList* pList) // 내부 Node를 전부 없애준다.
{
	ListNode *pNode;
	ListNode *next;

	pNode = pList->headerNode.pLink;
	while(pNode)
	{
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

int getLinkedListLength(LinkedList* pList) // list 내부 Node의 개수 return
{
	
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList) // List와 Node를 제거한다.
{
	clearLinkedList(pList);
	free(pList);
    pList = NULL;
}	
