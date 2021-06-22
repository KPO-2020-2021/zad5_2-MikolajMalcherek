#include "Matrix3x3.hh"


/**         
 * Wypelniamy macierz 3x3 potrzebna do obrotu figury wokol osi OX o zadany kat  
      
  Macierz potrzebna do obrotu wokol osi OZ
*/

Matrix3x3 Wypelnianie_macierzy_OX (double kat){
    Matrix3x3 macierz_rotacji;
    double kat_w_radianach = kat* M_PI / 180.0;
    macierz_rotacji(0,0) = 1;
    macierz_rotacji(0,1) = 0;
    macierz_rotacji(0,2) = 0;
    macierz_rotacji(1,0) = 0;
    macierz_rotacji(1,1) = cos(kat_w_radianach);
    macierz_rotacji(1,2) = -sin(kat_w_radianach);
    macierz_rotacji(2,0) = 0;
    macierz_rotacji(2,1) = sin(kat_w_radianach);
    macierz_rotacji(2,2) = cos(kat_w_radianach);
    return macierz_rotacji;
}


/**         
 * Wypelniamy macierz 3x3 potrzebna do obrotu figury wokol osi OY o zadany kat 

  Macierz potrzebna do obrotu wokol osi OZ
*/
Matrix3x3 Wypelnianie_macierzy_OY (double kat){
    Matrix3x3 macierz_rotacji;
    double kat_w_radianach = kat * M_PI / 180.0;
    macierz_rotacji(0,0) = cos(kat_w_radianach);
    macierz_rotacji(0,1) = 0;
    macierz_rotacji(0,2) = sin(kat_w_radianach);
    macierz_rotacji(1,0) = 0;
    macierz_rotacji(1,1) = 1;
    macierz_rotacji(1,2) = 0;
    macierz_rotacji(2,0) = -sin(kat_w_radianach);
    macierz_rotacji(2,1) = 0;
    macierz_rotacji(2,2) = cos(kat_w_radianach);
    return macierz_rotacji;
}

/**
  Macierz potrzebna do obrotu wokol osi OZ
*/


Matrix3x3 Wypelnianie_macierzy_OZ (double angle){
    Matrix3x3 rotation_matrix;
    double angle_radians = angle * M_PI / 180.0;
    rotation_matrix(0,0) = cos(angle_radians);
    rotation_matrix(0,1) = -sin(angle_radians);
    rotation_matrix(0,2) = 0;
    rotation_matrix(1,0) = sin(angle_radians);
    rotation_matrix(1,1) = cos(angle_radians);
    rotation_matrix(1,2) = 0;
    rotation_matrix(2,0) = 0;
    rotation_matrix(2,1) = 0;
    rotation_matrix(2,2) = 1;
    return rotation_matrix;
}
