#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

 float basarinotlari();
 float ortalama();
 float standartsapma();
 void harf();
 void harfYazdir();
 
 struct ogrTip
    {   unsigned long ogrNo;
        char ad[15];
        char soyad[15];
        unsigned vize;
        unsigned final;
        unsigned proje;
        unsigned short devam;
        float bNotu;
        char harf[2];
    }ogr[BUFSIZ] ={0,"","",0,0,0,0,0,""};
    
    int N;  // OGRENCI SAYACI 
    int A1=0,A2=0,B1=0,B2=0,C1=0,C2=0,D1=0,D2=0,E=0,F1=0,F2=0;
    
main()
{
    FILE *fp ,*fp2;
	fp=fopen("CENG101_IN.txt","r");
    
    if(fp==NULL)
    	printf("Dosya Bulunamadi...");
    	
    else
	{
	
	    int i=0;
		while(!feof(fp))
			{
				fscanf(fp,"%u\t%s\t%s\t%u\t%u\t%u\t%d",&ogr[i].ogrNo, ogr[i].ad, ogr[i].soyad, &ogr[i].vize, &ogr[i].final, &ogr[i].proje, &ogr[i].devam);
				//	printf("%d\t%d\t\n",pers[i].persNo, pers[i].satis);
				i++;
			}	
		N=i;
		fclose(fp);
		
		for(int i=0; i<N; i++)
	    {
	        fscanf(fp,"%u\t%s\t%s\t%u\t%u\t%u\t%d",&ogr[i].ogrNo, ogr[i].ad, ogr[i].soyad, &ogr[i].vize, &ogr[i].final, &ogr[i].proje, &ogr[i].devam);
	    }
	    fclose(fp);
	    
		basarinotlari();
	    float stdsapma=standartsapma();
	    harf();  //HARFLERI HESAPLADI
	
	//GORUNTULEME KISMI  ....
		printf("OGRENCI#\tAD\tSOYAD\t       VIZE   FINAL   PROJE   B.NOTU   HARF\n");
		printf("===========================================================================\n");
			
			for(int i=0; i<N; i++)
			    {
			        printf("%u\t%s\t%s\t\t%u\t%u\t%u\t%3.0f\t%s\n",ogr[i].ogrNo, ogr[i].ad, ogr[i].soyad, ogr[i].vize, ogr[i].final, ogr[i].proje, ogr[i].bNotu,ogr[i].harf);
			    }
			    
	    printf("Ogrenci Sayisi = %d\n",N);
	    printf("Basari Notlari Ortalamasi = %.2f\n",ortalama());
	    printf("Basari Notlari Standart Sapmasi = %.2f\n",stdsapma);
	  
	    harfYazdir();//HARF LISTESI
		
	//DOSYAYA YAZDIRMA KISMI================================>
	
		fp2=fopen("CENG101_OUT.txt","w");
		
		fprintf(fp2,"OGRENCI#\tAD\tSOYAD\t       VIZE   FINAL   PROJE   B.NOTU   HARF\n");
		fprintf(fp2,"===========================================================================\n");
			
			for(int i=0; i<N; i++)
			    {
			        fprintf(fp2,"%u\t%s\t%s\t\t%u\t%u\t%u\t%3.0f\t%s\n",ogr[i].ogrNo, ogr[i].ad, ogr[i].soyad, ogr[i].vize, ogr[i].final, ogr[i].proje, ogr[i].bNotu,ogr[i].harf);
			    }
			    
	    fprintf(fp2,"Ogrenci Sayisi = %d\n",N);
	    fprintf(fp2,"Basari Notlari Ortalamasi = %.2f\n",ortalama());
	    fprintf(fp2,"Basari Notlari Standart Sapmasi = %.2f\n",stdsapma);
	
	fprintf(fp2,"Harf Notlari Dagilimlari:\n");
			fprintf(fp2,"A1= %d\n",A1);
			fprintf(fp2,"A2= %d\n",A2);
			fprintf(fp2,"B1= %d\n",B1);
			fprintf(fp2,"B2= %d\n",B2);
			fprintf(fp2,"C1= %d\n",C1);
			fprintf(fp2,"C2= %d\n",C2);
			fprintf(fp2,"D1= %d\n",D1);
			fprintf(fp2,"D2= %d\n",D2);
			fprintf(fp2,"E = %d\n",E);
			fprintf(fp2,"F1= %d\n",F1);
			fprintf(fp2,"F2= %d\n",F2);
		
	
		fclose(fp2);
		
	// dosya yazdirma bitti ============>	
	}
}


float standartsapma()   //Ötelenmis notlarin standart sapmasi
{					
	float stp=0,gonder;
	for(int i=0; i<N; i++)
		{
			stp = pow(ogr[i].bNotu - ortalama(), 2) + stp;
			
	   	}
	gonder = sqrt(stp/(N-1));
	return gonder;
}

float basarinotlari()
{
	float a[BUFSIZ],b[BUFSIZ],c[BUFSIZ];

	for(int i=0;i<N;i++)
	{
		a[i]=ogr[i].vize;
		b[i]=ogr[i].final;
		c[i]=ogr[i].proje;
		
		ogr[i].bNotu=(a[i]*30/100)+(b[i]*40/100)+(c[i]*30/100);	
 	}
 	return ogr[0].bNotu;
}
  
float ortalama()
{ 	
	float t;
	int i;
	t = 0;
	for (i=0; i<N; i++)
		t = t + ogr[i].bNotu;
	float ort = t / N;
	return ort;
}

void harf() 
{ 

	for(int i=0;i<N;i++)
	{
		if(ogr[i].devam==0)
			{F2++; strcpy( ogr[i].harf, "F2" );}
		else if(ogr[i].bNotu>=89.50)
			{A1++; strcpy( ogr[i].harf, "A1" );}
		else if(ogr[i].bNotu >= 79.50)
			{A2++; strcpy( ogr[i].harf, "A2" );} 	
		else if(ogr[i].bNotu>=74.50)
			{B1++; strcpy( ogr[i].harf, "B1" );}
		else if(ogr[i].bNotu>=69.50)
			{B2++; strcpy( ogr[i].harf, "B2" );}
		else if(ogr[i].bNotu>=64.50)
			{C1++; strcpy( ogr[i].harf, "C1" );}
		else if(ogr[i].bNotu>=59.50)
			{C2++; strcpy( ogr[i].harf, "C2" );}
		else if(ogr[i].bNotu>=54.50)
			{D1++; strcpy( ogr[i].harf, "D1" );}
		else if(ogr[i].bNotu>=49.50)
			{D2++; strcpy( ogr[i].harf, "D2" );}
		else if(ogr[i].bNotu>=39.50)
			{E++;  strcpy( ogr[i].harf, "E" );}
		else
			{F1++; strcpy( ogr[i].harf, "F1" );}
	}	
}

void harfYazdir()
{
	printf("Harf Notlari Dagilimlari:\n");
		printf("A1= %d\n",A1);
		printf("A2= %d\n",A2);
		printf("B1= %d\n",B1);
		printf("B2= %d\n",B2);
		printf("C1= %d\n",C1);
		printf("C2= %d\n",C2);
		printf("D1= %d\n",D1);
		printf("D2= %d\n",D2);
		printf("E = %d\n",E);
		printf("F1= %d\n",F1);
		printf("F2= %d\n",F2);		
}

