#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int n;
void bubblesort(int *arr);

int main()
{
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * 10);
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
    }
    bubblesort(arr);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

void bubblesort(int *arr)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-1; j++)
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