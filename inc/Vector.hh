#pragma once

#include "size.hh"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <fstream>

using namespace std;

template <int Size>
class Vector{

private:

    double size[Size];     //Tablica wektora
    static int lacznie; // zmienne sluzace do zliczania wektorow
    static int aktualnie;

public:

    Vector();

    ~Vector(); // destruktor
    
    Vector(Vector<Size> &wektor)
    {
        for(int i = 0 ; i<Size ; i++)
        size[i]=wektor.size[i];

        aktualnie++;
    }

    constexpr Vector(const Vector &wektor)
    {
        for(int i = 0; i < Size; i++)
            size[i] = wektor.size[i];
        aktualnie++;
    }
    Vector &operator=(const Vector &wektor)     
    {
        for(int i = 0; i < Size; i++)
            size[i] = wektor.size[i];
        return *this;
    }

    Vector &operator=(const float &tmp)
    {
        for(int i=0 ; i<Size ; i++)
        {
            size[i]=tmp;
        }

            return *this;
    }

    Vector(double size[Size]);

    Vector<Size> operator + (Vector<Size> &v);

    Vector<Size> operator - (Vector<Size> &v);

    const double &operator [] (int index) const;

    double &operator [] (int index);

    void info();


};


    template <int Size>
    int Vector<Size>::lacznie = 0;

    template <int Size>
    int Vector<Size>::aktualnie = 0;





template <int Size>
void Vector<Size>::info()
{
    cout<<"Aktualnie obiektow: " << aktualnie << endl;
    cout << "Lacznie obiektow: " << lacznie << endl;
}


/******************************************************************************
 |  Konstruktor klasy Vector<Size>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <int Size>
Vector<Size>::Vector() {
    for (int i = 0; i < Size; ++i) {
        size[i] = 0;
        lacznie++;
        aktualnie++;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector<Size>.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int Size>
Vector<Size>::Vector(double tmp[Size]) {
    for (int i = 0; i < Size; ++i) {
        size[i] = tmp[i];
        lacznie++;
        aktualnie++;
    }
}



template <int Size>
Vector<Size>::~Vector()
    {
        aktualnie--;
    }





/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <int Size>
Vector<Size> Vector<Size>::operator + (Vector<Size> &v) {
    Vector<Size> result;
    for (int i = 0; i < Size; ++i) {
        result[i] = size[i] + v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int Size>
Vector<Size> Vector<Size>::operator - (Vector<Size> &v) {
    Vector<Size> result;
    for (int i = 0; i < Size; ++i) {
        result[i] = size[i] - v[i];
    }
    return result;
}




/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <int Size>
const double &Vector<Size>::operator [] (int index) const {
    if (index < 0 || index >= Size) {
        throw "Error: Wektor jest poza zasiegiem!" ;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <int Size>
double &Vector<Size>::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector<Size> *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template <int Size>
std::ostream &operator << (std::ostream &out, Vector<Size> const &tmp) {
    for (int i = 0; i < Size; ++i) {
        if(i%2==0){
            std::cout << std::endl;
        }
        out << tmp[i] << " ";
    }
    return out;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <int Size>
std::istream &operator >> (std::istream &in, Vector<Size> &tmp) {
    for (int i = 0; i < Size; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}



/*bool Vector<Size>::operator == (const Vector<Size> &v) {
    Vector<Size> result;
    for (int i = 0; i < Size; ++i) {
        if(v[i] != size[i])
            return false;
    }

    return true;
}*/
template <int Size>
 double length(const Vector<Size> &v1 , const Vector<Size> &v2)
 {
    double zmienna=0;
    for (int i = 0; i < Size; ++i)
        zmienna += pow(v2[i] - v1[i],2);
    return sqrt(zmienna);
 }

