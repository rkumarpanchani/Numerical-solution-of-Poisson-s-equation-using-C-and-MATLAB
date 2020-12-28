// Shape9Structure.cpp will defines the entry point for the console application
#include "stdafx.h"
#include "Cmplx.h"
#include <stdio.h>
#include <iostream>
#include "RVektor.h"
#include "RMatrix.h"
#include "SmallSquare.h"
#include "TwoPlates9.h"
using namespace std;	

int _tmain(int argc, _TCHAR* argv[])
{
	//Plate9 has been declared here
	TwoPlates9 Plate9;
	int row;
	double plateDistance;
	double sizeofPlate = 0.16;

	//Reads the value for the num of plates to be created
	cout << "\n**************************NUMERICAL SOLUTION OF POISSON'S EQUATION WITH 9 SHAPE STRUCTURE******************************\n\n";
	
	cout << "\nCharge Distribution of Ground Plane i.e. 100mm * 160mm\n";

	cout << "\nSince, we assumed 1 box is equivalent to 4 smaller boxes, therefore, hit 4 number";
	cout << "\n";
	cin >> row;
	getchar();
	
	cout << "\n**********************************************************************\n";
	
	//Sets the value of the number of small square plate for further calculations.
	Plate9.SetPlateAndPlaneSize(row);
	
	//Reads the value for the distance betwen two plates
	cout << "\nEnter the distance between two plates in mm (5, 10, 15, 20, 25)\n";
	cout << "\n";
	cin >> plateDistance;
	getchar();
		
	//Create the plate structure depending on the number of small square plate and distance between them
	plateDistance = plateDistance / 1000;
	Plate9.CreateStructure(plateDistance);

	//Creates the total Matrix considering all the charges on each plate.
	Plate9.CreateMatrix();

	//Function defining the boundary condition on the structure.Create the Excitation Vector
	Plate9.CreateExcitationVector();

	//Calculates the Charge Distribution on the entire structure
	Plate9.FindChargeDistribution();

	//Calculates the total charges on the entire structure
	Plate9.CalculateTotalCharge();
	
	//Calculates the total capacitance
	Plate9.CalculateCapacitance();

	cout << "\nPress enter key to exit the execution.........\n";
	cout << "\n**********************************************************************\n";

	cin.get();
	return 0;
}
