#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_wordlength 20
#define max_words 1000

char table[max_words][max_wordlength]={'\0'};
int get_ASCII(char word[]);
void create_hashtable(int , int, char word[]);
void display_hashtable(int);
void search_word(int, char word[]);


int main()
{
    int size, choice, ASCII=0, i;
    char ch, word[20];
    FILE *fp;

    fp= fopen("Dictionary.txt","r");

    printf("Enter the size of the hash table(greater than 1000):- ");
    scanf("%d", &size);

    printf("1- create hash table\t2-display hash table\t3- exit");

    while(1)
    {
        printf("\nEnter your choice:- ");
        scanf("%d", &choice);

        if(choice == 1)
            {
                if(fp == NULL)
                  {
                     printf("Cannot open file");
                     exit (1);
                  }
                   ch= fgetc(fp);

                  while(ch != '.')
                  {
                     i=0;
                      while(ch!= '\n')
                      {
                         word[i]= ch;
                         ch= fgetc(fp);
                         i++;
                      }
                      word[i]= '\0';
                      ASCII= get_ASCII(word);
                      create_hashtable(ASCII, size, word); 
                      ch= fgetc(fp);
                  }
                printf("Table is created");
            }

        if(choice == 2)
            display_hashtable(size);

        if(choice == 3)
        {
            printf("Enter the word you wanna search:- ");
            getchar();// fflush(stdin)
            scanf("%s", word);
            search_word(size,word);
        }


        if(choice == 4)
            exit(1);
    }
     fclose(fp);
      return 0;
}


void create_hashtable(int num,int n, char word[])
{
   int i=0, index, collision=0;
    while(1)
    {
       index= ((num % n)+collision)% n;

       if(collision>= n)
       {
           printf("Hash table is full");
           break;
       }
       else if(table[index][0] == '\0')
       {
           strcpy(table[index],word);
           break;
       }
       else
        collision++;
    }

}

void display_hashtable(int n)
{
    int i, j;
    printf("\nHash table\n");
    for(i=0; i<n; i++)
    {
        printf("%s\n", table[i]);
    }
}

void search_word(int n, char word[])
{
     int i=0, index, collision=0, flag=0;
      int num= get_ASCII(word);
      while(1)
     {
       index= ((num % n)+collision)% n;

       if(strcmp(table[index], word)== 0)
       {
           flag = 1;
           break;
       }
       else
        collision++;
    }
   if(flag == 1)
       printf("Element found at position %d", index);

    else
        printf("Element not found");
}


int get_ASCII(char word[])
{
    int i, ASCII=0;
    while(word[i] != '\0')
    {
       ASCII += word[i];
       i++;
    }
    return ASCII;
}

