#include "dusman.hpp"

Dusman::Dusman()
{
    sekil.setFillColor(Color::Red);
    sekil.setOutlineColor(Color::Black);
    sekil.setOutlineThickness(2);
    boyutAta(30);
    hizAta(2);
    dusmanUret();
    k1.setSize(Vector2f(30, 5));
    k2.setSize(Vector2f(5, 30));
    k3.setSize(Vector2f(30, 5));
    k4.setSize(Vector2f(5, 30));
    k1.setFillColor(Color::Transparent);
    k2.setFillColor(Color::Transparent);
    k3.setFillColor(Color::Transparent);
    k4.setFillColor(Color::Transparent);
}

void Dusman::ciz(Pencere& pencere)
{
    sekil.setPosition(mkonum);
    k1.setPosition(mkonum);
    k2.setPosition(mkonum + Vector2f(30, 0));
    k3.setPosition(mkonum + Vector2f(2, 30));
    k4.setPosition(mkonum);

    pencere.ciz(sekil);
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
    sekil.setSize(Vector2f(boyut, boyut));
}

float Dusman::hizgetir()
{
    return hiz;
}

void Dusman::hizAta(float hiz)
{
    this->hiz = hiz;
}

void Dusman::hareket(Vector2f hedef)
{
    Vector2f yol = hedef - mkonum;
    sf::Vector2f dusmanyol = Dusmanyol(yol);
    mkonum += dusmanyol * hiz;
}

void Dusman::dusmanUret()
{
    int a, b;
    srand(time(0));
    if (rand() % 2 == 0) {
        a = 360; b = 600;
        if (rand() % yukseklik < 360)
        {
            a = 720;
        }if (rand() % genislik < 600)
        {
            a = 1280;
        }
    }
    else {
        a = -360; b = -600;
        if (rand() % yukseklik > 360)
        {
            a = -720;
        }if (rand() % genislik > 600)
        {
            a = -1280;
        }
    }
    int x = (rand() % yukseklik + a);
    int y = (rand() % genislik + b);
    mkonum = Vector2f(y, x);
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

Vector2f Dusman::Dusmanyol(Vector2f& yol)
{
    float deger = std::sqrt(yol.x * yol.x + yol.y * yol.y);
    if (deger == 0) return sf::Vector2f(0.f, 0.f);
    return yol / deger;
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
    switch (yon)
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
