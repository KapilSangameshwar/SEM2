// Write a C program to implement circular doubly linked list and perform the following operations

// Insert at beginning
// Insert at end
// Insert after specified node
// delete at beginning
// delete at end
// delete after specified node
// display
// search an element
// Exit
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        newNode->next = *headRef;
    } else {
        struct Node* last = *headRef;
        while (last->next != *headRef) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *headRef;
    }

}

void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        newNode->next = *headRef;
    } else {
        struct Node* last = *headRef;
        while (last->next != *headRef) {
            last = last->next;
        }
        newNode->next = *headRef;
        *headRef = newNode;
        last->next = *headRef;
    }
   
}

void insertAfter() {

   struct Node *prevNode, *newNode,*headRef;
    int x, data;
    scanf("%d",&x);
    scanf("%d",&data);
     struct Node* temp = headRef;


    while (temp->data!= x)
    {

        temp = temp->next;
    }
    prevNode = temp;

    if (prevNode->next == NULL) {
        printf("Previous node cannot be NULL.");
        return;
    }

    newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.");
        return;
    }

    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    if (newNode->next != NULL) {
        
    }

 
}



void deleteAtBeginning(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("empty\n");
        return;
    }
    struct Node* last = *headRef;
    while (last->next != *headRef) {
        last = last->next;
    }
    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    last->next = *headRef;
    printf("%d\n",temp->data);
    free(temp);
}
 
void deleteAtEnd(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("empty\n");
        return;
    }
    struct Node* last = *headRef;
    struct Node* prevNode = NULL;
    while (last->next != *headRef) {
        prevNode = last;
        last = last->next;
    }
    if (prevNode == NULL) {
        *headRef = NULL;
    } else {
        prevNode->next = *headRef;
    }
    printf("%d\n",last->data);
    free(last);
}
void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL) {
       
    return;
}
if (prevNode->next == NULL) {
   
    return;
}
struct Node* temp = prevNode->next;
prevNode->next = temp->next;
printf(" %d \n", temp->data);
free(temp);
}

void display(struct Node* head) {
if (head == NULL) {
printf("empty\n");
return;
}
struct Node* temp = head;

do {
printf("%d ", temp->data);
temp = temp->next;
} while (temp != head);
printf("\n");
}

void search(struct Node* head, int data) {
if (head == NULL) {
printf("empty\n");
return;
}
struct Node* temp = head;
int pos = 1;
do {
if (temp->data == data) {
printf("present at %d \n", pos);
return;
}
temp = temp->next;
pos++;
} while (temp != head);
printf("absent\n");
}

void destroy(struct Node** headRef) {
struct Node* current = *headRef;
struct Node *next;
do {
next = current->next;
free(current);
current = next;
} while (current != *headRef);
*headRef = NULL;
}

int main() {
struct Node* head = NULL,*temp;
int choice, data, position;
while (1) {

scanf("%d", &choice);
switch (choice) {
case 1:

scanf("%d", &data);
insertAtBeginning(&head, data);
break;
case 2:

scanf("%d", &data);
append(&head, data);
break;
case 3:
insertAfter();
break;
case 4:
deleteAtBeginning(&head);
break;
case 5:
deleteAtEnd(&head);
break;
case 6:

scanf("%d", &data);
temp = head;
while (temp != NULL && temp->data != data) {
temp = temp->next;
}
 if (temp == NULL) {
 printf("%d not found in the list\n", data);
} else {
    deleteAfter(temp);
     }
 break;
        case 7:
            display(head);
            break;
        case 8:
            
            scanf("%d", &data);
            search(head, data);
            break;
        case 9:
            destroy(&head);
            
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}
return 0;
}