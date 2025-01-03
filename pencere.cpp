#include "pencere.hpp"
#include "uygulama.hpp"


// pencereyi oluþturur ve baþlýk adýný ve boyutunu ayarlar
void Pencere::olustur(unsigned int genislik, unsigned int yukseklik, const sf::String& ad)
{
	mpencere.create(sf::VideoMode(genislik, yukseklik), ad);
}

// þekli çizer ve ekrana gösterir
void Pencere::ciz(Drawable& sekil)
{
	mpencere.draw(sekil);

}

void Pencere::olaylariisle()
{
	Event olay;
	while (mpencere.pollEvent(olay))
	{
		// pencere kapatma olayý
		if (olay.type == Event::Closed)
			pencerekapat();
		// klavye olaylarý
		if (olay.type == sf::Event::KeyPressed)
		{
			for (auto siradaki : tusaBasFonklari)
				siradaki(olay.key.code);
		}
		// klavye býrakma olaylarý
		if (olay.type == sf::Event::KeyReleased)
		{
			for (auto siradaki : tusubirakFonklari)
				siradaki(olay.key.code);
		}
		// fare hareket olaylarý haraket ettirme durumunda fareyi takip eder
		if (olay.type == sf::Event::MouseMoved)
		{
			for (auto siradaki : fareHareketFonklari) 
				siradaki(olay.mouseMove);
		}
		// fare týklama olaylarý 
		if (olay.type == Event::MouseButtonPressed)
		{
			if (olay.mouseButton.button == Mouse::Left)// fare sol týklama olayý
			{
				for (auto siradaki : fareTiklamaFonklari)
					siradaki(olay.mouseButton);
			}
		}
	}
}


// pencerenin açýk olup olmadýðýný kontrol eder
bool Pencere::pencereAcikmi()
{
	return mpencere.isOpen();
}

// pencereyi kapatýr
void Pencere::pencerekapat()
{
	mpencere.close();
}

// pencereyi temizler
void Pencere::temizle()
{
	mpencere.clear(Color::White);
}


// pencereyi gösterir
void Pencere::goster()
{
	mpencere.display();
}

// pencereye klavye fonksiyonu ekler
void Pencere::tusabasfonkekle(KlavyeFonksiyonu fonk)
{
	tusaBasFonklari.push_back(fonk);
}
// pencereye klavye tuþ býrakma fonksiyonu ekler 
void Pencere::tusubirakfonkekle(KlavyeFonksiyonu fonk)
{
	tusubirakFonklari.push_back(fonk);
}
// pencereye fare hareket fonksiyonu ekler
void Pencere::farehareketfonkekle(FareHareketFonk fonk)
{
	fareHareketFonklari.push_back(fonk);
}

// pencereye fare týklama fonksiyonu ekler
void Pencere::faretiklamafonkekle(FareTiklamaFonk fonk)
{
	fareTiklamaFonklari.push_back(fonk);
}
// pencereyi döndürür
sf::RenderWindow& Pencere::getRenderWindow()
{
	return mpencere; // mpencere sf::RenderWindow tipinde olduðu için doðrudan dönebiliriz
}
