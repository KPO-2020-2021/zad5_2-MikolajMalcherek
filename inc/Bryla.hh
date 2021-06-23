#ifndef BRYLA_HH
#define BRYLA_HH

#include "Vector3D.hh"
#include "Matrix3x3.hh"
#include <vector>
#include <fstream>
#include <memory>

class Bryla
{
    protected:
        std::shared_ptr<Vector3D> dlugosci;
    std::vector<Vector3D> wspol_wierzholkow;    // tworzymy kontener zmiennych o nazwie wspol_wierzcholkow przetrzymujacy zmienne typu Vector3D
    Vector3D wspol_srodka;
    std::string nazwa; // tworzymy zmienna typu string nazwa tutaj, aby latwo odwolac sie pozniej do brył i wpisac im wartosci 


    public:

    Vector3D &operator[](int numer_indeksu);

    Vector3D operator[](int numer_indeksu) const;


    void ustawianie_nazwy_bryly(std::string nazwa);



    std::string wysylanie_nazwy_bryly() const;



    void ustawianie_wspol_srodka(Vector3D wspol_srodka); 
    Vector3D wysylanie_wspol_srodka() const;
   
    void przemieszczenie(Vector3D wek_przesuniecia);
    void obrot(Matrix3x3 macierz_obrotu);
    /*  Rozwiazanie z obrotow 3D

    void przemieszczenie_i_obrot(Vector3D wek_przesuniecia,Matrix3x3 macierz_obrotu);

    */


    void zapis_bryly();

   

};

/* Jesli chcemy odziedziczyc klase Bryla w pozniejszych fazach programu, musimy cos zrobic z utworzyonym powyzej kontenerem zmiennych, gdyż będąc 
              w sekcji prywatnej klasy podczas dziedziczenia klasy nie pobiora nam sie do nowej klasy wspolrzedne tych wierzcholkow
mozemy poprostu przeniesc nasz kontener do sekcji public lub wstawic nasze wierzcholki do sekcji protected, a to z kolei pozwoli nam na dziedziczenie,
                            ale nie pozwoli na odwylywanie sie do tych wierzcholkow w sposob, np. Bryla b; b.wspol_wierzcholkow                      
                                                                                                                                                        */

#endif