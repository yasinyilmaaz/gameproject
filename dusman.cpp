#include "dusman.hpp"

Dusman::Dusman()
{
    sekil.setFillColor(Color::Red);
    sekil.setOutlineColor(Color::Black);
    sekil.setOutlineThickness(2);
    boyutAta(30);
    hizAta(2);
    dusmanUret();
}

void Dusman::ciz(Pencere& pencere)
{
    sekil.setPosition(mkonum);
    pencere.ciz(sekil);
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

void Dusman::hareket()
{
}

void Dusman::dusmanUret()
{
    srand(time(0));
    int x = (rand() % yukseklik);
    int y = (rand() % genislik);
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
