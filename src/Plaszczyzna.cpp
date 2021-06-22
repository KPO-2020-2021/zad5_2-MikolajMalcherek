
#include "Plaszczyzna.hh"

Plaszczyzna::Plaszczyzna(Vector3D dlugosci,int gestosc_kratek, std::string nazwa)
{
    this->nazwa = nazwa;
    double tablica[3];
    ile_linii = 0;

    for(int i = -dlugosci[0]/2 ; i< dlugosci[0]/2 ; i += gestosc_kratek)
    {
        for(int j = -dlugosci[1]/2 ; j< dlugosci[1]/2 ; j += gestosc_kratek)
        {

        tablica[0]=i;
        tablica[1]=j;

        wspol_wierzcholkow.push_back(tablica);
        }
        ile_linii++;
    }
}


Vector3D &Plaszczyzna::operator[](int indeks)
{
    return wspol_wierzcholkow[indeks];
}


Vector3D Plaszczyzna::operator[](int indeks) const
{
    return wspol_wierzcholkow[indeks];
}


std::string Plaszczyzna::wyslij_nazwe() const
{
    return nazwa;
}

void Plaszczyzna::ustaw_nazwe(std::string nazwa)
{
    this->nazwa = nazwa;
}

void Plaszczyzna::zapisz()
{
    fstream plik;

    plik.open(nazwa , ios::out);

    for(int i = 0 ; i < (int)wspol_wierzcholkow.size() ; i++ )
    {
        if(i%ile_linii==0)
        plik<<endl;
        plik<<wspol_wierzcholkow[i]<<endl;

    }
    plik.close();
}