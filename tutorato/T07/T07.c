#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NMAX 10


struct punto {
    double x; 
    double y; 
};

/* posso definire la struttura in questo modo ed evitare di scrivere ogni volta struct, idem per le altre
typedef struct  {
    double x; 
    double y; 
} punto;*/

struct rettangolo {
    struct punto A;   // alto-sinistra
    struct punto B;   // basso-destra
};




//dichiarazione funzioni
struct punto leggi_punto(void);
void stampa_punto(struct punto p);
double distanza(struct punto p1, struct punto p2);
int interno(struct punto p, struct rettangolo r);
double area_rettangolo(struct rettangolo r);    
void indici_max_dist(struct punto vett[], int lung, int *max_i, int *max_j);  


int main()
{
 struct punto vett[NMAX];
 struct punto origine={0,0};    //assegna 0 a entrambe le variabili (x e y) della struttura
 struct rettangolo rett;
 unsigned int n;
 char s[80];
 int maxI=0,maxJ=0;

//lettura del numero n ed assegnamento del valore massimo in caso di superamento
printf("Inserisci un numero:\n");
fgets(s,sizeof(s),stdin);
n=atoi(s);
if(n>=NMAX)
    n=NMAX;
    
 double d=0;
 int i; 
 
 
 //lettura e acquisizione dei valori dei punti
  for(i=0 ;i<n;i++){
      vett[i]=leggi_punto();
 } 
 
 
 //stampa punti
 printf("[PUNTI]\n");
  for(i=0 ;i<n;i++){
 stampa_punto(vett[i]);
 }
 
 
 //distanza dall'origine
 printf("[DISTANZE]\n");
 for(i=0; i<n; i++){
    d=distanza(origine,vett[i]);
    printf("%.3f\n",d);
    }
 
 
 //acquisizione rettangolo
  rett.A=leggi_punto();
  rett.B=leggi_punto();
 
 //punti interni
 printf("[INTERNI]\n");
 for(i=0 ;i<n;i++){
 if(interno(vett[i],rett)){
     stampa_punto(vett[i]);
}}

 
 //area rettangolo
 printf("[AREA]\n");
 printf("%.3f\n",area_rettangolo(rett));
 
 
 //coppia dei punti più lontani
 printf("[COPPIA]\n");
 indici_max_dist(vett,n,&maxI,&maxJ);
 stampa_punto(vett[maxI]);
 stampa_punto(vett[maxJ]);
 
  
 
  return 0;
}



struct punto leggi_punto(void){
 /* funzione di tipo struct poichè restituisce la variabile p di tipo struct*/
  
  struct punto p;
  char s[80];
  fgets(s,sizeof(s),stdin);
  sscanf(s,"%lf %lf",&p.x, &p.y);  //le coordinate dei punti sono passate per indirizzo 
  return p;
   
}



/*questa funzione stampa le coordinate del punto*/
void stampa_punto(struct punto p){
    
printf("(%.3lf, %.3lf)\n",p.x, p.y);

}



/*questa funzione restituisce la distanza tra due punti*/
double distanza(struct punto p1, struct punto p2)
{
    
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}



/*questa funzione restituisce 1 se il punto e' interno, 0 altrimenti*/
int interno(struct punto p, struct rettangolo r)
{
    if (p.x >= r.A.x && p.x <= r.B.x && p.y >= r.B.y && p.y <= r.A.y)
        return 1;
    else
        return 0;
}



double area_rettangolo(struct rettangolo r)
{
    double b, h;
    b=r.B.x - r.A.x;
    h=r.A.y - r.B.y;
    
    return b*h;
}



void indici_max_dist(struct punto vett[], int lung, int *max_i, int *max_j){


double max,dist;
int i,j;  
*max_i=0;
*max_j=0;
max=distanza(vett[0],vett[1]); 
 
    for(i=0; i<lung-1; i++){
        for(j=i+1; j<lung; j++){                  //calcolano la distanza tra ciascun punto e il successivo
            dist=distanza(vett[i],vett[j]);
            if (dist>max) {
                max=dist;
                *max_i=i;
                *max_j=j;}
    }}
            
}