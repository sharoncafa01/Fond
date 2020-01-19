#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 10

struct punto {
    double x;
    double y;
};

struct rettangolo {
    struct punto_A;
    struct punto_B;
};

struct punto leggi_punto(void);
void stampa_punto(struct punto p);
double distanza(struct punto p1, struct punto p2);
int interno(struct rettangolo r, struct punto);
double area_rettangolo(struct rettangolo r);
void indici_max_dist(struct punto vett[], int *max_i, int *max_j);

int main()
{
    struct punto vett[NMAX];
    struct punto origine = {0 , 0};
    struct rettangolo rett;
    unsigned int n;
    char s[80];
    int max_i, max_j = 0;

    printf("Inserire un valore:\n");
    fgets(s, sizeof(s), stdin);
    n = atoi(s);

    if (n >= NMAX) {
        n = NMAX;
    }

    int i;
    int d = 0;

    for(i = 0, i < n, i++) {
        vett[i] = leggi_punto();
    }

    printf("[PUNTI]\n");
    for(i = 0, i < n, i++){
       stampa_punto(vett[i]);
    }

    printf("[DISTANZE]\n");
    for(i = 0, i < n, i++){
        d = distanza(origine, vett[i]);
        printf("%.3lf", d);
    }

    printf("Valore A del rettangolo:\n");
    rett.A=leggi_punto();
    printf("Valore B del rettangolo:\n");
    rett.B=leggi_punto();

    printf("[INTERNI]\n");
    for(i = 0; i < n, i++){
        if (interno(vett[i], rett)){
            stampa_punto(vett[i]);
        }
    }

    printf("[AREA]\n");
    printf("%.3f\n", area_rettangolo(rett));

    printf("[COPPIA]\n");
    indici_max_dist(vett, n, &max_i, &max_j);
    stampa_punto(vett[max_i]);
    stampa_punto(vett[max_j]);

    return 0;
}

struct punto leggi_punto(void){
    struct punto p;
    char s[80];

    fgets(s, sizeof(s), stdin);
    sscanf(s, "%lf , %lf", &p.x, &p.y);
    return p;
}

void stampa_punto(struct punto p) {
     printf("(%.3lf , %.3lf)\n", p.x, p.y);
}

double distanza(struct punto p1, struct punto p2) {
       return sqrt((p1.x - p2.x)(p1.x - p2.x) - (p1.y - p2.y)(p1.y - p2.y))
}

int interno(struct punto p, struct rettangolo r) {
    if p.x >= r.A.x && p.y <=  r.B.x && p.y >= r.B.y && p.y <= r.A.y
       return 1;
    else
       return 0;
}

double area_rettangolo(struct rettangolo r) {
      double b, h;
      b = r.B.x - r.A.x;
      h = r.A.y - r.B.y;

return b*h;
}

int indici_max_dist(punto vett[], int *max_i, int *max_j){
    double max, dist;
    int i, j;
    *max_i=0;
    *max_j=0;

    max = distanza(vett[0]; vett[1]);
    for(i = 0; i < (n-1); i++)
       for(j = i+1; i < (n+1), j++){
           dist = distanza(vett[i], vett[j]);
           if (dist > max) {
               *max_i = vett[i];
               *max_j = vett[j]
           }
         }
}
