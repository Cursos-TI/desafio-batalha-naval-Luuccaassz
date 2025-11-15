#include <stdio.h>

int main()
{

#define tabuleiro 10
#define navio 3

    int tabuleiro1[tabuleiro][tabuleiro]; // Matriz
    int i, j;

    // Tabuleiro inicializado com 0
    for (i = 0; i < tabuleiro; i++)
    {
        for (j = 0; j < tabuleiro; j++)
        {
            tabuleiro[&i][&j] = 0;
        }
    }

    // Cordenada Navio Horizontal

    int navioHL = 2; // Linha inicial
    int navioHC = 1; // Coluna inicial

    // Cordenada Navio Vertical
    int navioVL = 5; // Linha inicial
    int navioVC = 7; // Coluna inicial

    // Verificar se o navio esta dentro do tabuleiro

    if (navioHC + navio > tabuleiro || navioHL >= tabuleiro)
    {
        printf("Navio horizontal esta fora dos limites do tabuleiro\n");
        return 1;
    }
    // verificação navio vertical
    if (navioVL + navio > tabuleiro || navioVC >= tabuleiro)
    {
        printf("Navio vertical fora dos limites do tabuleiro!\n");
        return 1;

        // Posicionamento do Navio Horizontal

        for (i = 0; i < navio; i++)
        {
            tabuleiro[&navioHL][&navioHC + i] = 3;
        }

        // Posicionamento navio Vertical
        for (i = 0; i < navio; i++)
        {
            // Validação de sobreposição
            if (tabuleiro[&navioVL + i][&navioVC] == 3)
            {
                printf("Erro: navios sobrepostos!\n");
                return 1;
            }
            tabuleiro[&navioVL + i][&navioVC] = 3;
        }

        // Exibição dod tabuleiro com as colunas

        printf("--- BATALHA NAVAL ---\n\n");

        // cabeçalho colunas

        printf("   "); // Espaço pra alinhar linhas
        for (j = 0; j < tabuleiro; j++)
        {
            printf("%c ", 'A' + j);
        }
        printf("\n");

        // Exibição das linhas

        for (i = 0; i < tabuleiro; i++)
        {
            printf("%2d ", i + 1); // Numero Linha
            for (j = 0; j < tabuleiro; j++)
            {
                printf("%d ", tabuleiro[&i][&j]);
            }
            
        }

        return 0;
    }
