#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(){
	char yazi[100];
	int sayac;
	printf("cumle: ");gets(yazi);
	int uzun = strlen(yazi);

	for (int i=0; i<100; i++){
		if (yazi[i]=='a' || yazi[i]=='A'){
			sayac++;
		}
	}
	printf("%d kadar a harfi var\n", sayac);
	getch();
}