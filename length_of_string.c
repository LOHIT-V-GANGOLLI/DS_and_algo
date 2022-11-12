// length of string using pointers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int StringLength(char *str);
int stringLength(char *str);


int main()
{
    int n;
    char *str;
    printf("Enter the size of string: ");
    scanf("%d", &n);
    str = (char *)malloc(sizeof(char) * n);
    int i, len;
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    printf("Length of string is %d using strlen()", len);
    printf("\nThe length of the string is %d using pointers", StringLength(str));
    printf("\nThe length of the string is %d using recursion", stringLength(str));

    return 0;
}

int StringLength(char *str)
{
    int len = 0;
    while(*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

int stringLength(char *str)
{
    if (str == '\0')
    {
        return 0;
    }
    else
    {
        return 1 + stringLength(str + 1);
    }
}