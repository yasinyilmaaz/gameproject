#pragma once
#include<SFML/Graphics.hpp>
#include "pencere.hpp"

/*
	Cizilebilir s�n�f�
		�izilebilir s�n�f� �ekillerin �izilmesi i�in kullan�l�r
*/

using namespace sf;
enum class YON { Yukari, Asagi, Sag, Sol, Dur };

class Cizilebilir {
protected:
	Vector2f mkonum;

public:
	virtual void ciz(Pencere& pencere) = 0;
	Vector2f konumGetir();
};
