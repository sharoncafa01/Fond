#include <stdio.h>

int main()
{

  double euro = 123.10;
  double cambio_euro_dollaro = 1.18213;  
  double dollari;                         


  dollari = euro * cambio_euro_dollaro;


  printf("Importo in euro : %.2f\n", euro);
  printf("Importo in dollari : %.2f\n", dollari);
  
}