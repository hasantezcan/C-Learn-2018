#include <stdio.h>
#include <conio.h>
#define PI 3.14
int main(){
	float a, r;
	printf("Please type your \"r\"! ");
	printf("\t r = "); scanf("%f", &r);
	a=PI*r*r;
	printf("Area of your circle : %.2f\n", a);
	getch();
	}
