#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include "Inspection.h"
#include "ModuleTests.h"
#include "WorkPoint.h"


using namespace std;

////////////////////////////////////////////////////////



///////////////////////////////////////////////////

int main() {
	setlocale(LC_ALL, "Russian");
	int basicUserChoice;
	enum { moduleTests = 1, pointFromFile, pointPrintHands, exitProgram };

	cout << "Добрый день.\n" << "Вашему вниманию представлена программа, которая находит минимальный прямоугольник"
		<< "\n(для заданных минимум 3-х не лежащих на одной прямой точек)" << endl;

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
			double rectP = 0.0, rectS;
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
				Point p;
				vector<Point> points;

				vector<double> initialPoint;
				bool flagParity = true;
				int Buff;
				int i, j = 0;
				for (i = 0; ; i++) {
					if ((fin >> Buff)) { //Пробуем считать
						if (flagParity) {
							p.x = Buff;
						}
						else {
							p.y = Buff;
							points.push_back(p);
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

				convexHull(points);

				FileSavePoint(initialPoint);
			}
			/////////////////////////////

			break;
		}

		case pointPrintHands: {

			int amountPoint, i = 0, j = 0;
			double rectP = 0, rectS;
			cout << "Внимание. Нужно минимум 3 точки не лежащие на одной прямой." << endl;
			Point p;
			vector<Point> points;

			vector<double> initialPoint;

			do {
				int value;
				cout << "Введите координату Х точки (" << i + 1 << ") : ";
				p.x = DoubleInspectionStupid();
				initialPoint.push_back(p.x);
				cout << "Введите координату Y точки (" << i + 1 << ") : ";
				p.y = DoubleInspectionStupid();
				points.push_back(p);
				initialPoint.push_back(p.y);

				if (i > 1) {
					cout << "Если хотите ввести еще точку, введите любое другое число..\nЕсли Вам достаточно этих точек, введите 1" << endl;
					value = IntInspectionStupid();
					if (value == 1)
						break;
				}
				i++;

			} while (true);
			
			convexHull(points);

			FileSavePoint(initialPoint);
			break;
		}

		case exitProgram: {
			cout << "Возвращайтесь, мы Вас будем ждать." << endl;
			system("pause");
			return 0;
		}

		default: {
			cout << "Извините, неправильное значение. Попробуйте еще раз." << endl;
			break;
		}
		}

	} while (true);
}

