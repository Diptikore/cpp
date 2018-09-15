//����� ���������� ��������� � ���� �������
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Inspection.h"
#include "WorkFile.h"
#include "ModuleTest.h"

using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");
	enum { moduleTests = 1, textFromFile, textPrintHands, exitProgram };
	cout << "������ ����.\n��� ������������ ���������, "
		"������� ���� ���������� ����� ��������� � ���� �������." << endl;
	cout << "��� ����������� ������ ���������, ����������� ��������� �������" << endl;
	int basicUserChoice;
	bool exitmoduleTests = true;
	do {
		cout << "\n����� ������� ��������� �����, ������� 1"
			<< "\n����� ������ ����� �� �����, ������� 2";
		cout << "\n����� ������ ����� �������, ������� 3"
			<< "\n����� ������� ���������, ������� 4" << endl;
		basicUserChoice = IntInspectionStupid();

		switch (basicUserChoice) {
		case moduleTests: {
			ModuleTests();
			break;
		}

		case textFromFile: {
			cout << "\n �� ������� ���� ������ ������� �� ������." << endl;
			char fileName[256];
			cout << "������� ������ ����� ������� �����: ";
			cin >> fileName;
			if (!(CheckFileName(fileName))) {
				cout << "����������� ��� �����." << endl;
				break;
			}
			ifstream finOne(fileName);

			if (!finOne.is_open()) // ���� ���� �� ������
				cout << "\n���� �� ����� ���� ������!\n";
			else {
				cout << "������� ������ ����� ������� �����: ";
				cin >> fileName;
				if (!(CheckFileName(fileName))) {
					cout << "����������� ��� �����." << endl;
					break;
				}
				ifstream finTwo(fileName);

				if (!finTwo.is_open()) // ���� ���� �� ������
					cout << "\n���� �� ����� ���� ������!\n";
				else {
					//����
					int sizeOne, sizeTwo;
					cout << "������� ������ ������� ������: ";
					while (!(cin >> sizeOne) || sizeOne < 1) {
						cin.clear();
						while (cin.get() != '\n');
						cout << "������������ ������ ������." << endl;
					}

					cout << "������� ������ ������� ������: ";
					while (!(cin >> sizeTwo) || sizeTwo < 1) {
						cin.clear();
						while (cin.get() != '\n');
						cout << "������������ ������ ������." << endl;
					}
					char *textOne = new char[sizeOne + 1];
					char *textTwo = new char[sizeTwo + 1];
					int i = 0;
					char Buff;
					bool exitFile = false;

					//C�������� ������ �� 1 �����
					while (i < sizeOne) {
						if (finOne.get(Buff)) {
							if (Buff == '\n')
								Buff = ' ';
							textOne[i] = Buff;
							i++;
						}
						else {
							finOne.clear();
							cout << "������������ ���� #1" << endl;
							exitFile = true;
							break;
						}
						if (exitFile)
							break;
					}
					finOne.close();
					if (exitFile)
						break;
					textOne[i] = '\0';

					//C�������� ������ �� 2 �����
					i = 0;
					while (i < sizeTwo) {
						if (finTwo.get(Buff)) {
							if (Buff == '\n')
								Buff = ' ';
							textTwo[i] = Buff;
							i++;
						}
						else {
							finTwo.clear();
							cout << "������������ ���� #2" << endl;
							exitFile = true;
							break;
						}
						if (exitFile)
							break;
					}
					finTwo.close();
					if (exitFile)
						break;
					textTwo[i] = '\0';
					//�������� ���������� ������
					cout << "#1  " << textOne << endl;
					cout << "#2  " << textTwo << endl;

					int count = -1, indexTextOne = 0, indexTextTwo = 0;
					SubstringSearch(textOne, textTwo, count, indexTextOne, indexTextTwo);
					if (count == 0) {
						cout << "����� ��������� ���.";
						FileSaveInitial(textOne, 1);
						FileSaveInitial(textTwo, 2);
					}
					else {
						cout << "����� ������������������, �������� <"
							<< count << ">" << endl;
						cout << "���������� � <" << indexTextOne + 1
							<< "> �������� ������� ������ � � <" << indexTextTwo + 1
							<< "> �������� ������� ������." << endl;
						//�������� ������ ��������� �� 1 ������ � ������� lkz \0
						char *subString = new char[count + 1];
						int j = 0;
						for (int i = indexTextOne; i < indexTextOne + count; i++) {
							subString[j] = textOne[i];
							j++;
						}
						subString[j] = '\0';

						cout << "���������� ����� ������(#3) <" << subString << ">" << endl;

						FileSaveInitial(textOne, 1);
						FileSaveInitial(textTwo, 2);
						FileSaveInitial(subString, 3);
						delete subString;
					}
					delete textOne;
					delete textTwo;
					//����� ����
				}
			}
			break;
		}
		case textPrintHands: {
			cout << "\n �� ������� ���� ����� ������ �������." << endl;
			char *textOne = new char[256];
			char *textTwo = new char[256];
			int indexTextOne = 0, indexTextTwo = 0, count = 0;
			int i = 0;


			cout << "������� ������ ����� (�� ������ 255 ��������): ";
			cin.ignore(1);
			do {
				textOne[i] = getchar();
				i++;
			} while ((textOne[i - 1] != '\n') && i < 254);
			textOne[i] = '\0';


			i = 0;
			cout << "������� ������ ����� (�� ������ 255 ��������): ";
			do {
				textTwo[i] = getchar();
				i++;
			} while ((textTwo[i - 1] != '\n') && i < 254);
			textTwo[i] = '\0';


			cout << "#1  " << textOne << endl;
			cout << "#2  " << textTwo << endl;

			SubstringSearch(textOne, textTwo, count, indexTextOne, indexTextTwo);
			if (count == 0) {
				cout << "����� ��������� ���.";
				FileSaveInitial(textOne, 1);
				FileSaveInitial(textTwo, 2);
			}
			else {
				cout << "����� ������������������, �������� <"
					<< count << ">" << endl;
				cout << "���������� � <" << indexTextOne + 1
					<< "> �������� ������� ������ � � <" << indexTextTwo +1
					<< "> �������� ������� ������." << endl;
				//�������� ������ ��������� �� 1 ������ � ������� lkz \0
				char *subString = new char[count + 1];
				int j = 0;
				for (int i = indexTextOne; i < indexTextOne + count; i++) {
					subString[j] = textOne[i];
					j++;
				}
				subString[j] = '\0';

				cout << "���������� ����� ���������(#3) <" << subString << ">" << endl;

				FileSaveInitial(textOne, 1);
				FileSaveInitial(textTwo, 2);
				FileSaveInitial(subString, 3);
				delete subString;
			}
			delete textOne;
			delete textTwo;

			break;
		}
		case exitProgram: {
			cout << "\n����� ��������." << endl;
			system("pause");
			return 0;
		}
		default: {
			cout << "�������� ��������, ���������� ��� ���" << endl;
			break;
		}
		} // ����� ������
	} while (true);//����� ���������
}

