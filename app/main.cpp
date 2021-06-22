// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>



#include "exampleConfig.h"
#include "example.h"
#include "Matrix.hh"
#include "Vector.hh"
#include "Vector3D.hh"
#include "Matrix3x3.hh"
#include "prostopadloscian.hh"
#include "Scena.hh"
#include "Bryla.hh"
#include "skrzydla_drona.hh"
#include "Dron.hh"
#include "../inc/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150


int main() {
Scena plansza;
Vector3D wektor_test;

wektor_test.info();
while(plansza.opcje())
{
    plansza.rysowanie();
    wektor_test.info();
}
} 

