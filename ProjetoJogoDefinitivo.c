#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // inicializa aleatoriedade

    int opcao;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Pergunta e Resposta\n");
        printf("2 - Cobra na Caixa\n");
        printf("3 - Gousmas War\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        
        // JOGO 1
        
        if (opcao == 1) {
            int resposta, acertos, jogar;

            do {
                
				acertos = 0;
      
                printf("\n1) Maior pais?\n1-Canada 2-China 3-USA 4-Russia\n");
                scanf("%d", &resposta);
                if (resposta == 4) { printf("Correto!\n"); acertos++; }
                else printf("Errado!\nA resposta correta era 4. Russia\n");

                printf("\n2) Qunato e 7*8?\n1-54 2-56 3-64 4-48\n");
                scanf("%d", &resposta);
                if (resposta == 2) { printf("Correto!\n"); acertos++; }
                else printf("Errado!\nA resposta correta era 2. 56\n");

                printf("\n3) Qual o gas essencial para os humanos?\n1-Carbonico 2-Nitrogenio 3-Oxigenio 4-Hidrogenio\n");
                scanf("%d", &resposta);
                if (resposta == 3) { printf("Correto!\n"); acertos++; }
                else printf("Errado!\nA resposta correta era 3. Oxigenio\n");

                printf("\n4) Qual o autor de Dom Casmurro?\n1-Jose 2-Machado 3-Clarice 4-Lobato\n");
                scanf("%d", &resposta);
                if (resposta == 2) { printf("Correto!\n"); acertos++; }
                else printf("Errado!\nA resposta correta era 2. Machado");

                printf("\n5) Qual o maior oceano?\n1-Pacifico 2-Atlantico 3-Artico 4-Indico\n");
                scanf("%d", &resposta);
                if (resposta == 1) { printf("Correto!\n"); acertos++; }
                else printf("Errado!\nA resposta correta era 1. Pacifico");

                printf("\nAcertos: %d/5\n", acertos);

                printf("\n1-Jogar novamente\n2-Menu\n");
                scanf("%d", &jogar);

            } while (jogar == 1);
        }

        
        // JOGO 2
        
        if (opcao == 2) {

            int jogar;

            do{
				int botao = 1 + (rand() % 5);
                int cobra;

                do {
                    cobra = 1 + (rand() % 5);
                } while (cobra == botao);

                int abertas[5] = {0};
                int jogador = 1;
                int escolha;
                int fim = 0;

                printf("\nJogo iniciado!\n");

                do {
                    printf("\nJogador %d - escolha (1-5): ", jogador);
                    scanf("%d", &escolha);

                    if (escolha < 1 || escolha > 5 || abertas[escolha-1]) {
                        printf("Escolha invalida!\n");
                    } else {
                        abertas[escolha-1] = 1;

                        if (escolha == botao) {
                            printf("Jogador %d VENCEU!\n", jogador);
                            fim = 1;
                        }
                        else if (escolha == cobra) {
                            printf("Jogador %d PERDEU!\n", jogador);
                            fim = 1;
                        }
                        else {
                            printf("Vazia!\n");
                            jogador = (jogador == 1) ? 2 : 1;
                        }
                    }

                } while (!fim);

                printf("\n1-Jogar novamente\n2-Menu\n");
                scanf("%d", &jogar);

            } while (jogar == 1);
        }

        
        // JOGO 3
        
        if (opcao == 3) {

            int jogar;

            do {

				int j1Hl = 1, j1Hr = 1;
                int j2Hl = 1, j2Hr = 1;
                int turno = 1;
                int acao, escolha, alvo, valor;
                int fim = 0;

                do {
                    printf("\nJogador %d\n", turno);
                    printf("J1: [%d %d] | J2: [%d %d]\n", j1Hl, j1Hr, j2Hl, j2Hr);

                    printf("1-Atacar 2-Dividir: ");
                    scanf("%d", &acao);

                    if (acao == 1) {
                        printf("Escolha hand (1 ou 2): ");
                        scanf("%d", &escolha);

                        printf("Alvo (1 ou 2): ");
                        scanf("%d", &alvo);

                        if (turno == 1) {
                            int atk = (escolha == 1 ? j1Hl : j1Hr);
                            if (alvo == 1) j2Hl += atk;
                            else j2Hr += atk;
                            if (j2Hl > 5) j2Hl = 0;
                            if (j2Hr > 5) j2Hr = 0;
                        } else {
                            int atk = (escolha == 1 ? j2Hl : j2Hr);
                            if (alvo == 1) j1Hl += atk;
                            else j1Hr += atk;
                            if (j1Hl > 5) j1Hl = 0;
                            if (j1Hr > 5) j1Hr = 0;
                        }
                    }

                    if (acao == 2) {
                        printf("Escolha hand: ");
                        scanf("%d", &escolha);

                        printf("Valor: ");
                        scanf("%d", &valor);

                        if (turno == 1) {
                            if (escolha == 1 && j1Hl > valor) {
                                j1Hl -= valor;
                                j1Hr += valor;
                            }
                            if (escolha == 2 && j1Hr > valor) {
                                j1Hr -= valor;
                                j1Hl += valor;
                            }
                        } else {
                            if (escolha == 1 && j2Hl > valor) {
                                j2Hl -= valor;
                                j2Hr += valor;
                            }
                            if (escolha == 2 && j2Hr > valor) {
                                j2Hr -= valor;
                                j2Hl += valor;
                            }
                        }
                    }

                    if (j1Hl == 0 && j1Hr == 0) {
                        printf("\nJogador 2 venceu!\n");
                        fim = 1;
                    }

                    if (j2Hl == 0 && j2Hr == 0) {
                        printf("\nJogador 1 venceu!\n");
                        fim = 1;
                    }

                    turno = (turno == 1) ? 2 : 1;

                } while (!fim);

                printf("\n1-Jogar novamente\n2-Menu\n");
                scanf("%d", &jogar);

            } while (jogar == 1);
        }

    } while (opcao != 4);

    printf("\nEncerrado.\n");

    getchar();
    getchar();

    return 0;
}