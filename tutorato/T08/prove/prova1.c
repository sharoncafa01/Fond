#include <stdio.h>
#include <stdlib.h>
#define NMAX 168

struct misura {
    int AA, MM, GG;
    int hh, mm, ss, ms;
    char id[11];
    float temp, vel;
    int umid;
};

void leggi_file(FILE *f, struct misura *elenco, int *n);
void stampa_elenco(struct misura *elenco, int n);
void stampa_riga(struct misura *elenco, int *n);

int main(int argc, const char *argv[]){
    struct misura elenco[NMAX];
    FILE *infile;

    if (argc != 2)
        return 1;

    infile = fopen(argv[1], "r");

    if (infile == NULL){
        fprintf(stderr, "#Errore nell'apertura del file.\n");
        return 1;
    }

    int n = NMAX;
    leggi_file(infile, elenco, &n);

    printf("[ELENCO]\n");
    stampa_elenco(elenco, n);
    fclose(infile);

return 0;
}

void leggi_file(FILE *f, struct misura *elenco, int *n)
{
    char buf[2000];
    struct misura *m;
    int nconv;

    (*n) = 0;

    while(fgets(buf, sizeof(buf), f)){
        m = elenco + (*n);
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f\n",
                        &(m->AA), &(m->MM), &(m->GG),
                        &(m->hh), &(m->mm), &(m->ss), &(m->ms),
                        (m->id), &(m->temp), &(m->umid), &(m->vel));
        
        if (nconv != 11) continue;

        (*n)++;

        if ((*n) >= NMAX) break;
    }
}

void stampa_elenco(struct misura *elenco, int n)
{
    int i;
    for(i = 0; i < n; i++)
            stampa_riga(elenco, &i);
}

void stampa_riga(struct misura *elenco, int *n){
    printf("%0d-%02d-%02d %02d:%02d:%02d.%03d %s %.1f %d%% %.1f\n", 
                    elenco[*n].AA, elenco[*n].MM, elenco[*n].GG,
                    elenco[*n].hh, elenco[*n].mm, elenco[*n].ss, elenco[*n].ms,
                    elenco[*n].id, elenco[*n].temp, elenco[*n].umid, elenco[*n].vel);
}
