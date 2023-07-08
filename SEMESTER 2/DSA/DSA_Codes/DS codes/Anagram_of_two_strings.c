// Write a program in C to check whether two given strings are an anagram
#include<stdio.h>
#include<string.h>
int main()
{
  int i, j, len1, len2, temp1;
  char a[100], b[100], temp;
  scanf("%s",a);
  scanf("%s",b);
len1 = strlen(a);
len2 = strlen(b);
for(i=0;i<len1;i++)
{
  for(j=0;j<(len1 - 1);j++)
  {
    if(a[j]>a[j+1])
    {
      temp = a[j];
      a[j]= a[j+1];
      a[j+1] = temp;
    }
  }
}
for(i=0;i<len2;i++)
{
  for(j=0;j<(len2-1);j++)
  {
    if (b[j] > b[j+1])
    {
      temp = b[j];
      b[j] = b[j+1];
      b[j+1] = temp;
    }
  }
}
temp1 = strcmp(a,b);
if(temp1 == 0)
{
  printf("anagram");
}
else
{
  printf("not anagram");
}
return 0;  
}