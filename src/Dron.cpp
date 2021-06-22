#include "Dron.hh"





Dron::Dron(int numer_drona,PzG::LaczeDoGNUPlota &Lacze, Vector3D polozenie_drona) : Lacze(Lacze)
{
    this->numer_drona=numer_drona;
    oryginal.ustawianie_nazwy_bryly("../dat/bateria"+std::to_string(numer_drona)+".dat");

    for (int i = 0; i < 4; i++)
    {
        oryginal_smigla[i].ustawianie_nazwy_bryly("../dat/smiglo" + std::to_string(i) + std::to_string(numer_drona) + ".dat");
    }
    Lacze.DodajNazwePliku(oryginal.wysylanie_nazwy_bryly().c_str());

        for (int i = 0; i < 4; i++)
        {
        Lacze.DodajNazwePliku(oryginal_smigla[i].wysylanie_nazwy_bryly().c_str());
        }


        kopia_widoczna_na_ekranie=oryginal;

        kopia_widoczna_na_ekranie.przemieszczenie(polozenie_drona);
        for (int i = 0; i < 4; i++)
        {
        kopia_smigla[i] = oryginal_smigla[i];
        }

        
        for (int i = 0; i < 4; i++)
        {
        kopia_smigla[i].przemieszczenie(oryginal[i*2] + polozenie_drona);
        }
        przebyta_droga = przebyta_droga + polozenie_drona;
}



void Dron::przesuwanie(double przebyta_droga)
{
    Vector3D droga;
    droga[0] = przebyta_droga*cos(kat*M_PI/180);
    droga[1] = przebyta_droga*sin(kat*M_PI/180);
    // dla wspolrzednych z nie zmieniamy wartosci, wiec nic jej nie przypisujemy;


    this->przebyta_droga = this->przebyta_droga+droga;
    kopia_widoczna_na_ekranie.obrot(macierz_obrotu);
    kopia_widoczna_na_ekranie.przemieszczenie(this->przebyta_droga);



}

void Dron::obracanie(double kat) // w stopniach
{
    this->kat += kat;
    Matrix3x3 tmp;
    macierz_obrotu = tmp * Wypelnianie_macierzy_OZ(this->kat);
    kopia_widoczna_na_ekranie.obrot(macierz_obrotu);
    kopia_widoczna_na_ekranie.przemieszczenie(this->przebyta_droga);
}


void Dron::zapisz()
{
kopia_widoczna_na_ekranie.zapis_bryly();
    for (int i = 0; i < 4; i++)
    {
        kopia_smigla[i].zapis_bryly();
    }
} // zapisywaniie wszystkich elementow drona



/*! \brief 
Aby sprawdzic, czy dron sie przesuwa


 */
void Dron::kierowanie()
{
    
    int zmienna = 1;
    double droga;
    double kat;
    
    char wybor;
    std::cout << "|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|" << std::endl;
    std::cout << "|                   Wybierz opcje                   |" << std::endl;
    std::cout << "| p - przesuwanie o zadana droge                    |"<< std::endl;
    std::cout << "| o - obrot o zadany kat                            |" << std::endl;
    std::cout << "|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|" << std::endl;
    std::cin>>wybor;
    switch (wybor)
    {
    case 'p':
    
        std::cout<<"Podaj o ile sie przesunac: ";
        std::cin>>droga;

        

        Lacze.DodajNazwePliku("../dat/przebytadroga.dat");

        oblicz_trase(droga);

        for(int i=0; i<100 ; i++)  //animacja przesuwania sie co jeden, odpowiednio opozniona, aby efekt byl widoczny
        {
            kopia_widoczna_na_ekranie = oryginal;
            
                
                for(int i = 0; i<4;i++)
                {
                kopia_smigla[i]=oryginal_smigla[i];
                }
            podnies_drona(1);
            obrot_smigiel();
            zapisz();
            Lacze.Rysuj();
            usleep(20000);
        }

        for (int i = 0; i < droga; i++)
        {
            kopia_widoczna_na_ekranie = oryginal;


            for (int j = 0; j < 4; j++)
                kopia_smigla[j] = oryginal_smigla[j];
            przesuwanie(1);
            obrot_smigiel();
            zapisz();
            Lacze.Rysuj();
            usleep(20000);
        }

        

        for (int i = 0; i < 100; i++)
        {
            kopia_widoczna_na_ekranie = oryginal;
            for (int j = 0; j < 4; j++)
                kopia_smigla[j] = oryginal_smigla[j];
            podnies_drona(-1);
            obrot_smigiel();
            zapisz();
            Lacze.Rysuj();
            usleep(20000);

        }

        Lacze.UsunNazwePliku("../dat/przebytadroga.dat");
        break;




        case 'o':
        
        std::cout<<"Podaj kat: ";
        std::cin>>kat;
        
            if(kat>0) 
            zmienna=-1;
            for(int i=0; i<abs(kat); i++)  //animacja obrotu co jeden, odpowiednio opozniona, aby efekt byl widoczny
            {
                kopia_widoczna_na_ekranie = oryginal;
                for(int j=0; j < 4 ; j++)
                    kopia_smigla[j]=oryginal_smigla[j];
                obracanie(zmienna);
                obrot_smigiel();
                zapisz();
                Lacze.Rysuj();
                usleep(20000);
            }
            

            
    
        break;
    
    default:
        break;
    }

}




/*! \brief 
Obraca smigla


 */
void Dron::obrot_smigiel()
{
    static int kat = 0;
    kat += 3;
    if(kat==360)
    kat=0;

    Matrix3x3 macierz;
    macierz=macierz*Wypelnianie_macierzy_OZ(kat);

    for (int i = 0; i<4 ; i++)
    {
        kopia_smigla[i].obrot(macierz);
    }

    for(int j=0 ; j<4 ; j++)
    {
        kopia_smigla[j].przemieszczenie(kopia_widoczna_na_ekranie[j*2]);
    }
}





/*! \brief 
Podnies_drona



 */
void Dron::podnies_drona(double droga)
{
    Vector3D droga_tmp;
    droga_tmp[2]=droga;

    this->przebyta_droga = this->przebyta_droga + droga_tmp;

    kopia_widoczna_na_ekranie.obrot(macierz_obrotu);
    kopia_widoczna_na_ekranie.przemieszczenie(przebyta_droga);

}




/*! \brief 




 */
void Dron::oblicz_trase(double trasa)
{
    Vector3D wek = kopia_widoczna_na_ekranie.wysylanie_wspol_srodka();
    wek[2]=0;
    droga_przebyta_przez_drona.push_back(wek);
    wek[2] = 100;
    droga_przebyta_przez_drona.push_back(wek);
    wek[0] += trasa * cos(kat * M_PI /180);
    wek[1] += trasa * sin(kat * M_PI /180);
    droga_przebyta_przez_drona.push_back(wek);
    wek[2]=0;
    droga_przebyta_przez_drona.push_back(wek);


    std::fstream plik_z_droga;

    plik_z_droga.open("../dat/przebytadroga.dat", std::ios::out);

    for(int i = 0 ; i<(int)droga_przebyta_przez_drona.size(); i++)
    {
        plik_z_droga << droga_przebyta_przez_drona[i] << std::endl;
    }


    plik_z_droga.close();




}