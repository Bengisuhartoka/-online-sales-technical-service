#include<iostream> // cout,cin vs. i�in 
#include<fstream>// dosyalama i�lemleri i�in
#include<string> // string t�r� i�in 
#include<iomanip>//setw() i�in eklenen k�t�phane
#include <windows.h> //komut ekran�na renk vermek i�in 
#include<clocale> // t�rk�e krakter ekledik
using namespace std;
class urun            //  �r�n dosyas� i�in class yap�si olusturuldu
{
public:  
	int urunid;       // �r�nler dosyays� degiskenler tan�mlandi
	int modelno;
	string urunadi;
	int stok;
	int fiyat;      
	string marka;
	string islemci;
	string ekrankarti;
	string ram;
	string sabitdisk;
	string isletimsistemi;
	 void urungiris();       //�r�nler dosyas� clasa ba�l� fonksiyonlar tan�mland�
	 void yazdir();
	 void urunsil( int);     // sil fonksiyonu i�in parametre kullan�ld�
	 void guncelle();
	 void goruntule();


};            
void urun::urungiris()        // �r�n girisi icin clasa ba�l� urungiris fonksiyonu olusturuldu
{   
	cout<<"urun_ID girin     :";
	cin>>urunid;
	cout<<"model No girin    :";
	cin>>modelno;
	cout<<"urun Adi girin    :";
	cin>>urunadi;
	cout<<"marka girin       :";
	cin>>marka;
	cout<<"islemci girin     :";
	cin>>islemci;
	cout<<"ekran karti girin :";
	cin>>ekrankarti;
	cout<<"ram girin         :";
	cin>>ram;
	cout<<"sabit disk girin  :";
	cin>>sabitdisk; 
	cout<<"isletim sistemi girin:";
	cin>>isletimsistemi;
	cout<<"urun Stok girin(adet)   :";
	cin>>stok;
	cout<<"urun Fiyat girin  :";
	cin>>fiyat;
} 
void urun::yazdir()              // clasa bagl� yazd�r fonksiyonu ile urun dosyas� olu�turuldu ve kullan�cn�n girdi�i veriler dosyaya yazd�r�ld� ve fonksiyon sonuda dosya kapat�ld�
{  
	ofstream urundosyas�;	
	urundosyas�.open("urun.txt",ios::app);     
	    cout.setf(ios::left);              // verileri d�zenli olarak yazmak i�in setf ve setw kullan�ld�
	    urundosyas�<<urunid<<
		setw(20)<<modelno<<
		setw(20)<<urunadi<<
	setw(20)<<marka<<
    setw(20)<<islemci<<
	setw(20)<<ekrankarti<<
	setw(20)<<ram<<
	setw(20)<<sabitdisk<<
	setw(20)<<isletimsistemi<<
		setw(20)<<stok<<
		setw(20)<<fiyat<<endl;
	    urundosyas�.close();
}
void urun::urunsil(int u)              //  urun dosyas�ndan veri silmek icin urunsil prametrik fonksiuonu olusturuldu
{ 
	
	fstream urundosyas�;
	urundosyas�.open("urun.txt",ios::app|ios::in|ios::out);                                                                         // urunlerin al�nacag� dosya olusturuldu
	fstream urundosyas�2;                                                                                          
	 urundosyas�2.open("urun2.txt",ios::app|ios::in|ios::out);                                                                     //urunlerin aktar�lacag� dosya olusturuldu
	 while(urundosyas�>>urunid>>modelno>>urunadi>>marka>>islemci>>ekrankarti>>ram>>sabitdisk>>isletimsistemi>>stok>>fiyat)        // while dongusuyle ilk dosyadan(urundosyas�) dosyadan veri �ekildi
	{
		if(u!=urunid)                                                                                                            // girilen ID ye ait olmayan b�t�n veriler olusturulan ikinci dosyaya(urundosyas�2) aktar�ld�
			                                                                                                                    //�d ye ait veri ise yeni dosyaya aktar�lmad�
		{ 
		    	urundosyas�2<<urunid<<setw(20)<<                                                                                  
				modelno<<setw(20)<<
				urunadi<<setw(20)<<marka<<
				setw(20)<<islemci<<
				setw(20)<<ekrankarti<<
				setw(20)<<ram<<
				setw(20)<<sabitdisk<<
				setw(20)<<isletimsistemi<<
				setw(20)<<stok<<setw(20)<<fiyat<<endl;

		}
	 }
		urundosyas�.close();
		remove("urun.txt");                                                // olusturulan yeni dosya ile(urun2.txt) ile ilk doyan�n(urun.txt) ismleri de�i�tiridi.M�svette dosya silindi.
		urundosyas�2.close();
		rename("urun2.txt","urun.txt");
	
}
void urun::guncelle()                                                           // urun clas�na ba�l� g�ncelle fonksiyonu olusturuldu                                                    
{
	int noo;
	ifstream urundosyas�;
	fstream urundosyas�1;
	urundosyas�.open("urun.txt",ios::out);                                       //verilerin tutuldu�u dosya ac�ld�
	urundosyas�1.open("urun1.txt",ios::app|ios::out);                           //verilerin aktar�lacag� dosya ac�ld�
	cout<<"degistirmek istediginiz id yi girin   :   ";                       
	cin>>noo;                                               
	while (urundosyas�>>urunid>>modelno>>urunadi>>marka>>islemci>>ekrankarti>>ram>>sabitdisk>>isletimsistemi>>stok>>fiyat)   // while d�ng�s� ile urundosyas�ndan veriler al�nd�
	{
	
	if(noo==urunid){                                                                                                            // eger kullan�c�n girdi�i id ile dosyada ki id uyusuyorsa o id ye ait verilerin kullan�c�dan girisi istendi
	cout<<"urun_ID girin        :";
	cin>>urunid;
	cout<<"model No girin       :";
	cin>>modelno;
	cout<<"urun Adi girin       :";
	cin>>urunadi;
	cout<<"marka girin          :";
	cin>>marka;
	cout<<"islemci girin        :";
	cin>>islemci;
	cout<<"ekran karti girin    :";
	cin>>ekrankarti;
	cout<<"ram girin            :";
	cin>>ram;
	cout<<"sabit disk girin     :";
	cin>>sabitdisk;
	cout<<"isletim sistemi girin:";
	cin>>isletimsistemi;
	cout<<"urun Stok girin      :";
	cin>>stok;
	cout<<"urun Fiyat girin     :";
	cin>>fiyat;
	urundosyas�1<<urunid<<setw(20)<<                                                                  // kullan�c� taraf�ndan girilen yeni veriler urundosyass�1 e aktar�ld�
		modelno<<setw(20)<<
		urunadi<<setw(20)<<marka<<
		setw(20)<<islemci<<setw(20)<<
		ekrankarti<<setw(20)<<ram
		<<setw(20)<<
		sabitdisk<<setw(20)<<isletimsistemi<<setw(20)
		<<stok<<setw(20)<<fiyat<<endl;
	}
	else                                                                                         // ve dosyadaki dider verilerde urundosyas�1 e aktar�ld�
	{       urundosyas�1<<urunid<<setw(20)<<
			modelno<<setw(20)<<urunadi<<
			setw(20)<<marka<<setw(20)<<islemci<<
			setw(20)<<ekrankarti<<setw(20)<<ram<<
			setw(20)<<sabitdisk<<setw(20)<<
			isletimsistemi<<setw(20)<<stok<<
			setw(20)<<fiyat<<endl;
	}
	}
	urundosyas�.close();                                                                           //urunlerin al�d�g� dosya kapat�ld�
	urundosyas�1.close();                                                                          // urunler�n aktar�ld�g� dosya kapand�
	remove("urun.txt");                                                                            // ve urun dosyas� silinerek urun1 dosyas�n�n ad� urun olarak degistirildi
	rename("urun1.txt","urun.txt");

}
void urun::goruntule()                                                                                   //urun dosyas�nda ki verileri g�rmek icin clasa ba�l� g�r�nt�le fonksiyonu olusturuldu                                        
{ 
 ifstream urundosyas�;                                                                                      //verilerin okunacag� dosya (urundosyas�) olusturuldu
 urundosyas�.open("urun.txt",ios::in|ios::out|ios::app);
	while ( urundosyas�>>urunid>>modelno>>urunadi>>marka>>islemci>>ekrankarti>>ram>>sabitdisk>>isletimsistemi>>stok>>fiyat)          // urundosyas�ndan veriler al�narak ekrana yazd�r�ld�
 {
 cout<<"\n Urun Bilgileri \n"<<endl; 
 cout<<"urun_ID       :"<<urunid<<endl; 
 cout<<"model no      :"<<modelno<<endl; 
 cout<<"Urun adi      :"<<urunadi<<endl;
 cout<<"marka         :"<<marka<<endl; 
 cout<<"islemci       :"<<islemci<<endl; 
 cout<<"ekrankarti    :"<<ekrankarti<<endl; 
 cout<<"ram           :"<<ram<<endl;
 cout<<"sabitdisk     :"<<sabitdisk<<endl; 
 cout<<"isletimsistemi:"<<isletimsistemi<<endl; 
 cout<<"stok(adet)    :"<<stok<<endl;
 cout<<"fiyat         :"<<fiyat<<endl;
}urundosyas�.close();
}
class siparis                                      // siparis dosyas� icin class yap�s� kullan�ld�
{
public:
	int siparisno;                                 //siparis dosyas� icin gerekli degiskenler tan�mland�
	int musterino;
	int urunnu;
	int miktari;
	int korgo_ID;
	string kargo;
	void siparisgir();
	void siparisyazdir();
	void siparissil(int);
	void siparisgor();
	void siparisguncelle();
};                                        
void siparis::siparisgir()                           //siparis class �na bagl� siparis gir fonksiyonu olusturuldu
{
	
	cout<<"siparis no girin:";             
	cin>>siparisno;
	cout<<"musteri no girin:";
	cin>>musterino;
	cout<<"urun no girin   :";
	cin>>urunnu;
	cout<<"miktari girin   :";
	cin>>miktari;
	cout<<"kargo_Id girin  :";
	cin>>korgo_ID;
	cout<<"kargo adi girin :";
	cin>>kargo;
	
}
void siparis::siparisyazdir()                              //girilen bilgiler yeni a��lan siparis dosyas�na aktar�ld�
{ 
	ofstream siparisdosyasi;
	siparisdosyasi.open("Siparis.txt",ios::app);
	cout.setf(ios::left);
	siparisdosyasi<<siparisno<<
	setw(20)<<musterino <<
    setw(20)<<urunnu<<
	setw(20)<<miktari<<
	setw(20)<<korgo_ID<<
	setw(20)<<kargo<<endl;
	siparisdosyasi.close();


} 
void siparis::siparissil(int sip)                           // siparis dosyas�ndan veri silmek icn siparissil fonksiyonu olusturuldu
{
	fstream siparis;
	siparis.open("siparis.txt",ios::app|ios::in|ios::out);
	fstream siparis2;
	 siparis2.open("siparis2.txt",ios::app|ios::in|ios::out);
	 while(siparis>>siparisno>>musterino>>urunnu>>miktari>>korgo_ID>>kargo)                  // while dongusuyle dosyadan veri �ekildi
	{
		if(sip!=siparisno)
		{ 
			siparis2<<siparisno<<setw(20)<<musterino<<setw(20)<<urunnu<<setw(20)<<miktari<<setw(20)<<korgo_ID<<setw(20)<<kargo<<endl;    
			                                                                                                                            // girilen siparisno na ait olmayan b�t�n veriler olusturulan ikinci dosyaya(urundosyas�2) aktar�ld�

		}                                                                                                                                 //�d ye ait veri ise yeni dosyaya aktar�lmad�
	 }
		siparis.close();
		remove("siparis.txt");                                                                                                              // olusturulan yeni dosya ile(siparis2.txt) ile ilk doyan�n(siparis.txt) isimleri de�i�tiridi.M�svette dosya silindi.
		siparis2.close();
		rename("siparis2.txt","siparis.txt");
	
}
void siparis::siparisgor()                                                                                          //urun dosyas�nda ki verileri g�rmek icin clasa ba�l� g�r�nt�le fonksiyonu olusturuldu               
{
	ifstream siparisdosyasi;                                                                                         //verilerin okunacag� dosya (siparisdosyas�) olusturuldu
siparisdosyasi.open("Siparis.txt",ios::in|ios::out|ios::app);

	while (siparisdosyasi>>siparisno>>musterino>>urunnu>>miktari>>korgo_ID>>kargo) 
 {                                                     // urundosyas�ndan veriler al�narak ekrana yazd�r�ld� ve dosya kapat�ld�
	 cout<<"\n Siparis Bilgileri \n"; 
	cout<<"siparis no :"<<siparisno<<endl;
	cout<<"musteri    :"<<musterino<<endl;
	cout<<"urun no    :"<<urunnu<<endl;
	cout<<"miktari    :"<<miktari<<endl;
	cout<<"kargo_Id   :"<<korgo_ID<<endl;
	cout<<"kargo adi  :"<<kargo<<endl;
	cout<<endl;
}   siparisdosyasi.close();
	
}
void siparis::siparisguncelle()                                                                        // siparis clas�na ba�l� g�ncelle fonksiyonu olusturuldu  
{   int sparsno;
	ifstream siparisdosyas�;
	fstream siparisdosyasi1;
	siparisdosyas�.open("Siparis.txt",ios::out);
	
    siparisdosyasi1.open("Siparis1.txt",ios::out| ios::app);
	
	cout<<"degistirmek istediginiz siparisno yu girin   :   "; 
	cin>>sparsno;
	
	while (siparisdosyas�>>siparisno>>musterino>>urunnu>>miktari>>korgo_ID>>kargo) 
	{
	
    if(sparsno==siparisno)
		{
	  
	cout<<"siparis no girin:";
	cin>>siparisno;
	cout<<"musteri no girin:";
	cin>>musterino;
	cout<<"urun no girin   :";
	cin>>urunnu;
	cout<<"miktari girin   :";
	cin>>miktari;
	cout<<"kargo_Id girin  :";
	cin>>korgo_ID;
	cout<<"kargo girin     :";
	cin>>kargo;
	siparisdosyasi1<<siparisno<<setw(20)<<musterino<<setw(20)<<urunnu<<setw(20)<<miktari<<setw(20)<<korgo_ID<<setw(20)<<kargo<<endl;

	}
	else
	{
	
		siparisdosyasi1<<siparisno<<setw(20)<<musterino<<setw(20)<<urunnu<<setw(20)<<miktari<<setw(20)<<korgo_ID<<setw(20)<<kargo<<endl;

	}}
	
	siparisdosyas�.close();
	siparisdosyasi1.close();
	remove("Siparis.txt");
	rename("Siparis1.txt","Siparis.txt");

}

class fatura
{
    public:
    int faturano;
	int urunn;
	int personelno;
	string musteriadi;
	string musterisoyadi;
	string il;
	string ilce;
	string adres;
	string telno;

	void faturagir();
	void faturayazd�r();
	void faturasil(int);
	void faturagor();
	void faturaguncel();



};
void fatura::faturagir()
{
    cout<<"faturano girin:";
	cin>>faturano;
	cout<<"urun no girin:";
	cin>>urunn;
	cout<<"personel no girin:";
	cin>>personelno;
	cout<<"musteri Adi girin:";
	cin>>musteriadi;
	cout<<"Musteri Soyadi girin:";
	cin>>musterisoyadi;
	cout<<"il girin:";
	cin>>il;
	cout<<"ilce girin:";
	cin>>ilce;
	cout<<"adres girin:";
	cin>>adres;
	cout<<"tel_no girin:";
	cin>>telno;
}
void fatura::faturayazd�r()
{
	ofstream faturadosyasi;
	faturadosyasi.open("Fatura.txt",ios::app);
	cout.setf(ios::left);
	faturadosyasi<<faturano<<
	setw(20)<<urunn<<
	setw(20)<<personelno<<
	setw(20)<<musteriadi<<
    setw(20)<<musterisoyadi<<
	setw(20)<<il<<
	setw(20)<<ilce<<
	setw(20)<<adres<<
	setw(20)<<telno<<endl;
	faturadosyasi.close();

}
void fatura::faturasil(int sil)
{
	fstream fatura;
	fatura.open("Fatura.txt",ios::app|ios::in|ios::out);
	fstream fatura2;
	 fatura2.open("fatura2.txt",ios::app|ios::in|ios::out);
	 while(fatura>>faturano>>urunn>>personelno>>musteriadi>>musterisoyadi>>il>>ilce>>adres>>telno)
	{
		if(sil!=faturano)
		{ 
			fatura2<<faturano<<setw(20)<<urunn<<setw(20)<<personelno<<setw(20)<<musteriadi<<setw(20)<<musterisoyadi<<setw(20)<<il<<ilce<<adres<<telno<<endl;
		}
	 }
		fatura.close();
		remove("Fatura.txt");
		fatura2.close();
		rename("fatura2.txt","Fatura.txt");
}
void fatura::faturagor()
{
	ifstream faturadosyasi;
faturadosyasi.open("Fatura.txt",ios::in|ios::out|ios::app);
	while (faturadosyasi>>faturano>>urunn>>personelno>>musteriadi>>musterisoyadi>>il>>ilce>>adres>>telno) 
 { 
 cout<<"\n Fatura Bilgileri \n"; 
 cout<<"faturano     :"<<faturano<<endl; 
 cout<<"urun no      :"<<urunn<<endl; 
 cout<<"personelno   :"<<personelno<<endl; 
 cout<<"musteriadi   :"<<musteriadi<<endl; 
 cout<<"musterisoyadi:"<<musterisoyadi<<endl; 
 cout<<"il           :"<<il<<endl;
 cout<<"ilce         :"<<ilce<<endl; 
 cout<<"adres        :"<<adres<<endl; 
 cout<<"telno        :"<<telno<<endl;
}
	faturadosyasi.close();
}
void fatura::faturaguncel()
{
	int ftrno;
	ifstream faturadosyas�;
	fstream faturadosyasi1;
	faturadosyas�.open("Fatura.txt",ios::out);
	
    faturadosyasi1.open("Fatura1.txt",ios::out| ios::app);
	
	cout<<"degistirmek istediginizfatura no yu girin   :   "; 
	cin>>ftrno;
	
	while (faturadosyas�>>faturano>>urunn>>personelno>>musteriadi>>musterisoyadi>>il>>ilce>>adres>>telno) 
	{
	
    if(ftrno==faturano)
		{
	  
	cout<<"faturano girin:";
	cin>>faturano;
	cout<<"urun no girin:";
	cin>>urunn;
	cout<<"personel no girin:";
	cin>>personelno;
	cout<<"musteri Adi girin:";
	cin>>musteriadi;
	cout<<"Musteri Soyadi girin:";
	cin>>musterisoyadi;
	cout<<"il girin:";
	cin>>il;
	cout<<"ilce girin:";
	cin>>ilce;
	cout<<"adres girin:";
	cin>>adres;
	cout<<"tel_no girin:";
	cin>>telno;
	faturadosyasi1<<faturano<<
	setw(20)<<urunn<<
	setw(20)<<personelno<<
	setw(20)<<musteriadi<<
    setw(20)<<musterisoyadi<<
	setw(20)<<il<<
	setw(20)<<ilce<<
	setw(20)<<adres<<
	setw(20)<<telno<<endl;

	}
	else
	{
	 faturadosyasi1<<faturano<<
	setw(20)<<urunn<<
	setw(20)<<personelno<<
	setw(20)<<musteriadi<<
    setw(20)<<musterisoyadi<<
	setw(20)<<il<<
	setw(20)<<ilce<<
	setw(20)<<adres<<
	setw(20)<<telno<<endl;

	}}
	
	faturadosyas�.close();
	faturadosyasi1.close();
	remove("Fatura.txt");
	rename("Fatura1.txt","Fatura.txt");

}
class teknikservis
{
public:
	int urunnn;
	int teknikpersonelno;
	string urunadii;
	string urunarzasi;
	string musterin;
	string musteriadii;
	string mesteriadres;
	string grantisuresi;
	string telefon;  

	void teknik();
	void teknikseryazdirma();
	void goru();
	void tekniksil(int);
	void teknikguncel();
};
void teknikservis::teknik()
{
	 cout<<"urun no girin:";
	cin>>urunnn;
	cout<<"teknik personel no girin:";
	cin>>teknikpersonelno;
	cout<<"Urun adi girin:";
	cin>>urunadii;
	cout<<"Urun arizasi girin:";
	cin>>urunarzasi;
	cout<<"Musteri No girin:";
	cin>>musterin;
	cout<<"Musteri adi girin girin:";
	cin>>musteriadii;
	cout<<"Musteri adres girin:";
	cin>>mesteriadres;
	cout<<"granti suresi girin:";
	cin>>grantisuresi;
	cout<<"tel_no girin:";
	cin>>telefon;
}
void teknikservis::teknikseryazdirma()
{
	ofstream teknikservisdosyasi;
	teknikservisdosyasi.open("Teknik Servis.txt",ios::app);
	cout.setf(ios::left);
teknikservisdosyasi<<urunnn<<
	       setw(20)<<teknikpersonelno<<
	       setw(20)<<urunadii<<
	       setw(20)<<urunarzasi<<
           setw(20)<<musterin<<
	       setw(20)<<musteriadii<<
	       setw(20)<<mesteriadres<<
	       setw(20)<<grantisuresi<<
	       setw(20)<<telefon<<endl;
	       teknikservisdosyasi.close();
}
void teknikservis::goru()
{
	fstream teknikservisdosyasi;
teknikservisdosyasi.open("Teknik Servis.txt",ios::in|ios::out|ios::app);
	while (teknikservisdosyasi>>urunnn>>teknikpersonelno>>urunadii>>urunarzasi>>musterin>>musteriadii>>mesteriadres>>grantisuresi>>telefon) 
 { 
 cout<<"\n Teknik servis Bilgileri \n"; 
 cout<<"urun no              :"<<urunnn<<endl; 
 cout<<"teknik personel no no:"<<teknikpersonelno<<endl; 
 cout<<"urun adi             :"<<urunadii<<endl; 
 cout<<"urun arzasi          :"<<urunarzasi<<endl; 
 cout<<"musteri no           :"<<musterin<<endl;
 cout<<"musterisoyadi        :"<<musteriadii<<endl; 
 cout<<"musteri adres        :"<<mesteriadres<<endl;
 cout<<"granti suresi        :"<<grantisuresi<<endl; 
 cout<<"tel no               :"<<telefon<<endl; 
}
	teknikservisdosyasi.close();
}
void teknikservis::tekniksil(int clr)
{   fstream teknikserv;
	teknikserv.open("Teknik Servis.txt",ios::app|ios::in|ios::out);
	fstream teknikserv2;
	teknikserv2.open("Teknik Servis2.txt",ios::app|ios::in|ios::out);
	 while(teknikserv>>urunnn>>teknikpersonelno>>urunadii>>urunarzasi>>musterin>>musteriadii>>mesteriadres>>grantisuresi>>telefon)
	{
		if(clr!=urunnn)
		{ 
			teknikserv2<<urunnn<<
				setw(20)<<teknikpersonelno<<
				setw(20)<<urunadii<<setw(20)<<
				urunarzasi<<setw(20)<<musterin<<setw(20)<<
				musteriadii<<setw(20)<<mesteriadres<<
				grantisuresi<<telefon<<endl;

		}
	 }
		teknikserv.close();
		remove("Teknik Servis.txt");
		teknikserv2.close();
		rename("Teknik Servis2.txt","Teknik Servis.txt");
}
void teknikservis::teknikguncel()
{int uno;
	ifstream teknikserv;
	fstream teknikservis2;
	teknikserv.open("Teknik Servis.txt");
	
 teknikservis2.open("Teknik Servis2.txt",ios::out| ios::app);
	
	cout<<"degistirmek istediginizfatura no yu girin   :   "; 
	cin>>uno;
	
	while (teknikserv>>urunnn>>teknikpersonelno>>urunadii>>urunarzasi>>musterin>>musteriadii>>mesteriadres>>grantisuresi>>telefon) 
	{
	
		if(uno==urunnn)
		{
	cout<<"urun no girin:";
	cin>>urunnn;
	cout<<"teknik personel no girin:";
	cin>>teknikpersonelno;
	cout<<"Urun adi girin:";
	cin>>urunadii;
	cout<<"Urun arizasi girin:";
	cin>>urunarzasi;
	cout<<"Musteri No girin:";
	cin>>musterin;
	cout<<"Musteri adi girin girin:";
	cin>>musteriadii;
	cout<<"Musteri adres girin:";
	cin>>mesteriadres;
	cout<<"granti suresi girin:";
	cin>>grantisuresi;
	cout<<"tel_no girin:";
	cin>>telefon;
	teknikservis2<<urunnn<<
		setw(20)<<teknikpersonelno<<setw(20)<<
		urunadii<<setw(20)<<urunarzasi<<
		setw(20)<<musterin<<setw(20)<<musteriadii<<
		setw(20)<<mesteriadres<<grantisuresi<<telefon<<endl;

	}
	else
	{
	
		teknikservis2<<urunnn<<setw(20)<<
			teknikpersonelno<<setw(20)<<urunadii<<
			setw(20)<<urunarzasi<<setw(20)<<
			musterin<<setw(20)<<musteriadii<<setw(20)<<mesteriadres<<
			grantisuresi<<telefon<<endl;

	}}
	
	teknikserv.close();
	teknikservis2.close();
	remove("Teknik Servis.txt");
	rename("Teknik Servis2.txt","Teknik Servis.txt");

}
void urunblgi()
{                                                                                                      //�r�n dosyas�nda yapmak istedigimiz i�lemi seciyoroz
	
	int sec;
	urun degisken;
	char sect;
	do
			 {
			
			 cout<<"1-urun ekle ,2-urun guncelle ,3-urun sil , 4-Urun listeleme"<<endl;
	cin>>sec;
			

	if(sec==1)
	{
		cout<<"3-Urun ekleme"<<endl;
	    degisken.urungiris();
	    degisken.yazdir();
	}
	else if(sec==2)
	{
		cout<<"2-Urun guncelle"<<endl;
		degisken.guncelle();
		
	}
	else if(sec==3)
	{
		int u;
		cout<<"1-Urun silme"<<endl;
		
	   cout<<"silmek istediginiz urun_ID yi girin :"<<endl;
	   cin>>u;
		degisken.urunsil(u);
		
	}
	else if(sec==4)
	{ 
		cout<<"4-Urun listeleme"<<endl;
		degisken.goruntule();
	}
	else
	{
		cout<<"yanlis deger girdiniz"<<endl;
		
	}
	cout<<"baska  bi islem yapmak istermisin e/h"<<endl;
	cin>>sect;
			 } while (sect=='e'||sect=='E');
}
void siparisblgi()
{                                                                                                     //siparis dosyas�nda yapmak istedigimiz i�lemi seciyoruz
	siparis degisken1;
		int sec;
	char sect;
	 do
			 {
			 git:
			 cout<<"1-siparis ekle ,2-siparis guncelle ,3-siparis sil, 4-siparis listele"<<endl;
			 cin>>sec;
			 if(sec==1)
			 {
	cout<<"1-siparis ekleme"<<endl;
	degisken1.siparisgir();
	degisken1.siparisyazdir();
			 }
			 else if(sec==2)
			 {
				 cout<<"2-siparis guncelle"<<endl;
				 degisken1.siparisguncelle();


			 }
			 else if(sec==3)
			 {
				 int sip;
				 cout<<"3-siparis sil"<<endl;
				 cout<<"silmek istediginiz Siparisi yi girin"<<endl;
				 cin>>sip;
				 degisken1.siparissil(sip);
			 }
			 else if(sec==4)
			 { 
				 cout<<"4-siparis listele"<<endl;
				 degisken1.siparisgor();
				 
			 }
			 else
			 {
				 cout<<"yanlis deger girdiniz"<<endl;
				 goto git;
			 }
			 cout<<"baska  bi islem yapmak istermisin e/h"<<endl;
	         cin>>sect;
			 } while (sect=='e'||sect=='E');
}
void faturablgi()
{
	fatura degisken2;	char sect;   int sec;                                                                //fatura dosyas�nda yapmak istedi�imiz i�lemi se�iyoruz
	do
			 {
			 giit:
			 cout<<"1-fatura ekle ,2-fatura guncelle ,3-fatura sil ,4-fatura gor"<<endl;
			 cin>>sec;
			 if(sec==1)
			 {
	          cout<<"faturabilgi ekleme"<<endl;
	         degisken2.faturagir();
	         degisken2.faturayazd�r();
			 }
			 else if(sec==2)
			 {
				 cout<<"2-fatura guncelle"<<endl;
				 degisken2.faturaguncel();
			 }
			 else if(sec==3)
			 {
				 int sil;
				 cout<<"3-fatura sil"<<endl;
				 cout<<"silmek istediginiz Fatura yi girin"<<endl;
				 cin>>sil;
				 degisken2.faturasil(sil);
			 }
			 else if(sec==4)
			 {
				 cout<<"4-fatura gor"<<endl;
				 degisken2.faturagor();
			 }
			 else
			 {
				 cout<<"yanlis deger girdiniz"<<endl;
				 goto giit;
			 }
			 cout<<"baska  bi islem yapmak istermisin e/h"<<endl;
	         cin>>sect;
			 } while (sect=='e'||sect=='E');
			
}
void teknkblgi()
{                                                                                //teknikservis  dosyas�nda yapmak istedi�imiz i�lemi se�iyoruz
	char sect; int sec;
		teknikservis degisken3;
	do
			 {
			 giiit:
			 cout<<"1-teknik servis ariza raporu ekleme ,2-teknik servis guncelle ,3-teknik servis sil, 4-teknik servis listele"<<endl;
			 cin>>sec;
			 if(sec==1)
			 {
	         cout<<"teknik servis ariza raporu ekleme"<<endl;
			 degisken3.teknik();
			 degisken3.teknikseryazdirma();
			 }
			 else if(sec==2)
			 {
				 cout<<"2-teknik servis guncelle"<<endl;
				 degisken3.teknikguncel();

			 }
			 else if(sec==3)
			 {
				 int clr;
				 cout<<"3-teknik servis sil"<<endl;
				 cout<<"silmek istediginiz raporu girin"<<endl;
				 cin>>clr;
				 degisken3.tekniksil(clr);
				
			 }
			 else if(sec==4)
			 { 
				 cout<<"4-teknik servis listele"<<endl;
				 degisken3.goru();
				 
			 }
			 else
			 {
				 cout<<"yanlis deger girdiniz"<<endl;
				 goto giiit;
			 }
			 cout<<"baska  bi islem yapmak istermisin e/h"<<endl;
	         cin>>sect;
			 } while (sect=='e'||sect=='E');
}
void main()
{	
	 setlocale(LC_ALL, "turkish");   //t�rkce krakter ekledi
	system("color 80"); //komut ekran�n� renklendiriyoruz
	int secim;
	do{
		system("cls");
    cout<<"1- Urun Dosyasi         :"<<endl; 
    cout<<"2- siparis Dosyasi      :"<<endl; 
    cout<<"3- fatura Dosyasi       :"<<endl;
	cout<<"4- teknik servis Dosyasi:"<<endl;
	cout<<endl;
	 cout<<"Yapmak istediginiz islemi seciniz:"<<endl;
     cin>>secim;
	 switch (secim)                                                          //i�lem yapaca��m�z dosya yi se�mek i�in swich-case yap�s� olusturuldu
	 {
	 case 1:
		 {
		  urunblgi();
		 }
    break; 
	 case 2:
		 {
			 siparisblgi();
		 }
	break;
		 
	 case 3:
   {
	   faturablgi();
	    
   }
	break;
	 case 4:
		 {
			 teknkblgi();
		 }
		 break;
		 }
	
	}while (true);
	
	 
    system("pause");
	}
