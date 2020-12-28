#pragma once
#include "SmallSquare.h"
#include "Vector.h"
#include "RVektor.h"
#include "RMatrix.h"
class BasePlate
{
private:
	double platesize; //length of the sides of the plate
	int nN; //total number of SmallSquares
	int nX; //number of squares in x-direction must be a odd number
	int nY; // same number in y-direction

	double startpt;
	RMatrix HMat;

public:
	Vektor<SmallSquare> BPlate;
	BasePlate();
	~BasePlate();
	void CreatePlate(int nX, int nY);//This will fillup the vektor with small squares
	Vektor<SmallSquare>& GetPlate() { return BPlate; };
	int GetDiam() { return nN; };
	int GetYDiam() { return nY; };
	double GetPlateSize() { return platesize; };
};

