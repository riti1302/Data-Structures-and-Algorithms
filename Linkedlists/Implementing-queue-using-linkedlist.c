#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
} *start;


void display()
{
	struct node *p;
	p= start;

	if(p == NULL)
	{
		printf("\nEmpty linkedlist\n");
	}

	else
    {
    	while(p != NULL)
       {
    	printf("%d  ", p->data);
    	p= p->next;
	   }
	}
}


void enqueue()
{
	int x;
	struct node *p= start, *newnode;
	newnode= (struct node *)malloc(sizeof(struct node *));
    
    printf("Enter the element: ");
	scanf("%d", &newnode->data);

    start= newnode;
	newnode->next = p; 
}

int dequeue()
{
   struct node *p= start, *q =start;
   while(p->next != NULL)
   	{
   		q = p;
   		p = p->next;
   	}
   	q->next = NULL;
   	free(p);
}



int main()
{
	int choice;
	printf("Options:\n1- Enqueue\t2- Dequeue\t3- Display\t4- Exit");

	while(1)
	{
	   printf("\nEnter your option:- ");
	   scanf("%d", &choice);

		switch (choice)
	{
		case 1:
		enqueue();
		break;

		case 2:
		{
		 dequeue();
		 break;
		}

		case 3:
		display();
		break;

	   	case 4:
		exit(0);
		break;

	    default:
	    printf("Invalid option");
	    break;
	}
	}

	return 0;
}

