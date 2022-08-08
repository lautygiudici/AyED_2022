#include<iostream>
#include "./include/Cuadrado.h"
#include "./include/Circulo.h"
#include "./include/Figura.h"

using namespace std;

int main(){
    Figura* Figura[3]; 

    float radio, lado;

    cout<<"dijite el tamaño de un lado del cuadrado 1: ";
    cin>>lado;
    Figura[0]= new Cuadrado(lado);

    cout<<"digite el radio del circulo: ";
    cin>>radio;
    Figura[1]= new Circulo(radio);

    //creamos el 3er elemento como lo solicita en el examen
    cout<<"dijite el tamaño de un lado del cuadrado 2: ";
    cin>>lado;
    Figura[2]= new Cuadrado(lado);

   
    cout<<"el perimetro del cuadrado es: "<<Figura[0]->perimetro()<<endl;
    cout<<"el area del cuadrado es: "<<Figura[0]->area()<<endl;

    cout<<"el perimetro del circulo es: "<<Figura[1]->perimetro()<<endl;
    cout<<"el area del circulo es: "<<Figura[1]->area()<<endl;

    cout<<"el perimetro del segundo cuadrado es: "<<Figura[2]->perimetro()<<endl;
    cout<<"el area del segundo cuadrado es: "<<Figura[2]->area()<<endl;

   
    return 0;
}