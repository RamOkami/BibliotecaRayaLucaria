#include <iostream>
#include "systemas de clases/Libro.h"
#include "systemas de clases/MaterialBibliografico.h"

using namespace std;

Libro::Libro(string _nombre, int _isbn, string _autor, bool _prestado, string _fechaPublicacion, string _resumen) : MaterialBibliografico(_nombre, _isbn, _autor, _prestado){
    this -> fechaPublicacion = _fechaPublicacion;
    this -> resumen = _resumen;
}

void Libro::mostrarInformacion(){
    MaterialBibliografico::mostrarInformacion();
    cout<<endl;
    cout<<"Fecha de publicacion: "<<fechaPublicacion<<endl;
    cout<<"Resumen: "<<endl;
    cout<<resumen<<endl;
    cout<<"-------------------------------------------------------"<<endl;
}