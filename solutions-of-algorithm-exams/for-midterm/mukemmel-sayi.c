#include <stdio.h>
#include <conio.h>

int main(){
	int i,j,n,bolenler;
	printf("Lutfen sayiyi giriniz: ");scanf("%d", &n);
	for(i=0; i<=n; i++){
		bolenler = 0;
		for(j=1; j<i; j++){
			if(i%j==0){
				bolenler+=j;
			}
		}
		if(i==bolenler){
			printf("%-4d",i);
		}
	}
getch();
}