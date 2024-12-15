#pragma once
#include "Cizilebilir.hpp"
#include <time.h>

class Dusman :public Cizilebilir {
	RectangleShape sekil;
	float boyut;
	float hiz;
	unsigned int genislik = 1280;
	unsigned int yukseklik = 720;
public:
	Dusman();
	void ciz(Pencere& pencere)override;
	float boyutgetir();
	void boyutAta(float boyut);
	float hizgetir();
	void hizAta(float hiz);
	void hareket();
	void dusmanUret();
	void ayarla(unsigned int yukseklik, unsigned int genislik);
	RectangleShape getsekil();
};