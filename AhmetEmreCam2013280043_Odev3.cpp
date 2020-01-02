#include <iostream>
#include <fstream>
using namespace std;
/* Ahmet Emre Cam 2013280043 */
void siralama(int dizi[],int sayi) /* bubble sort siralamas� ile notlar� s�ralama */
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
	Medyan=(dizi[medyanTemp]+dizi[medyanTemp+1])/2; /* eger ogrenci say�s� tekse ortadaki say�lar� toplay�p 2 ye b�lere medyan� bulma */
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
	string ogrenciler [ogrenciSayisi][toplamSoru+1] = {}; /* input dosyas�ndaki bilgileri diziye aktarma */
	for (int i=0; i<ogrenciSayisi; i++)
	{
		for (int j=0; j<(toplamSoru+1); j++)
		{
			Dosya >> ogrenciler [i][j];
		}
	}
	int Sonuc[ogrenciSayisi] = {}; 
	for (int i=0; i<ogrenciSayisi; i++) /* cevaplara g�re puanland�rma */
	{
		notlar = 0; 
		for (int j=0; j<toplamSoru; j++)
		{			
			if (ogrenciler[i][j+1] == cevapAnahtari[j]) 
			notlar = notlar + 4; 		
				
			else if (ogrenciler[i][j+1] == "f") /* bo� soruyu f olarak tan�mlad�m */
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
		Sonuc[i] = (Sonuc[i] * 100) / maxNot; /* soru say�s�na gore puan� 100 luk sisteme cevirme */
	}	
	siralama(Sonuc,ogrenciSayisi);
	max=Sonuc[ogrenciSayisi-1]; /* dizi art�k s�ral� oldu�u i�in dizinin son eleman� max ilk elaman� min ( dizi 0 dan basladigindan toplam elaman sayisindan -1 c�kar�rsan son elaman� buluruz */
	min=Sonuc[0];
	aciklik=max-min;
	Dosya.close();
	for(int i = (ogrenciSayisi-1); i>=0; i--) /* odevde istenildi�i gibi max tan mine s�ralama */
	{
		Dosya2 << ogrenciler[i][0] << ","; /* dizidikeri dosyaya yazdirma */
		Dosya2 << Sonuc[i] << endl;
	}
	Dosya2 << "En yuksek not= "<< max << " En dusuk not= " << min << " S�n�f ortalamas�= " << ortBulma(Sonuc,ogrenciSayisi) << " S�n�f medyan�= " << medyanBulma(Sonuc,ogrenciSayisi) << " S�n�f�n ac�kl�g�= " << aciklik;	
	cout <<endl << "Tamamlandi." << endl;	
	Dosya2.close();	
	return 0;
	/* c++ � iyi bilmedigim icin c gibi yaz�p sonra c++ a cevirdim o y�zden kod karmas�kligi olabilir */
	/*KAYNAKCA http://anaturb.net/C/string_exapm.htm
				http://www.cplusplus.com/doc/tutorial/files/*/
}
