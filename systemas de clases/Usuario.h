#pragma one
#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include "MaterialBibliografico.h"

using namespace std;
class Usuario{
private:
    string nombre;
    int id;
    //Una lista de punteros del tipo MaterialBibliografico
    MaterialBibliografico* MaterialesPrestados[5] = {nullptr};
public:
    Usuario(string, int);
    void prestarMaterial(MaterialBibliografico*);
    void devolverMaterial(MaterialBibliografico*);
    void mostrarMaterialesPrestados();
    string mostrarLista();

    string getNombre();
    int getId();
    void mostrarInformacion();

    bool verificadorLista();
    void ordenarLista();
    int buscarLibro(MaterialBibliografico*);
    ~Usuario();
};

#endif