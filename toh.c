#include<stdio.h>

void toh(int, char from, char to, char aux);

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    return 0;
}



void toh(int n, char from, char to,  char aux)
{
    if (n==1)
    {
        printf("\nMove disk 1 from %c to %c", from, to);
        return;
    }
    toh (n-1, from, aux, to);
    printf("\nMove disk %d from %c to %c", n, from, to);
    toh (n-1, aux, to, from);

}