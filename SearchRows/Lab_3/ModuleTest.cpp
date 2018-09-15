#pragma once
#include <iostream>
#include <stdio.h>
#include "WorkFile.h"
#include "ModuleTest.h"
using namespace std;

void ModuleTests() {
	if (ModuleTestOne() && ModuleTestTwo() 
		&& ModuleTestThree() && ModuleTestFour())
		cout << "Модульные тесты прошли успешно." << endl;
};


bool ModuleTestOne() {
	char *textOne = new char[17];
	char *textTwo = new char[12];
	textOne = "My name is Putin";
	textTwo = "Hello Putin V V";
	int count = 0, indexTextOne = 0, indexTextTwo = 0;
	SubstringSearch(textOne, textTwo, count, indexTextOne, indexTextTwo);

	if (count == 6 && indexTextOne == 10 && indexTextTwo == 5)
		return true;
	else {
		cout << "Модульный тест #1 - прошел неуспешно." << endl;
		cout << "Наша программа нашла последовательность, размером <"
			<< count << ">" << endl;
		cout << "Которая начинается с <" << indexTextOne
			<< "> элемента первого текста и с <" << indexTextTwo
			<< "> элемента второго текста." << endl;
		cout << "Но значения должны быть 6  10  5 соответственно." << endl;
		return false;
	}
	delete textOne;
	delete textTwo;
};


bool ModuleTestTwo() {
	char *textOne = new char[20];
	char *textTwo = new char[9];
	 textOne = "You are disappointed\n";
	 textTwo = "hello are\n";
	int count = 0, indexTextOne = 0, indexTextTwo = 0;
	SubstringSearch(textOne, textTwo, count, indexTextOne, indexTextTwo);
	if (count == 4 && indexTextOne == 3 && indexTextTwo == 5)
		return true;
	else {
		cout << "Модульный тест #2 - прошел неуспешно." << endl;
		cout << "Наша программа нашла последовательность, размером <"
			<< count << ">" << endl;
		cout << "Которая начинается с <" << indexTextOne
			<< "> элемента первого текста и с <" << indexTextTwo
			<< "> элемента второго текста." << endl;
		cout << "Но значения должны быть 4  3  5 соответственно." << endl;
		return false;
	}
	delete textOne;
	delete textTwo;
};

bool ModuleTestThree() {
	char *textOne = new char[19];
	char *textTwo = new char[20];
	textOne = "Hello programmer";
	textTwo = "programmer so bad";
	int count = 0, indexTextOne = 0, indexTextTwo = 0;

	SubstringSearch(textOne, textTwo, count, indexTextOne, indexTextTwo);

	if (count == 10 && indexTextOne == 6 && indexTextTwo == 0)
		return true;
	else {
		cout << "Модульный тест #3 - прошел неуспешно." << endl;
		cout << "Наша программа нашла последовательность, размером <"
			<< count << ">" << endl;
		cout << "Которая начинается с <" << indexTextOne
			<< "> элемента первого текста и с <" << indexTextTwo
			<< "> элемента второго текста." << endl;
		cout << "Но значения должны быть 10  6  0 соответственно." << endl;
		return false;
	}
	delete textOne;
	delete textTwo;
}

bool ModuleTestFour() {
	char *textOne = new char[11];
	char *textTwo = new char[7];
	textOne = "abcdas adbc\n";
	textTwo = "kolonok\n";
	int count = 0, indexTextOne = 0, indexTextTwo = 0;

	SubstringSearch(textOne, textTwo, count, indexTextOne, indexTextTwo);

	if (count == 0 && indexTextOne == 0 && indexTextTwo == 0)
		return true;
	else {
		cout << "Модульный тест #4 - прошел неуспешно." << endl;
		cout << "Наша программа нашла последовательность, размером <"
			<< count << ">" << endl;
		cout << "Которая начинается с <" << indexTextOne
			<< "> элемента первого текста и с <" << indexTextTwo
			<< "> элемента второго текста." << endl;
		cout << "Но значения должны быть 0  0  0 соответственно." << endl;
		return false;
	}
	delete textOne;
	delete textTwo;
}