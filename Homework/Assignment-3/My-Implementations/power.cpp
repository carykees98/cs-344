#include "power.h"

long double power_iter(double x, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }

    return result;
}

long double power_rec(double x, int n)
{
    if (n != 0)
    {
        x *= power_rec(x, n - 1);
    }
    else
    {
        return 1;
    }

    return x;
}

long double power_half(double x, int n)
{
    if (n != 0)
    {
        if (n % 2) // Odd
        {
            x *= (power_half(x, n / 2) * power_half(x, n / 2));
        }
        else // Even
        {
            x = (power_half(x, n / 2) * power_half(x, n / 2));
        }
    }
    else
    {
        return 1;
    }

    return x;
}
