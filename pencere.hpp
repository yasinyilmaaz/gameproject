#pragma once
#include <SFML/Graphics.hpp>
#include "Fonksiyonlar.hpp"

/*
	Pencere sýnýfý
		pencereleri oluþturur ve iþleri iþler = pencere kapatma, klavye olaylarý, fare hareket olaylarý, fare týklama olaylarý gibi iþlemleri yapar

*/

using namespace sf;
using namespace std;
class Pencere {
private:
	KlavyeFonksiyonlari tusaBasFonklari; 
	KlavyeFonksiyonlari tusubirakFonklari;
	FareHareketFonklari fareHareketFonklari;
	FareTiklamaFonklari fareTiklamaFonklari;
	sf::RenderWindow mpencere;
public:
	// Pencere sýnýfý yapýcý fonksiyonu
	void olustur(unsigned int genislik = 1280,
		unsigned int yukseklik = 720, const sf::String& ad = "SFML");
	void ciz(Drawable& sekil);
	
	void olaylariisle(); // Olaylarý iþler = pencere kapatma, klavye olaylarý, fare hareket olaylarý, fare týklama olaylarý
	bool pencereAcikmi(); // Pencerenin açýk olup olmadýðýný kontrol eder
	void pencerekapat(); // Pencereyi kapatýr
	void temizle(); // Pencereyi temizler
	void goster(); // Pencereyi gösterir
	void tusabasfonkekle(KlavyeFonksiyonu fonk); // Tuþa basýldýðýnda fonksiyon ekle
	void tusubirakfonkekle(KlavyeFonksiyonu fonk); // Tuþ býrakýldýðýnda fonksiyon ekle
	void farehareketfonkekle(FareHareketFonk fonk); // Fare hareket fonksiyonu ekle
	void faretiklamafonkekle(FareTiklamaFonk fonk); // Fare týklama fonksiyonu ekle
	sf::RenderWindow& getRenderWindow(); // Pencereyi döndürür
};
