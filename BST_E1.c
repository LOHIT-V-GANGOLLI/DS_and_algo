#include <stdio.h>
#include <stdlib.h>
typedef struct bst
{
    char name[10];
    int ID;
    int sem;
    int cgpa;
    struct bst *left, *right;

} NODE;
NODE *root = NULL, *key;

int level(NODE *root)
{
    int b, i = 0, flag;
    NODE *curr;
    printf("enter the ID of the node\n");
    scanf("%d", &b);
    curr = root;
    while (curr != NULL)
    {
        i++;
        if (curr->ID > b)
        {
            curr = curr->left;
        }
        else if (curr->ID < b)
        {
            curr = curr->right;
        }
        else if (curr->ID == b)
        {
            flag = 1;
            break;
        }
    }
    return (i);
}

void bottom(NODE *root)
{
    if (root != NULL)
    {
        bottom(root->left);
        if (root->left == NULL && root->right == NULL)
        {
            printf("\n\t name---%s\n\t ID----%d\n\t sem----%d\n\t cgpa----%d\n\n", root->name, root->ID, root->sem, root->cgpa);
        }
        bottom(root->right);
    }
}

void view(NODE *root)
{
    NODE *curr;
    if (root == NULL)
    {
        printf("the bst is empty\n\n");
    }
    else
    {
        printf("\t!!TOP VIEW!!\n");
        printf("\n\t name---%s\n\t ID----%d\n\t sem----%d\n\t cgpa----%d\n\n", root->name, root->ID, root->sem, root->cgpa);
        printf("\t!!LEFT SIDE VIEW!!\n");
        curr = root;
        while (curr != NULL)
        {
            printf("\n\t name---%s\n\t ID----%d\n\t sem----%d\n\t cgpa----%d\n\n", curr->name, curr->ID, curr->sem, curr->cgpa);
            curr = curr->left;
        }
        printf("\t!!RIGHT SIDE VIEW!!\n");
        curr = root;
        while (curr != NULL)
        {
            printf("\n\t name---%s\n\t ID----%d\n\t sem----%d\n\t cgpa----%d\n\n", curr->name, curr->ID, curr->sem, curr->cgpa);
            curr = curr->right;
        }
    }
}

void grandparents(NODE *root, int x)
{
    int a[100], i = 0, flag = 0, j;
    NODE *curr, *par;
    curr = root;
    if (root == NULL)
    {
        printf("the list is empty\n");
        exit(0);
    }
    else
    {
        if (root->ID == x)
        {
            flag = 1;
            printf("it is a root node therefore no ancestors exists\n");
        }
        else
        {
            while (curr != NULL)
            {

                if (curr->ID > x)
                {
                    par = curr;
                    curr = curr->left;
                    a[i] = par->ID;
                }
                else if (curr->ID < x)
                {
                    par = curr;
                    curr = curr->right;
                    a[i] = par->ID;
                }
                else if (curr->ID == x)
                {
                    flag = 1;
                    break;
                }
                i++;
            }
        }

        if (flag == 1)
        {
            if (i - 2 >= 0)
            {
                printf("student ID is valid and the ID  of the  grandparent node is stated below\n\n");

                printf("%d\n", a[i - 2]);
            }
            else
            {
                printf("grandparents does not exists\n");
            }
        }
        else if (flag == 0)
        {
            printf("STUDENT ID IS INVALID\n");
        }
    }
}

void all_ancestors(NODE *root, int x)
{
    int a[100], i = 0, flag = 0, j;
    NODE *curr, *par;
    curr = root;
    if (root == NULL)
    {
        printf("the list is empty\n");
        exit(0);
    }
    else
    {
        if (root->ID == x)
        {
            flag = 1;
            printf("it is a root node therefore no ancestors exists\n");
        }
        else
        {
            while (curr != NULL)
            {

                if (curr->ID > x)
                {
                    par = curr;
                    curr = curr->left;
                    a[i] = par->ID;
                }
                else if (curr->ID < x)
                {
                    par = curr;
                    curr = curr->right;
                    a[i] = par->ID;
                }
                else if (curr->ID == x)
                {
                    flag = 1;
                    break;
                }
                i++;
            }
        }
        if (flag == 1)
        {
            printf("student ID is valid and the list of ancestors of the node is stated below\n\n");
            for (j = 0; j < i; j++)
            {
                printf("%d\n", a[j]);
            }
        }
        else if (flag == 0)
        {
            printf("STUDENT ID IS INVALID\n");
        }
    }
}
void adjacent(NODE *root, int x)
{

    NODE *curr, *par;
    curr = root;
    int flag = 0;
    if (root->ID == x)
    {
        flag = 1;
        printf("no adjacent  node as it is a root node\n");
    }
    else
    {
        while (curr != NULL)
        {
            if (curr->ID < x)
            {
                par = curr;
                curr = curr->right;
            }
            else if (curr->ID > x)
            {
                par = curr;
                curr = curr->left;
            }
            else if (curr->ID == x)
            {
                flag = 1;
                if (curr->ID > par->ID)
                {
                    printf("adjacent node of the given node %s is %s\n", curr->name, par->left->name);
                }
                else if (curr->ID < par->ID)
                {
                    printf("adjacent node of the given node %s is %s\n", curr->name, par->right->name);
                }
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("student does not exists in the database\n");
    }
}
void parent_finding(NODE *root, int x)
{
    NODE *curr, *par;
    curr = root;
    int flag = 0;
    if (root->ID == x)
    {
        flag = 1;
        printf("no parents as it is a root node\n");
    }
    else
    {
        while (curr != NULL)
        {
            if (curr->ID < x)
            {
                par = curr;
                curr = curr->right;
            }
            else if (curr->ID > x)
            {
                par = curr;
                curr = curr->left;
            }
            else if (curr->ID == x)
            {
                flag = 1;
                printf("parent of the student %s is %s\n", curr->name, par->name);
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("student does not exists in the database\n");
    }
}

void post(NODE *root)
{

    if (root != NULL)
    {

        post(root->left);
        post(root->right);
        printf("\n\tname---%s\n\tID----%d\n\t sem----%d\n\t cgpa----%d\n", root->name, root->ID, root->sem, root->cgpa);
    }
}

void pre(NODE *root)
{
    if (root != NULL)
    {

        printf("\n\tname---%s\n\tID----%d\n\t sem----%d\n\t cgpa----%d\n", root->name, root->ID, root->sem, root->cgpa);
        pre(root->left);
        pre(root->right);
    }
}
void in(NODE *root)
{
    if (root != NULL)
    {

        in(root->left);
        printf("\n\t name---%s\n\t ID----%d\n\t sem----%d\n\t cgpa----%d\n", root->name, root->ID, root->sem, root->cgpa);
        in(root->right);
    }
}

NODE *create(NODE *key)
{
    NODE *newnode;
    newnode = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}

NODE *insert(NODE *root, NODE *key)
{
    if (root == NULL)
    {
        root = create(key);
    }
    else
    {
        if (root->ID > key->ID)
        {
            root->left = insert(root->left, key);
        }
        else if (root->ID < key->ID)
        {
            root->right = insert(root->right, key);
        }
    }
    return (root);
}

NODE *search(NODE *root, int o)
{
    if (root->ID == o)
    {
        printf("\n\t name---%s\n\t ID----%d\n\t sem----%d\n\t cgpa----%d\n", root->name, root->ID, root->sem, root->cgpa);
    }
    else
    {
        if (root->ID > o)
        {
            root->left = search(root->left, o);
        }
        else if (root->ID < o)
        {
            root->right = search(root->right, o);
        }
    }
    return (root);
}

int main()
{
    int ch, o, x, sem, cgpa;
    while (ch != 14)
    {
        printf("enter 1----to insert element\n");
        printf("enter 2----to search element\n");
        printf("enter 3----to see traversals\n");
        printf("enter 4----to find the parent of the node\n");
        printf("enter 5----to find the adjacent node of the node\n");
        printf("enter 6----to  see the list of all the ancestors of the node\n");
        printf("enter 7----to  see the ID of the grand parent node\n");
        printf("enter 8----to  see all the 4 views of the tree\n");
        printf("enter 9----to  see the level of the NODE\n");
        printf("enter 14----to exit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            key = (NODE *)malloc(sizeof(NODE));
            printf("enter the name of the student\n");
            scanf("%s", key->name);
            printf("enter the id of the student\n");
            scanf("%d", &key->ID);
            printf("enter the sem of the student\n");
            scanf("%d", &key->sem);
            printf("enter the CGPA pf the student\n");
            scanf("%d", &key->cgpa);

            root = insert(root, key);
            break;
        case 2:
        {
            printf("enter the ID of the student to be found\n");
            scanf("%d", &o);
            root = search(root, o);
            break;
        }
        case 3:
            printf("\n\n");
            in(root);
            printf("\n\n");
            pre(root);
            printf("\n\n");
            post(root);

            break;
        case 4:
            printf("enter the ID of the student\n");
            scanf("%d", &x);
            parent_finding(root, x);
            break;
        case 5:
            printf("enter the ID of the student\n");
            scanf("%d", &x);
            adjacent(root, x);
            break;
        case 6:
            printf("enter the ID of the student\n");
            scanf("%d", &x);
            all_ancestors(root, x);
            break;
        case 7:
            printf("enter the ID of the student\n");
            scanf("%d", &x);
            grandparents(root, x);
            break;
        case 8:
            view(root);
            printf("\t!!bottom view !!\n");
            bottom(root);
            break;
        case 9:
            printf("\n\t%d is the level of the node\n", (level(root) - 1));
            break;
        }
    }
}