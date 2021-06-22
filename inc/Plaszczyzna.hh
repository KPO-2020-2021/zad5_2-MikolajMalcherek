#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH


#include "Matrix3x3.hh"
#include <fstream>
#include "Vector3D.hh"
#include <vector>




//klasa ta jest tworzona na podobnej zasadzie co klasa Bryla(jest to jakby bryla z zerowa gruboscia)

class Plaszczyzna
{
protected:
    std::vector<Vector3D> wspol_wierzcholkow;
    std::string nazwa;
   int ile_linii; // przydatne do funkcji zapisu plaszczyzny, aby policzyc ile mamy prostych
public:
    Plaszczyzna(Vector3D wymiary=Vector3D(),int gestosc_siatki=15, std::string nazwa="../dat/plaszczyzna.dat");

    Vector3D &operator[](int index);
    Vector3D operator[](int index) const;

    void ustaw_nazwe(std::string nazwa);
    std::string wyslij_nazwe() const;

    void zapisz();
};


#endif