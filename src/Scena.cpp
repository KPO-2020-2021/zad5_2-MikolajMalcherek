#include "Scena.hh"
#include "Plaskowyz.hh"
#include "lacze_do_gnuplota.hh"
#include "Rampa.hh"
#include "Gora.hh"


Scena::Scena()
{

    Lacze.ZmienTrybRys(PzG::TR_3D);

    Lacze.UstawZakresY(-500,500);
    Lacze.UstawZakresX(-500,500);
    Lacze.UstawZakresZ(-500,500);

    numer_drona=0;
    numer_elementu=6;
   

    double tablica_wymiarow[3]={1000,1000,0};
    Vector3D wymiary_spodu(tablica_wymiarow);
    spod = new Plaszczyzna(wymiary_spodu,25);


    Vector3D srodek_przeszkody;
    for(int i=0 ; i<4 ; i++)

    srodek_przeszkody[0]=rand()%450-225;
    srodek_przeszkody[1]=rand()%450-225;
    srodek_przeszkody[2]=50;
    Lista_przeszkod.push_front(std::make_shared<Plaskowyz>(srodek_przeszkody, 100, 150 , 100 , "../dat/Plaskowyz1.dat"));

    srodek_przeszkody[0]=rand()%450-225;
    srodek_przeszkody[1]=rand()%450-225;
    srodek_przeszkody[2]=50;
    Lista_przeszkod.push_front(std::make_shared<Gora>(srodek_przeszkody, 150, 80 , 100 , "../dat/Gora1.dat"));
    
    srodek_przeszkody[0]=rand()%450-225;
    srodek_przeszkody[1]=rand()%450-225;
    srodek_przeszkody[2]=50;
    Lista_przeszkod.push_front(std::make_shared<Rampa>(srodek_przeszkody, 230, 150 , 100 , "../dat/Rampa1.dat"));



    for(std::list<std::shared_ptr<Bryla>>::const_iterator a=Lista_przeszkod.begin() ; a != Lista_przeszkod.end(); a++)
    {
        Lacze.DodajNazwePliku((*a)->wysylanie_nazwy_bryly().c_str());
        (*a)->zapis_bryly();
    }


    Lacze.DodajNazwePliku(spod->wyslij_nazwe().c_str());
    spod->zapisz();


    for(int i=0; i<ILOSC_DRONOW; i++)
{
    double polozenie[3]={(double)(rand()%900-450),(double)(rand()%900-450),15}; // losujemy pozycje startowa drona
    tablica_dronow[i] = new Dron(i, Lacze, Vector3D(polozenie) );
    tablica_dronow[i]->zapisz();
    numer_drona++;
}


    Lacze.Rysuj();
}



// interfejs wyswietlajacy sie przy odpaleniu programu
bool Scena::opcje()
{




    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
    std::cout << "@              Wybierz opcje:              @" << std::endl;
    std::cout << "@    1 -wybierz drona                      @" << std::endl;
    std::cout << "@    2 - dodaj element do sceny            @" << std::endl;
    std::cout << "@    3 - usun element ze sceny             @" << std::endl;
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
    int opcja;
    std::cin >> opcja;
    int numer;
    
    switch (opcja)
    {
        case 1:
        {
            cout << "Wybierz drona wpisujac numer 0,1 lub 2: " << endl;
    std::cin>>numer;
    if(numer<ILOSC_DRONOW)
    {
        tablica_dronow[numer]->kierowanie();   
    }
    else
    {
        return false;
    }

    return true;
        }// case 1
    
    break;
        case 2:
        {
        cout << "Dodawanie elementu do sceny: " << endl;
        cout << "1 - plaskowyz" << endl;
        cout << "2 - gora" << endl;
        cout << "3 - rampa" << endl;
        cin >> numer;
        Vector3D srodek;

        srodek[0]=rand()%450-225;
        srodek[1]=rand()%450-225;
        srodek[2]=50;

    if(numer!=4)
    {
        if(numer==1)
        {
            Lista_przeszkod.push_front(std::make_shared<Plaskowyz>(srodek, 100, 150 , 100 , "../dat/Plaskowyz"+std::to_string(numer_elementu)+".dat"));
        }
        if(numer==2)
        {
            Lista_przeszkod.push_front(std::make_shared<Gora>(srodek, 150, 80 , 100 , "../dat/Gora"+std::to_string(numer_elementu)+".dat"));
        }
        if(numer==3)
        {
            Lista_przeszkod.push_front(std::make_shared<Rampa>(srodek, 230, 150 , 100 , "../dat/Rampa"+std::to_string(numer_elementu)+".dat"));
        }
        numer_elementu++;
        (*Lista_przeszkod.begin())->zapis_bryly();
        Lacze.DodajNazwePliku((*Lista_przeszkod.begin())->wysylanie_nazwy_bryly().c_str());
    }
    else
    {
        double pozycja_nowego_drona[3] = {(double)(rand() % 900 - 450), (double)(rand() % 900 - 450), 15};
        Lista_dronow.push_front(std::make_shared<Dron>(numer_drona, Lacze, Vector3D(pozycja_nowego_drona)));
        (*Lista_dronow.begin())->zapisz();
    }
    }//case 2
   
    break;

    case 3:
    {
    int zmienna=0;
    for (std::list<std::shared_ptr<Bryla>>::const_iterator a = Lista_przeszkod.begin(); a != Lista_przeszkod.end(); a++)
    {
      cout << zmienna << ": " << (*a)->wysylanie_nazwy_bryly() << endl;
      zmienna++;
    }

    cout << "Podaj numer przeszkody do usuniecia: " << endl;

    int numer_przeszkody;

    cin >> numer_przeszkody;
    std::list<std::shared_ptr<Bryla>>::const_iterator a = Lista_przeszkod.begin();

    for (int j = 0 ; j<numer_przeszkody ; j++)  // przesuwamy sie po elementach listy do momentu spotkania interesujacego nas numeru przeszkody
    {
        a++;
    }
    Lacze.UsunNazwePliku((*a)->wysylanie_nazwy_bryly());
    Lista_przeszkod.erase(a); // specjalna funkcja erase 
    }
    break;
}
return true;
}


Scena::~Scena()
{
    delete spod;
    for(int i ; i < ILOSC_DRONOW ; i++)
    delete tablica_dronow[i];
}

void Scena::rysowanie()
{
    Lacze.Rysuj();
}


