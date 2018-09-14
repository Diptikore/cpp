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
				<< "���� ������ �������� ������ �� �����"
				<< "\nX(1) Y(1) X(2) Y(2) ... X(N) Y(N)\n"
				<< "\n ��������. ���������� ����� �� ������ ���� ������ 3!" << endl;

			char fileName[256];
			int amountPoint;
			int j = 0;
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
				bool exitFile = false;
				vector<double> pointX;
				vector<double> pointY;
				vector<double> initialPoint;
				bool flagParity = true;
				int Buff;
				int i;
				for (i = 0; ; i++) {
					if ((fin >> Buff)) { //������� �������
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
				if (!(InspectionPoint(pointX, pointY))) {
					cout << "��������, ����� �� ��������� �������, ������� ��� ����� �� ������ ������ �� ����� ������." << endl;
				}
				else {
					EllipHavi(pointX, pointY, bigAxis, littleAxis);
					cout << "������� ������� = " << bigAxis << "\n����� ������� = " << littleAxis << endl;
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

			cout << "��������. ����� ������� 3 ����� �� ������� �� ����� ������." << endl;
			do {
				cout << "������� ���������� � ����� (" << i + 1 << ") : ";
				value = DoubleInspectionStupid();
				pointX.push_back(value);
				initialPoint.push_back(value);

				cout << "������� ���������� Y ����� (" << i + 1 << ") : ";
				value = DoubleInspectionStupid();
				pointY.push_back(value);
				initialPoint.push_back(value);


				if (i > 1) {
					cout << "���� ������ ������ ��� �����, ������� ����� ������ �����..\n���� ��� ���������� ���� �����, ������� 1" << endl;
					value = IntInspectionStupid();
					if (value == 1)
						break;
				}
				i++;

			} while (true);


		
			if (!(InspectionPoint(pointX, pointY))) {
				cout << "��������, ����� �� ��������� �������, ������� ��� ����� �� ������ ������ �� ����� ������." << endl;
			}
			else {
				EllipHavi(pointX, pointY, bigAxis, littleAxis);

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
				FileSave(initialPoint, bigAxis, littleAxis);
				FileSavePoint(initialPoint);
			}
			
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

//������ � ������ ������� ��������, ���������� ������� ��� ���� ���������� ��������
