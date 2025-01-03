#pragma once
#include "Pencere.hpp"
#include "karakter.hpp"
#include "mermi.hpp"

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
	float mermiuretmehiziMax = 20.f;
	float mermiuretmehizi = this->mermiuretmehiziMax;
	bool mermihazir = true;
	int Can = 3;
	int YokEdilenD = 0;
	int puan = 0;
	// Buton ve metin öðeleri
	Vector2f fareGuncelKonum;
	Vector2f fareTiklanmaKonum;
	sf::Clock saat;
	sf::Time cerceveSuresi;
	sf::Time gecenSure;
	void cerceveOlustur();
	void cizimFonksiyonu();
	void sahneGuncelle();
	void tusBasildi(sf::Keyboard::Key tus);
	void tusBirakildi(sf::Keyboard::Key tus);
	void fareHareket(sf::Event::MouseMoveEvent olay);
	void fareTiklandi(sf::Event::MouseButtonEvent olay);
	void karakterhasar();
	void dusmanuret();
	void dusmanciz();
	void dusmanguncelle();
	void mermiuret();
	void mermiciz();
	void mermiguncelle();
	void canKontrol();
	void maxDusmanArttirma();
	void ekrandaButonVeSkorGoster();
	void tiklamaKontrol(sf::RectangleShape& buton, sf::Vector2f farePozisyonu, int olay);
	void hoverKontrol(sf::RectangleShape& buton, sf::Vector2f farePozisyonu);

public:
	Uygulama();
	void insaEt(int genislik, int yukseklik);
	void baslat(int fps = 60);

};