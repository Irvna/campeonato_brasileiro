#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camp_structs.h"

void inicializa_nome_jogadores(struct NomeTime *nomeTime)
{
    FILE *nome_jogador;
    int i,j;

    nome_jogador = fopen("nome_jogadores.txt", "r");

    while(!feof(nome_jogador))
    {
        for(i=0; i<20; i++)
        {
            for(j=0; j<12; j++)
            {
                fgets(nomeTime[i].nJ[j].nomeJ, 30, nome_jogador);

            }
        }

    }

    fclose(nome_jogador);

}

