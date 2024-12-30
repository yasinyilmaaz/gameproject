#include "dusman.hpp"

Dusman::Dusman()
{
    sekil.setFillColor(Color::Red);//baþlangýç rengi
    sekil.setOutlineColor(Color::Black);//dýþ kenar rengi
    sekil.setOutlineThickness(2);//kenar kalýnlýðý
    boyutAta(30);//düþman boyut atamasý
    hizAta(2);//düþman hýz atamasý
    Canata(1);//düþman caný
    dusmanUret();
    k1.setSize(Vector2f(30, 5));//düþman çarpýþma kenarlarýnýn atanmasý
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
    sekil.setPosition(mkonum);//düþman ve çarpýþma kenarlarýnýn baþlangýç konumu
    k1.setPosition(mkonum);
    k2.setPosition(mkonum + Vector2f(30, 0));
    k3.setPosition(mkonum + Vector2f(2, 30));
    k4.setPosition(mkonum);

    pencere.ciz(sekil);//düþmanýn ve çarpýþma kenarlarýnýn çizimi
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
    sekil.setSize(Vector2f(boyut, boyut));//aldýðýmýz boyutu boyut*boyut'luk kare olacak þekilde atýyoruz
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
    Vector2f yol = hedef - mkonum;//düþman ile karakterin mevcut konumu arasýndaki uzaklýðý vektörel olarak hesaplama
    sf::Vector2f dusmanyol = Dusmanyol(yol);//bu hesapladaýðýmýz mesafeyi birim vektöre çevirme
    mkonum += dusmanyol * hiz;//düþmanýn birim vektöre göre hareketi
}

void Dusman::dusmanUret()
{
    int x = 0, y = 0;

    // Rastgele bir kenar seçiyoruz (üst, alt, sol veya sað)
    int kenar = rand() % 4;

    switch (kenar) {
    case 0: // Üst (oyun alanýnýn üstünde)
        x = rand() % genislik;
        y = -50;
        break;

    case 1: // Alt (oyun alanýnýn altýnda)
        x = rand() % genislik;
        y = yukseklik + 50;
        break;

    case 2: // Sol (oyun alanýnýn solunda)
        x = -50;
        y = rand() % yukseklik;
        break;

    case 3: // Sað (oyun alanýnýn saðýnda)
        x = genislik + 50;
        y = rand() % yukseklik;
        break;

    default:
        break;
    }

    if ((x < 0 || x >= genislik) || (y < 0 || y >= yukseklik)) {
        mkonum = Vector2f(x, y);
    }
    else {
        dusmanUret();
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

Vector2f Dusman::Dusmanyol(Vector2f& yol)
{
    float deger = std::sqrt(yol.x * yol.x + yol.y * yol.y);//birim vektör oluþturma formulü ile düþman ile karakter arasýndaki yolu birim vektöre döküyoruz
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
    switch (yon)//düþmanlar birbirine çarparsa çarptýklarý yöne göre birbirini itecek
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
