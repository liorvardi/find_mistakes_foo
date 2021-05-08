#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* foo(char* str, int* x) {
    //1)check for NULL str
    if(str == NULL || x){
        return NULL;
    }
    //2)checking x, if it is NULL, will do everything normally but returning it
    int x_is_NULL = 0;
    if(x == NULL) {
        x_is_NULL++;
        x = malloc(sizeof(int));
        if(x==NULL){
            return NULL;
        }
    }
    char* str2;
    int i;
    //3)changed x to *x
    *x = strlen(str);
    //4)added +1 to malloc size + multiply by sizeof(char)
    str2 = malloc(sizeof(char)*(*x+1));
    //5+6)copy only the first *x chars + added {}
    for (i = 1; i <= *x; i++) {
        str2[i] = str[*x - i];
    }
    //7)last char must be null-byte
    str2[*x] = 0;
    //8)if was at wrong order
    if (*x % 2 != 0) {
        printf("%s", str);
    }
    if (*x % 2 == 0){
        printf("%s", str2);
    }
    if(x_is_NULL){
        free(x);
    }
    return str2;
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
