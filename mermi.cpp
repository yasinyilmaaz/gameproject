#include "mermi.hpp"
#include <iostream>


// Mermi sýnýfý yapýcý fonksiyonu = mermi rengini ve boyutunu ayarlar
Mermi::Mermi()
{
    sekil.setFillColor(Color::Black);
    sekil.setOutlineColor(Color::Black);
    sekil.setOutlineThickness(2);
    boyutAta(5);
    hizAta(10);
}

// Mermi çizme fonksiyonu  = mermi þeklini çizer
void Mermi::ciz(Pencere& pencere)
{
    sekil.setPosition(mkonum);
    pencere.ciz(sekil);
}

// Mermi boyutunu döndürür 
float Mermi::boyutgetir()
{
    return boyut;
}

// Mermi boyutunu atar 
void Mermi::boyutAta(float boyut)
{
    this->boyut = boyut;
    sekil.setSize(Vector2f(5, 5));
}


// Mermi hýzýný döndürür
float Mermi::hizgetir()
{
    return hiz;
}

// Mermi hýzýný atar 
void Mermi::hizAta(float hiz)
{
    this->hiz = hiz;
}

// Mermi þeklini döndürür
RectangleShape Mermi::getsekil()
{
    return sekil;
}

// Mermi hareketini saðlar ve hedefe doðru ilerler
void Mermi::mermiHareket(Vector2f hedef)
{
    mkonum += dusmanyol * hiz;
}


// Mermi konumunu atar
void Mermi::mermikonum(Vector2f konum)
{
    mkonum = konum;
}

// Mermi yolunu hesaplar ve döndürür
Vector2f Mermi::mermiyol(Vector2f& yol)
{
    try {
		float uzunluk = sqrt(yol.x * yol.x + yol.y * yol.y);
		if (uzunluk == 0)
			throw "Mermi yol hesaplanamadý";
		return Vector2f(yol.x / uzunluk, yol.y / uzunluk);
	}
	catch (const char* hata)
	{
		cout << hata << endl;
    }
    
}

// Mermi güncel konumunu döndürür
Vector2f Mermi::mermiguncelkonum()
{
    return mkonum;
}

// Mermi bitiþ konumunu atar
void Mermi::setbitiskonum(Vector2f baslangic)
{
    bitiskonum = baslangic;
}


// Mermi bitiþ konumunu döndürür
Vector2f Mermi::getbitiskonum()
{
    return bitiskonum;
}

// Mermi düþmanýn yolunu hesaplar
void Mermi::setdusmanyol()
{
    Vector2f yol = bitiskonum - mkonum;
    dusmanyol = mermiyol(yol);
}

// Mermi harita sýnýrlarýna çarptý mý kontrolü yapar
void Mermi::mermikontrol()
{
    if (sekil.getPosition().y >= 720)
    {
        mermiharitakonum = true;
    }
    if (sekil.getPosition().y <= 0)
    {
        mermiharitakonum = true;
    }
    if (sekil.getPosition().x >= 1280)
    {
        mermiharitakonum = true;
    }
    if (sekil.getPosition().x <= 0)
    {
        mermiharitakonum = true;
    }
}


// Mermi harita sýnýrlarýna çarptý mý kontrolü yapar
bool Mermi::getmermiharitakonum()
{
    return mermiharitakonum;
}
