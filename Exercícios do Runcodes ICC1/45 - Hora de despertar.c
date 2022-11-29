#include <stdio.h>

int main()
{
    int h1,m1,s1,h2,m2,s2;
    
    scanf("%d",&h1);
    scanf("%d",&m1);
    scanf("%d",&s1);
    scanf("%d",&h2);
    scanf("%d",&m2);
    scanf("%d",&s2);
    
    
    if(h1>=0 && h1<24 && m1 >= 0 && m1 < 60 && s1 >= 0 && s1 < 60 && h2 >= 0 && h2<24 && m2 >= 0 && m2 < 60 && s2 >= 0 && s2 < 60)
    {
        h1 = h1+h2;
        m1 = m1+m2;
        s1 = s1+s2;
        
        if((m1/60) > 0)
        {
            h1 += m1/60;
            m1 -= 60*(m1/60);
        }
        if((s1/60) > 0)
        {
            m1 += s1/60;
            s1 -= 60*(s1/60);
        }
        
        if(h1 >= 24)
        {
            h1 = h1-24;
        }
        
        if(m1 >= 60)
        {
            m1 = m1-60;
        }
        
        if(s1 >=60)
        {
            s1= s1-60;
        }
        
        printf("%02d:%02d:%02d",h1,m1,s1);
        
    }
    

    return 0;
}