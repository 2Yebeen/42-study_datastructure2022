#include "doublyLinkedList.h"

int main()
{
	DoublyList	*temp;
	DoublyListNode a;
	DoublyListNode b;
	DoublyListNode c;
	DoublyListNode *d;

	temp = createDoublyList();

	

	a.data = 1;
	a.pLLink = NULL;
	a.pRLink = &b;

	temp->headerNode.pRLink = &a;
	
	b.data = 2;
	b.pLLink = &a;
	b.pRLink = &c;

	c.data = 3;
	c.pLLink = &b;
	c.pRLink = NULL;

	d = malloc(sizeof(DoublyListNode));
	d = getDLElement(temp, 2);
	printf("%d", d->data);
	
}