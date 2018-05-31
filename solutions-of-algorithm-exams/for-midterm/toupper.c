#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int main(){
	char cumle[BUFSIZ];
	printf("Bir cumle giriniz..\n");
	gets(cumle);
	int x = strlen(cumle);
	cumle[0] = toupper(cumle[0]);
	for(int i=1; i<x; i++){
		if(cumle[i]==' ' && cumle[i+1]!=' '){
			cumle[i+1]=toupper(cumle[i+1]);
		}
	}
	puts(cumle);
	getch();
}