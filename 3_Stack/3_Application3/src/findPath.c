#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define WIDTH 10
#define HIGH 10
char map[HIGH][WIDTH] = {
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
   { –1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
   { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
   { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
   { 1, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
   { 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
   { 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
   { 1, 1, 0, 1, 1, 1, 0, 0, 0, 1 },
   { 1, 1, 2, 1, 1, 1, 0, 1, 1, 1 },
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
void display(){
   int i, j;
   for (i = 0; i < HIGH; ++i){
      for (j = 0; j < WIDTH; ++j){
         switch (map[i][j]){
         case –1:
            printf(“◇”);
            break;
         case 1:
            printf(“■”);
            break;
         case 2:
            printf(“★”);
            break;
         case 0:
            printf(“□”);
         }
      }
      printf(“\n”);
   }
}
typedef struct __POINT
{
   int y;
   int x;
}point;
typedef struct __STACK
{
   struct __STACK * link;
   point point;
}stack;
void init(stack ** p_head){
   *p_head = NULL;
}
void push(stack **p_head, point point){
   stack * temp = (stack*)malloc(sizeof(stack));
   if (!temp)
      exit(1);
   if (*p_head != NULL){
      temp–>point = point;
      temp–>link = *p_head;
   }
   else{
      temp–>point = point;
      temp–>link = NULL;
   }
   *p_head = temp;
}
point pop(stack **p_head){
   if (!p_head)
      exit(1);
   point point_temp = (*p_head)–>point;
   stack * stack_temp = *p_head;
   *p_head = (*p_head)–>link;
   free(stack_temp);
   return point_temp;
}
void show(stack* head){
   for (; head; head = head–>link)
      printf(“(%d %d)\n”, head–>point.x, head–>point.y);
}
bool stackfree(stack **  p_head){
   stack * q = *p_head;
   stack * p =   NULL;
   if (!p_head)
      return false;
   for (; q; p = q, q = q–>link){
      free(p);
   }
   *p_head = NULL;
}
int main(){
   point Location={ 1,0 };
   stack *head;
   init(&head);
   push(&head,Location);
   while (map[Location.y + 1][Location.x]!=2){
      map[Location.y][Location.x] = –1;
      display();
      show(head);
      //UP
      if (map[Location.y + 1][Location.x] != 1 && map[Location.y+1 ][Location.x] !=–1 ){
         Location.y++;
         push(&head, Location);
      }
      //DOWN
      else if (map[Location.y – 1][Location.x] != 1 && map[Location.y–1][Location.x] != –1){
         Location.y––;
         push(&head, Location);
      }
      //LEFT
      else if (map[Location.y][Location.x – 1] != 1 && map[Location.y][Location.x–1] != –1){
         Location.x––;
         push(&head, Location);
      }
      //RIGHT
      else if (map[Location.y][Location.x + 1] != 1 && map[Location.y][Location.x+1] != –1){
         Location.x++;
         push(&head, Location);
      }
      //실패시 
      else{
         Location = pop(&head);
      }
      system(“pause”);
      system(“cls”);
   }
   printf(“목적지 도착”);
   display();
   stackfree(&head);
}
