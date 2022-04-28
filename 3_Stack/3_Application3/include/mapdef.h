#ifndef _MAP_DEF_
#define _MAP_DEF_

#include "linkedstack.h"

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},			// 위로 이동
	{1, 0},				// 오른쪽으로 이동
	{0, 1},				// 아래로 이당
	{-1, 0}				// 왼쪽으로 이동
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };

typedef struct MapPositionType
{
	int x;				// 현재 위치 x 좌표
	int y;				// 현재 위치 y 좌표
	int direction;		// ekdma dnlclfh dlehd
} MapPosition;

enum PosStatus {
	NOT_VISTIT = 0
	WALL = 1
	VISIT = -1
};

void    findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);		// 미로의 경로를 찾는 함수
int     pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void    showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]); 												// 찾은 경로를 화면에 표시
void    printMaze(int mazeArray[HEIGHT][WIDTH]);																	// 지도를 화면에 표시


#endif