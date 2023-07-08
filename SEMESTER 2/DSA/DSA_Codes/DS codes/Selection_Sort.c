// C program to implement Selection sort
#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int a[], int n)
{
	int i, j, min;
	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		if (a[j] < a[min])
			min = j;
		if(min != i)
			swap(&a[min], &a[i]);
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
	selectionSort(a, size);
	for (int i=0; i < size; i++)
    {
      printf("%d ", a[i]);
    }
		
	return 0;
}