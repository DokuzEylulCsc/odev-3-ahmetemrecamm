#include <iostream>
#include <fstream>
using namespace std;
/* Ahmet Emre Cam 2013280043 */
void siralama(int dizi[],int sayi) /* bubble sort siralamasi ile notlari siralama */
	{	
	int temp;
		for(int i = 0; i < sayi; i++)
		{
	    	for(int j = 0; j < sayi-1; j++)
			{  
				if(dizi[i] < dizi[j])
				{  
	                temp = dizi[j];
	                dizi[j] = dizi[i];
	                dizi[i] = temp;	
	            }
	        }
	    }	
	}
double ortBulma(int dizi[],int sayi)
	{
		double Ort;
		for (int i = 0; i < sayi; i++)
		{
			Ort += dizi[i];
		}
		return Ort = Ort / sayi;;
	}
int medyanBulma(int dizi[],int sayi)
	{
	int Medyan,medyanTemp;
	medyanTemp=sayi/2;
	if(sayi%2==0)
	{
	Medyan=dizi[medyanTemp];
	return Medyan;
	}
	else
	Medyan=(dizi[medyanTemp]+dizi[medyanTemp+1])/2; /* eger ogrenci sayisi tekse ortadaki sayilarin ortalamasini alma */
	return Medyan;
	
	}
		
int main()
{
	ifstream Dosya;
	int toplamSoru,ogrenciSayisi;	
	Dosya.open("input.txt");
	ofstream Dosya2;
	Dosya2.open("output.txt");
	int aciklik,maxNot,max,min,notlar=0;
	Dosya >> toplamSoru; 
	string cevapAnahtari[toplamSoru] = {}; 
	for (int i=0; i<toplamSoru; i++)
	{
		Dosya >> cevapAnahtari[i];
	}	
	Dosya >> ogrenciSayisi;
	string ogrenciler [ogrenciSayisi][toplamSoru+1] = {}; /* input dosyasýndaki bilgileri diziye aktarma */
	for (int i=0; i<ogrenciSayisi; i++)
	{
		for (int j=0; j<(toplamSoru+1); j++)
		{
			Dosya >> ogrenciler [i][j];
		}
	}
	int Sonuc[ogrenciSayisi] = {}; 
	for (int i=0; i<ogrenciSayisi; i++) /* cevaplara göre puanlandýrma */
	{
		notlar = 0; 
		for (int j=0; j<toplamSoru; j++)
		{			
			if (ogrenciler[i][j+1] == cevapAnahtari[j]) 
			notlar = notlar + 4; 		
				
			else if (ogrenciler[i][j+1] == "f") /* boþ soruyu f olarak tanýmladým */
			notlar = notlar + 0; 	
					
			else
			notlar = notlar - 1; 
						
			if (notlar<0) 
			notlar = 0;
		}
		Sonuc[i] = notlar; 
	}
	maxNot = (toplamSoru*4);
	for (int i=0; i<ogrenciSayisi; i++)
	{
		Sonuc[i] = (Sonuc[i] * 100) / maxNot; /* puanı 100 luk sisteme cevirme */
	}	
	siralama(Sonuc,ogrenciSayisi);
	max=Sonuc[ogrenciSayisi-1]; /* dizi artik sirali oldugu için dizinin son elemani max ilk elamani min oluyor( dizi 0 dan basladigindan toplam elaman sayisindan -1 cikarirsan son elamani buluruz */
	min=Sonuc[0];
	aciklik=max-min;
	Dosya.close();
	for(int i = (ogrenciSayisi-1); i>=0; i--) /* odevde istenildigi gibi max tan mine siralama */
	{
		Dosya2 << ogrenciler[i][0] << ","; /* dizidekileri dosyaya yazdirma */
		Dosya2 << Sonuc[i] << endl;
	}
	Dosya2 << "En yuksek not= "<< max << " En dusuk not= " << min << " Sinif ortalamasi= " << ortBulma(Sonuc,ogrenciSayisi) << " Sinif medyani= " << medyanBulma(Sonuc,ogrenciSayisi) << " Sinifin Acikligi= " << aciklik;	
	cout <<endl << "Tamamlandi." << endl;	
	Dosya2.close();	
	return 0;
	/* c++ i iyi bilmedigim icin c gibi yazýp sonra c++ a cevirdim o yüzden kod karmasikligi olabilir */
	/*KAYNAKCA http://anaturb.net/C/string_exapm.htm
				http://www.cplusplus.com/doc/tutorial/files/*/
}
