#pragma one
#ifndef REVISTA_H
#define REVISTA_H

#include <iostream>
#include "MaterialBibliografico.h"
using namespace std;

class Revista : public MaterialBibliografico{
private:
    int numeroEdicion;
    string mesPublicacion;
public:
    Revista(string, int, string, bool, int, string);
    void mostrarInformación() override;
};

#endif