//                                           binary search tree using recursion
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;  //self refrential pointer
    struct node *right; // self refrential pointer
} NODE;

NODE *createnode(int data) // dont ask for data in this function
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

NODE *insertion(NODE *node, int data)
{
    if (node == NULL)
    {
        node = createnode(data);
        return node;
    }
    else if (data < (node)->data)
    {
        node->left = insertion(node->left, data);
    }
    else if (data > (node)->data)
    {
        node->right = insertion(node->right, data);
    }
    return node;
}

NODE *traverse(NODE *node)
{
    if (node != NULL)
    {
        traverse(node->left);
        printf("%3d\n", node->data);
        traverse(node->right);
    }
    return node;
}

int countNodes(NODE *node)
{ // counts the number of nodes in a given binary tree
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
}

int maxValue(NODE *node) // max value of the node in a tree
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int max = node->data;
        int left = maxValue(node->left);
        int right = maxValue(node->right);
        if (left > max)
        {
            max = left;
        }
        if (right > max)
        {
            max = right;
        }
        return max;
    }
}

int minValue(NODE *node) // not working
{
    NODE *temp = node;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int countleafnodes(NODE *node)
{
    int child = 0;
    if (node == NULL)
    {
        return 0;
    }
    else if (node->left == NULL && node->right == NULL)
    {
        child++;
    }
    else
    {
        return countleafnodes(node->left) + countleafnodes(node->right);
    }
}

int countparentnodes(NODE *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else if (node->left != NULL || node->right != NULL)
    {
        return 1 + countparentnodes(node->left) + countparentnodes(node->right);
    }
    else
    {
        return 0;
    }
}

NODE *binarySearch(NODE *node, int key)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (key == node->data)
    {
        printf("%d found\n", key);
        return node;
    }
    else if (key < node->data)
    {
        return binarySearch(node->left, key);
    }

    else if (key > (node)->right)
    {
        return binarySearch(node->right, key);
    }
    else
    {
        printf("%d not found\n");
    }
}

int main()
{
    NODE *root = NULL;
    int data, key;
    int choice;
    while (true)
    {
        printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

        printf("\n1.Insertion\n2.Traversal\n3.Node count\n4.Max value of a node\n5.Min Value\n6.Count leaf nodes\n7.Count parent nodes\n8.Search\n9.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted\n");
            scanf("%d", &data);
            root = insertion(root, data);
            break;
        case 2:
            traverse(root);
            break;
        case 3:
            printf("The number of nodes in the given binary tree is %d", countNodes(root));
            break;
        case 4:
            printf("The max value of a node in the given binary tree is %d", maxValue(root));
            break;
        case 5:
            printf("The min value of a node in the given tree is %d", minValue(root));
            break;
        case 6:
            printf("The number of leaf nodes in the given tree are %d", countleafnodes(root));
            break;
        case 7:
            printf("The number of parent nodes in the given binary tree are %d", countparentnodes(root));
            break;
        case 8:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            binarySearch(root, key);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
