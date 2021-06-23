#include "skrzydla_drona.hh"



/** \brief Konstruktor parametryczny klasy prostopadloscian
 * 
 * Podobnie jak w przypadku prostopadloscianu
 */



skrzydla::skrzydla(Vector3D srodek,double grubosc, double promien_r, std::string nazwa)
{
    double tab[]={0,0,grubosc};
    dlugosci=std::make_shared<Vector3D> (tab);
    //this->nazwa to zmienna z klasy Skrzydla odziedziczonej z klasy Bryla
    this->nazwa=nazwa;
    wspol_srodka=srodek;
    Vector3D wspolrzedne;

    for (int i = 0; i <360 ; i+=60)
    {
        wspolrzedne[0] = promien_r * cos(3.14*i/180); //funkcja cos przyjmuje katy w radianach dlatego trzeba je zmienic na stopnie
        wspolrzedne[1] = promien_r * sin(3.14*i/180);
        wspolrzedne[2] = wspol_srodka[2] + (grubosc/2);
        wspol_wierzholkow.push_back(wspolrzedne);

        wspolrzedne[0] = promien_r * cos(3.14*i/180); 
        wspolrzedne[1] = promien_r * sin(3.14*i/180);
        wspolrzedne[2] = wspol_srodka[2] - (grubosc/2);
        wspol_wierzholkow.push_back(wspolrzedne);
        
    }
    


}