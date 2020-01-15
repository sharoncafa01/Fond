#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char s[40];
    int a, b, c, mediana;

    printf("Inserire il primo valore: ");
    fgets(s, sizeof(s), stdin);
    a = atoi(s);

    printf("Inserire il secondo valore: ");
    fgets(s, sizeof(s), stdin);
    b = atoi(s);

    printf("Inserire il terzo valore: ");
    fgets(s, sizeof(s), stdin);
    c = atoi(s);

    if ( a >= b && b>=c) {
        mediana = b;
    }
    else if (a >= c && c >= b) {
        mediana = c;
      }

    if ( b>= a && a >= c) {
       mediana = a;
    }
    else if ( b >= c && c >= a) {
        mediana = c;
    }

    if ( c >= a && a >= b) {
        mediana = a;
    }
    else if ( c >= b && b >= a) {
        mediana = b;
    }


    printf(" [MEDIANA] \n");
    printf(" %i\n ", mediana);

return 0;
}