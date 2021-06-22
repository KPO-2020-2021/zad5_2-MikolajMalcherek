#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#include "size.hh"
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>


#include "Vector3D.hh"
#include "Matrix.hh"
#include "Matrix3x3.hh"
#include "lacze_do_gnuplota.hh"
#include "Bryla.hh"




/** \brief definiujemy klase Plaskowyz, ktora dziedziczy klase bryla, jesli dziedziczymy klase i wpiszemy public, 
 * wszeyskie metody, zmienne itd. zostana odziedziczone tak samo jak jest to w klasie oryginalnej
 * (to co prywatne to bedzie prywatne, co publiczne co publiczne itd.)
 * klasa Plaskowyz jest bardzo podobna do klasy prostopadloscian ze wzgledu na ksztalt 
 *
 */

class Plaskowyz : public Bryla
{

public:

/** \brief konstruktor parametryczny klasy Plaskowyz
 * 
 *
 */

Plaskowyz(Vector3D wspol_srodka=Vector3D(), double dlugosc_x=100 , double wysokosc_y=150, double glebokosc_z=100, std::string nazwa="../dat/Plaskowyz.dat");

~Plaskowyz(){delete dlugosci;}

};


#endif 