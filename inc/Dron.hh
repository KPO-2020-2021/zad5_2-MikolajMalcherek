#ifndef DRON_HH
#define DRON_HH


#include "prostopadloscian.hh"
#include "skrzydla_drona.hh"
#include "lacze_do_gnuplota.hh"
#include "unistd.h"   //potrzebna do animacji przesuwania drona ( do usleep() )



/*! \brief 
*
* Aby uniknac coraz wiekszego bledu podczas obracania drona bedzie trzeba dzialac na jego kopii
*
*
 */


class Dron
{
    PzG::LaczeDoGNUPlota &Lacze;
    Matrix3x3 macierz_obrotu;
    Vector3D przebyta_droga; // zmienna potrzebna do metody oblicz_trase
    prostopadloscian oryginal;  // do oryginalu bedziemy sie odwolywac, natomiast kopia bedzie rysowana
    prostopadloscian kopia_widoczna_na_ekranie;
    int numer_drona;
    skrzydla oryginal_smigla[4];
    skrzydla kopia_smigla[4];
    double kat; // program musi zapamietac kat o jaki jest obrocony dron
    std::vector<Vector3D> droga_przebyta_przez_drona;

public:

        Dron(int numer_drona,PzG::LaczeDoGNUPlota &Lacze,Vector3D wektor_przemieszczenia);
        void przesuwanie(double przebyta_droga);
        void obracanie(double kat); // w stopniach
        void zapisz(); // zapisywaniie wszystkich elementow drona
        void kierowanie();
        void obrot_smigiel();
        void podnies_drona(double przebyta_droga);
        void oblicz_trase(double trasa);
};








#endif
