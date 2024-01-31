#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "camp_structs.h"
#include "declarar_funcoes.h"

// função para dexar em negrito
void bold(int status)
{
    static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
    printf("%s", seq[!!status]);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Campeonato c;
    struct NomeTime nomeTime[20];

    system("color 2F");//deixando o fundo verde
    // atualizando o nome dos times
    inicializa_nome(nomeTime);
    inicializa_nome_jogadores(nomeTime);

    // Inicializa a semente para números aleatórios
    srand(time(NULL));


    gera_campeonato(&c);
    gera_gols(&c);
    distribui_gols_jogadores(&c);
    menu(&c, nomeTime);

    // imprimir_campeonato(&c);

    return 0;
}

