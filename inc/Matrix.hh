#pragma once

#include "size.hh"
#include "Vector.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>


/** @brief Klasa Macierz.hh przechowujaca przeciazneia operatorow oraz metody dla macierzy

 * Macierze sluza do przechowywania kataw wewnatrz, ktore potrzebne sa do operacji obrotu
    @author Mikolaj Malcherek
    @date Maj 2020
    */





template <int Size>
class Matrix {

private:
    double value[Size][Size];               // Wartosci macierzy

public:
    Matrix(double [Size][Size]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector<Size> operator * (Vector<Size> tmp);           // Operator mnożenia przez wektor

    Matrix<Size> operator + (Matrix<Size> const &tmp);

    double  operator () (int row, int column) const;
    
    double &operator () (int row, int column);

    double wyznacznikgaussa();

    

    Matrix<Size> operator * (Matrix<Size> tmp);
};

template <unsigned int Size>
std::ostream & operator << (std::ostream &out, Matrix<Size> const &mat);  


template <unsigned int Size>
std::istream & operator >> (std::istream &in, Matrix<Size> &mat);        







/******************************************************************************
 |  Konstruktor klasy Matrix<Size>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template <int Size>
Matrix<Size>::Matrix() {
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
                if(i==j)
                {
                    value[i][j]=1;
                }
                else
                {
                    value[i][j] = 0;
                }
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix<Size>.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int Size>
Matrix<Size>::Matrix(double tmp[Size][Size]) {
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template <int Size>
Vector<Size> Matrix<Size>::operator *(Vector<Size> tmp) {
    Vector<Size> result;
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}



/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template <int Size>
double Matrix<Size>::operator()(int row, int column) const
{

    if (row >= Size) {
        throw "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= Size) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template <int Size>
double &Matrix<Size>::operator () (int row, int column) {

    if (row >= Size) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= Size) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template <int Size>
Matrix<Size> Matrix<Size>::operator + (Matrix<Size> const &tmp) {
    Matrix<Size> result;
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
template <int Size>
std::istream &operator>>(std::istream &in, Matrix<Size> &mat) {
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template <int Size>
std::ostream &operator<<(std::ostream &out, const Matrix<Size> &mat) {
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}








/*-------------------------------------------------------------------------------------------------------     
|                                                                                                        |
|       Obliczanie wyznacznika metoda Gaussa, w ktorej macierz stopniowo zamieniamy na diagonalna        |   
|                                                                                                        |
|--------------------------------------------------------------------------------------------------------*/
template <int Size>
double Matrix<Size>::wyznacznikgaussa()
{
     double ratio;
	 int i,j,k;


	 for(i=0;i<=Size-2;i++)
	 {
		  if(value[i][i] == 0.0)
		  {
			   std::cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(j=i+1;j<=Size;j++)
		  {
			   ratio = value[j][i]/value[i][i];

			   for(k=0;k<=Size;k++)
			   {
			  		value[j][k] = value[j][k] - ratio*value[i][k];
			   }
		  }
	 }

    for(int g=0;g<Size;g++)
    {
        for(int l=0;l<Size;l++)
        {
            std::cout << value[g][l] << " ";
        }
        std::cout << std::endl;
    }

    double wyznacznik = value[0][0];
    
    for (int h=0;h<Size;h++)
    {
        wyznacznik=value[h][h];
    }
    std::cout << wyznacznik ;
    return wyznacznik;
}








/*       Mnozenie macierzy przez macierz       */

template <int Size>
Matrix<Size> Matrix<Size>::operator * (Matrix<Size> tmp){
    Matrix<Size> result;
    for(int i = 0; i < Size; ++i){
        for(int j = 0; j < Size; ++j){    
            result(i,j) = 0;
            for(int k = 0; k < Size; ++k){
                result(i,j) +=  value[i][k] * tmp(k,j);
            }
        }
    }
    return result; 
}