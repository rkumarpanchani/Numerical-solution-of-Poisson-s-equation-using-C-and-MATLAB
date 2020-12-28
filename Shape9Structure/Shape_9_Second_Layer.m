%Matlab to demonstrate the parallel plate structure without having the plane
%The plane is displayed with colours based on the charge distributions.

%Reading the values from the saved files from C++ code i.e.
%ChargeDensity9Plate1.txt, ChargeDensity9Plate2.txt,
%ChargeDensity9Plate3.txt, ChargeDensity9Plate4.txt, ChargeDensity9Plate5.txt, and ChargeDensity9Plate6.txt.

%colormap default;
colormap(jet);
%colormap(hsv);
%colormap(winter);
%colormap(summer);
%colormap(autumn);
%colormap(gray);
%colormap(copper);
%colormap(bone);
%colormap(colorcube);
%colormap(hot);

PlateB = importdata('ChargeDensityBasePlate.txt');
Plate9_1 = importdata('ChargeDensity9Plate1.txt');
Plate9_2 = importdata('ChargeDensity9Plate2.txt');
Plate9_3 = importdata('ChargeDensity9Plate3.txt');
Plate9_4 = importdata('ChargeDensity9Plate4.txt');
Plate9_5 = importdata('ChargeDensity9Plate5.txt');
Plate9_6 = importdata('ChargeDensity9Plate6.txt');

LenB = length(PlateB);
B = (10^11)*PlateB;     %Increasing the scale by 10 power 11
A1 = (10^11)*Plate9_1; 
A2 = (10^11)*Plate9_2;
A3 = (10^11)*Plate9_3;
A4 = (10^11)*Plate9_4;
A5 = (10^11)*Plate9_5;
A6 = (10^11)*Plate9_6;

%Calculating the Structure Size(X and Y)
nXsubPlate = 4;  
%As the size of the Plate is 100 mm X 160 mm, nX = 16
nX = 16; 
%As the size of the Plate is 100 mm X 160 mm, nY = nX * 5/8
nY = 10;  

plateXsize = 160;
plateYsize = plateXsize * 5/8;
%DistZ = 0.005 % Distance between plates at 5mm (5mm/1000 = 0.005m)
%DistZ = 0.01 % Distance between plates at 10mm (10mm/1000 = 0.01m)
%DistZ = 0.015 % Distance between plates at 15mm (15mm/1000 = 0.015m)
%DistZ = 0.020 % Distance between plates at 20mm (20mm/1000 = 0.020m)
DistZ = 0.025 % Distance between plates at 25mm (25mm/1000 = 0.025m)
SmallSqSize = plateXsize/nX;

% Second layer structure 
xb = 0:SmallSqSize:plateXsize;
yb = 0:SmallSqSize:plateYsize;
[Xb,Yb] = meshgrid(xb,yb);
Zb = Yb*0;
Cb = reshape(B,nY,[]);

% Second layer for the sub plate 1st layer
plate1Xmin = 0;
plate1Xmax = plateXsize/8;
plate1Ymin = 0;
plate1Ymax = plateYsize;

% Second layer for the sub plate 2nd layer
plate2Xmin = plateXsize/8;
plate2Xmax = plateXsize/2;
plate2Ymin = plateYsize *8/10;
plate2Ymax = plateYsize;

% Second layer for the sub plate 3rd layer
plate3Xmin = plateXsize/2;
plate3Xmax = plateXsize*5/8;
plate3Ymin = 0;
plate3Ymax = plateYsize;

% Second layer for the sub plate 4th layer
plate4Xmin = plateXsize*5/8;
plate4Xmax = plateXsize*7/8;
plate4Ymin = 0;
plate4Ymax = plateYsize*2/10;

% Second layer for the sub plate 5th layer
plate5Xmin = plateXsize*5/8;
plate5Xmax = plateXsize*7/8;
plate5Ymin = plateYsize*8/10;
plate5Ymax = plateYsize;

% Second layer for the sub plate 6th layer
plate6Xmin = plateXsize*7/8;
plate6Xmax = plateXsize;
plate6Ymin = 0;
plate6Ymax = plateYsize;

% %Thus both X and Y vary 
% %In steps of the small square size
grid on;

% Sub plate 1st logic
x1 =plate1Xmin:SmallSqSize:plate1Xmax;
y1 = plate1Ymin:SmallSqSize:plate1Ymax;
[X1,Y1] = meshgrid(x1,y1);
Z1 = Y1*0 +1;
Z1 = DistZ * Z1;
Z1
C1y = 10;
C1 = reshape(A1,C1y,[]);
C1

% Sub plate 2nd logic
x2 =plate2Xmin:SmallSqSize:plate2Xmax;
y2 = plate2Ymin:SmallSqSize:plate2Ymax;
[X2,Y2] = meshgrid(x2,y2);
Z2 = Y2*0 +1;
Z2 = DistZ * Z2;
Z2
C2y = 2;
C2 = reshape(A2,C2y,[]);
C2

% Sub plate 3rd logic
x3 =plate3Xmin:SmallSqSize:plate3Xmax;
y3 = plate3Ymin:SmallSqSize:plate3Ymax;
[X3,Y3] = meshgrid(x3,y3);
Z3 = Y3*0 +1;
Z3 = DistZ * Z3;
Z3
C3y = 10;
C3 = reshape(A3,C3y,[]);
C3

% Sub plate 4th logic
x4 =plate4Xmin:SmallSqSize:plate4Xmax;
y4 = plate4Ymin:SmallSqSize:plate4Ymax;
[X4,Y4] = meshgrid(x4,y4);
Z4 = Y4*0 +1;
Z4 = DistZ * Z4;
Z4
C4y = 2;
C4 = reshape(A4,C4y,[]);
C4

% Sub plate 5th logic
x5 =plate5Xmin:SmallSqSize:plate5Xmax;
y5 = plate5Ymin:SmallSqSize:plate5Ymax;
[X5,Y5] = meshgrid(x5,y5);
Z5 = Y5*0 +1;
Z5 = DistZ * Z5;
Z5
C5y = 2;
C5 = reshape(A5,C5y,[]);
C5

% Sub plate 6th logic
x6 = plate6Xmin:SmallSqSize:plate6Xmax;
y6 = plate6Ymin:SmallSqSize:plate6Ymax;
[X6,Y6] = meshgrid(x6,y6);
Z6 = Y6*0 +1;
Z6 = DistZ * Z6;
Z6
C6y = 10;
C6 = reshape(A6,C6y,[]);
C6

surf(Xb,Yb,Zb,Cb);
hold on;

surf(X1,Y1,Z1,C1);
hold on;

surf(X2,Y2,Z2,C2);
hold on;

surf(X3,Y3,Z3,C3);
hold on;

surf(X4,Y4,Z4,C4);
hold on;

surf(X5,Y5,Z5,C5);
hold on;

surf(X6,Y6,Z6,C6);
hold on;

xlabel ('Plate Width in X-Direction(mm)');
ylabel ('Plate Length in Y-Direction(mm)');
zlabel ('Distance between two plates(mm)');

c = colorbar('northoutside');
c.Label.String = '10^-11 Columbs Charges';