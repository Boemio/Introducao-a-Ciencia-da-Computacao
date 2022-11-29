#include <stdio.h>

int main()
{
    int s,m,h;

    scanf("%d", &s);

    m = s/60;
    s = s%60;
    h = m/60;
    m -= h*60;

    printf("%02d:%02d:%02d\n",h,m,s);

    return 0;
}
