#include <stdio.h>
int main(){
	int a,b,c;
	for(a=0;a<100;a++){
		for(b=0;b<=a;b++){
			for(c=0;c<=b;c++){
				if(a*b*c==3*(a+b+c))
					printf("%2d, %2d, %2d\n", a,b,c);
			}
		}
	}
}