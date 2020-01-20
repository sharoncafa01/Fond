#include <stdio.h>
#include <stdlib.h>

void elabora_file(FILE *f);
int notturno(int h);

int main(int argc, const char *argv[])
{
    FILE *infile;

    if (argc != 2)
      return 1;

    infile = fopen(argv[1], "r");

    if (infile == NULL) {
        fprintf(stderr, "#Errore apertura file.\n");
        return 1;
    }

    elabora_file(infile);
    fclose(infile);

return 0;
}

void elabora_file(FILE *f){

    char buf[1000];
    int n;                 // numero di righe lette
    int nconv;             // numero di elementi convertiti
    float max_temp;        // temperatura massima
    int aa, MM, gg;        // data
    int hh, mm, ss, ms;    // orario
    char id[11];           // identificativo del dispositivo
    float temp;            // temperatura
    int umid;              // umidità
    float vel;             // velocità del vento

    puts("[NOTTURNO]");
    n = 0;
    max_temp = -300.0;

    while (fgets(buf, sizeof(buf), f)) {
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f",
        &aa, &MM, &gg,
        &hh, &mm, &ss, &ms,
        id, &temp, &umid, &vel);

        if (nconv != 11) continue;

        if (temp > max_temp) max_temp = temp;

        if (notturno(hh)) printf("%s", buf);

        n++;
    }

    printf("\n[MAX-TEMP]\n%.1f\n", max_temp);
    printf("\n[RIGHE]\n%d\n", n);
}

int notturno(int h)
{
    if ((h >= 22) || (h <= 5)) return 1;
    return 0;
}