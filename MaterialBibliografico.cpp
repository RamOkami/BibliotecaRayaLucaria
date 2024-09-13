#include <iostream>
#include "systemas de clases/MaterialBibliografico.h"

using namespace std;

MaterialBibliografico::MaterialBibliografico(string _nombre, int _isbn, string _autor, bool _prestado){
    this -> nombre = _nombre;
    this -> isbn = _isbn;
    this -> autor = _autor;
    this -> prestado = _prestado;
}

void MaterialBibliografico::mostrarInformación(){
    cout<<"Informacion del texto:"<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Identificador: "<<isbn<<endl;
    cout<<"Autor: "<<autor<<endl;
    if(prestado){
        cout<<"Estado: Prestado"<<endl;
    }else{
        cout<<"Estado: No prestado"<<endl;
    }
}

string MaterialBibliografico::getTitulo(){return nombre;}
string MaterialBibliografico::getAutor(){return autor;}
int MaterialBibliografico::getId(){return isbn;}
bool MaterialBibliografico::getEstado(){return prestado;}
void MaterialBibliografico::setEstado(bool _prestado){prestado = _prestado;}