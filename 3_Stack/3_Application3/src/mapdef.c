#include "../include/mapdef.h"
#include "../include/linkedstack.h"

// linked stack에 푸시
int pushLSMapPosition(LinkedStack *pStack, MapPosition data){
    StackNode node = {0, };
    node.data = data;

    return pushLS(pStack, node);
}

// 미로 경로 찾기
void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack) {
    int         x, y, direction;
    int         find = FALSE;
    int         maze[HEIGHT][WIDTH] = {0, };
    StackNode   *pNode;
    MapPosition pPosition;

    if (!pStack)
        return ;

    // 입구 위치 push
    pPosition = startPos;
    pPosition.direction = 1;
    pushLSMapPosition(pStack, pPosition);
    maze[x][y] = VISIT;

    while (isLinkedStackEmpty(pStack) == FALSE) {
        pNode = popLS(pStack);
        x = pNode->data.x;
        y = pNode->data.y;
        direction = pNode->data.direction;

        if (x == endPos.x && y == endPos.y) {
            find = TRUE;
        }
        for (int i = 0; i < 4; i++) {
            x = x + DIRECTION_OFFSETS[i][0]; //x
            y = y + DIRECTION_OFFSETS[i][1]; //y
            // 이동가능한 위치인지 확인 
            // 1. 미로를 벗어나지 않아야 한다.
            // 2. 방문한 곳이 아니고 길이어야 한다.
            if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH
                && maze[x][y] == NOT_VISIT) {
                pPosition.x = x;
                pPosition.y = y;
                pPosition.direction = direction + 1;
                pushLSMapPosition(pStack, pPosition);
                maze[x][y] = VISIT;
            }
        }
        free(pNode);
    }
    if (find)
        printf("탐색 성공");
    else 
        printf("탐색 실패");
}

// 경로 표시
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]) {
    StackNode *pNode;
    int x, y;
    int ansArray[HEIGHT][WIDTH] = {0, };

    if (!pStack)
        return ;

    for (x = 0; x < HEIGHT; x++) {
        for (y = 0; y < WIDTH; y++) {
            ansArray[x][y] = mazeArray[x][y];
        }
    }
    while (isLinkedStackEmpty(pStack) == FALSE) {
        pNode = popLS(pStack);
        if (pNode) {
            x = pNode->data.x;
            y = pNode->data.y;
            ansArray[x][y] = VISIT; //방문 표시

            printf("(%d, %d)\n", x, y);
            free(pNode);
        }
    }
    printMaze(ansArray);
}


// 지도 표시
void printMzse(int mazeArray[HEIGHT][WIDTH]) {
    for (int x = 0; x < HEIGHT; x++) {
        for (int y = 0; y < WIDTH; y++) {
            switch (mazeArray[x][y]) {
                // 방문함
                case VISIT:
                    printf("🟩");
                    break;
                // 벽
                case WALL:
                    printf("🟫");
                    break;
                // 방문하지 않음, 길
                case NOT_VISIT:
                    printf("⬜");
            }
        }
        printf("\n");
    }
}