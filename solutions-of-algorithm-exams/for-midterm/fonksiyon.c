#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(){
	float x;
	for(x=0; x<10; x=x+0.5){
		float f = 2*pow(x,3)+5*pow(x,2)+3*x-1;
		printf("x = %d icin F(x) = %7.2f\n", x, f);
	}
getch();
}