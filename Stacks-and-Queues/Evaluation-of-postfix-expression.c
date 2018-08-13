#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100

int top= -1;
float stack[max];
void push(float);
float pop();
float result(char source[]);

int main()
{
   char postfix[max];
   float get_result;

   printf("\tEnter the postfix expression:-  ");
   scanf("%s",postfix);

   get_result= result(postfix);
   printf("\tFinal result:-  %2f\n",get_result);
   return 0;
}

float result(char source[])
{
    int i=0, op1, op2, j;
    while(source[i] != '\0')
    {
        if(isdigit(source[i]))
        {
            push((float)(source[i]-'0'));
        }
        else if(source[i] == '+')
        {
            op2= pop();
            op1= pop();
            push(op1+op2);
        }
        else if(source[i] == '-')
        {
            op2= pop();
            op1= pop();
            push(op1-op2);
        }
        else if(source[i] == '*')
        {
            op2= pop();
            op1= pop();
            push(op1*op2);
        }
        else if(source[i] == '/')
        {
            op2= pop();
            op1= pop();
            push(op1/op2);
        }
        else if(source[i] == '%')
        {
            op2= pop();
            op1= pop();
            push(op1%op2);
        }
        else
        {
            printf("INVALID EXPRESSION");
            exit(1);
        }

        i++;
    }

    return stack[top];
}

void push(float value)
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
float pop()
{
    float value;
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






