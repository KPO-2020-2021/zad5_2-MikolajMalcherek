#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

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




/** \brief definiujemy klase prostopadloscian, ktora dziedziczy klase bryla, jesli dziedziczymy klase i wpiszemy public, 
 * wszeyskie metody, zmienne itd. zostana odziedziczone tak samo jak jest to w klasie oryginalnej
 * (to co prywatne to bedzie prywatne, co publiczne co publiczne itd.)
 * 
 *
 */

class prostopadloscian : public Bryla
{

public:

/** \brief konstruktor parametryczny klasy prostopadloscian
 * 
 *
 */

prostopadloscian(Vector3D wspol_srodka=Vector3D(), double dlugosc_x=50 , double wysokosc_y=60, double glebokosc_z=30, std::string nazwa="../dat/prostopadloscian.dat");

   prostopadloscian &operator=(const prostopadloscian &other)
    {
    dlugosci=other.dlugosci;
    wspol_wierzholkow=other.wspol_wierzholkow;
    wspol_srodka=other.wspol_srodka;
    nazwa=other.nazwa;
        return *this;
    }

};


#endif 