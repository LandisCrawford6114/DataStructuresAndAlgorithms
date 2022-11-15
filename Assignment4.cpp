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

void deleteNode(Node* root, int key)
{
    Node* current = NULL;
    Node* last == NULL;
    if(root->info == key)
    {
        current = root;
    }
    else
    {
        last = root;
        if(key < last->info && last->left != NULL)
        {
            current = last->left;
        }
        else if(key > last->info && last->right != NULL)
        {
            current = last->right;
        }
        else
        {
            printf("node does not exist");
            return;
        }
        while(current->info != key)
        {
            if(key < current->info && current->left != NULL)
            {
                last = current;
                current = current->left;
            }
            else if(key > current->info && current->right != NULL)
            {
                last = current;
                current = current->right;
            }
            else
            {
                printf("node does not exist");
                return;
            }
        }
    }
    
    if(current->left == NULL && current->right == NULL)
    {

    }
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

    tree=insertNode(tree, 5);
    tree=insertNode(tree, 3);
    tree=insertNode(tree, 1);
    tree=insertNode(tree, 7);
    tree=insertNode(tree, 7);


    cout<<"inorder: ";
    inorder(tree);
    cout<<"\npreorder: ";
    preorder(tree);
    cout<<"\npostorder: ";
    postorder(tree);
    cout<<endl;
    return 0;
}