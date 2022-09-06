#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void insert(int key, int data)
{
    //Reserve memory
    struct node *new = (struct node*)malloc(sizeof(struct node));
    
    //Fill data
    new->key = key;
    new->data = data;

    //Connect node
    new->next = head;
    head = new;
}

void print()
{
    current = head;
    while(current != NULL)
    {
        printf("%d \n",current->data);
        current = current->next;
    }
}

void length()
{
    int length = 0;
    current = head;
    while(current != NULL)
    {
        length++;
        current = current->next;
    }
    printf("Length: %d \n",length);
}

void delete(int key)
{
    struct node *next = head->next;
    current = head;

    if(current->key==key)
    {
        head = head->next;
    }
    else{
        while(next != NULL && next->key != key)
        {
            current = next;
            next = next->next;
        }
        current->next = next->next;
    }

}

int main()
{
    insert(1, 6);
    insert(2, 7);
    insert(3, 8);
    delete(3);
    length();
    print();
    return 0;
}