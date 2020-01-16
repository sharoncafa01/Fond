#include <stdio.h>
#include <stdlib.h>
#define MAXVOTO 30
#define MINVOTO 18
#define NMAX 100
#define NVOTI (MAXVOTO - MINVOTO +1)

int main()
{
    char s[80];
    int n, i;
    int voto;

    printf("Immettere valore: \n");
    fgets(s, sizeof(s), stdin);
    n = atoi(s);

    if (n <= 0)   {
        printf("[ERRORE]\n");
    }
    return 0;

    if (n > NMAX)  {
        printf("[ERRORE]\n");
    }
    return 0;


    int VOTI[NMAX];
    i = 0;

    do {
        printf("Immettere voto: \n");
        fgets(s, sizeof(s), stdin);
        voto = atoi(s);

        if (voto > MINVOTO) {
            if (voto < MAXVOTO)
            }
        {
            VOTI[i] = voto;
            i++;
        }
    }
    while (i < n);


    for ( i = 0; i < n; i++);
        printf("[VALORI]\n");
        printf("%i\n", VOTI[i]);

    int min = ( VOTI[0]);
    for ( i=1; i<n; i++)
      if (VOTI[i] < min) {
          min = VOTI[i];
      }
    printf("[MINIMO]\n");
    printf("%i\n", min);

    int freq[NVOTI]= 0
    for(i= 0; i < n; i++);
        freq[VOTI[i] - MINVOTO]++;

    printf("[FREQUENZA\n");

    for ( i= 0; i< NVOTI; i++);
       printf("%i\n", freq[i]);

    int MAXFREQ= freq[0];

    for ( i= 1; i< NVOTI; i++);
       if (freq[i]> MAXFREQ) {
           MAXFREQ = freq[i];
       }
    printf("[MAXFREQ]\n");
    printf("%i\n", MAXFREQ + MINVOTO);

return 0;
}