#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 10000

int *insertionSort(int *, int);
void swap(int *, int *);
int *randomArray(int *, int);
void displayArr(int *, int);

int main()
{
    int arr[MAX];
    double start, end;

    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    randomArray(arr, n);
    printf("\tBefore sorting the array\n");
    displayArr(arr, n);
    printf("\n\tAfter sorting the array\n\n");
    start = clock();
    insertionSort(arr, n);
    end = clock();
    displayArr(arr, n);
    printf("\t The total time taken by the Insertion Sort in %f seconds for  %d elements\n", (end- start)/CLOCKS_PER_SEC, n);
    return 0;
}

int *insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int hole = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > hole)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = hole;
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
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}