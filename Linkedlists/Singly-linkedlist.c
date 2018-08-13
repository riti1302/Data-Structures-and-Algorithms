#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
} *start;

void create()
{
	int n, i;
	struct node *newnode, *p;
    
    printf("Enter the size of list: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
    	newnode= (struct node*)malloc(sizeof(struct node));
	    printf("Enter the data:- ");
	    scanf("%d", &newnode->data);

	   if(start == NULL)
	   {
		  start= newnode;
	   }
	  else
	  {
		p = start;
		while(p->next != NULL)
		p= p->next;
		p->next= newnode;
	  }
		newnode->next= NULL;
    }
	
}

void display()
{
	struct node *p;
	p= start;

	if(p== NULL)
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

int list_length()
{
	int n=1;
	struct node* p= start;
	while(p->next != NULL)
	{
		n++;
		p= p->next;
	}
	return n;
}

void insert()
{
	int x, pos;
	struct node *p= start, *newnode;
	newnode= (struct node *)malloc(sizeof(struct node *));

	printf("Enter the integer to be inserted: ");
	scanf("%d", &newnode->data);
	printf("Enter the position:  ");
	scanf("%d", &pos);

	if(pos == 1)
	{
	   start= newnode;
	   newnode->next = p; 
	}

    else
    {
       for(int i=1; i<pos-1; i++)
	      p= p->next;
	   newnode->next= p->next;
	   p->next= newnode;	
    }
	
}

void del()
{
   int pos, i, n;
   struct node *p= start, *q =start;
   n= list_length();

   printf("Enter the position of the element to be deleted:- ");
   scanf("%d", &pos);

   if(pos == 1)
   {
   	 start= p->next;
   	 free(p);
   }

   else if(pos == n)
   {
   	while(p->next != NULL)
   	{
   		q = p;
   		p = p->next;
   	}
   	q->next = NULL;
   	free(p);
   }

  else
  {

   for(i=1; i<pos-1; i++)
     p= p->next;
   	 p->next = p->next->next;
   	 free(p->next);
  }
}


void search()
{
	struct node *p= start;
	int x, flag=0, pos= 0;
	printf("Enter the integer to be searched:- ");
	scanf("%d", &x);

	while(p != NULL)
	{
		pos++;
	if(p->data == x)
	{
		flag=1;
	}
	p= p->next;
	if(flag==1)
	break;
	}
	if(flag==1)
	{
		printf("Element found at position %d", pos);
	}
	else
	{
		printf("Element not found");
	}

}


void mid_value()
{
	struct node *p, *q;
	p= start;
	q=start;
	while((p != NULL) && (p->next != NULL))
	{
	   p= p->next->next;
	   q= q->next;
	}
	printf("Mid node is:- %d", q->data);
}

void reverse()
{
	struct node *current, *prev, *next;
	current= start;
	prev= NULL;
	while(current != NULL)
	{
		next= current->next;
		current->next= prev;
		prev= current;
		current= next;
	}
	start= prev;
}

void selectionsort()
{
	struct node *p, *q;
	int temp;
	for(p= start; p->next != NULL; p= p->next)
	{
		for(q= p->next; q != NULL; q= q->next)
		{
			if(p->data > q->data)
			{
				temp= p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}
int main()
{
	int choice;
	printf("Options:\n1- Create\t2- Display\t3- Insert\n4- Delete\t5- Search\t6- Mid value\n7- Reverse\t8- Sort\t9- Exit");

	while(1)
	{
	   printf("\nEnter your option:- ");
	   scanf("%d", &choice);

		switch (choice)
	{
		case 1:
		create();
		break;

		case 2:
		{
		display();
		printf("\n");
		break;
		}

		case 3:
		insert();
		break;

	   	case 4:
		del();
		break;

		case 5:
		search();
		break;

		case 6:
		mid_value();
		break;

		case 7:
		reverse();
		break;

		case 8:
		selectionsort();
		break;

		case 9:
	    exit(0);

	    default:
	    printf("Invalid option");
	    break;
	}
	}

	return 0;
}

