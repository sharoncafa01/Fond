#include <stdio.h>
#include <stdlib.h>
#define MAX_ID_LUNG 10
#define MAX_DATI 168

struct misura {
    int aa, MM, gg;
    int hh, mm, ss, ms;
    char id [MAX_ID_LUNG + 1];
    float temp, vel;
    int umid;
};

void leggi_file (FILE *f, struct misura *elenco, int *n);
void stampa_elenco(struct misura *elenco, int n);
float max_temp(struct misura *elenco, int n);

int main(int argc, char *argv[])
{
    int elenco[168];
    int n[168];

    FILE *infile;

    if (argc != 2)
       return 1;

    infile = fopen(argv[1], "r");

    if (infile == NULL)
        fprintf(stderr, "#Errore apertura file");
        return 1;

    leggi_file(infile, elenco, n);
    fclose(infile);

 return 0;
}

void leggi_file(FILE *f, struct misura *elenco, int *n)
{
    char buf[1000];
    int nconv;

    int i = 0;

    while (fgets(buf, sizeof(buf), f)) {

        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f",
                &(elenco[i].aa), &(elenco[i].MM), &(elenco[i].gg),
                &(elenco[i].hh), &(elenco[i].mm), &(elenco[i].ss), &(elenco[i].ms),
                (elenco[i].id), &(elenco[i].temp), &(elenco[i].umid), &(elenco[i].vel));

        if (nconv != 11) continue;

        i++;

        if (i >= MAX_DATI) break;
    }
    *n = i;
}


void stampa_elenco(struct misura *elenco, int n)
{
    int i;
    if (n <= 6) {
        for (i = n - 1; i >= 0; i--)
            stampa_riga(elenco + i);
    } else {
        for (i = 0; i < 3; i++)
            stampa_riga(elenco + i);
        for (i = n - 1; i >= n - 3; i--)
            stampa_riga(elenco + i);
    }
}

void stampa_riga(struct misura *elenco, int i)
{
    printf("%s", elenco[i]);
}

float max_temp(struct misura *elenco, int n)
{
    float max_temp;
    int i;


    if (n <= 0) return -1000;

    max_temp = elenco[0].temp;
    for (i = 1; i < n; i++) {
        if ((elenco + i)->temp > max_temp)
            max_temp = (elenco + i)->temp;
    }
    return max_temp;
}

