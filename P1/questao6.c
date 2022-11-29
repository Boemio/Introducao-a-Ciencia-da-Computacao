#include <stdio.h>

int main()
{
    for (int i = 2022; i <= 3000; i++)
    {
        if((i % 4) == 0 && (i % 100) != 0)
        {
            printf("%d\n", i);
        }
        else if((i % 100) == 0 && (i % 400) == 0)
        {
            printf("%d\n", i);
        }
    }
}