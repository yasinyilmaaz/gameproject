#pragma once
#include "Cizilebilir.hpp"
#include <iostream>

class Karakter :public Cizilebilir {
private:
	RectangleShape sekil;
	RectangleShape k1;//üst kenar
	RectangleShape k2;//sag kenar
	RectangleShape k3;//alt kenar
	RectangleShape k4;//sol  kenar
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
	RectangleShape getk1();
	RectangleShape getk2();
	RectangleShape getk3();
	RectangleShape getk4();
	void karakteritis(YON yon);
	Vector2f guncelkonum();
};