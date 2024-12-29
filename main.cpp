#include<iostream>
#include<string>
#include "Uygulama.hpp"
using namespace std;

int main()
{
	try
	{
		Uygulama uygulama;
		uygulama.insaEt(1280, 720);
		uygulama.baslat();
	}
	catch (const std::exception& err)
	{
		cout << "Hata olustu" << endl;
		cout << "HATA: " << err.what() << endl;
	}
	return 0;

}