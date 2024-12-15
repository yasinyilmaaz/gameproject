#pragma once
#pragma once
#include "Pencere.hpp"
#include "karakter.hpp"
#include "dusman.hpp"
class Uygulama
{
	Pencere pencere;
	Karakter karakter;
	Dusman dusman;
	int Can = 3;
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
public:
	Uygulama();
	void insaEt(int genislik, int yukseklik);
	void baslat(int fps = 60);
};