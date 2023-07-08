// Write a C program to implement singly linked list and perform the following operations

// Insert at beginning
// Insert at end
// Insert at specified index
// delete at beginning
// delete at end
// delete after specified node
// display
// search an element
// Exit
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int info;
  struct node* next;
};
struct node* head = NULL;

void traverse()
{
  struct node * temp;
  if(head==NULL)
    printf("empty ");
  else
  {
    temp = head;
    while (temp!= NULL)
    {
      printf("%d ",temp->info);
      temp = temp->next;
    }
  }
}
void insertAtFront()
{
  int data;
  struct node* temp;
  temp = malloc(sizeof(struct node));
  scanf("%d ",&data);
  temp -> info = data;
  temp -> next = head;
  head = temp;
}
void insertAtEnd()
{
  int data;
  struct node *temp,*h1;
  temp = malloc(sizeof(struct node));
  
  scanf("%d ", &data);
  
  temp -> next = NULL;
  temp -> info = data;
  h1 = head;
  while(h1->next != NULL)
  {
    h1 = h1->next;
  }
  h1 -> next = temp;
}
void insertAtPosition()
{
  struct node *temp, *newnode;
  int pos, data, i = 1;
  newnode = malloc(sizeof(struct node));
  scanf ("%d %d", &pos, &data);
  temp = head;
  newnode->info = data;
  newnode->next = NULL;
  while(i < pos - 1)
  {
    temp = temp -> next;
    i++;
  }
  newnode->next = temp->next;
  temp->next = newnode;
}
void deleteFirst()
{
  struct node* temp;
  if(head == NULL)
  {
    printf("empty ");
  }
  else
  {
    printf("%d ",head->info);
    temp = head;
    head = head->next;
    free(temp);
  }
}
void deleteEnd()
{
  struct node *temp,*prevnode;
  if (head == NULL)
  {
    printf("empty ");
  }
  else
  {
    temp = head;
    while (temp->next != NULL)
    {
      prevnode = temp;
      temp = temp -> next;
    }
    printf("%d ",temp->info);
    free(temp);
    prevnode->next = NULL;
  }
}
void deletePosition()
{
  int data, count=0;
  scanf("%d ",&data);
  struct node *temp, *position;
  int i = 1, pos;
  temp = head;;
  while(temp->info != data)
  {
    temp = temp ->next;
    count++;
  }
  pos = count;
  if (head == NULL)
  {
    printf("empty ");
  }
  else
  {
    temp = head;
    while (i < pos )
    {
      temp = temp -> next;
      i++;
    }
    position = temp -> next;
    temp -> next = position->next;
    printf("%d ",position->info);
    free(position);
  }
}
void searchAtPosition()
{
  int data, count = 0;
  scanf("%d ",&data);
  struct node *temp;
  temp = head;
  while(temp->next != NULL)
  {
    if(temp -> info == data)
    {
      count++;
    }
    temp = temp->next;
  }
  if(count==0)
  {
    printf("absent");
  }
  else
  {
    printf("Present at %d ",count+3);
  }
}
int main()
{
  int choice;
  while(1)
  {
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        insertAtFront();
        break;
      case 2:
        insertAtEnd();
        break;
      case 3:
        insertAtPosition();
        break;
      case 4:
        deleteFirst();
        break;
      case 5:
        deleteEnd();
        break;
      case 6:
        deletePosition();
        break;
      case 7:
        traverse();
        break;
      case 8:
        searchAtPosition();
        break;
      case 9:
        exit(0);
      default:
        printf("Incorrect choice");
          
    }
  }
  return 0;
}