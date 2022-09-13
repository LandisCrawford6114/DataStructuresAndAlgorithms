#include <stdio.h>
#include <stdlib.h>

struct node {
    int reading_date;
    int reading_time;
    int value;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void insert(int reading_date, int reading_time, int value)
{
    //Reserve memory
    struct node *new = (struct node*)malloc(sizeof(struct node));
    
    //Fill data
    new->reading_date = reading_date;
    new->reading_time = reading_time;
    new->value = value;

    //Connect node
    new->next = head;
    head = new;
}

// void insertEnd(int key, int data)
// {
//     //Reserve memory
//     struct node *new = (struct node*)malloc(sizeof(struct node));
    
//     //Fill data
//     new->key = key;
//     new->data = data;

//     //Connect node
//     current = head;
//     while(current->next != NULL)
//     {
//         current = current->next;
//     }
//     current->next = new;
// }

// void insertAt(int key, int data, int location)
// {
//     //Reserve memory
//     struct node *new = (struct node*)malloc(sizeof(struct node));
    
//     //Fill data
//     new->key = key;
//     new->data = data;

//     //Connect node
//     current = head;
//     while(current->next != NULL && current->key != location)
//     {
//         current = current->next;
//     }
//     if(current->key == location)
//     {
//         new->next = current->next;
//         current->next = new;
//     }
//     else
//     {
//         printf("Insertion failed: key not found");
//     }
// }

void delete(int reading_date, int reading_time)
{
    struct node *next = head->next;
    current = head;

    if(current->reading_date==reading_date && current->reading_time==reading_time)
    {
        struct node *old = head;
        head = head->next;
        free(old);
        printf("Entry Deleted\n\n");
    }
    else{
        while(next != NULL && next->reading_date != reading_date && next->reading_time != reading_time)
        {
            current = next;
            next = next->next;
        }
        if(next->reading_date == reading_date && next->reading_time != reading_time)
        {
            struct node *old = next;
            current->next = next->next;
            free(old);
            printf("Entry Deleted\n\n");
        }
        else
        {
            printf("Delete failed: entry not found\n\n");
        }
    }

}

void deleteAll(int value)
{
    struct node *next = head->next;
    current = head;
    while(current->value == value)
    {
        struct node *old = head;
        head = head->next;
        current = head;
        next = head->next;
        free(old);
    }
    while(next != NULL)
    {
        while(next != NULL && next->value == value)
        {
            struct node *old = next;
            current->next = next->next;
            if(next->next != NULL)
            {
                next = next->next;
            }
            free(old);
        }
        current = next;
        next = next->next;
    }
    printf("Entries deleted\n\n");
    
}

void search(int value)
{
    current = head;
    while(current->next != NULL)
    {
        if(current->value == value)
        {
            printf("Node found: %d %d %d\n", current->reading_date,current->reading_time,current->value);
        }
        current = current->next;
    }
    if(current->value == value)
    {
        printf("Node found: %d %d %d\n", current->reading_date,current->reading_time,current->value);
    }
    printf("Search Completed\n\n");
}

void print()
{
    current = head;
    while(current != NULL)
    {
        printf("%d %d %d \n",current->reading_date,current->reading_time,current->value);
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

void average()
{
    current = head;
    int average = 0;
    int length = 0;
    while(current != NULL)
    {
        average += current->value;
        length++;
        current = current->next;
    }
    printf("Average is %d\n\n", average/length);
}

int main()
{
    int input, reading_date, reading_time, value, deleteType, printType;
    while(input != 5)
    {
        printf("1-Insert\n");
        printf("2-Delete\n");
        printf("3-Search\n");
        printf("4-Print\n");
        printf("5-Exit\n");
        printf("Your Choice: ");
        scanf("%d", &input);
        printf("\n");
        if(input == 1)
        {
            // printf("1-Insert at Start\n");
            // printf("2-Insert at End\n");
            // printf("3-Insert at Key\n");
            // printf("Your Choice: ");
            // scanf("%d", &insertType);
            // printf("\n");
            printf("Reading Date: ");
            scanf("%d", &reading_date);
            printf("Reading Time: ");
            scanf("%d", &reading_time);
            printf("Value: ");
            scanf("%d", &value);
            // if(insertType == 1)
            // {
            //     insert(key, data);
            // }
            // else if(insertType == 2)
            // {
            //     insertEnd(key, data);
            // }
            // else if(insertType == 3)
            // {
            //     printf("\nLocation: ");
            //     scanf("%d", &location);
            //     insertAt(key, data, location);
            // }
            insert(reading_date,reading_time,value);
            printf("\n");
        }
        else if(input == 2)
        {
            printf("1-Delete one entry\n");
            printf("2-Delete multiple entries\n");
            printf("Your Choice: ");
            scanf("%d", &deleteType);
            printf("\n");
            if(deleteType == 1)
            {
                printf("Reading Date: ");
                scanf("%d", &reading_date);
                printf("Reading Time: ");
                scanf("%d", &reading_time);
                printf("\n");
                delete(reading_date,reading_time);
            }
            else if(deleteType == 2)
            {
                printf("Value: ");
                scanf("%d", &value);
                printf("\n");
                deleteAll(value);
            }
        }
        else if(input == 3)
        {
            printf("Value: ");
            scanf("%d", &value);
            printf("\n");
            search(value);
        }
        else if(input == 4)
        {
            printf("1-Print List\n");
            printf("2-Print Length\n");
            printf("3-Print Average\n");
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
            else if(printType == 3)
            {
                average();
            }
        }
    }
    return 0;
}

//cc Assignment1.c && ./a.out