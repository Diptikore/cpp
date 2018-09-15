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

////////////////////////////////////////////////////////



///////////////////////////////////////////////////

int main() {
	setlocale(LC_ALL, "Russian");
	int basicUserChoice;
	enum { moduleTests = 1, pointFromFile, pointPrintHands, exitProgram };

	cout << "������ ����.\n" << "������ �������� ������������ ���������, ������� ������� ����������� �������������"
		<< "\n(��� �������� ������� 3-� �� ������� �� ����� ������ �����)" << endl;

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
			double rectP = 0.0, rectS;
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
				Point *points = new Point[amountPoint];
				double *initialPoint = new double[amountPoint * 2];
				bool flagParity = true;
				int Buff;
				int i, j = 0;
				for (i = 0; i < amountPoint * 2; i++) {
					if ((fin >> Buff)) { //������� �������
						if (flagParity) {
							points[j].x = Buff;
						}
						else {
							points[j].y = Buff;
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

				convexHull(points, amountPoint);

				FileSavePoint(initialPoint, amountPoint);
				delete points;
				delete initialPoint;
			}
			/////////////////////////////

			break;
		}

		case pointPrintHands: {

			int amountPoint, i, j = 0;
			double rectP = 0, rectS;
			cout << "��������. ����� ������� 3 ����� �� ������� �� ����� ������." << endl;
			cout << "������� ���������� �����: ";
			while (!(cin >> amountPoint) || amountPoint <= 2) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "����� ������� 3 ����� . ���������� ��� ���." << endl;
			}

			Point *points = new Point[amountPoint];
			double *initialPoint = new double[amountPoint * 2];

			for (i = 0; i < amountPoint; i++) {
				cout << "������� ���������� � ����� (" << i + 1 << ") : ";
				points[i].x = DoubleInspectionStupid();
				initialPoint[j] = points[i].x;
				j++;
				cout << "������� ���������� Y ����� (" << i + 1 << ") : ";
				points[i].y = DoubleInspectionStupid();
				initialPoint[j] = points[i].y;
				j++;
			}
			convexHull(points, amountPoint);
			
			FileSavePoint(initialPoint, amountPoint);
			delete points;
			delete initialPoint;
			break;
		}

		case exitProgram: {
			cout << "�������������, �� ��� ����� �����." << endl;
			system("pause");
			return 0;
		}

		default: {
			cout << "��������, ������������ ��������. ���������� ��� ���." << endl;
			break;
		}
		}

	} while (true);
}

