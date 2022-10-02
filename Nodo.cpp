#include "Nodo.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Nodo::Nodo(int a){
    this->dato1 = "";
    this->dato2 = "";
    if(a == 0){
        nuevousuario();
    }
    else{
        this->dato1 = "usuario";
        this->dato2 = "pwd";
    }
}

string Nodo::PLACEHOLDER = "usuario\n\npwd\n\n";

void Nodo::nuevousuario(){
    ofstream arch;
    string jsjs;
    string waos;
    cout << "Digite un nombre de usuario... \n";
    getline(cin, this->dato1);
    cout << "Confirme su nombre de usuario... \n";
    getline(cin, this->dato1);
    cout << "Digite una contraseña... \n";
    getline(cin, this->dato2);
    jsjs = this->dato1+"\n"+""+"\n";
    jsjs = jsjs+this->dato2+"\n"+"\n";

    this->PLACEHOLDER = this->PLACEHOLDER+jsjs;
    
    waos = this->PLACEHOLDER;

    arch.open("usuarios.txt",ios::out);

    arch << waos;

    arch.close();
}

void Nodo::set_sgte(Nodo *l){
    this->sgte = l;
}

Nodo *Nodo::get_sgte(){
    return this->sgte;
}

string Nodo::toString(){
    string respuesta;
    respuesta = this->dato1+"\n"+""+"\n";
    respuesta = respuesta+this->dato2+"\n";
    return respuesta;
}

string Nodo::Busqueda(){
    string o;
    o = this->dato1;
    return o;
}

int main(){
    Nodo *inicio = new Nodo(1);
    Nodo *lista = inicio;
    int opcion = 1;
    int num = 1;
    do{
        cout << "Bienvenido" << "\n";
        cout << "-----------------------------------------" << "\n";
        cout << "Seleccione una de las siguientes opciones" << "\n";
        cout << "1. Ingresar nuevo usuario" << "\n";
        cout << "2. Buscar usuario" << "\n";
        cout << "3. Eliminar usuario existente" << "\n";
        cout << "4. Mostrar usuarios existentes" << "\n";
        cout << "5. Salir del sistema" << "\n\n";
        cin >> opcion;
        switch(opcion){
            case 1:{
                Nodo *nuevo = new Nodo(0);
                lista->set_sgte(nuevo);
                lista = nuevo;
                num = num+1;
                break;
            }
            case 2:{
                lista = inicio;
                string busqueda;
                string objetivo;
                cout << "Ingrese el usuario a buscar\n\n";
                cin >> busqueda;
                while(busqueda != objetivo){
                    objetivo = lista->Busqueda();
                    lista = lista->get_sgte();
                }
                if(busqueda == objetivo){
                    cout << "Bienvenido\n\n";
                }
                else{
                    cout << "No se encontro ese usuario\n\n";
                }
                break;
            }
            case 3:{
                lista = inicio;
                Nodo *Anterior = NULL;
                string eliminar;
                cout << "Ingrese el usuario que desea eliminar\n\n";
                cin >> eliminar;
                if(eliminar == lista->Busqueda()){
                    lista = lista->get_sgte();
                }
                else{
                    while((eliminar != lista->Busqueda()) && (lista != NULL)){
                        Anterior = lista;
                        lista = lista->get_sgte();
                    }
                    if(lista != NULL){
                        Anterior->set_sgte(lista->get_sgte());
                    }
                }
                break;
            }
            case 4:{
                lista = inicio;
                int i = 0;
                while(i<num){
                    cout << lista->toString() << "\n";
                    lista = lista->get_sgte();
                    i++;
                }
                break;
            }
            case 5:
                cout << "Adios"; 
                break;
        }
    }while(opcion != 5);
}