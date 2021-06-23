#ifndef SKRZYDLA_DRONA_HH
#define SKRZYDLA_DRONA_HH

#include "Bryla.hh"



 /*! \brief  
        skrzydla drona maja byc w ksztalcie graniastoslupa szesciokatnego
    */

class skrzydla : public Bryla
{
    public:

    /*! \brief  
        konstruktor parametryczny, przyjmuje wspolrzedne srodka oraz promien, 
        na podstawie tych danych obliczane sa wspolrzedne wszystkich wierzcholkow graniastoslupa
        wzory:
        x_i = r * cos(kat * i) + przesuniecie o x-owa srodka
        y_i = r * sin(kat * i) + przesuniecie o y-owa srodka

        @param srodek 
        @param promien_r
    
    */
    skrzydla(Vector3D srodek=Vector3D(), double glebokosc_z=30, double promien_r = 20, std::string nazwa = "../dat/skrzydla.dat");

};













#endif