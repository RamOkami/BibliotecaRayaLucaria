#include <iostream>
#include "systemas de clases/Usuario.h"
#include "systemas de clases/MaterialBibliografico.h"

using namespace std;

Usuario::Usuario(string _nombre, int _id){
    this -> nombre = _nombre;
    this -> id = _id;
}

void Usuario::prestarMaterial(MaterialBibliografico* _material){
    if(verificadorLista()){
        cout<<"Libro prestado con exito"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        for(int i = 0; i < 5; i++){
            if(MaterialesPrestados[i] == nullptr){
                _material->setEstado(true);
                MaterialesPrestados[i] = _material;
                break;
            }
        }
        ordenarLista();
    }else{
        cout<<"El usuario tiene el maximo de materiales permitidos (5)."<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<""<<endl;
    }
}

void Usuario::devolverMaterial(MaterialBibliografico* _material){
    int index = buscarLibro(_material);
    if(index >= 0){
        cout<<"Libro devuelto con exito"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        _material->setEstado(false);
        MaterialesPrestados[index] = nullptr;
        ordenarLista();
    }else{
        cout<<"No se ha encontrado el material"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<""<<endl;
    }
}

void Usuario::mostrarMaterialesPrestados(){
    for(int i = 0; i<5; i++){
        if(MaterialesPrestados[i] != nullptr){
            MaterialesPrestados[i]->mostrarInformación();
        }
    }
}

int Usuario::getId(){return id;}

void Usuario::mostrarInformacion(){
    cout<<"Nombre de Usuario: "<<nombre<<endl;
    cout<<"ID de Usuario: "<<id<<endl;
    cout<<"-------------------------------------------------------"<<endl;
}

bool Usuario::verificadorLista(){
    int aux = 0;
    for(int i = 0; i<5; i++){
        if(MaterialesPrestados[i] != nullptr){aux++;}
    }
    if(aux < 5){return true;}
    return false;
}

void Usuario::ordenarLista(){
    for(int i = 0; i<5; i++){
        if(MaterialesPrestados[i] == nullptr){
            if(i == 0){
                MaterialesPrestados[0] = MaterialesPrestados[i+1];
            }else if (i < 4){
                MaterialesPrestados[i] = MaterialesPrestados[i+1];
            }
        }   
    }
}

int Usuario::buscarLibro(MaterialBibliografico* _material){
    for(int i = 0; i<5; i++){
        if(MaterialesPrestados[i] != nullptr){
            if(_material->getId() == MaterialesPrestados[i]->getId()){
                return i;
            }
        }
    }
    return -1;
}