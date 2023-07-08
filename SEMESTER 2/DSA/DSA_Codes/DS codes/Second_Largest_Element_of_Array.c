// Write a program in C to find the second largest element in an array of size n
#include<stdio.h>
int main()
{
int a, b, n, temp,i,j;
  scanf("%d",&a);
  int c[a];
   
  for(i=0;i<a;i++)
  {
   scanf("%d",&c[i]);
  }
  for(i=0;i<a;i++)
         {
           for(j=0;j<a-1;j++)
           {
             if(c[j] < c[j+1])
             {temp = c[j];
               c[j] = c[j+1];
               c[j+1] = temp;
             }
           }
         }
printf("%d",c[1]);
         return 0;
}
