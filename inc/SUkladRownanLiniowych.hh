#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "SMacierz.hh"
#include "SWektor.hh"
/*
 * jest to klasa uklad rownan i sklada sie z macierzy oraz wyrazow wolnych.
 * Rozwiazuje dane uklady rownan, w tym zadaniu korzystajac z macierzy o wymiarach podanych w pliku ROZMIAR i wetora o ROZMiAR wyrazach.
 */
template<typename STyp, int SWymiar>
class SUkladRownanL {
  SMacierzKw<STyp,SWymiar> A;
  SWektor<STyp,SWymiar> b;
  public:
 SUkladRownanL(){};
 SUkladRownanL(SMacierzKw<STyp,SWymiar> _A, SWektor<STyp,SWymiar> _b): A(_A), b(_b){};
 const SMacierzKw<STyp,SWymiar> & get_A()const;
 const SWektor<STyp,SWymiar> &get_b() const; 
 void set_A(const SMacierzKw<STyp,SWymiar> & in);
 void set_b(const SWektor<STyp,SWymiar> & in);
 SWektor<STyp,SWymiar> operator * (const SWektor<STyp,SWymiar> & W)const;
 SWektor<STyp,SWymiar> Oblicz() const; 
 SWektor<STyp,SWymiar> wb()const; //obliczenie dlugosci wektora bledu
};


/*
 * Jest to przeciązenie operatora wczytywania. Powinien wczytywać wartosci potrzebnych do rozwiazania
 * ukladow rownan w formie macierzy rozszerzonej o wyrazy wolne.
 * Wczytuje macierz i wektor w tym wypadku podane w pliku
 */
template<typename STyp, int SWymiar>
std::istream& operator >> (std::istream &strm, SUkladRownanL<STyp,SWymiar> &UklRown);

/*
 * Przeciazenie strumienia wyjsciowego.Funkcja wyswietla dla uzytkownika
*  podana wartosc.
* 
*  Opis poszczegolnych parametrow wywolania funkcji:
*   ostream &strm  - odwolanie do sturmienia poprzez referencje,
*    const UkladRownanL  &UklRown - wartosc,ktora powinna zostac wyswietlona,
*   bez jej zmiany, w dodatku odwolujac sie do oryginalu
*   
*  Warunki wstepne:
*   strm musi byc strumieniem wyjsciowym, by mozna bylo wyswietlic wartosci,
*   watosci musza byc podane w odpowiedniej formie 
*
*  Warunki koncowe:
*   brak
*
*  Funkcja wyswietla na wyjsciu standardowym wartosci ukladu rownan.
 */
template<typename STyp, int SWymiar>
std::ostream& operator << ( std::ostream &strm,const SUkladRownanL<STyp,SWymiar>  &UklRown);


#endif
