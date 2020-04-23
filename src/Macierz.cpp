#include "Macierz.hh"
using std::cerr;
using std::endl;
using std::cout;
const Wektor &MacierzKw::operator[] (int Wie) const{
    if (Wie < 0 || Wie >= ROZMIAR) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return Wiersz[Wie];
  }
Wektor &MacierzKw::operator[] (int Wie){
       if (Wie < 0 || Wie >= ROZMIAR) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return Wiersz[Wie];
  }
 const double &MacierzKw::operator() (int Wie, int Kol) const{
      if ((Wie < 0 || Wie >= ROZMIAR) && (Kol < 0 || Kol >= ROZMIAR)) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return Wiersz[Wie][Kol];
  }
 double &MacierzKw::operator() (int Wie, int Kol){
     if ((Wie < 0 || Wie >= ROZMIAR) && (Kol < 0 || Kol >= ROZMIAR)) {
      cerr << "poza zakresem" << endl;
      exit(1);
    } 
    return Wiersz[Wie][Kol];
 }
  
Wektor MacierzKw::zwroc_kolumne(int ind)const{
  if (ind < 0 || ind >= ROZMIAR) {
      cerr << "poza zakresem" << endl;
      exit(1);
    } 
    Wektor Kol;
    for(int i=0;i<ROZMIAR;i++){
      Kol[i]=Wiersz[i][ind];
    }
      
    return Kol;
  } 
void MacierzKw::zmien_kolumne(int ind){
zwroc_kolumne(ind+1);
}
void MacierzKw::transpozycja(){
  Wektor Kolumna1=zwroc_kolumne(0);
  Wektor Kolumna2=zwroc_kolumne(1);
  Wektor Kolumna3=zwroc_kolumne(2);
  Wiersz[0]=Kolumna1;
  Wiersz[1]=Kolumna2;
  Wiersz[2]=Kolumna3;
}
void MacierzKw::odwrotnosc(){
 double minor[ROZMIAR-1][ROZMIAR-1];
 MacierzKw M;
 M.Wiersz[0]=Wiersz[0];
 M.Wiersz[1]=Wiersz[1];
 M.Wiersz[2]=Wiersz[2];
 double a=1/wyznacznikSarrus();
 if(a==0){
  cout<<"nie istnieje macierz odwrotna"<<endl;
  exit(2);
 }
for(int i=0;i<ROZMIAR;i++){
for(int j=0;j<ROZMIAR;j++){
 int b=0,c=0;
 for(int n=0;n<ROZMIAR;n++){
   for(int z=0;z<ROZMIAR;z++){
     if(n!=i)
     if(z!=j){
      minor[b][c]=M.Wiersz[n][z];
      if(c==1){
       c=0;
       b++;
      }
      else c++;
     }
   }
 }
 double wyznacznik=minor[0][0]*minor[1][1]-minor[1][0]*minor[0][1];
 Wiersz[i][j]=a*pow((-1),(i+j))*wyznacznik;
}
}
transpozycja();
}
double MacierzKw::wyznacznikSarrus(){
  double suma1,suma2,sumac;
  double skl1,skl2,skl3,skl4,skl5,skl6;
  skl1=Wiersz[0][0]*Wiersz[1][1]*Wiersz[2][2];
  skl2=Wiersz[0][1]*Wiersz[1][2]*Wiersz[2][0];
  skl3=Wiersz[0][2]*Wiersz[1][0]*Wiersz[2][1];
  suma1=skl1+skl2+skl3;
  skl4=Wiersz[2][0]*Wiersz[1][1]*Wiersz[0][2];
  skl5=Wiersz[2][1]*Wiersz[1][2]*Wiersz[0][0];
  skl6=Wiersz[2][2]*Wiersz[1][0]*Wiersz[0][1];
  suma2=skl4+skl5+skl6;
  sumac=suma1-suma2;
  return sumac;
}
double MacierzKw::wyznacznikLaplace(){
double suma1,suma2,suma3,sumac;
/*dla przykladowego wiersza 0 */

 suma1=pow((-1),(2))*Wiersz[0][0]*(Wiersz[1][1]*Wiersz[2][2]-Wiersz[1][2]*Wiersz[2][1]);
 suma2=pow((-1),(3))*Wiersz[0][1]*(Wiersz[1][0]*Wiersz[2][2]-Wiersz[1][2]*Wiersz[2][0]);
 suma3=pow((-1),(4))*Wiersz[0][2]*(Wiersz[1][0]*Wiersz[2][1]-Wiersz[1][1]*Wiersz[2][0]);
 sumac=suma1+suma2+suma3;
 return sumac;
}
double MacierzKw::wyznacznikGauss(){
  double suma=0;
  MacierzKw M;
  M.Wiersz[0]=Wiersz[0];
  if(Wiersz[0][0]==0){
    M.Wiersz[1]=Wiersz[1]-(Wiersz[2]*(Wiersz[1][0]/Wiersz[2][0])); 
    std::swap(M.Wiersz[0],M.Wiersz[2]);
    M.Wiersz[2]=M.Wiersz[2]-(M.Wiersz[0]*(M.Wiersz[2][1]/M.Wiersz[0][1]));}
  if(Wiersz[1][0]==0){
    M.Wiersz[1]=Wiersz[1];
  }
  else M.Wiersz[1]=Wiersz[1]-(Wiersz[0]*(Wiersz[1][0]/Wiersz[0][0]));
  if(Wiersz[2][0]==0 && Wiersz[2][1]==0){
  M.Wiersz[2]=Wiersz[2];
  }
  else{ M.Wiersz[2]=Wiersz[2]-(Wiersz[0]*(Wiersz[2][0]/Wiersz[0][0]));
  M.Wiersz[2]=M.Wiersz[2]-(M.Wiersz[1]*(M.Wiersz[2][1]/M.Wiersz[1][1]));}
 if(Wiersz[0][0]==0 || Wiersz[1][1]==0 || Wiersz[2][2]==0){
  return suma;
  }
  suma=M.Wiersz[0][0]*M.Wiersz[1][1]*M.Wiersz[2][2];
  return suma;
}
MacierzKw MacierzKw::operator+ (const MacierzKw & M)const{
  MacierzKw Suma;
   for(int ind=0;ind<ROZMIAR;ind++){
  Suma.Wiersz[ind]=Wiersz[ind]+M.Wiersz[ind];
   }
  return Suma;
  }
MacierzKw MacierzKw::operator - (const MacierzKw & M)const{
  MacierzKw Suma;
   for(int ind=0;ind<ROZMIAR;ind++){
  Suma.Wiersz[ind]=Wiersz[ind]-M.Wiersz[ind];
   }
  return Suma;
  }
MacierzKw MacierzKw::operator * (const MacierzKw & M)const{
  MacierzKw Suma;
  MacierzKw Mnoznik;
  for(int ind=0;ind<ROZMIAR;ind++){
  for(int j=0;j<ROZMIAR;j++){
  Wektor Kolumna=M.zwroc_kolumne(j);
  for(int i=0;i<ROZMIAR;i++){
  Mnoznik.Wiersz[ind]=Wiersz[ind]*Kolumna[i];
  Suma[ind][j]+=Mnoznik[ind][i];
  }
  }
  }
  return Suma;
  } 
MacierzKw MacierzKw::operator * (double l)const{
   MacierzKw M;
   for(int i=0;i<ROZMIAR;i++){
    M.Wiersz[i]=Wiersz[i]*l;
   }
   return M;
 }
Wektor MacierzKw::operator * (const Wektor &W) const{
double Mnoznik;
Wektor Wynik;  
for(int ind=0;ind<ROZMIAR;ind++){
for(int i=0;i<ROZMIAR;i++){
Mnoznik=Wiersz[ind][i]*W[i];
Wynik[ind]+=Mnoznik; 
}
}
return Wynik;
 }
 bool MacierzKw::operator == (const MacierzKw & M) const{
  for(int i=0;i<ROZMIAR;i++){
    if(M.Wiersz[i]!=Wiersz[i])
    return false;
    else;
  }
  return true;
 }
bool MacierzKw::operator != (const MacierzKw & M) const{
  for(int i=0;i<ROZMIAR;i++){
    if(M.Wiersz[i]==Wiersz[i])
    return false;
    else;
  }
  return true;
  }
std::istream& operator >> (std::istream &strm, MacierzKw &Mac){
for(int i=0;i<ROZMIAR;i++){
for(int j=0;j<ROZMIAR;j++){
strm>>Mac(i,j);
if(strm.fail())
strm.setstate(std::ios::failbit);
}
} 
return strm;
  } 
std::ostream& operator << (std::ostream &strm, const MacierzKw &Mac){
for(int i=0;i<ROZMIAR;i++){
for(int j=0;j<3;j++){
strm<<Mac(i,j)<<" ";
if(strm.fail())
strm.setstate(std::ios::failbit);
}
strm<<endl;
} 
return strm;
}
