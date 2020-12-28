#include "BasePlate.h"
#include <iostream>
#include <fstream>

//Constructor for the base plate
BasePlate::BasePlate()
{


}

void BasePlate::CreatePlate(int nX, int nY)
{
	std::ofstream BasePlateFile;
	BasePlateFile.open("BasePlateStructure.txt");
	std::cout << "\n**********************************************************************\n";
	std::cout << "\nCreating the base plate...\n\n";

	//Number of small squares
	nN = nY*nX;

	//delX = 0.01, delY = 0.01, nX = 16, nY = 10, nN=nY*nX, iN=0(for iteration of loop)
	//iX = 16, iY = 10

	//x=0.05 at (iX=1) and y=0.05(iY=1),0.015(iY=2),0.025(iY=3),0.035(iY=4),0.045(iY=5),0.055(iY=6),...till (iY=10)
	//x=0.014 at (iX=2) and y=....	
	
	//x=0.014 at (iX=2) and y=....
	double delX = .01;
	double delY = delX;
	int iN = 0;
	BPlate.SetDim(nN);
	
	for (int iX = 1; iX <= nX; iX++)
	{
		double x = delX*(iX - .5);

		for (int iY = 1; iY <= nY; iY++)
		{
			double y = delY*(iY - .5);
			BPlate[iN].MoveTo(x, y);;
			BPlate[iN].SetSide(delX);
			BasePlateFile << BPlate[iN] << "\n";
			std::cout << "iN =" << iN << " " << BPlate[iN] << "\n";
			iN++;
		}
	}

	BasePlateFile.close();
}


BasePlate::~BasePlate()
{

}