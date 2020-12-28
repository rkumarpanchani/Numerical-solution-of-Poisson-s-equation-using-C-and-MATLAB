#include "TwoPlates9.h"
#include <fstream>
using namespace std;

//Adding the definition for Error Handling
void(*Vektor<SmallSquare>::ErrHdlr)(char *) = Vektor<SmallSquare>::DefaultErrHdlr;
char Vektor<SmallSquare>::ErrFlag = 0;

TwoPlates9::TwoPlates9()
{
	//Potential of the plate in volt;
	potPlate_positive = 1.0;
	potPlate_negative = -1.0;

	//No charges yet
	totalcharge = 0; 
}

//----------------------------------------------------------------
//Number of squares on each plate in each direction -- numOfSquare
void TwoPlates9::SetPlateAndPlaneSize(int numOfSquare)
{
	//nX = 4 * numOfSquare; //numOfSquare = 4;
	nX = 16;
	// As the size of the Plate is 100 mm X 160 mm
	nY = nX * 5 / 8;
	//Number of small squares on Base plate
	BnN = nX*nY; 
	// Number of small squares on 9 - Shape plate
	nN_9 = BnN - 72; 
	vPlate.SetDim(BnN + nN_9);
	//16 boxes in x-direction
	plateXsize = 0.16; 
	//plateYsize=(0.16*5/8)=0.1, means 10 boxes in y-direction
	plateYsize = plateXsize * 5 / 8; 
}

#pragma region Geometry of the Structure
/*This Function is to define the Geometry of the Structure*/
void TwoPlates9::CreateStructure(double distance)
{
	BPlate.CreatePlate(nX, nY);
	plate_9.CreatePlate(nX, nY, distance, plateXsize, plateYsize, nN_9);
	bPlate1 = BPlate.GetPlate();
	_9Plate1 = plate_9.GetPlate();
	CreateTwoPlates();
}

/*This Function is to define the Geometry of the Base Plate*/
#pragma endregion
//------------------------------------------------------------
void TwoPlates9::CreateTwoPlates()
{
	std::ofstream file;
	file.open("createTwoPlates.txt");
	std::cout << "\n**********************************************************************\n";
	std::cout << "\nCreating 9 Shape Plate parallel to Base Plate... \n";
	vPlate.SetDim(BnN + nN_9);

	int iM = 0;

	for (int iN = 0; iN < BnN; iN++) //BnN = 160
	{
		vPlate[iM] = bPlate1[iN]; //vPlate[iM] = 160
		//std::cout << " iM = " << iM << " " << vPlate[iM] << "\n";
		file << vPlate[iM] << "\n"; //to store v
		iM++;
	}
	for (int iN = 0; iN < nN_9; iN++)  //GnN = 100
	{
		vPlate[iM] = _9Plate1[iN]; //vPlate[iM] = 100
		//std::cout << " iM = " << iM << " " << vPlate[iM] << "\n";
		file << vPlate[iM] << "\n";
		iM++;
	}

	file.close(); //to close the file after editing

}

void TwoPlates9::CreateExcitationVector()
{
	//To write in the file called "ExcitationVector.txt"
	std::ofstream file;
	//To open "ExcitationVector.txt" file
	file.open("ExcitationVector.txt"); 
	std::cout << "\n**********************************************************************\n"; 
	std::cout << "\nCalculating Excitation Vector.... \n";  
	//SetDim is the method to set the dimension
	gmVec.SetDim(BnN + nN_9);
	//BnN=160
	for (int i = 0; i<BnN; i++) 
		gmVec[i] = potPlate_positive;
	//GnN=100
	for (int i = BnN; i<BnN + nN_9; i++)
		gmVec[i] = potPlate_negative;
	
	std::cout << gmVec;
	file << gmVec;
	file.close();
}

//--------------------------------------
void TwoPlates9::CalculateTotalCharge()
{
	std::ofstream file;
	file.open("TotalCharge.txt");
	std::cout << "\n**********************************************************************\n";
	std::cout << "\nCalculating Total Charge and Capacitance.... \n";
	
	//Vector <SmallSquare> vPlate; 
	//Plate composed of SmallSquares
	double area = vPlate[0].GetArea();

	totalcharge = chargeVec9Structure.SumupElements(); 
	
	totalcharge *= area;

	std::cout << "\nTotal Charge = " << totalcharge << " coulombs\n";
	file << totalcharge;

	file.close();

}

void TwoPlates9::CalculateCapacitance()
{
	//Positive Potential of the Square Plate
	//Negative Potential of the Square Plate
	capacitance = abs(totalcharge) / (potPlate_positive - potPlate_negative);
	std::cout << "\nCapacitance = " << capacitance << " Farad\n\n";
}

//--------------------------------------
void TwoPlates9::FindChargeDistribution()
{
	std::ofstream file1;
	std::ofstream file2;
	std::ofstream file3;
	std::ofstream file4;
	std::ofstream file5;
	std::ofstream file6;
	std::ofstream file7;
	
	file1.open("ChargeDensityBasePlate.txt");
	file2.open("ChargeDensity9Plate1.txt");
	file3.open("ChargeDensity9Plate2.txt");
	file4.open("ChargeDensity9Plate3.txt");
	file5.open("ChargeDensity9Plate4.txt");
	file6.open("ChargeDensity9Plate5.txt");
	file7.open("ChargeDensity9Plate6.txt");

	std::cout << "\n**********************************************************************\n";
	std::cout << "\nCalculatng Charge density distribution.... \n";
	//(BnN+GnN) = (160+100) = 260
	chargeVec.SetDim(BnN + nN_9);
	//BnN=160
	chargeVecBase.SetDim(BnN); 
	//GnN=100
	chargeVec9Structure.SetDim(nN_9); 
	//Matrix of Coupling Coefficient between two plates
	//Potential of each Small Square
	chargeVec = RealGaussElimination(gMat, gmVec);
	std::cout << "\nCharge density \n";

	int iN = 0;
	for (int i = 0; i < BnN + nN_9; i++)
	{
		//chargeVec is used to store charge distribution
		std::cout << chargeVec[iN] << " ";
		std::cout << "\n";
		
		if (iN < BnN) {  
			file1 << chargeVec[iN] << "\n";
			chargeVecBase[iN] = chargeVec[iN];
		}

		else if (iN >= BnN && iN < BnN + 20){   
			file2 << chargeVec[iN] << "\n";
			chargeVec9Structure[iN - BnN] = chargeVec[iN];
		}

		else if (iN >= BnN + 20 && iN < BnN + 32 ){		
			file3 << chargeVec[iN] << "\n" ;
			chargeVec9Structure[iN - BnN] = chargeVec[iN];
		}

		else if (iN >= BnN + 32 && iN < BnN + 52){
			file4 << chargeVec[iN] << "\n";
			chargeVec9Structure[iN - BnN] = chargeVec[iN];
		}
		
		else if (iN >= BnN + 52 && iN < BnN + 60){
			file5 << chargeVec[iN] << "\n";
			chargeVec9Structure[iN - BnN] = chargeVec[iN];
		}

		else if (iN >= BnN + 60 && iN < BnN + 68){
			file6 << chargeVec[iN] << "\n";
			chargeVec9Structure[iN - BnN] = chargeVec[iN];
		}

		else if (iN >= BnN + 68 && iN < BnN + 88){
			file7 << chargeVec[iN] << "\n";
			chargeVec9Structure[iN - BnN] = chargeVec[iN];
		}
		iN++;
	}

	file1.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();
	file6.close();
	file7.close();
}

//---------------------------------------
void TwoPlates9::CreateMatrix()
{

	std::ofstream file;
	file.open("Matrix.txt");
	std::cout << "\n**********************************************************************\n";
	std::cout << "\nCreating Matrix..... \n";
	
	gMat.SetDimension(BnN + nN_9, BnN + nN_9);
	for (int i = 0; i < BnN + nN_9; i++)
	{
		for (int j = 0; j< BnN + nN_9; j++)
		{
			gMat[i][j] = vPlate[i].CouplingCoefficient(vPlate[j]);
		}
	}

	file << gMat;
	file.close();
}

TwoPlates9::~TwoPlates9()
{

}