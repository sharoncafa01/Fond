#include <stdio.h>
#include <stdlib.h>

#define DIM 20

 int main()
{
    char nome[DIM], cognome[DIM], s[DIM];

    strcpy(s, "");
    strcpy(nome, "Albert");
    strcpy(cognome, "Einstein");

    strcat(s, nome);
    strcat(s, " ");
    strcat(s, cognome);

    puts(s);

    printf("Lunghezza: %i\n", strlen(s));

    puts(strstr(s, "in"));


    puts(strchr(s, 'e'));
    puts(strrchr(s, 'e'));
}