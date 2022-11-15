#include <iostream>

using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int info;
    void inorder(Node* root);
    void preorder(Node* root);
    void postorder(Node* root);
};

Node* insertNode(Node* root, int key){
	// if the root is null, create a new one
	if (root == NULL){
        Node* n = new Node;
        n->left=NULL;
        n->right=NULL;
        n->info=key;
        return n;
    }
    //else, insert the node
	else if (key < root->info){
		root->left = insertNode(root->left, key);
    }
	else{
		root->right = insertNode(root->right, key);
    }
	return root;
}

Node* deleteNode(Node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    else if(key < root->info && root->left != NULL)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->info && root->right != NULL)
    {
        root->right = deleteNode(root->right, key);
    }
    else if(key == root->info)
    {
        if(root->right == NULL && root->left == NULL)
        {
            return NULL;
        }
        else if(root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node* temp = root->left;
            while(temp->right != NULL)
            {
                temp = temp->right;
            }

            root->info = temp->info;

            root->left = deleteNode(root->left,temp->info);
        }
    }
    return root;

}



void inorder(Node* root){
	if (root == NULL)
    {
        return;
    }
	inorder(root->left);
	printf("%d ", root->info);
	inorder(root->right);
}
void preorder(Node* root){
	if (root == NULL)
    {
        return;
    }
	printf("%d ", root->info);
    preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root){
	if (root == NULL)
    {
        return;
    }
    postorder(root->left);
	postorder(root->right);
    printf("%d ", root->info);
}


int main(){
    Node* tree=NULL;

    int numbers [21] = {70,60,92,50,63,82,94,40,68,72,88,98,20,45,65,75,85,96,35,80,78};
    for(int i = 0; i < 21; i++)
    {
        tree=insertNode(tree, numbers[i]);
    }
    while("true")
    {
        printf("1- Insert a new node\n");
        printf("2- Print the tree using inorder traversal\n");
        printf("3- Print the tree using preorder traversal\n");
        printf("4- Print the tree using postorder traversal\n");
        printf("5- Delete a node\n");

        int selection;
        scanf("%d", &selection);
        if(selection == 1)
        {
            int info;
            printf("info? ");
            scanf("%d", &info);
            insertNode(tree, info);
            printf("\n");
        }
        else if(selection == 2)
        {
            inorder(tree);
            printf("\n");
        }
        else if(selection == 3)
        {
            preorder(tree);
            printf("\n");
        }
        else if(selection == 4)
        {
            postorder(tree);
            printf("\n");
        }
        else if(selection == 5)
        {
            int info;
            printf("info? ");
            scanf("%d", &info);
            deleteNode(tree, info);
            printf("\n");
        }
        else if (selection == 6)
        {
            return 0;
        }
    }

}