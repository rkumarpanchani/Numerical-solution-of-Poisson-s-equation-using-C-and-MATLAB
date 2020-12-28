#ifndef TWOPLLATESG_H
#define TWOPLATESG_H
#endif;
#ifndef VEKTOR_H
#include "Vector.h"
#endif

#ifndef SMALLSQUARE_H
#include "SmallSquare.h"
#include "RMatrix.h"
#endif
#include "Shape9Plate.h"
#include "BasePlate.h"
#pragma once
class TwoPlates9
{
private:

	double plateXsize; //length of the sides of plate in X-Direction
	double plateYsize; //length of the sides of plate in Y-Direction
	int nX; //number of Squares in X-Direction must be a multiple of 4
	int nY; //number of Squares in Y-Direction nY = nx * 5/8
	int nN; // Total number of SmallSquares
	int BnN;//total number of SmallSquares in Base plate
	int nN_9;//total number of SmallSquares in G-Shape plate

	BasePlate BPlate;
	Shape9Plate plate_9;

	Vektor <SmallSquare> vPlate; //Plate composed of SmallSquares
	Vektor<SmallSquare> bPlate1;
	Vektor<SmallSquare> _9Plate1;

	RMatrix TotalMat;
	RMatrix BMat;
	RMatrix GMat;


	RMatrix gMat; //Matrix of Coupling Coefficient between two plates
	RVektor gmVec; //Potential of each Small Square
	double potPlate_positive; //Positive Potential of the Square Plate
	double potPlate_negative; //Negative Potential of the Square Plate
	RVektor chargeVec; //Vector to store charge distribution
	RVektor chargeVecBase; //Vector to store charge distribution of base plate
	RVektor chargeVec9Structure; //Vector to store charge distribution of 9 structure
	double totalcharge; // Value of all the charges on plate
	double distance; //Distance between two plates
	double capacitance;



public:

	TwoPlates9();
	~TwoPlates9();
	void SetPlateAndPlaneSize(int numOfSquare);
	void CreateStructure(double distance);
	void CreateTwoPlates();
	void CreateMatrix();//Creates the Coupling Matrix
	void CreateExcitationVector();//Assigning potential to each small square
	void FindChargeDistribution(); //Calculates the charge distribution
	void CalculateTotalCharge(); //Sums up the charge distribution
	void CalculateCapacitance();

};
//--------------------------------





