#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 100000

int swapCount1, compCount1 = 0;
int swapCount2, compCount2 = 0;
int swapCount3, compCount3 = 0;
int swapCount4, compCount4 = 0;
int swapCount5, compCount5 = 0;

int *bubbleSort(int *arr, int);
void display(int *, int);
void swap(int *, int *);
void randomArray(int *, int);
void selectionSort(int *, int);
void insertionSort(int *, int);
void merge(int arr[], int l, int m, int r, int n);
void mergeSort(int arr[], int l, int r, int n);
int *partition(int *arr, int low, int high);
int *quickSort(int *arr, int low, int high);

int main()
{
    int arr[MAX];
    long int n;
    n = rand() % 100000000000000;
    char choice;
    double start1, start2, start3, start4, start5, end1, end2, end3, end4, end5;
    // printf("\nEnter the size of the array: ");
    // scanf("%d", &n);
    randomArray(arr, n);
    printf("\nUnsorted array: ");
    display(arr, n);
    start1 = clock();
    swapCount1 = 0;
    bubbleSort(arr, n);
    printf("\nTotal Swaps in Bubble Sort: %d", swapCount1);
    printf("\nTotal Comparisons in Bubble Sort: %d", compCount1);
    end1 = clock();
    start2 = clock();
    swapCount2 = 0;
    selectionSort(arr, n);
    printf("\nTotal Swaps in Selection Sort: %d", swapCount2);
    printf("\nTotal Comparisons in Selection Sort: %d", compCount2);
    end2 = clock();
    start3 = clock();
    swapCount3 = 0;
    insertionSort(arr, n);
    printf("\nTotal Swaps in Insertion Sort: %d", swapCount3);
    printf("\nTotal Comparisons in Insertion Sort: %d", compCount3);
    end3 = clock();
    start4 = clock();
    swapCount4 = 0;
    mergeSort(arr, 0, n - 1, n);
    printf("\nTotal Swaps in Merge Sort: %d", swapCount4);
    printf("\nTotal Comparisons in Merge Sort: %d", compCount4);
    end4 = clock();
    start5 = clock();
    swapCount5 = 0;
    quickSort(arr, 0, n - 1);
    printf("\nTotal Swaps in Quick Sort: %d", swapCount5);
    printf("\nTotal Comparisons in Quick Sort: %d", compCount5);
    end5 = clock();

    printf("\nThe time taken by the bubble sort is: %lf", (end1 - start1) / CLOCKS_PER_SEC);
    printf("\nThe time taken by the selection sort is: %lf", (end2 - start2) / CLOCKS_PER_SEC);
    printf("\nThe time taken by the insertion sort is: %lf", (end3 - start3) / CLOCKS_PER_SEC);
    printf("\nThe time taken by the merge sort is: %lf", (end4 - start4) / CLOCKS_PER_SEC);
    printf("\nThe time taken by the quick sort is: %lf", (end5 - start5) / CLOCKS_PER_SEC);
    printf("\n\n\tNOTE: if time is shown as 0.0, it means you have to take large input size, if random is not generating that much..\n\n");
    printf("\n\tUNCOMMENT LINE 33 and 34 and comment out LINE 30 to take large input\n");
    printf("\nDo you want to see the sorted array? (y/n): ");
    scanf(" %c", &choice);
    switch (choice)
    {
    case 'y':
        display(arr, n);
        break;

    default:
        printf("\n");
        break;
    }
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
                swapCount1++;
            }
            compCount1++;
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

void insertionSort(int arr[], int n) // insertion sort
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            swapCount3++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        compCount3++;
        arr[j + 1] = key;
        swapCount3++;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            compCount2++;
        }
        swap(&arr[min], &arr[i]);
        swapCount2++;
    }
    return;
}

void merge(int arr[], int l, int m, int r, int n)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[MAX], R[MAX];
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
            swapCount4++;
            compCount4++;
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
        compCount4++;
    }
    return;
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
            swap(&arr[i], &arr[j]);
            swapCount5++;
            compCount5++;
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
        compCount5++;
    }
    return arr;
}
