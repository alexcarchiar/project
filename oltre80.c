#include <stdio.h>

int main()
{	
  printf("Calcolo il costo della chiamata con offerta Oltre80\n");
  int i, sec;  
  i = 1;
  float costo;
  costo = 0.10;
  printf("Quanto durera' la telefonata?\n");
  scanf("%d", &sec);
  for(i=0; i<sec; i++)
  {
   
    if (i < 80)
      costo = costo + 0.15;
    else
      costo = costo + 0.09;
    
  }
  
  printf("Il costo della chiamata e': ");
  printf("%f", costo);
  printf(" euro");
  
  return 0;
}
