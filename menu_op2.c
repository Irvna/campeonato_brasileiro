#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camp_structs.h"


void escreve_tabela_artilheiros(int somaJogadores[][11], int *time, int *jogador, struct NomeTime *nomeTime, int rod)
{
    system("color 2F");//deicando o fundo verde
    int i;
    if(rod == 3)
    {
        for (i = 0; i < rod; i++)
        {
            printf("| %dº |%s: %d gols |%s\n", i + 1, nomeTime[time[i]].nJ[jogador[i]].nomeJ, somaJogadores[time[i]][jogador[i]], nomeTime[time[i]].nome);
        }
    }
    else
    {
        for (i = 0; i < rod; i++)
        {
            if(somaJogadores[time[i]][jogador[i]] < 10)
            {
                printf("|----|---------------------|---------|-----------------------------------------------------------|\n| %dº |%s |  %d gols | Time do jogador: %s                           |\n", i + 1, nomeTime[time[i]].nJ[jogador[i]].nomeJ, somaJogadores[time[i]][jogador[i]], nomeTime[time[i]].nome);
            }
            else
            {
                printf("|----|---------------------|---------|-----------------------------------------------------------|\n| %dº | %s| %d gols | Time do jogador: %s                            |\n", i + 1, nomeTime[time[i]].nJ[jogador[i]].nomeJ, somaJogadores[time[i]][jogador[i]], nomeTime[time[i]].nome);
            }
        }
    }
}

// função que ordena os artilheiros e retorna dois vetores com as posições em ordem
void ordena_artilheiros(int somaJogadores[][11], int *time, int *jogador)
{

    int i, j, k, somaAux[20][11], maior;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 11; j++)
        {
            somaAux[i][j] = somaJogadores[i][j];
        }
    }

    for (k = 0; k < 5; k++)
    {
        maior = somaAux[0][0];
        for (i = 0; i < 20; i++)
        {

            for (j = 0; j < 11; j++)
            {
                if (somaAux[i][j] > maior)
                {
                    maior = somaAux[i][j];
                    time[k] = i;
                    jogador[k] = j;
                }
            }
        }

        somaAux[time[k]][jogador[k]] = -1;
    }
}

void tabela_artilheiro(struct Campeonato *c, struct NomeTime *nomeTime, int rod)
{

    int i, j, k, w, time, somaJogadores[20][11], ordem_time[5], ordem_jogadores[5];

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 11; j++)
        {
            somaJogadores[i][j] = 0;
        }
    }

    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 2; k++)
            {
                time = c->r[i].p[j].t[k].numeroTime - 1;

                for (w = 0; w < 11; w++)
                {
                    if (c->r[i].p[j].t[k].j[w].golsJog != 0)
                    {

                        somaJogadores[time][w] += c->r[i].p[j].t[k].j[w].golsJog;
                    }
                }
            }
        }
    }

    ordena_artilheiros(somaJogadores, ordem_time, ordem_jogadores);
    escreve_tabela_artilheiros(somaJogadores, ordem_time, ordem_jogadores, nomeTime, rod);
}
