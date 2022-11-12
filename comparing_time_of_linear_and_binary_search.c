#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 100

int n;
// function prototypes
void linearSearch(int arr[], int);
void binarySearch(int arr[], int);
void dataInput(int arr[]);
void bubbleSort(int arr[]);

int main(void)
{
    int arr[MAX_LEN];
    int key;
    float c1, c2, c3, c4;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    dataInput(arr);
    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    c1 = clock();
    linearSearch(arr, key);
    c2 = clock();
    printf("\nThe time taken by linear search is %lf seconds", (c2 - c1) / CLOCKS_PER_SEC);
    bubbleSort(arr);
    printf("\n\nSorted Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    c3 = clock();
    binarySearch(arr, key);
    c4 = clock();
    printf("\nThe time taken by binary search is %lf seconds", (c4 - c3) / CLOCKS_PER_SEC);

    return 0;
}

void linearSearch(int arr[], int key)
{
    for (int i = 0; i <= n; i++)
    {
        if (key == arr[i])
        {
            printf("\nThe key is found at index %d", i);
            return;
        }
    }
    printf("\nThe key is not found");
}

void binarySearch(int arr[], int key)
{
    
    int low = 0;
    int high = n;
    int mid;
    // bubbleSort();
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
        {
            printf("\nThe key is found in binary search");
            return;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("\nThe key is not found in binary search");
}

void dataInput(int arr[])
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
        printf("%d ", arr[i]);
    }
    return;
}

void bubbleSort(int arr[])
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}