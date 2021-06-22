#include "Macierz4x4.hh"


/**
 * Macierz 4x4 zawierajaca katy potrzebne do obortu oraz zmienna typu Vector3D 
*/

Matrix4x4 Wypelnianiemacierzy4x4(double alphaX, double betaY, double gammaZ, Vector3D obrot){
    Matrix4x4 combined_matrix;

    for (unsigned int i = 0; i < 4; ++i)
        combined_matrix(i,i) = 0; 
        
    double katX = alphaX * M_PI / 180.0, katY = betaY * M_PI / 180.0, katZ = gammaZ * M_PI / 180.0;

    combined_matrix(0,0) = cos(katZ) * cos(katY); 
    combined_matrix(0,1) = cos(katZ) * sin(katY) * sin(katX) - sin(katZ) * cos(katX); 
    combined_matrix(0,2) = cos(katZ) * sin(katY) * cos(katX) + sin(katZ) * sin(katX); 
    combined_matrix(0,3) = obrot[0];
  
    combined_matrix(1,0) = sin(katZ) * cos(katY); 
    combined_matrix(1,1) = sin(katZ) * sin(katY) * sin(katX) + cos(katZ) * cos(katX); 
    combined_matrix(1,2) = sin(katZ) * sin(katY) * cos(katX) - cos(katZ) * sin(katX); 
    combined_matrix(1,3) = obrot[1];

    combined_matrix(2,0) = -sin(katY);
    combined_matrix(2,1) = cos(katY) * sin(katX);
    combined_matrix(2,2) = cos(katY) * cos(katX);
    combined_matrix(2,3) = obrot[2];
  
    combined_matrix(3,3) = 1;

    return combined_matrix;
}