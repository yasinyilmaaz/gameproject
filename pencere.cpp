#include "pencere.hpp"

void Pencere::olustur(unsigned int genislik, unsigned int yukseklik, const sf::String& ad)
{
	mpencere.create(sf::VideoMode(genislik, yukseklik), ad);
}

void Pencere::ciz(Drawable& sekil)
{
	mpencere.draw(sekil);

}

void Pencere::olaylariisle()
{
	Event olay;
	while (mpencere.pollEvent(olay))
	{
		if (olay.type == Event::Closed)
			pencerekapat();
		if (olay.type == sf::Event::KeyPressed)
		{
			for (auto siradaki : tusaBasFonklari)
				siradaki(olay.key.code);
		}
		if (olay.type == sf::Event::KeyReleased)
		{
			for (auto siradaki : tusubirakFonklari)
				siradaki(olay.key.code);
		}
		if (olay.type == sf::Event::MouseMoved)
		{
			for (auto siradaki : fareHareketFonklari)
				siradaki(olay.mouseMove);
		}
		if (olay.type == Event::MouseButtonPressed)
		{
			if (olay.mouseButton.button == Mouse::Left)
			{
				for (auto siradaki : fareTiklamaFonklari)
					siradaki(olay.mouseButton);
			}
		}
	}
}

bool Pencere::pencereAcikmi()
{
	return mpencere.isOpen();
}

void Pencere::pencerekapat()
{
	mpencere.close();
}

void Pencere::temizle()
{
	mpencere.clear(Color::White);
}

void Pencere::goster()
{
	mpencere.display();
}

void Pencere::tusabasfonkekle(KlavyeFonksiyonu fonk)
{
	tusaBasFonklari.push_back(fonk);
}

void Pencere::tusubirakfonkekle(KlavyeFonksiyonu fonk)
{
	tusubirakFonklari.push_back(fonk);
}

void Pencere::farehareketfonkekle(FareHareketFonk fonk)
{
	fareHareketFonklari.push_back(fonk);
}

void Pencere::faretiklamafonkekle(FareTiklamaFonk fonk)
{
	fareTiklamaFonklari.push_back(fonk);
}
