#ifndef FIGURA_H
#define FIGURA_H

class Figura{
     public:
        float x;
        Figura();
        virtual float perimetro()=0;
        virtual float area()=0;

         virtual ~Figura();


};

#endif //FIGURA_H
