#include "systemas de clases/MaterialBibliografico.h"
#include "systemas de clases/Libro.h"
#include "systemas de clases/Revista.h"
#include "systemas de clases/Usuario.h"
#include "systemas de clases/system.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

MaterialBibliografico * biblioteca [100] = {nullptr};
Usuario * usuarios [100] = {nullptr};
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
            case 4:
                opcionesMaterial();
                break;
            case 5:
                gestionUsuarios();
                break;
            case 6:
                cout<<"SALIENDO DEL SISTEMA..."<<endl;
                break;
            }
        }
    }while(opera != 6);
}

//-----------------------------------------AGREGAR MATERIALES---------------------------------
void agregarMaterial(){
    int count_material = 0;
    int opera;
    do{
        cout<<"INGRESO DE MATERIALES"<<endl;
        cout<<"1.Agregar Libro"<<endl;
        cout<<"2.Agregar Revista"<<endl;
        cout<<"3.Regresar"<<endl;
        cout<<"Ingrese el numero de la operacion que desea realizar: "; cin>>opera;

        if(opera == 3){
            cout<<""<<endl;
            cout<<"REGRESANDO AL MENU..."<<endl;
            break;
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
    cout<<"Ingrese el nombre del texto: ";
    cin.ignore('\n');
    getline(cin, nombre);
    cout<<"Ingrese el id del material: "; cin>>isbn;
    cout<<"Ingrese el autor del texto: ";
    cin.ignore('\n');
    getline(cin, autor);
    cout<<"Se encuentra prestado el material (S/N): "; cin>>prestado;
    cout<<endl;

    if(toupper(prestado) == 'S'){
        prestamo = true;
    }else{
        prestamo = false;
    }

    if(aux == 1){
        cout<<"Ingrese la fecha de publicacion: ";
        cin.ignore('\n');
        getline(cin, fechaPublicacion);
        cout<<"Ingrese resumen: ";
        cin.ignore('\n');
        getline(cin, resumen);
        cout<<endl;

        MaterialBibliografico* libros = new Libro(nombre, isbn, autor, prestamo, fechaPublicacion, resumen);
        for(int i = 0; i < 100; i++){
            if(biblioteca[i] == nullptr){
                biblioteca[i] = libros;
                break;
            }
        }
        cout<<"Material agregado con exito"<<endl;
        cout<<endl;
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
            material->mostrarInformacion();
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
                cout<<"Ingrese el nombre del autor: ";
                cin.ignore('\n');
                getline(cin, nombre);
                buscador(nombre, true);
                break;
            case 2:
                cout<<"Ingrese el titulo del material: ";
                cin.ignore('\n');
                getline(cin, titulo);
                buscador(titulo, false);
                break;
            case 3:
                cout<<"REGRESANDO AL MENU..."<<endl;
                break;
            }
        }
    }while(opera != 3);
}

void buscador(string buscar, bool aux_busqueda){
    int aux = 0;
    if(aux_busqueda){
        for(MaterialBibliografico* material:biblioteca){
            if(material != nullptr and upperletters(material->getAutor()) == upperletters(buscar)){
                cout<<""<<endl;
                cout<<"Material encontrado: "<<endl;
                cout<<"-------------------------------------------------------"<<endl;
                material->mostrarInformacion();
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
                material->mostrarInformacion();
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

bool materialAux(string nombre){
    for(MaterialBibliografico* material: biblioteca){
        if(material != nullptr and upperletters(material->getTitulo()) == upperletters(nombre)){
            return true;
        }
    }
    return false;
}

//--------------------------------OPCIONES DE MATERIALES--------------------------------------
void opcionesMaterial(){
    int opera = 0;
    do{
        cout<<"Opciones de materiales:"<<endl;
        cout<<"1. Prestar material"<<endl;
        cout<<"2. Devolucion de material"<<endl;
        cout<<"3. Regresar"<<endl;
        cout<<"Ingrese el numero de operacion: "; cin>>opera;
        cout<<""<<endl;

        if(opera < 1 or opera > 3){
            cout<<"ERROR: Valor fuera de rango..."<<endl;
            cout<<"REINGRESAR DATOS PORFAVOR"<<endl; 
        }else{
            switch(opera){
            case 1:
                prestarMaterial();
                break;
            case 2:
                devolverMaterial();
                break;
            case 3:
                cout<<"REGRESANDO AL MENU..."<<endl;
                break;
            }
        }
    }while(opera < 1 or opera > 3 or opera != 3);
}

void prestarMaterial(){
    int _id = 0;
    Usuario* user;
    MaterialBibliografico* aux_material;
    string nombre;
    cout<<"------------------------------------------"<<endl;
    cout<<"Ingrese el id del usuario: "; cin>>_id;
    if(buscarUsuario(_id, false)){
        user = usuarioObj(_id);
        cout<<""<<endl;
        cout<<"Busqueda de material"<<endl;
        cout<<"Ingrese el nombre del material: ";
        cin.ignore('\n');
        getline(cin, nombre);
        if(materialAux(nombre)){
            aux_material = materialObj(nombre);
            if(!(aux_material->getEstado())){
                user->prestarMaterial(aux_material);
                cout<<""<<endl;
            }else{
                cout<<""<<endl;
                cout<<"El material se encuentra prestado"<<endl;
                cout<<""<<endl;
            }
        }else{
            cout<<""<<endl;
            cout<<"MATERIAL NO ENCONTRADO..."<<endl;
            cout<<""<<endl;
        }
    }
}

void devolverMaterial(){
    int _id = 0;
    Usuario* user;
    MaterialBibliografico* aux_material;
    string nombre;
    cout<<"------------------------------------------"<<endl;
    cout<<"Ingrese el id del usuario: "; cin>>_id;
    if(buscarUsuario(_id, false)){
        user = usuarioObj(_id);
        cout<<""<<endl;
        cout<<"Ingrese el nombre del material: ";
        cin.ignore('\n');
        getline(cin, nombre);
        if(materialAux(nombre)){
            aux_material = materialObj(nombre);
            user->devolverMaterial(aux_material);
            cout<<""<<endl;
        }else{
            cout<<""<<endl;
            cout<<"MATERIAL NO ENCONTRADO..."<<endl;
            cout<<""<<endl;
        }
    }
}

//-----------------------------------OPCIONES USUARIO-----------------------------------------
void gestionUsuarios(){
    int opera = 0, _id = 0;
    do{
        cout<<"Gestion de Usuarios:"<<endl;
        cout<<"1. Agregar Usuario"<<endl;
        cout<<"2. Buscar Usuario"<<endl;
        cout<<"3. Eliminar Usuario"<<endl;
        cout<<"4. Regresar"<<endl;
        cout<<"Ingrese el numero de operacion: "; cin>>opera;
        cout<<""<<endl;

        if(opera < 1 or opera > 4){
            cout<<"ERROR: Valor fuera de rango..."<<endl;
            cout<<"REINGRESAR DATOS PORFAVOR"<<endl; 
        }else{
            switch(opera){
            case 1:
                if(!hayEspacioUsers()){
                    cout<<"ERROR: No se pueden ingresar mas usuarios."<<endl;
                    cout<<"NO QUEDAN VACANTES..."<<endl;
                    cout<<""<<endl;
                }else{
                    addUser();
                }
                break;
            case 2:
                cout<<"Ingrese el ID del Usuario: "; cin>>_id;
                cout<<""<<endl;
                cout<<"-------------------------------------------------------"<<endl;
                buscarUsuario(_id, true);
                cout<<""<<endl;
                break;
            case 3:
                deleteUser();
                break;
            case 4:
                cout<<"REGRESANDO AL MENU..."<<endl;
                break;
            }
        }
    }while(opera != 4);
}

void addUser(){
    string _nombre;
    int _id;
    bool aux = false;
    cout<<"AGREGAR USUARIOS"<<endl;
    cout<<"Ingrese Nombre de Usuario: ";
    cin.ignore('\n');
getline(cin, _nombre);
    do{
        cout<<"Ingrese ID de Usuario: "; cin>>_id;
        if(buscarUsuario(_id, false)){
            aux = true;
            cout<<""<<endl;
            cout<<"ERROR: EL ID YA SE ENCUENTRA OCUPADO."<<endl;
            cout<<""<<endl;
        }else{
            aux = false;
        }
    }while(aux);
    cout<<"ID "<<_id<<" se encuentra disponible."<<endl;

    Usuario* user = new Usuario(_nombre, _id);
    for(int i = 0; i < 100; i++){
        if(usuarios[i] == nullptr){
            usuarios[i] = user;
            break;
        }
    }

    cout<<"Usuario Creado con Exito"<<endl;
    cout<<""<<endl;
}

bool buscarUsuario(int id, bool aux){
    for(Usuario* user: usuarios){
        if(user != nullptr and user->getId() == id){
            if(aux){
                user->mostrarInformacion();
            }
            return true;
        }
    }
    cout<<""<<endl;
    cout<<"No se encontro el Usuario"<<endl;
    return false;
}

void deleteUser(){
    int _id;
    bool aux = true;
    cout<<"PANEL DE ELIMINACION DE USUARIOS"<<endl;
    do{
        cout<<"Use 0 para cancelar operacion"<<endl;
        cout<<"Ingrese el ID del usuario para eliminar: "; cin>>_id;
        if(_id == 0){
            cout<<""<<endl;
            break;
        }
        if(!buscarUsuario(_id, false)){
            aux = false;
            cout<<""<<endl;
        }else{
            aux = true;
        }
    }while(!aux);

    if(_id != 0){
        for(int i = 0; i < 100; i++){
            if(usuarios[i] != nullptr and usuarios[i]->getId() == _id){
                cout<<""<<endl;
                cout<<"Usuario "<<usuarios[i]->getId()<<" Eliminado con Exito"<<endl;
                cout<<""<<endl;
                delete usuarios[i];
                usuarios[i] = nullptr;
            }
        }
    }
}

//--------------------------------CARGAR MATERIALES--------------------------------------
void cargaMateriales(){
    
}

void cargaUsuarios(){
    
}

//--------------------------------------UTILIDADES--------------------------------------------
MaterialBibliografico* materialObj(string nombre){
    for(MaterialBibliografico* material: biblioteca){
        if(upperletters(material->getTitulo()) == upperletters(nombre)){
            return material;
        }
    }
    return nullptr;
}

Usuario* usuarioObj(int id){
    for(Usuario* user: usuarios){
        if(user != nullptr and user->getId() == id){
            return user;
        }
    }
    return nullptr;
}

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

bool hayEspacioUsers(){
    int aux = 0;
    for(Usuario* user: usuarios){
        if(user != nullptr){
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