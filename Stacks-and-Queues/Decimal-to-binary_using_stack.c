#include<stdio.h>
#define max 100
int top= -1;

struct stack
{
	int element[max];
}; 
struct stack st;

void push(int x)
{
	if(top == max-1)
	{
		printf("Stack is full");
	}
	else
	{
		top++;
		st.element[top] = x;
	}
}

int main()
{
	int num;
	printf("Enter the decimal number: ");
	scanf("%d", &num);
	while(num > 0)
	{
	    push(num%2);
		num= num/2;
	}
	printf("Equivalent binary: ");
	while(top>-1)
	{
		printf("%d", st.element[top]);
		top--;
	}
	printf("\n");
	return 0;
}

