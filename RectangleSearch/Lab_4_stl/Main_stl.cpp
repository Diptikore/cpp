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
				<< "���� ������ �������� ������ �� �����"
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
				bool exitFile = false;
				Point p;
				vector<Point> points;

				vector<double> initialPoint;
				bool flagParity = true;
				int Buff;
				int i, j = 0;
				for (i = 0; ; i++) {
					if ((fin >> Buff)) { //������� �������
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
						cout << "������������ ����." << endl;
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
			cout << "��������. ����� ������� 3 ����� �� ������� �� ����� ������." << endl;
			Point p;
			vector<Point> points;

			vector<double> initialPoint;

			do {
				int value;
				cout << "������� ���������� � ����� (" << i + 1 << ") : ";
				p.x = DoubleInspectionStupid();
				initialPoint.push_back(p.x);
				cout << "������� ���������� Y ����� (" << i + 1 << ") : ";
				p.y = DoubleInspectionStupid();
				points.push_back(p);
				initialPoint.push_back(p.y);

				if (i > 1) {
					cout << "���� ������ ������ ��� �����, ������� ����� ������ �����..\n���� ��� ���������� ���� �����, ������� 1" << endl;
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

