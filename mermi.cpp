#include "mermi.hpp"
#include <iostream>


// Mermi s�n�f� yap�c� fonksiyonu = mermi rengini ve boyutunu ayarlar
Mermi::Mermi()
{
    sekil.setFillColor(Color::Black);
    sekil.setOutlineColor(Color::Black);
    sekil.setOutlineThickness(2);
    boyutAta(5);
    hizAta(10);
}

// Mermi �izme fonksiyonu  = mermi �eklini �izer
void Mermi::ciz(Pencere& pencere)
{
    sekil.setPosition(mkonum);
    pencere.ciz(sekil);
}

// Mermi boyutunu d�nd�r�r 
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


// Mermi h�z�n� d�nd�r�r
float Mermi::hizgetir()
{
    return hiz;
}

// Mermi h�z�n� atar 
void Mermi::hizAta(float hiz)
{
    this->hiz = hiz;
}

// Mermi �eklini d�nd�r�r
RectangleShape Mermi::getsekil()
{
    return sekil;
}

// Mermi hareketini sa�lar ve hedefe do�ru ilerler
void Mermi::mermiHareket(Vector2f hedef)
{
    mkonum += dusmanyol * hiz;
}


// Mermi konumunu atar
void Mermi::mermikonum(Vector2f konum)
{
    mkonum = konum;
}

// Mermi yolunu hesaplar ve d�nd�r�r
Vector2f Mermi::mermiyol(Vector2f& yol)
{
    try {
		float uzunluk = sqrt(yol.x * yol.x + yol.y * yol.y);
		if (uzunluk == 0)
			throw "Mermi yol hesaplanamad�";
		return Vector2f(yol.x / uzunluk, yol.y / uzunluk);
	}
	catch (const char* hata)
	{
		cout << hata << endl;
    }
    
}

// Mermi g�ncel konumunu d�nd�r�r
Vector2f Mermi::mermiguncelkonum()
{
    return mkonum;
}

// Mermi biti� konumunu atar
void Mermi::setbitiskonum(Vector2f baslangic)
{
    bitiskonum = baslangic;
}


// Mermi biti� konumunu d�nd�r�r
Vector2f Mermi::getbitiskonum()
{
    return bitiskonum;
}

// Mermi d��man�n yolunu hesaplar
void Mermi::setdusmanyol()
{
    Vector2f yol = bitiskonum - mkonum;
    dusmanyol = mermiyol(yol);
}

// Mermi harita s�n�rlar�na �arpt� m� kontrol� yapar
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


// Mermi harita s�n�rlar�na �arpt� m� kontrol� yapar
bool Mermi::getmermiharitakonum()
{
    return mermiharitakonum;
}
