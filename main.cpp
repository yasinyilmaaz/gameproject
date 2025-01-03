#include<iostream>
#include<string>
#include "Uygulama.hpp"
using namespace std;

/*
	* Ana fonksiyon
	 Uygulama sýnýfý oluþturulur ve insaEt fonksiyonu çaðrýlýr.
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