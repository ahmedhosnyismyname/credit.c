#include <cs50.h>
#include <stdio.h>
void check(long n);
int digits(long x);
#include <math.h>

int main(void)
{
    long a = get_long("Number: ");
    long c = a;
    int x = digits(a);
    int sum = 0;
    long num;
    long exp;

    for (int i = x - 1; i >= 0; i--)
    {
        exp = pow(10, i);
        num = a / exp;
        if (num > 0)
        {
            a %= num * exp;
        }
        if (i % 2 != 0)
        {
            num *= 2;
            if (num >= 10)
            {
                num = (num % 10) + 1;
            }
        }
        sum += num;
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        check(c);
    }
}

void check(long n)
{
    if (1e15 > n && n >= 1e14)
    {
        n /= 1e13;
        if (n == 34 || n == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (1e16 > n && n >= 1e15)
    {
        n /= 1e14;
        if (n < 50 && n >= 40)
        {
            printf("VISA\n");
        }
        else if (n < 56 && n > 50)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (1e13 > n && n >= 1e12)
    {
        n /= 1e11;
        if (n < 50 && n >= 40)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int digits(long x)
{
    int n = 0;
    do
    {
        x /= 10;
        n++;
    }
    while (x > 0);
    return n;
}
