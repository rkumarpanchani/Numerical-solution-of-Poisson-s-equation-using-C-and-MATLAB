#include "Shape9Plate.h"
#include <iostream>
#include <fstream>
using namespace std;

Shape9Plate::Shape9Plate()
{

}

void Shape9Plate::CreatePlate(int nX, int nY, double distance,double plateXsize, double plateYsize, int nN_9)
{
	std::ofstream file1;
	std::ofstream file2;
	std::ofstream file3;
	std::ofstream file4;
	std::ofstream file5;
	std::ofstream file6;
	
	file1.open("Shape9Plate1.txt");
	file2.open("Shape9Plate2.txt");
	file3.open("Shape9Plate3.txt");
	file4.open("Shape9Plate4.txt");
	file5.open("Shape9Plate5.txt");
	file6.open("Shape9Plate6.txt");

	double delX = plateXsize / nX;
	double delY = delX;
	double startptX = (plateXsize / nX) / 2.0;
	double startptY = ((plateYsize) / nY) / 2.0;

	std::cout << "\n**********************************************************************\n";
	std::cout << "\n\nCreating 9 Shape Plate... \n";
	std::cout << "\n**********************************************************************\n";
	Plate_9.SetDim(nN_9);

	int iM = 0;

	for (double iX = startptX; iX < plateXsize; iX = iX + delX)
	{
		double x = iX;

		for (double iY = startptY; iY < (plateYsize); iY = iY + delY)
		{
			double y = iY;

			//Here the 9 Shape empty spaces will be printed here:
			if (x >= plateXsize / 8 && x < plateXsize / 2 && y < 8 * plateYsize / 10 ||
				(x >= 5 * plateXsize / 8 && x < 7 * plateXsize / 8 && y >= 2 * plateYsize / 10) &&
				(x >= 5 * plateXsize / 8 && x < 7 * plateXsize / 8 && y < 8 * plateYsize / 10))
			{
			 // For empty spaces 
			}
			
			else
			{
				Plate_9[iM].SetSide(delX);
				Plate_9[iM].MoveToPlane(x, y, distance);

				if (x < (plateXsize) / 8 && y < (plateYsize))
				{ 
					file1 << x;
					file1 << " ";
					file1 << y;
					file1 << " ";
					file1 << distance << "\n" ;
				}
			
				else if((x >= (plateXsize) / 8 && x < (plateXsize) / 2) &&	(y >= 8 * (plateYsize) / 10))
				{ 
					file2 << x;
					file2 << " ";
					file2 << y;
					file2 << " ";
					file2 << distance << "\n";
				}
				
				else if ((x >= (plateXsize) / 2 && x < 5 * (plateXsize) / 8) && (y < (plateYsize)))
				{
					file3 << x;
					file3 << " ";
					file3 << y;
					file3 << " ";
					file3 << distance << "\n";
				}
				
				else if ((x >= 5 * (plateXsize) / 8 && x < 7*(plateXsize) / 8 ) && (y < 2 * (plateYsize) / 10))
				{
					file4 << x;
					file4 << " ";
					file4 << y;
					file4 << " ";
					file4 << distance << "\n";
				}
				
				else if ((x >= 5 * (plateXsize) / 8 && x < 7 * (plateXsize) / 8) && (y > 7 * (plateYsize) / 10))
				{
					file5 << x;
					file5 << " ";
					file5 << y;
					file5 << " ";
					file5 << distance << "\n";
				}
				
				else if (x >= 7* (plateXsize) / 8 && (y >= 0))
				{
					file6 << x;
					file6 << " ";
					file6 << y;
					file6 << " ";
					file6 << distance << "\n";
				}
				
				std::cout << "iM =" << iM << " " << Plate_9[iM] << "\n";
				iM++;
			}
			
		}
	}

	file1.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();
	file6.close();
}

Shape9Plate::~Shape9Plate()
{

}
