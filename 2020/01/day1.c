#include <stdio.h>
#include <stdlib.h>
#include "D:\\ADVENT-OF-CODE\\mylib\\myCPlib.h"
//#include "myCPlib.h"
int input[200] = {};

int solvePart1()
{
    FILE *input_F;
    input_F = fopen("D:/ADVENT-OF-CODE/2020/01/input.txt","r");
    if(input_F == NULL)
        printf("Open file failed !!!");
    else
    {
        for (int i = 0; i < 200;i++)
            fscanf(input_F, "%d", &input[i]);
        Quick_Sort(input, 0, 200);
        for(int i = 0; i < 200; i++)
        {
            if(Binary_Search(input, i, 199, 2020 - input[i]) != -1)
            {
                printf("Found 2 numbers: %d %d\n", input[i], 2020 - input[i]);
                printf("Result: %d\n", input[i] * (2020 - input[i]));
                break;
            }
        }
    }
}

int solvePart2()
{
    FILE *input_F;
    input_F = fopen("D:/ADVENT-OF-CODE/2020/01/input.txt","r");
    if(input_F == NULL)
        printf("Open file failed !!!");
    else
    {
        for (int i = 0; i < 200;i++)
            fscanf(input_F, "%d", &input[i]);  
        Quick_Sort(input, 0, 200);
        for (int i = 0; i < 200;i++){
            for (int j = i + 1; j < 200;j++){
                if(Binary_Search(input, j, 199, 2020 - input[i] - input[j]) != -1)
                {
                    printf("Found 3 numbers: %d %d %d\n", input[i], input[j], 2020 - input[i] - input[j]);
                    printf("Result: %d\n", input[i] * input[j] * (2020 - input[i] - input[j]));
                    break;
                }
            }
        }
    }
}
int main()
{

    //solvePart1();
    //solvePart2();
    return 0;
    
}
