#include <stdio.h>
#include <stdlib.h>
#include "../include/mapdef.h"
#include "../include/linkedstack.h"

int main(int ac, char *av[]) {
    LinkedStack *pStack = NULL;
    MapPosition startPos, endPos;

    int mazeArray[HEIGHT][WIDTH] = {
        {0,0,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,1},
        {1,1,1,0,1,1,1,1},
        {1,1,1,0,1,1,1,1},
        {1,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,0}
    }

    pStack = createLinkedStack();
    startPos.x = 0;
    startPos.y = 0;
    endPos.x = 7;
    endPos.y = 7;

    printMaze(mazeArray);
    findPath(mazeArray, startPos, endPos, pStack);
    showPath(pStack, mazeArray);
    deleteLinkedStack(pStack);

    return 0;
}