#include "../include/mapdef.h"
#include "../include/linkedstack.h"

int pushLSMapPosition(LinkedStac *pStack, MapPosition data){
    StackNode node = {0, };
    node.data = data;

    return pushLS(pStack, node);
}

void findPath

// 지도 표시
void printMzse(int mazeArray[HEIGHT][WIDTH]) {
    for (int x = 0; x < HEIGHT; x++) {
        for (int y = 0; y < WIDTH; y++) {
            if (mazeArray[x])[y] == WALL) {
                print("🟫");
            } else if (mazeArray[x][y] == VISIT) {
                printf("🟩");
            } else {
                printf("⬜");
            }
        }
    }
}