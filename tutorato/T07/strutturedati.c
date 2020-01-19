#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 10

struct punto_t {
    double x;
    double y;
}

struct rettangolo_t {
    struct punto_A;
    struct punto_B;
}

struct punto_t leggi_punto(void);
void stampa_punto(struct punto_t p);
double distanza(struct punto_t p1, struct punto_t p2);
int interno(struct rettangolo_t r, struct punto_t);
double area_rettangolo(struct rettangolo_t r);
void indici_max_dist(struct punto_t vett[], int *max_i, int *max_j);

int main()
{
    struct punto_t vett[NMAX];
    struct punto_t origine = {0 , 0};
    struct rettangolo_t rett;
    unsigned int n;
    char s[80];
    int max_i, max_j = 0;

    printf("Inserire un valore:\n");
    fgets(s, sizeof(s), stdin);
    n = atoi(s);

    if (n >= 10) {
        n = NMAX;
    }

    int i;
    int d = 0;

    for(i = 0, i < n, i++){
        vett[i] = leggi_punto();
    }

    printf("[PUNTI]\n");
    for(i = 0, i < n, i++){
       stampa_punto(vett[i]);
    }

    printf("[DISTANZE]\n");
    for(i = 0, i < n, i++){
        d = distanza(origine, vett[i];
        printf("%.3lf", d));
    }

    printf("Valore A del rettangolo:\n");
    rett.A=leggi_punto();
    printf("Valore B del rettangolo:\n");
    rett.B=leggi_punto();

    printf("[INTERNI]\n");
    for(i = 0; i < n, i++){
        if (interno(vetti[i], rett)){
            stampa_punto(vett[i]);
        }
    }

    printf("[AREA]\n");
    printf("%.3f\n", area_rettangolo(rett));

    printf("[COPPIA]\n");
    indici_max_dist(vett, n, &max_i, &max_j);
    stampa_punto(max_i);
    stampa_punto(max_j);

    return 0;
}

struct punto_t leggi_punto(void){
    struct punto p;
    char s[80];

    fgets(s, sizeof(s), stdin);
    sscanf(s, "%lf , %lf", &p.x, &p.y)
}