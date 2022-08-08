#include "../include/Cuadrado.h"
#include <iostream>

using namespace std;

Cuadrado::Cuadrado(float lado){
   x = lado;
}

Cuadrado::~Cuadrado(){
    cout<<"cuadrado eliminado"<<endl;

}

float Cuadrado::perimetro(){
    return 4 * x;

}

float Cuadrado::area(){
    return x * x;

}


