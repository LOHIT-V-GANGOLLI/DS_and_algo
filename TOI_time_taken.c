#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void toh(int, char, char, char);

int main()
{
    float tic = clock();
    int n;
    char from = 'A', to = 'C', aux = 'B';
    printf("Enter the number of disks in the tower: ");
    scanf("%d", &n);
    toh(n, from, to, aux);  
    float toc = clock();
    printf("The time taken by TOH is %f seconds", (toc - tic) / CLOCKS_PER_SEC);

    return 0;
}
void toh(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from disk %c to %c\n", from, to);
        return;
    }
    else
    {
        toh(n - 1, from, aux, to);
        printf("Move disk %d from %c to %c\n", n, aux, to, from);
        toh(n - 1, aux, to, from);
    }
}
