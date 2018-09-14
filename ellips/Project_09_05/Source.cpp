#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
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
				<< "Файл должен состоять только из чисел (первое число N равное количеству точек и после 2N чисел."
				<< "\nX(1) Y(1) X(2) Y(2) ... X(N) Y(N)\n"
				<< "\n Внимание. Количество точек не должно быть меньше 3!" << endl;

			char fileName[256];
			int amountPoint;
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
				if ((fin >> amountPoint) && (amountPoint > 2)) {
					cout << "Количество точек: " << amountPoint << endl;
				}
				else {
					cout << "Некорректное количество точек" << endl;
					break;
				}
				bool exitFile = false;
				double *pointX = new double[amountPoint];
				double *pointY = new double[amountPoint];
				double *initialPoint = new double[amountPoint * 2];
				bool flagParity = true;
				int Buff;
				int i, j = 0;
				for (i = 0; i < amountPoint * 2; i++) {
					if ((fin >> Buff)) { //Пробуем считать
						if (flagParity) {
							pointX[j] = Buff;
						}
						else {
							pointY[j] = Buff;
							j++;
						}
						flagParity = !flagParity;
						initialPoint[i] = Buff;
					}
					else {
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
				if (!(InspectionPoint(pointX, pointY, amountPoint))) {
					cout << "Извините, точки не выполняют условия, минимум три точки не должны лежать на одной прямой." << endl;
				}
				else {
					EllipHavi(pointX, pointY, amountPoint, bigAxis, littleAxis);
					cout << "Большая полуось = " << bigAxis << "\nМалая полуось = " << littleAxis << endl;
					FileSave(initialPoint, amountPoint, bigAxis, littleAxis);
					FileSavePoint(initialPoint, amountPoint);

				}
				delete pointX;
				delete pointY;
				delete initialPoint;
			}
			/////////////////////////////

			break;
		}

		case pointPrintHands: {

			int amountPoint, i, j = 0;
			double bigAxis = 0, littleAxis;
			cout << "Внимание. Нужно минимум 3 точки не лежащие на одной прямой." << endl;
			cout << "Введите количество точек: ";
			while (!(cin >> amountPoint) || amountPoint <= 2) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "Нужно минимум 3 точки . Попробуйте еще раз." << endl;
			}

			double *pointX = new double[amountPoint];
			double *pointY = new double[amountPoint];
			double *initialPoint = new double[amountPoint * 2];

			for (i = 0; i < amountPoint; i++) {
				cout << "Введите координату Х точки (" << i + 1 << ") : ";
				pointX[i] = DoubleInspectionStupid();
				initialPoint[j] = pointX[i];
				j++;
				cout << "Введите координату Y точки (" << i + 1 << ") : ";
				pointY[i] = DoubleInspectionStupid();
				initialPoint[j] = pointY[i];
				j++;
			}
			if (!(InspectionPoint(pointX, pointY, amountPoint))) {
				cout << "Извините, точки не выполняют условия, минимум три точки не должны лежать на одной прямой." << endl;
			}
			else {
				EllipHavi(pointX, pointY, amountPoint, bigAxis, littleAxis);
				
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
				FileSave(initialPoint, amountPoint, bigAxis, littleAxis);
				FileSavePoint(initialPoint, amountPoint);
			}
			delete pointX;
			delete pointY;
			delete initialPoint;
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

