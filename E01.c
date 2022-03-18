#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// m <= 1000

/* typedef struct server
{
	char *name;
	char *ip;
}   server_t; */

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	getchar(); // Consome \n

    char map[m];

    for (int i = 0; i < n; i++)
    {
        char* string;
        scanf("%m[^\n]", &string);
    
    }

	return 0;
}

/**
 * @brief Função hash: encontra a posição correta de uma string em uma tabela
 * hash de tamanho dado.
 *
 * @param string cadeia de caracteres cuja posição na tabela será calculada;
 * @param m tamanho da tabela hash;
 * @return posição da string na tabela hash (int).
 */
int hash(char* string, int m)
{
    int p = 1000000007;
    int x = 263;

    long int sum = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        sum += (int)string[i] * pow(x, i);
        sum %= p;
    }

    return sum % m;
}