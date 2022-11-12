#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void floyd(int A[MAX][MAX], int n);
int min(int, int);
void print(int A[MAX][MAX], int);
// int main()
bool main()
{
    int A[MAX][MAX];
    int n;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    floyd(A, n);

    return false;
}

void floyd(int A[MAX][MAX], int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
    print(A, n);
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void print(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d - %d : %d\n", i + 1, j + 1, A[i][j]);
        }
    }
}