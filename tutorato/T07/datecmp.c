#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    struct data d1, d2;
    int n1, n2, cmp;

    if (argc != 3) {
       printf("Numero di paremetri errato.\n");
    return -1;
    }

    n1 = sscanf(argv[1], "%d-%d-%d", &d1.a, &d1.m, &d1.g);
    if (n1 != 3) {
        printf("Conversione data 1 errata\n");
        return -1;
    }

    n2 = sscanf(argv[2], "%d-%d-%d", &d2.a, &d2.m, &d2.g);
    if (n2 != 3) {
        printf("Conversione data 2 errata\n");
        return -1;
    }

    cmp = datecmp(&d1, &d2);

    if (cmp < 0 ){
        printf("%s < %s\n", argv[1], argv[2]);
    } else if (cmp == 0) {
        printf("%s = %s\n", argv[1], argv[2]);
    } else {
        printf("%s > %s\n", argv[1], argv[2]);
    }

    return 0;
}