#pragma once
#include <SFML/Graphics.hpp>
#include "Fonksiyonlar.hpp"

/*
	Pencere s�n�f�
		pencereleri olu�turur ve i�leri i�ler = pencere kapatma, klavye olaylar�, fare hareket olaylar�, fare t�klama olaylar� gibi i�lemleri yapar

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
	// Pencere s�n�f� yap�c� fonksiyonu
	void olustur(unsigned int genislik = 1280,
		unsigned int yukseklik = 720, const sf::String& ad = "SFML");
	void ciz(Drawable& sekil);
	
	void olaylariisle(); // Olaylar� i�ler = pencere kapatma, klavye olaylar�, fare hareket olaylar�, fare t�klama olaylar�
	bool pencereAcikmi(); // Pencerenin a��k olup olmad���n� kontrol eder
	void pencerekapat(); // Pencereyi kapat�r
	void temizle(); // Pencereyi temizler
	void goster(); // Pencereyi g�sterir
	void tusabasfonkekle(KlavyeFonksiyonu fonk); // Tu�a bas�ld���nda fonksiyon ekle
	void tusubirakfonkekle(KlavyeFonksiyonu fonk); // Tu� b�rak�ld���nda fonksiyon ekle
	void farehareketfonkekle(FareHareketFonk fonk); // Fare hareket fonksiyonu ekle
	void faretiklamafonkekle(FareTiklamaFonk fonk); // Fare t�klama fonksiyonu ekle
	sf::RenderWindow& getRenderWindow(); // Pencereyi d�nd�r�r
};
