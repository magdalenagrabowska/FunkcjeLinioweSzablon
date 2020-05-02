#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "SWektor.hh"
#include <string.h>
/*
 *  Jest to klasa macierz, opisuje rzedy SWymiar tablic jednowymiarowych.
 *  Wraz z klasa wektor posluzy do rozwiazywania rownan liniowych.
 */
template<typename STyp, int SWymiar>
class SMacierzKw{
  SWektor<STyp, SWymiar> Wiersz [SWymiar]; // 3 wektory skladajace sie na macierz, bedace wierszami owej macierzy
  public:
  SMacierzKw(){ 
    for(int i=0;i<SWymiar;i++){
     for(int j=0;j<SWymiar;j++){
     Wiersz[i][j]=0; 
    }
  }
  }
  void transpozycja(); 
  void odwrotnosc(); 
  STyp wyznacznikGauss()const; 
  /*SMacierzKw<STyp,SWymiar-1> minor(int i, int j)const;*/
  SMacierzKw<STyp, SWymiar> operator + (const SMacierzKw<STyp, SWymiar> & M)const;
  SMacierzKw<STyp, SWymiar> operator - (const SMacierzKw<STyp, SWymiar> & M)const;
  
  SMacierzKw<STyp, SWymiar> operator * (const SMacierzKw<STyp,SWymiar> & M)const;
  SMacierzKw<STyp, SWymiar>  operator * (double l)const;
  SWektor<STyp, SWymiar> operator * (const SWektor<STyp,SWymiar> & W)const;

  const SWektor<STyp, SWymiar> & operator[] (unsigned int Wie) const;
  SWektor<STyp, SWymiar> & operator[] (unsigned int Wie);

  const STyp & operator() (unsigned int Wie, unsigned int Kol) const;
  STyp & operator() (unsigned int Wie,unsigned int Kol);

 SWektor<STyp, SWymiar> zwroc_kolumne(int ind)const; 
 void zmien_kolumne(SWektor<STyp,SWymiar> W, int i); 
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
template<typename STyp, int SWymiar>
std::istream& operator>>(std::istream &strm, SMacierzKw<STyp, SWymiar> &Mac);

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
template<typename STyp, int SWymiar>
std::ostream& operator<<(std::ostream &strm, const SMacierzKw<STyp, SWymiar> &Mac);


#endif
