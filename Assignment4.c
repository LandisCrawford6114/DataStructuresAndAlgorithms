#include <stdio.h>
#include <stdlib.h>

//Create node
struct node {
    int info;
    struct node left;
    struct node right;
};

struct node *root = NULL;
struct node *current = NULL;

void insert(int newInfo)
{
    if(root == NULL)
    {
        root->info = newInfo;
    }
    else if()
}

