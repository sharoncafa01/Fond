#include <stdio.h>
#include <stdlib.h>

struct misura{
    int aa, MM, gg;
    int hh, mm, ss, ms;
    char id[11];
    float temp, vel;
    int umid;
}

struct misura leggi_file(FILE *f, int *n);
void stampa_identificativi(elenco, n);

int main(int argc, char *argv[])
{
    struct misura *elenco;
    FILE *infile;

    if (argc != 2) return 1;

    infile = fopen(argv[1], "r");
    if (infile == NULL)
       fprintf(stderr, "#Errore di apertura file\n");

    elenco = leggi_file(infile, &n);

    printf("[IDENTIFICATIVA]\n");
    stampa_identificativi(elenco, n);

    fclose(infile);

return 0;
}

struct misura leggi_file(FILE *f, int *n);
{
    struct misura *elenco, *m;
    char buf[1000];
    int a, b;
    int nconv;
    int size, i;
    
    *n = 0;

    fgets(buf, sizeof(buf), f);
    sscanf(buf,"%d", &a);
    fgets(buf, sizeof(buf), f);
    sscanf(buf,"%d", &b);

    if ((b < a) || (b = 0) || (a = 0))
       return NULL;

    size = (b - a +1);
    elenco = malloc(size *sizeof(*elenco));

    for(i = 0; i < a; i++)
    fgets(buf, sizeof(buf), f);

    while (fgets(buf, sizeof(buf), f)
    {
        m = elenco + (*n);
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f",
            &(m->aa), &(m->MM), &(m->gg),
            &(m->hh), &(m->mm), &(m->ss), &(m->ms),
            (m->id), &(m->temp), &(m->umid), &(m->vel));

        if (nconv != 11) continue;
        
        *n++;

        if ( n>= size ) break;
    }
    if ( n <= size)
       elenco = realloc(elenco, (*n)*sizeof(*elenco));
return elenco;
}

void stampa_identificativi(struct misura *elenco, int n)
{
    int i;

    for(i = n-1; i >= 0; i++)
    printf("%s", (elenco + 1)-> id);
}