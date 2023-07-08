#include <stdio.h>
#include <stdlib.h>


struct node {
	int info;
	struct node* next;
};
struct node* head = NULL;



void traverse()
{
	struct node* temp;

	if (head == NULL)
		printf("\nList is empty\n");
	else {
		temp = head;
		while (temp != NULL) {
			printf("%d->", temp->info);
			temp = temp->next;
		}
	}
}


void insertAtFront()
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = head;
	head = temp;
}

void insertAtEnd()
{
	int data;
	struct node *temp, *h1;
	temp = malloc(sizeof(struct node));

	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);

	temp->next = NULL;
	temp->info = data;
	h1 = head;
	while (h1->next != NULL) {
		h1 = h1->next;
	}
	h1->next = temp;
}

void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));

	printf("\nEnter position and data :");
	scanf("%d %d", &pos, &data);

	temp = head;
	newnode->info = data;
	newnode->next = NULL;
	while (i < pos - 1) {
		temp = temp->next;
		i++;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}

void deleteFirst()
{
	struct node* temp;
	if (head == NULL)
		printf("\nList is empty\n");
	else {
		temp = head;
		head = head->next;
		free(temp);
	}
}

void deleteEnd()
{
	struct node *temp, *prevnode;
	if (head == NULL)
		printf("\nList is Empty\n");
	else {
		temp = head;
		while (temp->next != NULL) {
			prevnode = temp;
			temp = temp->next;
		}
		free(temp);
		prevnode->next = NULL;
	}
}

void deletePosition()
{
	struct node *temp, *position;
	int i = 1, pos;

	if (head == NULL)
		printf("\nList is empty\n");
	else {
		printf("\nEnter index : ");
		scanf("%d", &pos);
		temp = head;
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		position = temp->next;
		temp->next = position->next;
		free(position);
	}
}


int main()
{
	int choice;
	while (1) {

		printf("\n\t1 Traverse\n");
		printf("\t2 insert front\n");
		printf("\t3 insert at end\n");
		printf("\t4 insert at any position\n");
		printf("\t5 delete first\n");
		printf("\t6 delete last\n");
		printf("\t7 Delete from any position\n");
		printf("\t8 exit\n");

		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;
		case 8:
            exit(0);
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}