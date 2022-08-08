#include "../include/Circulo.h"
#include <iostream>


Circulo::Circulo(float radio){
    x = radio;
}

Circulo::~Circulo(){
}

float Circulo::perimetro(){
    return 2 * 3.14 * x;

}

float Circulo::area(){
    return 3.14 * x*x;

}