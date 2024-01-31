#include <stdio.h>
#include "camp_structs.h"

void menu(struct Campeonato *c, struct NomeTime *nomeTime)
{
    system("color 2F");//deicando o fundo verde
    int escolha, rodada;

    printf("|------------------------------------------------------------------------------------------------|\n|                                     ESCOLHA UMA OPÇÃO:                                         |\n|------------------------------------------------------------------------------------------------|\n| 1: Ver tabela final de classificação.                                                          |\n|------------------------------------------------------------------------------------------------|\n| 2: Ver artilheiros do campeonato.                                                              |\n|------------------------------------------------------------------------------------------------|\n| 3: Ver goleiros menos vazados.                                                                 |\n|------------------------------------------------------------------------------------------------|\n| 4: Ver os resultados dos jogos até uma rodada.                                                 |\n|------------------------------------------------------------------------------------------------|\n| 5: Ver relatório final do campeonato.                                                          |\n|------------------------------------------------------------------------------------------------|\n| Digite um numero diferente de 1 a 5 para sair.                                                 |\n|------------------------------------------------------------------------------------------------|\n|Sua escolha: ");

    scanf("%d", &escolha);

    while (escolha >= 0 && escolha <= 5)
    {
        switch (escolha)
        {

        case 1: // chamada função que mostra a tabela final de classificação;
            printf("|------------------------------------------------------------------------------------------------|\n|                         TABELA FINAL DE CLASSIFICAÇÃO DO CAMPEONATO                            |\n");
            tabela_final(c, 20, nomeTime);
            break;

        case 2: // chamada função que mostra a tabela de artilheiros; ;
            printf("|------------------------------------------------------------------------------------------------|\n|                                  TABELA DE ARTILHEIROS                                         |\n");
            tabela_artilheiro(c, nomeTime, 5);
            break;

        case 3: // chamada função que mostra a tabela de goleiros menos vazados;
            printf("|------------------------------------------------------------------------------------------------|\n|                                  GOLEIROS MENOS VAZADOS                                        |\n");
            top_goleiros(c, nomeTime, 5);
            break;

        case 4: // chamada da função para imprimir o campeonato ate a rodada desejada
            do
            {
                printf("|------------------------------------------------------------------------------------------------|\n|Digite o numero da rodada desejada (1 a 19): ");
                scanf("%d", &rodada);
            }
            while (rodada < 1 || rodada > 19);
            if(rodada<10)
            {
                printf("|------------------------------------------------------------------------------------------------|\n|                         TABELA DOS RESULTADOS DOS JOGOS ATÉ A RODADA %d                         |\n",rodada);
            }
            else
            {
                printf("|------------------------------------------------------------------------------------------------|\n|                         TABELA DOS RESULTADOS DOS JOGOS ATÉ A RODADA %d                        |\n",rodada);

            }
            imprimir_campeonato(c, rodada, nomeTime);
            break;

        case 5: // chamada da função para relatório final do campeonagto
            relatorio_final(c, nomeTime);
            break;
        }

        printf("|------------------------------------------------------------------------------------------------|\n|                                     ESCOLHA UMA OPÇÃO:                                         |\n|------------------------------------------------------------------------------------------------|\n| 1: Ver tabela final de classificação.                                                          |\n|------------------------------------------------------------------------------------------------|\n| 2: Ver artilheiros do campeonato.                                                              |\n|------------------------------------------------------------------------------------------------|\n| 3: Ver goleiros menos vazados.                                                                 |\n|------------------------------------------------------------------------------------------------|\n| 4: Ver os resultados dos jogos até uma rodada.                                                 |\n|------------------------------------------------------------------------------------------------|\n| 5: Ver relatório final do campeonato.                                                          |\n|------------------------------------------------------------------------------------------------|\n| Digite um numero diferente de 1 a 5 para sair.                                                 |\n|------------------------------------------------------------------------------------------------|\n|Sua escolha: ");
        scanf("%d", &escolha);
    }

    printf("----------------------------------------------\nObrigado pela visita. :)\n----------------------------------------------\n");
}

