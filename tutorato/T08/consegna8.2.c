#include <stdio.h>
#include <stdlib.h>
#define NMAX 168

struct misura {
    int aa, MM, gg;
    int hh, mm, ss, ms;
    char id[11];
    float temp, vel;
    int umid;
};

void leggi_file(FILE *f, struct misura *elenco, int *n);
void stampa_elenco(struct misura *elenco, int n);
void stampa_riga(struct misura *elenco, int *n);
float max_temp (struct misura *elenco, int n);

int main(int argc, const char *argv[])
{
    struct misura elenco[NMAX];
    FILE *infile;

    if (argc != 2){
        return 1;
    }
    
    infile = fopen(argv[1], "r");

    if (infile == NULL){
        fprintf(stderr, "#Errore apertura file.\n");
        return 1; 
    }
    int n = NMAX;
    leggi_file(infile, elenco, &n);

    printf("[INVERTITA]\n");
    stampa_elenco(elenco, n);
    fclose(infile);

    
    printf("[MAX-TEMP]\n");
    float temp_max = -300.0;
    temp_max = max_temp(elenco, n);
    printf("%.1f\n", temp_max);

return 0;
}

void leggi_file(FILE *f, struct misura *elenco, int *n)
{
    char buf[2000];
    int nconv;
    struct misura *m;

    *n = 0;
     while(fgets(buf, sizeof(buf), f)){
         m = elenco + (*n);
         nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f\n",
                        &(m->aa), &(m->MM), &(m->gg),
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

    if ( n <= 6){
        for(i = n-1; i >= 0; i--)
        stampa_riga(elenco, &i);
    }
    else {
        for( i = 0; i < 3; i++)
        stampa_riga(elenco, &i);
        for( i = n-1; i < n-3; i--)
        stampa_riga(elenco, &i);
    }
}

void stampa_riga(struct misura *elenco, int *n){
    printf("%d-%d-%d %d:%d:%d.%d %s %.1f %d%% %.1f\n", elenco[*n].aa, elenco[*n].MM, elenco[*n].gg,
                                                   elenco[*n].hh, elenco[*n].mm, elenco[*n].ss, elenco[*n].ms,
                                                   elenco[*n].id, elenco[*n].temp, elenco[*n].umid, elenco[*n].vel);
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