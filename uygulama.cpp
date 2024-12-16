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
	dusmanciz();
	mermiciz();
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
	fareGuncelKonum = Vector2f(olay.x, olay.y);
}

void Uygulama::fareTiklandi(sf::Event::MouseButtonEvent olay)
{
	if (mermihazir)
	{
		fareTıklanmaKonum = fareGuncelKonum;
		mermiuret();
		mermiuretmehizi = 0.f;
	}
}

void Uygulama::karakterhasar()
{
	FloatRect k1box = karakter.getk1().getGlobalBounds();
	FloatRect k2box = karakter.getk2().getGlobalBounds();
	FloatRect k3box = karakter.getk3().getGlobalBounds();
	FloatRect k4box = karakter.getk4().getGlobalBounds();
	for (auto& d : dusmanlar) {
		FloatRect dusmanbox = d.getsekil().getGlobalBounds();
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
}

void Uygulama::dusmanuret()
{
	dusman.dusmanUret();
	dusmanlar.push_back(dusman);
}

void Uygulama::dusmanciz()
{
	for (auto& d : dusmanlar) {
		d.ciz(pencere);
	}
}

void Uygulama::dusmanguncelle()
{
	if (dusmanlar.size() < maxDusman)
	{
		if (dusmanuretmehizi >= dusmanuretmehiziMax)
		{
			dusmanuret();
			dusmanuretmehizi = 0.f;
		}
		else
		{
			dusmanuretmehizi += 1.f;
		}
	}
	for (int i = 0; i < dusmanlar.size(); i++)
	{
		bool silindi = false;
		dusmanlar[i].hareket(karakter.guncelkonum());
		for (int j = 0; j < mermiler.size(); j++)
		{
			if (this->dusmanlar[i].getsekil().getGlobalBounds().intersects(mermiler[j].getsekil().getGlobalBounds()))
			{
				silindi = true;
				dusmanlar.erase(dusmanlar.begin() + i);
				mermiler.erase(mermiler.begin() + j);

			}
		}
		FloatRect k1box = dusmanlar[i].getk1().getGlobalBounds();
		FloatRect k2box = dusmanlar[i].getk2().getGlobalBounds();
		FloatRect k3box = dusmanlar[i].getk3().getGlobalBounds();
		FloatRect k4box = dusmanlar[i].getk4().getGlobalBounds();
		for (auto m : dusmanlar) {
			FloatRect dusmanbox = m.getsekil().getGlobalBounds();
			if (k1box.intersects(dusmanbox) || k2box.intersects(dusmanbox) || k3box.intersects(dusmanbox) || k4box.intersects(dusmanbox))
			{
				if (k1box.intersects(dusmanbox))
				{
					dusmanlar[i].dusmanitis(YON::Asagi);
				}
				if (k3box.intersects(dusmanbox))
				{
					dusmanlar[i].dusmanitis(YON::Yukari);
				}
				if (k4box.intersects(dusmanbox))
				{
					dusmanlar[i].dusmanitis(YON::Sag);
				}
				if (k2box.intersects(dusmanbox))
				{
					dusmanlar[i].dusmanitis(YON::Sol);
				}

			}
		}
	}
}

void Uygulama::mermiuret()
{
	mermi.mermikonum(karakter.guncelkonum() + Vector2f(14, 14));
	mermi.setbitiskonum(fareTıklanmaKonum);
	mermi.setdusmanyol();
	mermiler.push_back(mermi);
}

void Uygulama::mermiciz()
{
	for (auto& m : mermiler) {
		m.ciz(pencere);
	}
}

void Uygulama::mermiguncelle()
{
	if (mermiuretmehizi >= mermiuretmehiziMax)
	{
		mermihazir = true;
	}
	else
	{
		mermihazir = false;
		mermiuretmehizi += 1.f;
	}
	for (int i = 0; i < mermiler.size(); i++)
	{
		mermiler[i].mermiHareket(mermiler[i].getbitiskonum());
		mermiler[i].mermikontrol();
		if (mermiler[i].getmermiharitakonum())
		{
			mermiler.erase(mermiler.begin() + i);
			cout << "mermi siindi" << endl;
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
			dusmanguncelle();
			mermiguncelle();
			gecenSure = sf::seconds(0.0f);
			saat.restart();
		}
		else
		{
			sf::sleep(gecenSure - cerceveSuresi);
		}
	}
}
