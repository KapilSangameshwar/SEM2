// Write a program in C to find the missing number in a given array of size n
#include<stdio.h>
  int main()
  {
    int a , b , i , j , n;
    scanf("%d",&n);
    int sum = (n+1)*(n+2)/2;
    int sum1 = 0;
    for(i=0;i<n;i++)
    {
      int temp;
      scanf("%d",&temp);
      sum1 += temp;
    }
    printf("%d",sum - sum1);

    return 0;
  }