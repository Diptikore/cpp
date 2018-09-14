#include <iostream>
#include <stdio.h>
#include "WorkPoint.h"
#include "ModuleTests.h"

using namespace std;

void ModuleTests() {
	if (ModuleTestOne() && ModuleTestTwo() && ModuleTestThree() && ModuleTestFour())
		cout << "Модульные тесты прошли успешно." << endl;
};

bool ModuleTestOne() {
	int amountPoint = 3;
	double littleAxis, bigAxis = 0;
	double pointX[] = { 0, 6, 3 };
	double pointY[] = { 0, 0, 2 };
	EllipHavi(pointX, pointY, amountPoint, bigAxis, littleAxis, true);
	if ((bigAxis == 3 && littleAxis == 2) || (bigAxis == 2 && littleAxis == 3))
		return true;
	else {
		cout << "Модульный тест #1 - прошел неуспешно." << endl;
		cout << "Программа нашла две полуоси, равные \"" << bigAxis << "\" и \"" << littleAxis << "\" единиц соответственно." << endl;
		cout << "Но должно быть \"3\" и \"2\" " << endl;
		return false;
	}
};


//Тест с центром в 0 0
bool ModuleTestTwo() {
	int amountPoint = 3;
	double littleAxis, bigAxis = 0;
	double pointX[] = { -3, 3, 0 };
	double pointY[] = { 0, 0, 2 };
	EllipHavi(pointX, pointY, amountPoint, bigAxis, littleAxis, true);
	if ((bigAxis == 3 && littleAxis == 2) || (bigAxis == 2 && littleAxis == 3))
		return true;
	else {
		cout << "Модульный тест #2 - прошел неуспешно." << endl;
		cout << "Программа нашла две полуоси, равные \"" << bigAxis << "\" и \"" << littleAxis << "\" единиц соответственно." << endl;
		cout << "Но должно быть \"3\" и \"2\" " << endl;
		return false;
	}
};

//Тест с центром 0 0 и повернутым эллипсом на 90 градусов
bool ModuleTestThree() {
	int amountPoint = 3;
	double littleAxis, bigAxis = 0;
	double pointX[] = { 0, 0, 2 };
	double pointY[] = { -3, 3, 0 };
	EllipHavi(pointX, pointY, amountPoint, bigAxis, littleAxis, true);
	if ((bigAxis == 3 && littleAxis == 2) || (bigAxis == 2 && littleAxis == 3))
		return true;
	else {
		cout << "Модульный тест #3 - прошел неуспешно." << endl;
		cout << "Программа нашла две полуоси, равные \"" << bigAxis << "\" и \"" << littleAxis << "\" единиц соответственно." << endl;
		cout << "Но должно быть \"3\" и \"2\" " << endl;
		return false;
	}
}


//Тест со смещенным центром и повернутым эллипсом на 90 градусов
bool ModuleTestFour() {
	int amountPoint = 4;
	double littleAxis, bigAxis = 0;
	double pointX[] = { 1, 3, 5, 3 };
	double pointY[] = { 3, 6, 3, 0 };
	EllipHavi(pointX, pointY, amountPoint, bigAxis, littleAxis, true);
	if ((bigAxis == 3 && littleAxis == 2) || (bigAxis == 2 && littleAxis == 3))
		return true;
	else {
		cout << "Модульный тест #4 - прошел неуспешно." << endl;
		cout << "Программа нашла две полуоси, равные \"" << bigAxis << "\" и \"" << littleAxis << "\" единиц соответственно." << endl;
		cout << "Но должно быть \"3\" и \"2\" " << endl;
		return false;
	}
}