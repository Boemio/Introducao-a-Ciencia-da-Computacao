#include <stdio.h>

int main()
{
    int estacaoInicial;
    
    scanf("%d", &estacaoInicial);

    switch(estacaoInicial)
    {
        case 0:
            printf("* Morumbi\n");
            printf("|\n");
            printf("* Butanta\n");
            printf("|\n");
            printf("* Pinheiros\n");
            printf("|\n");
            printf("* Faria Lima\n");
            printf("|\n");
            printf("* Fradique Coutinho\n");
            printf("|\n");
            printf("* Oscar Freire\n");
            break;
        case 1:
            printf("* Butanta\n");
            printf("|\n");
            printf("* Pinheiros\n");
            printf("|\n");
            printf("* Faria Lima\n");
            printf("|\n");
            printf("* Fradique Coutinho\n");
            printf("|\n");
            printf("* Oscar Freire\n");
            break;
        case 2:
            printf("* Pinheiros\n");
            printf("|\n");
            printf("* Faria Lima\n");
            printf("|\n");
            printf("* Fradique Coutinho\n");
            printf("|\n");
            printf("* Oscar Freire\n");
            break;
        case 3:
            printf("* Faria Lima\n");
            printf("|\n");
            printf("* Fradique Coutinho\n");
            printf("|\n");
            printf("* Oscar Freire\n");
            break;
        case 4:
            printf("* Fradique Coutinho\n");
            printf("|\n");
            printf("* Oscar Freire\n");
            break;
        case 5:
            printf("* Oscar Freire\n");
            break;
        case 6:
            printf("* Paulista\n");
            printf("|\n");
            printf("* Higienopolis-Mackenzie\n");
            printf("|\n");
            printf("* Republica\n");
            printf("|\n");
            printf("* Luz\n");
            break;
        case 7:
            printf("* Higienopolis-Mackenzie\n");
            printf("|\n");
            printf("* Republica\n");
            printf("|\n");
            printf("* Luz\n");
            break;
        case 8:
            printf("* Republica\n");
            printf("|\n");
            printf("* Luz\n");
            break;
        case 9:
            printf("* Luz\n");
            break;
    }

    return 0;
}