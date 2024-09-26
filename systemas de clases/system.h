#pragma one
#ifndef SYSTEM_H
#define SYSTEM_H

#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"

#include <iostream>
using namespace std;

void menuGlobal();
void agregarMaterial();
void ingresoDatos(int);
void mostrarMateriales();
void buscarMaterial();
void buscador(string, bool);
bool materialAux(string);
void opcionesMaterial();
void prestarMaterial();
void devolverMaterial();
void gestionUsuarios();
void gestionDatos();
void addUser();
bool buscarUsuario(int, bool);
void deleteUser();

void cargaMateriales();
void cargaUsuarios();

MaterialBibliografico* materialObj(string);
Usuario* usuarioObj(int);
void ordenarBiblioteca();
bool hayEspacio();
bool hayEspacioUsers();
string upperletters(string);
void deleteTxt(string, string);
void escribirTxt(string, string);
void sobreescribirTxt(string, string, string);
void destructores();
#endif