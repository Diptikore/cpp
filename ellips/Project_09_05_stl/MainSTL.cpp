#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iterator>
#include "Inspection.h"
#include "ModuleTests.h"
#include "WorkPoint.h"


using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	int basicUserChoice;
	enum { moduleTests = 1, pointFromFile, pointPrintHands, exitProgram };

	cout << "Добрый день.\n" << "Вашему вниманию представлена программа, которая рассчитывает минимальный размер полуосей эллипса"
		<< "\nдля заданных минимум 3 не лежащих на одной прямой точек)" << endl;

	do {
		cout << "\nЧтобы включить модульные тесты - введите 1" << endl;
		cout << "Чтобы взять координаты из файла - введите 2" << endl;
		cout << "Чтобы ввести координаты вручную - введите 3" << endl;
		cout << "Чтобы закрыть программу - введите 4" << endl;

		basicUserChoice = IntInspectionStupid();

		switch (basicUserChoice) {
		case moduleTests: {
			ModuleTests();
			
			break;
		}

		case pointFromFile: {
			cout << "Внимание!\n" << "Первое число в файле - количество точек.\n"
				<< "Файл должен состоять только из чисел"
				<< "\nX(1) Y(1) X(2) Y(2) ... X(N) Y(N)\n"
				<< "\n Внимание. Количество точек не должно быть меньше 3!" << endl;

			char fileName[256];
			int amountPoint;
			int j = 0;
			double bigAxis = 0.0, littleAxis;
			double tiltAngel = 0.0;
			cout << "Введите полный адрес файла: ";
			cin >> fileName;

			if (!CheckFileName(fileName)) {
				cout << "Запрещенное имя файла." << endl;
				break;
			}

			ifstream fin(fileName);
			if (!fin.is_open()) // если файл не открыт
				cout << "\nФайл не может быть открыт!\n";
			else {
				bool exitFile = false;
				vector<double> pointX;
				vector<double> pointY;
				vector<double> initialPoint;
				bool flagParity = true;
				int Buff;
				int i;
				for (i = 0; ; i++) {
					if ((fin >> Buff)) { //Пробуем считать
						if (flagParity) {
							pointX.push_back(Buff);
						}
						else {
							pointY.push_back(Buff);
							j++;
						}
						flagParity = !flagParity;
						initialPoint.push_back(Buff);
					}
					else {
						if ((j > 1) && flagParity)
							break;
						fin.clear();
						cout << "Некорректный файл." << endl;
						exitFile = true;
						break;
					}
				}
				fin.close();
				if (exitFile) {
					break;
				}


				///////////////////////////////////
				if (!(InspectionPoint(pointX, pointY))) {
					cout << "Извините, точки не выполняют условия, минимум три точки не должны лежать на одной прямой." << endl;
				}
				else {
					EllipHavi(pointX, pointY, bigAxis, littleAxis);
					cout << "Большая полуось = " << bigAxis << "\nМалая полуось = " << littleAxis << endl;
					FileSave(initialPoint, bigAxis, littleAxis);
					FileSavePoint(initialPoint);

				}
				
			}
			/////////////////////////////
			
			break;
		}

		case pointPrintHands: {

			int amountPoint, i = 0, j = 0;
			double value;
			bool exitPoint = true;
			double bigAxis = 0, littleAxis;
			vector<double> pointX;
			vector<double> pointY;
			vector<double> initialPoint;

			cout << "Внимание. Нужно минимум 3 точки не лежащие на одной прямой." << endl;
			do {
				cout << "Введите координату Х точки (" << i + 1 << ") : ";
				value = DoubleInspectionStupid();
				pointX.push_back(value);
				initialPoint.push_back(value);

				cout << "Введите координату Y точки (" << i + 1 << ") : ";
				value = DoubleInspectionStupid();
				pointY.push_back(value);
				initialPoint.push_back(value);


				if (i > 1) {
					cout << "Если хотите ввести еще точку, введите любое другое число..\nЕсли Вам достаточно этих точек, введите 1" << endl;
					value = IntInspectionStupid();
					if (value == 1)
						break;
				}
				i++;

			} while (true);


		
			if (!(InspectionPoint(pointX, pointY))) {
				cout << "Извините, точки не выполняют условия, минимум три точки не должны лежать на одной прямой." << endl;
			}
			else {
				EllipHavi(pointX, pointY, bigAxis, littleAxis);

				cout << "Большая полуось = ";
				if (bigAxis == 0)
					cout << "близка к 0";
				else
					cout << bigAxis;
				cout << "\nМалая полуось = ";
				if (littleAxis == 0)
					cout << "близка к 0" << endl;
				else
					cout << littleAxis << endl;
				FileSave(initialPoint, bigAxis, littleAxis);
				FileSavePoint(initialPoint);
			}
			
			break;
		}

		case exitProgram: {
			cout << "Возвращайтесь, мы Вас будем ждать." << endl;
			system("pause");
			return 0;
		}

		default: {
			cout << "Извините, не правильное значение. Попробуйте еще раз." << endl;
			break;
		}
		}

	} while (true);
}

//Вопрос о памяти массива структур, двумерного массива или двух одномерных массивов
