#include <stdio.h>

int main()
{
    int vg,vs,vn;
    int pg,ps,pn;
    int totalv, totalp;
    int g = 0,s = 0,n = 0;

    scanf("%d",&vg);
    scanf("%d",&vs);
    scanf("%d",&vn);

    scanf("%d",&pg);
    scanf("%d",&ps);
    scanf("%d",&pn);

    totalv = (vg*493) + (vs*29) + vn;
    totalp = (pg*493) + (ps*29) + pn;

    if(totalp >= totalv)
    {
        totalp -= totalv;

        if(totalp >= 493)
        {
            g = totalp/493;
            totalp -=  (g*493);
        }

        if(totalp >= 29)
        {
            s = totalp/29;
            totalp -= (s*29);
        }

        n = totalp;

        printf("Seu troco eh %d galeoes, %d sicles e %d nuques, Harry!\n",g,s,n);

    }


    return 0;
}