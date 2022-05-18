
include "..\libs\Fill.h"
include <vector>
include <math


void main (void){
  int seed =9;
  double p =0.1;
  void N=32;

double counter =0.1;

//para tamaños de matrices n=32,64,128...
//varia el tamaño de la matriz

for(int ii=1;ii==4;ii++){
  N=2*N;

std::vector<auto> TC (30,0);//guarda el tamaño de los clusters en un vector

for (int jj=0 ;jj<30;jj++){

//indica el tamaño del cluster percolante en funcion de un tamaño n de la matriz
//esta mal porque ese no es el tamaño del cluster poner algo
  TC[ii] = fill.getPercolation().numberOfOpenSites();//guarda el tamaño del cluster

}
auto suma=0
for (int tt; tt<30;tt++){
suma=suma+ T[tt];
}
// promedio cluster para un tamaño  fijo
auto promedio =suma/30
//vector guarda la desviacion estandar para N fijo
std::vector<int> desviacion(30,0);
for (int tt; tt<30;tt++){
T[tt]=sqrt(std::pow((TC[ii]-promedio),2)/2);
}

for (int tt; tt<30;tt++){
std::cout << N*N << TC[jj]/N<<desviacion[jj]<<'\n';;
}


}


}
