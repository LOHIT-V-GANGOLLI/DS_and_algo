 #include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20

int bruteForce(char *, char *);

bool main()
{
    char string[MAX];  //= "atharmujtabawani";
    char pattern[MAX]; //= "har";
    printf("Enter the string: ");
    scanf("%s", string);
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    if (bruteForce(string, pattern) == 0)
    {
        printf("pattern not found\n");
    }
    else
    {
        printf("pattern found at index %d\n", bruteForce(string, pattern));
    }

    return false;
}

int bruteForce(char string[], char pattern[])
{
    int len_string = strlen(string);
    int len_pattern = strlen(pattern);
    int i, j;

    int max = len_string - len_pattern + 1;

    for (i = 0; i < max; i++)
    {
        bool flag = true;
        for (j = 0; j < len_pattern && flag == true; j++)
        {
            if (pattern[j] != string[j + i])
            {
                flag = false;
            }
        }

        if (flag == true)
        {
            return i;
        }
    }
    return 0;
}