#include <cs50.h>
#include <stdio.h>
#include<stdlib.h>



int main(void)
{
    //read number
    long n;
    do
    {
        n = get_long("Enter Number: ");
    }
    while (!(n > 0 || n < 0 || n == 0));
    long c = n;
    int sum = 0;
    int sum2 = 0;



    //AMEX
    // if n starts with 34 or 37 and n has 15 digits
    if ((c / 100000000000000) % 10 == 3 && (c / 10000000000000) % 10 == 7 && c / 1000000000000000 == 0)
    {
        //sum for digits multiplied by 2
        for (int i = 0; i < 7; i++)
        {

            int digit = (n / 10) % 10;
            n /= 100;
            sum += (2 * digit) % 10 + (2 * digit) / 10;

        }

        //sum for digits not multiplied by 2
        n = c;
        for (int i = 0; i < 8; i++)
        {
            int digit2 = n % 10;
            n /= 100;
            sum2 += digit2;
        }

        //check validity
        if ((sum + sum2) % 10 == 0)
        {
            printf("AMEX");
        }
        else
        {
            printf("INVALID");
        }

    }

    //MASTERCARD
    // else if n starts with 51, 52, 53, 54, or 55 and n has 16 digits
    else if ((c / 1000000000000000) % 10 == 5 && (c / 100000000000000) % 10 >= 1 && (c / 100000000000000) % 10 <= 5
             && c / 10000000000000000 == 0)
    {
        //sum for digits multiplied by 2
        for (int i = 0; i < 8; i++)
        {

            int digit = (n / 10) % 10;
            n /= 100;
            sum += (2 * digit) % 10 + (2 * digit) / 10;

        }

        //sum for digits not multiplied by 2
        n = c;
        for (int i = 0; i < 8; i++)
        {
            int digit2 = n % 10;
            n /= 100;
            sum2 += digit2;
        }

        //check validity
        if ((sum + sum2) % 10 == 0)
        {
            printf("MASTERCARD");
        }
        else
        {
            printf("INVALID");
        }
    }



    //VISA
    //else if n starts with 4 and n has 13 or 16 digits

    //16-digit VISA
    else if (((c / 1000000000000000) % 10 == 4 && (c / 10000000000000000 == 0)))
    {
        //sum for digits multiplied by 2
        for (int i = 0; i < 8; i++)
        {

            int digit = (n / 10) % 10;
            n /= 100;
            sum += (2 * digit) % 10 + (2 * digit) / 10;

        }

        //sum for digits not multiplied by 2
        n = c;
        for (int i = 0; i < 8; i++)
        {
            int digit2 = n % 10;
            n /= 100;
            sum2 += digit2;
        }

        //check validity
        if ((sum + sum2) % 10 == 0)
        {
            printf("VISA");
        }
        else
        {
            printf("INVALID");
        }
    }

    // 13-digit VISA
    else if ((c / 1000000000000) % 10 == 4 && c / 10000000000000 == 0)
    {


        //sum for digits multiplied by 2
        for (int i = 0; i < 6; i++)
        {

            int digit = (n / 10) % 10;
            n /= 100;
            sum += (2 * digit) % 10 + (2 * digit) / 10;

        }

        //sum for digits not multiplied by 2
        n = c;
        for (int i = 0; i < 7; i++)
        {
            int digit2 = n % 10;
            n /= 100;
            sum2 += digit2;
        }

        //check validity
        if ((sum + sum2) % 10 == 0)
        {
            printf("VISA");
        }

        else
        {
            printf("INVALID");
        }
    }
    else
    {
        printf("INVALID");
    }


    printf("\n");


}