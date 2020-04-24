#include "SWektor.cpp"
#include"LZespolona.cpp"

using namespace std;

template class SWektor<double,5>;
template istream & operator>> (istream & strm, SWektor<double,5>&Wek);
template ostream & operator<< (ostream & strm,const SWektor<double,5>&Wek);
template SWektor<double, 5> operator * (double l1, SWektor<double,5> W2);
template class SWektor<LZespolona,5>;
template istream & operator>> (istream & strm, SWektor<LZespolona,5>&Wek);
template ostream & operator<< (ostream & strm,const SWektor<LZespolona,5>&Wek);
template SWektor<LZespolona, 5> operator * (double l1, SWektor<LZespolona,5> W2);
