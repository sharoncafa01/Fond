#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcolo_rettangolo(a, b);

int main(int argc, char *argv[])
{
    if (argc != 3)
      return 1;

    int a, b;

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    printf("L'altezza del rettangolo è %i\n", a);
    printf("La base del rettangolo è: %i\n", b);

    printf("[Dati rettangolo]\n");
    calcolo_rettangolo(a, b);

    return 0;
}

void calcolo_rettangolo(int a, int b)
{
    int p, ar;
    float d;

    p = (a+b)*2;
    ar = (a*b);
    d = sqrt((b*b)+ (a*a));

    printf("Il perimetro è: %i\n", p);
    printf("L'area è: %i\n", ar);
    printf("La diagonale è: %.2lf\n", d);
}