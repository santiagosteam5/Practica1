#ifndef Nodo_h
#define Nodo_h

#include <iostream>
#include <string>

using namespace std;

class Nodo{
    private:
        static string PLACEHOLDER;
        string dato1;
        string dato2;
        Nodo *sgte;
    public:
        Nodo(int);
        ~Nodo();
        void set_sgte(Nodo*);
        Nodo *get_sgte();
        void nuevousuario();
        string toString();
        string Busqueda();

};

#endif