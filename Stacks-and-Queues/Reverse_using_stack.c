#include<stdio.h>
#include<math.h>
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
int main()
{
	int num;
	printf("Enter the number: ");
	scanf("%d", &num);
	
	int sum=0, c=0;
	while(num>0)
	{
		push(num%10);
		num= num/10;
	}
	while(top>-1)
	{
		sum= sum+ (st.element[top]*pow(10,c));
		top--;
		c++;
	}
	printf("Reverse: %d\n", sum);
	return 0;
}

