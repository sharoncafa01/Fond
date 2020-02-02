#include <stdio.h>
#include <stdlib.h>
#define NMAX 168

struct misura {
    int AAAA, MM, GG;
    int hh, mm, ss, ms;
    char id[11];
    float temp, vel;
    int umid;
};

void leggi_file(FILE *f, struct misura *elenco, int *n);
void stampa_elenco(struct misura *elenco, int n);
float max_temp(struct misura *elenco, int n);

int main(int argc, char *argv[])
{
    FILE *infile;
    struct misura elenco[NMAX];
    int n[168];

    if (argc != 2)
        return 1;

    infile = fopen(argv[1], "r");

    if (infile == NULL)
        fprintf(stderr, "#Errore apertura file.\n");
        return 1;

    void leggi_file (infile, elenco, n);

    printf("[INVERTITA]\n");
    void stampa_elenco(infile, elenco, n);

    printf("[MAX-TEMP]\n");
    float max_temp(infile, elenco, n);

    fclose(infile);

return 0;
}

void leggi_file(FILE *f, struct misura *elenco, int *n){
    char buf[1000];
    int i, nconv;
    i = 0;

    while(fgets(buf, sizeof(buf), f)){
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f", 
       &(elenco[i].AAAA), &(elenco[i].MM), &(elenco[i].GG), 
       &(elenco[i].hh), &(elenco[i].mm), &(elenco[i].ss), &(elenco[i].ms), 
       (elenco[i].id), &(elenco[i].temp), &(elenco[i].umid), &(elenco[i].vel));

       if (nconv != 11) continue;
     i++;  
    }

    if (i >= NMAX) return -1;

*n = i;
}

void stampa_elenco(struct misura *elenco, int n){
    int i;
    if (n <= 6){
        for(i = n-1; i >= 0; i--)
        puts("elenco[i]");}
    else 
        for(i=0; i <3; i++){
            puts("elenco[i]");
        }
        for (i = n-1; i < n-3; i--){
            puts("elenco[i]");
        }
    
}

float max_temp(struct misura *elenco, int n){
    int i;
    float max_temp;
    max_temp = -300.0;

    for (i=0; i < n; i++){
        if ((elenco[i].temp) > max_temp)
            max_temp = (elenco[i].temp); 
    }
    printf("%f\n", max_temp);
}