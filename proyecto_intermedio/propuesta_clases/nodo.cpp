#include "nodo.h"
#include <iostream>

Nodo::Nodo(bool state){
  std::cout<<"Estado "<<state<<std::endl;
}
void Nodo::setState(bool state){
   std::cout<<"Nuevo estado "<<state<<std::endl;
}
