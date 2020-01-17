#include <stdio.h>
#include <stdlib.h>

#define NMAX 100
#define MINVOTO 18
#define MAXVOTO 30
#define NVOTI (MAXVOTO - MINVOTO + 1)

void leggi_voti(int voti[], int n);
void stampa_voti(int voti[], int n);
int minimo(int voti[], int n);
void FREQUENZE(int voti[], int n, int freq[]);
int MAXFREQ(int freq[]);

int main()
{
    int n;
    int voti[NMAX];
    int freq[NVOTI] = {0};
    char p[80];

    printf("Immettere valore: \n");
    fgets(p, sizeof(p), stdin);
    n = atoi(p);

    if (n <= 0 || n > NMAX) {
        printf("[RISULTATO]\n errore\n");
    return 0;
    }

    leggi_voti(voti, n);

    printf("[VALORI]\n");
    stampa_voti(voti, n);

    printf("[MINIMO]\n");
    printf(" %d\n", minimo(voti, n));

    printf("[FREQUENZE]\n");
    FREQUENZE(voti, n, freq);

    printf("[MAXFREQ]\n");
    printf("%d\n", MAXFREQ(freq));

return 0;
}

void leggi_voti(int voti[], int n)
{
    char s[80];
    int i, voto;

    i = 0;

    do
    {
        printf("Immettere voto: \n");
        fgets(s, sizeof(s), stdin);
        voto = atoi(s);

        if (voto >= MINVOTO && voto <= MAXVOTO) {
            voti[i] = voto;
            i++;
        }

    }
    while (i < n);
}

void stampa_voti(int voti[], int n)
{
    int i;

    for(i = 0; i < n; i++) {
       printf("%d\n", voti[i]);
    }
}

int minimo(int voti[], int n)
{
    int min = voti[0];
    int i;

    for(i = 1; i < n; i++)
       if (voti[i] < min) {
           min = voti [i];
       }

    return min;
}

void FREQUENZE(int voti[], int n, int freq[])
{
    int i;
    for (i = 0; i < n; i++){
        freq[voti[i] - MINVOTO]++;
    }
    for (i = 0; i < NVOTI; i++){
        printf("%d\n", freq[i]);
    }
}


int MAXFREQ(int freq[])
{
    int i;
    int MAXFREQ = 0;

    for(i = 1; i < NVOTI; i++)
       if (freq[i] > freq[MAXFREQ]) {
           MAXFREQ = i;
       }
    return (MAXFREQ + MINVOTO);
}
