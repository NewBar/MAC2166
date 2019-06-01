/***************************************************************/
/**                                                           **/
/**   Gustavo Oliveira Barranova          10336661            **/
/**   Exercício-Programa 01                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
int main() {
    int cem, cinq, dez, cinco, um,  /* Guarda a quantidade atual de cada nota */
    op,                             /* Numero de operacoes a realizar */
    cont,                           /* Contador */
    sd,                             /* Tipo de operacao */
    saque,                          /* Inicialmente guarda o quanto ira sacar */
    scem, scinq, sdez, scinco, sum, /* Guarda quantas notas de cada se sacou */
    cem2, cinq2, dez2, cinco2, um2, /* Guarda a quantidade de notas anterior */
    dcem, dcinq, ddez, dcinco, dum; /* Quantidade de notas a depositar */
    printf ("Digite a quantidade inicial de notas de 100, 50, 10, 5 e 1 ducas:\n");
    scanf ("%d", &cem);scanf("\n%d", &cinq);scanf("\n%d", &dez);scanf("\n%d", &cinco);scanf("\n%d", &um);
    printf ("Quantas operacoes deseja realizar?\n");
    scanf ("%d", &op);
    cont = 1;
    /* Roda ate que o cont se iguale a quantidade de op  */
    while (cont <= op) {
        printf ("\n\nQual operacao deseja efetuar? (0=saque, 1=deposito)\n");
        scanf ("%d", &sd);
            /* Roda caso seja selecionado o modo saque */
            if (sd == 0) {
            printf ("Quantos ducas deseja sacar?\n");
            scanf ("%d", &saque);
            if (saque > 0) {
                cem2 = cem, cinq2 = cinq, dez2 = dez, cinco2 = cinco, um2 = um;
                scem = 0, scinq = 0, sdez = 0, scinco = 0, sum = 0;
                /* Cada while verifica se é possível subtrair tal quantia sem que o saque fique menor que 0, implementa o numero de notas utilizadas e verifica se existem notas disponiveis*/
                while (cem > 0 && (saque-100) >= 0) {
                    scem++;
                    saque -= 100 , cem--;
                }
                while (cinq > 0 && (saque-50) >= 0) {
                    scinq++;
                    saque -= 50 , cinq--;
                }
                while (dez > 0 && (saque-10) >= 0) {
                    sdez++;
                    saque -= 10 , dez--;
                }
                while (cinco > 0 && (saque-5) >= 0) {
                    scinco++;
                    saque -= 5 , cinco--;
                }
                while (um > 0 && (saque-1) >= 0) {
                    sum++;
                    saque -= 1 , um--;
                }
                /* Caso nao haja notas suficiente, retorna o valor anterior da quantidade de notas */
                if (saque > 0) {
                    printf ("Saque nao efetuado!\n");
                    cem = cem2, cinq = cinq2, dez = dez2, cinco = cinco2, um = um2;
                    printf ("Notas disponiveis: %d %d %d %d %d\n", cem, cinq, dez, cinco, um);
                }
                /* Caso haja notas suficientes mostra o saque e quantas notas sobraram */
                if (saque == 0) {
                    printf ("Saque efetuado: %d %d %d %d %d\n", scem, scinq, sdez, scinco, sum);
                    printf ("Notas disponiveis: %d %d %d %d %d\n", cem, cinq, dez, cinco, um);
                }
            }
        }
        /* Roda caso seja selecionado o modo deposito e adiciona a quantidade depositada ao numero de notas */
        if (sd == 1) {
            printf ("Digite a quantidade de notas de 100, 50, 10, 5 e 1 ducas sendo depositadas:\n");
            scanf ("\n%d", &dcem);scanf("\n%d", &dcinq);scanf("\n%d", &ddez);scanf("\n%d", &dcinco);scanf("\n%d", &dum);
            cem += dcem, cinq += dcinq, dez += ddez, cinco += dcinco, um += dum;
            printf ("Deposito efetuado!");
            printf ("\nNotas disponiveis: %d %d %d %d %d\n", cem, cinq, dez, cinco, um);
        }
        cont++;
    }
    return 0;
}
