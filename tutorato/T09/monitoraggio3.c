#include <stdio.h>
#include <stdlib.h>

struct misura {
    int aa, MM, gg;             
    int hh, mm, ss, ms;         
    char id[11];   
    float temp;                 
    int umid;                   
    float vel;
};

struct misura *leggi_file (FILE *f, int *n);
void stampa_identificativi(struct misura *elenco, int n);
float max_temp(struct misura *elenco, int n);

int main(int argc, const char *argv[])
{
    int n;
    struct misura *elenco;
    FILE *infile;

    if (argc != 2) return 1;

    infile = fopen(argv[1], "r");

    if (infile == NULL)
        fprintf(stderr, "#Errore nell'apertura del file.\n");
        return 1;

    elenco = leggi_file(infile, &n);

    printf("[IDENTIFICATIVI]\n");
    stampa_identificativi(elenco, n);

    printf("[MAX-TEMP]\n");
    printf("%.1f\n", max_temp(elenco, n));
    
    fclose(infile);

return 0;    
}

struct misura *leggi_file (FILE *f, int *n)
{
    struct misura  *m, *elenco;
    char buf[2000];
    int nconv;
    int i, size;
    int a, b;

    *n = 0;

    fgets(buf, sizeof(buf), f);
    sscanf(buf, "%d", &a);
    fgets(buf, sizeof(buf), f);
    sscanf(buf, "%d", &b);

    if ((b < a) || (a < 0) || (b < 0)) return NULL;

    size = ( b - a + 1);
    elenco = malloc(size * sizeof( *elenco));

    for(i = 0; i < a; i++)
        fgets(buf, sizeof(buf), f);
    
    while(fgets(buf, sizeof(buf), f))
    {
        m = (elenco + (*n));
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f",
            &(m->aa), &(m->MM), &(m->gg),
            &(m->hh), &(m->mm), &(m->ss), &(m->ms),
            (m->id), &(m->temp), &(m->umid), &(m->vel));

        if (nconv != 11) continue;

        (*n)++;

        if ((*n) >= size) break;
    }
    
    if ((*n) <= size)
       elenco = realloc(elenco, (*n) * sizeof(*elenco));


return elenco;
}

void stampa_identificativi(struct misura *elenco, int n)
{
    int i;

    for( i = n-1; i >= 0; i--)
        printf("%s\n", (elenco + i)->id);

}

float max_temp(struct misura *elenco, int n)
{
    int i;
    float max_temp;

    max_temp = -300.0;

    for(i = 0; i < n; i++)
        if ((elenco + i)-> id > max_temp)
            max_temp = (elenco + i)->id;

return max_temp;
}