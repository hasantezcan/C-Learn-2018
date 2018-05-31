#include <stdio.h>
void stringKopyala(char *, char *);

int main(){
	char s1[BUFSIZ], s2[BUFSIZ];
	printf("S1 degiskeni icin cumle giriniz:"); fgets(s1, 100, stdin);
	stringKopyala(s2, s1);
	puts(s2);

	return 0;
}

void stringKopyala(char *s1, char *s2){
	for(int i=0; s2[i] != '\0'; i++){
		s1[i] = s2[i];
	}
}