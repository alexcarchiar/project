#include <stdio.h>
#import <math.h>

int main()
{
  float a, b, c, delta, asse, vx, vy, fx, fy, dir;
  printf("Calcolo i punti notevoli delle parabole\n");
  printf("La parabola deve essere nella forma y=ax^2 + bx + c\n");
  printf("Dammi a: ");
  scanf("%f", &a);
  printf("Dammi b: ");
  scanf("%f", &b);
  printf("Dammi c: ");
  scanf("%f", &c);
  delta = b*b - 4*a*c;
  vx = -b/(2*a);
  vy = -delta/(4*a);
  fx = vx;
  fy = (1-delta)/(4*a);
  asse = -b/(2*a);
  dir = -(1+delta)/(4*a);
  printf("Il vertice ha coordinate: (");
  printf("%f", vx);
  printf(";");
  printf("%f", vy);
  printf(")\n");
  printf("Il fuoco ha coordinate: (");
  printf("%f", fx);
  printf(";");
  printf("%f", fy);
  printf(")\n");
  printf("La direttrice ha equazione: y = ");
  printf("%f \n", dir);
  printf("L'asse ha equazione: x = ");
  printf("%f", asse);
	return 0;
}
