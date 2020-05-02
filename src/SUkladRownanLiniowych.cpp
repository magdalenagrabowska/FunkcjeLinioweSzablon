#include "SUkladRownanLiniowych.hh"
using std::endl;
using std::cout;

template<typename STyp, int SWymiar>
std::istream& operator >> (std::istream &strm, SUkladRownanL<STyp,SWymiar> &UklRown){
   SMacierzKw<STyp,SWymiar> A;
   SWektor<STyp,SWymiar> b;
    strm>>A;
    UklRown.set_A(A);
    strm>>b;
    UklRown.set_b(b);
    if(strm.fail())
    strm.setstate(std::ios::failbit);
    return strm;
}

template<typename STyp, int SWymiar>
std::ostream& operator << ( std::ostream &strm,const SUkladRownanL<STyp,SWymiar>  &UklRown){
  SMacierzKw<STyp,SWymiar> A=UklRown.get_A();
  SWektor<STyp,SWymiar> b=UklRown.get_b(); 
    strm<<"Macierz poczatkowa"<<endl;
    strm<<A; 
    strm<<"Wektor wyrazow wolnych"<<endl;
    strm<<b;
    if(strm.fail())
    strm.setstate(std::ios::failbit);
    return strm;
} 
template<typename STyp, int SWymiar>
const SMacierzKw<STyp,SWymiar> &SUkladRownanL<STyp,SWymiar>::get_A()const{
for(int i=0;i<SWymiar;i++){
    for(int j=0;j<SWymiar;j++){
    A[i][j];
    }
}
return A;
}
template<typename STyp, int SWymiar>
const SWektor<STyp,SWymiar> &SUkladRownanL<STyp,SWymiar>::get_b() const {
 for(int i=0;i<SWymiar;i++){
     b[i];
 }
 return b;
 }

 template<typename STyp, int SWymiar>
 void SUkladRownanL<STyp,SWymiar>::set_A(const SMacierzKw<STyp,SWymiar> & in){
   for(int i=0;i<SWymiar;i++){
    for(int j=0;j<SWymiar;j++){
    A[i][j]=in[i][j];
    }
 }
  A.transpozycja();
 }
template<typename STyp, int SWymiar>
 void SUkladRownanL<STyp,SWymiar>::set_b(const SWektor<STyp,SWymiar> & in){
  for(int i=0;i<SWymiar;i++){
     b[i]=in[i];
 }
 }
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SUkladRownanL<STyp,SWymiar>::Oblicz() const{
SWektor<STyp,SWymiar> Wynik;
STyp porownik; porownik=0;
STyp wyniczek; wyniczek=0;
STyp X=A.wyznacznikGauss();
if(X==porownik){
  cout<<"brak rozwiazania"<<endl;
  exit(2);
 }
for(int i=0;i<SWymiar;i++){
   SMacierzKw<STyp,SWymiar> M=A;
   M.zmien_kolumne(b,i); 
   wyniczek=M.wyznacznikGauss()/X;
   Wynik[i]=wyniczek;
}

return Wynik;
}
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SUkladRownanL<STyp,SWymiar>::wb()const{
SWektor<STyp,SWymiar> W=Oblicz();
SMacierzKw<STyp,SWymiar> M=A;
SWektor<STyp,SWymiar> Wynik=M*W;
SWektor<STyp,SWymiar> blad=Wynik-b;
return blad;
}
