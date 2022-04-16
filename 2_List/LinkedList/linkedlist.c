#include "linkedlist.h"

/*linked list를 만든다*/
LinkedList* createLinkedList()
{
    LinkedList *pList;

	pList = (LinkedList *)malloc(sizeof(LinkedList));
	if (!pList)
        return (NULL);
    memset(pList, 0, sizeof(LinkedList));
	return (pList);
}

/*linked list의 특정 위치에 node를 추가한다.*/
int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode *pNewNode;
    ListNode *pNode;

    if (!pList || !(position >= 0 && position < pList->currentElementCount))
        return (FALSE);
    pNewNode = (ListNode *)malloc(sizeof(ListNode));
    if (!pNewNode)
        return (FALSE);
    *pNewNode = element;
    pNewNode->pLink = NULL;
    *pNode = pList->headerNode;
    while (position--)
        pNode = pNode->pLink;
    pNewNode->pLink = pNode->pLink;
    pNode->pLink = pNewNode;
    pList->currentElementCount++;
    return (TRUE);
}

/*linked list의 특정 위치에 있는 node를 제거한다.*/
int removeLLElement(LinkedList* pList, int position)
{
    ListNode *pDelNode;
    ListNode *pNode;

    if (!pList || !(position >= 0 && position < pList->currentElementCount))
        return (FALSE);
    *pNode = pList->headerNode;
    while (position--)
        pNode = pNode->pLink;
    pDelNode = pNode->pLink;
    pNode->pLink = pDelNode->pLink;
    free(pDelNode);
    pDelNode = NULL;
    pList->currentElementCount--;
    return (TRUE);
}

/*linked list의 특정 위치에 있는 node값 반환한다.*/
ListNode* getLLElement(LinkedList* pList, int position)
{
    ListNode *pNode;

    if (!pList || !(position >= 0 && position < pList->currentElementCount))
        return (NULL);
    *pNode = pList->headerNode;
    while (position--)
        pNode = pNode->pLink;
    return (pNode);
}

/*linked list를 비운다.*/
void clearLinkedList(LinkedList* pList)
{
    ListNode *pDelNode;
    ListNode *pNode;

    if(pList->currentElementCount == 0)
        return ;
    *pNode = pList->headerNode;
    while (pNode)
    {
        pDelNode = pNode;
        pNode = pNode->pLink;
        free(pDelNode);
    }
    pDelNode = NULL;
    pList->currentElementCount = 0;
}

/*linked list의 길이를 반환한다.*/
int getLinkedListLength(LinkedList* pList)
{
    if (!pList)
        return (FALSE);
    return (pList->currentElementCount);
}

/*linked list를 삭제한다.*/
void deleteLinkedList(LinkedList* pList)
{
    ListNode *pDelNode;
    ListNode *pNode;

    if (!pList)
        return ;
    pDelNode = NULL;
    *pNode = pList->headerNode;
    while (pNode)
    {
        pDelNode = pNode;
        pNode = pNode->pLink;
        free(pDelNode);
    }
    pDelNode = NULL;
    free(pList);
    pList = NULL;
}
