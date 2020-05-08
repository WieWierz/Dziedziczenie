#include <iostream>
#include <fstream>
using namespace std;

class miasto{
	public:
		string nazwa,liczba_ludnosci, powierzchnia;
		ifstream plik1;
		ofstream plik2;
		void wczytaj();
		void zapisz();
};

void miasto::wczytaj(){
	plik1.open("wej1.txt");
	getline(plik1,nazwa);
	getline(plik1,liczba_ludnosci);
	getline(plik1,powierzchnia);	
}

void miasto::zapisz(){
	plik2.open("wej3.txt");
	plik2<<"[";
	plik2<<"{\"nazwa\":\""<<nazwa<<"\",\"zaludnienie\":\""<<liczba_ludnosci<<"\",\"powierzchnia\":\""<<powierzchnia<<"\",";
}

class stolica:public miasto
{
	public:
		string stolica_jakiego_panstwa;
		
		void wczytaj();
		void zapisz();
};

void stolica::wczytaj(){
	miasto::wczytaj();
	getline(plik1,stolica_jakiego_panstwa);
	plik1.close();
}

void stolica::zapisz(){
	miasto::zapisz();
	plik2<<"\"stolica panstwa\":\""<<stolica_jakiego_panstwa<<"\"}";
	plik2<<"]";
	plik2.close();
}
int main(int argc, char** argv) {
	stolica s;
	s.wczytaj();
	s.zapisz();
	return 0;
}
