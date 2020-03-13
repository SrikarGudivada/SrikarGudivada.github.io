#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int main()
{
    long long number;
    do
    {
        printf("Number: ");
        number = get_long_long();
    }while(number < 1);
    
    int check = 0;
    long long original = number;
    
    number = number/10;
    while(number)
    {
        int result = (number%10)*2;
        if(result>9)
        {
            check += result%10;
            check += result/10;
        }
        else check += result;
        number = number/100;
    }
    number = original;
    while(number)
    {
        check += (number%10);
        number = number/100;
    }
    if(check%10 != 0) printf("INVALID\n");
    else
    {
        if(original/(long long)pow(10,15))
        {
            if((original/(long long )pow(10,14) > 50) && (original/(long long)pow(10,14) < 56)) printf("MASTERCARD\n");
            else if(original/(long long )pow(10,15) == 4) printf("VISA\n");
        }
        else if((original/(long long)pow(10,13) == 34) || (original/(long long)pow(10,13) == 37)) printf("AMEX\n");
        else if((original/(long long)pow(10,12) == 4)) printf("VISA\n");
        else printf("INVALID\n");
    }
    return 0;
}