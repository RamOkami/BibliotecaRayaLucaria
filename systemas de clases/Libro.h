#pragma one
#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include "MaterialBibliografico.h"
using namespace std;

class Libro : public MaterialBibliografico{
private:
    string fechaPublicacion, resumen;
public:
    Libro(string, int, string, bool, string, string);
    void mostrarInformacion() override;
    ~Libro() override;
};

#endif