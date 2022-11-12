#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define null ((void *)0) // to avoid uppercase NULL which is headache i have defined my own null which is in lowercase

typedef struct bst
{
    int data;
    struct bst *left, *right;
} * NODE;


// function prototyping
NODE getnode();
NODE insert(NODE, int);
void searchNode(NODE, int);
NODE delete (NODE, int);
void inOrderTravsersal(NODE);
void preOrderTravsersal(NODE);
void postOrderTravsersal(NODE);



bool flag = false;


// main function
int main()
{
    NODE root;
    root = null;
    return 0;
}

NODE getnode()
{
    NODE ptr = (NODE)malloc(sizeof(struct bst));
    printf("Enter the data for the node\n");
    scanf("%d", &ptr->data);
    ptr->left = null;
    ptr->right = null;

    return ptr;
}
NODE insert(NODE root, int value)
{
    if (root == null)
    {
        return getnode();
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    return root;
}

void searchNode(NODE root, int key)
{

    if (root->data = null)
    {
        printf("Tree is empty\n");
    }
    else
    {
        if (root->data == key)
        {
            printf("%d found\n", key);
            flag = true;
            return;
        }
        if (flag == false && root->left != null)
        {
            searchNode(root->left, key);
        }
        if (flag == false && root->right != null)
        {
            searchNode(root->right, key);
        }
    }
}

void inOrderTravsersal(NODE root)
{
    if (root->data == null)
    {
        return;
    }
    else{
        inOrderTravsersal(root->left);
        printf("%d\n", root->data);
        inOrderTravsersal(root->right);
    }
    
}

void preOrderTravsersal(NODE root)
{
    if (root->data == null)
    {
        return;
    }
    else{
        printf("%d\n", root->data);
        inOrderTravsersal(root->left);
        inOrderTravsersal(root->right);
    }
    
}

void postOrderTravsersal(NODE root)
{
    if (root->data == null)
    {
        return;
    }
    else{
        inOrderTravsersal(root->left);
        inOrderTravsersal(root->right);
        printf("%d\n", root->data);
    }
    
}