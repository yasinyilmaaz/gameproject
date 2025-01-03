#pragma once
#include "dusman.hpp"

/*
	Mermi s�n�f�
	mermi s�n�f� mermi olu�turur ve mermi hareketini sa�lar
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
	void ciz(Pencere& pencere)override; // Mermi �izme fonksiyonu
	float boyutgetir(); // Mermi boyutunu d�nd�r�r
	void boyutAta(float boyut); // Mermi boyutunu belirler
	float hizgetir(); // Mermi h�z�n� d�nd�r�r
	void hizAta(float hiz); // Mermi h�z�n� belirler
	RectangleShape getsekil(); // Mermi �eklini d�nd�r�r
	void mermiHareket(Vector2f hedef); // Mermi hareket fonksiyonu
	void mermikonum(Vector2f konum); // Mermi konumunu belirler
	Vector2f mermiyol(Vector2f& yol); // Mermi y�n�n� belirler
	Vector2f mermiguncelkonum(); // Mermi g�ncel konumunu d�nd�r�r
	void setbitiskonum(Vector2f bitis);
	Vector2f getbitiskonum(); // Mermi biti� konumunu d�nd�r�r
	void setdusmanyol(); // Mermi d��man y�n�n� belirler
	void mermikontrol(); // Mermi kontrol fonksiyonu
	bool getmermiharitakonum(); // Mermi harita d���na ��kt� m� kontrol�
};