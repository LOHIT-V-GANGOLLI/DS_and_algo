/*
Name : Athar Mujtaba
Roll : 153
Batch : A2
Course : DSA lab
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// function prototyping
void push(int[], int *, int);
int pop(int[], int *);
void peak(int[], int *);
void display(int[], int *);

// =============colour functions start================
// red
void red()
{
    printf("\033[1;31m");
}
// function for yellow colour
void yellow()
{
    printf("\033[1;33m");
}
// function for reset
void reset()
{
    printf("\033[0m");
}
// green
void green()
{
    printf("\033[1;32m");
}
// cyan
void cyan()
{
    printf("\033[0;36m");
}
// blue
void blue()
{
    printf("\033[1;34m");
}
// purple
void purple()
{
    printf("\033[1;35m");
}
// white
void white()
{
    printf("\033[1;37m");
}
// ====================colour functions end====================

// main function
int main()
{
    int a[MAX], b[MAX], choice, roll, top1 = -1, top2 = -1;
    blue();
    printf("\t\t                    .-:/+++//:.`                \n");
    printf("\t\t               ./syyo+::---::/osys+-            \n");
    printf("\t\t            .ohs/.               `:oho-         \n");
    printf("\t\t          -yh:`         `:`          -yh:       \n");
    printf("\t\t        `sdmd-         `hdd.         `hmdy.     \n");
    printf("\t\t       -do.myd-       `hs od.       `hym:/d/    \n");
    printf("\t\t      -m/ `m:/d-     `hs   od.     `hs`m: -d/   \n");
    printf("\t\t     `d+  .m: +d.   `hy     od.   `hs `m:  -m-  \n");
    printf("\t\t     sh   .m:  +d. `hy       od. `hs  `m:   sh  \n");
    printf("\t\t     m/   .m-   +d-hy         od-hs   `m:   -m. \n");
    printf("\t\t    .m-   .m-    +my           omy    `m:   `m: \n");
    printf("\t\t    .m:   .m-   `hhd.         `hhd.   `m:   `m: \n");
    printf("\t\t     d+   .m-  `hy +d.       `hs od.  `m:   :m. \n");
    printf("\t\t     +d`  .m- `yy   +d.     `hs   od. `m:   yy  \n");
    printf("\t\t     `hs  .m-`yy     od.   `hs     od.`m:  /d.  \n");
    printf("\t\t      .do -m-yy       od. `hs       +d-m: /m-   \n");
    printf("\t\t       `yy:mdy`        od-hs         +dm/od.    \n");
    printf("\t\t         /dmy`          oms           ommo`     \n");
    printf("\t\t          `+ho-                     .+ho.       \n");
    printf("\t\t             :sho:.             `:oyy/`         \n");
    printf("\t\t                ./syyso+++++osyys+-             \n");
    printf("\t\t                    .-:/+++//:.`                \n");
    reset();
    red();
    printf("\t\t\n                \t\tBy Athar Mujtaba Wani \n");
    while (true)
    {

        green();
        printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        reset();
        yellow();

        printf("Enter 1 to push\nEnter 2 for peak\nEnter 3 to display\nEnter 4 to exit\n");
        reset();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            cyan();
            printf("Enter data\n");
            reset();
            scanf("%d", &roll);
            if (top1 == -1)
            {
                push(a, &top1, roll);
                break;
            }
            else
            {
                while (roll < a[top1] && top1 != -1)

                {
                    int x = pop(a, &top1);
                    push(b, &top2, x);
                }
                push(a, &top1, roll);
                while (top2 != -1)
                {
                    int y = pop(b, &top2);
                    push(a, &top1, y);
                }
            }
            break;
        case 2:
            peak(a, &top1);
            break;
        case 3:
            display(a, &top1);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

// funcgtions start
void push(int a[], int *top, int roll)
{
    if (*top == MAX - 1)
    {
        red();
        printf("Stack is full\n");
        reset();
        return;
    }
    else
    {
        *top = *top + 1;
        a[*top] = roll;
    }
}

int pop(int a[], int *top)
{
    if (*top == -1)
    {
        red();
        printf("Stack is empty\n");
        reset();
    }
    else
    {
        int temp;
        temp = a[*top];
        *top = *top - 1;
        return temp;
    }
}

void peak(int a[], int *top)
{
    if (*top == -1)
    {
        red();
        printf("Stack is empty\n");
        reset();
    }
    else
    {
        green();
        printf("The top is %d\n", a[*top]);
        reset();
    }
}

void display(int a[], int *top)
{
    if (*top == -1)
    {
        red();
        printf("Stack is empty\n");
        reset();
    }
    else
    {
        for (int i = *top; i >= 0; i--)
        {
            green();
            printf("\n%d", a[i]);
            reset();
        }
    }
}