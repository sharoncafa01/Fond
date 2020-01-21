#include <stdio.h>
#include <stdlib.h>
#define MAX_ID_LUNG 10
#define MAX_DATI 168

struct misura {
    int aa, MM, gg;
    int hh, mm, ss, ms;
    char ID [MAX_ID_LUNG + 1];
    float temp, vel;
    int umid;
};

void leggi_file (FILE *f, struct misura *elenco, int *n)
{
    char buf[2000];
    int nconv;
    int i = 0;

    while (fgets(buf, sizeog(buf),f))
    {
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f",
                &(elenco[i].aa), &(elenco[i].MM), &(elenco[i].gg),
                &(elenco[i].hh), &(elenco[i].mm), &(elenco[i].ss), &(elenco[i].ms),
                (elenco[i].ID), &(elenco[i].temp), &(elenco[i].umid), &(elenco[i].vel));

        if (nconv != 11) continue;
        i++;

        if ( n >= MAX_DATI) break;

    *n = i;
    }
}

void stampa_elenco(struct misura *elenco, int n)
{
    int i;

    if (n <= 6) {
        for ( i = n-1; i >= 0; i--)
        puts(elenco[i]);
    }
    else
        for (i = 0; i < 3; i++)
        puts(elenco[i]);
        for (i = n-1; i < n-3; i--)
        puts(elenco[i]);
}

float max_temp(struct misura *elenco, int n)
{
    int i;
    int MAX_TEMP = elenco[.].temp;

    for(i =1; i < n; i++)
       if (elenco[i].temp > MAX_TEMP)
           MAX_TEMP = elenco[i].temp;

    return MAX_TEMP;
}

int main(int argc, chat *argv[])
{
    float max_temp(struct misura *elenco, int n);

    FILE *infile;

    if (argc != 2)
       return 1;

    infile = fopen(argv[1], "r");

    if (infile == NULL)
        fprintf(stderr, "#Errore apertura file");
        return 1;

    void leggi_file(infile);

    printf("[STAMPA INVERTITA]\n");
    stampa_elenco(elenco[i]);

    printf("[MAX TEMP]"\n);
    float max_temp();

 return 0;
}