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
    	printf("%d\n", p->data);
    	p= p->next;
	   }
	}
}


void push()
{
	int x;
	struct node *p= start, *newnode;
	newnode= (struct node *)malloc(sizeof(struct node *));
    
    printf("Enter the element: ");
	scanf("%d", &newnode->data);

    start= newnode;
	newnode->next = p; 
}

int pop()
{
   struct node *p= start;

   start= p->next;
   	free(p);
}



int main()
{
	int choice;
	printf("Options:\n1- Push\t2- Pop\t3- Display\t4- Exit");

	while(1)
	{
	   printf("\nEnter your option:- ");
	   scanf("%d", &choice);

		switch (choice)
	{
		case 1:
		push();
		break;

		case 2:
		{
		 pop();
		 break;
		}

		case 3:
		display();
		printf("\n");
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
