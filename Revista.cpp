#include <iostream>
#include "systemas de clases/Revista.h"
#include "systemas de clases/MaterialBibliografico.h"

using namespace std;

Revista::Revista(string _nombre, int _isbn, string _autor, bool _prestado, int _numeroEdicion, string _mesPublicacion) : MaterialBibliografico(_nombre, _isbn, _autor, _prestado){
    this -> numeroEdicion = _numeroEdicion;
    this -> mesPublicacion = _mesPublicacion;
}

void Revista::mostrarInformacion(){
    MaterialBibliografico::mostrarInformacion();
    cout<<endl;
    cout<<"Numero de edicion: "<<numeroEdicion<<endl;
    cout<<"Mes de publicacion: "<<mesPublicacion<<endl;
    cout<<"-------------------------------------------------------"<<endl;
}