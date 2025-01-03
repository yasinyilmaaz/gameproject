#include "uygulama.hpp"
#include <iostream>
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
		fareTiklanmaKonum = fareGuncelKonum;
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
			puan = puan - 50;
			
		}
	}
}

void Uygulama::dusmanuret()
{
	dusman.Canata(DusmanCan);
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
		dusmanlar[i].hareket(karakter.guncelkonum());
		for (int j = 0; j < mermiler.size(); j++)
		{
			if (this->dusmanlar[i].getsekil().getGlobalBounds().intersects(mermiler[j].getsekil().getGlobalBounds()))
			{
				puan = puan + 10;
				
				mermiler.erase(mermiler.begin() + j);
				dusmanlar[i].Canata(dusmanlar[i].Cangetir() - 1);
				if (dusmanlar[i].Cangetir() < 1)
				{
					dusmanlar.erase(dusmanlar.begin() + i);
					YokEdilenD++;
					dusmanarttirma++;
				}
				if (Can < 3 && YokEdilenD>3)
				{
					Can++;
					YokEdilenD = 0;
				}

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
	mermi.setbitiskonum(fareTiklanmaKonum);
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
		}

	}
}

void Uygulama::canKontrol()
{
	if (Can == 3)
	{
		karakter.renkayarla(Color::Green);
	}
	else if (Can == 2) {
		karakter.renkayarla(Color::Blue);
	}
	else if (Can == 1) {
		karakter.renkayarla(Color::Black);
	}


}

void Uygulama::maxDusmanArttirma()
{
	if (dusmanarttirma >= 5 && maxDusman < 20)
	{
		maxDusman += 1;
		dusmanarttirma = 0;
	}
	else if (dusmanarttirma >= 5 && maxDusman >= 20)
	{
		DusmanCan++;
		dusmanarttirma = 0;
		maxDusman = 10;
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



void Uygulama::hoverKontrol(sf::RectangleShape& buton, sf::Vector2f farePozisyonu)
{
	if (buton.getGlobalBounds().contains(farePozisyonu)) {
		// Fare butonun �zerine gelirse, butonun rengini de�i�tir
		buton.setFillColor(sf::Color::Yellow);  // �rne�in, hover olunca sar� yapal�m
	}
	else {
		// Fare butonun �zerinden ayr�ld���nda, eski rengine geri d�n
		buton.setFillColor(sf::Color::Green);  // Normalde ye�il
	}
}

void Uygulama::tiklamaKontrol(sf::RectangleShape& buton, sf::Vector2f farePozisyonu, int olay)
{

	// "Tekrar Oyna" butonuna t�klama kontrol�
	if (buton.getGlobalBounds().contains(farePozisyonu) &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left) && olay==1) {
		// Butona t�klan�rsa yeni bir oyun ba�lat
		pencere.pencerekapat();
		Uygulama yeniOyun;
		yeniOyun.insaEt(1280, 720);
		yeniOyun.baslat(60); // FPS'yi ge�mek istiyorsan�z bunu da parametre olarak ge�ebilirsiniz
	}
	// "Kapat" butonuna t�klama kontrol�
	if (buton.getGlobalBounds().contains(farePozisyonu) &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left) && olay == 0) {
		// Uygulama kapans�n
		pencere.pencerekapat();
	}
}

void Uygulama::ekrandaButonVeSkorGoster()
{
	// Fontu y�kleyelim
	sf::Font font;
	if (!font.loadFromFile("D:/SFML/font/arimo/ArimoBold.ttf")) {
		std::cerr << "Font y�klenemedi!" << std::endl;
		return;
	}

	// Skor metnini olu�turma
	sf::Text skorMetni;
	skorMetni.setFont(font);
	skorMetni.setCharacterSize(34);
	skorMetni.setPosition(540, 215);
	skorMetni.setFillColor(sf::Color::Black);
	skorMetni.setString("Skor:   " + std::to_string(puan));

	// Buton olu�turma
	sf::RectangleShape buton(sf::Vector2f(200, 50)); // Buton boyutu
	buton.setFillColor(sf::Color::Green);
	buton.setPosition(540, 300); // Ekranda butonun yerini ayarla

	// "Kapat" butonunu olu�turma
	sf::RectangleShape kapatButonu(sf::Vector2f(200, 50)); // Buton boyutu
	kapatButonu.setFillColor(sf::Color::Red);
	kapatButonu.setPosition(540, 370); // Ekranda butonun yerini ayarla

	// Buton �zerindeki yaz�y� olu�turma
	sf::Text butonYazisi;
	butonYazisi.setFont(font);
	butonYazisi.setCharacterSize(20);
	butonYazisi.setFillColor(sf::Color::Black);
	butonYazisi.setString("Tekrar Oyna");
	butonYazisi.setPosition(580, 315); // Buton �zerindeki yaz�

	// "Kapat" butonundaki yaz�y� olu�turma
	sf::Text kapatButonYazisi;
	kapatButonYazisi.setFont(font);
	kapatButonYazisi.setCharacterSize(20);
	kapatButonYazisi.setFillColor(sf::Color::Black);
	kapatButonYazisi.setString("Kapat");
	kapatButonYazisi.setPosition(610, 385); // Buton �zerindeki yaz�

	// Hover olay�n� kontrol et
	hoverKontrol(buton, fareGuncelKonum);
	hoverKontrol(kapatButonu, fareGuncelKonum);
	// Buton ve skoru ekranda �izme
	tiklamaKontrol(buton, fareGuncelKonum,1);
	tiklamaKontrol(kapatButonu, fareGuncelKonum,0);


	pencere.temizle();
	pencere.ciz(skorMetni);  // Skoru ekranda g�ster
	pencere.ciz(buton);      // Butonu ekranda g�ster
	pencere.ciz(butonYazisi); // Buton yaz�s�n� ekranda g�ster
	pencere.ciz(kapatButonu); // Kapat butonunu ekranda g�ster
	pencere.ciz(kapatButonYazisi); // Kapat butonu yaz�s�n� ekranda g�ster
	
	pencere.goster();
}

void Uygulama::baslat(int fps)
{
	float cerfps = 1.0f / fps;
	cerceveSuresi = sf::seconds(cerfps);

	gecenSure = saat.restart();


	karakter.yonAta(YON::Dur);
;
	while (pencere.pencereAcikmi())
	{
		pencere.olaylariisle();
		sf::Vector2i farePozisyonuGlobal = sf::Mouse::getPosition(pencere.getRenderWindow());  // Global fare pozisyonu
		fareGuncelKonum = pencere.getRenderWindow().mapPixelToCoords(farePozisyonuGlobal);
		gecenSure = saat.getElapsedTime();

		if (gecenSure >= cerceveSuresi)
		{
			if(Can <= 0) {
				
				ekrandaButonVeSkorGoster();
				// T�klama olay�n� kontrol et
				
				gecenSure = sf::seconds(0.0f);
				saat.restart();
			}
			else {
				cerceveOlustur();
				karakter.karakterKontrol();
				karakterhasar();
				dusmanguncelle();
				mermiguncelle();
				canKontrol();
				maxDusmanArttirma();
				gecenSure = sf::seconds(0.0f);
				saat.restart();
			}
		}
		else
		{
			sf::sleep(gecenSure - cerceveSuresi);
		}
	}
}
