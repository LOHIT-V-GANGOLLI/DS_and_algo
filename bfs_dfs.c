#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 10

// =============colour functions start================
// red
void red()
{
    printf("\033[1;31m");
}
// function for yellow colour
void yellow()
{
    printf("\033[1;33m");
}
// function for reset
void reset()
{
    printf("\033[0m");
}
// green
void green()
{
    printf("\033[1;32m");
}
// cyan
void cyan()
{
    printf("\033[0;36m");
}
// blue
void blue()
{
    printf("\033[1;34m");
}
// purple
void purple()
{
    printf("\033[1;35m");
}
// white
void white()
{
    printf("\033[1;37m");
}
// ====================colour functions end====================

int visited[20];
int visited2 = 0;

void bfs(int a[MAX][MAX], int b[MAX][MAX], int, int);
void dfs(int a[MAX][MAX], int b[MAX][MAX], int, int);

int main()
{
    red();
    printf("\n\n\t\t\tImplementation of BFS and DFS by Athar Mujtaba Wani\n");
    int i, j; //
    int s;
    int dist;
    int v = 7; // number of vertices
    int a[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 0},
                       {1, 0, 0, 1, 0, 0, 0},
                       {1, 0, 0, 0, 1, 0, 0},
                       {0, 1, 0, 0, 0, 1, 0},
                       {0, 0, 1, 0, 0, 0, 1},
                       {0, 0, 0, 1, 0, 0, 1},
                       {0, 0, 0, 0, 1, 1, 0}};

    int w_a[MAX][MAX] = { {0, 2, 3, 0, 0, 0, 0},
                          {2, 0, 0, 4, 0, 0, 0},
                          {3, 0, 0, 0, 5, 0, 0},
                          {0, 4, 0, 0, 0, 7, 0},
                          {0, 0, 5, 0, 0, 0, 6},
                          {0, 0, 0, 7, 0, 0, 8},
                          {0, 0, 0, 0, 6, 8, 0} }; // weight of matrix a

    int b[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 0},
                       {1, 0, 0, 1, 0, 0, 0},
                       {1, 0, 0, 0, 1, 0, 0},
                       {0, 1, 0, 0, 0, 0, 1},
                       {0, 0, 1, 0, 0, 0, 1},
                       {0, 0, 0, 0, 0, 0, 1},
                       {0, 0, 0, 1, 1, 1, 0}};

    int w_b[MAX][MAX] = {{0, 2, 3, 0, 0, 0, 0},
                         {2, 0, 0, 4, 0, 0, 0},
                         {3, 0, 0, 0, 5, 0, 0},
                         {0, 4, 0, 0, 0, 0, 6},
                         {0, 0, 5, 0, 0, 0, 7},
                         {0, 0, 0, 0, 0, 0, 8},
                         {0, 0, 0, 6, 7, 8, 0}}; // weight of matrix b

    int c[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 0},
                       {1, 0, 1, 1, 0, 0, 0},
                       {1, 1, 0, 0, 1, 0, 0},
                       {0, 1, 0, 0, 0, 1, 0},
                       {0, 0, 1, 0, 0, 1, 1},
                       {0, 0, 0, 1, 1, 0, 1},
                       {0, 0, 0, 0, 1, 1, 0}};

    int w_c[MAX][MAX] = {{0, 5, 6, 0, 0, 0, 0},
                         {5, 0, 2, 3, 0, 0, 0},
                         {6, 2, 0, 0, 10, 0, 0},
                         {0, 3, 0, 0, 0, 13, 0},
                         {0, 0, 10, 0, 0, 9, 11},
                         {0, 0, 0, 13, 9, 0, 12},
                         {0, 0, 0, 0, 11, 12, 0}}; // weight of the matrix c

    int d[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 0},
                       {1, 0, 1, 1, 0, 0, 0},
                       {1, 1, 0, 1, 0, 0, 0},
                       {0, 1, 1, 0, 1, 0, 0},
                       {0, 0, 0, 1, 0, 0, 1},
                       {0, 0, 0, 1, 0, 0, 1},
                       {0, 0, 0, 0, 1, 1, 0}};

    int w_d[MAX][MAX] = {{0, 3, 2, 0, 0, 0, 0},
                         {3, 0, 4, 5, 0, 0, 0},
                         {2, 4, 0, 6, 0, 0, 0},
                         {0, 5, 6, 0, 9, 0, 0},
                         {0, 0, 0, 9, 0, 0, 10},
                         {0, 0, 0, 11, 0, 0, 8},
                         {0, 0, 0, 0, 10, 8, 0}}; //  weight of matrix d

    int e[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 0},
                       {1, 0, 0, 0, 1, 0, 0},
                       {1, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 1, 1, 0},
                       {0, 1, 1, 1, 0, 0, 1},
                       {0, 0, 0, 1, 0, 0, 1},
                       {0, 0, 0, 0, 1, 1, 0}};

    int w_e[MAX][MAX] = {{0, 2, 3, 0, 0, 0, 0},
                         {2, 0, 0, 0, 5, 0, 0},
                         {3, 0, 0, 0, 6, 0, 0},
                         {0, 0, 0, 0, 11, 7, 0},
                         {0, 5, 6, 11, 0, 0, 9},
                         {0, 0, 0, 7, 0, 0, 10},
                         {0, 0, 0, 0, 9, 10, 0}};// weight of matrix e

    s = 0; // source vertex
    green();
    printf("\nThe different topologies are:\n");
    yellow();
    printf("\nMatrix 1 (BFS)\n");
    bfs(a, w_a, v, s);
    printf("\nMatrix 2 (BFS)\n");
    bfs(b, w_b, v, s);
    printf("\nMatrix 3 (BFS)\n");
    bfs(c, w_c, v, s);
    printf("\nMatrix 4 (BFS)\n");
    bfs(d, w_d, v, s);
    printf("\nMatrix 5 (BFS)\n");
    bfs(e, w_e, v, s);
    red();
    printf("\n\n_-_-_-_-_|||Using DFS|||-_-_-_-_-_\n");
    purple();
    printf("\nMatrix 1 (DFS)\n");
    dfs(a, w_a, v, s);
    printf("\nMatrix 2 (DFS)\n");
    dfs(b, w_b, v, s);
    printf("\nMatrix 3 (DFS)\n");
    dfs(c, w_c, v, s);
    printf("\nMatrix 4 (DFS)\n");
    dfs(d, w_d, v, s);
    printf("\nMatrix 5 (DFS)\n");
    dfs(e, w_e, v, s);
    reset();

    return 0;
}

void bfs(int a[MAX][MAX], int b[MAX][MAX], int v, int s)
{
    int visited1 = 0; // visited matrix
    int queue[20];
    int front = 0, rear = 0, i;
    int u; // current vertex
    int visited[20];
    for (i = 0; i < v; i++)
        visited[i] = 0;
    queue[rear] = s;
    visited[s] = 1;

    while (front <= rear)
    {
        u = queue[front];

        front = front + 1;
        for (i = 0; i < v; i++)
        {
            if (a[u][i] == 1 && visited[i] == 0)
            {
                visited1 = visited1 + b[u][i];
                visited[i] = 1;
                rear = rear + 1;
                queue[rear] = i;
            }
        }
    }
    printf("\nThe total distance is %d meters", visited1);
    printf("\nThe total cost of implementation = %d Rupees\n", visited1 * 100);
}

void dfs(int a[MAX][MAX], int b[MAX][MAX], int v, int s)
{
    int visited1 = 0;
    int stack[20];
    int top = -1, i, u;
    int visited[20];
    for (i = 0; i < v; i++)
        visited[i] = 0;
    stack[++top] = s;
    visited[s] = 1;

    while (top >= 0)
    {
        u = stack[top];
        top = top - 1;
        for (i = 0; i < v; i++)
        {
            if (a[u][i] == 1 && visited[i] == 0)
            {
                visited1 = visited1 + b[u][i];
                visited[i] = 1;
                top = top + 1;
                stack[top] = i;
            }
        }
    }
    printf("\nThe total distance is %d meters", visited1);
    printf("\nThe total cost of implementation = %d Rupees\n", visited1 * 100);
}