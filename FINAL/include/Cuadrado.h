#ifndef CUADRADO_H
#define CUADRADO_H

#include "./Figura.h" 


class Cuadrado : public Figura{
  
    public:
        Cuadrado(float);
        virtual ~Cuadrado();
        float perimetro();
        float area();
};

#endif //CUADRADO_H