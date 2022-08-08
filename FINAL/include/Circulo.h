#ifndef CIRCULO_H
#define CIRCULO_H  

#include "./Figura.h"

class Circulo : public Figura{
  
        Circulo(float);
        virtual ~Circulo();
        float perimetro();
        float area();

};

#endif // CIRCULO_H