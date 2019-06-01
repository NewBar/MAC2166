/***************************************************************/
/**                                                           **/
/**   Gustavo Oliveira Barranova          10336661            **/
/**   Exercício-Programa 03                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MMAX 90
#define NMAX 90
#define TRUE 1
#define FALSE 0
/* Função que recebe uma matriz mxn e zera-a para não ficar com valores flutuantes. */
void ZERAMATRIZ (int M[MMAX][NMAX], int m, int n){
    int i, j;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            M[i][j] = 0;
    return;
}
/* Função que recebe uma matriz mxn e imprime-a já com a moldura. */
void IMPRIMEMATRIZ (char M[MMAX][NMAX], int m, int n){
    int i, j;
    printf("      1");
    for(j = 2; j<=n; j++) printf(" %2d", j);
    printf("\n");
    printf("   +");
    for(j = 1; j<=n; j++) printf("---");
    printf("-+");
    printf("\n");
    for (i = 1; i <= m; i++){
        printf("%2d |", i);
        for (j = 1; j <= n; j++){
            printf("  %c", M[i][j]);
        }
        printf(" |  %d", i);
        printf("\n");
    }
    printf("   +");
    for(j = 1; j<=n; j++) printf("---");
    printf("-+");
    printf("\n");
    printf("      1");
    for(j = 2; j<=n; j++) printf(" %2d", j);
    printf("\n");
}
/* Função que recebe uma matriz mxn e enche de pontos nela.*/
void FECHAMATRIZ (char M[MMAX][NMAX], int m, int n){
    int i, j;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            M[i][j] = '.' ;
    return;
}
/* Função que checa se existe algum zero aberto e continua varrendo a matriz até que não exista zero com a sua volta fechada.
Também conta quantas casas foram abertas e subtrai da variável livres.*/
void ABREEMVOLTA (char M[MMAX][NMAX], int N[MMAX][NMAX], int m, int n, int *livres){
    int b, c,
    contaponto; /* Conta quantos pontos foram abertos e faz sair do loop se for igual a zero. */
    do{
        contaponto = 0;
        for(b = 1; b <= m; b++)
            for(c = 1; c <= n; c++){
                if(M[b][c] == '0'){
                if(M[b-1][c-1] == '.' && b-1 >= 1 && c-1 >= 1){ M[b-1][c-1] = N[b-1][c-1] + 48; contaponto++;}
                if(M[b-1][c] == '.' && b-1 >= 1) {M[b-1][c] = N[b-1][c] + 48;contaponto++;}
                if(M[b-1][c+1] == '.' && b-1 >= 1 && c+1 <= n) {M[b-1][c+1] = N[b-1][c+1] + 48;contaponto++;}
                if(M[b][c+1] == '.' && c+1 <= n) {M[b][c+1] = N[b][c+1] + 48;contaponto++;}
                if(M[b+1][c+1] == '.' && b+1 <= m && c+1 <= n) {M[b+1][c+1] = N[b+1][c+1] + 48;contaponto++;}
                if(M[b+1][c] == '.' && b+1 <= m) {M[b+1][c] = N[b+1][c] + 48;contaponto++;}
                if(M[b+1][c-1] == '.' && b+1 <= m && c-1 >= 1) {M[b+1][c-1] = N[b+1][c-1] + 48;contaponto++;}
                if(M[b][c-1] == '.' && c-1 >= 1) {M[b][c-1] = N[b][c-1] + 48;contaponto++;}
                }
            }
        *livres -= contaponto;
    }while(contaponto != 0);
    return ;
}
/* Função que abre a matriz toda, substituindo a mina pela variavel x que pode ser * ou @ dependendo se o jogador ganha ou perde.
O 48 é devido a tabela ASCII contando o char como um inteiro. */
void ABREMATRIZ (char M[MMAX][NMAX], int N[MMAX][NMAX], int m, int n, char x){
    int i, j;
    for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++){
        if (N[i][j] == -1) M[i][j] = x;
        else M[i][j] = N[i][j] + 48;
    }
}
int main (){
    int m, n, mn, /* Número de linhas, colunas e número de casas da matriz, respectivamente. */
    z, /* Número de minas. */
    s, /* Semente */
    T[MMAX][NMAX], /* Matriz que guarda os valores reais. */
    i, j, /* Contadores para varrer matrizes. */
    numero, /* Gera o número aleatório. */
    k, /* Conta quantas minas há envolta de uma certa casa e adiona nela. */
    marca = 0, /* Conta quantas casas estão marcadas */
    livres, /* Mostra quantas casas livres o tabuleiro ainda possuí. */
    derrota, vitoria, /* Avisa se perdeu ou ganhou. */
    a /* Conta quantas minas já foram colocadas*/,
    b, c /* Para inserir minas */ ;
    char comando, /* Guarda o comando (a, d ou m). */
    I[MMAX][NMAX]; /* Matriz que imprime o tabuleiro. */
    do{
        printf ("De o numero de linhas do tabuleiro: ");
        scanf ("%d", &m);
    } while (m < 3 || m > MMAX);
    do{
        printf ("De o numero de colunas do tabuleiro: ");
        scanf ("%d", &n);
    } while (n < 3 || n > NMAX);
    mn = m*n;
    livres = m*n;
    do{
        printf ("De o numero de minas: ");
        scanf ("%d", &z);
    } while (z < 1 || z >= (m*n));
    do{
        printf ("De a semente: ");
        scanf ("%d", &s);
    } while (s < 1 || s > 65535);
    printf ("Numero de linhas (3 <= m <= 90): %d\n", m);
    printf ("Numero de colunas (3 <= n <= 90): %d\n", n);
    printf ("Numero de minas (1 <= z < %d): %d\n", mn, z);
    printf ("Semente (1 <= s <= 65535): %d\n", s);
    printf ("Bem vindo ao BuscaMinas!\n");
    FECHAMATRIZ( I, m, n);
    IMPRIMEMATRIZ (I, m, n);
    ZERAMATRIZ (T, m, n);
    printf ("\nProximo chute: ");
    scanf (" %c %d %d", &comando, &i, &j);
    /* Faz com que o primeiro comando seja para abrir independente do que ele digita. */
    if(comando == 'm' || comando == 'M' || comando == 'd' || comando == 'D') comando = 'a';
    srand (s);
    /* Insere as minas. */
    for(a = 0; a < z; a++){
        do{
            numero = rand();
            b = numero % m + 1;
            c = (numero / m) % n + 1;
        } while((b == i && c == j) || T[b][c] == -1 );
        T[b][c] = -1;
    }
    /* Coloca os valores de quantas minas tem em volta de cada casa. */
    for(b = 1; b <= m; b++)
        for(c = 1; c <= n; c++){
            k = 0;
            if (T[b][c] != -1){
                if(T[b-1][c-1] == -1 && b-1 >= 1 && c-1 >= 1) k++;
                if(T[b-1][c] == -1 && b-1 >= 1) k++;
                if(T[b-1][c+1] == -1 && b-1 >= 1 && c+1 <= n) k++;
                if(T[b][c+1] == -1 && c+1 <= n) k++;
                if(T[b+1][c+1] == -1 && b+1 <= m && c+1 <= n) k++;
                if(T[b+1][c] == -1 && b+1 <= m) k++;
                if(T[b+1][c-1] == -1 && b+1 <= m && c-1 >= 1) k++;
                if(T[b][c-1] == -1 && c-1 >= 1) k++;
                T[b][c] = k;
            }
        }
    derrota = FALSE;
    vitoria = FALSE;
    /* Continua o loop enquanto o jogador não tiver ganho ou perdido. */
    do{
    /* Abre a casa desejada.*/
        if (comando == 'a' || comando == 'A'){
            if (I[i][j] == '*' || I[i][j] == '.'){
                if (T[i][j] == -1 ) {
                    derrota = TRUE;
                }
                I[i][j] = T[i][j] + 48;
                livres--;
                ABREEMVOLTA (I, T, m, n, &livres);
                if (livres <= (z - marca) && derrota == FALSE) {
                    vitoria = TRUE;
                }

            }
            else {
                printf("Sem efeito.\n");
                goto PULAMATRIZ; /* Vai para PULAMATRIZ para não ter que imprimir a matriz de novo. */
            }
        }
        /* Marca a casa desejada. */
        if (comando == 'm' || comando == 'M'){
            if(I[i][j] == '.' && marca != z){
                I[i][j] = '*';
                marca++;
                livres--;
            }
            else {
                printf("Sem efeito.\n");
                goto PULAMATRIZ; /* Vai para PULAMATRIZ para não ter que imprimir a matriz de novo. */
            }
        }
        /* Desmarca a casa desejada. */
        if (comando == 'd' || comando == 'D'){
            if(I[i][j] == '*'){
                I[i][j] = '.';
                marca--;
                livres++;
        }
            else {
                printf("Sem efeito.\n");
                goto PULAMATRIZ; /* Vai para PULAMATRIZ para não ter que imprimir a matriz de novo. */
            }
        }
        /* Imprime a matriz pedindo o próximo comando apenas se o jogando ainda não tiver ganho nem perdido. */
        if (derrota == FALSE && vitoria == FALSE){
            printf("Por enquanto: %d/%d marcadas, %d livres.\n", marca, z, livres);
            IMPRIMEMATRIZ (I, m, n);
            PULAMATRIZ:
            printf ("\nProximo chute: ");
            scanf (" %c %d %d", &comando, &i, &j);
        }
    }while (derrota == FALSE && vitoria == FALSE);
    /* Se o jogador perder imprime o tabuleiro com as minas em forma de "@" */
    if(derrota == TRUE){
        printf("BOOOOM! Voce acaba de pisar numa mina!\n");
        ABREMATRIZ(I, T, m, n, '@');
    }
    /* Se o jogador ganhar imprime o tabuleiro com as minas em forma de "*" */
    if(vitoria == TRUE){
        printf("Parabens! Voce encontrou todas as minas!\n");
        ABREMATRIZ(I, T, m, n, '*');
    }
    IMPRIMEMATRIZ (I, m, n);
    return 0;
}
