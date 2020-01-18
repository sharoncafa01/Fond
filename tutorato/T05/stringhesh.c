#include <stdio.h>
#include <stdlib.h>

int trova_ultimo_separatore(const char *percorso)
{
    int pos;
    pos = (strlen(percorso) - 1);

    while (pos >= 0 && percorso[pos] != '/')
          pos--;
    return pos;
}

void basename(const char *percorso, char *b)
{
    int pos = (trova_ultimo_separatore(percorso) + 1);
    int i;
    int f = (strlen(percorso) - 1);

    for(i = pos ; i < f; i++)
          b[i] = percorso[i];

    printf("%s\n", b);

}

void dirname(const char *percorso, char *b)
{
    int i;
    int n = trova_ultimo_separatore(percorso);

    if (n >= 0 ) {
       for(i = 0; i < n; i++)
          b[i] = percorso[i];
          b[n] = '\0';
          puts(b);
       }
    else
        b[0] = '\0';


}

int tipo_percorso(const char *percorso)
{
    if (percorso[0] == '\'') {
        printf("ASSOLUTO\n");
    }
    else
        printf("RELATIVO\n");
}

int trova_ultimo_punto(const char *percorso)
{
    int posi = (strlen(percorso) - 1);
    while (posi >= 0 && percorso[posi] != '.')
         posi--;

    return posi;
}

int trova_ultimo_carattere(const char *percorso)
{
    int pnt = (trova_ultimo_punto(percorso) + 1);

    if (percorso[pnt] != '\0')
      printf("%s\n", percorso[pnt]);
    else
      printf("nessuna\n");
}

int main(int argc, char *argv[])
{
    int percorso[1024];
    int pos[1024];
    int b[1024];

    if (argc != 2) {
        printf ("Numero di parametri errato.\n");
        return -1;
    }

    strcpy(percorso, *argv);

    printf("[BASENAME]\n");
    basename(percorso, b);

    printf("[DIRNAME]\n");
    dirname(percorso, b);

    printf("[TIPO]\n");
    tipo_percorso(percorso);

    printf("[ESTENSIONE]\n");
    trova_ultimo_carattere(percorso);

return 0;
}