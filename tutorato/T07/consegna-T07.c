#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXDIM 11
#define DIM 10
#define RIGA 1024

// AAAA-MM-GG hh:mm:ss.ms ID TEMP UMID VEL


struct riga {
    int anno, mese, giorno, ora, minuti, secondi, ms, umid;
    char id[MAXDIM];
    float vel, temp;
    };
    
    
struct riga *leggiFile(char *path, int *l){
    //path prende il valore della stringa argv[1]
    FILE *f;
    struct riga *a;
    int k = 1;
    int i = 0;
    char buffer[RIGA];
    
    a = malloc(k * DIM * sizeof(struct riga)); // dopo la malloc 
    //ogni variabile di tipo struct riga occupa un segmento di memoria, con la malloc
    //metto a disposizione di a k * DIM per la dimensione di un segmento di memoria per
    //memorizzare una variabile struct riga
    //a fine malloc, a punta all'indirizzo libero allocato (se tutto è andato bene)
    if (a == NULL) {
        puts("errore di allocazione");
        return NULL;
    }
    
    //f è un indirizzo
    //tutti gli indirizzi, quando appena dichiarati, valgono NULL (valgono NULL anche se c'è un 
    //errore di elaborazione)
    f = fopen(path, "r");
    if (f == NULL) {
        puts("errore apertura file");
        return NULL;
    }
    //fgets ritorna 1 se legge una riga dal file, altrimenti ritorna 0
    //se fgets ritorna 1 continuo la lettura del file (salvo la riga e passo a quella 
    //successiva a fine iterazione)
    while(fgets(buffer, sizeof(buffer), f)){
        //a fine di ogni fgets buffer contiene una riga del file
        
        //2019-03-03 23:59:10.120 ID000 17.5 20% 0.4
        sscanf(buffer, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f", &a[i].anno, &a[i].mese, &a[i].giorno, &a[i].ora,
                                                             &a[i].minuti, &a[i].secondi, &a[i].ms, a[i].id, 
                                                             &a[i].temp, &a[i].umid, &a[i].vel);
                                                             
        i++;
        if (i >= k*DIM) {
            k++;
            a = realloc(a, k * DIM * sizeof(struct riga));
            if (a == NULL) {
                 puts("errore prima riallocazione");
                return NULL;
            }
        } 
    }
    
    *l = i; // l indica il numero di righe lette (anche il numero di elementi della struttura)
    
    a = realloc(a, i*sizeof(struct riga));
    if (a == NULL) {
        puts("errore seconda riallocazione");
        return NULL;
    }
    
    fclose(f);
    return a;
}

void stampa(struct riga *a, int l){
    int i;
    
    for(i=0; i<l; i++) {
        printf("%d-%02d-%02d %02d:%02d:%02d.%03d %s %.1f %d%% %.1f\n", a[i].anno, a[i].mese, a[i].giorno, a[i].ora,
                                                             a[i].minuti, a[i].secondi, a[i].ms, a[i].id, 
                                                             a[i].temp, a[i].umid, a[i].vel);
    }
}
    
    //argv[0] = nome eseguibile
    //argv[1] = nome file
void dimFile(struct riga *a, int l){
    int i = 0;
    int dim = 0;
    printf("%d\n", sizeof(a[0].anno)); //anno è una variabile int, le variabili int hanno 4 byte
    printf("%d\n", sizeof(a[0].id));
    /*for( i = 0; i < l; i++){
        dim += (sizeof(a[i].anno) + sizeof(a[i].mese)) + sizeof(a[i].giorno) + sizeof(a[i].ora) + sizeof(a[i].minuti)
            + sizeof(a[i].secondi) +sizeof(a[i].ms) +sizeof(a[i].id) + sizeof(a[i].temp) + sizeof(a[i].umid)
            +sizeof(a[i].vel);
    }*/
   dim = sizeof(struct riga) * l;
    printf("[DIM]\n%d\n", dim);
    //facendo così ti viene DIM = 156, mentre nel caso prima viene 153. non saprei il motivo
    //probabilmente avere una struttura dati ha un costo leggermente maggiore in byte rispetto alle variabili pure
    
}


void stampaIdentificativi(struct riga *a, int l)
{
    int i;
    for (i = l - 1; i >= 0; i--) {
        printf("%s\n", a[i].id); 
    }
}




void maxTemp(struct riga *a, int l)
{
    float maxTemp;
    int i;

    maxTemp = a[0].temp;
    /* una iterazione per ogni struttura successiva alla
     * prima, se ce ne sono */
    for (i = 1; i < l; i++) {
        /* se la temperatura corrente è maggiore del
         * massimo attuale, aggiorna il massimo */
        if (a[i].temp > maxTemp)
            maxTemp = a[i].temp;
    }
    printf("[MAX-TEMP]\n%.1f\n", maxTemp);
}




int confronta(const void *a, const void *b) {
	const struct riga *ca=a, *cb=b;
	if (!(strcmp(ca ->id, cb ->id))) {
	    return ca->umid - cb->umid ;
	}
    	
		return strcmp(ca ->id, cb ->id) ;
}



    
int main (int argc, char *argv[]) {
    
    struct riga *a;
    int l;
    
    // 1 = vero 0 = falso
    if (argc != 2) {
        puts("errore nel passaggio dei parametri");
        return 0;
    }
    //argv[1] corrisponde all'indirizzo di partenza in cui è salvato il file
    a = leggiFile(argv[1], &l);

    if (a == NULL) {
        return 0;
    }
     puts("[RIGHE]");
     stampa(a, l);
     printf("[ID-INVERSI]");
     stampaIdentificativi(a, l);
     dimFile(a, l);
     
     printf("[NUMERO-RIGHE]\n%d\n", l);
     
     maxTemp(a, l);
     
     //qsort(a, l, sizeof(a), compare);
     puts("[ORDINAMENTO-ID]");
     qsort(a, l, sizeof(*a), confronta);

     stampa(a, l);
     

     
     
    int i = 0;
    int freq[12] = {0};      
    for (i = 0; i < l; i++)
        freq[a[i].mese]++;
        
        
  //  printf("[FREQUENZE]\n");
  //  for (i = 0; i < 12; i++)      
    //    printf("%d\n", freq[i]);


    int maxIndice = 0;
    for (i = 1; i < 12; i++)
        if (freq[i] > freq[maxIndice])
            maxIndice = i;


    printf("[MAXFREQ]\n");
    printf("%02d\n", maxIndice);
    printf("%d\n", l);
    
    
    
    
    
    
     
    
    free(a);
    return 0;
}