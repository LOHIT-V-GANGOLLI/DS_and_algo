
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



char *toss()
{
    srand(time(NULL));
    int random = rand() % 2;
    if (random == 1)
        return "Head";
    else
        return "Tail";
}

int main()
{
    printf("%s", toss());
    return 0;
}