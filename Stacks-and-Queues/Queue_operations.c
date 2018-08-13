#include<stdio.h>
#include<stdlib.h>
#define max 100
int front = 0, rear = 0;

struct queue
{
	int element[max];
};
struct queue st;

void enqueue(int x)
{
	if(front == max-1)
	{
		printf("Queue is full");
	}
	else
	{
		front++;
		st.element[front] = x;
	}
}
int dequeue()
{
	int x;
	if(rear == front)
	{
		printf("Queue is empty");
	}
	else
	{
		x = st.element[rear];
		rear++;
	}
	return x;
}

void display()
{
	printf("The current status of queue is:-\n");
	for(int i=front; i>rear; i--)
	{
	   printf("%d  ", st.element[i]);
	}
}

int main()
{
	int choice, x;
	printf("\nEnter 1 - Enqueue\nEnter 2 - Dequeue\nEnter 3- Display\nEnter 4 - Exit");
	while(1)
	{
		printf("\nChoice:- ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter the element to be enqueued:- ");
				scanf("%d", &x);
				enqueue(x);
				break;
			}
			case 2:
			{
				dequeue();
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
