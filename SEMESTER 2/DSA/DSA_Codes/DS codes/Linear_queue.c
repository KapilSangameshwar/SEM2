// Write a C program to implement Linear queue using array and perform the following operations

// Insert()
// delete()
// display()
// queue full()
// queue empty()
// EXIT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
  int element;
  if (rear == MAX - 1)
  {
    printf("full ");
  }
  else
  {
    if (front == -1)
    {
      front = 0;
    }
    scanf("%d", &element);
    rear ++;
    queue[rear] = element;
  }
}

void delete()
  {
    int element;
    if(front == -1 && rear == -1)
    {
      printf("empty");
    }
    else
    {
      element = queue[front];
      printf("%d ",element);
      front++;
    }
  }
void display()
{
  int i;
  if (front == -1)
  {
    printf("empty ");
  }
  else
  {
    for (i = front; i<= rear; i++)
    {
      printf("%d ",queue[i]);
    }
  }
}
void isFull()
{
  if(rear == MAX - 1)
  {
    printf("full ");
  }
}
void isEmpty()
{
  if (front == -1)
  {
    printf("empty ");
  }
}

int main()
{
  int choice;
  while(1)
  {
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
        insert();
        break;
      case 2:
        delete();
        break;
      case 3:
        display();
        break;
      case 4:
        isFull();
        break;
      case 5:
        isEmpty();
        break;
      case 6:
        exit(0);
      default:
        printf("Invalid Choice");
    }
  }
  return 0;
}
