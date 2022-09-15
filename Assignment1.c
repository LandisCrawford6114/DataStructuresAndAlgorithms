//Landis Crawford Assignment 1
#include <stdio.h>
#include <stdlib.h>

//Create node
struct node {
    int reading_date;
    int reading_time;
    int value;
    struct node *next;
};

//creates head and current nodes
struct node *head = NULL;
struct node *current = NULL;

//insert a node
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

//delete a node with specific date and time
void delete(int reading_date, int reading_time)
{
    //makes sure list isn't empty
    if(head == NULL)
    {
        printf("List already empty\n\n");
        return;
    }

    //creates next node
    struct node *next = head->next;
    current = head;

    //checks head node
    if(current->reading_date==reading_date && current->reading_time==reading_time)
    {
        struct node *old = head;
        head = head->next;
        free(old);
        printf("Entry Deleted\n\n");
    }
    else
    {
        //cycles until it finds the correct node to delete
        while(next != NULL && next->reading_date != reading_date && next->reading_time != reading_time)
        {
            current = next;
            next = next->next;
        }
        //checks to make sure found the correct node and not the end of the list
        if(next->reading_date == reading_date && next->reading_time == reading_time)
        {
            //steps around the node to delete
            struct node *old = next;
            current->next = next->next;
            free(old);
            printf("Entry Deleted\n\n");
        }
        else
        {
            //node to delete doesn't exist
            printf("Delete failed: entry not found\n\n");
        }
    }

}

//delete all nodes with specific value
void deleteAll(int value)
{
    //makes sure list isn't empty
    if(head == NULL)
    {
        printf("List already empty\n\n");
        return;
    }

    //checks to see if head needs deleted and deletes from front of list
    current = head;
    while(current->value == value)
    {
        struct node *old = head;
        head = head->next;
        free(old);
        current = head;
    }

    //cycles through non-head nodes to check if they should be deleted
    while(current != NULL)
    {
        while(current->next != NULL && current->next->value == value)
        {
            //steps around node to delete it
            struct node *old = current->next;
            current->next = current->next->next;
            free(old);
        }
        current = current->next;
    }
    printf("Entries Deleted\n\n");
}

//search for node with specific value
void search(int value)
{
    //cycles through list to find node being searched for
    current = head;
    while(current->next != NULL)
    {
        //prints desired node
        if(current->value == value)
        {
            printf("Node found: %d %d %d\n", current->reading_date,current->reading_time,current->value);
        }
        current = current->next;
    }

    //checks the last node and prints it if applicable
    if(current->value == value)
    {
        printf("Node found: %d %d %d\n", current->reading_date,current->reading_time,current->value);
    }
    printf("Search Completed\n\n");
}

//print all nodes in list
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

//print number of nodes in list
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

//print average value of all nodes
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
    //creates neccessary variables
    int input, reading_date, reading_time, value, deleteType, printType;

    /*Dummy Data:
    insert(1,2,3);
    insert(4,5,6);
    insert(4,5,3);
    insert(7,8,3);
    insert(7,8,9);
    insert(1,0,3);*/

    while(input != 8)
    {
        printf("Welcome to sensory reading system\n");
        printf("1- Add a sensory reading\n");
        printf("2- Remove a sensory reading based on specific date and time\n");
        printf("3- Remove all sensory readings with a specific value\n");
        printf("4- Search for a specific sensory reading value\n");
        printf("5- Print information of all sensory readings\n");
        printf("6- Print the number of sensory readings saved in the system\n");
        printf("7- Print the average of all sensory reading values\n");
        printf("8- Exit\n");
        printf("Your choice: ");
        scanf("%d", &input);

        if(input == 1)
        {
                //Insert
                printf("Reading Date: ");
                scanf("%d", &reading_date);
                printf("Reading Time: ");
                scanf("%d", &reading_time);
                printf("Value: ");
                scanf("%d", &value);
                insert(reading_date,reading_time,value);
                printf("\n");
        }
        else if(input == 2)
        {
            printf("Reading Date: ");
            scanf("%d", &reading_date);
            printf("Reading Time: ");
            scanf("%d", &reading_time);
            printf("\n");
            delete(reading_date,reading_time);
        }
        else if(input == 3)
        {
            printf("Value: ");
            scanf("%d", &value);
            printf("\n");
            deleteAll(value);
        }
        else if(input == 4)
        {
            printf("Value: ");
            scanf("%d", &value);
            printf("\n");
            search(value);
        }
        else if(input == 5)
        {
            print();
        }
        else if(input == 6)
        {
            length();
        }
        else if(input == 7)
        {
            average();
        }
    }
    return 0;
}