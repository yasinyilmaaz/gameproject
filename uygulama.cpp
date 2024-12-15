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
	FloatRect k1box = karakter.getk1().getGlobalBounds();
	FloatRect k2box = karakter.getk2().getGlobalBounds();
	FloatRect k3box = karakter.getk3().getGlobalBounds();
	FloatRect k4box = karakter.getk4().getGlobalBounds();
	FloatRect dusmanbox = dusman.getsekil().getGlobalBounds();
	if (k1box.intersects(dusmanbox) || k2box.intersects(dusmanbox) || k3box.intersects(dusmanbox) || k4box.intersects(dusmanbox))
	{
		if (k1box.intersects(dusmanbox))
		{
			karakter.karakteritis(YON::Asagi);
		}
		if (k3box.intersects(dusmanbox))
		{
			karakter.karakteritis(YON::Yukari);
		}
		if (k4box.intersects(dusmanbox))
		{
			karakter.karakteritis(YON::Sag);
		}
		if (k2box.intersects(dusmanbox))
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
			dusman.hareket(karakter.guncelkonum());
			gecenSure = sf::seconds(0.0f);
			saat.restart();
		}
		else
		{
			sf::sleep(gecenSure - cerceveSuresi);
		}
	}
}
