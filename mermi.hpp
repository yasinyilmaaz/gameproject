#pragma once
#include "dusman.hpp"

/*
	Mermi sýnýfý
	mermi sýnýfý mermi oluþturur ve mermi hareketini saðlar
*/


class Mermi :public Cizilebilir {
	RectangleShape sekil;
	float boyut;
	float hiz;
	Vector2f bitiskonum;
	Vector2f dusmanyol;
	bool mermiharitakonum = false;
public:
	Mermi();
	void ciz(Pencere& pencere)override; // Mermi çizme fonksiyonu
	float boyutgetir(); // Mermi boyutunu döndürür
	void boyutAta(float boyut); // Mermi boyutunu belirler
	float hizgetir(); // Mermi hýzýný döndürür
	void hizAta(float hiz); // Mermi hýzýný belirler
	RectangleShape getsekil(); // Mermi þeklini döndürür
	void mermiHareket(Vector2f hedef); // Mermi hareket fonksiyonu
	void mermikonum(Vector2f konum); // Mermi konumunu belirler
	Vector2f mermiyol(Vector2f& yol); // Mermi yönünü belirler
	Vector2f mermiguncelkonum(); // Mermi güncel konumunu döndürür
	void setbitiskonum(Vector2f bitis);
	Vector2f getbitiskonum(); // Mermi bitiþ konumunu döndürür
	void setdusmanyol(); // Mermi düþman yönünü belirler
	void mermikontrol(); // Mermi kontrol fonksiyonu
	bool getmermiharitakonum(); // Mermi harita dýþýna çýktý mý kontrolü
};