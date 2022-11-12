#include <stdio.h>
int visited[20];
int visited2 = 0;

main()
{
    int i, j;
    int v = 7;

    int a[10][10] = {{0, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 1, 0}};
    int b[10][10] = {{0, 2, 3, 0, 0, 0, 0}, {2, 0, 0, 4, 0, 0, 0}, {3, 0, 0, 0, 5, 0, 0}, {0, 4, 0, 0, 0, 7, 0}, {0, 0, 5, 0, 0, 0, 6}, {0, 0, 0, 7, 0, 0, 8}, {0, 0, 0, 0, 6, 8, 0}}; // weight of matrix 1
    int c[10][10] = {{0, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 1, 0}};
    int d[10][10] = {{0, 2, 3, 0, 0, 0, 0}, {2, 0, 0, 4, 0, 0, 0}, {3, 0, 0, 0, 5, 0, 0}, {0, 4, 0, 0, 0, 0, 6}, {0, 0, 5, 0, 0, 0, 7}, {0, 0, 0, 0, 0, 0, 8}, {0, 0, 0, 6, 7, 8, 0}}; // weight of matrix 2
    int e[10][10] = {{0, 1, 1, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0}, {1, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 1, 1}, {0, 0, 0, 1, 1, 0, 1}, {0, 0, 0, 0, 1, 1, 0}};
    int f[10][10] = {{0, 5, 6, 0, 0, 0, 0}, {5, 0, 2, 3, 0, 0, 0}, {6, 2, 0, 0, 10, 0, 0}, {0, 3, 0, 0, 0, 13, 0}, {0, 0, 10, 0, 0, 9, 11}, {0, 0, 0, 13, 9, 0, 12}, {0, 0, 0, 0, 11, 12, 0}}; // weight of matrix 3
    int g[10][10] = {{0, 1, 1, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0}, {1, 1, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 1, 0}};
    int h[10][10] = {{0, 3, 2, 0, 0, 0, 0}, {3, 0, 4, 5, 0, 0, 0}, {2, 4, 0, 6, 0, 0, 0}, {0, 5, 6, 0, 9, 0, 0}, {0, 0, 0, 9, 0, 0, 10}, {0, 0, 0, 11, 0, 0, 8}, {0, 0, 0, 0, 10, 8, 0}}; // weight of matrix  4
    int l[10][10] = {{0, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0}, {0, 1, 1, 1, 0, 0, 1}, {0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 1, 0}};
    int m[10][10] = {{0, 2, 3, 0, 0, 0, 0}, {2, 0, 0, 0, 5, 0, 0}, {3, 0, 0, 0, 6, 0, 0}, {0, 0, 0, 0, 11, 7, 0}, {0, 5, 6, 11, 0, 0, 9}, {0, 0, 0, 7, 0, 0, 10}, {0, 0, 0, 0, 9, 10, 0}}; // weight of matrix 5
    int s = 0, o;
    int visited[20];

    printf(" different topographies are\nthe bfs for 1st matrix\n");
    bfs(a, b, s, v);
    printf("the bfs for 2nd matrix \n");
    bfs(c, d, s, v);
    printf("the bfs for 3rd matrix\n");
    bfs(e, f, s, v);
    printf("the bfs for 4th matrix is \n");
    bfs(g, h, s, v);
    printf("the bfs for 5th matrix is \n");
    bfs(l, m, s, v);
    printf("the dfs for 1st matrix is \n");
    for (i = 0; i < v; i++)
        visited[i] = 0;
    printf("%d\t", s);
    o = dfs(a, b, s, v);
    printf("total distance %d\n", o);
    printf("the dfs for 2st matrix is \n");
    for (i = 0; i < v; i++)
        visited[i] = 0;
    printf("%d\t", s);
    o = dfs(c, d, s, v);
    printf("total distance %d\n", o);
    printf("the dfs for 3st matrix is \n");
    for (i = 0; i < v; i++)
        visited[i] = 0;
    printf("%d\t", s);
    o = dfs(e, f, s, v);
    printf("total distance %d\n", o);
    printf("the dfs for 4th matrix is \n");
    for (i = 0; i < v; i++)
        visited[i] = 0;
    printf("%d\t", s);
    o = dfs(g, h, s, v);
    printf("total distance %d\n", o);
    printf("the dfs for 5st matrix is \n");
    for (i = 0; i < v; i++)
        visited[i] = 0;
    printf("%d\t", s);
    o = dfs(c, d, s, v);
    printf("total distance %d\n", o);
}
void bfs(int a[10][10], int b[10][10], int s, int v)
{
    int visited1 = 0;
    int queue[20];
    int front = 0, rear = 0, i, u;
    int visited[20], visited2 = 0;
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
    printf("\nthe total distance is %d", visited1);
    printf("\nthe total cost of implementation = %d\n", visited1 * 100);
}
int dfs(int a[10][10], int b[10][10], int s, int v)
{
    int i;

    visited[s] = 1;
    for (i = 0; i < v; i++)
    {
        if (a[s][i] == 1 && visited[i] == 0)
        {

            visited2 = visited2 + b[s][i];
            dfs(a, b, i, v);
        }
    }
    return (visited2);
}