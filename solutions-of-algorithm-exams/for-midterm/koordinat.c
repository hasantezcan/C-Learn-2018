#include <stdio.h>
#include <conio.h>

int main() {
	int n,i,x,y,i1,i2,i3,i4;
	printf("Kac adet nokta cifti gireceksiniz? "); scanf("%d", &n);
	for (i=1; i<=n; i++){
		printf("%d numarali nokta ciftinin x degeri? ", i); scanf("%d", &x);
		printf("%d numarali nokta ciftinin y degeri? ", i); scanf("%d", &y);
			if (x > 0 && y > 0){
				printf("I. Bolgede\n");
				i1++;
			}
			if (x < 0 && y > 0){
				printf("II. Bolgede\n");
				i2++;
			}
			if (x < 0 && y < 0){
				printf("III. Bolgede\n");
				i3++;
			}
			if (x > 0 && y < 0){
				printf("IV. Bolgede\n");
				i4++;
			}
	}/** This part of program is not working for a no reason.
		if (i1>0){
			printf("I. Bolgede %d adet nokta var..\n", i1);
		}
		if (i2>0){
			printf("II. Bolgede %d adet nokta var..\n", i2);
		}
		if (i3>0){
			printf("III. Bolgede %d adet nokta var..\n", i3);
		}
		if (i4>0){
			printf("IV. Bolgede %d adet nokta var..\n", i4);
		}
	**/

	getch();
}