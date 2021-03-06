%Program to Display the Parallel Plate structure without the Plane.
%The plane is displayed with colours based on the Charge Distribution.

%Reading the values from the Saved Files from C++ Program
PlateB = importdata('ChargeDensityBasePlate.txt');
PlateA1 = importdata('ChargeDensityGPlate1.txt');
PlateA2 = importdata('ChargeDensityGPlate2.txt');
PlateA3 = importdata('ChargeDensityGPlate3.txt');
LenB = length(PlateB);
B = (10^11)*PlateB;     %Increasing the scale by 10 power 11
A1 = (10^11)*PlateA1; 
A2 = (10^11)*PlateA2;
A3 = (10^11)*PlateA3;
A1
A2
A3
% %Calculating the Structure Size(X and Y)
nXsubPlate = 4;  % number of division on each subplate in X- direction
nX = 16; %  nX is multiple of 8

nY = 10; %As the size of the Plate is 100 mm X 160 mm, nY = nX * 5/8 
plateXsize = 0.16;
plateYsize = plateXsize * 5/8;
SmallSqSize = plateXsize/nX;
SmallSqSize
DistZ = 0.05 % Distance between plates
% Base Plate
xb = 0+SmallSqSize/2:SmallSqSize:plateXsize-SmallSqSize/2;
yb = 0+SmallSqSize/2:SmallSqSize:plateYsize-SmallSqSize/2;
xb
yb
[Xb,Yb] = meshgrid(xb,yb);
Xb
Yb
Zb = Yb*0;
Cb = reshape(B,nY,[]);

% Sub Plate 1
plate1Xmin = 0+SmallSqSize/2;
plate1Xmax = plateXsize/4-SmallSqSize/2;
plate1Ymin = 0+SmallSqSize/2;
plate1Ymax = plateYsize-SmallSqSize/2;
% Sub Plate 2
plate2Xmin = plateXsize/4+SmallSqSize/2;
plate2Xmax = plateXsize/2-SmallSqSize/2;
plate2Ymin = 0+SmallSqSize/2;
plate2Ymax = plateYsize * 3/10-SmallSqSize/2;
% Sub Plate 3
plate3Xmin = plateXsize/2+SmallSqSize/2;
plate3Xmax = plateXsize-SmallSqSize/2;
plate3Ymin = 0+SmallSqSize/2;
plate3Ymax = plateYsize-SmallSqSize/2;
% 

% 
% %Thus both X and Y vary 
% %In steps of the small square size
% Sub Plate 1
grid on;

x1 =plate1Xmin:SmallSqSize:plate1Xmax;
y1 = plate1Ymin:SmallSqSize:plate1Ymax;
[X1,Y1] = meshgrid(x1,y1);
Z1 = Y1*0 +1;
Z1 = DistZ * Z1;
Z1
C1y = nY;
C1 = reshape(A1,C1y,[]);
C1

% Sub Plate 2
x2 =plate2Xmin:SmallSqSize:plate2Xmax;
y2 = plate2Ymin:SmallSqSize:plate2Ymax;
[X2,Y2] = meshgrid(x2,y2);
Z2 = Y2*0 +1;
Z2 = DistZ * Z2;
Z2
C2y = nY * 3/10;
C2 = reshape(A2,C2y,[]);
C2


% Sub Plate 3
x3 =plate3Xmin:SmallSqSize:plate3Xmax;
y3 = plate3Ymin:SmallSqSize:plate3Ymax;
[X3,Y3] = meshgrid(x3,y3);
Z3 = Y3*0 +1;
Z3 = DistZ * Z3;
Z3
C3y = nY;
C3 = reshape(A3,C3y,[]);
C3

surf(Xb,Yb,Cb);
hold on;
surf(X1,Y1,C1);
hold on;
surf(X2,Y2,C2);
hold on;
surf(X3,Y3,C3);
hold on;

xlabel ('X - Plate width (metre)');
ylabel ('Y - Plate Length (metre)');
zlabel ('Z - Chage Density X 10 ^-7');

colorbar;