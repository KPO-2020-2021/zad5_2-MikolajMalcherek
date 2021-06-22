#ifndef Rampa_HH
#define Rampa_HH

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




/** \brief definiujemy klase Rampa, ktora dziedziczy klase bryla, jesli dziedziczymy klase i wpiszemy public, 
 * wszeyskie metody, zmienne itd. zostana odziedziczone tak samo jak jest to w klasie oryginalnej
 * (to co prywatne to bedzie prywatne, co publiczne co publiczne itd.)
 * klase Rampa tworzymy na podstawie klasy Plaskowyz 
 *
 */

class Rampa : public Bryla
{

public:

/** \brief konstruktor parametryczny klasy Rampa
 * 
 *
 */

Rampa(Vector3D wspol_srodka=Vector3D(), double dlugosc_x=230 , double wysokosc_y=150, double glebokosc_z=200, std::string nazwa="../dat/Rampa.dat");




};


#endif 