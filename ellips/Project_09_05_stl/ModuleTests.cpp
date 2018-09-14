#include <iostream>
#include <stdio.h>
#include "WorkPoint.h"
#include "ModuleTests.h"

using namespace std;

void ModuleTests() {
	if (ModuleTestOne() && ModuleTestTwo() && ModuleTestThree() && ModuleTestFour())
		cout << "��������� ����� ������ �������." << endl;
};

bool ModuleTestOne() {
	double littleAxis, bigAxis = 0;
	vector<double> pointX = { 0, 6, 3 };
	vector<double> pointY = { 0, 0, 2 };
	EllipHavi(pointX, pointY, bigAxis, littleAxis, true);
	if ((bigAxis == 3 && littleAxis == 2) || (bigAxis == 2 && littleAxis == 3))
		return true;
	else {
		cout << "��������� ���� #1 - ������ ���������." << endl;
		cout << "��������� ����� ��� �������, ������ \"" << bigAxis << "\" � \"" << littleAxis << "\" ������ ��������������." << endl;
		cout << "�� ������ ���� \"3\" � \"2\" " << endl;
		return false;
	}
};


//���� � ������� � 0 0
bool ModuleTestTwo() {
	double littleAxis, bigAxis = 0;
	vector<double> pointX = { -3, 3, 0 };
	vector<double> pointY = { 0, 0, 2 };
	EllipHavi(pointX, pointY, bigAxis, littleAxis, true);
	if ((bigAxis == 3 && littleAxis == 2) || (bigAxis == 2 && littleAxis == 3))
		return true;
	else {
		cout << "��������� ���� #2 - ������ ���������." << endl;
		cout << "��������� ����� ��� �������, ������ \"" << bigAxis << "\" � \"" << littleAxis << "\" ������ ��������������." << endl;
		cout << "�� ������ ���� \"3\" � \"2\" " << endl;
		return false;
	}
};

//���� � ������� 0 0 � ���������� �������� �� 90 ��������
bool ModuleTestThree() {
	double littleAxis, bigAxis = 0;
	vector<double> pointX = { 0, 0, 2 };
	vector<double> pointY = { -3, 3, 0 };
	EllipHavi(pointX, pointY,  bigAxis, littleAxis, true);
	if ((bigAxis == 3 && littleAxis == 2) || (bigAxis == 2 && littleAxis == 3))
		return true;
	else {
		cout << "��������� ���� #3 - ������ ���������." << endl;
		cout << "��������� ����� ��� �������, ������ \"" << bigAxis << "\" � \"" << littleAxis << "\" ������ ��������������." << endl;
		cout << "�� ������ ���� \"3\" � \"2\" " << endl;
		return false;
	}
}


//���� �� ��������� ������� � ���������� �������� �� 90 ��������
bool ModuleTestFour() {
	double littleAxis, bigAxis = 0;
	vector<double> pointX = { 1, 3, 5, 3 };
	vector<double> pointY = { 3, 6, 3, 0 };
	EllipHavi(pointX, pointY,  bigAxis, littleAxis, true);
	if ((bigAxis == 3 && littleAxis == 2) || (bigAxis == 2 && littleAxis == 3))
		return true;
	else {
		cout << "��������� ���� #4 - ������ ���������." << endl;
		cout << "��������� ����� ��� �������, ������ \"" << bigAxis << "\" � \"" << littleAxis << "\" ������ ��������������." << endl;
		cout << "�� ������ ���� \"3\" � \"2\" " << endl;
		return false;
	}
}