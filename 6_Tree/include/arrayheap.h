#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct ArrayHeapNodeType
{
    int key;
    char data;
} ArrayHeapNode;

typedef struct ArrayHeapType
{
    int maxElementCount;        // 최대 원소 개수
    int currentElementCount;    // 현재 원소의 개수
    ArrayHeapNode *pElement;    // 노드 저장을 위한 1차원 배열 포인터
} ArrayMaxHeap;

// 생성
ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);
// 노드 추가
int insertArrayMaxHeapAH(ArrayMaxHeap* pHeap, ArrayHeapNode element);
// 노드 제거
ArrayHeapNode* deleteArrayMaxHeapAH(ArrayMaxHeap* pHeap);
// 삭제
void deleteArrayMaxHeap(ArrayMaxHeap* pHeap);

#endif // _ARRAY_HEAP_

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif // _COMMON_TREE_DEF_