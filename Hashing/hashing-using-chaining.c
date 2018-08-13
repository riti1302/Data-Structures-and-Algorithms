#include<stdio.h>
#include<stdlib.h>
#define max 50

struct chain
{
    int element;
    struct chain *next; 
};
struct chain table[max];

void create_hashtable(int n, int num)
{
   struct chain *p, *newnode;
   newnode= (struct chain *)malloc(sizeof(struct chain));
   int index;

   index= num % n;
       p= &table[index];

       if(p->element == 0)
       {
           p->element= num;
           p->next= NULL;
       }
       else
       {
           while(p->next != NULL)
            p= p->next;
           p->next= newnode;
           newnode->element= num;
           newnode->next= NULL;
       }
}

void display_hashtable(int n)
{
    struct chain *p;
    int i;
    printf("Hashtable\n");
    for(i=0; i<n; i++)
    {
       p= &table[i];
       while(p != NULL)
       {
           printf("%d   ", p->element);
           p= p->next;
       }
        printf("\n");
    }
}

void  search_element(int num, int n)
{
  struct chain *p;
  int index, flag=0, sub_index=0;

      index= num % n;
      p= &table[index];
      while(p != NULL)
      {
          if(p->element == num)
           {
              flag=1;
              break;
           }
          sub_index++;
          p= p->next;
      }
      if(flag == 1)
        printf("Element found at position %d-%d",index, sub_index);

     else
        printf("Element not found!");

      printf("\n");
}


int main()
{
    int size, number, choice;
    printf("Enter the size of the hash table:- ");
    scanf("%d", &size);

    printf("1- Insert element in hashtable\t2- Display hashtable\t3- search an element\t4- exit");

    while(1)
    {
        printf("\nEnter your choice:- ");
        scanf("%d", &choice);

        if(choice == 1)
            {
                printf("Enter the number:- ");
                scanf("%d", &number);
                create_hashtable(size,number);
            }

        else if(choice == 2)
          display_hashtable(size);


        else if(choice == 3)
        {
            printf("Enter the number you want to search:- ");
            scanf("%d", &number);
            search_element(number,size);
        }

        else if(choice == 4)
            exit(1);


        else
            printf("\nInvalid option");
    }

      return 0;
}
