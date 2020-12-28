#pragma once
#include "SmallSquare.h"
#include "Vector.h"
#include "RVektor.h"
#include "RMatrix.h"
class Shape9Plate
{
private:
	double platesizeX; //length of the sides of the plate
	double platesizeY; //length of the sides of the plate
	double platesize;//length of the sides of the plate
	int nN; //total number of SmallSquares
	int nX; //number of squares in x-direction must be a odd number
	int nY; // number of squares in y-direction
	int nd;
	double startptX;
	double startptY;
	RMatrix AMat;

public:
	Vektor<SmallSquare> Plate_9;
	Shape9Plate();
	~Shape9Plate();
	void CreatePlate(int nX, int nY, double distance, double plateXsize, double plateYsize, int GnN);//This will fillup the vektor with small squares
	Vektor<SmallSquare> & GetPlate() { return Plate_9; };
	int GetDiam() { return nN; };
	int GetYDiam() { return nY; };
	double GetPlateSize() { return platesize; };
	double GetPlateSizeX() { return platesizeX; };
	double GetPlateSizeY() { return platesizeY; };
};

