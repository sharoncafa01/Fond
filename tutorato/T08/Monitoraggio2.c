//CONSEGNA: http://robot.unipv.it/tutorati-fdi/T08-lettura-quantita-calcolata.html
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATI (168)
//definizione della struttura in cui saranno contenuti tutti i campi del file inserito come input
struct misura {
    int aa, MM, gg;             // data
    int hh, mm, ss, ms;         // orario
    char id[MAX_DATI];                    // identificativo del dispositivo
    float temp;                 // temperatura
    int umid;                   // umidità
    float vel;                  // velocità del vento
};

void leggi_file(FILE *f, struct misura *elenco, int *n); //Dichiarazione funzioni
void stampa_elenco(struct misura *elenco, int n);        //""
float max_temp(struct misura *elenco, int n);            //""
void stampa_riga (struct misura *elenco, int *n);                //""

int main(int argc, const char *argv[])
{
    struct misura vett[MAX_DATI];
    FILE *inputf; //definizione del puntatore che segna l'indirizzo in cui si trova il file inserito in argv[1]

    // se il numero di argomenti passati è diverso da 2, allora si notifica l'errore
    if (argc != 2)
        return 1;

    // apre il file in lettura
    inputf = fopen(argv[1], "r");
    // termina in caso in cui avvenga un determinato errore
    if (inputf == NULL) {
        fprintf(stderr, "# Errore apertura file\n");
        return 1;
    }
    
    int numero_elementi= MAX_DATI;
    leggi_file(inputf, vett, &numero_elementi); //richiamo la funzione per inserire le righe nella struttura "misura"
    
    printf("[INVERSO]\n");
    //richiamo la funzione per leggere le righe della struttura in modo invertito
    stampa_elenco(vett, numero_elementi);  
    fclose(inputf);        //chiusura del file in lettura
   
    printf("[MAX-TEMP]\n");
    //richiamo la funzione per calcolare la temperatura massima, tra gli elementi nella struttura 
    float temperatura_massima=-3000;
    temperatura_massima = max_temp(vett, numero_elementi);
    printf("%f" , temperatura_massima);
    return 0; //fine dele programma
}

//definizione funzione per la lettura del file
void leggi_file(FILE *f, struct misura *elenco, int *n)
{
    char buf[1000];
    int nconv;        // numero di elementi convertiti
    struct misura *m;
    /* inizializza a zero il numero di strutture caricate */
    *n = 0;
    /* ad ogni iterazione legge una nuova riga */
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
        /* per precauzione controlla che non si leggano più
         * dati di quelli che possono essere ospitati nel vettore;
         * questo non dovrebbe mai succedere se il file è corretto */
        if ((*n) >= MAX_DATI) break;
    }
}

//definizione funzione per la stampa del file, in senso opposto
void stampa_elenco(struct misura *elenco, int n)
{
    int i;
    if (n <= 6) {
        /* stampa tutte le righe in ordine inverso */
        for (i = n - 1; i >= 0; i--)
            stampa_riga(elenco, &i);
    } else {
        /* stampa le prime tre righe */
        for (i = 0; i < 3; i++)
            stampa_riga(elenco, &i);
        /* stampa le ultime tre righe in ordine inverso */
        for (i = n - 1; i >= n - 3; i--)
            stampa_riga(elenco, &i);
    }
}

//definizione funzione per stampare la riga desiderata della struttura "misura", per poi effettuare la stampa in modo invertito
void stampa_riga (struct misura *elenco, int *n)
{
    printf("%d-%d-%d %d:%d:%d.%d %s %0.1f %d%% %0.1f\n", 
    elenco[*n].aa, elenco[*n].MM, elenco[*n].gg, elenco[*n].hh, elenco[*n].mm, elenco[*n].ss, 
    elenco[*n].ms,elenco[*n].id, elenco[*n].temp, elenco[*n].umid, elenco[*n].vel);
}    

//definizione funzione per il calcolo della temperatura massima, tra tutte quelle presenti nel file
float max_temp(struct misura *elenco, int n)
{
    float max_temp;
    int i;

    /* esce in caso non vi siano elementi nel vettore */
    if (n <= 0) return -1000;
    /* il massimo viene inizializzato con il primo valore
     * disponibile */
    max_temp = elenco[0].temp;
    /* una iterazione per ogni struttura successiva alla
     * prima, se ce ne sono */
    for (i = 1; i < n; i++) {
        /* se la temperatura corrente è maggiore del
         * massimo attuale, aggiorna il massimo */
        if ((elenco + i)->temp > max_temp)
            max_temp = (elenco + i)->temp;
    }
    return max_temp;
}