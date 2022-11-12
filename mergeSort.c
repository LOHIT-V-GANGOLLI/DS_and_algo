#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100000

void merge(int arr[], int l, int m, int r, int n);
void mergeSort(int arr[], int l, int r, int n);
void printArray(int arr[], int n);
int *randomArray(int arr[], int n);

int main()
{
    int arr[MAX_SIZE];
    int n;
    double start, end;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    randomArray(arr, n);
    printf("\n\t Before Sorting the array\n");
    printArray(arr, n);
    start = clock();
    mergeSort(arr, 0, n - 1, n);
    end = clock();
    printf("\n\t After Sorting the array\n");
    printArray(arr, n);
    printf("\t The total time taken by the Merge Sort is %f seconds for sorting of %d elements\n", (end - start) / CLOCKS_PER_SEC, n);

    return 0;
}

void merge(int arr[], int l, int m, int r, int n)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[MAX_SIZE], R[MAX_SIZE];
    L[n1], R[n2];

    for (i = 0; i < n; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return;
}

void mergeSort(int arr[], int l, int r, int n)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);
        merge(arr, l, m, r, n);
    }
    return;
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

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}