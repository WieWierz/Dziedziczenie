#include <iostream>
#include <fstream>
using namespace std;

class miasto{
	public:
		string nazwa,liczba_ludnosci, powierzchnia;
		ifstream plik1;
		void wczytaj();
};

void miasto::wczytaj(){
	plik1.open("wej1.txt");
	getline(plik1,nazwa);
	getline(plik1,liczba_ludnosci);
	getline(plik1,powierzchnia);	
}

class stolica:public miasto
{
	public:
		string stolica_jakiego_panstwa;
		ofstream plik2;
	
		void wczytajs();
		void zapisz();
};

void stolica::wczytajs(){
	wczytaj();
	getline(plik1,stolica_jakiego_panstwa);
	plik1.close();
}

void stolica::zapisz(){
	plik2.open("wej2.txt");
	plik2<<"[";
	plik2<<"{\"nazwa\":\""<<nazwa<<"\",\"zaludnienie\":\""<<liczba_ludnosci<<"\",\"powierzchnia\":\""<<powierzchnia<<"\",\"stolica panstwa\":\""<<stolica_jakiego_panstwa<<"\"}";
	plik2<<"]";
	plik2.close();
}
int main(int argc, char** argv) {
	stolica s;
	s.wczytajs();
	s.zapisz();
	return 0;
}
