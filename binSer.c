#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node
{
    int value;
    node *left;
    node *right;
};
//Function to crate a node
node *create_node(int x)
{
    node *n = (node*)malloc(sizeof(node));
    n->value = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}
//Function to insert new node
node *Insert(node*root , int x)
{
    if(root == NULL)
    {
        return create_node(x);

    }
    if(root->value < x)
    {
        root->right = Insert(root->right,x);
    }
    else if(root->value > x)
    {
        root->left = Insert(root->left , x);
    }
    return root;
}

int minRightSub(node *root)
{
    node *temp = root;
    while(temp->left)
    {
        temp = temp->left;
    }
    return temp->value;
}
//Function to delete a node
node *Delete(node *root, int x)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->value < x)
    {
        root->right = Delete(root->right,x);
    }
    else if(root->value > x)
    {
        root->left = Delete(root->left,x);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            node *new_node = root->right;
            free(root);
            return new_node;
        }
        else if(root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            int min_in_right = minRightSub(root->right);
            root->value = min_in_right;
            root->right = Delete(root->right,min_in_right);
        }
    }
    return root;
}

void inorder(node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->value);
    inorder(root->right);
}
void preorder(node* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}
void TRAVEL(node *p)
{
    printf("\nPreorder Travarsal   :");
    preorder(p);
    printf("\nPostorder Travarsal  :");
    postorder(p);
    printf("\nInorder Travarsal    :");
    inorder(p);
}


int main()
{
    node *root = NULL;
    root = Insert(root,10);
    root = Insert(root,12);
    root = Insert(root,5);
    root = Insert(root,4);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,7);
    root = Insert(root,15);
    root = Insert(root,13);

    printf("The unmodified tree is\n");
    TRAVEL(root);
    printf("\n");
    printf("Inserting the value 39 to the tree we get\n");
    root = Insert(root,39);
    TRAVEL(root);
    printf("\n");
    printf("Deleting the node with key value 12 from the tree we get:\n");
    Delete(root,12);
    TRAVEL(root);
    printf("\n");
    return 0;
}