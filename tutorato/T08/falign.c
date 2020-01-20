#include <stdio.h>
#include <stdlib.h>

void falign(FILE  * infile, FILE * outfile, int maxcol)
{
    char ch;
    int col = 0;

    while ((ch = getc(infile)) != EOF) {  /* controlla se c'è un carattere diverso dall'errore */
        if (ch == '\n') {/*controlla se il carattare è uguale all'andata a capo */
          putc(' ', outfile); /*stampa uno spazio sul file outfile */
        } else
          putc(ch, outfile);  /* se è diverso da \n stampa il carattere su outfile */
          ++col;

        if (col >= maxcol){
            putc('\n', outfile);
            col = 0;
        }
     }
     putc('\n', outfile);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    int maxcol;

    if (argc != 3){
        printf("Uso: falign file colonne\n");
        return 1;
    }

    maxcol = atoi(argv[2]);  /*determino quante colonne voglio */
    if (!(fp = fopen(argv[1], "r"))) {    /*il puntatore fp è l'apertura del file */
        printf("Errore nell'apertura del file &s\n", argv[1]);
        return 1;
    }

    int i;
    for(i = 1; i <= maxcol; i++)
       printf("%d", i % 10);
    putc('\n',stdout);

    falign(fp, stdout, maxcol);  /* utilizziamo fp puntataore stdout(come stdin), maxcol */
    fclose(fp); /* diamo il comando di chiusare a fp che punta al file */

    return 0;
}