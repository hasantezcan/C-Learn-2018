// fibonaci dizisinin ilk 100 elemani...

#include<stdio.h>

main(){

	float F[99];
	F[0]=1;
	F[1]=1;
	
	for(int i=0; i<100; i++){
            F[i+2]=F[i+1]+F[i];
	}

	for(int i=0; i<100; i++){
            printf("\n%f",F[i]);
        }

}
