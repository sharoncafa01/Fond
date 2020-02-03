#include <stdio.h>
#include <stdlib.h>
#define NMAX 168

struct misura {
    int aa, MM, gg;             
    int hh, mm, ss, ms;         
    char id[11];   
    float temp;                 
    int umid;                   
    float vel;  
};
void leggi_file (FILE *f, struct misura *elenco, int *n);
void stampa_elenco(struct misura *elenco, int n);

int main(int argc, const char *argv[])
{
    struct misura *elenco[NMAX];
    int n;
    FILE *infile;

    if (argc != 2)
        return 1;
    
    infile = fopen(argv[1], "r");

    if (infile == NULL)
        fprintf(stderr, "#Errore apertura file\n");
        return 1;


    printf("[ELENCO]\n");
    stampa_elenco(elenco, n);

    fclose(infile);

return 0;
}

void leggi_file (FILE *f, struct misura *elenco, int *n)
{
    int i, nconv;
    char buf[2000];
    i = 0;

    while(fgets(buf,sizeof(buf),f)){
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f",
                &(elenco[i].aa), &(elenco[i].MM), &(elenco[i].gg),
                &(elenco[i].hh), &(elenco[i].mm), &(elenco[i].ss), &(elenco[i].ms),
                (elenco[i].id), &(elenco[i].temp), &(elenco[i].umid), &(elenco[i].vel));

    if (nconv != 11) continue;

    i++;

    (*n) = i;

    return elenco;
    }
}

void stampa_elenco(struct misura *elenco, int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%s", (elenco + i));
    }
}

