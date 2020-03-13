#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i,j,k;
    int height;
    do
    {
        printf("height: ");
        height = GetInt();
    }while((height < 0) || (height > 23));
    
    for(i = 0; i < height  ; i++ )
    {
        for(k = 0 ; k < (height - i -1);  k++)
        {
            printf(" ");
        }
        for(j = 0; j < (height - k + 1); j++)
        {
           printf("#");
        }
        printf("\n");
    }
}