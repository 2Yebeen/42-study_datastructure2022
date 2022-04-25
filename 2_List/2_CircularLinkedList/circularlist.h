#ifndef _CIRCULAR_LIST_
#define _CIRCULAR_LIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType	*pRLink;
} CircularListNode;

typedef struct CircularListType
{
	int	currentElementCount;	
	CircularListNode	headerNode;
}	CircularList;

CircularList		*createCircularList();
int	                addCLElement(CircularList *pList, int position, CircularListNode element);

CircularListNode	*getCLElement(CircularList *pList, int position);
int				    getCircularListLength(CircularList *pList);

int				    removeCLElement(CircularList *pList, int position);
void	    		clearCircularList(CircularList *pList);
void    			deleteCircularList(CircularList *pList);

void		    	displayCircularList(CircularList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif