#include <stdio.h>
#include <conio.h>

int main(){
	/*if(10>=4>=3) şeklinde olsa yanlış çıktı verirdi. 
	c'de hepsi ayrı ayrı girilmelidir. 10>=4 sonucunu 1 alıp, 1>=3 sonucunu
	yanlış diye basar.*/
	printf("%d\n", 10>=4);
	if(10>=4 && 4>=3){
		printf("a\n");
	}
	else{
		printf("b\n");
	}
	getch();
}