#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree
{
    char data[25];
    struct tree *left;
    struct tree *right;
};

typedef struct tree TREE;
TREE *insert(TREE *root)
{
    int i;
    TREE *newnode;
    newnode=(TREE*)malloc(sizeof(struct tree));
    if(newnode!=NULL)
    {
        printf("newnode created\n");
    }
    newnode->left=NULL;
    newnode->right=NULL;
    printf("Enter newnode data:");
    scanf("%s",newnode->data);
    printf("%s\n",newnode->data);
    if(root==NULL)
    {
        printf("root created\n");
        root=newnode;
        return root;
    }
    TREE *temp,*parent;
    temp=root;
    parent=NULL;

    while(temp != NULL)
    {

        parent=temp;

        if(strcmp(newnode->data,temp->data)<0)
            {

                temp=temp->left;
            }
            else if (strcmp(newnode->data,temp->data)>0)
                  {

                  temp=temp->right;
                  }
    }
    if(strcmp(newnode->data,parent->data)<0)
        {
            parent->left=newnode;
        }
    else{
        parent->right=newnode;
    }

    return root;
}
void inorder(TREE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%s ",root->data);
        inorder(root->right);
    }
}
void preorder(TREE *root)
{
    if(root!=NULL)
    {
        printf("%s ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(TREE *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%s ",root->data);
    }
}
TREE* tree_delete(TREE *root)
{
   TREE *parent,*cur,*succ,*p;
   char data[25];
   if(root==NULL)
   {
       printf("root is null\n");
       return root;
   }
   cur=root;
   parent=NULL;
   printf("Enter the word you want to delete:");
   scanf("%s",data);
   while(cur!=NULL && strcmp(cur->data,data)!=0)
   {
       parent=cur;
       if(strcmp(data,cur->data)<0)
       {
           cur=cur->left;
       }
       else
        cur=cur->right;
   }
   if(cur==NULL)
   {
       printf("data not found\n");
       return root;
   }
   if(cur->left==NULL)
    p=cur->right;
   else if(cur->right==NULL)
    p=cur->right;
   else
    {
        succ=cur->left;
   while(succ!=NULL)
   {
       succ=succ->left;
   }
   succ->left=cur->left;
   p=cur->left;
    }
    if(parent==NULL)
    {
        return p;
    }
    else if(cur==parent->left)

    {
        parent->left=p;
    }
    else{
        parent->right=p;
    }
    free(cur);
    return root;
}

void menu()
{
    printf("1.insert data\n 2.display \n 3.delete data\n 4.to add words in a loop\n5.exit\n");
}
void display(TREE *root)
{
    int choice;
    printf("in which order you want to print data:\n");
    printf("1.inorder\n2.preorder\n 3.postorder\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Inorder traversal :");
            inorder(root);
        break;

        case 2:
            printf("\npreorder traversal : ");
            preorder(root);
        break;

        case 3:
            printf("\npostorder traversal : ");
            postorder(root);
        break;
    }
}
int main()
{
    TREE *root=NULL;
    int k,i=0;
    char n[25];
    menu();
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d",&k);
        switch(k)
        {
            case 1:root=insert(root);
            break;
            case 2:display(root);
            break;
            case 3:tree_delete(root);
            break;
            case 4:printf("Enter the word to be searched\n");
                   scanf("%s",n);

            break;
            case 5: printf("terminating\n");
            exit(1);
            break;
        }
    }
}
