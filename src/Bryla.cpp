#include "Bryla.hh"




/** \brief Metoda zwracajaca nazwe figury
 * 
 * @return nazwa bryly
 */


void Bryla::ustawianie_nazwy_bryly(std::string nazwa)
{
    this->nazwa = nazwa;
}

std::string Bryla::wysylanie_nazwy_bryly() const
{
    return nazwa;
}

/** \brief Metoda wpisujaca do bryly wspolrzedne jej srodka
 * 
 * @return wspol_srodka
 */


void Bryla::ustawianie_wspol_srodka(Vector3D srodek_bryly)
{
    wspol_srodka = srodek_bryly;
}


/** \brief Metoda zwracajaca wspolrzedne srodka bryly
 * 
 * @return wspol_srodka
 */


Vector3D Bryla::wysylanie_wspol_srodka() const
{
    return wspol_srodka;
}
   


/** \brief Metoda przemieszczenia bryly o dany wektor, petla powtarza sie tak duzo razy, ile jest wierzcholkow w bryle
 *ilosc wierzcholkow bryly mozna sprawdzic za pomoca wbudowanej funkcji size dla utworzonego kontenera danych w klasie Bryla.hh 
 *                           a nastepnie dokonujemy rzutowania na zmienna int otrzymanej wartosci
 * 
 * @return wspol_srodka
 */


void Bryla::przemieszczenie(Vector3D wek_przesuniecia)
{
        for(int i=0; i<(int)wspol_wierzholkow.size(); i++)
        {
            wspol_wierzholkow[i]=wspol_wierzholkow[i]+wek_przesuniecia;
        }
        wspol_srodka=wspol_srodka+wek_przesuniecia; // aby srodek przesuwal sie razem z cala bryla
}



void Bryla::obrot(Matrix3x3 macierz_obrotu)
{
      for(int i=0; i<(int)wspol_wierzholkow.size(); i++)
        {
            wspol_wierzholkow[i]= (macierz_obrotu* wspol_wierzholkow[i]);
        }
        wspol_srodka=macierz_obrotu*wspol_srodka;// aby srodek przesuwal sie razem z cala bryla
}







/** 
void Bryla::przemieszczenie_i_obrot(Vector3D wektor_przes,Matrix3x3 macierz_obrotu)
{
        for (int i = 0; i < (int)wspol_wierzholkow.size(); ++i)
        {
            wspol_wierzholkow[i] = (macierz_obrotu * wspol_wierzholkow[i]) + wektor_przes;
        }

}
*/



void Bryla::zapis_bryly()
{
    double tab[]={0, 0, (*dlugosci)[2]/2};
    Vector3D przesuniecie_srodka(tab);

    std::fstream plik_z_prostopadloscianem;
    //out oznaczna, ze jesli pliku nie ma to zostanie stworzony pusty plik, a jesli jest, to plik zostanie wyczyszczony i zostana wpisane do niego nowe dane
    plik_z_prostopadloscianem.open(nazwa, std::ios::out);
    



/*bryle rysujemy idac o polowe z do gory od srodka i przemieszczajac siedo srodka gornej ppodstawy i wierzcholka gorenj podstawy, z wierzcholka z gornej podstawy przechodzimy do wierzcholka dolnej podstawy i z niego do srodka dolnej podstawy */
    for(int i=0; i<(int)wspol_wierzholkow.size();i+=2)
    {
        plik_z_prostopadloscianem<<wspol_srodka+przesuniecie_srodka<<std::endl;
        for(int j=0;j<2;j++)
        {
            plik_z_prostopadloscianem<<wspol_wierzholkow[j+i]<<std::endl;
        }
        plik_z_prostopadloscianem<<wspol_srodka-przesuniecie_srodka<<std::endl<<std::endl;
    }

    //powtarzamy zapis pierwszej krawedzi jako ostatniej aby bryla sie zamknela
        plik_z_prostopadloscianem<<wspol_srodka+przesuniecie_srodka<<std::endl;
        for(int j=0;j<2;j++)
        {
            plik_z_prostopadloscianem<<wspol_wierzholkow[j]<<std::endl;
        }
        plik_z_prostopadloscianem<<wspol_srodka-przesuniecie_srodka<<std::endl<<std::endl;

    plik_z_prostopadloscianem.close();
}



Vector3D &Bryla::operator[](int numer_indeksu)
    {
        return wspol_wierzholkow[numer_indeksu];
    }
Vector3D Bryla::operator[](int numer_indeksu) const
    {
        return wspol_wierzholkow[numer_indeksu];
    }
