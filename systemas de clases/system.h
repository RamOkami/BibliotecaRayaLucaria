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

void ordenarBiblioteca();
bool hayEspacio();
string upperletters(string);

#endif