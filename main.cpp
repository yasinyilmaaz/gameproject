#include<iostream>
#include<string>
#include "Uygulama.hpp"
using namespace std;

/*
	* Ana fonksiyon
	 Uygulama s�n�f� olu�turulur ve insaEt fonksiyonu �a�r�l�r.
*/

int main(){
	try {
		Uygulama uygulama;
		uygulama.insaEt(1280, 720);
		uygulama.baslat();
	}	
	catch (const char* hata)
	{
		cout << hata << endl;
	}
}