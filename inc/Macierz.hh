#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"
#include<algorithm>
/*
 *  Jest to klasa macierz, opisuje 3 rzedy tablic jednowymiarowych.
 *  Wraz z klasa wektor posluzy do rozwiazywania rownan liniowych.
 */
class MacierzKw {
  Wektor Wiersz[ROZMIAR]; // 3 wektory skladajace sie na macierz, bedace wierszami owej macierzy
  public:
  MacierzKw(){ 
    for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
     Wiersz[i][j]=0; 
    }
  }
  }
  void transpozycja(); 
  void odwrotnosc(); 
  double wyznacznikSarrus();
  double wyznacznikLaplace();
  double wyznacznikGauss(); //za pomoca metody laplacea,gaussa,sarrusa
  MacierzKw operator + (const MacierzKw & M)const;
  MacierzKw operator - (const MacierzKw & M)const;
  MacierzKw operator * (const MacierzKw & M)const;
  MacierzKw operator * (double l)const;
  Wektor operator * (const Wektor & W)const;
  bool operator == (const MacierzKw & M) const;
  bool operator != (const MacierzKw & M) const;

  const Wektor & operator[] (int Wie) const;
  Wektor & operator[] (int Wie);

  const double & operator() (int Wie, int Kol) const;
  double & operator() (int Wie, int Kol);

 Wektor zwroc_kolumne(int ind)const; 
 void zmien_kolumne(int ind); 
};

/*
  *  Przeciazenie strumienia wejsciowego.Funkcja wczytuje podana wartosc od
  *  uzytkownika.
  * 
  *  Opis poszczegolnych parametrow wywolania funkcji:
  *   istream &strm  - odwolanie do sturmienia poprzez referencje,
  *   Macierz &Mac  - wartosc,ktora powinna zostac wczytana i zapisana
  *   w strukturze Macierz
  *   
  *   
  *  Warunki wstepne:
  *   strm musi byc strumieniem wejsciowym, by mozna bylo wczytac wartosci,
  *   podane watosci musza byc podane w odpowiedniej formie (tutaj za pomoca tablic)
  *
  *  Warunki koncowe:
  *   wszystko musi byc poprawnie wczytane, w przeciwnym wypadku strumien jest bledny
  *
  *  Funkcja wczytuje i zapisuje do tablic wartosci macierzy
  */

std::istream& operator >> (std::istream &strm, MacierzKw &Mac);

/*
  *  Przeciazenie strumienia wyjsciowego.Funkcja wyswietla dla uzytkownika
  *  podana wartosc.
  * 
  *  Opis poszczegolnych parametrow wywolania funkcji:
  *   ostream &strm  - odwolanie do sturmienia poprzez referencje,
  *   const Macierz &Mac  - wartosc,ktora powinna zostac wyswietlona,
  *   bez jej zmiany, w dodatku odwolujac sie do oryginalu
  *   
  *  Warunki wstepne:
  *   strm musi byc strumieniem wyjsciowym, by mozna bylo wyswietlic wartosci,
  *   watosci musza byc podane w odpowiedniej formie (tutaj za pomoca tablicy)
  *
  *  Warunki koncowe:
  *   brak
  *
  *  Funkcja wyswietla na wyjsciu standardowym wartosci macierzy.
  */
std::ostream& operator << (std::ostream &strm, const MacierzKw &Mac);


#endif
