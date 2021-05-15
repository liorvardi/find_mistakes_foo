#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
// 1) bad naming of the variable x
// 2) bad naming of the function
char* foo(char* str, int* x) {
    // 3) bad naming of the variable str2
    char* str2;
    int i;

    // 4) no check if x is null
    // 5) no check if str2 is empty

    // 6) x is a pointer, not an int
    // 7) need to add 1 for null at end of string (strlen doesn't count it)
    x = strlen(str);

    // 8) not checking if the malloc succeeded
    // 9) need to multiply by sizeof(char), what if char is more than 1 byte?
    str2 = malloc(*x);
    for (i = 0; i < *x; i++)
        str2[i] = str[*x - i];

    // 10) null will not be added

    if (*x % 2 == 0) {
        printf("%s", str);
    }
    if (*x % 2 != 0)
    {
        printf("%s", str2);
    }
    return str2;
}
*/

char* reverseStr(char* str, int* str_size) {
    char* reversed_str;

    if(str == NULL || str_size == NULL)
    {
        return NULL;
    }

    *str_size = (int)strlen(str);
    reversed_str = (char*)malloc(sizeof(char)*(*str_size+1));
    if(reversed_str == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < *str_size; i++)
    {
        reversed_str[i] = str[*str_size -1 - i];
    }
    reversed_str[*str_size] = '\0';


    if (*str_size % 2 == 0)
    {
        printf("%s\n", str);
    }
    else
    {
        printf("%s\n", reversed_str);
    }
    return reversed_str;
}

int main()
{
    int size;
    char *str = reverseStr("hi", &size);
    assert(strcmp(str, "ih") == 0);
    free(str);

    str = reverseStr("hello", &size);
    assert(strcmp(str, "olleh") == 0);
    free(str);

    return 0;
}