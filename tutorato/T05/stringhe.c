#include <stdio.h>
#include <string.h>


int trova_ultimo_separatore(const char *percorso) 
{
    int pos = strlen(percorso) - 1;    /* tutta la lunghezza sulla linea di comando*/
    while (pos >= 0 && percorso[pos] != '/')
        pos--;
    return pos;   /* mi da come valore 0 o la posizione, mi restituisce la posizione a cui sono arrivato alla fine del controllo*/
}                                                    /*funzione la quale, ricevuto un percorso come argomento, restituisce l'indice dell'ultimo 
                                                    ultimo separatore (il carattere /) presente nella stringa, oppure un valore negativo se nessun 
                                                    separatore è presente. */
                                                   
    void basename(const char *percorso, char *b) {
    int pos = trova_ultimo_separatore(percorso);   /*dichiaro il valore della posizione come intero richiamando la funzione per poi copiare in b*/
    strcpy(b, percorso + pos + 1);   /*ho ultimo separatore piu tutta la stringa*/
}


void basename(const char *percorso, char *b);

int main(int argc, char *argv[])    /*Per poter leggere il percorso da linea di comando*/
{
    
    char b[1024];
    char percorso[1024];
    
    if (argc != 2) {
        printf ("Numero di parametri errato.\n");
        return -1;
    }

    strcpy(percorso, argv[1]);  /*copio dentro percorso cio che era sulla linea di comando ottenuto da argv1 */
    
    basename(percorso,b);    /*richiamo della funzione*/
    
    printf("BASENAME\n");
    puts(b);      /*stampa della stringa*/
        
return 0;
}