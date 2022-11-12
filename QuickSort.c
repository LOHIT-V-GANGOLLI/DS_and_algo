#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 10000

int *partition(int *arr, int low, int high);
int *quickSort(int *arr, int low, int high);
void printArray(int *arr, int size);
int *randomArray(int arr[], int size);

int main()
{
    int arr[MAX];  // array to be sorted
    int n;
    double start, end;  //
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    randomArray(arr, n);
    printf("\n\t Before sorting the array\n\n");
    printArray(arr, n);
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    printf("\n\t After sorting the array\n\n");
    printArray(arr, n);
    printf("\t The total time taken by the Quick Sort is %f seconds for sorting of %d elements\n", (end - start) / CLOCKS_PER_SEC, n);

    return 0;
}

int *partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int temp;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return arr + (i + 1);
}

int *quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int *pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - arr - 1);
        quickSort(arr, pivot - arr + 1, high);
    }
    return arr;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return;
}

int *randomArray(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % MAX;
    }
    return arr;
}