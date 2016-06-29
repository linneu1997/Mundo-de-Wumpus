#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <conio.h>

int getGraph(int lin, int col, int i, int j, int arr, int pontos, int passos, char A[15])
    {
    for (int y = 0; y != lin; y++)
    {
        for (int x = 0; x != col; x++)
        {
            if (i == x && j == y)
            {
                printf(" * ");
            }
            else
            {
                printf(" 0 ");
            }
        }
        printf("\n");
    }
printf("\n");
			printf("================================================================================");
			printf(" ||b  -> Brisa fraca   c  -> Cheiro fraco  L  -> Tesouro  M  -> Monstro Wumpus||\n");
			printf("||bB -> Brisa media   cC -> Cheiro medio   A  -> Abismo   D  -> Monstro Morto ||\n");
			printf("||B  -> Brisa forte   C  -> Cheiro forte      -> Nada                         ||\n");
			printf("================================================================================\n");
			printf("PASSOS: %5d      PONTOS: %5d      FLECHAS: %5d\n\n",passos, pontos, arr);
            printf("          |UP|               ACOES:\n");
			printf("          (8)               (1) -> Andar\n");
			printf(" |LEFT| (4)+(6) |RIGHT|     (2) -> Checar\n");
			printf("          (2)               (3) -> Atirar\n");
			printf("         |DOWN|\n\n");
			printf("Voce sente: %s\n", A);
    return 0;
}

int main()
{
    //contadores para os fors
    int i, j;

    //nome do arquivo
    char *url = 0;
    url = (char*) malloc(10 * sizeof(char));
    url = "matriz.txt";

    //"r" é o modo que vai abrir o arquivo
    FILE *arquivo = fopen(url, "r");

    //le o numero de linhas e colunas
    int linhas, colunas;
    fscanf(arquivo, "%d", &linhas);
    fscanf(arquivo, "%d", &colunas);
    fgetc(arquivo);

    //cria a matriz no tamanho certo
    char *matriz[linhas][colunas];

    //cria um char e um contador pra usar no for abaixo
    char c;
    int contador = 0;

    //le o arquivo e preenche a matriz
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            matriz[i][j] = (char *) malloc(0);
            do
            {
                c = fgetc(arquivo);
                matriz[i][j] = (char *) realloc(matriz[i][j], contador + 1);
                matriz[i][j][contador++] = c;
            }
            while (c != 10);
            matriz[i][j][contador - 1] = '\0';
            contador = 0;
        }
    }

    //libera a memoria do url e fecha o arquivo
    fclose(arquivo);

    int t = 0, s = 0, mov, chec, flec, arrow = 1, escolha, T, S;
    int titulo;
    int passos1, passos2;
    int score = 0;
    for (titulo = 0; titulo < 45; titulo++)
        printf ("*");
    printf("\n");
    for (titulo = 0; titulo < 45; titulo++)
        printf ("*");
    printf ("\n* ==   = ==  == ==   = ====   ==  == ====== *");
    printf ("\n* ==   = ==  == === == ==  =  ==  == ==     *");
    printf ("\n* == = = ==  == == = = ====   ==  == ====== *");
    printf ("\n* === == ====== ==   = ==     ======     == *");
    printf ("\n* ==   = ====== ==   = ==     ====== ====== *\n");
    for (titulo = 0; titulo < 45; titulo++)
        printf ("*");
    printf("\n");
    for (titulo = 0; titulo < 45; titulo++)
        printf ("*");
    printf ("\n\n");
    system("pause");
    char A[15];
    int menu = 0;
    while (menu != 2)
    {
        printf ("\n===menu===\n");
        printf ("pressione 1 para ver as instrucoes\n");
        printf ("pressione 2 para jogar\n");
        scanf ("%d", &menu);
        if (menu == 1)
        {
            printf ("Seja bem vindo ao mundo de Wumpus, um lugar cheio de misterios, aventuras, \nperigo e tesouros... Ou so um trabalho de ICC. Aqui voce deve buscar pelo grande\ntesouro, mas cuidado, profundos abismos e um temivel monstro lhe aguardam!\n\n");
            //troar o x pelo numero de movimentos na linha abaico!
            printf ("Objetivo do jogo: Para ganhar voce deve chegar ao tesouro, mas cuidado, se cair em um abismo, encontrar o Wumpus ou realizar mais que %d movimentos, voce perde.\n", linhas*colunas);
            printf ("Voce pode saber se esta perto de um abismo ou do monstro a partir da sensacao debrisas e do cheiro da seguinte maneira:\n");
            printf ("brisa fraca: abismo a 3 casas de voce   cheiro fraco: monstro a 3 casas de voce\nbrisa media: abismo a 2 casas de voce   cheiro medio: monstro a 2 casas de voce\nbrisa forte: abismo a 1 casa de voce    cheiro forte: monstro a 1 casa de voce\n\n");
            printf ("Como jogar:\nQuando perguntado sua acao, pressione\n 1: andar\n 2: olhar\n 3: atirar\nDepois selecione a direcao na qual voce vai realizar tal acao da seguinte\nmaneira:\n 2: para baixo\n 4: para a esquerda\n 8: para cima\n 6: para direita.\n\n");
            printf ("Lembre-se: Voce possui apenas uma flecha para atirar e matar o monstro\n");
            printf ("pressione 2 para jogar\n");
            scanf ("%d", &menu);
            system("cls");
        }
    }
    if (menu == 2)
    {
        passos1 = linhas*colunas;
        while (strcmp(matriz[t][s], "L ") != 0 && strcmp(matriz[t][s], "M ") != 0 && strcmp(matriz[t][s], "A ") != 0 && passos1 != 0)
        {
            system("cls");
            getGraph(linhas, colunas, s, t, arrow, score, passos1, matriz[t][s]);
            printf ("O que voce quer fazer?\n");
            scanf("%d", &escolha);
            if (escolha == 1)
            {
                printf ("para que direcao voce quer se mover?\n");
                scanf("%d", &mov);
                if (mov == 8)
                {
                    if (t - 1 < 0)
                    {
                        printf("MOVIMENTO INVALIDO!\n");
                    }
                    else
                    {
                        t--;
                    }
                }
                if (mov == 2)
                {
                    if (t + 1 > linhas)
                    {
                        printf("MOVIMENTO INVALIDO!\n");
                    }
                    else
                    {
                        t++;
                    }
                }
                if (mov == 4)
                {
                    if (s + 1 < 0)
                    {
                        printf("MOVIMENTO INVALIDO!\n");
                    }
                    else
                    {
                        s--;
                    }
                }
                if (mov == 6)
                {
                    if (s + 1 > colunas)
                    {
                        printf("MOVIMENTO INVALIDO!\n");
                    }
                    else
                    {
                        s++;
                    }
                }
                passos1--;
                score--;
            }
            if (escolha == 2)
            {
                printf ("qual direcao voce quer olhar?\n");
                scanf("%d", &chec);
                if (chec == 8)
                {
                    if (t-1 < 0)
                    {
                        printf("Uma parede!\n");
                    }
                    else
                    {
                        if (strcmp(matriz[t-1][s], "M ") == 0 || strcmp(matriz[t-1][s], "A ") == 0)
                        {
                            t--;
                        }
                        else
                        {
                            printf("Voce percebe: %s", matriz[t-1][s]);
                        }
                    }
                }
                if (chec == 2)
                {
                    if (t+1 > linhas)
                    {
                        printf("Uma parede!\n");
                    }
                    else
                    {
                        if (strcmp(matriz[t+1][s], "M ") == 0 || strcmp(matriz[t+1][s], "A ") == 0)
                        {
                            t++;
                        }
                        else
                        {
                            printf("Voce percebe: %s", matriz[t+1][s]);
                        }
                    }
                }
                if (chec == 4)
                {
                    if (s-1 < 0)
                    {
                        printf("Uma parede!\n");
                    }
                    else
                    {
                        if (strcmp(matriz[t][s-1], "M ") == 0 || strcmp(matriz[t][s-1], "A ") == 0)
                        {
                            s--;
                        }
                        else
                        {
                            printf("Voce percebe: %s", matriz[t][s-1]);
                        }
                    }
                }
                if (chec == 6)
                {
                    if (s+1 > colunas)
                    {
                        printf("Uma parede!\n");
                    }
                    else
                    {
                        if (strcmp(matriz[t][s+1], "M ") == 0 || strcmp(matriz[t][s+1], "A ") == 0)
                        {
                        }
                        else
                        {
                            printf("Voce percebe: %s", matriz[t][s+1]);
                        }
                    }
                }
                score--;
            }
            if (escolha == 3)
            {
                if (arrow == 1)
                {
                    printf ("para qual lado voce vai atirar?\n");
                    scanf("%d", &flec);
                    if (flec == 8)
                    {
                        if (strcmp(matriz[t-1][s], "M ") == 0)
                        {
                            printf("Voce matou Wumpus.\n");
                            strcpy(matriz[t-1][s], "D");
                            score += 10000;
                        }
                        else
                        {
                            printf("Nao havia monstro ai.\n");
                        }
                    }
                    if (flec == 2)
                    {
                        if (strcmp(matriz[t+1][s], "M ") == 0)
                        {
                            printf("Voce matou Wumpus.\n");
                            strcpy(matriz[t+1][s], "D");
                            score += 10000;
                        }
                        else
                        {
                            printf("Nao havia monstro ai.\n");
                        }
                    }
                    if (flec == 4)
                    {
                        if (strcmp(matriz[t][s-1], "M ") == 0)
                        {
                            printf("Voce matou Wumpus.\n");
                            strcpy(matriz[t][s-1], "D");
                            score += 10000;
                        }
                        else
                        {
                            printf("Nao havia monstro ai.\n");
                        }
                    }
                    if (flec == 6)
                    {
                        if (strcmp(matriz[t][s+1], "M ") == 0)
                        {
                            printf("Voce matou Wumpus.\n");
                            strcpy(matriz[t][s+1], "D");
                            score += 10000;
                        }
                        else
                        {
                            printf("Nao havia monstro ai.\n");
                        }
                    }
                }
                else
                {
                    printf("SEM FLECHAS!\n");
                }
                arrow--;
            }
            passos2 = passos1;
            system("pause");
        }

    if (strcmp(matriz[t][s], "L ") == 0)
    {
        printf ("Parabens! Voce achou o tesouro! Consegue agora achar a saida?\n");
        score += 1000;
    }
    while ((t+s != 0) && strcmp(matriz[t][s], "M ") != 0 && strcmp(matriz[t][s], "A ") != 0 && passos2!=0)
    {
        system("cls");
        getGraph(linhas, colunas, s, t, arrow, score, passos2, matriz[t][s]);
        printf ("O que voce quer fazer?\n");
        scanf("%d", &escolha);
        if (escolha == 1)
        {
            printf ("para que direcao voce quer se mover?\n");
            scanf("%d", &mov);
            if (mov == 8)
            {
                if (t - 1 < 0)
                {
                    printf("MOVIMENTO INVALIDO!\n");
                }
                else
                {
                    t--;
                }
            }
            if (mov == 2)
            {
                if (t + 1 > linhas)
                {
                    printf("MOVIMENTO INVALIDO!\n");
                }
                else
                {
                    t++;
                }
            }
            if (mov == 4)
            {
                if (s + 1 < 0)
                {
                    printf("MOVIMENTO INVALIDO!\n");
                }
                else
                {
                    s--;
                }
            }
            if (mov == 6)
            {
                if (s + 1 > colunas)
                {
                    printf("MOVIMENTO INVALIDO!\n");
                }
                else
                {
                    s++;
                }
            }
            passos1--;
            score--;
        }
        if (escolha == 2)
        {
            printf ("qual direcao voce quer olhar?\n");
            scanf("%d", &chec);
            if (chec == 8)
            {
                if (t-1 < 0)
                {
                    printf("Uma parede!\n");
                }
                else
                {
                    if (strcmp(matriz[t-1][s], "M ") == 0 || strcmp(matriz[t-1][s], "A ") == 0)
                    {
                        t--;
                    }
                    else
                    {
                        printf("Voce percebe: %s", matriz[t-1][s]);
                    }
                }
            }
            if (chec == 2)
            {
                if (t+1 > linhas)
                {
                    printf("Uma parede!\n");
                }
                else
                {
                    if (strcmp(matriz[t+1][s], "M ") == 0 || strcmp(matriz[t+1][s], "A ") == 0)
                    {
                        t++;
                    }
                    else
                    {
                        printf("Voce percebe: %s", matriz[t+1][s]);
                    }
                }
            }
            if (chec == 4)
            {
                if (s-1 < 0)
                {
                    printf("Uma parede!\n");
                }
                else
                {
                    if (strcmp(matriz[t][s-1], "M ") == 0 || strcmp(matriz[t][s-1], "A ") == 0)
                    {
                        s--;
                    }
                    else
                    {
                        printf("Voce percebe: %s", matriz[t][s-1]);
                    }
                }
            }
            if (chec == 6)
            {
                if (s+1 > colunas)
                {
                    printf("Uma parede!\n");
                }
                else
                {
                    if (strcmp(matriz[t][s+1], "M ") == 0 || strcmp(matriz[t][s+1], "A ") == 0)
                    {
                    }
                    else
                    {
                        printf("Voce percebe: %s", matriz[t][s+1]);
                    }
                }
            }
            score--;
        }
        if (escolha == 3)
        {
            if (arrow == 1)
            {
                printf ("para qual lado voce vai atirar?\n");
                scanf("%d", &flec);
                if (flec == 8)
                {
                    if (strcmp(matriz[t-1][s], "M ") == 0)
                    {
                        printf("Voce matou Wumpus.\n");
                        strcpy(matriz[t-1][s], "D");
                        score += 10000;
                    }
                    else
                    {
                        printf("Nao havia monstro ai.\n");
                    }
                }
                if (flec == 2)
                {
                    if (strcmp(matriz[t+1][s], "M ") == 0)
                    {
                        printf("Voce matou Wumpus.\n");
                        strcpy(matriz[t+1][s], "D");
                        score += 10000;
                    }
                    else
                    {
                        printf("Nao havia monstro ai.\n");
                    }
                }
                if (flec == 4)
                {
                    if (strcmp(matriz[t][s-1], "M ") == 0)
                    {
                        printf("Voce matou Wumpus.\n");
                        strcpy(matriz[t][s-1], "D");
                        score += 10000;
                    }
                    else
                    {
                        printf("Nao havia monstro ai.\n");
                    }
                }
                if (flec == 6)
                {
                    if (strcmp(matriz[t][s+1], "M ") == 0)
                    {
                        printf("Voce matou Wumpus.\n");
                        strcpy(matriz[t][s+1], "D");
                        score += 10000;
                    }
                    else
                    {
                        printf("Nao havia monstro ai.\n");
                    }
                }
            }
            else
            {
                printf("SEM FLECHAS!\n");
            }
            arrow--;
        }
        system("pause");
    }

if (strcmp(matriz[t][s], "M ") == 0)
{
    printf ("WUMPUS! Voce morreu!\nGAME OVER\n");
    score -= 10000;
}
if (strcmp(matriz[t][s], "A ") == 0)
{
    printf ("AAAAAAHHHHHH! Um abismo. Voce morreu!\nGAME OVER\n");
    score -=10000;
}
if (t+s == 0)
{
    printf ("Voce achou a saida! E so te custou uma perna!\n Parabens, voce venceu!\n");
    score += 1000;
}
if (passos1 == 0)
{
    printf("Oh nao, voce esta muito cansado para continuar!\nGAME OVER\n");
}
printf ("Sua pontuacao foi de %d pontos\n", score);
}

//no final deixe essa função para liberar a memoria:
for (i = 0; i < linhas; i++)
{
    for (j = 0; j < colunas; j++)
    {
        free(matriz[i][j]);
    }
}

return 0;
}
