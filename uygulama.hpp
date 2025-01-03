#pragma once
#include "Pencere.hpp"
#include "karakter.hpp"
#include "mermi.hpp"
#include <SFML/Graphics.hpp>
#include <string>

/*
 Uygulama s�n�f�
	bu class oyunun ana s�n�f�d�r
	oyunun ba�lat�lmas�, oyunun �izilmesi, oyunun g�ncellenmesi, oyunun kapat�lmas� men� sayfas� a��lmas� gibi i�lemleri yapar
	dusmanlarin hareketi, dusmanlarin uretilmesi, dusmanlarin carpismasi, 
	
*/

class Uygulama
{
	Pencere pencere;
	Karakter karakter;
	Dusman dusman;
	vector<Dusman> dusmanlar;
	Mermi mermi;
	vector<Mermi> mermiler;
	float dusmanuretmehiziMax = 20.f;
	float dusmanuretmehizi = this->dusmanuretmehiziMax;
	int maxDusman = 10;
	int dusmanarttirma = 0;
	int DusmanCan = 1;
	sf::Color renk = sf::Color::Red;
	float mermiuretmehiziMax = 20.f;
	float mermiuretmehizi = this->mermiuretmehiziMax;
	bool mermihazir = true;
	int Can = 3;
	int YokEdilenD = 0;
	int puan = 0;
	// Buton ve metin ��eleri
	Vector2f fareGuncelKonum;
	Vector2f fareTiklanmaKonum;
	sf::Clock saat;
	sf::Time cerceveSuresi;
	sf::Time gecenSure;
	// Oyunun ba�lat�lmas�
	void cerceveOlustur();
	void cizimFonksiyonu();
	void sahneGuncelle();
	// klavye ve mause olaylar,
	void tusBasildi(sf::Keyboard::Key tus);
	void tusBirakildi(sf::Keyboard::Key tus);
	void fareHareket(sf::Event::MouseMoveEvent olay);
	void fareTiklandi(sf::Event::MouseButtonEvent olay);
	// D��manlar 
	void dusmanuret();
	void dusmanciz();
	void dusmanGuncelle();
	void dusmanEkle();
	void dusmanlariHareketEttir();
	void dusmanCarpismalariniKontrolEt();
	void dusmanMermiCarpismaKontrol(size_t dusmanIndex);
	void dusmanDusmanCarpismaKontrol(size_t dusmanIndex);
	void maxDusmanArttirma();
	// Mermi 
	void mermiuret();
	void mermiciz();
	void mermiguncelle();
	// Can kontrol
	void canKontrol();
	void karakterhasar();
	// Oyun bitti�inde ekranda buton ve skor g�sterme
	void ekrandaButonVeSkorGoster();
	void tiklamaKontrol(sf::RectangleShape& buton, sf::Vector2f farePozisyonu, int olay);
	void hoverKontrol(sf::RectangleShape& buton, sf::Vector2f farePozisyonu);
	sf::Text createText(const std::string& text, const sf::Font& font, int size, const sf::Color& color, float x, float y);
	sf::RectangleShape createButton(float width, float height, const sf::Color& color, float x, float y);

public:
	Uygulama();
	void insaEt(int genislik, int yukseklik);
	void baslat(int fps = 60);

};