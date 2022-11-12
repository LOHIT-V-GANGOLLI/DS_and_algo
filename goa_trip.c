#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INFINITY INT_MAX

typedef struct priority_queue
{
    int distance;
    int node;
} pq;
typedef struct places
{
    char arr[100];
} places;
pq front(pq p[], int n)
{
    pq temp;
    temp.distance = INFINITY;
    for (int i = 0; i < n; i++)
    {
        if (p[i].distance < temp.distance && p[i].distance != -1)
        {
            temp = p[i];
        }
    }
    return temp;
}
void haspath(int **arr, int src, int dest, int weight, int included[], places p[])
{
    if (weight < 0)
        return;
    if (weight == 0 && src == dest)
    {
        for (int i = 0; i < 14; i++)
        {
            if (included[i] == 1)
                printf("%s --> ", p[i].arr);
        }
        printf("Goa\n");
        included[src] = 0;
        return;
    }
    else
    {
        if (included[src] == 0)
        {
            included[src] = 1;
            for (int i = 0; i < 14; i++)
            {
                if (arr[src][i] != 0 && arr[src][i] <= weight && included[i] == 0)
                {
                    haspath(arr, i, dest, weight - arr[src][i], included, p);
                }
            }
            included[src] = 0;
        }
    }
}
void dequeue(pq p[], int n)
{
    pq temp = front(p, n);
    for (int i = 0; i < n; i++)
    {
        if (temp.distance == p[i].distance && temp.node == p[i].node)
        {
            p[i].distance = -1;
            p[i].node = -1;
        }
    }
}
int isEmpty(pq p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].node != -1)
            return 0;
    }
    return 1;
}
int dijkstra(int **arr, int n, int dist[], int source, int destination)
{
    pq p[100];
    for (int i = 0; i < 100; i++)
    {
        p[i].node = -1;
        p[i].distance = -1;
    }
    int l = 0;
    dist[source] = 0;
    p[l].distance = 0;
    p[l].node = source;
    while (!isEmpty(p, l + 1))
    {
        pq t = front(p, l + 1);
        int node = t.node;
        int d = t.distance;
        dequeue(p, l + 1);
        for (int i = 0; i < n; i++)
        {
            int curr_dist = d;
            if (arr[node][i] != 0)
            {
                int next_distance = curr_dist + arr[node][i];
                if (next_distance < dist[i])
                {
                    dist[i] = next_distance;
                    l = l + 1;
                    p[l].distance = next_distance;
                    p[l].node = i;
                }
            }
        }
    }
    int temp = dist[destination];
    for (int i = 0; i < 14; i++)
        dist[i] = INFINITY;
    return temp;
}
int main()
{
    places p[] = {"Hubli\0",
                  "Dharwad\0",
                  "Mugad\0",
                  "Alanvar\0",
                  "Belur\0",
                  "Tegur\0",
                  "Kittur\0",
                  "Bidi\0",
                  "Nanagad\0",
                  "Rangarook\0",
                  "Mollem\0",
                  "Collem\0",
                  "Goa\0"};
    int array[][14] = {{0, 10, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {10, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {9, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 10, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 14, 0, 0, 0, 0, 17, 0, 49, 0, 0, 0},
                       {0, 0, 20, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 16, 0, 7, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 7, 0, 4, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 17, 0, 0, 4, 0, 9, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 20, 0, 0, 0},
                       {0, 0, 0, 0, 49, 0, 0, 0, 0, 20, 0, 5, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 16},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 10},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 10, 0}};
    int **arr = (int **)malloc(sizeof(int *) * 14);
    for (int i = 0; i < 14; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * 14);
        for (int j = 0; j < 14; j++)
        {
            arr[i][j] = array[i][j];
        }
    }
    int distance[14];
    for (int i = 0; i < 14; i++)
        distance[i] = 7726;
    int alanvar = dijkstra(arr, 14, distance, 4, 13);
    int included[14];
    for (int i = 0; i < 14; i++)
        included[i] = 0;
    // printf("%d \n",alanvar);
    printf("\nThe path followed from Alanvar to Goa due to road block is : \n\n");
    haspath(arr, 4, 13, alanvar, included, p);
    printf("\n\nTotal distance of this path is %d: ", alanvar);
}