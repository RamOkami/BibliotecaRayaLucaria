#include "systemas de clases/MaterialBibliografico.h"
#include "systemas de clases/Libro.h"
#include "systemas de clases/Revista.h"
#include "systemas de clases/Usuario.h"
#include "systemas de clases/system.h"

#include <string.h>
#include <iostream>
using namespace std;

MaterialBibliografico * biblioteca [100] = {nullptr};
//---------------------------------------MENU GLOBAL------------------------------------------
void menuGlobal(){
    cout<<"Bienvenido a la Biblioteca de Raya Lucaria"<<endl;
    int opera = 0;
    do{
        cout<<""<<endl;
        cout<<"1. Agregar Materiales"<<endl;
        cout<<"2. Mostrar Informacion de los Materiales"<<endl;
        cout<<"3. Buscar Materiales"<<endl;
        cout<<"4. Prestar o Devolver Material"<<endl;
        cout<<"5. Gestion de Usuarios"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Ingrese el numero de operacion porfavor: "; cin>>opera;
        cout<<""<<endl;

        if(opera < 1 or opera > 6){
            cout<<"ERROR: Valor fuera de rango..."<<endl;
            cout<<"REINGRESAR DATOS PORFAVOR"<<endl;
        }else{
            switch(opera){
            case 1:
                if(!hayEspacio()){
                    cout<<"ERROR: No se puedo ingresar mas material."<<endl;
                    cout<<"LAS ESTANTERIAS ESTAN LLENAS..."<<endl;
                    cout<<endl;
                }else{
                    agregarMaterial();
                }
                break;
            case 2:
                mostrarMateriales();
                break;
            case 3:
                buscarMaterial();
                break;
            case 6:
                cout<<"SALIENDO DEL SISTEMA..."<<endl;
                break;
            }
        }
    }while(opera != 6 or opera < 1 or opera > 6);
}

//-----------------------------------------AGREGAR MATERIALES---------------------------------
void agregarMaterial(){
    int count_material = 0;
    int opera;
    do{
        cout<<"Ingreso de Materiales..."<<endl;
        cout<<"1.Agregar Libro"<<endl;
        cout<<"2.Agregar Revista"<<endl;
        cout<<"3.Cancelar Operacion"<<endl;
        cout<<"Ingrese el numero de la operacion que desea realizar: "; cin>>opera;

        if(opera == 3){
            cout<<"cancelando operacion..."<<endl;
            cout<<""<<endl;
            menuGlobal();
        }else{
            ingresoDatos(opera);
            count_material++;
        }

    }while(count_material < 100 and opera != 3);
}

void ingresoDatos(int aux){
    string nombre, autor, fechaPublicacion, resumen, mesPublicacion;
    char prestado;
    int isbn, numeroEdicion;
    bool prestamo;

    cout<<endl;
    cout<<"Ingrese el nombre del texto: "; cin>>nombre;
    cout<<"Ingrese el id del material: "; cin>>isbn;
    cout<<"Ingrese el autor del texto: "; cin>>autor;
    cout<<"Se encuentra prestado el material (S/N): "; cin>>prestado;
    cout<<endl;

    if(toupper(prestado) == 'S'){
        prestamo = true;
    }else{
        prestamo = false;
    }

    if(aux == 1){
        cout<<"Ingrese la fecha de publicacion: "; cin>>fechaPublicacion;
        cout<<"Ingrese resumen: "; cin>>resumen;
        cout<<endl;

        MaterialBibliografico* libros = new Libro(nombre, isbn, autor, prestamo, fechaPublicacion, resumen);
        for(int i = 0; i < 100; i++){
            if(biblioteca[i] == nullptr){
                biblioteca[i] = libros;
                break;
            }
        }
        cout<<"Material agregado con exito"<<endl;
    }else if(aux == 2){
        cout<<"Ingrese el numero de edicion: "; cin>>numeroEdicion;
        cout<<"Ingrese el mes de publicacion: "; cin>>mesPublicacion;
        cout<<endl;

        MaterialBibliografico* revistas = new Revista(nombre, isbn, autor, prestamo, numeroEdicion, mesPublicacion);
        for(int i = 0; i < 100; i++){
            if(biblioteca[i] == nullptr){
                biblioteca[i] = revistas;
                break;
            }
        }
        cout<<"Material agregado con exito"<<endl;
    }
}

//----------------------------------MOSTRAR MATERIALES----------------------------------------
void mostrarMateriales(){
    int aux = 0;
    cout<<"                  LISTA DE MATERIALES                  "<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    for(MaterialBibliografico* material: biblioteca){
        if(material != nullptr){
            material->mostrarInformación();
        }else{
            aux++;
        }
    }
    if(aux > 99){cout<<"No hay materiales en la biblioteca..."<<endl;}
}

//-----------------------------------BUSCAR MATERIALES----------------------------------------
void buscarMaterial(){
    int opera = 0;
    string nombre;
    string titulo;
    do{
        cout<<"Realizar busqueda por:"<<endl;
        cout<<"1. Busqueda por autor"<<endl;
        cout<<"2. Busqueda por titulo"<<endl;
        cout<<"3. Regresar"<<endl;
        cout<<"Ingrese el numero de operacion: "; cin>>opera;
        cout<<""<<endl;

        if(opera < 1 or opera > 3){
            cout<<"ERROR: Valor fuera de rango..."<<endl;
            cout<<"REINGRESAR DATOS PORFAVOR"<<endl;
        }else{
            switch(opera){
            case 1:
                cout<<"Ingrese el nombre del autor: "; cin>>nombre;
                buscador(nombre, true);
                break;
            case 2:
                cout<<"Ingrese el titulo del material: "; cin>>titulo;
                buscador(titulo, false);
                break;
            case 3:
                cout<<"REGRESANDO AL MENU..."<<endl;
                break;
            }
        }
    }while(opera != 3 or opera < 1 or opera > 3);
}

void buscador(string buscar, bool aux_busqueda){
    int aux = 0;
    if(aux_busqueda){
        for(MaterialBibliografico* material:biblioteca){
            if(material != nullptr and upperletters(material->getAutor()) == upperletters(buscar)){
                cout<<""<<endl;
                cout<<"Material encontrado: "<<endl;
                cout<<"-------------------------------------------------------"<<endl;
                material->mostrarInformación();
                cout<<""<<endl;
                break;
            }else{
                aux++;
            }
        }
    }else{
        for(MaterialBibliografico* material:biblioteca){
            if(material != nullptr and upperletters(material->getTitulo()) == upperletters(buscar)){
                cout<<""<<endl;
                cout<<"Material encontrado: "<<endl;
                cout<<"-------------------------------------------------------"<<endl;
                material->mostrarInformación();
                cout<<""<<endl;
                break;
            }else{
                aux++;
            }
        }
    }
    if(aux >= 99){
        cout<<""<<endl;
        cout<<"Material no encontrado..."<<endl;
        cout<<""<<endl;
    }
}

//--------------------------------------UTILIDADES--------------------------------------------
void ordenarBiblioteca(){
    for(int i = 0; i<100; i++){
        if(biblioteca[i] == nullptr){
            if(i == 0){
                biblioteca[0] = biblioteca[i+1];
            }else if(i < 99){
                biblioteca[i] = biblioteca[i+1];
            }
        }
    }
}

bool hayEspacio(){
    int aux = 0;
    for(MaterialBibliografico* material: biblioteca){
        if(material != nullptr){
            aux++;
        }
    }
    if(aux >= 99){
        return false;
    }else{
        return true;
    }
}

string upperletters(string palabra){
    for(char& letra:palabra){
        letra = toupper(letra);
    }
    return palabra;
}