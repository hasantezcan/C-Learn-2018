#include <stdio.h>

union paylas{
	int x;
	char y;
} a;

int main(int argc, char const *argv[]){
	a.x = 10;
	a.y = 'A';
	a.x++;
	printf("x=%d\ny=%c\n\n", a.x,a.y);

	char c = 'a';
	printf("%d\n", c);
	return 0;
}