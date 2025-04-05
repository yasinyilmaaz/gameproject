#include "dusman.hpp"
#include <iostream>
Dusman::Dusman()
{
    sekil.setFillColor(renk);//ba�lang�� rengi
    sekil.setOutlineColor(Color::Black);//d�� kenar rengi
    sekil.setOutlineThickness(2);//kenar kal�nl���
    boyutAta(30);//d��man boyut atamas�
    hizAta(1.5);//d��man h�z atamas�
    Canata(1);//d��man can�
    dusmanUret();

	// �arp��ma kenarlar�n�n boyutlar�
    k1.setSize(Vector2f(30, 5));//d��man �arp��ma kenarlar�n�n atanmas�
    k2.setSize(Vector2f(5, 30));
    k3.setSize(Vector2f(30, 5));
    k4.setSize(Vector2f(5, 30));

	// �arp��ma kenarlar�n�n rengi
    k1.setFillColor(Color::Transparent);
    k2.setFillColor(Color::Transparent);
    k3.setFillColor(Color::Transparent);
    k4.setFillColor(Color::Transparent);
}

void Dusman::ciz(Pencere& pencere)
{
    sekil.setPosition(mkonum);//d��man ve �arp��ma kenarlar�n�n ba�lang�� konumu
    k1.setPosition(mkonum);
    k2.setPosition(mkonum + Vector2f(30, 0));
    k3.setPosition(mkonum + Vector2f(2, 30));
    k4.setPosition(mkonum);

    pencere.ciz(sekil);//d��man�n ve �arp��ma kenarlar�n�n �izimi
    pencere.ciz(k1);
    pencere.ciz(k2);
    pencere.ciz(k3);
    pencere.ciz(k4);
}

float Dusman::boyutgetir()
{
    return boyut;
}

void Dusman::boyutAta(float boyut)
{
    this->boyut = boyut;
    sekil.setSize(Vector2f(boyut, boyut));//ald���m�z boyutu boyut*boyut'luk kare olacak �ekilde at�yoruz
}

float Dusman::hizgetir()
{
    return hiz;
}

void Dusman::hizAta(float hiz)
{
    this->hiz = hiz;
}

int Dusman::Cangetir()
{
    return Can;
}

void Dusman::Canata(int can)
{
    Can = can;
}

void Dusman::hareket(Vector2f hedef)
{
        
    try {
        Vector2f yol = hedef - mkonum;//d��man ile karakterin mevcut konumu aras�ndaki uzakl��� vekt�rel olarak hesaplama
        sf::Vector2f dusmanyol = Dusmanyol(yol);//bu hesaplada���m�z mesafeyi birim vekt�re �evirme
        mkonum += dusmanyol * hiz;//d��man�n birim vekt�re g�re hareketi
	}
	catch (const char* hata)
	{
		cout << hata << endl;
    
    }
}
void Dusman::dusmanUret()
{
    int x = 0, y = 0;

    // Rastgele bir kenar se�iyoruz (�st, alt, sol veya sa�)
    int kenar = rand() % 4;

    switch (kenar) {
    case 0: // �st (oyun alan�n�n �st�nde)
        x = rand() % genislik;
        y = -50;
        break;

    case 1: // Alt (oyun alan�n�n alt�nda)
        x = rand() % genislik;
        y = yukseklik + 50;
        break;

    case 2: // Sol (oyun alan�n�n solunda)
        x = -50;
        y = rand() % yukseklik;
        break;

    case 3: // Sa� (oyun alan�n�n sa��nda)
        x = genislik + 50;
        y = rand() % yukseklik;
        break;

    default:
        break;
    }
    try {
        if ((x < 0 || x >= genislik) || (y < 0 || y >= yukseklik)) {
            mkonum = Vector2f(x, y);
        }
        else {
            dusmanUret();
        }
    }
    catch (const char* hata) {
        cout << hata << endl;
    }
    
}

void Dusman::ayarla(unsigned int yukseklik, unsigned int genislik)
{
    this->yukseklik = yukseklik;
    this->genislik = genislik;
}

RectangleShape Dusman::getsekil()
{
    return sekil;
}

// D��man�n hareket y�n�n� belirler (birim vekt�r) ve d�nd�r�r
Vector2f Dusman::Dusmanyol(Vector2f& yol)
{
    try {
		float uzunluk = sqrt(yol.x * yol.x + yol.y * yol.y);
		if (uzunluk == 0)
			throw "D��man yol hesaplanamad�";
		return Vector2f(yol.x / uzunluk, yol.y / uzunluk);
	}
    catch (const char* hata)
    {
        cout << hata << endl;
    }
}

RectangleShape Dusman::getk1()
{
    return k1;
}

RectangleShape Dusman::getk2()
{
    return k2;
}

RectangleShape Dusman::getk3()
{
    return k3;
}

RectangleShape Dusman::getk4()
{
    return k4;
}

void Dusman::dusmanitis(YON yon)
{
    switch (yon)//d��manlar birbirine �arparsa �arpt�klar� y�ne g�re birbirini itecek
    {
    case YON::Yukari:
        mkonum.y -= 1;
        break;
    case YON::Asagi:
        mkonum.y += 1;
        break;
    case YON::Sag:
        mkonum.x += 1;
        break;
    case YON::Sol:
        mkonum.x -= 1;
        break;
    default:
        break;
    }
}
