#include <stdio.h>

int main()
{
    double eu = 100;
    double dollaro;
    double tasso = 1,18213;

    dollaro = (eu * tasso);

    printf("Importo in euro: %.2f/n", eu);
    printf("Importo in dollari: %.2f/n", dollaro);

    return 0;

}