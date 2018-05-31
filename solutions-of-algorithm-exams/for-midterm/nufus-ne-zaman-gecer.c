#include <stdio.h>
#include <conio.h>
int main(){
	int denizli=265000;
	int samsun=315000;
	int yil=2000;

	while(denizli<samsun){
		denizli=denizli+(float)denizli*0.024;
		samsun=samsun+(float)samsun*0.019;
		yil++;
	}

	printf("%d", yil);
getch();
}