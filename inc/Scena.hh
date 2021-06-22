#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <filesystem>
#include <vector>
#include <memory>
#include <list>


#include "Vector.hh"
#include "Matrix.hh"
#include "Matrix3x3.hh"
#include "prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"


#define ILOSC_DRONOW 3

class Scena
{
    // tworzymy liste korzystajac z biblioteki <list>, lista przechowuje inteligentne wskazniki typu Bryla
    std::list<std::shared_ptr<Bryla>> Lista_przeszkod;
    std::list<std::shared_ptr<Dron>> Lista_dronow;
    PzG::LaczeDoGNUPlota Lacze;

    int numer_elementu;
    int numer_drona;
    Dron *tablica_dronow[ILOSC_DRONOW]; //tablica dronow
    Plaszczyzna *spod;
    public:
    Scena(); //konstruktor bezparametryczny
    
/*!
 * \brief Funkcja opcje()
 *
 * dzieki temu bedziemy dostawac sie do sterowania dronem, bool zwraca true albo false
 */
    bool opcje();



/*!
 * \brief Funkcja rysowanie()
 *
 * funkcja ktora bedzie rysowala cala scene
 */
    void rysowanie();  

/*!
 * \brief Funkcja rysowanie()
 *
 * destruktor
 */
~Scena();

};