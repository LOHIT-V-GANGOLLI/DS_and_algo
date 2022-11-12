

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//100 mb = 104,857,600 bytes
#define MAXSIZE 104857600
//Size reserved for MAT table data
#define RESERVED 100000
//Char * is used so that each arithmetic operation is as expected(+1 or -1)
#define POINTER char *

//Remaining size in the heap
int rem = MAXSIZE - RESERVED;
POINTER mem_start;
POINTER mem_block_mem;
POINTER block_mem;
POINTER init;

//User defined Data type for each entry of MAT
struct memory_block
{
    char user_name[25];
    void *start;
    void *end;
    struct memory_block *next;
};
typedef struct memory_block MB;

MB *head = NULL;
MB *last = NULL;

//Allocate each block in the reserved memory
MB *new_block()
{
    MB *n = (MB *)mem_block_mem;
    mem_block_mem += sizeof(MB);
    n->next = NULL;
    return n;
}

//Function to insert a block at the end of MAT
void insert_at_end(MB **n)
{

    if (head == NULL)
    {
        head = *n;
        return;
    }
    MB *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = *n;
    last = *n;
}

//Function to allocate memory in the 100mb
void *my_malloc()
{
    long long size_needed;
    char user_name[25];
    printf("\nSize(in bytes): ");
    scanf("%lld", &size_needed);
    if (size_needed > rem)
    {
        printf("\nInsufficent Memory to perform this operation!");
        printf("\nPerform Free Memory Operation!");
        return NULL;
    }
    printf("Username: ");
    MB *n = new_block();
    scanf("%s", n->user_name);
    POINTER k = block_mem;
    block_mem += size_needed;
    rem -= size_needed;
    n->start = k;
    n->end = block_mem;
    block_mem += 1;
    insert_at_end(&n);
    void *ptr = (void *)k;
    return ptr;
}

//Function to view the MAT
void view_mat()
{
    //Prints the memory information.
    printf("\nMemory Information: \n");
    printf("\nAvailable memory: %.2lf Mb", (double)rem / 1048576);
    printf("\nOccupied memory: %.2lf Mb", (double)((MAXSIZE)-rem - RESERVED) / 1048576);
    printf("\nSystem reserved: %.2lf Mb", (double)RESERVED / 1048576);
    printf("\n\n**** Memory Allocation Table ****");
    if (head == NULL)
    {
        printf("\n*******************************");
        return;
    }
    MB *temp = head;
    while (temp != NULL)
    {
        printf("\n\nUser: %s\nStart: %x\nEnd: %x\nSize: %d bytes", temp->user_name, temp->start, temp->end, (int)(temp->end - temp->start));
        temp = temp->next;
    }
    printf("\n********************************\n");
}

//Function to delete a Memory block in the MAT
void delete_mb(MB **l)
{
    MB *t = *l;
    if (head == t && head->next == NULL)
    {
        head = NULL;
        return;
    }
    if (head == t)
    {
        head = t->next;
        return;
    }
    MB *tempo = head;
    MB *tempo2 = head;
    int flag = 0;
    while (tempo->next != NULL)
    {
        if (tempo == t)
        {

            tempo2->next = tempo->next;
            return;
        }
        tempo = tempo->next;
        if (flag == 1)
        {
            tempo2 = tempo2->next;
        }
        flag = 1;
    }
    if (tempo->next == NULL && tempo == t)
    {
        tempo2->next = NULL;
        return;
    }
}

//Function to change address of each block after deletion
void change_addrs(MB *t, int size)
{
    MB *tempo = t;
    while (tempo != NULL)
    {
        tempo->start -= (size + 1);
        tempo->end -= (size + 1);
        tempo = tempo->next;
    }
}

//Function to free the memory
void my_free()
{
    POINTER start_key;
    POINTER end_key;
    POINTER start_key2;
    POINTER end_key2;
    char key[25];
    int isFound = 0;
    printf("\n\n****** Free Memory *******");
    if (head == NULL)
    {
        printf("\nNo memory allocated to delete!");
        return;
    }
    printf("\nEnter the username: ");
    scanf("%s", key);
    MB *temp = head;
    MB *temp2 = NULL;
    while (temp != NULL)
    {
        if (!strcmp(temp->user_name, key))
        {
            start_key = temp->start;
            end_key = temp->end;
            isFound = 1;
            if (isFound)
            {
                rem += (int)(temp->end - temp->start);
                if (temp != last)
                {
                    temp2 = temp->next;
                    start_key2 = temp2->start;
                    for (int i = 0; i < (int)(temp->end - temp->start); i++)
                    {
                        *start_key = *start_key2;
                        start_key++;
                        start_key2++;
                    }
                    block_mem -= (temp->end - temp->start);
                }
                delete_mb(&temp);
                change_addrs(temp2, (int)(temp->end - temp->start));
            }
        }
        temp = temp->next;
    }
}

//Function to read and write int values in the allocated memory
void values_manip()
{
    printf("\n***** Value Manipulation *****");
    if (head == NULL)
    {
        printf("\nNo memory allocated!");
        return;
    }
    char key[25];
    printf("\nEnter the user name: ");
    scanf("%s", key);
    MB *ptr1 = head;
    int *int_ptr;
    int n, choice;
    int k;
    printf("\nSelect the operation: ");
    printf("\n1. Write");
    printf("\n2. Read");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        while (ptr1 != NULL)
        {
            if (!strcmp(ptr1->user_name, key))
            {
                printf("\nEnter the number of integers you would like to write in %s: ", ptr1->user_name);
                scanf("%d", &n);
                int_ptr = (int *)ptr1->start;
                for (int i = 0; i < n; i++)
                {
                    if ((int *)(int_ptr + i) > (int *)ptr1->end)
                    {
                        printf("\nLimit exceeded user scope.");
                        return;
                    }
                    printf("Enter (%d) integer: ", (i + 1));
                    scanf("%d", &k);
                    *(int_ptr + i) = k;
                }
            }
            ptr1 = ptr1->next;
        }
    }
    else if (choice == 2)
    {
        while (ptr1 != NULL)
        {
            if (!strcmp(ptr1->user_name, key))
            {
                printf("\nEnter the number of integers you would like to read in %s: ", ptr1->user_name);
                scanf("%d", &n);
                int_ptr = (int *)ptr1->start;
                for (int i = 0; i < n; i++)
                {
                    if ((int *)(int_ptr + i) > (int *)ptr1->end)
                    {
                        printf("\nLimit exceeded user scope.");
                        return;
                    }
                    printf("\n(%d) integer: %d", (i + 1), *(int_ptr + i));
                }
            }
            ptr1 = ptr1->next;
        }
    }
}

int main()
{
    //MAXSIZE -> 100Mb
    init = malloc(MAXSIZE);
    if (init == NULL)
    {
        printf("\nInsufficent Memory in the Heap!");
        printf("\nRe run the program!");
        exit(0);
    }
    //The initial memory begins without the reserved memory in 100mb
    mem_start = init + RESERVED;
    mem_block_mem = init;
    block_mem = mem_start;
    int choice;
    void *temp_ptr;
    while (1)
    {
        //Menu and its formatiing
        printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\xB2\xB2\xB2                          \xB2\xB2\xB2\n");
        printf("\xB2\xB2\xB2  1. Get Memory           \xB2\xB2\xB2\n");
        printf("\xB2\xB2\xB2  2. Free Memory          \xB2\xB2\xB2\n");
        printf("\xB2\xB2\xB2  3. View MAT             \xB2\xB2\xB2\n");
        printf("\xB2\xB2\xB2  4. Manipulate Values    \xB2\xB2\xB2\n");
        printf("\xB2\xB2\xB2  5. Exit                 \xB2\xB2\xB2\n");
        printf("\xB2\xB2\xB2  Enter your choice: ");
        scanf("%d", &choice);
        printf("\xB2\xB2\xB2                \n");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        switch (choice)
        {
        case 1:
            temp_ptr = my_malloc();
            break;
        case 2:
            my_free();
            break;
        case 3:
            view_mat();
            break;
        case 4:
            values_manip();
            break;
        default:
            printf("\nProgram Terminated!");
            exit(0);
            break;
        }
    }
    return 0;
}