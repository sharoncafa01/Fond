#include <stdio.h>
#include <stdlib.h>

int trova_massimo( a, b, c);
int trova_minimo(a, b, c);
int trova_intermedio(a, b, c);

int main()
{
    int a, b, c;
    char s[80];

    printf("Inserire il primo valore:\n");
    fgets(s, sizeof(s), stdin);
    a = atoi(s);

    printf("Inserire il secondo valore:\n");
    fgets(s, sizeof(s),stdin);
    b = atoi(s);

    printf("Inserire il terzo valore:\n");
    fgets(s, sizeof(s), stdin);
    c = atoi(s);

    int max = trova_massimo(a, b, c);
    int min = trova_minimo(a, b, c);
    int med = trova_intermedio(a, b, c);
    

     printf("I lati più corti sono: %i e %i\n", min, med);
     printf("Il lato più lungo è: %i\n", max);

    int somma = (min + med);
    
    if (somma < max) {
       printf("I valori inseriti non sono quelli di un triangolo\n");
    }


 return 0;
}

int trova_massimo(int a, int b, int c)
{
    int max = 0;

    if ((a >= b) && ( a >= c))
        max = a;
    else if ((b >= a) && ( b >= c))
        max = b;
    else 
        max = c;
    
    return max;
}

int trova_minimo(int a, int b, int c)
{
    int min = 1;

    if ((a <= b) && (a <= c))
        min = a;
    else  if ((b <= a) && ( b <= c))
        min = b;
        else 
            min = c;
}

int trova_intermedio(int a, int b, int c)
{
    int med = 0;

    if ( a >= b && b>=c) {
        med = b;
    }
    else if (a >= c && c >= b) {
        med = c;
      }

    if ( b>= a && a >= c) {
       med = a;
    }
    else if ( b >= c && c >= a) {
        med = c;
    }

    if ( c >= a && a >= b) {
        med = a;
    }
    else if ( c >= b && b >= a) {
        med = b;
    }
   return med;
}