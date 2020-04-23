#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <string.h>
#include<cmath>
/*
 *  Ta klasa opisuje wektor.
 *  Wektor jest rozmiarow tablicy 1xwartosc zdefiniowana ROZMIAR.
 *  Moze byc uzyty przy wyrazach wolnych albo przy niewiadomych.
 *  
 */
template<typename STyp, int ROZMIAR>
class SWektor {
  STyp _tab[ROZMIAR];
  public:
  SWektor(){for(STyp &tab: _tab) tab=0; }
  SWektor<STyp, ROZMIAR> operator + (const SWektor<STyp, ROZMIAR> & W2) const;
  SWektor<STyp, ROZMIAR>  operator - (const SWektor<STyp, ROZMIAR>  & W2) const;
 
  STyp operator * (const SWektor<STyp, ROZMIAR>  & W2) const;

  SWektor<STyp, ROZMIAR>  operator * (double li) const;

  bool operator == (const SWektor<STyp, ROZMIAR>  & W2) const;
  bool operator != (const SWektor<STyp, ROZMIAR>  & W2) const;

  STyp dlugosc() const;   
   
  const STyp & operator[] (unsigned int index) const; 
  STyp & operator[] (unsigned int index);
  
};


/*
  *  Przeciazenie strumienia wejsciowego.Funkcja wczytuje podana wartosc od
  *  uzytkownika.
  * 
  *  Opis poszczegolnych parametrow wywolania funkcji:
  *   istream &strm  - odwolanie do sturmienia poprzez referencje,
  *   Wektor &Wek  - wartosc,ktora powinna zostac wczytana i zapisana
  *   w strukturze Wektor
  *   
  *   
  *  Warunki wstepne:
  *   strm musi byc strumieniem wejsciowym, by mozna bylo wczytac wartosci,
  *   podane watosci musza byc podane w odpowiedniej formie (tutaj za pomoca tablicy)
  *
  *  Warunki koncowe:
  *   wszystko musi byc poprawnie wczytane, w przeciwnym wypadku strumien jest bledny
  *
  *  Funkcja wczytuje do klasy wektor podane wartosci
  */
 template<typename STyp, int ROZMIAR>
 std::istream& operator >> (std::istream &Strm, SWektor<STyp, ROZMIAR>  &Wek);

/*
  *  Przeciazenie strumienia wyjsciowego.Funkcja wyswietla dla uzytkownika
  *  podana wartosc.
  * 
  *  Opis poszczegolnych parametrow wywolania funkcji:
  *   ostream &strm  - odwolanie do sturmienia poprzez referencje,
  *   const Wektor &Wek  - wartosc,ktora powinna zostac wyswietlona,
  *   bez jej zmiany, w dodatku odwolujac sie do oryginalu
  *   
  *  Warunki wstepne:
  *   strm musi byc strumieniem wyjsciowym, by mozna bylo wyswietlic wartosci,
  *   watosci musza byc podane w odpowiedniej formie (tutaj za pomoca tablicy)
  *
  *  Warunki koncowe:
  *   brak
  *
  *  Funkcja wyswietla na wyjsciu standardowym wartosci wektora.
  */
template<typename STyp, int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const  SWektor<STyp, ROZMIAR> &Wek);

template<typename STyp, int ROZMIAR>
SWektor<STyp,ROZMIAR>  operator * (double l1, SWektor<STyp, ROZMIAR> W2);
#endif
