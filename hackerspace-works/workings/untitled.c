#include <stdio.h>


void topla(int a, int b, int *sonuc){
	*sonuc = a + b;
	printf("%p\n", sonuc);
}


int main(int argc, char const *argv[])
{
	/* #1
	int a = 5;
	int *b = &a;
	printf("%p\n", b);
	*/

	#2
	int a = 5;
	int b = 7;
	int sonuc;
	topla(a, b, &sonuc);
	printf("%d\n", sonuc);

	

	return 0;
}