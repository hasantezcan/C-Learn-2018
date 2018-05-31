//Verilen bir kelimenin palindrome olup olmadigini kontrol eden kod
#include <stdio.h>
#include <string.h>

main(){

	char kelime[100],ayna[100];
	
	
	printf("Bir kelime giriniz.. =");
	scanf("%s",&kelime);
	
	strcpy(ayna,kelime);
	strrev(ayna);
	
	if(strcmp(kelime,ayna) == 0)   
		printf("Kelimeniz polindrome bir kelimedir");
	else
		printf("Kelimeniz polindrome bir kelime DEGILDIR!!");
	printf ("\n\n%s",ayna);
}

