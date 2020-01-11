#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    char s[80];
    
    fgets(s, sizeof(s), stdin);
    a = atoi(s);
    fgets(s, sizeof(s), stdin);
    b = atoi(s);
    fgets(s, sizeof(s), stdin);
    c = atoi(s);
    
    if (((a > b ) && (a < c)) || ((a < b) && (a > c))){
      printf("[MEDIANA]\n");
      printf("%d\n", a);
    }if (((b > a ) && (b < c)) || ((b < a) && (b > c))){
      printf("[MEDIANA]\n");
      printf("%d\n", b);
    }if (((c > a ) && (c < b)) || ((c < a) && (c > b))){
      printf("[MEDIANA]\n");
      printf("%d\n", c); 
    }


    return 0;
}

