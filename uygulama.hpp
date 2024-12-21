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
	int dusmanarttırma = 0;
	float mermiuretmehiziMax = 20.f;
	float mermiuretmehizi = this->mermiuretmehiziMax;
	bool mermihazir = true;
	int Can = 3;
	int YokEdilenD = 0;
	Vector2f fareGuncelKonum;
	Vector2f fareTıklanmaKonum;
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
	void maxDusmanArttırma();
public:
	Uygulama();
	void insaEt(int genislik, int yukseklik);
	void baslat(int fps = 60);
};