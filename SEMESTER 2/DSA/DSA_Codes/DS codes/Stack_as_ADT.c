// Write a C program to implement stack (bounded stack) as ADT (PUSH ,POP,PEEK ,STACK FULL and STACK EMPTY operations)
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int top = -1;
int stack[20];
void push();
int pop();
int peek();
bool isEmpty();
bool isFull();
int main()
{
 int operation;
  while(1)
  {
  scanf("%d",&operation);
  switch (operation)
  {
    case 1: push();
      break;
    case 2: pop();
      break;
    case 3: peek();
      break;
    case 4: isFull();
      break;
    case 5: isEmpty();
      break;
    case 6: exit(0);
    default: printf("Please select correct operation");
  }
  }
  return 0;
}

void push()
{
  if (top == 20-1)
  {
    printf("Overflow");
  }
  else
  {
    int x;
    scanf("%d ",&x);
    top+=1;
    stack[top] = x;
  }
}
int pop()
{
  if (top == -1)
  {
    printf("Underflow");
  }
  else {
    isEmpty();
    int x = stack[top];
    printf("%d ",x);
    top-=1;
    return x;
  }
  return -1;
}
int peek()
{
  printf("%d ",stack[top]);
  return stack[top];
}
bool isEmpty()
{
  if(top == -1)
  {
    printf("true ");
    return true;
  }
 
   // printf("false ");
    return false;
  
}
bool isFull()
{
  if (top == 20-1)
  {
    printf("true ");
    return true;
  }
  
    printf("false ");
    return false;
  
}