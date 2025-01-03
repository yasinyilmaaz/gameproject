#include "Cizilebilir.hpp"
#include <time.h>
#include <cmath>
#include <SFML/Graphics/Color.hpp>

/*
	Dusman sını
		Dusman sınıfı düşman oluşturur ve düşmanın hareketini sağlar ve düşmanın çizimini yapar

*/

class Dusman :public Cizilebilir {
	RectangleShape sekil;
	RectangleShape k1;//üst kenar
	RectangleShape k2;//sag kenar
	RectangleShape k3;//alt kenar
	RectangleShape k4;//sol  kenar
	float boyut;
	float hiz;
	sf::Color renk = sf::Color::Red;
	int Can;
	unsigned int genislik = 1280;
	unsigned int yukseklik = 720;
public:
	Dusman();
	void ciz(Pencere& pencere)override;
	float boyutgetir();
	void boyutAta(float boyut);
	float hizgetir();
	void hizAta(float hiz);
	int Cangetir();
	void Canata(int can);
	void hareket(Vector2f hedef);
	void dusmanUret();
	void ayarla(unsigned int yukseklik, unsigned int genislik);
	RectangleShape getsekil();
	Vector2f Dusmanyol(Vector2f& yol);
	RectangleShape getk1();
	RectangleShape getk2();
	RectangleShape getk3();
	RectangleShape getk4();
	void dusmanitis(YON yon);
};