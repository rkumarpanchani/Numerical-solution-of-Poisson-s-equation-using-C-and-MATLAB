
#include "stdafx.h"
#include <iostream>
#include "RVektor.h"
#ifndef SMALLSQUARE_H
#include "SmallSquare.h"
#endif

#include "Physicon.h"

SmallSquare::SmallSquare() 
{
	side = 0;

	//RVektor(0., 0., 0.), therefore, we have the x-axis, y-axis and z-axis
	rCenter = RVektor(0., 0., 0.);  
}


SmallSquare::~SmallSquare()
{

}

void SmallSquare::MoveTo(const double aX, const double aY) {
	RVektor aVec(aX, aY, 0.);
	MoveTo(aVec);
	//rCenter.SetX(aX);
	//rCenter.SetY(aY);
}


void SmallSquare::MoveToPlane(const double aX, const double aY, const double aZ) {
	RVektor aVec(aX, aY, aZ);
	MoveTo(aVec);
}
void SmallSquare::MoveToVer(const double aY, const double aZ) {
	RVektor aVec(0., aY, aZ);
	MoveTo(aVec);
}
bool SmallSquare::IsSelfCoupling(const SmallSquare& aSq) {
	return (rCenter == aSq.rCenter);
}
//-----------------------
double SmallSquare::CouplingCoefficient(const SmallSquare& aSq) {
	if (IsSelfCoupling(aSq))
		return SelfCoupling();
	else
		return DistanceCoupling(aSq);
}
//----------
double SmallSquare::SelfCoupling() {
	double retVal = side / (PI*EPS_0);
	retVal *= log(sqrt(2.) + 1);
	return retVal;
}

double SmallSquare::DistanceCoupling(const SmallSquare& aSq)
{
	RVektor disVec = rCenter - aSq.GetCenter();
	double dis = disVec.Norm();
	double  retVal = side*side;
	retVal /= 4.*PI*EPS_0*dis;
	return retVal;
}

/************************* Stream Output ************************/
std::ostream& operator<<(std::ostream& os, const SmallSquare& aSq)
{
	os << "(";
	os << aSq.GetSide() << ")";
	os << aSq.GetCenter();
	return os;
}