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
	void yonAta(YON yon); // karakterin yönünü belirler
	YON yonGetir(); // karakterin yönünü döndürür
	float boyutgetir(); // karakterin boyutunu döndürür
	void boyutAta(float boyut); // karakterin boyutunu değiştirir
	float hizgetir(); // karakterin hızını döndürür
	void hizAta(float hiz); // karakterin hızını değiştirir
	void hareket(); // karakterin haraket yönünü belirler
	void karakterKontrol(); // karakterin kontrolünü sağlar
	void renkayarla(Color renk); // karakterin rengini belirler
	// şekil döndürme fonksiyonları 
	RectangleShape getsekil();
	RectangleShape getk1();
	RectangleShape getk2();
	RectangleShape getk3();
	RectangleShape getk4();
	// karakterin hareket yönünü belirleme
	void karakteritis(YON yon);
	Vector2f guncelkonum();
};