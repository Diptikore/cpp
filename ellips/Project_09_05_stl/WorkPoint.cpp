#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <cstring>
#include <vector>
#include <iterator>

#include "WorkPoint.h"
#include "Inspection.h"

using namespace std;

#define PI 3.14159265 


void EllipHavi(vector<double>& pointX, vector<double>& pointY, double &bigAxis, double &littleAxis, bool ModuleTest) {
	int i, j, indexMaxPointOne, indexMaxPointTwo, centerX, centerY;
	int distance;
	double tiltAngel = 0.0;
	for (i = 0; i < pointX.size(); i++) {

		for (j = 1; j < pointX.size(); j++) {
			if (bigAxis < sqrt(pow((pointX[i] - pointX[j]), 2) + pow((pointY[i] - pointY[j]), 2))) {
				bigAxis = sqrt(pow((pointX[i] - pointX[j]), 2) + pow((pointY[i] - pointY[j]), 2));
				indexMaxPointOne = i;
				indexMaxPointTwo = j;
			}

		}
	}
	centerX = (pointX[indexMaxPointTwo] + pointX[indexMaxPointOne]) / 2;
	centerY = (pointY[indexMaxPointTwo] + pointY[indexMaxPointOne]) / 2;

	if (!ModuleTest)
		cout << "Center = " << centerX << " " << centerY << endl;
	distance = 0;

	//Угол наклона 
	if (pointY[indexMaxPointOne] != pointY[indexMaxPointTwo]) {
		tiltAngel = (pointY[indexMaxPointOne] - pointY[indexMaxPointTwo]) / (pointX[indexMaxPointOne] - pointX[indexMaxPointTwo]);
		tiltAngel = (atan(tiltAngel) * 180.0 / PI);
	}
	if (!ModuleTest)
		cout << "\nУгол между большой осью эллипса и ОХ: " << tiltAngel << " градусов." << endl;

	tiltAngel = round(tiltAngel);
	//Поворачиваем точки вокруг центра на tiltAngel градусов
	//Переводим в радианы
	double  cosTilt, sinTilt;
	int intTiltAngel = tiltAngel;

	if (intTiltAngel == 90 || intTiltAngel == -90) {
		cosTilt = 0;
		sinTilt = 1;
	}
	else {
		cosTilt = cos(tiltAngel * PI / 180);
		sinTilt = sin(tiltAngel * PI / 180);
	}

	if (tiltAngel != 0)
		for (i = 0; i < pointX.size(); i++) {
			double dublPoint;
			dublPoint = pointX[i];
			pointX[i] = (centerX + (pointX[i] - centerX) * cosTilt - (pointY[i] - centerY) * sinTilt);
			pointY[i] = (centerY + (pointY[i] - centerY) * cosTilt + (dublPoint - centerX) * sinTilt);
		}

	for (i = 0; i < pointX.size(); i++) {

		for (j = 1; j < pointX.size(); j++) {
			if (bigAxis < sqrt(pow((pointX[i] - pointX[j]), 2) + pow((pointY[i] - pointY[j]), 2))) {
				bigAxis = sqrt(pow((pointX[i] - pointX[j]), 2) + pow((pointY[i] - pointY[j]), 2));
				indexMaxPointOne = i;
				indexMaxPointTwo = j;
			}

		}
	}
	for (i = 0; i < pointX.size(); i++) {
		pointX[i] -= centerX;
		pointY[i] -= centerY;
	}

	for (i = 0; i < pointX.size(); i++) {
		if (distance < ((abs((pointY[indexMaxPointTwo] - pointY[indexMaxPointOne])*pointX[i] - (pointX[indexMaxPointTwo] - pointX[indexMaxPointOne])*pointY[i]
			- pointX[indexMaxPointTwo] * pointY[indexMaxPointOne] - pointY[indexMaxPointTwo] * pointX[indexMaxPointOne])) / bigAxis));
		distance = ((abs((pointY[indexMaxPointTwo] - pointY[indexMaxPointOne])*pointX[i] - (pointX[indexMaxPointTwo] - pointX[indexMaxPointOne])*pointY[i]
			- pointX[indexMaxPointTwo] * pointY[indexMaxPointOne] - pointY[indexMaxPointTwo] * pointX[indexMaxPointOne])) / bigAxis);
	}

	if (!ModuleTest)
		cout << "Расстояние между точками " << indexMaxPointOne + 1 << " и " << indexMaxPointTwo + 1 << " = " << bigAxis << "\n" << endl;
	bigAxis = bigAxis / 2;
	bigAxis = round(bigAxis);



	//Первый цикл формирует шаг длины малой полуоси
	///Второй цикл проходится с этой полуосью по точкам, и если 
	bool radiusFound = false;
	double index;
	for (index = distance; ; index += 0.2) { ///бесконечный цикл от дистанции
		radiusFound = true;
		for (j = 0; j < pointX.size(); j++) {
			if (j == indexMaxPointOne || j == indexMaxPointTwo) {
				continue;
			}
			if ((pow(pointX[j], 2) / pow(bigAxis, 2) + pow(pointY[j], 2) / pow(index, 2)) > 1) {
				radiusFound = false;
			}
			littleAxis = index;


		}
		if (radiusFound)
			break;
	}
	//littleAxis += 0.499;
	littleAxis = round(littleAxis);
}


int FileSave(vector<double>& initialPoint, double &bigAxis, double &littleAxis) {
	int userchoicesavingFile;
	enum { savingFile = 1, notSavingFile };
	do {
		cout << "Введите 1, если хотите сохранить эти данные в файл." << endl;
		cout << "Введите 2, если не хотите сохранять." << endl;
		userchoicesavingFile = IntInspectionStupid();
		switch (userchoicesavingFile) {
		case (savingFile): {
			do {
				char fileName[256];
				cout << "Внимание!\n Чтобы после создания файла Вы могли его открыть, используйте"
					<< " корректные расширения файлов (.txt .doс .html и так далее)" << endl;
				cout << "Введите полный адрес файла: ";

				cin >> fileName;
				if (!CheckFileName(fileName)) {
					cout << "Запрещенное имя файла." << endl;
					continue;
				}
				ifstream fin(fileName);
				int choiceSaving;
				bool newAddress = false;
				if (!fin.is_open()) {
					do {
						if (newAddress) break;
						cout << "\nФайл не существует!" << endl;
						cout << "Нажмите 1, чтобы создать этот файл." << endl;
						cout << "Нажмите 2, чтобы заново ввести адрес файла." << endl;
						choiceSaving = IntInspectionStupid();
						enum { creatFile = 1, newAddressFile };
						switch (choiceSaving) {
						case (creatFile): {
							ofstream fout(fileName); //создать
							PrintToFile(fout, initialPoint, bigAxis, littleAxis);
							fout.close();
							cout << "Данные успешно сохранены." << endl;
							system("pause");
							return 0;
						}
						case (newAddressFile): {
							newAddress = true;
							break;
						}
						default: {
							cout << "Неверное значение. Попробуйте еще раз." << endl;
							break;
						}
						}
					} while (true);

				}
				else {
					do {
						if (newAddress)
							break;
						cout << "\nТакой файл уже существует\n";
						enum { owerwriteFile = 1, writeDownFile, newAddressFile };
						cout << "Нажмите 1, чтобы перезаписать этот файл." << endl;
						cout << "Нажмите 2, чтобы записать данные в конец файла." << endl;
						cout << "Нажмите 3, чтобы заново ввести адрес файла." << endl;
						int dataStorage = IntInspectionStupid();

						switch (dataStorage) {
						case (owerwriteFile): {
							ofstream fout(fileName, ios_base::trunc);
							PrintToFile(fout, initialPoint, bigAxis, littleAxis);
							fout.close();
							cout << "Данные успешно сохранены." << endl;
							system("pause");
							return 0;
						}
						case (writeDownFile): {
							ofstream fout(fileName, ios_base::app);
							PrintToFile(fout, initialPoint, bigAxis, littleAxis);
							fout.close();
							cout << "Данные успешно сохранены." << endl;
							system("pause");
							return 0;
						}
						case (newAddressFile): {
							newAddress = true;
							break;
						}
						default: {
							cout << "Неверное значение. Попробуйте еще раз." << endl;
							break;
						}
						}
					} while (true);
				}
			} while (true);
		}
		case (notSavingFile): {
			return 0;
		}
		default: {
			cout << "Неверное значение, попробуйте еще раз." << endl;
			break;
		}
		}
	} while (true);
};


void PrintToFile(ofstream &fout, vector<double>& initialPoint, double bigAxis, double  littleAxis, bool initial) {
	if (initial) {
		fout << initialPoint.size()/2 << " ";
		for (int i = 0; i < initialPoint.size(); i++) {
			fout << initialPoint[i] << " ";
		}
	}

	else {
		fout << "\nТочки ";
		int j = 0;
		for (int i = 0; i < initialPoint.size()/2; i++) {
			fout << "{" << initialPoint[j];
			j++;
			fout << "," << initialPoint[i] << "}   ";
			j++;
		}

		fout << "Большая полуось = ";
		if (bigAxis == 0)
			fout << "близка к 0";
		else
			fout << bigAxis;
		fout << "\nМалая полуось = ";
		if (littleAxis == 0)
			fout << "близка к 0" << endl;
		else
			fout << littleAxis << endl;
	}
};


int FileSavePoint(vector<double>& initialPoint) {
	int userchoicesavingFile;
	enum { savingFile = 1, notSavingFile };
	do {
		cout << "Введите 1, если хотите сохранить точки в файл." << endl;
		cout << "Введите 2, если не хотите сохранять." << endl;
		userchoicesavingFile = IntInspectionStupid();
		switch (userchoicesavingFile) {
		case (savingFile): {
			do {
				char fileName[256];
				cout << "Внимание!\n Чтобы после создания файла Вы могли его открыть, используйте"
					<< " корректные расширения файлов (.txt .doс .html и так далее)" << endl;
				cout << "Введите полный адрес файла: ";
				cin >> fileName;
				if (!CheckFileName(fileName)) {
					cout << "Запрещенное имя файла." << endl;
					continue;
				}
				ifstream fin(fileName);
				int choiceSaving;
				bool newAddress = false;
				if (!fin.is_open()) {
					do {
						if (newAddress) break;
						cout << "\nФайл не существует!" << endl;
						cout << "Нажмите 1, чтобы создать этот файл." << endl;
						cout << "Нажмите 2, чтобы заново ввести адрес файла." << endl;
						choiceSaving = IntInspectionStupid();
						enum { creatFile = 1, newAddressFile };
						switch (choiceSaving) {
						case (creatFile): {
							ofstream fout(fileName); //создать
							PrintToFile(fout, initialPoint, 0, 0, true);
							fout.close();
							cout << "Данные успешно сохранены." << endl;
							system("pause");
							return 0;
						}
						case (newAddressFile): {
							newAddress = true;
							break;
						}
						default: {
							cout << "Неверное значение. Попробуйте еще раз." << endl;
							break;
						}
						}
					} while (true);

				}
				else {
					do {
						if (newAddress)
							break;
						cout << "\nТакой файл уже существует\n";
						enum { owerwriteFile = 1, writeDownFile, newAddressFile };
						cout << "Нажмите 1, чтобы перезаписать этот файл." << endl;
						cout << "Нажмите 2, чтобы записать данные в конец файла." << endl;
						cout << "Нажмите 3, чтобы заново ввести адрес файла." << endl;
						int dataStorage = IntInspectionStupid();

						switch (dataStorage) {
						case (owerwriteFile): {
							ofstream fout(fileName, ios_base::trunc);
							PrintToFile(fout, initialPoint, 0, 0, true);
							fout.close();
							cout << "Данные успешно сохранены." << endl;
							system("pause");
							return 0;
						}
						case (writeDownFile): {
							ofstream fout(fileName, ios_base::app);
							PrintToFile(fout, initialPoint, 0, 0, true);
							fout.close();
							cout << "Данные успешно сохранены." << endl;
							system("pause");
							return 0;
						}
						case (newAddressFile): {
							newAddress = true;
							break;
						}
						default: {
							cout << "Неверное значение. Попробуйте еще раз." << endl;
							break;
						}
						}
					} while (true);
				}
			} while (true);
		}
		case (notSavingFile): {
			return 0;
		}
		default: {
			cout << "Неверное значение, попробуйте еще раз." << endl;
			break;
		}
		}
	} while (true);
};