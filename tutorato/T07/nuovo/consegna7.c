#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 10

struct punto_t {
    double x;
    double y;
};

struct rettangolo_t {
    struct punto_t A;
    struct punto_t B;
};

struct punto_t leggi_punto(void);
void stampa_punto (struct punto_t p);
double distanza(struct punto_t p1, struct punto_t p2);
int interno(struct punto_t p, struct rettangolo_t r);
double area_rettangolo(struct rettangolo_t r);

int main()
{
    struct punto_t vett[MAXN];
    struct punto_t origine ={0, 0};
    struct rettangolo_t rett;
    unsigned n;
    char s[80];

    printf("Inserisci valore n:\n");
    fgets(s, sizeof(s), stdin);
    n = atoi(s);

    if ( n >= MAXN)
       n = MAXN;

    int i;
    int d = 0;

    printf("Inserisci valori: \n");
    for (i = 0; i < n; i++)
      vett[i] = leggi_punto();

    printf("[PUNTI]\n");
    for (i=0; i < n; i++)
    stampa_punto(vett[i]);

    printf("[DISTANZE]\n");
    for (i=0; i < n; i++)
        d = distanza(origine, vett[i]);
        printf("%.3lf\n", d);

    printf("Inserire valori A e B:\n");
    rett.A = leggi_punto();
    rett.B = leggi_punto();

    printf("[INTERNI]\n");
    for (i=0; i < n; i++)
        if (interno(vett[i], rett))
           stampa_punto(vett[i]);

    printf("[AREA]\n");
    printf("(%.3lf)\n", area_rettangolo(rett));

return 0;
}

struct punto_t leggi_punto(void)
{
    struct punto_t p;
    char s[80];
    fgets(s, sizeof(s), stdin);
    sscanf(s, "%.lf , %.lf", &p.x, &p.y);

    return p;
}

void stampa_punto (struct punto_t p)
{
    printf("(%.3lf %.3lf)", &p.x, &p.y);
}

double distanza(struct punto_t p1, struct punto_t p2)
{
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));

}

int interno(struct punto_t p, struct rettangolo_t rett)
{
    if (p.x > rett.A.x && p.x < rett.B.x && p.y > rett.B.y && p.y < rett.A.y)
        return 1;
    else 
        return 0;
}

double area_rettangolo(struct rettangolo_t rett)
{
    double b, h;
    b = (rett.B.x - rett.A.x);
    h = (rett.A.y - rett.B.y);

 return b*h;
}