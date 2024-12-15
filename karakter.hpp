#pragma once
#include "Cizilebilir.hpp"
#include <iostream>
enum class YON { Yukari, Asagi, Sag, Sol, Dur };

class Karakter :public Cizilebilir {
private:
	RectangleShape sekil;
	YON karakteryon;
	float boyut;
	float hiz;
public:
	Karakter();
	void ciz(Pencere& pencere)override;
	void yonAta(YON yon);
	YON yonGetir();
	float boyutgetir();
	void boyutAta(float boyut);
	float hizgetir();
	void hizAta(float hiz);
	void hareket();
	void karakterKontrol();
	void renkayarla(Color renk);
	RectangleShape getsekil();
	void karakteritis(YON yon);
};
