#include "Plaskowyz.hh"
#include "Vector.hh"



/** \brief Konstruktor parametryczny klasy Plaskowyz
 * 
 * @return Plaskowyz
 */


Plaskowyz::Plaskowyz(Vector3D wspol_srodka, double dlugosc_x ,double wysokosc_y, double glebokosc_z,std::string nazwa)
{
    this->wspol_srodka=wspol_srodka;
    Vector3D wspolrzedne;


//this->nazwa jest to nazwa z klasy Bryla
    this->nazwa=nazwa;


    double tab[]={dlugosc_x,wysokosc_y,glebokosc_z};
    dlugosci = std::make_shared<Vector3D> (tab);

    wspolrzedne[0]=wspol_srodka[0]-(dlugosc_x/2);
    wspolrzedne[1]=wspol_srodka[1]+(wysokosc_y/2);
    wspolrzedne[2]=wspol_srodka[2]+(glebokosc_z/2);
    wspol_wierzholkow.push_back(wspolrzedne);

    wspolrzedne[0]=wspol_srodka[0]-(dlugosc_x/2);
    wspolrzedne[1]=wspol_srodka[1]+(wysokosc_y/2);
    wspolrzedne[2]=wspol_srodka[2]-(glebokosc_z/2);
    wspol_wierzholkow.push_back(wspolrzedne);




    wspolrzedne[0]=wspol_srodka[0]+(dlugosc_x/2);
    wspolrzedne[1]=wspol_srodka[1]+(wysokosc_y/2);
    wspolrzedne[2]=wspol_srodka[2]+(glebokosc_z/2);
    wspol_wierzholkow.push_back(wspolrzedne);

    wspolrzedne[0]=wspol_srodka[0]+(dlugosc_x/2);
    wspolrzedne[1]=wspol_srodka[1]+(wysokosc_y/2);
    wspolrzedne[2]=wspol_srodka[2]-(glebokosc_z/2);
    wspol_wierzholkow.push_back(wspolrzedne);




    wspolrzedne[0]=wspol_srodka[0]+(dlugosc_x/2);
    wspolrzedne[1]=wspol_srodka[1]-(wysokosc_y/2);
    wspolrzedne[2]=wspol_srodka[2]+(glebokosc_z/2);
    wspol_wierzholkow.push_back(wspolrzedne);

    wspolrzedne[0]=wspol_srodka[0]+(dlugosc_x/2);
    wspolrzedne[1]=wspol_srodka[1]-(wysokosc_y/2);
    wspolrzedne[2]=wspol_srodka[2]-(glebokosc_z/2);
    wspol_wierzholkow.push_back(wspolrzedne);




    wspolrzedne[0]=wspol_srodka[0]-(dlugosc_x/2);
    wspolrzedne[1]=wspol_srodka[1]-(wysokosc_y/2);
    wspolrzedne[2]=wspol_srodka[2]+(glebokosc_z/2);
    wspol_wierzholkow.push_back(wspolrzedne);

    wspolrzedne[0]=wspol_srodka[0]-(dlugosc_x/2);
    wspolrzedne[1]=wspol_srodka[1]-(wysokosc_y/2);
    wspolrzedne[2]=wspol_srodka[2]-(glebokosc_z/2);
    wspol_wierzholkow.push_back(wspolrzedne);

}


/** \brief Konstruktor kopiujacy klasy Plaskowyz
 * 
 * @return Plaskowyz
 */


