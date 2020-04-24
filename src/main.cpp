#include <iostream>
#include "SWektor.hh"
#include "LZespolona.hh"
# include "rozmiar.h"

using namespace std;

void Test_SzablonWektor_double()
{
  cout << endl
       << " --------- Test klasy Wektor<double," << ROZMIAR << "> ----------" << endl
       << endl;

  SWektor<double,ROZMIAR> W,W2, W_wynik;
  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W2[Ind] = Ind+2;
  }

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind] = Ind;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;

  W_wynik = W*2;
  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W_wynik << endl
       << endl;
  
  W_wynik = W*3-W;
  cout << "  Wyswietlenie wyniku  W*3-W" << endl
       << "        " << W_wynik << endl
       << endl; 
  W_wynik = W*4.5+W;
  cout << "  Wyswietlenie wyniku W*4.5+W" << endl
       << "        " << W_wynik << endl
       << endl; 
  
  double mnozenie=W*W2;
  cout << "  Wyswietlenie mnozenia" << endl
       << "        " <<mnozenie<< endl
       << endl; 

}




 void Test_SzablonWektor_LZespolona()
{
  cout << endl
       << " --------- Test klasy Wektor<LZespolona," << ROZMIAR << "> ----------" << endl
       << endl;


  SWektor<LZespolona,ROZMIAR> W,W2,W_wynik;
  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind].re = Ind;      W[Ind].im = Ind;
  }
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W2[Ind].re = Ind+6;      W2[Ind].im = Ind+4;
  }
  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;

  W_wynik = W*2;
  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W_wynik << endl
       << endl;
  
  W_wynik = W+W2;
  cout << "  Wyswietlenie wyniku: W+W2" << endl
       << "        " << W_wynik << endl
       << endl; 
  LZespolona wynik=W*W2;
  cout << "  Wyswietlenie wyniku: W*W2" << endl
       << "        " <<wynik << endl
       << endl;
   W_wynik = W-W2;
  cout << "  Wyswietlenie wyniku: W-W2" << endl
       << "        " << W_wynik << endl
       << endl; 
     
}



int main()
{
  Test_SzablonWektor_double();
  Test_SzablonWektor_LZespolona(); 
}