#include <stdio.h>

int main()
{
    int n; // máximo de rodadas 
    int m; // número de jogadores 
    int p; // posição de Pingu na ordem de rodadas 
    int frase = 1; // frase atual
    int n_pinguins = 1; // numero de pinguins
    int contador = 1; // conta a passagem da frase
    int ispingutime = 1; // confere se é a vez do pingu

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &p);

    for(int i = 0; i < n; i++)
    {
        if(frase > 3)
        {
            frase = 1;
            n_pinguins++;
        }

        if(p == ispingutime)
        {    
            switch(frase)
            {
                case 1:
                    switch(n_pinguins)
                    {
                        case 1:
                            printf("1 pinguim\n");
                            break;
                        default:
                            printf("%d pinguins\n", n_pinguins);
                    }
                    break;
                case 2:
                    printf("no gelo\n");
                    break;
                case 3:
                    printf("uhuu!\n");
                    break;
            }
        }

        if(contador == n_pinguins)
        {
            contador = 0;
            frase++;
        }
        if(ispingutime == m)
        {
            ispingutime = 0;
        }

        contador++;
        ispingutime++;
    }

    return 0;
}