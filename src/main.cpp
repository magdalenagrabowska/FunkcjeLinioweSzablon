#include <iostream>
#include "SWektor.hh"
#include "LZespolona.hh"
#include "rozmiar.h"
#include "SMacierz.hh"
#include <fstream>
#include "SUkladRownanLiniowych.hh"
using namespace std;

void Test_SzablonMacierz_double(){
     cout << endl
       << " --------- Test klasy Macierz<double," << ROZMIAR << "> ----------" << endl
       << endl;

  SMacierzKw<double,ROZMIAR> M, M2, M_Wynik;
  SWektor<double,ROZMIAR> W, W_Wynik;

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind] = Ind;
  }

  M[0][0]=1; M[0][1]=4; M[0][2]=3; M[0][3]=2; M[0][4]=0;
  M[1][0]=2; M[1][1]=-3; M[1][2]=5; M[1][3]=0; M[1][4]=-1;
  M[2][0]=-1; M[2][1]=1; M[2][2]=2; M[2][3]=0; M[2][4]=3;
  M[3][0]=0; M[3][1]=3; M[3][2]=4; M[3][3]=0; M[3][4]=1;
  M[4][0]=-5; M[4][1]=0; M[4][2]=-1; M[4][3]=0; M[4][4]=2;

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
  for (unsigned int i = 0; i<ROZMIAR; ++i){
    M2(Ind,i) = Ind;
  }
  }
  M.zmien_kolumne(W,0);
  cout<<M;
  /*
  cout<<"  Wyswietlenie wspolrzednych macierzy: M"<<endl;
  cout<< M;
  cout<<endl<<endl;
   
  cout<<"  Wyswietlenie wspolrzednych macierzy: M2"<<endl;
  cout<< M2;
  cout<<endl<<endl;

 M_Wynik=M+M2;
  cout << "  Wyswietlenie wyniku:M+M2 " << endl
       << M_Wynik;
       cout<< endl;
 M_Wynik=M-M2;
  cout << "  Wyswietlenie wyniku:M-M2 " << endl
       << M_Wynik;
       cout<< endl; 
M_Wynik=M*M2*3;
  cout << "  Wyswietlenie wyniku:M*M2*3 " << endl
       << M_Wynik;
       cout<< endl; 
W_Wynik=M*W;
  cout << "  Wyswietlenie wyniku:M*W " << endl
       << W_Wynik;
       cout<< endl; 
  double wyzn=M.wyznacznikGauss();
       cout << "  Wyswietlenie wyznacznika macierzy " << endl
       << wyzn;
       cout<< endl;  */  
 M.transpozycja();
  cout << "  Wyswietlenie transpozycji macierzy " << endl
       << M;
       cout<< endl;    
  
}
void Test_SzablonMacierz_zespolone(){
     cout << endl
       << " --------- Test klasy Macierz<LZespolona," << ROZMIAR << "> ----------" << endl
       << endl;

  SMacierzKw<LZespolona,ROZMIAR> M, M2, M_Wynik;
  SWektor<LZespolona,ROZMIAR> W, W_Wynik;

  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind].re = Ind;      W[Ind].im = Ind;
  }
  
  M[0][0].re=1;M[0][0].im=1; M[0][1].re=4;M[0][1].im=4; M[0][2].re=3;M[0][2].im=3; M[0][3].re=2;M[0][3].im=2; M[0][4].re=0;M[0][4].im=0;
  M[1][0].re=2;M[1][0].im=2; M[1][1].re=-3;M[1][1].im=-3; M[1][2].re=5;M[1][2].im=5; M[1][3].re=0;M[1][3].im=0; M[1][4].re=-1;M[1][4].im=-1;
  M[2][0].re=-1;M[2][0].im=-1; M[2][1].re=1; M[2][1].im=1; M[2][2].re=2;M[2][2].im=2; M[2][3].re=0;M[2][3].im=0; M[2][4].re=3;M[2][4].im=3;
  M[3][0].re=0;M[3][0].im=0; M[3][1].re=3; M[3][1].im=3;  M[3][2].re=4;M[3][2].im=4; M[3][3].re=0; M[3][3].im=0; M[3][4].re=1; M[3][4].im=1;
  M[4][0].re=-5;M[4][0].im=-5; M[4][1].re=0;M[4][1].im=0; M[4][2].re=-1;M[4][2].im=-1; M[4][3].re=0; M[4][3].im=0; M[4][4].re=2;M[4][4].im=2;
  

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
  for (unsigned int i = 0; i<ROZMIAR; ++i){
    M2(Ind,i).re = i; M2(Ind,i).im = i;
  }
  }
  /*cout<<"  Wyswietlenie wspolrzednych macierzy: M"<<endl;
  cout<< M;
  cout<<endl<<endl;
   
  cout<<"  Wyswietlenie wspolrzednych macierzy: M2"<<endl;
  cout<< M2;
  cout<<endl<<endl;

 M_Wynik=M+M2;
  cout << "  Wyswietlenie wyniku:M+M2 " << endl
       << M_Wynik;
       cout<< endl;
 M_Wynik=M-M2;
  cout << "  Wyswietlenie wyniku:M-M2 " << endl
       << M_Wynik;
       cout<< endl; 
M_Wynik=M*M2*3;
  cout << "  Wyswietlenie wyniku:M*M2*3 " << endl
       << M_Wynik;
       cout<< endl; 
W_Wynik=M*W;
  cout << "  Wyswietlenie wyniku:M*W " << endl
       << W_Wynik;
       cout<< endl; */
  LZespolona wyzn=M.wyznacznikGauss();
       cout << "  Wyswietlenie wyznacznika macierzy " << endl
       << wyzn;
       cout<< endl;  /*  
  M.transpozycja();
  cout << "  Wyswietlenie transpozycji macierzy " << endl
       << M;
       cout<< endl; */  
  
}

int main(int argc, char *argv[]){
      if (argv[1][0]=='-' && argv[1][1]=='-' && argv[1][2]=='h' && argv[1][3]=='e' && argv[1][4]=='l' && argv[1][5]=='p'){ 
          cerr<<"dozwolone opcje to r i z. r oznacza rozwiazanie rownania rzeczywistego, a z- zespolonego."<<endl;
      return 0;
      }
    switch(argv[1][0]){
         case 'r':{
      SUkladRownanL<double,ROZMIAR>  UklRown;
     ifstream wczyt;
     wczyt.open("funkcja_liniowa.txt");
     wczyt>>UklRown;
          if(cin.fail()){
       cout<<"Blad sie wkradl"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
          } 
     cout<<endl;
     cout<<"Oto twoj uklad rownan"<<endl;
     cout<<UklRown;
     cout<<endl;
     SWektor<double, ROZMIAR> Wynik=UklRown.Oblicz();
     cout<<"Oto wynik twych obliczen"<<endl;
     cout<<Wynik;
     cout<<endl;
     SWektor<double,ROZMIAR> blad=UklRown.wb();
     cout<<"Oto dlugosc wektora bledu obliczen"<<endl;
     cout<<blad<<endl;
     if(cout.fail()){
    cout<<"Masz blad!"<<endl;
     } 
     else cout<<"Koniec programu"<<endl;

     wczyt.close();
      break;
    }
    case 'z':{
        SUkladRownanL<LZespolona,ROZMIAR>  UklRown;
     ifstream wczyt;
     wczyt.open("funkcja_liniowa_re.txt");
     wczyt>>UklRown;
          if(cin.fail()){
       cout<<"Blad sie wkradl"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
          } 
     cout<<endl;
     cout<<"Oto twoj uklad rownan"<<endl;
     cout<<UklRown;
     cout<<endl;
     SWektor<LZespolona, ROZMIAR> Wynik=UklRown.Oblicz();
     cout<<"Oto wynik twych obliczen"<<endl;
     cout<<Wynik;
     cout<<endl;
     SWektor<LZespolona,ROZMIAR> blad=UklRown.wb();
     cout<<"Oto dlugosc wektora bledu obliczen"<<endl;
     cout<<blad<<endl;
     if(cout.fail()){
    cout<<"Masz blad!"<<endl;
     } 
     else cout<<"Koniec programu"<<endl;

     wczyt.close();
     break;
    }
 }
    }


