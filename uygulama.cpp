#include "uygulama.hpp"
void Uygulama::cerceveOlustur()
{
	sahneGuncelle();
	cizimFonksiyonu();
}

void Uygulama::cizimFonksiyonu()
{
	pencere.temizle();
	karakter.ciz(pencere);
	dusman.ciz(pencere);
	pencere.goster();
}

void Uygulama::sahneGuncelle()
{
	karakter.hareket();
}

void Uygulama::tusBasildi(sf::Keyboard::Key tus)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
		karakter.yonAta(YON::Sol);
	if (Keyboard::isKeyPressed(Keyboard::D))
		karakter.yonAta(YON::Sag);
	if (Keyboard::isKeyPressed(Keyboard::W))
		karakter.yonAta(YON::Yukari);
	if (Keyboard::isKeyPressed(Keyboard::S))
		karakter.yonAta(YON::Asagi);
}

void Uygulama::tusBirakildi(sf::Keyboard::Key tus)
{
	if (tus == sf::Keyboard::W)
		karakter.yonAta(YON::Dur);
	if (tus == sf::Keyboard::A)
		karakter.yonAta(YON::Dur);
	if (tus == sf::Keyboard::S)
		karakter.yonAta(YON::Dur);
	if (tus == sf::Keyboard::D)
		karakter.yonAta(YON::Dur);
}

void Uygulama::fareHareket(sf::Event::MouseMoveEvent olay)
{

}

void Uygulama::fareTiklandi(sf::Event::MouseButtonEvent olay)
{
}

void Uygulama::karakterhasar()
{
	FloatRect karakterbox = karakter.getsekil().getGlobalBounds();
	FloatRect dusmanbox = dusman.getsekil().getGlobalBounds();
	if (karakterbox.intersects(dusmanbox))
	{
		if (karakter.konumGetir().y > dusman.konumGetir().y)
		{
			karakter.karakteritis(YON::Yukari);
		}
		if (karakter.konumGetir().y < dusman.konumGetir().y)
		{
			karakter.karakteritis(YON::Asagi);
		}
		if (karakter.konumGetir().x > dusman.konumGetir().x)
		{
			karakter.karakteritis(YON::Sag);
		}
		if (karakter.konumGetir().x < dusman.konumGetir().x)
		{
			karakter.karakteritis(YON::Sol);
		}
		Can--;
		if (Can == 2) {
			karakter.renkayarla(Color::Blue);
		}
		else if (Can == 1) {
			karakter.renkayarla(Color::Black);
		}
		else if (Can <= 0) {
			cout << Can << endl;
		}
	}
	if (!karakterbox.intersects(dusmanbox))
	{

	}
}

Uygulama::Uygulama()
{
}

void Uygulama::insaEt(int genislik, int yukseklik)
{
	pencere.olustur(genislik, yukseklik);
	dusman.ayarla(yukseklik, genislik);
	pencere.farehareketfonkekle(
		std::bind(&Uygulama::fareHareket, this, std::placeholders::_1)
	);
	pencere.faretiklamafonkekle(
		std::bind(&Uygulama::fareTiklandi, this, std::placeholders::_1)
	);
	pencere.tusabasfonkekle(
		std::bind(&Uygulama::tusBasildi, this, std::placeholders::_1)
	);
	pencere.tusubirakfonkekle(
		std::bind(&Uygulama::tusBirakildi, this, std::placeholders::_1)
	);
}

void Uygulama::baslat(int fps)
{
	float cerfps = 1.0f / fps;
	cerceveSuresi = sf::seconds(cerfps);

	gecenSure = saat.restart();
	karakter.yonAta(YON::Dur);
	while (pencere.pencereAcikmi())
	{
		pencere.olaylariisle();

		gecenSure = saat.getElapsedTime();

		if (gecenSure >= cerceveSuresi)
		{

			cerceveOlustur();
			karakter.karakterKontrol();
			karakterhasar();
			gecenSure = sf::seconds(0.0f);
			saat.restart();
		}
		else
		{
			sf::sleep(gecenSure - cerceveSuresi);
		}
	}
}
