#include <iostream>
#include <fstream>

using namespace std;

class osoba
{
	
	public:
		
		string imie,nazwisko;
	int pesel;
		void wczytaj();
};

void osoba::wczytaj()
{
	cout<<"Podaj imie, nazwisko i pesel nauczyciela:";
			cin>>imie>>nazwisko>>pesel;
}

class nauczyciel:public osoba
{
	public:
	string przedmiot;
	
	void wprowadz_nauczyciela()
	
	{
		wczytaj();
		
		cout<<"Podaj przedmiot nauczyciela:";
		cin>>przedmiot;
	}
	
	void zapiszDoPliku()
	{
		ofstream plik2;
		plik2.open("dane2.txt");
		
		plik2<<"Nauczyciel:"<<endl;
		plik2<<"[";
		plik2<<"{\"imie:\":\""<<imie<<",\"nazwisko\":\""<<nazwisko<<"\",\"pesel\":\""<<pesel<<"\",\"przedmiot\":\""<<przedmiot<<"\"}";
		plik2<<"]"<<endl;
	}
};



class uczen:public osoba
{
	public:
		
	double srednia;
	string klasa;
	int k=0;
	
	ifstream plik1;
	
		void wczytajZPliku()
		{
			plik1.open("dane.txt");
			
			while(!plik1.eof())
				{
					plik1>>imie;
					plik1>>nazwisko;
					plik1>>pesel;
					plik1>>klasa;
					plik1>>srednia;
					k++;
		
				}
			plik1.close();
		}
		
		void wypisz()
		{
			for (int i=0;i<k;i++)
				{
					cout<<"Uczen:";
					cout<<"[";
					cout<<"{\"imie:\":\""<<imie<<",\"nazwisko\":\""<<nazwisko<<"\",\"pesel\":\""<<pesel<<"\",\"klasa\":\""<<klasa<<"\",\"srednia\":\""<<srednia<<"\"}";
					cout<<"]"<<endl;
				}
		}
		
};

int main(int argc, char** argv) {
	
	nauczyciel n;
	uczen u;
 	n.wprowadz_nauczyciela();
	n.zapiszDoPliku();
	u.wczytajZPliku();
	u.wypisz();
	return 0;
}
