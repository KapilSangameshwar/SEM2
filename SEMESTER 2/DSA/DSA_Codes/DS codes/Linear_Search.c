// C program to implement Linear search
#include<stdio.h>
int i, j, n, a[10],b,c = 0;

int main()
{
  scanf("%d",&n);
  for(i=0; i<n; i++)
  {
    scanf("%d",&a[i]);
  }
  scanf("%d",&b);
  for(i=0; i<n; i++)
  {
    j = a[i];
    if(j == b)
    {
      c = i;
        if (c != 0)
        {
           printf("present at %d position\n",c+1);
        }
 
      j = 0;
      
    }
  }

if(c == 0)
  {
    printf("absent");
  }
  return 0;
}
