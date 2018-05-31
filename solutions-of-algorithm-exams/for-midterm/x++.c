#include <stdio.h>
#include <conio.h>

int main(){
	int x,y,z;
	x=10;
	y=x/2;
	z=y+x;
	printf("x=%d y=%d, z=%d\n", x++, --y,z);
	printf("%d\n", z);
	getch();
}