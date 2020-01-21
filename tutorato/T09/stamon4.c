#include <stdio.h>
#include <stdlib.h>

struct misura {
    int aa, MM, gg;
    int hh, mm, ss, ms;
    char id[11];
    float temp, vel;
    int umid;
};

struct misura *leggi_file(FILE *f, int *n);
void stampa_identificativi(struct misura *elenco, int n);

int main(int argc, char *argv[])
{
    int n;

    FILE *infile;
    struct misura *elenco;

    if (argc != 2) 
        return 1;

    infile = fopen(argv[1], "r");
    if (infile == NULL){
       fprintf(stderr, "#Errore apertura file\n");
       return 1;
    }

    elenco=leggi_file(infile, &n);
    printf("[IDENTIFICATIVI]\n");
    stampa_identificativi(elenco, n);
    fclose(infile);

return 0;
}

struct misura *leggi_file(FILE *f, int *n)
{
    struct misura *elenco, *m, *punt_temp;
    char buf[1000];
    int nconv;
    int dim=4;

    *n=0;
    elenco=malloc(dim * sizeof(*elenco));

    while(fgets(buf, sizeof(buf), f))
    {
        m = elenco + (*n);
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f" ,
            &(m->aa), &(m->MM), &(m->gg),
            &(m->hh), &(m->mm), &(m->ss), &(m->ms),
            (m->id), &(m->temp), &(m->umid), &(m->vel));

        if (nconv != 11) continue;

        (*n)++;
    
         if ((*n) >= dim) {
             dim*=2;
             punt_temp=realloc(elenco, dim * sizeof(*elenco));
             if(punt_temp==NULL) return NULL;
                elenco = punt_temp;
        }
    }
    elenco = realloc(elenco, (*n) * sizeof(*elenco));

    return elenco;
}

void stampa_identificativi(struct misura *elenco, int n)
{
    int i;

    for(i = n-1; i >= 0; i--)
        printf("%s\n", (elenco + i)->id);
}