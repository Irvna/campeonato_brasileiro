#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camp_structs.h"

void relatorio_final(struct Campeonato *c, struct NomeTime *nomeTime)
{
    printf("|----------------------------------------------------------------------------------------------------------------|\n");
    bold(1);
    printf("|                                                 CURIOSIDADES                                                    \n");
    bold(0);
    printf("|----------------------------------------------------------------------------------------------------------------|\n");
    printf("|1 - Brasileirão Assaí teve a terceira melhor média de publico presente da história da competição: 21.646        |\n|2 - Competições geraram meio bilhão de reais de renda aos clubes.                                               |\n|3 - Flamengo foi o clube que mais levou torcedores ao estádio: 1.315.556 de presentes nos jogos como mandante.  |\n");
    printf("|----------------------------------------------------------------------------------------------------------------|\n");
    bold(1);
    printf("|                                                 TOP 3 VENCEDORES                                                 \n");
    bold(0);
    printf("|----------------------------------------------------------------------------------------------------------------|\n");
    tabela_final(c, 3, nomeTime);
    printf("|----------------------------------------------------------------------------------------------------------------|\n");
    bold(1);
    printf("|                                                  MELHOR GOLEIRO                                                 \n");
    bold(0);
    printf("|----------------------------------------------------------------------------------------------------------------|\n");
    top_goleiros(c, nomeTime, 1);
    printf("|----------------------------------------------------------------------------------------------------------------|\n");
    bold(1);
    printf("|                                                  TOP 3 ARTILHEIROS                                              \n");
    bold(0);
    printf("|----------------------------------------------------------------------------------------------------------------|\n");
    tabela_artilheiro(c, nomeTime, 3);
    printf("|----------------------------------------------------------------------------------------------------------------|\n");
    bold(1);
    printf("|                                                   GOLS DO TIME                                                  \n");
    bold(0);
    printf("|----------------------------------------------------------------------------------------------------------------|\n");
    tabela_final(c, 0, nomeTime);
    system("color 2F");//deicando o fundo verde
}
