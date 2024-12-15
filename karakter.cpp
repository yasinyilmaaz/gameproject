#include "karakter.hpp"

Karakter::Karakter()
{
    sekil.setFillColor(Color::Green);
    sekil.setOutlineColor(Color::Black);
    sekil.setOutlineThickness(2);
    boyutAta(30);
    hizAta(5);
}

void Karakter::ciz(Pencere& pencere)
{
    sekil.setPosition(mkonum + Vector2f(640, 360));
    pencere.ciz(sekil);

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

