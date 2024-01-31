#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 20
#include "camp_structs.h"

// Função para gerar o campeonato
void gera_campeonato(struct Campeonato *c)
{
    int i, j, k;
    struct Time times[n];

    // Inicializando os números dos times
    for (i = 0; i < n; i++)
    {
        times[i].numeroTime = i + 1;
    }

    // Gerando as partidas e gols e armazenando diretamente em c
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n / 2; j++)
        {
            c->r[i].p[j].t[0] = times[j];
            c->r[i].p[j].t[1] = times[n - j - 1];
        }
        struct Time temp = times[n - 1];
        for (k = n - 1; k > 1; k--)
        {
            times[k] = times[k - 1];
        }
        times[1] = temp;
    }
}

// Função para gerar os gols nos nas partidas em cada time
void gera_gols(struct Campeonato *c)
{
    int i, j, k;

    // gera o saldo de gols dos times;
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 2; k++)
            {
                c->r[i].p[j].t[k].gols = (rand() % 7);
                ;
            }
        }
    }
}

// Função para alocar os gols nos jogadores
void distribui_gols_jogadores(struct Campeonato *c)
{
    int i, j, k, w, nGols, escolhaJog;

    // inicializa o saldo de gols dos jogadores com 0;
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 2; k++)
            {
                for (w = 0; w < 11; w++)
                {
                    c->r[i].p[j].t[k].j[w].golsJog = 0;
                }
            }
        }
    }

    // aloca os gols nos jogadores aleatoriamente
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 2; k++)
            {
                nGols = c->r[i].p[j].t[k].gols; // armazena o numero de gols daquele time na partida j da rodada k.

                for (w = 1; w <= nGols; w++) // aloca os w gols nos jogadores aleatoriamnte.
                {
                    escolhaJog = (rand() % 11);

                    c->r[i].p[j].t[k].j[escolhaJog].golsJog++;
                }
            }
        }
    }
}
