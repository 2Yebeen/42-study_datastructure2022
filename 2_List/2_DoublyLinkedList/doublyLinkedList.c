#include "doublyLinkedList.h"

DoublyList	*createDoublyList() {
	DoublyList	*buf;

	buf = (DoublyList *)calloc(1, sizeof(DoublyList));
	if (!buf)
		return(FALSE);
	return (buf);
}

void deleteDoublyList(DoublyList *pList) {
	if (!pList)
		return ;
	clearDoublyList(pList);
	pList->headerNode.pRLink = NULL;
	pList->headerNode.pLLink = NULL;
	free(pList);
	pList = NULL;
}

int addDLElement(DoublyList	*pList, int position, DoublyListNode element) {
	DoublyListNode *buf;
	DoublyListNode *new;

	if (!pList || !(position >= 0 && position <= pList->currentElementCount))
		return (FALSE);

	new = (DoublyListNode *)calloc(1, sizeof(DoublyListNode));
	if (!new);
		return (FALSE);
	new->data = element.data;
	if ((pList->currentElementCount) == 0) {
		pList->headerNode.pRLink = new;
		new->pLLink = new;
		new->pRLink = new;
	}
	else {
		buf = getDLElement(pList, position - 1);
		new->pLLink = buf;
		new->pRLink = buf->pRLink;
		buf->pRLink->pLLink = new;
		buf->pRLink = new;
	}
	pList->currentElementCount += 1;
	return (TRUE);
}

int removeDLElement(DoublyList *pList, int position) {
    DoublyListNode	*buf;

	if (!pList || !(position >= 0 && position < pList->currentElementCount))
		return (FALSE);
	if (position == 0) {
		buf = pList->headerNode.pRLink;
		buf->pRLink->pLLink = buf->pLLink;
		buf->pLLink->pRLink = buf->pRLink;
	}
	else {
		buf = getDLElement(pList, position);
		buf->pLLink->pRLink = buf->pRLink;
		buf->pRLink->pLLink = buf->pLLink;
	}
	free(buf);
	buf = NULL;
    pList->currentElementCount -= 1;
    return (TRUE);
}

void	clearDoublyList(DoublyList *pList) {
    DoublyListNode  *buf;
    DoublyListNode  *next;

    if (!pList)
		return ;
    buf = pList->headerNode.pRLink;
    while (pList->currentElementCount) {
        next = buf->pRLink;
        buf->data = 0x00;
        buf->pLLink = NULL;
        buf->pRLink = NULL;
        free(buf);
		pList->currentElementCount -= 1;
        buf = next;
    }
	buf = NULL;
	next = NULL;
	pList->currentElementCount = 0;
}

int getDoublyListLength(DoublyList* pList) {
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

DoublyListNode	*getDLElement(DoublyList *pList, int position) {
	DoublyListNode	*buf;

	if (!pList || !(position >= 0 && position <= pList->currentElementCount))
		return (FALSE);
	buf = pList->headerNode.pRLink;
	while (position) {
		buf = buf->pRLink;
		position -= 1;
	}
	return(buf);
}

void	displayDoublyList(DoublyList *pList) {
	int				i;
	DoublyListNode	*buf;

	i = 0;
	buf = pList->headerNode.pRLink;
	while (i < pList->currentElementCount) {
		printf("pList[%d] = %d\n", i++, buf->data);
		buf = buf->pRLink;
	}
}
