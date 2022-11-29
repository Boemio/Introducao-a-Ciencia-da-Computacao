#include <stdio.h>

void preencherRotor(int rotor[]);
void printarRotor(int rotor[]);
void ajusteRotor(int rotor[]);

int main()
{
    int rotor1[26];
    int rotor2[26];
    int rotor3[26];
    char c;
    int contadorRotor1 = 0;
    int contadorRotor2 = 0;

    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha
    scanf("%*[\r\n]s"); // Ignora o pula linha
    preencherRotor(rotor1);
    preencherRotor(rotor2);
    preencherRotor(rotor3);
    scanf("%*[\r\n]s"); // Ignora o pula linha
    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha
    scanf("%*[\r\n]s"); // Ignora o pula linha

    while(scanf("%c", &c) != EOF)
    {
        if(c >= 65 && c <= 90) // Maiúscula
        {
            c -= 65;
            c = rotor3[rotor2[rotor1[(int)c]]];
            c += 65;
            printf("%c", c);
            // Ajuste dos rotores
            contadorRotor1++;
            ajusteRotor(rotor1);
            if(contadorRotor1 % 26 == 0)
            {
                contadorRotor2++;
                ajusteRotor(rotor2);

                if(contadorRotor2 % 26 == 0)
                {
                    ajusteRotor(rotor3);
                }
            }
        }
        else if(c >= 97 && c <= 122) // Minúscula
        {   
            c -= 97;
            c = rotor3[rotor2[rotor1[(int)c]]];
            c += 97;
            printf("%c", c);
            // Ajuste dos rotores
            contadorRotor1++;
            ajusteRotor(rotor1);
            if(contadorRotor1 % 26 == 0)
            {
                contadorRotor2++;
                ajusteRotor(rotor2);

                if(contadorRotor2 % 26 == 0)
                {
                    ajusteRotor(rotor3);
                }
            }
        }
        else // Caracteres especiais
        {
            printf("%c", c);
        }
    }

    return 0;
}

void preencherRotor(int rotor[])
{
    for(int i = 0; i < 26; i++)
    {
        scanf("%d", &rotor[i]);
    }
}

void printarRotor(int rotor[])
{
    for(int i = 0; i < 26; i++)
    {
        printf("%d ", rotor[i]);
    }
    printf("\n");
}

void ajusteRotor(int rotor[])
{
    int rotorCopia[26];

    for(int i = 0; i < 26; i++)
    {
        rotorCopia[i] = rotor[i];
    }

    for(int i = 0; i < 25; i++)
    {
        rotor[i] = rotorCopia[i+1];
    }

    rotor[25] = rotorCopia[0];
}