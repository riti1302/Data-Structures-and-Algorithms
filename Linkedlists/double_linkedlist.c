#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
}*start= NULL;

int count()  //length of the list
{
    struct node *p= start;
    int count= 1;
    while(p->next != NULL)
    {
        p= p->next;
        count++;
    }
    return count;
}
void create()
{
    int n, i;
    struct node *newnode, *p;

     p= start;
     newnode= (struct node *)malloc(sizeof(struct node));

     printf("Enter the size of list: ");
     scanf("%d", &n);

     printf("Enter the data:- ");
     scanf("%d", &newnode->data);
    for(i=0; i<n; i++)
    {
        if(p == NULL)
    {
      start= newnode;
      newnode->prev= NULL;
    }
    else
    {
        while(p->next != NULL)
            p=p->next;
        newnode->prev= p;
        p->next= newnode;
    }
    newnode->next= NULL;
    }
    
}

void display()
{
    struct node *p= start;

    if(p == NULL)
    {
        printf("List is empty");
    }
    else
    {
       while(p != NULL)
        {
            printf("%d ", p->data);
            p= p->next;
        }
    }
}

void insert()
{
    int i, pos, c= count();
    struct node *p, *q;
    p= start;
    q=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter the element and position in which you want to insert it:- ");
    scanf("%d %d", &q->data, &pos);

    if(pos == 1) //inserting in the beginning
    {
       start= q;
       q->prev= NULL;
       q->next= p;
    }
    else if(pos<1 || pos>c+1) //inserting outside the scope of linked list
    {
       printf("\nInvalid position");
    }
    else if(pos == c+1) //inserting at the end of the list which is same as creating a new node
    {
        while(p->next != NULL)
            p=p->next;
        q->prev= p;
        p->next= q;
        q->next= NULL;
    }
    else // inserting somewhere in the middle
    {
        for(i=1; i<pos-1; i++)
            p=p->next;
        q->next= p->next;
        p->next= q;
        q->prev= p;
    }
}

void del()
{
    struct node *p= start;
    int i, pos, c= count();

    printf("Enter the position of the element which is to be deleted:- ");
    scanf("%d", &pos);

    if(pos == 1) // deleting the first element of the list
    {
        start= p->next;
        p->next->prev= NULL;
    }
    else if(pos<1 || pos>c) //deleting a position which is out of the scope of the list
    {
        printf("Invalid position");
    }
    else if(pos == c) //deleting the last element
    {
        while(p->next != NULL)
            p= p->next;
        p->prev->next= NULL;
    }
    else //deleting element somewhere in the middle
    {
       for(i=1; i<pos; i++)
         p= p->next;
         p->next->prev= p->prev;
         p->prev->next= p->next;
         free(p);
    }
}

int main()
{
	int choice;
	printf("Options:\n1- Create\t2- Display\t3- Insert\n4- Delete");

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
	    exit(0);

	    default:
	    printf("Invalid option");
	    break;
	}
  }

	return 0;
}

