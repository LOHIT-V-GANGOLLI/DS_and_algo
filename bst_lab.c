#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct bst
{
    char Name_of_the_product[10];
    int ID;
    float cost;
    struct bst *left, *right;
} * NODE;

// function prototyping
NODE getnode();
NODE insertion(NODE, int);
NODE searchTree(NODE, int);
NODE deleteNode(NODE, int);
NODE minValue(NODE);
void inOrderTraversal(NODE);
void preOrderTraversal(NODE);
void postOrderTraversal(NODE);
void productsWithSameCost(NODE);
// NODE ProductWithMaxCost(NODE);
NODE ParentNodeWithGivenID(NODE, int);
int levelNode(NODE);
// void all_ancestors(NODE, int);

int main()
{
    int choice, ID, costkey;
    NODE root = NULL, temp = NULL;
    ;
    while (true)
    {
        printf("\n\n\n**Menu\n\n1. Insert product\n2. Search\n3. Delete\n4. Traversal\n5. Same cost Products\n6. Product with Max cost\n7. Parent Node\n8. Node level\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the ID of the Product: \n");
            scanf("%d", &ID);
            root = insertion(root, ID);
            break;
        case 2:
            printf("Enter the ID of the product\n");
            scanf("%d", &ID);
            temp = searchTree(root, ID);
            if (temp == NULL)
                printf("ID not found\n");
            else if (temp->ID == ID)
                printf("ID found\n");
            break;
        case 3:
            printf("Enter the ID of the product\n");
            scanf("%d", &ID);
            root = deleteNode(root, ID);
            break;
        case 4:
            printf("Enter the traversal type\n");
            printf("1. Inorder\n2. Preorder\n3. Postorder\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                inOrderTraversal(root);
                break;
            case 2:
                preOrderTraversal(root);
                break;
            case 3:
                postOrderTraversal(root);
                break;
            default:
                printf("Invalid choice\n");
            }
            break;
        case 5:
            productsWithSameCost(root);
            break;
        // case 6:
        //     temp = root;
        //     temp = ProductWithMaxCost(root);
        //     if (temp == NULL)
        //         printf("No product with max cost\n");
        //     else
        //         printf("Product with max cost is %s\n", temp->Name_of_the_product);
        //     break;
        case 7:
            printf("Enter the ID of the product\n");
            scanf("%d", &ID);
            temp = ParentNodeWithGivenID(root, ID);
            if (temp == NULL)
                printf("No parent node found\n");
            break;
        case 8:
            printf("Level of the node is %d\n", levelNode(root));
            break;
        

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

NODE getnode()
{
    NODE ptr = (NODE)malloc(sizeof(struct bst));

    printf("Enter the name of the Product: \n");
    scanf("%10s", ptr->Name_of_the_product);
    printf("Enter the cost of the Product: \n");
    scanf("%f", &ptr->cost);
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

NODE insertion(NODE root, int ID) // function to insert the node
{
    if (root == NULL)
    {
        root = getnode();
        root->ID = ID;
        return root;
    }
    else if (ID < root->ID)
    {
        root->left = insertion(root->left, ID);
    }
    else if (ID > root->ID)
    {
        root->right = insertion(root->right, ID);
    }
    else
    {
        printf("ID already exists\n");
    }

    return root;
}

NODE searchTree(NODE root, int key) // function to search the binary search tree
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (key < root->ID)
    {
        return searchTree(root->left, key);
    }
    else if (key > root->ID)
    {
        return searchTree(root->right, key);
    }
    else
    {
        return root;
    }
}

NODE minValue(NODE root) // function to find the minimum value in the binary search tree
{
    NODE current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

NODE deleteNode(NODE root, int key) // function to delete the node
{
    NODE temp;

    if (root == NULL)
    {
        return root;
    }
    else if (key < root->ID)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->ID)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL)
        {
            temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            temp = root;
            root = root->left;
            free(temp);
        }

        else
        {
            temp = minValue(root->right);
            root->ID = temp->ID;
            root->right = deleteNode(root->right, temp->ID);
        }
    }
    return root;
}

void inOrderTraversal(NODE root) // function to print the inorder traversal of the binary search tree
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inOrderTraversal(root->left);
        printf("Product ID = %d\n", root->ID);
        printf("Product Name = %s\n", root->Name_of_the_product);
        printf("Product Cost = %.2f\n", root->cost);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(NODE root) // function to print the preorder traversal of the binary search tree
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("Product ID = %d\n", root->ID);
        printf("Product Name = %s\n", root->Name_of_the_product);
        printf("Product Cost = %.2f\n", root->cost);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(NODE root) // function to print the postorder traversal of the binary search tree
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("Product ID = %d\n", root->ID);
        printf("Product Name = %s\n", root->Name_of_the_product);
        printf("Product Cost = %.2f\n", root->cost);
    }
}

void productsWithSameCost(NODE root) // function to print the products with same cost
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root->left != NULL)
        {
            if (root->left->cost == root->cost)
            {
                printf("Product ID = %d\n", root->left->ID);
                printf("Product Name = %s\n", root->left->Name_of_the_product);
                printf("Product Cost = %.2f\n", root->left->cost);
            }
        }
        if (root->right != NULL)
        {
            if (root->right->cost == root->cost)
            {
                printf("Product ID = %d\n", root->right->ID);
                printf("Product Name = %s\n", root->right->Name_of_the_product);
                printf("Product Cost = %.2f\n", root->right->cost);
            }
        }
        productsWithSameCost(root->left);
        productsWithSameCost(root->right);
    }
}

// NODE ProductWithMaxCost(NODE root) // function to print the product with max cost
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     else
//     {
//         if (root->right != NULL)
//         {
//             if (root->right->cost > root->cost)
//             {
//                 return ProductWithMaxCost(root->right);
//             }
//         }
//         if (root->left != NULL)
//         {
//             if (root->left->cost > root->cost)
//             {
//                 return ProductWithMaxCost(root->left);
//             }
//         }
//         return root;
//     }
//     return root;
// }

NODE ParentNodeWithGivenID(NODE root, int ID) // function to print the parent node of the given ID
{
    NODE curr, parent;
    curr = root;
    int flag = 0;
    if (root->ID == ID)
    {
        flag = 1;
        printf("Root node\n");
    }
    else
    {
        while (curr != NULL)
        {
            if (curr->ID < ID)
            {
                parent = curr;
                curr = curr->right;
            }
            else if (curr->ID > ID)
            {
                parent = curr;
                curr = curr->left;
            }
            else if (curr->ID == ID)
            {
                flag = 1;
                printf("parent of the Product %s is %s\n", curr->Name_of_the_product, parent->Name_of_the_product);
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("Product not found\n");
    }
}

int levelNode(NODE root)
{
    int ID, i = 0, flag;
    NODE curr;
    printf("Enter the ID of the product\n");
    scanf("%d", &ID);
    curr = root;
    while (curr!=NULL)
    {
        i++;
        if (curr->ID == ID)
        {
            flag = 1;
            break;
        }
        else if (curr->ID < ID)
        {
            curr = curr->right;
        }
        else if (curr->ID > ID)
        {
            curr = curr->left;
        }   
        else if (curr->ID == ID)
        {
            flag = 1;
            break;
        }
    }
    return i;
    
}

// void all_ancestors(NODE root, int ID)
// {
//     int a[100], i = 0, flag = 0, j;
//     NODE curr, par;
//     curr = root;
//     if (root == NULL)
//     {
//         printf("the list is empty\n");
//         exit(0);
//     }
//     else
//     {
//         if (root->ID == x)
//         {
//             flag = 1;
//             printf("it is a root node therefore no ancestors exists\n");
//         }
//         else
//         {
//             while (curr != NULL)
//             {

//                 if (curr->ID > ID)
//                 {
//                     par = curr;
//                     curr = curr->left;
//                     a[i] = par->ID;
//                 }
//                 else if (curr->ID < ID)
//                 {
//                     par = curr;
//                     curr = curr->right;
//                     a[i] = par->ID;
//                 }
//                 else if (curr->ID == ID)
//                 {
//                     flag = 1;
//                     break;
//                 }
//                 i++;
//             }
//         }
//         if (flag == 1)
//         {
//             printf("Product ID is valid and the list of ancestors of the node is stated below\n\n");
//             for (j = 0; j < i; j++)
//             {
//                 printf("%d\n", a[j]);
//             }
//         }
//         else if (flag == 0)
//         {
//             printf("Product ID IS INVALID\n");
//         }
//     }
// }