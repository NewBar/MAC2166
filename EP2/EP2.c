/***************************************************************/
/**                                                           **/
/**   Gustavo Oliveira Barranova          10336661            **/
/**   Exerc�cio-Programa 02                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
#define TRUE 1
#define FALSE 0
/* Fun��o que calcula o m�dulo de um n�mero (se for negativo retorna menos ele. */
double fabs (double x) {
    if (x < 0) x = -x;
    return x;
}
/* Fun��o que devolve a parte inteira do n�mero real (obs: aparece um warning em rela��o ao floor mas n�o estou usando a biblioteca math.h). */
int floor (double x) {
    x=(int)x;
    return x;
}
/* Fun��o que l� dois n�meros inteiros "x" e "e" retorna x^e. */
int pot (int x, int e) {
    int i, p = 1;
    for(i = 1; i <= e; i++) {
        p *= x;
    }
    return p;
}
/* Fun��o que calcula um fatorial de um n�mero */
int fat (int x) {
    int i, f = 1;
    for (i = 1; i <= x; i++){
        f *= i;
    }
    return f;
}
/* Fun��o que calcula o seno de um n�mero em radianos atrav�s do polin�mio de taylor. */
double sen (double x) {
    double soma1,
    soma2; /* Guarda o valor da soma anterior */
    int i = 1,
    um = -1; /* Essa v�riavel serve para inverter o sinal de cada opera��o devido ao polin�mio. */
    soma1 = x;
    soma2 = 0;
    while ( fabs(soma1-soma2) >= 0.00000001) {
        soma2 = soma1;
        soma1 += um*(double)pot(x,2*i+1)/fat(2*i+1);
        um *= -1;
        i++;
    }
    return soma1;
}
int main() {
    double caixa, teto, rifa, carta,
           soma1, /* Soma das cartas do apostador. */
           soma2; /* Soma das cartas da m�quina */
    int i, /* Contador para a realiza��o de 100 testes. */
        j, /* Conta o n�mero de cartas do apostador. */
        k, /* Conta o n�mero de cartas da m�quina. */
        l, /* Conta o n�mero de "*" */
        derrota; /* Conta o n�mero de derrotas da m�quina (vit�rias do apostador) */
    printf ("Digite o valor inicial da caixa:");
    scanf ("%lf", &caixa);
    /* Depois de lido um valor inicial para caixa, trasforma-o em um n�mero menor que 1. */
    while (caixa >= 1) {
        caixa /= 10;
    }
    /* Realiza um la�o para cada teto de meio em meio. */
    for(teto = 0; teto <= 7.5; teto+=0.5) {
        derrota = 0;
        /* Realiza 100 la�os com o mesmo teto */
        for (i = 1; i <= 100; i++){
            k = 0;
            j=0;
            soma1 = 0;
            soma2 = 0;
            /* Realiza esse la�o enquanto soma1(soma do apostador) for menor que seu teto, comprando e somando as cartas necess�rias. */
            while(soma1 < teto) {
                rifa = ( 9821.0 * fabs(sen(caixa)) ) + 0.211327;
                caixa = rifa - floor(rifa);
                carta = floor( caixa*10 + 1);
                if (carta == 1) soma1 += 1;
                if (carta == 2) soma1 += 2;
                if (carta == 3) soma1 += 3;
                if (carta == 4) soma1 += 4;
                if (carta == 5) soma1 += 5;
                if (carta == 6) soma1 += 6;
                if (carta == 7) soma1 += 7;
                if (carta == 8 || carta == 9 || carta == 10) soma1 += 0.5;
                j++;
            }
            /* Roda o la�o somente se o apostador n�o tiver estourado(soma1 > 7.5), fazendo com que a m�quina at� ganhar ou n�o possuir chance de ganhar. */
            if(soma1 <= 7.5) {
                while(soma2 <= soma1 && soma2 < 7.5) {
                    rifa = ( 9821.0 * fabs(sen(caixa)) ) + 0.211327;
                    caixa = rifa - floor(rifa);
                    carta = floor( caixa*10 + 1);
                    if (carta == 1) soma2 += 1;
                    if (carta == 2) soma2 += 2;
                    if (carta == 3) soma2 += 3;
                    if (carta == 4) soma2 += 4;
                    if (carta == 5) soma2 += 5;
                    if (carta == 6) soma2 += 6;
                    if (carta == 7) soma2 += 7;
                    if (carta == 8 || carta == 9 || carta == 10) soma2 += 0.5;
                    k++;
                }
            }
            /* Confere os resultados caso o apostador n�o tenha estourado. */
            /* Apostador ganha caso sua soma seja maior que a da m�quina ou quando for igual possuir menor numero de cartas ou quando a m�quina estourar. */
            if(soma1 <= 7.5){
                if(soma1 > soma2) derrota++;
                if(soma1 == soma2 && j < k ) derrota++;
                if(soma2 > 7.5) derrota ++;
            }
        }
        printf("%.1f  %d ", teto, derrota);
        l=0;
        /* Coloca os "*" referente ao n�mero de derrotas. */
        while(l< derrota){
            printf("*");
            l++;
        }
        printf("\n");
    }
    return 0;
}
