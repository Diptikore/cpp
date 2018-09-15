#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Inspection.h"

using namespace std;


void SubstringSearch(char *textOne, char *textTwo, int &test, int &indexTextOne, int &indexTextTwo) {

	int size = 0, i = 0, j = 0, dublI;
	test = -1;
	while (textOne[i] != '\n' && textOne[i] != '\0') {
		dublI = i;

		while ((textTwo[j] != '\n')) {
			if (textOne[dublI] == textTwo[j]) {

				size++;
				dublI++;
			}
			else {
				if (test < size) {
					test = size;
					indexTextTwo = j - size;
					indexTextOne = i;
				}
				size = 0;
				dublI = i;
			}

			j++;
			if (textTwo[j] == '\n' && textTwo[i] != '\0') {
				if (test < size) {
					test = size;
					indexTextTwo = j - size;
					indexTextOne = i;
				}
				size = 0;
				dublI = i;
			}
		}
		j = 0;
		size = 0;
		i++;

	}

}

int FileSaveInitial(char *text, int number) {
	int userchoiceSavingFile;
	enum { SavingFile = 1, NotSavingFile };
	do {
		cout << "\nВведите 1, если хотите сохранить текст #"
			<< number << " в файл." << endl;
		cout << "Введите 2, если не хотите сохранять." << endl;
		userchoiceSavingFile = IntInspectionStupid();
		switch (userchoiceSavingFile) {
		case (SavingFile): {
			do {
				char fileName[256];
				cout << "Введите полный адрес файла: ";
				cin >> fileName;
				if (!(CheckFileName(fileName))) {
					cout << "Запрещенное имя файла." << endl;
					break;
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
							fout << text;
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
						enum { OwerwriteFile = 1, WriteDownFile, newAddressFile };
						cout << "Нажмите 1, чтобы перезаписать этот файл." << endl;
						cout << "Нажмите 2, чтобы записать данные в конец файла." << endl;
						cout << "Нажмите 3, чтобы заново ввести адрес файла." << endl;
						int DataStorage = IntInspectionStupid();

						switch (DataStorage) {
						case (OwerwriteFile): {
							ofstream fout(fileName, ios_base::trunc);
							fout << text;
							fout.close();
							cout << "Данные успешно сохранены." << endl;
							system("pause");
							return 0;
						}
						case (WriteDownFile): {
							ofstream fout(fileName, ios_base::app);
							fout << "\n" << text;
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
		case (NotSavingFile): {
			return 0;
		}
		default: {
			cout << "Неверное значение, попробуйте еще раз." << endl;
			break;
		}
		}
	} while (true);
};
