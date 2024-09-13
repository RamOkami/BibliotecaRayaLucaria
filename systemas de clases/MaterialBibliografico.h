#pragma one
#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#include <iostream>
using namespace std;

class MaterialBibliografico{
private:
    string nombre, autor;
    int isbn;
    bool prestado;

public:
    MaterialBibliografico(string, int, string, bool);
    virtual void mostrarInformación();
    int getId();
    string getTitulo();
    string getAutor();
    bool getEstado();
    void setEstado(bool);
};

#endif