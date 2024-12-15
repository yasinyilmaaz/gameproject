#pragma once
#include <SFML/Graphics.hpp>
#include "Fonksiyonlar.hpp"
using namespace sf;
using namespace std;
class Pencere {
private:
	RenderWindow mpencere;
	KlavyeFonksiyonlari tusaBasFonklari;
	KlavyeFonksiyonlari tusubirakFonklari;
	FareHareketFonklari fareHareketFonklari;
	FareTiklamaFonklari fareTiklamaFonklari;
public:
	void olustur(unsigned int genislik = 1280,
		unsigned int yukseklik = 720, const sf::String& ad = "SFML");
	void ciz(Drawable& sekil);
	void olaylariisle();
	bool pencereAcikmi();
	void pencerekapat();
	void temizle();
	void goster();
	void tusabasfonkekle(KlavyeFonksiyonu fonk);
	void tusubirakfonkekle(KlavyeFonksiyonu fonk);
	void farehareketfonkekle(FareHareketFonk fonk);
	void faretiklamafonkekle(FareTiklamaFonk fonk);
};
