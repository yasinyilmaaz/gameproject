#include "karakter.hpp"


// Karakter s�n�f� yap�c� fonksiyonu = karakter rengini , boyutunu ayarlar ve karakterin hareket h�z�n� belirler ve karakterin par�alar�n� olu�turur
Karakter::Karakter()
{
    sekil.setFillColor(Color::Green);
    sekil.setOutlineColor(Color::Black);
    sekil.setOutlineThickness(2);
    boyutAta(30);
    hizAta(5);
    k1.setSize(Vector2f(30, 5));
    k2.setSize(Vector2f(5, 30));
    k3.setSize(Vector2f(30, 5));
    k4.setSize(Vector2f(5, 30));
    k1.setFillColor(Color::Transparent);
    k2.setFillColor(Color::Transparent);
    k3.setFillColor(Color::Transparent);
    k4.setFillColor(Color::Transparent);
}

// Karakter �izme fonksiyonu = karakter �eklini �izer
void Karakter::ciz(Pencere& pencere)
{
    sekil.setPosition(mkonum + Vector2f(640, 360));
    k1.setPosition(mkonum + Vector2f(640, 355));
    k2.setPosition(mkonum + Vector2f(670, 360));
    k3.setPosition(mkonum + Vector2f(642, 390));
    k4.setPosition(mkonum + Vector2f(637, 360));

    pencere.ciz(sekil);
    pencere.ciz(k1);
    pencere.ciz(k2);
    pencere.ciz(k3);
    pencere.ciz(k4);
}


// karakterin y�n�n� belirler
void Karakter::yonAta(YON yon)
{
    karakteryon = yon;
}


// karakterin y�n�n� d�nd�r�r
YON Karakter::yonGetir()
{
    return karakteryon;
}


// karakterin boyutunu d�nd�r�r
float Karakter::boyutgetir()
{
    return boyut;
}

// karakterin boyutunu de�i�tirir
void Karakter::boyutAta(float boyut)
{
	this->boyut = boyut; // global boyutu de�i�tirir
	sekil.setSize(Vector2f(boyut, boyut)); // karakterin boyutunu de�i�tirir
}

// karakterin h�z�n� d�nd�r�r
float Karakter::hizgetir()
{
    return hiz;
}

// karakterin h�z�n� de�i�tirir
void Karakter::hizAta(float hiz)
{
    this->hiz = hiz;
}

// karakterin haraket y�n�n� belirler
void Karakter::hareket()
{
    switch (karakteryon)
    {
    case YON::Yukari:
        mkonum.y -= hiz;
        break;
    case YON::Asagi:
        mkonum.y += hiz;
        break;
    case YON::Sag:
        mkonum.x += hiz;
        break;
    case YON::Sol:
        mkonum.x -= hiz;
        break;
    default:
        break;
    }
}

// karakterin y�n�ne g�re haraketini belirler
void Karakter::karakterKontrol()
{
    if (sekil.getPosition().y >= 690)
    {
        mkonum.y -= hiz;
    }
    if (sekil.getPosition().y <= 1)
    {
        mkonum.y += hiz;
    }
    if (sekil.getPosition().x >= 1250)
    {
        mkonum.x -= hiz;
    }
    if (sekil.getPosition().x <= 0)
    {
        mkonum.x += hiz;
    }
}

// karakterin rengini belirler
void Karakter::renkayarla(Color renk)
{
    sekil.setFillColor(renk);
}

// karakterin �eklini d�nd�r�r
RectangleShape Karakter::getsekil()
{
    return sekil;
}

// karakterin  �st par�alar�n� d�nd�r�r
RectangleShape Karakter::getk1()
{
	return k1; // k1 par�as�n� d�nd�r�r
}

// karakterin sa� par�alar�n� d�nd�r�r
RectangleShape Karakter::getk2()
{
    return k2;
}
// karakterin alt par�alar�n� d�nd�r�r
RectangleShape Karakter::getk3()
{
    return k3;
}

// karakterin sol par�alar�n� d�nd�r�r
RectangleShape Karakter::getk4()
{
    return k4;
}

// karakterin hareket y�n�n� belirler
void Karakter::karakteritis(YON yon)
{
    
    switch (yon)
    {
    case YON::Yukari:
        mkonum.y -= 20;
        yonAta(YON::Dur);
        break;
    case YON::Asagi:
        mkonum.y += 20;
        yonAta(YON::Dur);
        break;
    case YON::Sag:
        mkonum.x += 20;
        yonAta(YON::Dur);
        break;
    case YON::Sol:
        mkonum.x -= 20;
        yonAta(YON::Dur);
        break;
    default:
        break;
    }
}

// karakterin son konumunu d�nd�r�r
Vector2f Karakter::guncelkonum()
{
    Vector2f gkonum = sekil.getPosition();
    return gkonum;

}

