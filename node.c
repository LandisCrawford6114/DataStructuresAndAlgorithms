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
    printf("\n");
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
    printf("Length: %d \n\n",length);
}

void delete(int key)
{
    struct node *next = head->next;
    current = head;

    if(current->key==key)
    {
        struct node *old = head;
        head = head->next;
        free(old);
        printf("Node Deleted\n\n");
    }
    else{
        while(next != NULL && next->key != key)
        {
            current = next;
            next = next->next;
        }
        if(next->key == key)
        {
            struct node *old = next;
            current->next = next->next;
            free(old);
            printf("Node Deleted\n\n");
        }
        else
        {
            printf("Delete failed: key not found\n\n");
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
        printf("Node found: data=%d\n\n", current->data);
    }
    else
    {
        printf("Search failed: key not found\n\n");
    }
}

int main()
{
    int input, key, data, location, insertType, printType;
    // insert(1, 6);
    // insert(2, 7);
    // insertEnd(3, 8);
    // insertAt(4, 9, 1);
    // delete(2);
    // search(4);
    // length();
    // print();
    while(input != 5)
    {
        printf("1-Insert\n");
        printf("2-Delete\n");
        printf("3-Search\n");
        printf("4-Print\n");
        printf("5-You're done\n");
        printf("Your Choice: ");
        scanf("%d", &input);
        printf("\n");
        if(input == 1)
        {
            printf("1-Insert at Start\n");
            printf("2-Insert at End\n");
            printf("3-Insert at Key\n");
            printf("Your Choice: ");
            scanf("%d", &insertType);
            printf("\n");
            printf("Key: ");
            scanf("%d", &key);
            printf("Data: ");
            scanf("%d", &data);
            if(insertType == 1)
            {
                insert(key, data);
            }
            else if(insertType == 2)
            {
                insertEnd(key, data);
            }
            else if(insertType == 3)
            {
                printf("\nLocation: ");
                scanf("%d", &location);
                insertAt(key, data, location);
            }
            printf("\n");
        }
        else if(input == 2)
        {
            printf("Key: ");
            scanf("%d", &key);
            printf("\n");
            delete(key);
        }
        else if(input == 3)
        {
            printf("Key: ");
            scanf("%d", &key);
            printf("\n");
            search(key);
        }
        else if(input == 4)
        {
            printf("1-Print List\n");
            printf("2-Print Length\n");
            printf("Your Choice: ");
            scanf("%d", &printType);
            printf("\n");
            if(printType == 1)
            {
                print();
            }
            else if(printType == 2)
            {
                length();
            }
        }
    }
    return 0;
}