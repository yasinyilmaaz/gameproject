#include "karakter.hpp"

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

void Karakter::yonAta(YON yon)
{
    karakteryon = yon;
}

YON Karakter::yonGetir()
{
    return karakteryon;
}

float Karakter::boyutgetir()
{
    return boyut;
}

void Karakter::boyutAta(float boyut)
{
    this->boyut = boyut;
    sekil.setSize(Vector2f(boyut, boyut));
}

float Karakter::hizgetir()
{
    return hiz;
}

void Karakter::hizAta(float hiz)
{
    this->hiz = hiz;
}

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

void Karakter::renkayarla(Color renk)
{
    sekil.setFillColor(renk);
}

RectangleShape Karakter::getsekil()
{
    return sekil;
}

RectangleShape Karakter::getk1()
{
    return k1;
}

RectangleShape Karakter::getk2()
{
    return k2;
}

RectangleShape Karakter::getk3()
{
    return k3;
}

RectangleShape Karakter::getk4()
{
    return k4;
}

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

Vector2f Karakter::guncelkonum()
{
    Vector2f gkonum = sekil.getPosition();
    return gkonum;

}

