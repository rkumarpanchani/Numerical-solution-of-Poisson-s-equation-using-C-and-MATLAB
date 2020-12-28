#ifndef SMALLSQUARE_H
#define SMALLSQUARE_H
#include <iostream>
#include "RVektor.h"

#pragma once

class SmallSquare
{
private:
	double side;//Length of a side in meter
	RVektor rCenter; //Vector to the center of the square 
public:
	SmallSquare();
	~SmallSquare();
	double GetSide() const { return side; }; // Get the side value 
	RVektor GetCenter() const { return rCenter; };//Get the vector to center
	void SetSide(const double aSide) { side = aSide; }; //To assign value to vector
	void MoveTo(const RVektor& aVec) { rCenter = aVec; };//Moves the square to aVec
	void MoveTo(const double aX, const double aY);//move the square in xy plane
	void MoveToPlane(const double aX, const double aY, const double aZ);//move the squares in cutting plane
	void MoveToVer(const double aY, const double aZ);//move the square in yz plane
	double GetArea() const { return side*side; };//calculates the area of the square

	double CouplingCoefficient(const SmallSquare & aSq);//Calculates the coupling between squares
	double SelfCoupling(); //Coupling to itself
	double DistanceCoupling(const SmallSquare& aSq); //Coupling between difference squares
	bool IsSelfCoupling(const SmallSquare& aSq); //Same SmallSquare
};
std::ostream& operator<< (std::ostream& os, const SmallSquare& aSquare);
#endif