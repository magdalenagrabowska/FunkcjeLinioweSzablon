#include "SMacierz.hh"
using std::cerr;
using std::endl;
using std::cout;

template<typename STyp, int SWymiar>
const SWektor<STyp,SWymiar> & SMacierzKw<STyp, SWymiar>::operator[] (unsigned int Wie) const{
    if (Wie < 0 || Wie >= SWymiar) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return Wiersz[Wie];
}
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> & SMacierzKw<STyp, SWymiar>::operator[] (unsigned int Wie){
       if (Wie < 0 || Wie >= SWymiar) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return Wiersz[Wie];
  }

template<typename STyp, int SWymiar>
 const STyp & SMacierzKw<STyp,SWymiar>::operator() (unsigned int Wie,unsigned int Kol) const{
      if ((Wie < 0 || Wie >= SWymiar) && (Kol < 0 || Kol >= SWymiar)) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return Wiersz[Wie][Kol];
  }
template<typename STyp, int SWymiar>
 STyp & SMacierzKw<STyp,SWymiar>::operator() (unsigned int Wie, unsigned int Kol){
     if ((Wie < 0 || Wie >= SWymiar) && (Kol < 0 || Kol >= SWymiar)) {
      cerr << "poza zakresem" << endl;
      exit(1);
    } 
    return Wiersz[Wie][Kol];
 }
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SMacierzKw<STyp,SWymiar>::zwroc_kolumne(int ind)const{
  if (ind < 0 || ind >= SWymiar) {
      cerr << "poza zakresem" << endl;
      exit(1);
    } 
    SWektor<STyp,SWymiar> Kol;
    for(int i=0;i<SWymiar;i++){
      Kol[i]=Wiersz[i][ind];
    }
      
    return Kol;
  }
 
template<typename STyp, int SWymiar>
void SMacierzKw<STyp,SWymiar>::zmien_kolumne(SWektor<STyp,SWymiar> W, int i){
 for(int j=0;j<SWymiar;j++)
 {
 Wiersz[j][i]=W[j];
 }
}

template<typename STyp, int SWymiar>
void SMacierzKw<STyp,SWymiar>::transpozycja(){
 SMacierzKw<STyp,SWymiar> M;
 SWektor<STyp,SWymiar> W;
 for(int i=0;i<SWymiar;i++){
   M.Wiersz[i]=Wiersz[i];
 }
 for(int i=0;i<SWymiar;i++){
   W=M.zwroc_kolumne(i);
   Wiersz[i]=W;
 }
}

template<typename STyp, int SWymiar>
STyp SMacierzKw<STyp,SWymiar>::wyznacznikGauss()const{
  STyp porownik;
  porownik=0;
  SMacierzKw<STyp,SWymiar> M;
  for(int i=0;i<SWymiar;i++){
   M.Wiersz[i]=Wiersz[i];
 }
  STyp det;
  det=1;
  STyp mnoznik;
  mnoznik=1;
  for(int i=0; i<SWymiar; ++i) {
         if(M.Wiersz[i][i] == porownik) {
              int j;
              for(j=i+1; j<SWymiar; ++j) // znajdź lepszy wiersz
                   if(M.Wiersz[j][i]!=porownik) {
                       SWektor<STyp,SWymiar> tmp = M.Wiersz[i];
                        M.Wiersz[i] = M.Wiersz[j];
                        M.Wiersz[j] = tmp;
                        det = -det;
                        break;
                   }
         }
  }
 for(int i=0;i<SWymiar-1;i++){
   for(int j=i+1;j<SWymiar;j++){
    mnoznik=M.Wiersz[j][i]/M.Wiersz[i][i];
    for(int k=i;k<SWymiar;k++)
    M.Wiersz[j][k]=M.Wiersz[j][k]-mnoznik*M.Wiersz[i][k];
   }
 }
 for(int z=0;z<SWymiar;++z){
   det*=M.Wiersz[z][z];
 }
 return det;
}

template<typename STyp, int SWymiar>
SMacierzKw<STyp,SWymiar> SMacierzKw<STyp,SWymiar>::operator+ (const SMacierzKw<STyp,SWymiar> & M)const{
  SMacierzKw<STyp,SWymiar> Suma;
   for(int ind=0;ind<SWymiar;ind++){
  Suma.Wiersz[ind]=Wiersz[ind]+M.Wiersz[ind];
   }
  return Suma;
  }
template<typename STyp, int SWymiar>
SMacierzKw<STyp,SWymiar> SMacierzKw<STyp,SWymiar>::operator - (const SMacierzKw<STyp,SWymiar> & M)const{
  SMacierzKw<STyp,SWymiar> Suma;
   for(int ind=0;ind<SWymiar;ind++){
  Suma.Wiersz[ind]=Wiersz[ind]-M.Wiersz[ind];
   }
  return Suma;
  }
template<typename STyp, int SWymiar>
SMacierzKw<STyp,SWymiar> SMacierzKw<STyp,SWymiar>::operator * (const SMacierzKw<STyp,SWymiar> & M)const{
  SMacierzKw<STyp,SWymiar> Suma;
  for(int ind=0;ind<SWymiar;ind++){
  SWektor<STyp,SWymiar> WK=M.zwroc_kolumne(ind);
  for(int i=0;i<SWymiar;i++){
  Suma.Wiersz[ind][i]=WK*Wiersz[ind];
  }
  }
  return Suma;
  } 

template<typename STyp, int SWymiar>
SMacierzKw<STyp,SWymiar> SMacierzKw<STyp,SWymiar>::operator * (double l)const{
   SMacierzKw<STyp,SWymiar> M;
   for(int i=0;i<SWymiar;i++){
    M.Wiersz[i]=Wiersz[i]*l;
   }
   return M;
 }
 
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SMacierzKw<STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> &W) const{
STyp Mnoznik;
SWektor<STyp,SWymiar> Wynik;  
for(int ind=0;ind<SWymiar;ind++){
for(int i=0;i<SWymiar;i++){
Mnoznik=Wiersz[ind][i]*W[i];
Wynik[ind]+=Mnoznik; 
}
}
return Wynik;
 }
 

template<typename STyp, int SWymiar>
std::istream& operator>>(std::istream &strm, SMacierzKw<STyp,SWymiar> &Mac){
for(int i=0;i<SWymiar;i++){
for(int j=0;j<SWymiar;j++){
strm>>Mac(i,j);
if(strm.fail())
strm.setstate(std::ios::failbit);
}
} 
return strm;
  }

template<typename STyp, int SWymiar>
std::ostream& operator<<(std::ostream &strm, const SMacierzKw<STyp,SWymiar> &Mac){
for(int i=0;i<SWymiar;i++){
for(int j=0;j<SWymiar;j++){
strm<<Mac(i,j);
 strm<<" ";
if(strm.fail())
strm.setstate(std::ios::failbit);
}
strm<<endl;
} 
return strm;
}
