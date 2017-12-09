#include <cs50.h>
#include <stdio.h>

int     count_digits(long long n);
int    checksum(long long n, int digit);

int     main(void)
{
    // prompts user for credit card number and report type of card
    printf("Number: ");
    long long number = get_long_long();

    if (number < 0)
    {
        printf("Retry: ");
        number = get_long_long();
    }

    int digit = count_digits(number);

    if (digit != 13 && digit != 15 && digit != 16)
        printf("INVALID\n");
    
    else if (digit == 15 && checksum(number, digit))
    {
        if (number / 10000000000000 == 34 || number / 10000000000000 == 37)
            printf("AMEX\n");
        else
            printf("INVALID\n");
    }
    
    else if (digit == 16 && checksum(number, digit))
    {
        if (number / 100000000000000 == 51 || number / 100000000000000 == 52 || number / 100000000000000 == 53
        || number / 100000000000000 == 54 || number / 100000000000000 == 55)
            printf("MASTERCARD\n");
        else if (number / 1000000000000000 == 4)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    
    else if (digit == 13 && checksum(number, digit))
    {
        if (number / 1000000000000 == 4)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    
    else
    {
        printf("INVALID\n");
    }

    return (0);
}

int    count_digits(long long n)
{
    int digit = 0;
    while (n >= 1)
    {
        n = n / 10;
        digit++;
    }
    return (digit);
}

int    checksum(long long n, int digit)
{
    int sum[digit];

    for (int i = 0; i < digit - 1; i++)
    {
        sum[i] = n % 10;
        i += 1;
        sum[i] = (n / 10) % 10 * 2;
        n /= 100;
    }

    if (digit % 2 != 0)
    {
        sum[digit - 1] = n % (10 * (digit - 1));
    }

    int total = 0;

    for (int j = 0; j < digit; j++)
    {
        total += sum[j] % 10 + (sum[j] / 10);
        //printf("Element[%d] = %d, Total = %d\n", j, sum[j], total);
    }

    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}