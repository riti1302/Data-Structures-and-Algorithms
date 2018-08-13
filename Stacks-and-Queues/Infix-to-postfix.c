#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define max 100

int top = -1;
char stack[max];

void conversion(char source[],char target[]);
void push(char);
char pop();
int priority(char);


int main()
{
    char infix[max], postfix[max];

    printf("\tEnter the expression:-  ");
    scanf("%s",infix);

    strcpy(postfix, "");

    conversion(infix,postfix);
    printf("\n\tResultant postfix expression:-  %s\n", postfix);
    
    return 0;
}

void conversion(char source[], char target[])
{
  int i=0, j=0, temp;
  while(source[i] != '\0')
  {
      if(source[i] == '(')
      {
          push(source[i]);
          i++;
      }
      else if(source[i] == ')')
      {
          while(top != -1 && stack[top] != '(')
          {
              target[j]=pop();
              j++;
          }
          if(top == -1)
          {
              printf("Invalid expression");
              exit(1);
          }
          temp= pop();
          i++;
      }
      else if(isdigit(source[i]) || isalpha(source[i]))
      {
          target[j]= source[i];
          i++;
          j++;
      }
      else if((source[i] == '+') || (source[i] == '-') || (source[i] == '/') || (source[i] == '*') || (source[i] == '%'))
      {
          while(top != -1 && stack[top] != '(' && priority(stack[top]) >= priority(source[i]))
          {
              target[j]= pop();
              j++;
          }
          push(source[i]);
          i++;
      }
      target[j]= '\0';
  }
  while(top != -1)
  {
      target[j]= pop();
      j++;
  }
  target[j]= '\0';
}


void push(char value)
{
	if(top== max-1)
	{
		printf("Stack is full");
	}
	else
	{
		top++;
		stack[top] = value;
	}
}
char pop()
{
    char value;
	if(top== -1)
	{
		printf("Stack is empty");
	}
	else
	{
        value = stack[top];
		top--;
	}
	return value;
}

int priority(char op)
{
    if(op=='%' || op=='/' || op=='*')
        return 1;
    if(op=='+' || op=='-')
        return 0;
}


