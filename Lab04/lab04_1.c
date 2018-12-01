//Lab04, exercise 1
//Program to solve quadratic equations
#include <stdio.h>
#include <math.h>

int main {
	
	float a, b, c, x1, x2, delta;
	printf("I solve equations of the type ax^2 + bx + c = 0\na = \n");
	scanf("%g", &a);
	printf("b = \n");
	scanf("%g", &b);
	printf("c = \n");
	scanf("%g", &c);
	delta = b*b - 4*a*c;
	if(delta == 0){
		x1 = (-b /(2*a);
		printf("The solution is %g", x1);	
	} else if(delta < 0)
		printf("No real roots");
	else{
		x1 = ((-b + sqrt(delta)) /(2*a);
		x2 = ((-b - sqrt(delta)) /(2*a);
		printf("The solutions are %g  %g", x1, x2);
}

	return 0:
}
