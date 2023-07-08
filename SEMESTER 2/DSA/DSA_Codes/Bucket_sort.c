// Bucket sort in C

#include <stdio.h>
#include <stdlib.h>

#define size 7
#define Bucket_no 6
#define B_range 10

struct Node {
  int data;
  struct Node *next;
};
// function declaration
void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void printBuckets(struct Node *list);
int getBucketIndex(int value);



int main() {
  int array[size];
  printf("\nEnter %d Elements\n",size);
   for (int i = 0; i < size; i++)
  {
    scanf("%d",&array[i]);
  }

  printf("Initial array: ");
 for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  printf("-------------\n");

  BucketSort(array);
  printf("-------------\n");
  printf("Sorted array: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}



void BucketSort(int arr[]) {
  int i, j;
  struct Node **buckets;

  buckets = (struct Node **)malloc(sizeof(struct Node *) * Bucket_no);

  for (i = 0; i < Bucket_no; ++i) {
    buckets[i] = NULL;
  }

  for (i = 0; i < size; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  for (i = 0; i < Bucket_no; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }

  for (i = 0; i < Bucket_no; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }

  printf("-------------\n");
  printf("Buckets after sorting\n");
  for (i = 0; i < Bucket_no; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }

  for (j = 0, i = 0; i < Bucket_no; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  return;
}

struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

int getBucketIndex(int value) {
  return value / B_range;
}


void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

/*

OUTPUT
Enter 7 Elements
23
17
36
49
51
16
22
Initial array: 23 17 36 49 51 16 22
-------------
Bucket[0]:
Bucket[1]: 16 17
Bucket[2]: 22 23
Bucket[3]: 36
Bucket[4]: 49
Bucket[5]: 51
-------------
Buckets after sorting
Bucket[0]:
Bucket[1]: 16 17
Bucket[2]: 22 23
Bucket[3]: 36
Bucket[4]: 49
Bucket[5]: 51
-------------
Sorted array: 16 17 22 23 36 49 51

Process returned 0 (0x0)   execution time : 28.516 s
Press any key to continue.


*/
