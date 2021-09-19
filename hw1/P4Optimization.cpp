#include <iostream>

int main()
{
    int a[N][4];
    int rand_number = rand();
    threshold = 2.0 * rand_number;
    if (threshold < 4)
    {
        for (j = N - 1; j >= 0; j--)
        {
            sum = sum + a[j][i];
            sum = sum + a[j][i + 1];
            sum = sum + a[j][i + 2];
            sum = sum + a[j][i + 3];
        }
    }
    else
    {
        for (j = N-1; j >= 0; j--)
        {
            sum = sum + a[j][i] + 1;
            sum = sum + a[j][i + 1] + 1;
            sum = sum + a[j][i + 2] + 1;
            sum = sum + a[j][i + 3] + 1;
        }
    }
}