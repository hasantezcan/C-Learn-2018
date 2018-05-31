#include <stdio.h>
#include <conio.h>

/*do_while'de önce işlem yapılır daha sonra kontrol yapılır while ile*/
int main(){
	int x=0;
	do {
		printf("hello\n");
		x++;
	}
	while(x<10);
getch();
}