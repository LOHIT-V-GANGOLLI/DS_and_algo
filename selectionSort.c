#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 10000

int *selectionSort(int *, int);
void swap(int *, int *);
int *randomArray(int *, int);
void displayArr(int *, int);

int main()
{
    int arr[MAX];
    int n;
    double start, end;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    randomArray(arr, n);
    printf("\tBefore sorting the array\n");
    displayArr(arr, n);
    printf("\tAfter sorting the array\n");
    start = clock();
    selectionSort(arr, n);
    end = clock();
    displayArr(arr, n);

    printf("\t The total time taken by the Selection Sort is %f seconds for sorting of %d elements\n", (end - start) / CLOCKS_PER_SEC, n);

    return 0;
}

int *selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // no. of passes
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min]) // linear search
            {
                min = j;
            }
        }
        if (arr[i] != arr[min])
        {
            swap(&arr[i], &arr[min]);
        }
    }
    return arr;
}

int *randomArray(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
    return arr;
}

void displayArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}