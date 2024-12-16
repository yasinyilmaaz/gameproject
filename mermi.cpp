#include "mermi.hpp"

Mermi::Mermi()
{
    sekil.setFillColor(Color::Black);
    sekil.setOutlineColor(Color::Black);
    sekil.setOutlineThickness(2);
    boyutAta(5);
    hizAta(10);
}

void Mermi::ciz(Pencere& pencere)
{
    sekil.setPosition(mkonum);
    pencere.ciz(sekil);
}

float Mermi::boyutgetir()
{
    return boyut;
}

void Mermi::boyutAta(float boyut)
{
    this->boyut = boyut;
    sekil.setSize(Vector2f(5, 5));
}

float Mermi::hizgetir()
{
    return hiz;
}

void Mermi::hizAta(float hiz)
{
    this->hiz = hiz;
}

RectangleShape Mermi::getsekil()
{
    return sekil;
}

void Mermi::mermiHareket(Vector2f hedef)
{
    Vector2f yol = hedef - mkonum;
    sf::Vector2f dusmanyol = mermiyol(yol);
    mkonum += dusmanyol * hiz;
}

void Mermi::mermikonum(Vector2f konum)
{
    mkonum = konum;
}

Vector2f Mermi::mermiyol(Vector2f& yol)
{
    float deger = std::sqrt(yol.x * yol.x + yol.y * yol.y);
    if (deger == 0) return sf::Vector2f(0.f, 0.f);
    return yol / deger;
}

Vector2f Mermi::mermiguncelkonum()
{
    return mkonum;
}

void Mermi::setbitiskonum(Vector2f baslangic)
{
    bitiskonum = baslangic;
}

Vector2f Mermi::getbitiskonum()
{
    return bitiskonum;
}
