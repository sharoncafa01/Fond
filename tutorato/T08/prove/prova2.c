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
    int AAAA, MM, GG;
    int hh, mm, ss, ms;
    char id[11];
    int umid;
    float TEMP, vel, min_temp;
    char buf[1000];
    int n, nconv;

    puts("[NOTTURNO]");
    n = 0; 
    min_temp = 3000.0;

    while(fgets(buf, sizeof(buf), f)){
        nconv = sscanf(buf, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f", 
            &AAAA, &MM, &GG,  
            &hh, &mm, &ss, &ms, 
            id, &TEMP, &umid, &vel);

        if (nconv != 11) continue;

        if (TEMP < min_temp) min_temp = TEMP;

        if (notturno(hh)) {
            printf("%s", buf);
        }

    n++;
    }

    printf("[MAX-TEMP]\n");
    printf("%.1f\n", min_temp);

    printf("[RIGHE]\n");
    printf("%d\n", n);
}

int notturno(int h){
    if ((h >= 22) || (h <= 5)) return 1;
    return 0;
}
