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
