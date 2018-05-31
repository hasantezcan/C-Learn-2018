#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void sirala(int arr[],int eleman); int asalsayiKontrol(int toplam); int pulCek(int e[3]); int topla(int e[3]);

main()
{
	int a,e[3],toplam=0;
	int kontrol;
	int fark,i,size;
	char d = 'E';
	srand(time(NULL));
	printf("Oyuna baslamak icin herhangi bir tusa basiniz.."); getch();
	while(d =='E'){
		
		
		pulCek(e);
		
		for(int i=0;i<3;i++)
		{
			printf("\n-Pul %d = %d",i+1,e[i]);
		}

		toplam=topla(e); 
	
		sirala(e,3);
		fark=e[2]-e[0];
		
		kontrol=asalsayiKontrol(toplam);

		if(toplam<150)
			printf("\nTebrikler, kazandiniz. (1.Kural)");
		
		else if (kontrol==2)
		{
			printf("\nTebrikler, kazandiniz. (2.Kural)");	
		}	
		
		else if (fark > e[1])
		{
			printf("\nTebrikler, kazandiniz. (3.Kural)");		
		}
		
		else 
		{
			printf("\nMalesef kaybettin..!");
		}
			
		printf("\nOyuna devam [e/E]");
		d = getche();
		d = toupper(d);
		printf("\n");
	}
}

//----------------------FONKSIYONLAR-------------------//

void sirala(int arr[],int eleman){
	int i,j;
	for(i=0; i<eleman ;i++){
		for(j=1; j<eleman-i;j++){
			if(arr[j-1] > arr[j]){
				int kutu = arr[j];
				arr[j] = arr[j-1]; 
				arr[j-1] = kutu;	
			}
		}
	}
}

int asalsayiKontrol(int toplam)
{
	int j,kontrol=0;
	for(j=toplam;j>0;j--)
			{
				if(toplam%j==0)
					kontrol++;
			}	
		return kontrol;			
}

int pulCek(int e[3])
{

	for(int i=0;i<3;i++)
		{
			e[i]=(rand()%99+1);
			
			if(e[0]==e[1])
				e[0]=(rand()%99+1);
			
			else if (e[1]==e[2])
				e[1]=(rand()%99+1);
			
			else if  (e[0]==e[2])
				e[2]=(rand()%99+1);
		}
	return e[3];		
}

int topla(int e[3])
{
	int toplam=e[0]+e[1]+e[2];
	//	printf("\ntoplam = %d",toplam);
		
		return toplam;
}

