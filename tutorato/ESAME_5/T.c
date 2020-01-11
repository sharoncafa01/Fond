#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct tratta {
    int x, y;
    char alt;
    char tipo;
    double lunghezza;
};

struct percorso {
    struct tratta tratte[10];
    int n_tratte;
    int flag;
    float dist;
};

void stampa_percorso(struct percorso *g)
{
    int i;
    for (i = 0; i < g->n_tratte; ++i) {
        printf("%d %d %c %c (%lf)\n",
                g->tratte[i].x,
                g->tratte[i].y,
                g->tratte[i].alt,
                g->tratte[i].tipo,
                g->tratte[i].lunghezza
                );
    }
}

void stampa_percorsi(struct percorso *g, int n)
{
    int i;
    for (i = 0; i < n; ++i) {
        stampa_percorso(&g[i]);
        puts("");
    }
}

struct percorso *carica(FILE *f, int *tot)
{
    struct percorso *g, *tmp_g;
    char buff[100];
    int i, perc = -1;
    int alloc = 4;
    int campi;
    int x, y;
    char alt, tipo;

    g = malloc(alloc * sizeof(*g));
    if (g == NULL) return NULL;

    while (fgets(buff, sizeof(buff), f)) {
        campi = sscanf(buff, "%d %d %c %c", &x, &y, &alt, &tipo);
        if (campi == 2) {
            perc++;
            g[perc].n_tratte = 1;
            g[perc].tratte[0].x = x;
            g[perc].tratte[0].y = y;
            g[perc].tratte[0].alt = ' ';
            g[perc].tratte[0].tipo = ' ';
        } else {
            g[perc].n_tratte++;
            i = g[perc].n_tratte - 1;
            g[perc].tratte[i].x = x;
            g[perc].tratte[i].y = y;
            g[perc].tratte[i].alt = alt;
            g[perc].tratte[i].tipo = tipo;
        }
        if (perc + 1 >= alloc) {    // faccio la realloc
            alloc *= 2;
            tmp_g = realloc(g, alloc * sizeof(struct percorso));
            if (tmp_g == NULL) return NULL;
            g = tmp_g;
        }
    }
    *tot = perc + 1;
    //stampa_percorsi(g, *tot);
    g = realloc(g, (*tot) * sizeof(*g));
    return g;
}

void stampa_altimetrie(struct percorso *g, int tot)
{
    int p = 0, m = 0;
    int i, j;

    for (i = 0; i < tot; i++) {
        for (j = 0; j < g[i].n_tratte; ++j) {
            if (g[i].tratte[j].alt == 'P') p++;
            if (g[i].tratte[j].alt == 'M') m++;
        }
    }
    printf("%d\n", p);
    printf("%d\n", m);
}

double distanza(int x1, int y1, int x2, int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void calcola_lunghezze_tratte(struct percorso *g, int n)
{
    int xs, ys;
    int i, j;

    for (i = 0; i < n; ++i) {
        xs = g[i].tratte[0].x;
        ys = g[i].tratte[0].y;
        for (j = 1; j < g[i].n_tratte; ++j) {
            g[i].tratte[j].lunghezza =
                distanza(xs, ys, g[i].tratte[j].x, g[i].tratte[j].y);
            xs = g[i].tratte[j].x;
            ys = g[i].tratte[j].y;
        }
    }
}

double lunghezza_percorso(struct percorso *g)
{
    double somma = 0.0;
    int i;

    for (i = 0; i < g->n_tratte; ++i)
        somma += g->tratte[i].lunghezza;   
    return somma;
}

double max_distanza(struct percorso *g, int n)
{
    int i;
    double dist, max = 0.0;

    for (i = 0; i < n; ++i) {
        dist = lunghezza_percorso(&g[i]);
        if (dist > max) max = dist;
    }
    return max;
}

int max_distrib(struct percorso *g, int n)
{
    int distrib[20] = {0};
    int i, j, max;
    for (i = 0; i < n; ++i) {
        for (j = 1; j < g[i].n_tratte; j++) {
            distrib[(int)(g[i].tratte[j].lunghezza / 10)]++;
        }
    }
    max = 0;
    for (i = 0; i < 20; ++i) {
        if (distrib[i] > max) max = distrib[i];
    }
    return max;
}

int conta_tratte(struct percorso *g, int n)
{
    int somma = 0;
    int i;

    for (i = 0; i < n; ++i) {
        somma += g[i].n_tratte;
    }
    return somma;
}

int confronta(const void *p1, const void *p2)
{
    const struct tratta *t1 = p1;
    const struct tratta *t2 = p2;
    double dist1, dist2;

    dist1 = distanza(0, 0, t1->x, t1->y);
    dist2 = distanza(0, 0, t2->x, t2->y);
    if (dist1 > dist2) return 1;
    if (dist1 < dist2) return -1;
    return 0;
}

void stampa_ordinamento(struct percorso *g, int n)
{
    struct tratta *tratte;
    int i, j, tot;
    int tot_tratte = conta_tratte(g, n);

    tratte = malloc(tot_tratte * sizeof(*tratte));

    tot = 0;
    for (i = 0; i < n; ++i) {
        for (j = 1; j < g[i].n_tratte; ++j) {
            tratte[tot] = g[i].tratte[j];
            tot++;
        }
    }
    qsort(tratte, tot, sizeof(*tratte), confronta);
    for (i = 0; i < tot; ++i) {
        printf("%d %d %c %c\n",
                tratte[i].x,
                tratte[i].y,
                tratte[i].alt,
                tratte[i].tipo
                );
    }
    free(tratte);
}

int main(int argc, char *argv[])
{

    struct percorso *g;
    FILE *f;
    int n;

    if (argc != 2) {
        printf("Numero di parametri errato\n");
        return 1;
    }
    if ((f = fopen(argv[1], "r")) == NULL) {
        perror("Errore lettura file");
        return 1;
    }
    g = carica(f, &n);
    fclose(f);
    calcola_lunghezze_tratte(g, n);
    //stampa_percorsi(g, n);
    puts("[ALTIMETRIA]");
    stampa_altimetrie(g, n);
    printf("[MAX-COUNT]\n%d\n\n", max_distrib(g, n));
    printf("[LUNGHEZZA]\n%d\n\n", (int)(round(max_distanza(g, n))));
    puts("[ORDINAMENTO]");
    stampa_ordinamento(g,  n);
    //ordinamento(g, n);
    free(g);
    return 0;
}