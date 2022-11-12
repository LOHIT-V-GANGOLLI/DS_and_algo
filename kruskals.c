#include <stdio.h>

#define MAX 100

typedef struct edge
{
    int u, v, w;
} edge;

typedef struct edge_list
{
    edge data[MAX];
    int n; // number of edges
} edgelist;

edgelist elist;
edgelist spanlist;

int n;           // number of vertices
int G[MAX][MAX]; // adjacency matrix

void kruskal();
void sort();
void union1(int belongs[], int x, int y);
int find(int belongs[], int vertex_no);
void print();
void sort();
void swap(edge *a, edge *b);

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // G[i][j] = 0;
            scanf("%d", &G[i][j]);
        }
    }
    kruskal();
    print();
    return 0;
}

void kruskal()
{
    int belongs[MAX];
    int i, j, cno1, cno2;
    elist.n = 0;
    spanlist.n = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] != 0)
            {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = G[i][j];
                elist.n++;
            }
        }
    }
    sort();

    for (i = 0; i < n; i++)
    {
        belongs[i] = i;
    }
    for (i = 0; i < elist.n; i++)
    {
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v);
        if (cno1 != cno2)
        {
            spanlist.data[spanlist.n].u = elist.data[i].u;
            spanlist.n += 1;
            union1(belongs, cno1, cno2);
        }
    }
}

int find(int belongs[], int vertex_no)
{
    return belongs[vertex_no];
}

void union1(int belongs[], int x, int y)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (belongs[i] = y)
        {
            belongs[i] = x;
        }
    }
}

void sort()
{
    for (int i = 0; i < elist.n; i++)
    {
        for (int j = 0; j < elist.n - 1; j++)
        {
            if (elist.data[j].w > elist.data[j + 1].w)
            {
                swap(&elist.data[j], &elist.data[j + 1]);
            }
        }
    }
}

void swap(edge *a, edge *b)
{
    edge temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print()
{
    printf("\nThe spanning tree is:\n");
    printf("u  v  w\n");
    for (int i = 0; i < spanlist.n; i++)
    {
        printf("%d %d %d\n", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    }
}
