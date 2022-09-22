#include <stdio.h>
#include <stdlib.h>

//Create node
struct node {
    int data;
    int value;
    struct node *next;
};

//creates head and current nodes
struct node *head = NULL;
struct node *current = NULL;
struct node *end = NULL;
int size = 0;
int limit = 0;

//initialize queue
void initialize(int input)
{
    if(limit == 0)
    {
        limit = input;
    }
    else
    {
        printf("Queue already initialized\n");
    }
}

//insert a node
void push(int data, int value)
{
    if(limit == 0)
    {
        printf("Must initialize queue first\n");
        return;
    }
    else if(size == limit)
    {
        printf("Queue already full\n");
        return;
    }
    //Reserve memory
    struct node *new = (struct node*)malloc(sizeof(struct node));
    
    //Fill data
    new->data = data;
    new->value = value;

    //Connect node
    if(head == NULL)
    {
        end = new;
    }
    new->next = head;
    head = new;
    size++;
}

//remove a node
void pop()
{
    if(head == NULL)
    {
        printf("No entries in list\n");
        return;
    }
    current = head;
    if(current->next == NULL)
    {
        head = NULL;
        end = NULL;
        free(current);
        return;
    }
    while(current->next != end)
    {
        current = current->next;
    }
    struct node *tmp = current->next;
    current->next = NULL;
    end = current;
    free(tmp);
    size--;
}

//check if empty
void isEmpty()
{
    if(size == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }
}

//check if full
void isFull()
{
    if(size == limit)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Queue is not full\n");
    }
}

//print front
void front()
{
    if(end == NULL)
    {
        printf("No entries in list\n");
        return;
    }
    printf("Data: %d \nValue: %d\n", end->data, end->value);
}

//print back
void back()
{
    if(head == NULL)
    {
        printf("No entries in list\n");
        return;
    }
    printf("Data: %d \nValue: %d\n", head->data, head->value);
}

int main()
{
    initialize(3);
    isEmpty();
    push(2,3);
    push(1,6);
    isEmpty();
    isFull();
    push(4,7);
    front();
    back();
    isFull();
    pop();
    isFull();
    pop();
    pop();

    return 0;
}