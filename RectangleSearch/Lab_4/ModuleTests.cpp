#include <iostream>
#include <stdio.h>
#include "WorkPoint.h"
#include "ModuleTests.h"

using namespace std;

void ModuleTests() {
	if (ModuleTestOne() && ModuleTestTwo() && ModuleTestThree() && ModuleTestFour())
		cout << "��������� ����� ������ �������." << endl;
};

//16 12
bool ModuleTestOne() {
	int amountPoint = 3;
	double P = 0, S = 0;
	double *pointX = new double[3];
	double *pointY = new double[3];
	pointX[0] = 3; pointX[1] = 6; pointX[2] = 0;
	pointY[0] = 2; pointY[1] = 0; pointY[2] = 0;
	RectangleWork(pointX, pointY, amountPoint, P, S, true);
	if (P == 16 && S == 12)
		return true;
	else {
		cout << "��������� ���� #1 - ������ ���������." << endl;
		cout << "��������� ����� �������� ������ " << P << " � ������� ������ "
			<< S << endl;
		cout << "�� ������ ���� \"16\" � \"12\" " << endl;
		return false;
	}
};

bool ModuleTestTwo() {
	int amountPoint = 3;
	double P, S;
	double *pointX = new double[3];
	double *pointY = new double[3];
	pointX[0] = 3; pointX[1] = 6; pointX[2] = 0;
	pointY[0] = 2; pointY[1] = 0; pointY[2] = 0;
	SquareWork(pointX, pointY, amountPoint, P, S, true);
	if (P == 24 && S == 36)
		return true;
	else {
		cout << "��������� ���� #2 - ������ ���������." << endl;
		cout << "��������� ����� �������� ������ " << P << " � ������� ������ "
			<< S << endl;
		cout << "�� ������ ���� \"24\" � \"36\" " << endl;
		return false;
	}
};


//�������� �������������� = 17.2111
//������� �������������� = 18.0278

bool ModuleTestThree() {
	int amountPoint = 3;
	double P, S;
	double *pointX = new double[3];
	double *pointY = new double[3];
	pointX[0] = 0; pointX[1] = 3; pointX[2] = -3;
	pointY[0] = 2; pointY[1] = 0; pointY[2] = 0;
	RectangleWork(pointX, pointY, amountPoint, P, S, true);
	if (P == 16 && S == 12)
		return true;
	else {
		cout << "��������� ���� #3 - ������ ���������." << endl;
		cout << "��������� ����� �������� ������ " << P << " � ������� ������ "
			<< S << endl;
		cout << "�� ������ ���� \"16\" � \"12\" " << endl;
		return false;
	}
}

//20 25
bool ModuleTestFour() {
	int amountPoint = 4;
	double P, S;
	double *pointX = new double[4];
	double *pointY = new double[4];
	pointX[0] = 1; pointX[1] = 3; pointX[2] = 5; pointX[3] = 3;
	pointY[0] = 3; pointY[1] = 6; pointY[2] = 3; pointY[3] = 0;
	SquareWork(pointX, pointY, amountPoint, P, S, true);
	if (P == 20 && S == 25)
		return true;
	else {
		cout << "��������� ���� #4 - ������ ���������." << endl;
		cout << "��������� ����� �������� ������ " << P << " � ������� ������ "
			<< S << endl;
		cout << "�� ������ ���� \"20\" � \"25\" " << endl;
		return false;
	}
}