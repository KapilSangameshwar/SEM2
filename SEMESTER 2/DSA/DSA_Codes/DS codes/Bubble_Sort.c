// C program to implement bubble sort
#include<stdio.h>
int main()
{
int a[10], i, j, n, b, c;
scanf("%d",&n);
for(i=0; i<n; i++)
{
  scanf("%d",&a[i]);
}
for(i = 0; i < n; i++)
{
  for(j = i+1; j < n; j++)
  {
    if (a[j] > a[j + 1])
    {
      int temp = a[j];
      a[j] = a[j + 1];
      a[j + 1] = temp;
    }
  }
}
  for(i = 0; i<n; i++)
  {
    printf("%d ",a[i]);
  }
  return 0;
}