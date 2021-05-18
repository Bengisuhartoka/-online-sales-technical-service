#include<iostream> // cout,cin vs. için 
#include<fstream>// dosyalama iþlemleri için
#include<string> // string türü için 
#include<iomanip>//setw() için eklenen kütüphane
#include <windows.h> //komut ekranýna renk vermek için 
#include<clocale> // türkçe krakter ekledik
using namespace std;
class urun            //  ürün dosyasý için class yapýsi olusturuldu
{
public:  
	int urunid;       // ürünler dosyaysý degiskenler tanýmlandi
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
	 void urungiris();       //ürünler dosyasý clasa baðlý fonksiyonlar tanýmlandý
	 void yazdir();
	 void urunsil( int);     // sil fonksiyonu için parametre kullanýldý
	 void guncelle();
	 void goruntule();


};            
void urun::urungiris()        // ürün girisi icin clasa baðlý urungiris fonksiyonu olusturuldu
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
void urun::yazdir()              // clasa baglý yazdýr fonksiyonu ile urun dosyasý oluþturuldu ve kullanýcnýn girdiði veriler dosyaya yazdýrýldý ve fonksiyon sonuda dosya kapatýldý
{  
	ofstream urundosyasý;	
	urundosyasý.open("urun.txt",ios::app);     
	    cout.setf(ios::left);              // verileri düzenli olarak yazmak için setf ve setw kullanýldý
	    urundosyasý<<urunid<<
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
	    urundosyasý.close();
}
void urun::urunsil(int u)              //  urun dosyasýndan veri silmek icin urunsil prametrik fonksiuonu olusturuldu
{ 
	
	fstream urundosyasý;
	urundosyasý.open("urun.txt",ios::app|ios::in|ios::out);                                                                         // urunlerin alýnacagý dosya olusturuldu
	fstream urundosyasý2;                                                                                          
	 urundosyasý2.open("urun2.txt",ios::app|ios::in|ios::out);                                                                     //urunlerin aktarýlacagý dosya olusturuldu
	 while(urundosyasý>>urunid>>modelno>>urunadi>>marka>>islemci>>ekrankarti>>ram>>sabitdisk>>isletimsistemi>>stok>>fiyat)        // while dongusuyle ilk dosyadan(urundosyasý) dosyadan veri çekildi
	{
		if(u!=urunid)                                                                                                            // girilen ID ye ait olmayan bütün veriler olusturulan ikinci dosyaya(urundosyasý2) aktarýldý
			                                                                                                                    //ýd ye ait veri ise yeni dosyaya aktarýlmadý
		{ 
		    	urundosyasý2<<urunid<<setw(20)<<                                                                                  
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
		urundosyasý.close();
		remove("urun.txt");                                                // olusturulan yeni dosya ile(urun2.txt) ile ilk doyanýn(urun.txt) ismleri deðiþtiridi.Müsvette dosya silindi.
		urundosyasý2.close();
		rename("urun2.txt","urun.txt");
	
}
void urun::guncelle()                                                           // urun clasýna baðlý güncelle fonksiyonu olusturuldu                                                    
{
	int noo;
	ifstream urundosyasý;
	fstream urundosyasý1;
	urundosyasý.open("urun.txt",ios::out);                                       //verilerin tutulduðu dosya acýldý
	urundosyasý1.open("urun1.txt",ios::app|ios::out);                           //verilerin aktarýlacagý dosya acýldý
	cout<<"degistirmek istediginiz id yi girin   :   ";                       
	cin>>noo;                                               
	while (urundosyasý>>urunid>>modelno>>urunadi>>marka>>islemci>>ekrankarti>>ram>>sabitdisk>>isletimsistemi>>stok>>fiyat)   // while döngüsü ile urundosyasýndan veriler alýndý
	{
	
	if(noo==urunid){                                                                                                            // eger kullanýcýn girdiði id ile dosyada ki id uyusuyorsa o id ye ait verilerin kullanýcýdan girisi istendi
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
	urundosyasý1<<urunid<<setw(20)<<                                                                  // kullanýcý tarafýndan girilen yeni veriler urundosyassý1 e aktarýldý
		modelno<<setw(20)<<
		urunadi<<setw(20)<<marka<<
		setw(20)<<islemci<<setw(20)<<
		ekrankarti<<setw(20)<<ram
		<<setw(20)<<
		sabitdisk<<setw(20)<<isletimsistemi<<setw(20)
		<<stok<<setw(20)<<fiyat<<endl;
	}
	else                                                                                         // ve dosyadaki dider verilerde urundosyasý1 e aktarýldý
	{       urundosyasý1<<urunid<<setw(20)<<
			modelno<<setw(20)<<urunadi<<
			setw(20)<<marka<<setw(20)<<islemci<<
			setw(20)<<ekrankarti<<setw(20)<<ram<<
			setw(20)<<sabitdisk<<setw(20)<<
			isletimsistemi<<setw(20)<<stok<<
			setw(20)<<fiyat<<endl;
	}
	}
	urundosyasý.close();                                                                           //urunlerin alýdýgý dosya kapatýldý
	urundosyasý1.close();                                                                          // urunlerýn aktarýldýgý dosya kapandý
	remove("urun.txt");                                                                            // ve urun dosyasý silinerek urun1 dosyasýnýn adý urun olarak degistirildi
	rename("urun1.txt","urun.txt");

}
void urun::goruntule()                                                                                   //urun dosyasýnda ki verileri görmek icin clasa baðlý görüntüle fonksiyonu olusturuldu                                        
{ 
 ifstream urundosyasý;                                                                                      //verilerin okunacagý dosya (urundosyasý) olusturuldu
 urundosyasý.open("urun.txt",ios::in|ios::out|ios::app);
	while ( urundosyasý>>urunid>>modelno>>urunadi>>marka>>islemci>>ekrankarti>>ram>>sabitdisk>>isletimsistemi>>stok>>fiyat)          // urundosyasýndan veriler alýnarak ekrana yazdýrýldý
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
}urundosyasý.close();
}
class siparis                                      // siparis dosyasý icin class yapýsý kullanýldý
{
public:
	int siparisno;                                 //siparis dosyasý icin gerekli degiskenler tanýmlandý
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
void siparis::siparisgir()                           //siparis class ýna baglý siparis gir fonksiyonu olusturuldu
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
void siparis::siparisyazdir()                              //girilen bilgiler yeni açýlan siparis dosyasýna aktarýldý
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
void siparis::siparissil(int sip)                           // siparis dosyasýndan veri silmek icn siparissil fonksiyonu olusturuldu
{
	fstream siparis;
	siparis.open("siparis.txt",ios::app|ios::in|ios::out);
	fstream siparis2;
	 siparis2.open("siparis2.txt",ios::app|ios::in|ios::out);
	 while(siparis>>siparisno>>musterino>>urunnu>>miktari>>korgo_ID>>kargo)                  // while dongusuyle dosyadan veri çekildi
	{
		if(sip!=siparisno)
		{ 
			siparis2<<siparisno<<setw(20)<<musterino<<setw(20)<<urunnu<<setw(20)<<miktari<<setw(20)<<korgo_ID<<setw(20)<<kargo<<endl;    
			                                                                                                                            // girilen siparisno na ait olmayan bütün veriler olusturulan ikinci dosyaya(urundosyasý2) aktarýldý

		}                                                                                                                                 //ýd ye ait veri ise yeni dosyaya aktarýlmadý
	 }
		siparis.close();
		remove("siparis.txt");                                                                                                              // olusturulan yeni dosya ile(siparis2.txt) ile ilk doyanýn(siparis.txt) isimleri deðiþtiridi.Müsvette dosya silindi.
		siparis2.close();
		rename("siparis2.txt","siparis.txt");
	
}
void siparis::siparisgor()                                                                                          //urun dosyasýnda ki verileri görmek icin clasa baðlý görüntüle fonksiyonu olusturuldu               
{
	ifstream siparisdosyasi;                                                                                         //verilerin okunacagý dosya (siparisdosyasý) olusturuldu
siparisdosyasi.open("Siparis.txt",ios::in|ios::out|ios::app);

	while (siparisdosyasi>>siparisno>>musterino>>urunnu>>miktari>>korgo_ID>>kargo) 
 {                                                     // urundosyasýndan veriler alýnarak ekrana yazdýrýldý ve dosya kapatýldý
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
void siparis::siparisguncelle()                                                                        // siparis clasýna baðlý güncelle fonksiyonu olusturuldu  
{   int sparsno;
	ifstream siparisdosyasý;
	fstream siparisdosyasi1;
	siparisdosyasý.open("Siparis.txt",ios::out);
	
    siparisdosyasi1.open("Siparis1.txt",ios::out| ios::app);
	
	cout<<"degistirmek istediginiz siparisno yu girin   :   "; 
	cin>>sparsno;
	
	while (siparisdosyasý>>siparisno>>musterino>>urunnu>>miktari>>korgo_ID>>kargo) 
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
	
	siparisdosyasý.close();
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
	void faturayazdýr();
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
void fatura::faturayazdýr()
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
	ifstream faturadosyasý;
	fstream faturadosyasi1;
	faturadosyasý.open("Fatura.txt",ios::out);
	
    faturadosyasi1.open("Fatura1.txt",ios::out| ios::app);
	
	cout<<"degistirmek istediginizfatura no yu girin   :   "; 
	cin>>ftrno;
	
	while (faturadosyasý>>faturano>>urunn>>personelno>>musteriadi>>musterisoyadi>>il>>ilce>>adres>>telno) 
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
	
	faturadosyasý.close();
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
{                                                                                                      //ürün dosyasýnda yapmak istedigimiz iþlemi seciyoroz
	
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
{                                                                                                     //siparis dosyasýnda yapmak istedigimiz iþlemi seciyoruz
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
	fatura degisken2;	char sect;   int sec;                                                                //fatura dosyasýnda yapmak istediðimiz iþlemi seçiyoruz
	do
			 {
			 giit:
			 cout<<"1-fatura ekle ,2-fatura guncelle ,3-fatura sil ,4-fatura gor"<<endl;
			 cin>>sec;
			 if(sec==1)
			 {
	          cout<<"faturabilgi ekleme"<<endl;
	         degisken2.faturagir();
	         degisken2.faturayazdýr();
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
{                                                                                //teknikservis  dosyasýnda yapmak istediðimiz iþlemi seçiyoruz
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
	 setlocale(LC_ALL, "turkish");   //türkce krakter ekledi
	system("color 80"); //komut ekranýný renklendiriyoruz
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
	 switch (secim)                                                          //iþlem yapacaðýmýz dosya yi seçmek için swich-case yapýsý olusturuldu
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
