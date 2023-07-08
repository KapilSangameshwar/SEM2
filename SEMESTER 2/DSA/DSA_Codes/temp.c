#include <stdio.h>
#include <stdlib.h>

int length = 0;

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;

struct node* create_node (int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node)) ; 
    n->data = data;
    n->next = NULL;
    return n; 
}

void display()
{
	struct node* temp;

	if (head == NULL)
    {
      printf("\nList is empty\n");
    }
		
	else {
		temp = head;
		while (temp->next != head) {
			printf("%d->", temp->data);
			temp = temp->next;
		}
	}
}

void insertAtFront()
{
      int data;
    scanf("%d%*c", &data);
    struct node* new_node = node_create(data);
    if (length == 0) 
    {
        head = new_node;
        head->next = new_node;
    }
    else
    {
        struct node* temp = head;
        for (int i = 0; i < length - 1; i++)
        {
             temp = temp->next;
        } 
        temp->next = new_node;
        new_node->next = head;
    }
}

void insertAtEnd () {
    int data;
    scanf("%d%*c", &data);
    struct node* new_node = node_create(data);
    if (length == 0)
    {
        head = new_node;
        new_node->next = head;
    }
    else 
    {
        struct node* temp = head;
        for (int i = 0; i < length - 1; i++)
        {
            temp = temp->next;
        } 
        temp->next = new_node;
        new_node->next = head;
        
    }
}

void insertAfterPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));

	scanf("%d %d", &pos, &data);

	temp = head;
	newnode->data = data;
	newnode->next = head;
	while (i < pos) {
		temp = temp->next;
		i++;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}

void deleteAtFirst()
{
	struct node* temp;
	if (head == NULL)
    {
      printf("\nList is empty\n");
    }
		
	else {
		temp = head;
		head = head->next;
		free(temp);
	}
}

void deleteAtEnd()
{
	struct node *temp, *prevnode;
	if (head == NULL)
    {
      printf("\nList is Empty\n");
    }
		
	else 
    {
		temp = head;
		while (temp->next != head) 
        {
			prevnode = temp;
			temp = temp->next;
		}
		free(temp);
		prevnode->next = head;
	}
}

void deleteAfterPosition()
{
	struct node *temp, *position;
	int i = 1, pos;

	if (head == NULL)
    {
      printf("\nList is empty\n");
    }
		
	else 
    {
		scanf("%d", &pos);
		temp = head;
		while (i < pos)
        {
			temp = temp->next;
			i++;
		}
		position = temp->next;
		temp->next = position->next;
		free(position);
	}
}

int  SearchAnElement()
{
  struct node* temp;
  int value,i=0;
  
  scanf("%d",&value);

	if (head == NULL)
    {
      printf("\nList is empty\n");
    }
		
	else 
    {
		temp = head;
		while (temp != head) 
        {
          if(temp->data==value)
          {
            printf("%d",i);
          }
          i++;
		  temp = temp->next;
		}
	}
}

int main()
{
  int choice;
  while(1)
  {
     scanf("%d", &choice);

		switch (choice) 
        {
		
		case 1:
			insertAtFront();
			break;
		case 2:
			insertAtEnd();
			break;
		case 3:
			insertAfterPosition();
			break;
		case 4:
			deleteAtFirst();
			break;
		case 5:
			deleteAtEnd();
			break;
		case 6:
			deleteAfterPosition();
			break;
		case 7:
            display();
            break;
        case 8:
            SearchAnElement();
            break;
        case 9:
            return 0;
		
		}
  }
  return 0;
}
	
