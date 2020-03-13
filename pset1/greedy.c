#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float money;
    do
    {
        printf("O hai!");
        printf(" How much change is owed?\n");
        money = GetFloat();
    }while(money < 0);
    int cents = round(money * 100);
    int coins = 0;
    if(cents/25 >0)
    {
        coins = coins + cents / 25;
        cents = cents % 25;
    }
    if(cents/10 >0)
    {
        coins = coins + cents / 10;
        cents = cents % 10;
    }
    if(cents/5 >0)
    {
        coins = coins + cents / 5;
        cents = cents % 5;
    }
    coins = coins + cents;
    printf("%d\n", coins);
}