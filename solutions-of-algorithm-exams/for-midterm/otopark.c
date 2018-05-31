#include <stdio.h>
#include <conio.h>

int main(){
	int sure;
	int ucret=0;
	printf("Kalis suresini giriniz: "); scanf("%d", &sure);

	for(int i=sure; i>0; i-=24){
		if(i<=1)
			ucret+=2;
		else if(i<=2)
			ucret+=3;
		else if(i<=4)
			ucret+=5;
		else if(i<=8)
			ucret+=8;
		else if(i<=24)
			ucret+=12;
		else
			ucret+=12;
	}
	printf("Odenecek miktar: %d TL", ucret);
getch();

}