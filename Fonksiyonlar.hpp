#pragma once
#include <functional>
#include <vector>
#include <SFML/Window/Event.hpp>
using namespace std;
using namespace sf;
// Klavye fonksiyonlar� i�in kullan�lacak fonksiyonlar
typedef function<void(Keyboard::Key)> KlavyeFonksiyonu;
typedef vector<KlavyeFonksiyonu> KlavyeFonksiyonlari;

// Fare hareket fonksiyonlar� i�in kullan�lacak fonksiyonlar
typedef function<void(Event::MouseMoveEvent)> FareHareketFonk;
typedef vector<FareHareketFonk> FareHareketFonklari;

// Fare t�klama fonksiyonlar� i�in kullan�lacak fonksiyonlar
typedef function<void(Event::MouseButtonEvent)> FareTiklamaFonk;
typedef vector<FareTiklamaFonk> FareTiklamaFonklari;