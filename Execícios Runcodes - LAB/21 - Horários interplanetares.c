#include <stdio.h>
#include <string.h>

void conversao(long long int segundos, char planeta[], long long int *pdias, long long int *phoras, long long int *pminutos, long long int *psegundos);

int main()
{
    // Declaração das variáveis
    long long int segundos;
    char planeta[20];
    long long int dias;
    long long int horas;
    long long int minutos;
    long long int segundosaux;

    // Declarando os ponteiros
    long long int *pdias;
    long long int *phoras;
    long long int *pminutos;
    long long int *psegundos;

    // Iniciando os ponteiros
    pdias = &dias;
    phoras = &horas;
    pminutos = &minutos;
    psegundos = &segundosaux;

    // Lendo as variáveis
    scanf("%llu", &segundos);
    scanf("%s", planeta);

    // Executando a função
    conversao(segundos, planeta, pdias, phoras, pminutos, psegundos);

    // Printando
    printf("%llu segundos no planeta %s equivalem a:\n%llu dias, %llu horas, %llu minutos e %llu segundos\n", segundos, planeta, *pdias, *phoras, *pminutos, *psegundos);

    return 0;
}

void conversao(long long int segundos, char planeta[], long long int *pdias, long long int *phoras, long long int *pminutos, long long int *psegundos)
{
    if(strcmp(planeta, "Terra") == 0)
    {
        // Dias
        *pdias = segundos/86400;
        segundos -= (*pdias)*86400;
        
        // Horas
        *phoras = segundos/3600;
        segundos -= (*phoras)*3600;

        // Minutos
        *pminutos = segundos/60;
        segundos -= (*pminutos)*60;

        // Segundos
        *psegundos = segundos;
    }

    else if(strcmp(planeta, "Venus") == 0)
    {
        // Dias
        *pdias = segundos/20995200;

        // Horas
        *phoras = (segundos % 20995200)/3600;

        // Minutos
        *pminutos = ((segundos % 20995200) % 3600)/60;

        // Segundos
        *psegundos = ((segundos % 20995200) % 3600) % 60;
    }
    
    else if(strcmp(planeta, "Mercurio") == 0)
    {
        // Dias
        *pdias = segundos/5068800;

        // Horas
        *phoras = (segundos % 5068800)/3600;

        // Minutos
        *pminutos = ((segundos % 5068800) % 3600)/60;

        // Segundos
        *psegundos = ((segundos % 5068800) % 3600) % 60;
    }

    else if(strcmp(planeta, "Jupiter") == 0)
    {
        // Dias
        *pdias = segundos/35760;

        // Horas
        *phoras = (segundos % 35760)/3600;

        // Minutos
        *pminutos = ((segundos % 35760) % 3600)/60;

        // Segundos
        *psegundos = ((segundos % 35760) % 3600) % 60;
    }
}