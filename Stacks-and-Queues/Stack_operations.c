#include<stdio.h>
#include<stdlib.h>
#define max 100
int top = -1;

struct stack
{
	int element[max];
};
struct stack st;

void push(int x)
{
	if(top== max-1)
	{
		printf("Stack is full");
	}
	else
	{
		top++;
		st.element[top] = x;
	}
}
int pop()
{
	int x;
	if(top== -1)
	{
		printf("Stack is empty");
	}
	else
	{
	    x = st.element[top];
		top--;
	}
	return x;
}

void display()
{
	printf("The current status of stack is:-\n");
	for(int i=top; i>=0; i--)
	{
	   printf("%d\n", st.element[i]);
	}
}

int main()
{
	int choice, x;
	printf("\nEnter 1 - push\nEnter 2 - pop\nEnter 3- display\nEnter 4 - exit");
	while(1)
	{
		printf("\nChoice:- ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter the element to be pushed:- ");
				scanf("%d", &x);
				push(x);
				break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
				{
					display();
					break;
				}
			case 4:
				{
			    	exit(0);
			    	break;
				}

			default:
				printf("\nInvalid option");
				break;
		}
	}
	return 0;
}
