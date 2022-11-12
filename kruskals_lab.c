// kruskals lab evaluation

#include <stdio.h>
#define MAX 10

typedef struct edge
{
    int u, v, w;
} edge;

typedef struct edgelist
{
    edge data[MAX];
    int n;
} edgelist;

int G[MAX][MAX];
int n;

edgelist e_list;
edgelist spanList;

void kruskals();
int find(int belongs[], int vertex_no);
void quickSort(edge data[], int left, int right);
void sort();
void union_(int belongs[], int x, int y);
void swap(edge *a, edge *b);
void partition();

int main()
{
    int high = e_list.n - 1;
    int low = 0;
    printf("Enter the no. of vertices:\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    kruskals();

    return 0;
}

void kruskals()
{
    int belongs[MAX], cost = 0;
    int i, j, cno1, cno2;
    e_list.n = 0;
    spanList.n = 0;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] != 0)
            {
                e_list.data[e_list.n].u = i;
                e_list.data[e_list.n].v = j;
                e_list.data[e_list.n].w = G[i][j];
                e_list.n++;
            }
        }
    }
    quickSort();
    sort();

    for (i = 0; i < n; i++)
    {
        belongs[i] = i;
    }
    for (i = 0; i < e_list.n; i++)
    {
        cno1 = find(belongs, e_list.data[i].u);
        cno2 = find(belongs, e_list.data[i].v);
        if (cno1 != cno2)
        {
            spanList.data[spanList.n] = e_list.data[i];
            spanList.n = spanList.n + 1;
            union_(belongs, cno1, cno2);
        }
    }
    printf("\n\t\t Minimum spanning Tree\n");

    printf("\n\nu - v : w\n\n");
    for (i = 0; i < spanList.n; i++)
    {
        printf("%d - %d : %d\n", spanList.data[i].u, spanList.data[i].v, spanList.data[i].w);
        cost = cost + spanList.data[i].w;
    }

    printf("\nTotal cost of minimum spanning tree: %d", cost);
}

int find(int belongs[], int vertex_no)
{
    return (belongs[vertex_no]);
}

void sort()
{
    edge temp;
    for (int i = 1; i < e_list.n; i++)
    {
        for (int j = 0; j < e_list.n - 1; j++)
        {
            if (e_list.data[j].w > e_list.data[j + 1].w)
            {
                swap(&e_list.data[j], &e_list.data[j + 1]);
            }
        }
    }
}

 void partition(edge e_list.data )
 {
     
 } // int *arr, int low, int high)
// {
//     int high = e_list.n - 1;
//     int low = 0;
//     int pivot = e_list.data[high].w;
//     int i = low - 1;
//     int temp;
//     for (int j = low; j < high; j++)
//     {
//         if (e_list.data[j].w <= pivot)
//         {
//             i++;
//             swap(&e_list.data[i], &e_list.data[j]);
//         }
//     }
//     temp = e_list.data[i + 1].w;
//     e_list.data[i + 1].w = e_list.data[high].w;
//     e_list.data[high].w = temp;
//     return e_list.data[high].w + (i + 1);
// }

// void quickSort(int *e_list, int low, int high)
// {
//     if (low < high)
//     {
//         int *pivot = partition(e_list, low, high);
//         quickSort(arr, low, pivot - arr - 1);
//         quickSort(arr, pivot - arr + 1, high);
//     }
//     return;
// }

void swap(edge *a, edge *b)
{
    edge temp = *a;
    *a = *b;
    *b = temp;
}

void union_(int belongs[], int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        if (belongs[i] == y)
        {
            belongs[i] = x;
        }
    }
}
