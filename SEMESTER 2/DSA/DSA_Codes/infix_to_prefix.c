#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char a)
{
  if(top>=MAX-1)
  {
    printf("stack overflow\n");
    return;
  }
  stack[++top]=a;
}

char pop()
{
  if (top<0)
  {
    printf("stack underflow");
    return 0;
  }
  return stack[top--];
}

int operator(char c)
{
  return(c=='+'|| c=='-'||c=='*'||c=='/');
}

int precedence(char c)
{
  if(c=='+'||c=='-')
  {
    return 1;
  }
  if(c=='*'||c=='/')
  {
    return 2;
  }
  if(c=='^')
  {
    return 3;
  }
  return 0;
}
 
void reverse(char str[])
{
  int i,j;
  char temp;
  int len=strlen(str);
  
  for(i=0,j=len-1;i<j;i++,j--)
  {
    temp=str[i];
    str[i]=str[j];
    str[j]=temp;
  }
}

int main()
{
  char infix[100],prefix[100];
  int i,j=0;
  char ch,temp;
  
  printf("Enter the infix string to be converted \n");
  gets(infix);
  
  reverse(infix);
  
  for(i=0;infix[i]!='\0';i++)
  {
    ch=infix[i];
    
    if(isalnum(ch))
    {
      prefix[j++]=ch;
    }
    else if(ch==')')
    {
      push(ch);
    }
    else if(operator(ch))
    {
      while(top>=0 && precedence(stack[top])>precedence(ch))
      {
        temp=pop();
        prefix[j++]=temp;
      }
      push(ch);
    }
    else if(ch=='(')
    {
      while(top>=0 && stack[top]!=')')
      {
        temp=pop();
        prefix[j++]=temp;
      }
      if(top>=0 && stack[top]==')')
      {
        pop();
      }
      else
      {
        printf("invalid Expression");
      }
    }
  }
  while(top>=0)
  {
    temp=pop();
    prefix[j++]=temp;
  }
  prefix[j]='\0';
  
  reverse(prefix);
  
  printf("The prefix string is %s\n",prefix);
  
  return 0;
}