#include "pencere.hpp"
#include "uygulama.hpp"


// pencereyi olu�turur ve ba�l�k ad�n� ve boyutunu ayarlar
void Pencere::olustur(unsigned int genislik, unsigned int yukseklik, const sf::String& ad)
{
	mpencere.create(sf::VideoMode(genislik, yukseklik), ad);
}

// �ekli �izer ve ekrana g�sterir
void Pencere::ciz(Drawable& sekil)
{
	mpencere.draw(sekil);

}

void Pencere::olaylariisle()
{
	Event olay;
	while (mpencere.pollEvent(olay))
	{
		// pencere kapatma olay�
		if (olay.type == Event::Closed)
			pencerekapat();
		// klavye olaylar�
		if (olay.type == sf::Event::KeyPressed)
		{
			for (auto siradaki : tusaBasFonklari)
				siradaki(olay.key.code);
		}
		// klavye b�rakma olaylar�
		if (olay.type == sf::Event::KeyReleased)
		{
			for (auto siradaki : tusubirakFonklari)
				siradaki(olay.key.code);
		}
		// fare hareket olaylar� haraket ettirme durumunda fareyi takip eder
		if (olay.type == sf::Event::MouseMoved)
		{
			for (auto siradaki : fareHareketFonklari) 
				siradaki(olay.mouseMove);
		}
		// fare t�klama olaylar� 
		if (olay.type == Event::MouseButtonPressed)
		{
			if (olay.mouseButton.button == Mouse::Left)// fare sol t�klama olay�
			{
				for (auto siradaki : fareTiklamaFonklari)
					siradaki(olay.mouseButton);
			}
		}
	}
}


// pencerenin a��k olup olmad���n� kontrol eder
bool Pencere::pencereAcikmi()
{
	return mpencere.isOpen();
}

// pencereyi kapat�r
void Pencere::pencerekapat()
{
	mpencere.close();
}

// pencereyi temizler
void Pencere::temizle()
{
	mpencere.clear(Color::White);
}


// pencereyi g�sterir
void Pencere::goster()
{
	mpencere.display();
}

// pencereye klavye fonksiyonu ekler
void Pencere::tusabasfonkekle(KlavyeFonksiyonu fonk)
{
	tusaBasFonklari.push_back(fonk);
}
// pencereye klavye tu� b�rakma fonksiyonu ekler 
void Pencere::tusubirakfonkekle(KlavyeFonksiyonu fonk)
{
	tusubirakFonklari.push_back(fonk);
}
// pencereye fare hareket fonksiyonu ekler
void Pencere::farehareketfonkekle(FareHareketFonk fonk)
{
	fareHareketFonklari.push_back(fonk);
}

// pencereye fare t�klama fonksiyonu ekler
void Pencere::faretiklamafonkekle(FareTiklamaFonk fonk)
{
	fareTiklamaFonklari.push_back(fonk);
}
// pencereyi d�nd�r�r
sf::RenderWindow& Pencere::getRenderWindow()
{
	return mpencere; // mpencere sf::RenderWindow tipinde oldu�u i�in do�rudan d�nebiliriz
}
