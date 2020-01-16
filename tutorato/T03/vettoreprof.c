#include <stdlib.h>
#include <stdio.h>

#define MINVOTO 18
#define MAXVOTO 30
#define NVOTI   (MAXVOTO - MINVOTO + 1)
#define NMAX    100

int main() {
    char s[80];
    int n;
    int voti[NMAX];
    int i, voto;

    printf("Immettere valore: \n");
    fgets(s, sizeof(s), stdin);
    n = atoi(s);


    if (n <= 0 || n > NMAX) {
        printf("[RISULTATO]\nerrore\n");
        return 0;
    }


    i = 0;
    do {
        printf("Immettere voto: \n");
        fgets(s, sizeof(s), stdin);
        voto = atoi(s);


        if (voto >= MINVOTO && voto <= MAXVOTO) {
            voti[i] = voto;
            i++;
        }
    } while (i < n);


    printf("[VALORI]\n");
    for (i = 0; i < n; i++)
        printf("%d\n", voti[i]);


    int min = voti[0];
    for (i = 1; i < n; i++)
        if (voti[i] < min)
            min = voti[i];
    printf("[MINIMO]\n");
    printf("%d\n", min);


    int freq[NVOTI] = {0};
    for (i = 0; i < n; i++)
        freq[voti[i] - MINVOTO]++;
    printf("[FREQUENZE]\n");
    for (i = 0; i < NVOTI; i++)
        printf("%d\n", freq[i]);


    int maxIndice = 0;
    for (i = 1; i < NVOTI; i++)
        if (freq[i] > freq[maxIndice])
            maxIndice = i;

    printf("[MAXFREQ]\n");
    printf("%d\n", maxIndice + MINVOTO);

    return 0;
}