// C program to implement Insertion sort
#include <stdio.h>

void insertionSort(int a[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

int main()
{
  int size;
  scanf("%d", &size);
  int a[size];
  for(int i = 0; i < size; i++)
  {
    scanf("%d", &a[i]);
  }
  
	insertionSort(a, size);
  
	for (int i = 0; i < size; i++)
	{
  		printf("%d ", a[i]);
	}
		

	return 0;
}