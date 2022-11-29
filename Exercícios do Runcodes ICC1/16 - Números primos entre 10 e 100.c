#include <stdio.h>

int main()
{
    int a, b, primo;

    for(a=10; a<=100; a++)
    {
        if(a%2 != 0)
        {
            for(b=a-1; b>1; b --)
            {
                if(a%b == 0)
                {
                    primo = 0;
                    break;
                }
                primo = a;
            }

            if(primo > 0)
            {
                printf("%d ", primo);
            }
        }
    }

    return 0;
}