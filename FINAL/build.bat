:: Compilo c+odigo objeto
g++ -Wall -std=c++11 -c .\src\Circulo.cpp 
g++ -Wall -std=c++11 -c .\src\Cuadrado.cpp
g++ -Wall -std=c++11 -c .\src\Figura.cpp
g++ -Wall -std=c++11 -c main.cpp 

:: Compilo el Binario
g++ Circulo.o Cuadrado.o Figura.o main.o -o Figura.exe 

:: Limpio los códigos objeto
DEL .\*.o