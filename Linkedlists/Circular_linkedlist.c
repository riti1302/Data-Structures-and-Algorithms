#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
}*start = NULL;


int size;

void createList(){
    struct node* p = start;
    printf("Enter Data :\n");
    int data, i;
    for (i = 0;i < size;i++){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &data);
        newNode->data = data;
        if (start == NULL){
            start = newNode;
            p = start;
        }
        else{
            p->next = newNode;
            p = p->next;
        }
        newNode->next = start;
    }
}

void displayList(){
    int i = size;
    struct node* p = start;
    while(i--){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insertNodeAt(int index)
{
    if (index < 0 || index > size - 1)
    {
        printf("Invalid Index!\n");
        return;
    }
    int data;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newNode->data = data;
    struct node* p = start;
    
    if (index == 0)
    {
        while(p->next != start){
            p = p->next;
        }
        p->next = newNode;
        newNode->next = start;
        start = newNode;
    }

    else
    {
        int i = index - 1;
        while(i--)
        {
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    size ++;
}

void deleteNodeAt(int index){
    if (index < 0 || index > size - 1){
        printf("Invalid Index!\n");
        return;
    }
    struct node* toDelete = NULL, *p = start;
    int i = index - 1;

    if (i == -1){
        while(p->next != start){
            p = p->next;
        }
        toDelete = start;
        p->next = p->next->next;
        start = p->next;
        free(toDelete);
    }
    else{
        while(i--){
            p = p->next;
        }
        toDelete = p->next;
        p->next = p->next->next;
        free(toDelete);
    }
    size --;
}

int main(void){
    printf("Size: ");
    scanf("%d", &size);
    createList();
    int choice = 0, index;
    while(1)
        {
            printf("\n\n1. Display List\t 2. Insert Node\t 3. Delete Node\t 4. Quit");
        printf("\nChoice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                displayList();
                break;
            }
            case 2:
            {
                printf("Insert Node At (INDEX): ");
                scanf("%d", &index);
                insertNodeAt(index);
                break;
            }
            case 3:{
                printf("Delete Node At (INDEX): ");
                scanf("%d", &index);
                deleteNodeAt(index);
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("Invalid Choice!\n");
            }
        }

    }
    return 0;
}
