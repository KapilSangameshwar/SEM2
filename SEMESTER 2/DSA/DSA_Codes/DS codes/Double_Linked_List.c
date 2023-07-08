// write a C program to implement doubly linked list and perform the following operations

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

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    
}

// Function to insert a node after a specified node
void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
       
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
    
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf(" empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
   
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf(" empty.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
   
}

// Function to delete a node after a specified node
void deleteAfterNode(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("The specified node does not exist.\n");
        return;
    }
    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = prevNode;
    }
    free(temp);
    
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf(" empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for an element in the doubly linked list
void searchElement(struct Node* head, int element) {
    if (head == NULL) {
        printf(" empty.\n");
        return;
    }
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == element) {
            printf(" %d.\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf(" not found .\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, element;

    while (1)
    {
      
     
        // printf("\n-- Doubly Linked List Operations --\n");
        // printf("1. Insert at beginning\n");
        // printf("2. Insert at end\n");
        // printf("3. Insert after specified node\n");
        // printf("4. Delete from beginning\n");
        // printf("5. Delete from end\n");
        // printf("6. Delete after specified node\n");
        // printf("7. Display\n");
        // printf("8. Search an element\n");
        // printf("9. Exit\n");

        // printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
               
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
               
                scanf("%d", &data);
               
                scanf("%d", &element);
                insertAfterNode(head, data);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
               
                scanf("%d", &element);
                deleteAfterNode(head);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
               
                scanf("%d", &element);
                searchElement(head, element);
                break;
            case 9:
                return 0;
                break;
            default:
                printf("Invalid choice.\n");
        }
    
    }

    return 0;
}


