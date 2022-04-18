#include "arraylist.h"

// ArrayList 생성
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

// ArrayList node 추가
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

// 원소 지운다.
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

void ft_putnbr(int n)
{
    char c;

    if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
    if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
    c = n % 10 + '0';
	write(1, &c, 1);
}

// 모든 원소 출력
void displayArrayList(ArrayList* pList) 
{
    size_t  i;

    if (!pList)
        write(1, "(null)", 6);

    write(1, "maxElementCount is ", 19);
    ft_putnbr(pList->maxElementCount);
    write(1, "\n", 1);
    
    write(1, "currentElementCount is ", 23);
    ft_putnbr(pList->currentElementCount);
    write(1, "\n", 1);
    
    i = 0;
    write(1, "Elements is \n", 13);
    while(pList->pElement[i].data) {
        ft_putnbr(i);
        write(1, " : ", 3);
        ft_putnbr(pList->pElement[i].data);
        write(1, "\n", 1);
        i++;
    }
}

// 원소를 지운다.
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

//List length 반환
int getArrayListLength(ArrayList* pList) 
{
    return (pList->currentElementCount);
}

//모든 원소와 list를 지운다. 
void deleteArrayList(ArrayList* pList) 
{
    clearArrayList(pList);
    free(pList);
    pList = NULL;
}