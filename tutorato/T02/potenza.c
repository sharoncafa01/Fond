#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char s[80];
    double a, risultato;
    int b;

    risultato = 1;

    printf("Il valore della base è: ");
    fgets(s, sizeof(s), stdin);
    a = atof(s);

    printf("Il valore dell'esponente è: ");
    fgets(s, sizeof(s), stdin);
    b = atoi(s);

    if (b < 0) {
        printf("[POTENZA]\n");
        printf("NON CALCOLABILE");
    }
    else {
        while (b > 0) {
            if (b%2 == 1)
            risultato = risultato * a;
            a = a*a;
            b = b/2;
        }
    }

    printf("[POTENZA]\n");
    printf(" %.2f\n", risultato);

return 0;
}