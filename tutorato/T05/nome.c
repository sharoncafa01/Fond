#include <stdio.h>
#include <stdlib.h>

void stampa_stringa(const char *str);

int main()
{
    char cognome[20];

    strcpy(cognome, "Einstein");
    stampa_stringa(cognome);
}

void stampa_stringa(const char *s)
{
    printf("<%s>\n", s, strlen(s));
}