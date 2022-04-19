# 연결 리스트 (Linked List)

## 목차
1. [단일 연결 리스트란 ?](#단일-연결-리스트-sing-linked-list)
2. [단일 연결 리스트의 특징](#특징)
3. [단일 연결 리스트 구현](#구현)
    1. [리스트 생성](#생성)
    2. [원소 추가](#추가)
    3. [원소 반환](#반환)
    4. [원소 제거](#제거)
    5. [리스트 삭제](#삭제)

<br>

## 단일 연결 리스트 (Sing Linked List)

<img src="https://upload.wikimedia.org/wikipedia/commons/9/9c/Single_linked_list.png">


<p>
단일 연결 리스트는 각 노드들이 한 줄로 연결되어 있는 자료구조이다. 이름에서 말하듯이 데이터를 담고 있는 노드들이 연결되어 있는데, 노드의 포인터가 다음이나 이전의 노드와의 연결을 담당하게 된다. 연결 리스트는 늘어선 노드의 중간지점에서도 자료의 추가와 삭제가 O(1)의 시간에 가능하다는 장점을 갖는다. (다만, 오늘 구현할 것은 tail을 갖지 않는 linked list로 1번의 반복문을 거치게 된다.) 다만, 기존 링크를 해제하거나 삽입할 때에는 기존 링크의 전이나 다음 노드 관리에 대해 유의해야 한다. 또한 배열이나 트리 구조와는 달리 특정 위치의 데이터를 검색해 내는데에는 O(n)의 시간이 걸리는 단점도 갖고 있다. 특히 단일 연결 리스트는 각 노드에 자료 공간과 한 개의 포인터 공간이 있고, 각 노드의 포인터는 다음 노드를 가리킨다.
</p>

<br>

## 특징
- 동적으로 메모리 할당이 가능하다.
- 삭제나 추가가 빠르다.
- 데이터가 빈틈 없이 연속적이다.
- 대용량 데이터 처리에 탁월하다.
- 구현이 어렵다.
- 탐색에 오래 걸린다. (O(N))
- 논리적 순서와 물리적 순서가 동일하지 않다.

<br>

## 구현
- [리스트 생성](#생성)
- [원소 추가](#추가)
- [원소 반환](#반환)
- [원소 제거](#제거)
- [리스트 삭제](#삭제)

<br>

### 생성
```
typedef struct ListNodeType // List에 들어갈 Node
{
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;
```

위와 같이 헤더를 선언하여 List를 생성한다.

<br>

```
/*linked list를 만든다*/
LinkedList* createLinkedList() // Linked list 생성
{
	LinkedList	*pList;

	pList = (LinkedList *)calloc(1, sizeof(LinkedList));
	return (pList);
}
```

<br>

### 추가

```
int addLLElement(LinkedList* pList, int position, ListNode element) // Node 추가
{
	int		i;
	ListNode	*pNode;
	ListNode	*curr;
	ListNode	*prev;
	
	if (!pList || !(position >= 0 && position <= pList->currentElementCount))
		return (FALSE);
	if(position == 0) {
		// Header Node가 없을 때 
		if (pList->currentElementCount == 0) {
			pList->headerNode = element; 			// 인자로 들어온 Node를 할당한다.
			pList->currentElementCount = 1;
			pList->headerNode.pLink = NULL;
		// Header Node가 있을 때 
		} else { 
			curr = malloc(sizeof(ListNode)); 		// 원래 header 의 데이터 복사
			curr->data = pList->headerNode.data;
			curr->pLink = pList->headerNode.pLink;
			element.pLink = curr; 					// 새로 들어온 element를 헤더로 바꾸기 위해 복사한 포인터를 next로 지칭
			pList->headerNode = element; 			// 새로 들어온 element를 헤더로 바꿔준다.
			pList->currentElementCount += 1;
		}
	}
	pNode = &(pList->headerNode);
	i = 0;
	while(pNode && i < position) {
		// 새로 들어올 node를 위해 position 이전의 node의 주소를 저장한다.
		if (i + 1 == position) 
			prev = pNode;
		pNode = pNode->pLink;
		i++;
	}
	// Node 추가
	if (position == i) {
		curr = malloc(sizeof(ListNode)); 			// node 추가를 위한 데이터 복사
		curr->data = element.data;
		curr->pLink = pNode; 						// 원래 위치의 node를 밀어내로
		prev->pLink = curr; 						// 원래 node 전의 node 의 next로 연결한다.
		pList->currentElementCount += 1;
	} else
		return (TRUE);
}
```
생성을 하면서 Header인지 아닌지로 크게 분기한 이후, 들어갈 전의 node와 후의 node 관리에 유의해야 한다.

<br>

### 반환
```
ListNode* getLLElement(LinkedList* pList, int position) // 원하는 위치의 Node를 얻는다.
{
	ListNode *pNode;

	// 위치가 음수인 것과 현재 엘리먼트 갯수보다 큰 위치의 노드는 없다!
    if (!(position >= 0 && position <= pList->currentElementCount))
        return (FALSE);
	pNode = &(pList->headerNode);
	// position 만큼 이동한다.
	while(position--) 
		pNode = pNode->pLink;
    return (pNode);
}
```
position 만큼 반복문을 통해 반환한다. 특성상 탐색에는 O(N)이라는 시간이 걸린다.

<br>

### 제거
```
int removeLLElement(LinkedList* pList, int position) // node를 지운다.
{
	size_t		i;
	ListNode	*pNode;
	ListNode	*prev;
	ListNode	*next;

	// 위치가 음수인 것과 현재 엘리먼트 갯수보다 큰 위치의 노드는 없다!
	if (!(position >= 0 && position < pList->currentElementCount))
		return (FALSE);
	i = 0;
	pNode = &(pList->headerNode);
	// Header Node일 때
	if (position == 0) 
	{
		// Header Node 의 Next가 없을 때
		if (!(pNode->pLink)) 
		{
			pNode->data = 0x00;
			pNode->pLink = NULL;
			pList->currentElementCount -= 1;
		// Header Node 의 Next가 있을 때
		} else {
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
		next = pNode->pLink; 			// 현재 위치 다음 것을
		prev->pLink = next; 			// 현재 위치 전의 것에 연결해준다.
		pNode->data = 0x00;
		pNode->pLink = NULL;
		free(pNode);
		pList->currentElementCount -= 1;
		return (TRUE);
	} else
		return (FALSE);
}
```
마찬가지로 삭제하면서 Header인지 아닌지로 크게 분기한 이후, HeaderNode가 Pointer가 아니기 때문에 next가 있는지를 판별하고, 들어갈 전의 node와 후의 node 관리에 유의해야 한다.

<br>

### 삭제
```
void clearLinkedList(LinkedList* pList) // 내부 Node를 전부 없애준다.
{
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

void deleteLinkedList(LinkedList* pList) // List와 Node를 제거한다.
{
	clearLinkedList(pList);
	free(pList);
    pList = NULL;
}
```
반복문을 돌면서 순차적으로 삭제하는데, 이 때 dangling pointer에 유의하여 주소에 NULL을 넣어준다.

<br>
