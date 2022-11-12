#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 100000

int *bubbleSort(int *arr, int);
void display(int *, int);
void swap(int *, int *);
void randomArray(int *, int);


int main()
{
    int arr[MAX];
    int n;
    double start, end;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    // randomArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\tBefore sorting: \n");
    display(arr, n);
    printf("\n");
    printf("\tAfter sorting: \n");
    start = clock();
    bubbleSort(arr, n);
    end = clock();
    display(arr, n);
    printf("\n");
    printf("\t The total time taken by the Bubble Sort is %f seconds for sorting of %d elements\n", (end - start) / CLOCKS_PER_SEC, n);
    return 0;
}

int *bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return arr;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void randomArray(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
}