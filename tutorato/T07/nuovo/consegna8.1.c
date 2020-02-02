#include <stdio.h>
#include <stdlib.h>

void elabora_file(FILE *infile);
int notturno(int h);

int main(int argc, char *argv[])
{
    FILE *infile;

    if (argc != 2)
       return 1;

    infile = fopen(argv[1], "r");

    if (infile == NULL)
        fprintf(stderr, "#Errore apertura file\n");
        return 1;

    elabora_file(infile);
    fclose(infile);

return 0;
}

void elabora_file(FILE *infile){
    int AAAA, MM, GG;
    int hh, mm, ss, ms;
    char id[11];
    int umid;
    float TEMP, vel, max_temp;
    char buf[100];
    int n, nconv;

    puts("[NOTTURNO]\n");
    n = 0; nconv = 0;
    max_temp = -2000;

    while(fgets(buf, sizeof(buf), infile)){
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f", &AAAA, &MM, &GG, &hh, &mm, &ss, &ms, id, &TEMP, &umid, &vel);

        if (nconv != 11) continue;

        if (TEMP > max_temp)
            max_temp = TEMP;

        n++;
    }

    printf("[MAX-TEMP]\n");
    printf("%f", max_temp);

    printf("[RIGHE]\n");
    printf("%d", n);
}

int notturno(int h){
    if (h >= 22 && h <= 5)
        return 1;
}