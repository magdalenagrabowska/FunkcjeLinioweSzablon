#include "SWektor.hh"
using std::endl;
using std::cerr;

template<typename STyp, int ROZMIAR>
 STyp & SWektor<STyp, ROZMIAR>::operator[] (unsigned int index) { 
    if (index < 0 || index >= ROZMIAR) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return _tab[index];     
  }

template<typename STyp, int ROZMIAR>
const STyp & SWektor<STyp, ROZMIAR>::operator[] (unsigned int index) const{
  if (index < 0 || index >= ROZMIAR) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
     return _tab[index];
}
template<typename STyp, int ROZMIAR>
std::istream &operator>>(std::istream &strm, SWektor<STyp, ROZMIAR>  &Wek){
for(int i=0;i<ROZMIAR;i++){
  strm>>Wek[i];
if(strm.fail())
strm.setstate(std::ios::failbit);
}
return strm;
}
template<typename STyp, int ROZMIAR>
std::ostream& operator <<(std::ostream &strm, const SWektor<STyp, ROZMIAR> &Wek){
for(int i=0;i<ROZMIAR;i++){
strm<<Wek[i]<<" ";
if(strm.fail())
strm.setstate(std::ios::failbit);
 } 
return strm;
}

template<typename STyp, int ROZMIAR>
SWektor<STyp, ROZMIAR> SWektor<STyp, ROZMIAR>::operator + (const SWektor<STyp, ROZMIAR> & W2) const{
SWektor<STyp, ROZMIAR> Suma;
for(int ind=0;ind<ROZMIAR;ind++){
  Suma._tab[ind]=_tab[ind]+W2._tab[ind];
}
return Suma;
}

template<typename STyp, int ROZMIAR>
SWektor<STyp, ROZMIAR> SWektor<STyp, ROZMIAR>::operator - (const  SWektor<STyp, ROZMIAR>& W2) const{
SWektor<STyp, ROZMIAR> Suma;
for(int ind=0;ind<ROZMIAR;ind++){
  Suma._tab[ind]=_tab[ind]-W2._tab[ind];
}
return Suma;
  }

template<typename STyp, int ROZMIAR>
STyp SWektor<STyp, ROZMIAR>::operator * (const SWektor<STyp, ROZMIAR> & W2) const{
STyp Suma;
Suma=0; //iloczyn skalarny
STyp mnoznik;
mnoznik=0;
for(int ind=0;ind<ROZMIAR;ind++){
  mnoznik=_tab[ind]*W2._tab[ind];
  Suma+=mnoznik;
}
return Suma;
}
template<typename STyp, int ROZMIAR>
SWektor<STyp, ROZMIAR> SWektor<STyp, ROZMIAR>::operator * (double li)const{
SWektor<STyp, ROZMIAR> W2;
 for(int ind=0;ind<ROZMIAR;ind++){
  W2._tab[ind]=_tab[ind]*li;
 }
return W2;
  }

template<typename STyp, int ROZMIAR>
bool SWektor<STyp, ROZMIAR>::operator == (const SWektor<STyp, ROZMIAR> & W2) const{
  for(int i=0;i<ROZMIAR;i++){
    STyp wartosc=W2._tab[i]-_tab[i];
    if(0,01<wartosc)
    return false;
    else;
  }
 return true;
  }

template<typename STyp, int ROZMIAR>
bool SWektor<STyp, ROZMIAR>::operator != (const SWektor<STyp, ROZMIAR> & W2) const{
  for(int i=0;i<ROZMIAR;i++){
    STyp wartosc=W2._tab[i]-_tab[i];
    if(0,01>wartosc)
    return false;
    else;
  }
 return true;
  }

template<typename STyp, int ROZMIAR>
STyp SWektor<STyp, ROZMIAR>::dlugosc() const{
  STyp a=0;
  for(int i=0;i<ROZMIAR;i++){
    STyp skl=(pow((_tab[i]),(2)));
    a+=skl;
  }
  a=sqrt(a);
return a;
  }  

template<typename STyp, int ROZMIAR>  
SWektor<STyp, ROZMIAR> operator * (double l1, SWektor<STyp, ROZMIAR> W2){
  for(int ind=0;ind<ROZMIAR;ind++){
  W2[ind]=l1*W2[ind];
}
return W2;
}

