#include <stdio.h>

int main(void)
//This is a test
{
    char name[7];

    printf("Hola, Como se llama?\n ");
    fgets(name,20,stdin);
    printf("Nice to meat you %s.", name);
    return 0;


}