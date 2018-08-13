#include<stdio.h>
#include<stdlib.h>
#define max 100

int table[max]={0};

void create_hashtable(int num, int n)
{
   int i=0, index;

    while(1)
    {
       index= ((num % n)+i)% n;

       if(i>= n)
       {
           printf("Hash table is full\n");
           break;
       }
       else if(table[index] == 0)
       {
           table[index]= num;
           break;
       }

       else
        i++;
    }

}

void display_hashtable(int n)
{
    int i;
     printf("\nHash table\n");
    for(i=0; i<n; i++)
        printf("%d ", table[i]);
}

int search_element(int num, int n)
{
    int index, i=0;
    while(i<n)
    {
         index= ((num % n)+i)% n;
         if(table[index] == num)
        {
            printf("Element is found at position %d", index);
            break;
        }
         else
            i++;
    }
    return index;
}

int main()
{
    int size, number, choice;
    printf("Enter the size of the hash table:- ");
    scanf("%d", &size);

    printf("1- Insert element in hashtable\t2-display hash table\t3- search an element\t4- exit");

    while(1)
    {
        printf("\nEnter your choice:- ");
        scanf("%d", &choice);

        if(choice == 1)
            {
                printf("Enter the number:- ");
                scanf("%d", &number);
                create_hashtable(number, size);
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
          printf("Invalid option");

    }

      return 0;
}
