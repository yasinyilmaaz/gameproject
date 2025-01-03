#include "karakter.hpp"


// Karakter sýnýfý yapýcý fonksiyonu = karakter rengini , boyutunu ayarlar ve karakterin hareket hýzýný belirler ve karakterin parçalarýný oluþturur
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

// Karakter çizme fonksiyonu = karakter þeklini çizer
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


// karakterin yönünü belirler
void Karakter::yonAta(YON yon)
{
    karakteryon = yon;
}


// karakterin yönünü döndürür
YON Karakter::yonGetir()
{
    return karakteryon;
}


// karakterin boyutunu döndürür
float Karakter::boyutgetir()
{
    return boyut;
}

// karakterin boyutunu deðiþtirir
void Karakter::boyutAta(float boyut)
{
	this->boyut = boyut; // global boyutu deðiþtirir
	sekil.setSize(Vector2f(boyut, boyut)); // karakterin boyutunu deðiþtirir
}

// karakterin hýzýný döndürür
float Karakter::hizgetir()
{
    return hiz;
}

// karakterin hýzýný deðiþtirir
void Karakter::hizAta(float hiz)
{
    this->hiz = hiz;
}

// karakterin haraket yönünü belirler
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

// karakterin yönüne göre haraketini belirler
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

// karakterin þeklini döndürür
RectangleShape Karakter::getsekil()
{
    return sekil;
}

// karakterin  üst parçalarýný döndürür
RectangleShape Karakter::getk1()
{
	return k1; // k1 parçasýný döndürür
}

// karakterin sað parçalarýný döndürür
RectangleShape Karakter::getk2()
{
    return k2;
}
// karakterin alt parçalarýný döndürür
RectangleShape Karakter::getk3()
{
    return k3;
}

// karakterin sol parçalarýný döndürür
RectangleShape Karakter::getk4()
{
    return k4;
}

// karakterin hareket yönünü belirler
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

// karakterin son konumunu döndürür
Vector2f Karakter::guncelkonum()
{
    Vector2f gkonum = sekil.getPosition();
    return gkonum;

}

