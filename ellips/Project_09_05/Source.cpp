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

	cout << "������ ����.\n" << "������ �������� ������������ ���������, ������� ������������ ����������� ������ �������� �������"
		<< "\n��� �������� ������� 3 �� ������� �� ����� ������ �����)" << endl;
	
	do {
		cout << "\n����� �������� ��������� ����� - ������� 1" << endl;
		cout << "����� ����� ���������� �� ����� - ������� 2" << endl;
		cout << "����� ������ ���������� ������� - ������� 3" << endl;
		cout << "����� ������� ��������� - ������� 4" << endl;

		basicUserChoice = IntInspectionStupid();

		switch (basicUserChoice) {
		case moduleTests: {
			ModuleTests();
			
			break;
		}

		case pointFromFile: {
			cout << "��������!\n" << "������ ����� � ����� - ���������� �����.\n"
				<< "���� ������ �������� ������ �� ����� (������ ����� N ������ ���������� ����� � ����� 2N �����."
				<< "\nX(1) Y(1) X(2) Y(2) ... X(N) Y(N)\n"
				<< "\n ��������. ���������� ����� �� ������ ���� ������ 3!" << endl;

			char fileName[256];
			int amountPoint;
			double bigAxis = 0.0, littleAxis;
			double tiltAngel = 0.0;
			cout << "������� ������ ����� �����: ";
			cin >> fileName;

			if (!CheckFileName(fileName)) {
				cout << "����������� ��� �����." << endl;
				break;
			}

			ifstream fin(fileName);
			if (!fin.is_open()) // ���� ���� �� ������
				cout << "\n���� �� ����� ���� ������!\n";
			else {
				if ((fin >> amountPoint) && (amountPoint > 2)) {
					cout << "���������� �����: " << amountPoint << endl;
				}
				else {
					cout << "������������ ���������� �����" << endl;
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
					if ((fin >> Buff)) { //������� �������
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
						cout << "������������ ����." << endl;
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
					cout << "��������, ����� �� ��������� �������, ������� ��� ����� �� ������ ������ �� ����� ������." << endl;
				}
				else {
					EllipHavi(pointX, pointY, amountPoint, bigAxis, littleAxis);
					cout << "������� ������� = " << bigAxis << "\n����� ������� = " << littleAxis << endl;
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
			cout << "��������. ����� ������� 3 ����� �� ������� �� ����� ������." << endl;
			cout << "������� ���������� �����: ";
			while (!(cin >> amountPoint) || amountPoint <= 2) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "����� ������� 3 ����� . ���������� ��� ���." << endl;
			}

			double *pointX = new double[amountPoint];
			double *pointY = new double[amountPoint];
			double *initialPoint = new double[amountPoint * 2];

			for (i = 0; i < amountPoint; i++) {
				cout << "������� ���������� � ����� (" << i + 1 << ") : ";
				pointX[i] = DoubleInspectionStupid();
				initialPoint[j] = pointX[i];
				j++;
				cout << "������� ���������� Y ����� (" << i + 1 << ") : ";
				pointY[i] = DoubleInspectionStupid();
				initialPoint[j] = pointY[i];
				j++;
			}
			if (!(InspectionPoint(pointX, pointY, amountPoint))) {
				cout << "��������, ����� �� ��������� �������, ������� ��� ����� �� ������ ������ �� ����� ������." << endl;
			}
			else {
				EllipHavi(pointX, pointY, amountPoint, bigAxis, littleAxis);
				
				cout << "������� ������� = ";
				if (bigAxis == 0)
					cout << "������ � 0";
				else
					cout << bigAxis;
				cout << "\n����� ������� = ";
				if (littleAxis == 0)
					cout << "������ � 0" << endl;
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
			cout << "�������������, �� ��� ����� �����." << endl;
			system("pause");
			return 0;
		}

		default: {
			cout << "��������, �� ���������� ��������. ���������� ��� ���." << endl;
			break;
		}
		}

	} while (true);
}

