#pragma once

#include "Matrix.hh"
#include "Vector3D.hh"

typedef Matrix<4> Matrix4x4;


Matrix4x4 Wypelnianiemacierzy4x4(double alphaX, double betaY, double gammaZ, Vector3D obrot);