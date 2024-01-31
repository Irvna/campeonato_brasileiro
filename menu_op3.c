#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 20
#include "camp_structs.h"

void ordenar_top_goleiros(int total_gols_tomados[], int goleiros_menos_vazados[], struct Campeonato *c)
{
    int i, j, k;
    int aux_troca_vetor;

    for (i = 0; i < n; i++)
    {
        total_gols_tomados[i] = 0;
        goleiros_menos_vazados[i] = i;
    }

    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < n / 2; j++)
        {
            total_gols_tomados[c->r[i].p[j].t[0].numeroTime - 1] += c->r[i].p[j].t[1].gols;
            total_gols_tomados[c->r[i].p[j].t[1].numeroTime - 1] += c->r[i].p[j].t[0].gols;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {

            if (i != j && total_gols_tomados[i] < total_gols_tomados[j])
            {
                k = goleiros_menos_vazados[i];
                goleiros_menos_vazados[i] = goleiros_menos_vazados[j];
                goleiros_menos_vazados[j] = k;

                aux_troca_vetor = total_gols_tomados[i];
                total_gols_tomados[i] = total_gols_tomados[j];
                total_gols_tomados[j] = aux_troca_vetor;
            }
        }
    }
}

void top_goleiros(struct Campeonato *c, struct NomeTime *nomeTime, int rod)
{
    int i;
    int total_gols_tomados[n];
    int goleiros_menos_vazados[n];

    ordenar_top_goleiros(total_gols_tomados, goleiros_menos_vazados, c);

    if(rod == 1)
    {
        bold(1);
        printf("| 1º |%s|    |Time: %s     \n", nomeTime[goleiros_menos_vazados[0]].nJ[10].nomeJ,  nomeTime[goleiros_menos_vazados[0]].nome);
        bold(0);
        system("color 2F");//deixando o fundo verde
        printf("|    |Gols tomados: %d                  \n", total_gols_tomados[0]);
    }
    else
    {
        for (i = 0; i < rod; i++)
        {
            printf("|----|---------------------|----------------------|----------------------------------------------|\n");
            bold(1);
            printf("| %dº | %s| Gols tomados: %d     | Time: %s                         |\n", i + 1, nomeTime[goleiros_menos_vazados[i]].nJ[10].nomeJ, total_gols_tomados[i], nomeTime[goleiros_menos_vazados[i]].nome);
            bold(0);
            system("color 2F");//deicando o fundo verde
        }
    }
}
