/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:56:54 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/16 20:23:02 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

/*linked list를 만든다*/
LinkedList*	createLinkedList()
// {
// 	LinkedList	*pList;

// 	pList = (LinkedList *)malloc(sizeof(LinkedList));
// 	if (!pList)
// 		return (NULL);
// 	memset(pList, 0, sizeof(LinkedList));
// 	return (pList);
// }
{
    LinkedList *new;

    new = calloc(1, sizeof(LinkedList)); // 구조체 변수 (현재 원소 개수 - 0, pLink - NULL) 초기화를 위해 calloc 사용하여 할당
    if (!new)
        return (NULL);
    return (new);
}

/*linked list의 특정 위치에 node를 추가한다.*/
int addLLElement(LinkedList* pList, int position, ListNode element)  
// {
//     ListNode* pPreNode;
//     ListNode* pNewNode;

// 	if (!pList || !(position >= 0 && position <= pList->currentElementCount))
// 		return (FALSE);
// 	pNewNode = (ListNode*)malloc(sizeof(ListNode));
// 	if (!pNewNode)
// 		return (FALSE);
// 	*pNewNode = element;
// 	pNewNode->pLink = NULL;

// 	pPreNode = &(pList->headerNode);    //들어가야할 위치를 찾기 위한 노드
// 	while (position--)
// 		pPreNode = pPreNode->pLink;        //다음 노드로 계속 넘어감
// 	pNewNode->pLink = pPreNode->pLink;    //노드 연결
// 	pPreNode->pLink = pNewNode;
// 	pList->currentElementCount++;
//     return (TRUE);
// }
{
    ListNode *new; // 추가하려는 노드
    ListNode *prev; // 추가하려는 노드를 연결 할 이전 노드

    if(!pList || position < 0 || position > pList->currentElementCount) // 에러 처리
        return (FALSE);
    new = malloc(sizeof(ListNode) * 1); // 새 노드 할당
    if (!new)
        return (FALSE);
    *new = element; // 역참조를 통해 추가하려는 원소의 모든 정보 저장
    prev = &(pList->headerNode); // headerNode라는 더미노드를 통해 연결
    for (int i = 0; i < position; i++) // 추가하려는 position '전' 까지 prev 이동
        prev = prev->pLink;
    new->pLink = prev->pLink; // 추가하려는 노드의 pLink에 이전 노드의 pLink를 연결
    prev->pLink = new; // 이전 노드의 pLink를 추가하려는 노드에 연결
    // 위 두 과정의 순서가 바뀔 시 이전 노드의 pLink를 잃게 되므로 순서 중요
    pList->currentElementCount++; // 현재 원소 개수 갱신
    return (TRUE);
}
/*linked list의 특정 위치에 있는 node를 제거한다.*/
int removeLLElement(LinkedList *pList, int position)
{
	ListNode	*pDelNode;
	ListNode	*pNode;

	if (!pList || !(position >= 0 && position < pList->currentElementCount))
		return (FALSE);
	pNode = &(pList->headerNode);
	while (position--)
		pNode = pNode->pLink;
	pDelNode = pNode->pLink;
	pNode->pLink = pDelNode->pLink;
	free(pDelNode);
	pList->currentElementCount--;
	return (TRUE);
}

/*linked list의 특정 위치에 있는 node값 반환한다.*/
ListNode*	getLLElement(LinkedList *pList, int position)
{
	ListNode	*pNode;

	if (!pList || !(position >= 0 && position < pList->currentElementCount))
		return (NULL);
	pNode = &(pList->headerNode);
	while (position--)
		pNode = pNode->pLink;
	return (pNode);
}

/*linked list를 비운다.*/
void clearLinkedList(LinkedList *pList)
{
	ListNode	*pDelNode;
	ListNode	*pNode;

	if (pList->currentElementCount == 0)
		return ;
	pNode = &(pList->headerNode);
	while (pNode)
	{
		pDelNode = pNode;
		pNode = pNode->pLink;
		free(pDelNode);
		pDelNode = NULL;
	}
	pList->currentElementCount = 0;
}

/*linked list의 길이를 반환한다.*/
int	getLinkedListLength(LinkedList *pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

/*linked list를 삭제한다.*/
void	deleteLinkedList(LinkedList *pList)
{
	if (!pList)
		return ;
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}


int	main(void)
{
	LinkedList *temp;
	ListNode *buf;

	ListNode a;
	ListNode b;
	ListNode c;
	ListNode d;
	ListNode e;
	
	a.data = 5;
	a.pLink = NULL;

	b.data = 1;
	b.pLink = NULL;

	c.data = 3;
	c.pLink = NULL;

	d.data = 4;
	d.pLink = NULL;

	e.data = 12;
	e.pLink = NULL;
	
	temp = createLinkedList();
	addLLElement(temp, 0, a);
	addLLElement(temp, 0, b);
	addLLElement(temp, 0, c);
	addLLElement(temp, 0, d);
	addLLElement(temp, 0, e);
	buf = &(temp->headerNode);

	while(buf)
	{
		printf("buf : %d\n", buf->data);
		buf = buf->pLink;
	}
	
	// ListNode *aa = getLLElement(temp, 3);
	// printf("%d\n", aa->data);
	// clearLinkedList(temp);

	// removeLLElement(temp, 2);
	// deleteLinkedList(temp);
	// buf = &(temp->headerNode);
	// while(buf)
	// {
	// 	printf("\n%d\n", buf->data);
	// 	buf = buf->pLink;
	// }
	printf("the length %d\n", getLinkedListLength(temp));
	return 0;
}
