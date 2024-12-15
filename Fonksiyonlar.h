#pragma once
#include <functional>
#include <vector>
#include <SFML/Window/Event.hpp>
using namespace std;
using namespace sf;

typedef function<void(Keyboard::Key)> KlavyeFonksiyonu;
typedef vector<KlavyeFonksiyonu> KlavyeFonksiyonlari;

typedef function<void(Event::MouseMoveEvent)> FareHareketFonk;
typedef vector<FareHareketFonk> FareHareketFonklari;

typedef function<void(Event::MouseButtonEvent)> FareTiklamaFonk;
typedef vector<FareTiklamaFonk> FareTiklamaFonklari;