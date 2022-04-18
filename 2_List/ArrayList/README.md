# 배열 리스트 (Array List)

## 목차
1. [배열 리스트란 ?](#배열-리스트란)
2. [배열 리스트의 특징](#특징)
3. [배열 리스트의 구현](#구현)
    1. [배열 리스트 생성](#생성)
    2. [배열 리스트의 요소 추가](#추가)
    3. [배열 리스트 탐색](#탐색)
    4. [배열 리스트의 요소 삭제](#원소-삭제)
    5. [배열 리스트 삭제](#리스트-삭제)

<br>

## 배열 리스트란 ?

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/3f/Array1.svg/1024px-Array1.svg.png">

<br>

<p>
배열리스트는 자료를 순서대로 저장하는 자료구조로, 논리적 순서(저장)와 물리적 순서(저장)가 동일하다. 원소의 위치 인덱스는 0부터 시작하고, 정적배열로 최대 갯수가 정해져 있고,이는 배열과 동일하다.
C에서는 라이브러리로 배열리스트를 지원하지 않기 때문에, 개발자가 직접 구현해야하는 기능으로는,리스트 생성, 원소 추가(원소 추가 가능 여부 판단), 원소 반환, 원소 제거(리스트 초기화), 리스트 삭제가 있다.
</p>

<br>

## 특징

<p>
저장순서가 순차적이기 때문에 Index가 곧 위치로, 탐색(O(1))에 용이하지만, 배열이 공백을 허용하지 않아 삽입이나 삭제 시에는 노드가 끊기지 않아야 하기 때문에, 삽입이 됐을 떄에는 기존 노드를 뒤로 미루거나, 삭제가 됐을 때에는 원래 노드들을 앞으로 땡기는 등의 작업이 필요하다(O(N)). 또한 정적배열로 저장할 수 있는 최대 갯수가 정해져 있어 이를 넘어가는 저장은 불가하다.
</p>

<br>

## 구현

<br>

### 생성
```
typedef struct ArrayListNodeType // List에 들어갈 Node
{
    int data;
} ArrayListNode;

typedef struct ArrayListType
{
    int maxElementCount;        // 최대 원소 개수
    int currentElementCount;    // 현재 원소의 개수
    ArrayListNode *pElement;    // 원소 저장을 위한 1차원 배열
} ArrayList;
```
위와 같이 헤더를 선언하여, List를 생성한다.

```
ArrayList* createArrayList(int maxElementCount) 
{
    ArrayList *buf;

    if (maxElementCount < 0)
        return (FALSE);
    buf = malloc(sizeof(ArrayList *));
    buf->pElement = malloc(sizeof(int) * maxElementCount);
    buf->maxElementCount = maxElementCount;
    buf->currentElementCount = 0;
    return (buf);
}
```
위의 구조체 선언대로 List를 생성한다.

<br>

### 추가
```
int addALElement(ArrayList* pList, int position, ArrayListNode element) 
{
    int i;

    if (pList->maxElementCount <= position)                     // max 넘겨 node 추가할 때
        return (FALSE);
    if (pList->maxElementCount < pList->currentElementCount)    // 원소 + 1 <= maxCount
        return (FALSE);
    i = pList->currentElementCount + 1;                         // node 추가를 위한 인덱싱
    while(i >= position) {
        pList->pElement[i].data = pList->pElement[i - 1].data;  // 원래 값들을 한 칸 뒤로 이동시킨다.
        i--;
    }
    pList->pElement[position].data = element.data;              // position 에 원하는 값 입력
    pList->currentElementCount += 1;
    return (TRUE);
}
```
위와 같이 원래 Node가 있을 때를 고려하거나, MaxCount보다 넘기는 값인지에 대해 유의해야 한다.
이 때 원래 값들을 뒤로 밀어줘야 하기 때문에 O(N)으로 Linked List와 비교하여 단점을 지닌다.

<br>

### 탐색
```
// 원하는 위치의 주소값 반환
ArrayListNode* getALElement(ArrayList* pList, int position) 
{
    return &(pList->pElement[position]); 
}

// list 꽉 찼는지 여부
int isArrayListFull(ArrayList* pList) 
{
    return (pList->maxElementCount == pList->currentElementCount);
}
```
ArrayList는 특성 상 Index 값을 통해 탐색하기 때문에 O(1) 의 속도를 갖는다.

```
//List length 반환
int getArrayListLength(ArrayList* pList) 
{
    return (pList->currentElementCount);
}
```

<br>

### 원소 삭제
```
// 개별 원소 삭제
int removeALElement(ArrayList* pList, int position) 
{
    int i;

    i = position;
    pList->pElement[position].data = 0;                         // position의 값 지운 후
    while (i <= pList->currentElementCount - 1)
    {
        pList->pElement[i].data = pList->pElement[i + 1].data; // 값들을 앞으로 땡긴다.
        i++;
    }
    pList->pElement[i].data = 0;
    pList->currentElementCount -= 1;
    return (TRUE);
}
```
```
// 전체 원소 삭제
void clearArrayList(ArrayList* pList) 
{
    size_t  i;

    i = 0;
    while (pList->pElement[i].data) {
        pList->pElement[i].data = 0;
        i++;
    }
    pList->currentElementCount = 0;
    free(pList->pElement);
    pList->pElement = NULL;
}
```
개별 원소를 삭제할 때에는 삭제된 뒤의 Node들을 앞으로 땡겨줘야 하기 때문에 O(N)으로 Linked List와 비교하여 단점을 지닌다.

<br>

### 리스트 삭제
```
void deleteArrayList(ArrayList* pList) 
{
    clearArrayList(pList);
    free(pList);
    pList = NULL;
}
```

<br>
