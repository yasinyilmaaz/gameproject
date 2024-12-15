#pragma once
#pragma once
#include<SFML/Graphics.hpp>
#include "pencere.hpp"
using namespace sf;

class Cizilebilir {
protected:
	Vector2f mkonum;

public:
	virtual void ciz(Pencere& pencere) = 0;
	Vector2f konumGetir();
};