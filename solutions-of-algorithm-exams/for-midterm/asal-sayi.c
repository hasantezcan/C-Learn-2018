#include <stdio.h>
#include <conio.h>

int main(){
	int kontrol,n,i,j;
	printf("Lutfen sayi giriniz: "); scanf("%d", &n);
	printf("1-%d arasindaki asal sayilar\n", n);
	for(i=2; i<=n; i++){
		kontrol=0;
		for(j=2; j<i; j++){
			if(i%j==0){
				kontrol++;
			}
		}
		if(kontrol==0){
			printf("%-4d", i);
		}
	}
getch();
}