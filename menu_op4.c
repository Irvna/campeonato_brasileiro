#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 20
#include "camp_structs.h"

// Função para imprimir o campeonato
void imprimir_campeonato(struct Campeonato *c, int rod, struct NomeTime *nomeTime)
{
    int i, j;

    for (i = 0; i < rod; i++)
    {
        bold(1);
        if (i < 9)
        {
            printf("|------------------------------------------------------------------------------------------------|\n| RODADA %d:                                                                                      |\n", i + 1);
        }
        else
        {
            printf("|------------------------------------------------------------------------------------------------|\n| RODADA %d:                                                                                     |\n", i + 1);
        }
        bold(0);
        system("color 2F");//deicando o fundo verde
        for (j = 0; j < n / 2; j++)
        {

            if (j != 9)
            {
                printf("|------------------------------------------------------------------------------------------------|\n| Partida %d     |%s      |     %d VS %d       | %s                         |\n", j + 1, nomeTime[c->r[i].p[j].t[0].numeroTime - 1].nome, c->r[i].p[j].t[0].gols, c->r[i].p[j].t[1].gols, nomeTime[c->r[i].p[j].t[1].numeroTime - 1].nome);
            }
            else
            {
                printf("|------------------------------------------------------------------------------------------------|\n| Partida %d    |%s      |     %d VS %d       | %s                         |\n", j + 1, nomeTime[c->r[i].p[j].t[0].numeroTime - 1].nome, c->r[i].p[j].t[0].gols, c->r[i].p[j].t[1].gols, nomeTime[c->r[i].p[j].t[1].numeroTime - 1].nome);
            }
        }
    }
}
