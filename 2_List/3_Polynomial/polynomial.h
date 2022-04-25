#ifndef _LINKEDLIST_
#define _LINKEDLIST_


#include <stdlib.h>
#include <stdio.h>

typedef struct ListNodeType
{
	int coef;
	int	degree;
	struct ListNodeType *pLLink;
	struct ListNodeType *pRLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	ListNode headerNode;
} LinkedList;

LinkedList* createPolynomialList();

int         addPLElement(LinkedList* pList, ListNode element);

ListNode	*getPLElement(LinkedList* pList, int position);
int	        getPolynomialListLength(LinkedList *pList);

int	        removePLElement(LinkedList *pList, int position);
void	    clearPolynomialList(LinkedList *pList);
void	    deletePolynomialList(LinkedList *pList);

void	    displayPLLinkedList(LinkedList *pList);

LinkedList	*plus(LinkedList *aList, LinkedList *bList);
LinkedList	*minus(LinkedList *aList, LinkedList *bList);
void	 	alloc_calc_node(LinkedList *new_list, LinkedList *base_list, int flag);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif