#include <stdio.h>
#include <stdlib.h>

void dijkstra(int **graph, int n, int s, int *dist, int *dest);
int destination;
int main()
{
    int source, destination;
    int n, i, j;   // n is the number of the vertices, i is the index of the vertices, j is the index of the edges
    int **graph;   // adjacency matrix
    int dist[100]; // distance from source to each vertex
    int dest[100]; // destination of each vertex
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the adjacency matrix: \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("Enter the destination vertex: ");
    scanf("%d", &destination);
    dijkstra(graph, n, source, dist, dest);
}

void dijkstra(int **graph, int n, int s, int *dist, int *dest)
{
    int i, j, k;
    int min, min_index; // min is the minimum distance, min_index is the index of the vertex with the minimum distance
    int visited[100];   // visited[i] = 1 if vertex i is visited, 0 otherwise
    for (i = 0; i < n; i++)
    {
        dist[i] = graph[s][i]; // distance from source s to vertex i
        dest[i] = s;           // destination of vertex i
        visited[i] = 0;        // initially all vertices are unvisited
    }
    visited[s] = 1;             // source vertex is visited
    for (i = 0; i < n - 1; i++) // n-1 because we have already visited the source vertex
    {
        min = 100;
        for (j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] < min) // 
            {
                min = dist[j];
                min_index = j;
            }
        }
        visited[min_index] = 1;  // min_index is visisted
        for ( k = 0; k<n;k++)
        {
            if(visited[k] == 0 && graph[min_index][k] && dist[min_index] + graph[min_index][k] < dist[k]) // if the distance from source to vertex k is less than the current distance
            {
                dist[k] = dist[min_index] + graph[min_index][k]; // update the distance from source to vertex k
                dest[k] = min_index; // update the destination of vertex k
            }
        }
    }
    printf("The shortest distance from vertex %d to vertex %d is %d\n", s, destination, dist[destination]);
}