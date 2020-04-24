#include "SWektor.cpp"
#include"LZespolona.cpp"
#include "rozmiar.h"
using namespace std;

template class SWektor<double,ROZMIAR>;
template istream & operator>> (istream & strm, SWektor<double,ROZMIAR>&Wek);
template ostream & operator<< (ostream & strm,const SWektor<double,ROZMIAR>&Wek);
template SWektor<double, ROZMIAR> operator * (double l1, SWektor<double,ROZMIAR> W2);
template class SWektor<LZespolona,ROZMIAR>;
template istream & operator>> (istream & strm, SWektor<LZespolona,ROZMIAR>&Wek);
template ostream & operator<< (ostream & strm,const SWektor<LZespolona,ROZMIAR>&Wek);
template SWektor<LZespolona, ROZMIAR> operator * (double l1, SWektor<LZespolona,ROZMIAR> W2);
