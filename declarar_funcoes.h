#ifndef DECLARAR_FUNCOES
#define DECLARAR_FUNCOES
#include "camp_structs.h"

void inicializa_nome(struct NomeTime *nomeTime);
void inicializa_nome_jogadores(struct NomeTime *nomeTime);
void gera_campeonato(struct Campeonato *c);
void gera_gols(struct Campeonato *c);
void distribui_gols_jogadores(struct Campeonato *c);
void menu(struct Campeonato *c, struct NomeTime *nomeTime);

#endif // DECLARAR_FUNCOES
