#include <stdio.h>

int main()
{
    int x=0,y=0,contador=0;
    char c;

    while(contador < 6)
    {
        scanf("%c", &c);
        if(c == 'W')
        {
            y++;
        }
        if(c == 'S')
        {
            y--;
        }
        if (c == 'D')
        {
            x++;
        }
        if(c == 'A')
        {
            x--;
        }
        contador++;
    }

    printf("%d %d\n", x, y);

    return 0;

}
