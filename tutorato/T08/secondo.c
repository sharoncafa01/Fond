#include <stdio.h>




struct misura {
    int aa, MM, gg;             // data
    int hh, mm, ss, ms;         // orario
    char id[MAX_ID_LUNG + 1];   // identificativo del dispositivo
    float temp;                 // temperatura
    int umid;                   // umidità
    float vel;                  // velocità del vento
};


void leggi_file(FILE *f, struct misura *elenco, int *n)
{
    char buf[1000];
    int nconv;        // numero di elementi convertiti

    /* inizializza a zero il numero di strutture caricate */
    int i = 0;
    /* ad ogni iterazione legge una nuova riga */
    while (fgets(buf, sizeof(buf), f)) {
        /* punta all'elemento corrente da memorizzare */
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f",
                &(elenco[i].aa), &(elenco[i].MM), &(elenco[i].gg),
                &(elenco[i].hh), &(elenco[i].mm), &(elenco[i].ss), &(elenco[i].ms),
                (elenco[i].id), &(elenco[i].temp), &(elenco[i].umid), &(elenco[i].vel));
        /* passa alla riga successiva se non ci sono esattamente 11
         * elementi da convertire */
        if (nconv != 11) continue;
        /* se si arriva qui, la riga è stata letta e memorizzata
         * correttamente; incremento il numero di righe lette */
        i++;
        /* per precauzione controlla che non si leggano più
         * dati di quelli che possono essere ospitati nel vettore;
         * questo non dovrebbe mai succedere se il file è corretto */
        if (i >= MAX_DATI) break;
    }
    *n = i;
}


void stampa_elenco(struct misura *elenco, int n)
{
    int i;
    if (n <= 6) {
        /* stampa tutte le righe in ordine inverso */
        for (i = n - 1; i >= 0; i--)
            puts(elenco[i]);
    } else {
        /* stampa le prime tre righe */
        for (i = 0; i < 3; i++)
            printf("%s\n", (elenco + i);
        /* stampa le ultime tre righe in ordine inverso */
        for (i = n - 1; i >= n - 3; i--)
            stampa_riga(elenco + i);
    }
}





int main(int argc, const char *argv[])
{
    FILE *infile;

    /* termina se il numero di parametri è errato */
    if (argc != 2)
        return 1;

    /* apre il file in lettura */
    infile = fopen(argv[1], "r");
    /* termina in caso di errore */
    if (infile == NULL) {
        fprintf(stderr, "# Errore apertura file\n");
        return 1;
    }
    leggi_file(infile);
    stampa_elenco()
    fclose(infile);

    return 0;
}