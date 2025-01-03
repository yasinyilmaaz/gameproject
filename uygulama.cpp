#include "uygulama.hpp"
#include <iostream>

// Oyunun çerçevesini oluþturur ve karakteri çizer ve düþmanlarý çizer ve mermileri çizer ve ekrana gösterir
void Uygulama::cerceveOlustur()
{
	sahneGuncelle();
	cizimFonksiyonu();
}


// ekraný temizler ve karakteri çizer ve düþmanlarý çizer ve mermileri çizer ve ekrana gösterir
void Uygulama::cizimFonksiyonu()
{
	pencere.temizle();
	karakter.ciz(pencere);
	dusmanciz();
	mermiciz();
	pencere.goster();
}

// karakterin hareketini saðlar
void Uygulama::sahneGuncelle()
{
	karakter.hareket();
}

// tuþa basýldýðýnda karakterin hareketini saðlar
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


// Tuþ býrakýldýðýnda karakterin durmasýný saðlar
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
	fareGuncelKonum = Vector2f(olay.x, olay.y); // Fare pozisyonunu günceller 
}


// Fare týklandýðýnda mermi üretir ve mermi hýzýný sýfýrlar
void Uygulama::fareTiklandi(sf::Event::MouseButtonEvent olay)
{
	if (mermihazir)
	{
		fareTiklanmaKonum = fareGuncelKonum;
		mermiuret();
		mermiuretmehizi = 0.f;
	}
}

// Karakterin düþmanlara çarpmasýný kontrol eder ve canýný azaltýr
void Uygulama::karakterhasar()
{
	FloatRect k1box = karakter.getk1().getGlobalBounds();
	FloatRect k2box = karakter.getk2().getGlobalBounds();
	FloatRect k3box = karakter.getk3().getGlobalBounds();
	FloatRect k4box = karakter.getk4().getGlobalBounds();

	// Düþmanlarla çarpýþma kontrolü ve düþmanlara çarptýðýnda karakterin canýný azaltma
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
			// Eðer karakter düþmana çarparsa canýný azalt puan eksilt
			Can--;
			puan = puan - 20;
			
		}
	}
}

// Düþman üretme fonksiyonu = düþman üretir ve düþman üretme hýzýný sýfýrlar 
void Uygulama::dusmanuret()
{
	dusman.Canata(DusmanCan);
	dusman.dusmanUret();
	dusmanlar.push_back(dusman);
}

// Düþmanlarý çizme fonksiyonu = düþmanlarý ekrana çizdirir 
void Uygulama::dusmanciz()
{
	for (auto& d : dusmanlar) {
		d.ciz(pencere);
	}
}

// Düþman güncelleme fonksiyonu = düþman üretme, düþman hareket ve düþman çarpýþmalarýný kontrol etme iþlemlerini yapar
void Uygulama::dusmanGuncelle()
{
	dusmanEkle();
	dusmanlariHareketEttir();
	dusmanCarpismalariniKontrolEt();
}

// Düþman üretme fonksiyonu = düþman üretir ve düþman üretme hýzýný sýfýrlar
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

// Düþmanlarýn karaktere doðru hareket etmesini saðlar
void Uygulama::dusmanlariHareketEttir()
{
	for (auto& dusman : dusmanlar)
	{
		dusman.hareket(karakter.guncelkonum());
	}
}

// Düþmanlarýn birbirine ve mermilere çarpýþmasýný kontrol eder
void Uygulama::dusmanCarpismalariniKontrolEt()
{
	for (size_t i = 0; i < dusmanlar.size(); ++i)
	{
		dusmanMermiCarpismaKontrol(i);
		dusmanDusmanCarpismaKontrol(i);
	}
}

// Düþmanlarýn mermilerle çarpýþmasýný kontrol eder
void Uygulama::dusmanMermiCarpismaKontrol(size_t dusmanIndex)
{
	for (size_t j = 0; j < mermiler.size(); ++j)
	{
		// Eðer mermi ve düþman çarpýþýrsa mermiyi ve düþmaný sil ve puaný arttýr
		if (dusmanlar[dusmanIndex].getsekil().getGlobalBounds().intersects(mermiler[j].getsekil().getGlobalBounds()))
		{
			puan += 10;

			mermiler.erase(mermiler.begin() + j); // Mermiyi sil
			dusmanlar[dusmanIndex].Canata(dusmanlar[dusmanIndex].Cangetir() - 1); // Düþmanýn canýný azalt

			// Eðer düþmanýn caný 0'dan küçükse düþmaný sil
			if (dusmanlar[dusmanIndex].Cangetir() < 1)
			{
				dusmanlar.erase(dusmanlar.begin() + dusmanIndex); // Düþmaný sil
				YokEdilenD++;
				dusmanarttirma++;

				// eðer 3 düþman yok edilirse caný 1 arttýr
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

// Düþmanlarýn birbirine çarpýþmasýný kontrol eder
void Uygulama::dusmanDusmanCarpismaKontrol(size_t dusmanIndex)
{
	auto& dusman = dusmanlar[dusmanIndex];
	// Düþmanýn kenarlarýný al ve diðer düþmanlarla çarpýþmasýný kontrol et
	FloatRect k1box = dusman.getk1().getGlobalBounds();
	FloatRect k2box = dusman.getk2().getGlobalBounds();
	FloatRect k3box = dusman.getk3().getGlobalBounds();
	FloatRect k4box = dusman.getk4().getGlobalBounds();

	for (auto& digerDusman : dusmanlar)
	{
		// Eðer düþmanlar birbirine çarparsa düþmanlarý it
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

// Mermi üretme fonksiyonu = mermi üretir
void Uygulama::mermiuret()
{
	mermi.mermikonum(karakter.guncelkonum() + Vector2f(14, 14));
	mermi.setbitiskonum(fareTiklanmaKonum);
	mermi.setdusmanyol();
	mermiler.push_back(mermi);
}

//  Mermileri çizme fonksiyonu = mermileri ekrana çizdirir
void Uygulama::mermiciz()
{
	for (auto& m : mermiler) {
		m.ciz(pencere);// Mermiyi çiz
	}
}


// Mermi güncelleme fonksiyonu = mermi hareket, mermi kontrol ve mermi silme iþlemlerini yapar
void Uygulama::mermiguncelle()
{
	if (mermiuretmehizi >= mermiuretmehiziMax)
	{
		// Eðer mermi hazýrsa mermi üretme hýzýný sýfýrla
		mermihazir = true;
	}
	else
	{
		// Eðer mermi hazýr deðilse mermi üretme hýzýný arttýr
		mermihazir = false;
		mermiuretmehizi += 1.f;
	}
	for (int i = 0; i < mermiler.size(); i++)
	{
		mermiler[i].mermiHareket(mermiler[i].getbitiskonum()); // Mermi hareket ettir 
		mermiler[i].mermikontrol();// Mermi kontrolü yap
		if (mermiler[i].getmermiharitakonum()) // Eðer mermi harita dýþýna çýkarsa mermiyi sil
		{
			mermiler.erase(mermiler.begin() + i); // Mermiyi sil
		}

	}
}


// Can kontrol fonksiyonu. Can azaldýkça karakterin rengini deðiþtirir
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

// Düþman sayýsýna göre düþman sayýsýný ve canýný arttýrýr
void Uygulama::maxDusmanArttirma()
{
	// Eðer düþman sayýsý 5'ten büyükse ve max düþman sayýsý 15'ten küçükse düþman sayýsýný arttýr
	if (dusmanarttirma >= 5 && maxDusman < 15)
	{
		maxDusman += 1; 
		dusmanarttirma = 0; 
	}// Eðer düþman sayýsý 5'ten büyükse ve max düþman sayýsý 15'ten büyükse düþman sayýsýný arttýr ve düþman arttýrma hýzýný sýfýrla
	else if (dusmanarttirma >= 5 && maxDusman >= 15)
	{
		DusmanCan++;
		dusmanarttirma = 0;
		maxDusman = 7;
	}
}

// Uygulama sýnýfýnýn yapýcý fonksiyonu
Uygulama::Uygulama()
{
}

// Uygulama sýnýfýnýn yapýcý fonksiyonu = Pencereyi oluþturur ve düþmanýn boyutunu ve hýzýný ayarlar
void Uygulama::insaEt(int genislik, int yukseklik)
{
	pencere.olustur(genislik, yukseklik); // Pencereyi oluþtur
	dusman.ayarla(yukseklik, genislik); // Düþmanýn boyutunu ve hýzýný ayarla	
	// Olaylarý ekle ve baðla
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
		// Fare butonun üzerine gelirse, butonun rengini deðiþtir
		buton.setFillColor(sf::Color::Yellow);  // Örneðin, hover olunca sarý yapalým
	}
	else {
		// Fare butonun üzerinden ayrýldýðýnda, eski rengine geri dön
		buton.setFillColor(sf::Color::Green);  // Normalde yeþil
	}
}

// Menude text oluþturmak için kullanýlacak fonksiyonlar
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
// Menude buton oluþturmak için kullanýlacak fonksiyonlar
sf::RectangleShape Uygulama::createButton(float width, float height, const sf::Color& color, float x, float y)
{
	sf::RectangleShape button(sf::Vector2f(width, height));
	button.setFillColor(color);
	button.setPosition(x, y);
	return button;
}
// Buton týklama kontrol fonksiyonu olayllarý gerçekleþtirir
void Uygulama::tiklamaKontrol(sf::RectangleShape& buton, sf::Vector2f farePozisyonu, int olay)
{

	// "Tekrar Oyna" butonuna týklama kontrolü, 1 olayý yeni oyun baþlatma iþlemi
	if (buton.getGlobalBounds().contains(farePozisyonu) &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left) && olay==1) {
		// Butona týklanýrsa yeni bir oyun baþlat
		pencere.pencerekapat();
		Uygulama yeniOyun;
		yeniOyun.insaEt(1280, 720);
		yeniOyun.baslat(60); // FPS'yi geçmek istiyorsanýz bunu da parametre olarak geçebilirsiniz
	}
	// "Kapat" butonuna týklama kontrolü 0 olayý kapatma iþlemi
	if (buton.getGlobalBounds().contains(farePozisyonu) &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left) && olay == 0) {
		// Uygulama kapansýn
		pencere.pencerekapat();
	}
}



// Buton ve skoru ekranda gösterme fonksiyonu (Menu)
void Uygulama::ekrandaButonVeSkorGoster()
{
	// Fontu yükleyeme baþarýlý olursa devam et
	sf::Font font;
	if (!font.loadFromFile("D:/SFML/font/arimo/ArimoBold.ttf")) {
		std::cerr << "Font yüklenemedi!" << std::endl;
		return;
	}

	// Skor metnini oluþturma
	sf::Text skorMetni = createText("Skor:   " + std::to_string(puan), font, 34, sf::Color::Black, 540, 215);

	// "Tekrar Oyna" butonunu oluþturma
	sf::RectangleShape buton = createButton(200, 50, sf::Color::Green, 540, 300);
	sf::Text butonYazisi = createText("Tekrar Oyna", font, 20, sf::Color::Black, 580, 315);

	// "Kapat" butonunu oluþturma
	sf::RectangleShape kapatButonu = createButton(200, 50, sf::Color::Red, 540, 370);
	sf::Text kapatButonYazisi = createText("Kapat", font, 20, sf::Color::Black, 610, 385);

	// Hover olayýný kontrol et
	hoverKontrol(buton, fareGuncelKonum);
	hoverKontrol(kapatButonu, fareGuncelKonum);
	// Buton ve skoru ekranda çizme
	tiklamaKontrol(buton, fareGuncelKonum,1);
	tiklamaKontrol(kapatButonu, fareGuncelKonum,0);

	// Ekranda gösterme
	pencere.temizle();
	pencere.ciz(skorMetni);  // Skoru ekranda göster
	pencere.ciz(buton);      // Butonu ekranda göster
	pencere.ciz(butonYazisi); // Buton yazýsýný ekranda göster
	pencere.ciz(kapatButonu); // Kapat butonunu ekranda göster
	pencere.ciz(kapatButonYazisi); // Kapat butonu yazýsýný ekranda göster
	
	pencere.goster();
}

// Uygulamayý baþlatma fonksiyonu
void Uygulama::baslat(int fps)
{
	float cerfps = 1.0f / fps;
	cerceveSuresi = sf::seconds(cerfps);

	gecenSure = saat.restart();


	karakter.yonAta(YON::Dur);
;
	while (pencere.pencereAcikmi())
	{
		
		pencere.olaylariisle();// Olaylarý iþle
		sf::Vector2i farePozisyonuGlobal = sf::Mouse::getPosition(pencere.getRenderWindow());  // Global fare pozisyonu
		fareGuncelKonum = pencere.getRenderWindow().mapPixelToCoords(farePozisyonuGlobal); // Global fare pozisyonunu pencereye göre ayarla
		gecenSure = saat.getElapsedTime();// Zamaný baþlat

		if (gecenSure >= cerceveSuresi)
		{
			// Oyun bitti mi kontrol et
			if(Can <= 0) {
				
				ekrandaButonVeSkorGoster();
				// Týklama olayýný kontrol et
				
				gecenSure = sf::seconds(0.0f);
				saat.restart();
			}
			else {
				cerceveOlustur();
				karakter.karakterKontrol();
				karakterhasar();
				dusmanGuncelle();
				mermiguncelle(); // Mermi güncelleme
				canKontrol(); // Can kontrolü
				maxDusmanArttirma(); // Düþman sayýsýný arttýrma
				gecenSure = sf::seconds(0.0f); // Zamaný sýfýrla
				saat.restart(); // Zamaný tekrar baþlat
			}
		}
		else
		{
			sf::sleep(gecenSure - cerceveSuresi);// Oyunun FPS'ini ayarla
		}
	}
}
