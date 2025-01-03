#include "uygulama.hpp"
#include <iostream>

// Oyunun �er�evesini olu�turur ve karakteri �izer ve d��manlar� �izer ve mermileri �izer ve ekrana g�sterir
void Uygulama::cerceveOlustur()
{
	sahneGuncelle();
	cizimFonksiyonu();
}


// ekran� temizler ve karakteri �izer ve d��manlar� �izer ve mermileri �izer ve ekrana g�sterir
void Uygulama::cizimFonksiyonu()
{
	pencere.temizle();
	karakter.ciz(pencere);
	dusmanciz();
	mermiciz();
	pencere.goster();
}

// karakterin hareketini sa�lar
void Uygulama::sahneGuncelle()
{
	karakter.hareket();
}

// tu�a bas�ld���nda karakterin hareketini sa�lar
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


// Tu� b�rak�ld���nda karakterin durmas�n� sa�lar
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
	fareGuncelKonum = Vector2f(olay.x, olay.y); // Fare pozisyonunu g�nceller 
}


// Fare t�kland���nda mermi �retir ve mermi h�z�n� s�f�rlar
void Uygulama::fareTiklandi(sf::Event::MouseButtonEvent olay)
{
	if (mermihazir)
	{
		fareTiklanmaKonum = fareGuncelKonum;
		mermiuret();
		mermiuretmehizi = 0.f;
	}
}

// Karakterin d��manlara �arpmas�n� kontrol eder ve can�n� azalt�r
void Uygulama::karakterhasar()
{
	FloatRect k1box = karakter.getk1().getGlobalBounds();
	FloatRect k2box = karakter.getk2().getGlobalBounds();
	FloatRect k3box = karakter.getk3().getGlobalBounds();
	FloatRect k4box = karakter.getk4().getGlobalBounds();

	// D��manlarla �arp��ma kontrol� ve d��manlara �arpt���nda karakterin can�n� azaltma
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
			// E�er karakter d��mana �arparsa can�n� azalt puan eksilt
			Can--;
			puan = puan - 20;
			
		}
	}
}

// D��man �retme fonksiyonu = d��man �retir ve d��man �retme h�z�n� s�f�rlar 
void Uygulama::dusmanuret()
{
	dusman.Canata(DusmanCan);
	dusman.dusmanUret();
	dusmanlar.push_back(dusman);
}

// D��manlar� �izme fonksiyonu = d��manlar� ekrana �izdirir 
void Uygulama::dusmanciz()
{
	for (auto& d : dusmanlar) {
		d.ciz(pencere);
	}
}

// D��man g�ncelleme fonksiyonu = d��man �retme, d��man hareket ve d��man �arp��malar�n� kontrol etme i�lemlerini yapar
void Uygulama::dusmanGuncelle()
{
	dusmanEkle();
	dusmanlariHareketEttir();
	dusmanCarpismalariniKontrolEt();
}

// D��man �retme fonksiyonu = d��man �retir ve d��man �retme h�z�n� s�f�rlar
void Uygulama::dusmanEkle()
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
}

// D��manlar�n karaktere do�ru hareket etmesini sa�lar
void Uygulama::dusmanlariHareketEttir()
{
	for (auto& dusman : dusmanlar)
	{
		dusman.hareket(karakter.guncelkonum());
	}
}

// D��manlar�n birbirine ve mermilere �arp��mas�n� kontrol eder
void Uygulama::dusmanCarpismalariniKontrolEt()
{
	for (size_t i = 0; i < dusmanlar.size(); ++i)
	{
		dusmanMermiCarpismaKontrol(i);
		dusmanDusmanCarpismaKontrol(i);
	}
}

// D��manlar�n mermilerle �arp��mas�n� kontrol eder
void Uygulama::dusmanMermiCarpismaKontrol(size_t dusmanIndex)
{
	for (size_t j = 0; j < mermiler.size(); ++j)
	{
		// E�er mermi ve d��man �arp���rsa mermiyi ve d��man� sil ve puan� artt�r
		if (dusmanlar[dusmanIndex].getsekil().getGlobalBounds().intersects(mermiler[j].getsekil().getGlobalBounds()))
		{
			puan += 10;

			mermiler.erase(mermiler.begin() + j); // Mermiyi sil
			dusmanlar[dusmanIndex].Canata(dusmanlar[dusmanIndex].Cangetir() - 1); // D��man�n can�n� azalt

			// E�er d��man�n can� 0'dan k���kse d��man� sil
			if (dusmanlar[dusmanIndex].Cangetir() < 1)
			{
				dusmanlar.erase(dusmanlar.begin() + dusmanIndex); // D��man� sil
				YokEdilenD++;
				dusmanarttirma++;

				// e�er 3 d��man yok edilirse can� 1 artt�r
				if (Can < 3 && YokEdilenD > 3)
				{
					Can++;
					YokEdilenD = 0;
				}
			}

			break;
		}
	}
}

// D��manlar�n birbirine �arp��mas�n� kontrol eder
void Uygulama::dusmanDusmanCarpismaKontrol(size_t dusmanIndex)
{
	auto& dusman = dusmanlar[dusmanIndex];
	// D��man�n kenarlar�n� al ve di�er d��manlarla �arp��mas�n� kontrol et
	FloatRect k1box = dusman.getk1().getGlobalBounds();
	FloatRect k2box = dusman.getk2().getGlobalBounds();
	FloatRect k3box = dusman.getk3().getGlobalBounds();
	FloatRect k4box = dusman.getk4().getGlobalBounds();

	for (auto& digerDusman : dusmanlar)
	{
		// E�er d��manlar birbirine �arparsa d��manlar� it
		FloatRect dusmanbox = digerDusman.getsekil().getGlobalBounds();
		if (k1box.intersects(dusmanbox))
		{
			dusman.dusmanitis(YON::Asagi);
		}
		if (k2box.intersects(dusmanbox))
		{
			dusman.dusmanitis(YON::Sol);
		}
		if (k3box.intersects(dusmanbox))
		{
			dusman.dusmanitis(YON::Yukari);
		}
		if (k4box.intersects(dusmanbox))
		{
			dusman.dusmanitis(YON::Sag);
		}
	}
}

// Mermi �retme fonksiyonu = mermi �retir
void Uygulama::mermiuret()
{
	mermi.mermikonum(karakter.guncelkonum() + Vector2f(14, 14));
	mermi.setbitiskonum(fareTiklanmaKonum);
	mermi.setdusmanyol();
	mermiler.push_back(mermi);
}

//  Mermileri �izme fonksiyonu = mermileri ekrana �izdirir
void Uygulama::mermiciz()
{
	for (auto& m : mermiler) {
		m.ciz(pencere);// Mermiyi �iz
	}
}


// Mermi g�ncelleme fonksiyonu = mermi hareket, mermi kontrol ve mermi silme i�lemlerini yapar
void Uygulama::mermiguncelle()
{
	if (mermiuretmehizi >= mermiuretmehiziMax)
	{
		// E�er mermi haz�rsa mermi �retme h�z�n� s�f�rla
		mermihazir = true;
	}
	else
	{
		// E�er mermi haz�r de�ilse mermi �retme h�z�n� artt�r
		mermihazir = false;
		mermiuretmehizi += 1.f;
	}
	for (int i = 0; i < mermiler.size(); i++)
	{
		mermiler[i].mermiHareket(mermiler[i].getbitiskonum()); // Mermi hareket ettir 
		mermiler[i].mermikontrol();// Mermi kontrol� yap
		if (mermiler[i].getmermiharitakonum()) // E�er mermi harita d���na ��karsa mermiyi sil
		{
			mermiler.erase(mermiler.begin() + i); // Mermiyi sil
		}

	}
}


// Can kontrol fonksiyonu. Can azald�k�a karakterin rengini de�i�tirir
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

// D��man say�s�na g�re d��man say�s�n� ve can�n� artt�r�r
void Uygulama::maxDusmanArttirma()
{
	// E�er d��man say�s� 5'ten b�y�kse ve max d��man say�s� 15'ten k���kse d��man say�s�n� artt�r
	if (dusmanarttirma >= 5 && maxDusman < 15)
	{
		maxDusman += 1; 
		dusmanarttirma = 0; 
	}// E�er d��man say�s� 5'ten b�y�kse ve max d��man say�s� 15'ten b�y�kse d��man say�s�n� artt�r ve d��man artt�rma h�z�n� s�f�rla
	else if (dusmanarttirma >= 5 && maxDusman >= 15)
	{
		DusmanCan++;
		dusmanarttirma = 0;
		maxDusman = 7;
	}
}

// Uygulama s�n�f�n�n yap�c� fonksiyonu
Uygulama::Uygulama()
{
}

// Uygulama s�n�f�n�n yap�c� fonksiyonu = Pencereyi olu�turur ve d��man�n boyutunu ve h�z�n� ayarlar
void Uygulama::insaEt(int genislik, int yukseklik)
{
	pencere.olustur(genislik, yukseklik); // Pencereyi olu�tur
	dusman.ayarla(yukseklik, genislik); // D��man�n boyutunu ve h�z�n� ayarla	
	// Olaylar� ekle ve ba�la
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

// Menude text olu�turmak i�in kullan�lacak fonksiyonlar
sf::Text Uygulama::createText(const std::string& text, const sf::Font& font, int size, const sf::Color& color, float x, float y)
{
	sf::Text createdText;
	createdText.setFont(font);
	createdText.setCharacterSize(size);
	createdText.setFillColor(color);
	createdText.setString(text);
	createdText.setPosition(x, y);
	return createdText;
}
// Menude buton olu�turmak i�in kullan�lacak fonksiyonlar
sf::RectangleShape Uygulama::createButton(float width, float height, const sf::Color& color, float x, float y)
{
	sf::RectangleShape button(sf::Vector2f(width, height));
	button.setFillColor(color);
	button.setPosition(x, y);
	return button;
}
// Buton t�klama kontrol fonksiyonu olayllar� ger�ekle�tirir
void Uygulama::tiklamaKontrol(sf::RectangleShape& buton, sf::Vector2f farePozisyonu, int olay)
{

	// "Tekrar Oyna" butonuna t�klama kontrol�, 1 olay� yeni oyun ba�latma i�lemi
	if (buton.getGlobalBounds().contains(farePozisyonu) &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left) && olay==1) {
		// Butona t�klan�rsa yeni bir oyun ba�lat
		pencere.pencerekapat();
		Uygulama yeniOyun;
		yeniOyun.insaEt(1280, 720);
		yeniOyun.baslat(60); // FPS'yi ge�mek istiyorsan�z bunu da parametre olarak ge�ebilirsiniz
	}
	// "Kapat" butonuna t�klama kontrol� 0 olay� kapatma i�lemi
	if (buton.getGlobalBounds().contains(farePozisyonu) &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left) && olay == 0) {
		// Uygulama kapans�n
		pencere.pencerekapat();
	}
}



// Buton ve skoru ekranda g�sterme fonksiyonu (Menu)
void Uygulama::ekrandaButonVeSkorGoster()
{
	// Fontu y�kleyeme ba�ar�l� olursa devam et
	sf::Font font;
	if (!font.loadFromFile("D:/SFML/font/arimo/ArimoBold.ttf")) {
		std::cerr << "Font y�klenemedi!" << std::endl;
		return;
	}

	// Skor metnini olu�turma
	sf::Text skorMetni = createText("Skor:   " + std::to_string(puan), font, 34, sf::Color::Black, 540, 215);

	// "Tekrar Oyna" butonunu olu�turma
	sf::RectangleShape buton = createButton(200, 50, sf::Color::Green, 540, 300);
	sf::Text butonYazisi = createText("Tekrar Oyna", font, 20, sf::Color::Black, 580, 315);

	// "Kapat" butonunu olu�turma
	sf::RectangleShape kapatButonu = createButton(200, 50, sf::Color::Red, 540, 370);
	sf::Text kapatButonYazisi = createText("Kapat", font, 20, sf::Color::Black, 610, 385);

	// Hover olay�n� kontrol et
	hoverKontrol(buton, fareGuncelKonum);
	hoverKontrol(kapatButonu, fareGuncelKonum);
	// Buton ve skoru ekranda �izme
	tiklamaKontrol(buton, fareGuncelKonum,1);
	tiklamaKontrol(kapatButonu, fareGuncelKonum,0);

	// Ekranda g�sterme
	pencere.temizle();
	pencere.ciz(skorMetni);  // Skoru ekranda g�ster
	pencere.ciz(buton);      // Butonu ekranda g�ster
	pencere.ciz(butonYazisi); // Buton yaz�s�n� ekranda g�ster
	pencere.ciz(kapatButonu); // Kapat butonunu ekranda g�ster
	pencere.ciz(kapatButonYazisi); // Kapat butonu yaz�s�n� ekranda g�ster
	
	pencere.goster();
}

// Uygulamay� ba�latma fonksiyonu
void Uygulama::baslat(int fps)
{
	float cerfps = 1.0f / fps;
	cerceveSuresi = sf::seconds(cerfps);

	gecenSure = saat.restart();


	karakter.yonAta(YON::Dur);
;
	while (pencere.pencereAcikmi())
	{
		
		pencere.olaylariisle();// Olaylar� i�le
		sf::Vector2i farePozisyonuGlobal = sf::Mouse::getPosition(pencere.getRenderWindow());  // Global fare pozisyonu
		fareGuncelKonum = pencere.getRenderWindow().mapPixelToCoords(farePozisyonuGlobal); // Global fare pozisyonunu pencereye g�re ayarla
		gecenSure = saat.getElapsedTime();// Zaman� ba�lat

		if (gecenSure >= cerceveSuresi)
		{
			// Oyun bitti mi kontrol et
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
				dusmanGuncelle();
				mermiguncelle(); // Mermi g�ncelleme
				canKontrol(); // Can kontrol�
				maxDusmanArttirma(); // D��man say�s�n� artt�rma
				gecenSure = sf::seconds(0.0f); // Zaman� s�f�rla
				saat.restart(); // Zaman� tekrar ba�lat
			}
		}
		else
		{
			sf::sleep(gecenSure - cerceveSuresi);// Oyunun FPS'ini ayarla
		}
	}
}
