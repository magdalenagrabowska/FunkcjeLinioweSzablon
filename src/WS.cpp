#include "SWektor.cpp"
#include"LZespolona.cpp"
#include "SMacierz.cpp"
#include "SUkladRownanLiniowych.cpp"
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

template class SMacierzKw<double,ROZMIAR>;
template istream & operator>>(istream & strm, SMacierzKw<double,ROZMIAR> &Mac);
template ostream & operator<<(ostream & strm,const SMacierzKw<double,ROZMIAR> &Mac);
template class SMacierzKw<LZespolona,ROZMIAR>;
template istream & operator>> (istream & strm, SMacierzKw<LZespolona,ROZMIAR>&Mac);
template ostream & operator<< (ostream & strm,const SMacierzKw<LZespolona,ROZMIAR>&Mac);

template class SUkladRownanL<double,ROZMIAR>;
template istream & operator>>(istream & strm, SUkladRownanL<double,ROZMIAR> &UklRown);
template ostream & operator<<(ostream & strm,const SUkladRownanL<double,ROZMIAR> &UklRown);
template class SUkladRownanL<LZespolona,ROZMIAR>;
template istream & operator>>(istream & strm, SUkladRownanL<LZespolona,ROZMIAR> &UklRown);
template ostream & operator<<(ostream & strm,const SUkladRownanL<LZespolona,ROZMIAR> &UklRown);