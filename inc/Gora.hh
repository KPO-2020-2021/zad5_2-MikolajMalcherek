#ifndef Gora_HH
#define Gora_HH

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




/** \brief definiujemy klase Gora, ktora dziedziczy klase bryla, jesli dziedziczymy klase i wpiszemy public, 
 * wszeyskie metody, zmienne itd. zostana odziedziczone tak samo jak jest to w klasie oryginalnej
 * (to co prywatne to bedzie prywatne, co publiczne co publiczne itd.)
 * klase Gora tworzymy na podstawie klasy Plaskowyz 
 *
 */

class Gora : public Bryla
{

public:

/** \brief konstruktor parametryczny klasy Gora
 * 
 *
 */

Gora(Vector3D wspol_srodka=Vector3D(), double dlugosc_x=150 , double wysokosc_y=80, double glebokosc_z=200, std::string nazwa="../dat/Gora.dat");
Gora( Gora& pr );
Gora &operator=(const Gora &other)
    {
     dlugosci=other.dlugosci;
    wspol_wierzholkow=other.wspol_wierzholkow;
    wspol_srodka=other.wspol_srodka;
    nazwa=other.nazwa;
        return *this;
    }

};


#endif 