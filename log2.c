//From lecture
#include <stdio.h>
#include <math.h>

//add a prototype to make sure there are no errors.
//a prototype is like the declaration of a function,
//it is possible to prototype a function multiple times,
//it is possible to declare a function that does not exist.
//In general, we should just declare functions that we define and use.
double log2(double x);

int main(void){
	double x = 512.0;
	printf("log2(%g) = %g\n", x, log2(x));
}

//this is the definition of a function
//we can declare a function only once
double log2(double x){
	double res = log(x)/log(2.0);
	return res;
}
//This is an implicit cast: (this is NOT ok).
// int x = 1337;
//char c = x; //donwsize cast
//This is explicit cast: (this MAY be okay).s
//int x = 1337;
//char c = (char)x;