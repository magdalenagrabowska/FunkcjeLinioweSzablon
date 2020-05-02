#include "LZespolona.hh"
#include<iostream>
#include<iomanip>
using std::cout;
using std::endl;
using std::cin;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona &LZespolona::operator=(double liczba){
  if(liczba==1){
    this->re=liczba;
    this->im=1;
  }
else{
this->re=liczba;
this->im=0;
}
return *this;
}
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik(0);

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
LZespolona LZespolona::operator +=(const LZespolona &Skl1){
  this->re=this->re+Skl1.re;
  this->im=this->im+Skl1.im;
  return *this;
}
LZespolona LZespolona::operator *=(const LZespolona &Skl1){
  this->re=this->re*Skl1.re;
  this->im=this->im*Skl1.im;
  return *this;
}
LZespolona operator - (LZespolona Skl1,LZespolona Skl2){
  LZespolona Wynik(0);
  Wynik.re=Skl1.re-Skl2.re;
  Wynik.im=Skl1.im-Skl2.im;
  return Wynik;
}
LZespolona LZespolona::operator -(){
  this->re=-this->re;
  this->im=-this->im;
  return *this;
}
LZespolona operator * (LZespolona Skl1, LZespolona Skl2){
  LZespolona Wynik(0);
  Wynik.re=(Skl1.re*Skl2.re)-(Skl1.im*Skl2.im);
  Wynik.im=(Skl1.re*Skl2.im)+(Skl1.im*Skl2.re);
  return Wynik;
}
LZespolona operator * (LZespolona Skl1, double liczba ){
  LZespolona Wynik(0);
  Wynik.re=Skl1.re*liczba;
  Wynik.im=Skl1.im*liczba;
  return Wynik;
}
LZespolona operator / (LZespolona  Skl1, LZespolona  Skl2){
  LZespolona Wynik;
  LZespolona Sprzez;
  Sprzez = sprzezenie(Skl2);
  Wynik.re = (Skl1.re * Sprzez.re - (-1) * Skl1.im * Sprzez.im)/modulKw(Skl2);
  Wynik.im = (Skl1.re * Sprzez.im + Skl1.im * Sprzez.re)/modulKw(Skl2);
  return Wynik;
  
}
LZespolona sprzezenie (LZespolona  Skl){
  LZespolona Sprzez;
  Sprzez.re = Skl.re;
  Sprzez.im = (-1)*Skl.im;
  return Sprzez;
}
double modulKw (LZespolona Skl){
  double Wynik;
  Wynik = Skl.re * Skl.re + Skl.im * Skl.im;
  return Wynik;
}

LZespolona  operator / (LZespolona  Dzielna, double  Dzielnik_Liczba){
    LZespolona Wynik;
    Wynik.re = Dzielna.re / Dzielnik_Liczba;
    Wynik.im = Dzielna.im / Dzielnik_Liczba;
    return Wynik;
}
bool operator ==(LZespolona Skl1,LZespolona Skl2){
if((Skl1.re==Skl2.re)&&(Skl1.im==Skl2.im))
return true;
else return false;
}

bool operator !=(LZespolona Skl1, LZespolona Skl2){
  if (Skl1==Skl2)
  return false;
  else return true;
} 
std::ostream & operator<< (std::ostream &strm, const LZespolona &Z1){
  
 strm<<"("<<Z1.re<<std::showpos<<Z1.im<<std::noshowpos<<"i)";
 return strm;
}

std::istream & operator>> (std::istream &strm, LZespolona &Z1){
  char znak;
 strm>>znak;
  if(znak!='(')
    strm.setstate(std::ios::failbit);
 strm>>Z1.re;
 strm>>znak;
 strm>>Z1.im;
 if(znak=='-')
    Z1.im=(-Z1.im);
 strm>>znak;
  if(znak!='i')
    strm.setstate(std::ios::failbit);
 strm>>znak;
  if(znak!=')')
    strm.setstate(std::ios::failbit);
  return strm;
}
