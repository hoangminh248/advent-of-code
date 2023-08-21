#include <stdio.h>
#include <stdlib.h>

int solvePart1()
{
    FILE *input_F;
    input_F = fopen("D:/ADVENT-OF-CODE/xxxx/xx/input.txt","r");
    if(input_F == NULL)
        printf("Open file failed !!!");
    else
    {
        while(!feof(input_F)){
            printf("%c",fgetc(input_F));
        }
    }
}
int solvePart2()
{
    FILE *input_F;
    input_F = fopen("D:/ADVENT-OF-CODE/xxxx/xx/input.txt","r");
    if(input_F == NULL)
        printf("Open file failed !!!");
    else
    {
        while(!feof(input_F)){
            printf("%c",fgetc(input_F));
        }
    }
}

int main()
{
    // Start here
    return 0;
}