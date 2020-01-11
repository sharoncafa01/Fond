#include <stdio.h>
#include <stdlib.h>

int main ()
{
    double a;
    int b;
    double risultato;
    char s [80];
    
    fgets (s, sizeof (s), stdin);
    a = atof (s);
    fgets (s, sizeof (s), stdin);
    b = atoi (s);
    
    if (b < 0 )  {
        printf ("non calcolabile");
    }
    else  {
            risultato = 1 ;
        while  ((b >  0) || (a == 0 && b==0))  {
            if (b % 2 == 1) 
                risultato = risultato * a ;
                a = a * a ;
                b = b / 2 ;
        }
        printf ("[POTENZA]\n");
        printf ("%f\n", risultato);
        
    }
    return 0;
}


    

    
    