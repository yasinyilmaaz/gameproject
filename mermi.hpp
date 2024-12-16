#pragma once
#include "dusman.hpp"
class Mermi :public Cizilebilir {
	RectangleShape sekil;
	float boyut;
	float hiz;
	Vector2f bitiskonum;
public:
	Mermi();
	void ciz(Pencere& pencere)override;
	float boyutgetir();
	void boyutAta(float boyut);
	float hizgetir();
	void hizAta(float hiz);
	RectangleShape getsekil();
	void mermiHareket(Vector2f hedef);
	void mermikonum(Vector2f konum);
	Vector2f mermiyol(Vector2f& yol);
	Vector2f mermiguncelkonum();
	void setbitiskonum(Vector2f bitis);
	Vector2f getbitiskonum();
};