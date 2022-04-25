#include "../include/polynomial.h"

// list를 생성한다.
LinkedList *createPolynomialList() {
	LinkedList	*lst;

	lst = calloc(1, sizeof(LinkedList));
    if (!lst)
        return (FALSE);
	return (lst);
}

// 차수가 같은지 판별하여 더해준다.
int find_degree(LinkedList *pList, ListNode element) {
	ListNode	*headNode;
	int			i;

	headNode = pList->headerNode.pRLink->pLLink;            // 뒤에서 부터 찾는다.
	i = pList->currentElementCount;
	while (i-- && !(headNode->degree == element.degree))
		headNode = headNode->pLLink;
    // 차수가 같다면
	if (headNode->degree == element.degree) {
		headNode->coef += element.coef;                     // 더해준다.
		if (headNode->coef == 0)                            // 더한 결과가 0이라면 remove
			removePLElement(pList, i);
		return (TRUE);
	}
	return (FALSE);
}

int addPLElement(LinkedList *pList, ListNode element) {
	ListNode	*newNode;
	ListNode	*headNode;
	int			i;

	newNode = calloc(1, sizeof(ListNode));
	newNode->coef = element.coef;
	newNode->degree = element.degree;
    // header node 일 경우
	if (pList->currentElementCount == 0) { 
		pList->headerNode.pRLink = newNode;         // header로 지정한다.
		newNode->pLLink = pList->headerNode.pRLink; // 자기 자신을 지칭하게 한다.
		newNode->pRLink = newNode;
	}
	else {
        // 만약 같은 차수가 있다면, 기존 node에 더해준다.
		if (find_degree(pList, element)) {
			free(newNode);
			newNode = NULL;
			return (TRUE);
		}
		i = 0;
		headNode = pList->headerNode.pRLink->pLLink; // 뒤에서 부터 찾아준다.
		// 새로 들어올 node의 차수가 더 작을 때 멈춰 차수로 정렬한다.
		while (headNode->degree < newNode->degree) {
			if (i++ == pList->currentElementCount)  // while 문은 node 개수만큼만 반복한다.
				break ;
			headNode = headNode->pLLink;
		}
		newNode->pLLink = headNode;                 // 기존 list에 삽입한다.
		newNode->pRLink = headNode->pRLink;
		headNode->pRLink->pLLink = newNode;
		headNode->pRLink = newNode;
		headNode = &(pList->headerNode);
		// 만약 갱신된 node의 차수가 더 크다면 header를 갱신한다.
		if (headNode->pRLink->pLLink->degree - headNode->pRLink->degree > 0) 
			headNode->pRLink = headNode->pRLink->pLLink;
	}
	pList->currentElementCount++;
	return (TRUE);
}

// 원하는 position의 node를 보여준다.
ListNode *getPLElement(LinkedList* pList, int position) {
	ListNode	*head;

	head = pList->headerNode.pRLink;
	while (position) {
		head = head->pRLink;
		position -= 1;
	}
	return (head);
}

// list의 length를 반환한다.
int getPolynomialListLength(LinkedList *pList) {
	return (pList->currentElementCount);
}

// 내부 node 전부를 보여준다.
void displayPLLinkedList(LinkedList *pList) {
	ListNode	*head;
	int			idx = pList->currentElementCount;

	head = pList->headerNode.pRLink;
	while (idx) {
		if (idx == pList->currentElementCount)
			printf("%dx^%d ", head->coef, head->degree);
		else if (head->coef > 0)
			printf("+ %dx^%d ", head->coef, head->degree);
		else
			printf("- %dx^%d ", -head->coef, head->degree);
		head = head->pRLink;
		idx--;
	}
	printf("\n");
}

int removePLElement(LinkedList *pList, int position) // 개별 node 삭제
{
	ListNode	*headNode;
	int			i;

	// position이 음수이거나, 현재 node 개수 이상일 수 없다.
	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	i = 0;
	headNode = pList->headerNode.pRLink;
	while (i++ < position)
		headNode = headNode->pRLink;
	headNode->pLLink->pRLink = headNode->pRLink;
	headNode->pRLink->pLLink = headNode->pLLink;
	pList->currentElementCount--;
	if (ZERO(position) && UPPER_ZERO(pList->currentElementCount))   // 만약 header node 라면
		pList->headerNode.pRLink = headNode->pRLink;                // header를 갱신한다.
	headNode->pLLink = NULL;
	headNode->pRLink = NULL;
	free(headNode);
	headNode = NULL;
	return (TRUE);
}

// 내부 node를 전부 삭제한다.
void clearPolynomialList(LinkedList *pList) {
	ListNode	*headNode;
	ListNode	*nextNode;

	headNode = pList->headerNode.pRLink;
	while (pList->currentElementCount)
	{
		nextNode = headNode->pRLink;
		headNode->pLLink = NULL;
		headNode->pRLink = NULL;
		free(headNode);
		headNode = nextNode;
		pList->currentElementCount -= 1;
	}
	nextNode = NULL;
	headNode = NULL;
}

// 내부 node와 list를 삭제한다.
void deletePolynomialList(LinkedList *pList) {
	clearPolynomialList(pList);
	free(pList);
	pList = NULL;
}

void alloc_calc_node(LinkedList *new_list, LinkedList *base_list, int flag) {
	ListNode	*base_head;
	ListNode	*new_node;
	int			baseidx = base_list->currentElementCount;   // 연산을 위해 base list node 갯수를 저장한다.

	base_head = base_list->headerNode.pRLink;
	new_node = calloc(1, sizeof(ListNode));
	while(baseidx--) {
		new_node->degree = base_head->degree;
		if (flag)
			new_node->coef = -(base_head->coef);	
		else
			new_node->coef = base_head->coef;
		addPLElement(new_list, *new_node);                  // node를 새로운 list에 할당한다.
		base_head = base_head->pRLink;
	}
	free(new_node);
	new_node = NULL;
	deletePolynomialList(base_list);
	base_list = NULL;
}

// 다항식의 뺏셈
LinkedList *minus(LinkedList *aList, LinkedList *bList) {
	LinkedList	*newList = createPolynomialList();
	alloc_calc_node(newList, aList, 0);
	alloc_calc_node(newList, bList, 1);
	return (newList);
}

// 다항식의 덧셈
LinkedList *plus(LinkedList *aList, LinkedList *bList) {
	LinkedList	*newList = createPolynomialList();
	alloc_calc_node(newList, aList, 0);
	alloc_calc_node(newList, bList, 0);
	return (newList);
}

