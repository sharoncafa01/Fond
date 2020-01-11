#include <stdio.h>
#include <stdlib.h>
#define MAX_ID_LUNG 11
 
 
 
/*La prima cosa da fare è realizzare la struttura che ospiterà i dati delle singole righe*/
struct misura {
    int aa, MM, gg;             // data
    int hh, mm, ss, ms;         // orario
    char id[MAX_ID_LUNG + 1];   // identificativo del dispositivo
    float temp;                 // temperatura
    int umid;                   // umidità
    float vel;                  // velocità del vento
};


/*funzione che si occupa della lettura del file*/

struct misura *leggi_file(FILE *f, int *n)
{
    struct misura *m, *elenco, *tmp_ptr;
    char buf[1000];
    int nconv;        // numero di elementi convertiti
    int dim;

    /* inizializza a zero il numero di strutture caricate (11 elementi) */
    *n = 0;
    /* elenco e' il nostro vettore; dimensionamento e allocazione iniziale del vettore (numero dirighe dentro il vettore)*/
    dim = 4;
    elenco = malloc(dim * sizeof(*elenco));

    /* ad ogni iterazione, legge una riga fino alla fine del file */
    while (fgets(buf, sizeof(buf), f)) {
        /* punta all'elemento corrente da memorizzare */
        m = elenco + (*n);
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f",
            &(m->aa), &(m->MM), &(m->gg),
            &(m->hh), &(m->mm), &(m->ss), &(m->ms),
            (m->id), &(m->temp), &(m->umid), &(m->vel));
        /* passa alla riga successiva se non ci sono esattamente 11
         * elementi da convertire */
        if (nconv != 11) continue;
        /* se si arriva qui, la riga è stata letta e memorizzata
         * correttamente; incremento il numero di righe lette */
        (*n)++;
        /* verifica se il vettore è riempito */
        if ((*n) >= dim) {
            /* raddoppia il valore della variabile */
            dim *= 2;
            /* ri-alloca lo spazio per il vettore */
            tmp_ptr = realloc(elenco, dim * sizeof(*elenco));
            /* controlla che la ri-allocazione abbia avuto successo */
            if (tmp_ptr == NULL) return NULL;
            /* se è tutto a posto, assegna il puntatore */
            elenco = tmp_ptr;
        }
    }
    /* riduce la dimensione del vettore fissandola pari a *n */
    elenco = realloc(elenco, (*n) * sizeof(*elenco));
    /* restituisce il vettore con i dati letti */
    return elenco;
}

/* La funzione che stampa gli identificativi in senso inverso
Essa riceve come argomenti il vettore delle strutture caricate da file e il numero di elementi nel vettore.
Effettua un ciclo for con contatore che parte dall'ultimo elemento del vettore (indice n - 1) e decrementa
 il contatore fino ad indirizzare l'elemento di indice 0 del vettore. */

void stampa_identificativi(struct misura *elenco, int n)
{
    int i;
    for (i = n - 1; i >= 0; i--)
        printf("%s\n", (elenco + i)->id);
}




int main(int argc, char *argv[])
{
    struct misura leggi_file;
    struct misura elenco;
    FILE *infile;
    

    /* termina se il numero di parametri è errato */
    if (argc != 2)      /*uno il programma e l'altro file*/
        return 1;

    /* apre il file in lettura */
    infile = fopen(argv[1], "r");
    /* termina in caso di errore ,se c'e NULL non lo legge ed e' errore*/
    if (infile == NULL) {              
        fprintf(stderr, "# Errore apertura file\n");
        return 1;
    }
    
    leggi_file(infile);         /*apertura e chiusura del file*/
    stampa_identificativi(&elenco, stdout); 
    fclose(infile);
    return 0;
}
