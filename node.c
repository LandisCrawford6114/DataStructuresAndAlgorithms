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

void insertEnd(int key, int data)
{
    //Reserve memory
    struct node *new = (struct node*)malloc(sizeof(struct node));
    
    //Fill data
    new->key = key;
    new->data = data;

    //Connect node
    current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = new;
}

void insertAt(int key, int data, int location)
{
    //Reserve memory
    struct node *new = (struct node*)malloc(sizeof(struct node));
    
    //Fill data
    new->key = key;
    new->data = data;

    //Connect node
    current = head;
    while(current->next != NULL && current->key != location)
    {
        current = current->next;
    }
    if(current->key == location)
    {
        new->next = current->next;
        current->next = new;
    }
    else
    {
        printf("Insertion failed: key not found");
    }
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
        printf("Node Deleted\n");
    }
    else{
        while(next != NULL && next->key != key)
        {
            current = next;
            next = next->next;
        }
        if(next->key == key)
        {
            current->next = next->next;
            printf("Node Deleted\n");
        }
        else
        {
            printf("Delete failed: key not found\n");
        }
    }

}

void search(int key)
{
    current = head;
    while(current->next != NULL && current->key != key)
    {
        current = current->next;
    }
    if(current->key == key)
    {
        printf("Node found: data=%d\n", current->data);
    }
    else
    {
        printf("Search failed: key not found\n");
    }
}

int main()
{
    insert(1, 6);
    insert(2, 7);
    insertEnd(3, 8);
    insertAt(4, 9, 1);
    delete(2);
    search(4);
    length();
    print();
    return 0;
}