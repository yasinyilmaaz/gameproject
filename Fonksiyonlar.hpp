#pragma once
#include <functional>
#include <vector>
#include <SFML/Window/Event.hpp>
using namespace std;
using namespace sf;
// Klavye fonksiyonlarý için kullanýlacak fonksiyonlar
typedef function<void(Keyboard::Key)> KlavyeFonksiyonu;
typedef vector<KlavyeFonksiyonu> KlavyeFonksiyonlari;

// Fare hareket fonksiyonlarý için kullanýlacak fonksiyonlar
typedef function<void(Event::MouseMoveEvent)> FareHareketFonk;
typedef vector<FareHareketFonk> FareHareketFonklari;

// Fare týklama fonksiyonlarý için kullanýlacak fonksiyonlar
typedef function<void(Event::MouseButtonEvent)> FareTiklamaFonk;
typedef vector<FareTiklamaFonk> FareTiklamaFonklari;