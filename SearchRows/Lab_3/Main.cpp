//Поиск наибольшей подстроки в двух строках
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
	cout << "Добрый день.\nВам представлена программа, "
		"которая ищет наибольшую общую подстроку в двух строках." << endl;
	cout << "Для корректного поиска подстроки, используйте латинские символы" << endl;
	int basicUserChoice;
	bool exitmoduleTests = true;
	do {
		cout << "\nЧтобы выбрать модульные тесты, нажмите 1"
			<< "\nЧтобы ввести текст из файла, нажмите 2";
		cout << "\nЧтобы ввести текст вручную, нажмите 3"
			<< "\nЧтобы закрыть программу, нажмите 4" << endl;
		basicUserChoice = IntInspectionStupid();

		switch (basicUserChoice) {
		case moduleTests: {
			ModuleTests();
			break;
		}

		case textFromFile: {
			cout << "\n Вы выбрали меню чтения текстов из файлов." << endl;
			char fileName[256];
			cout << "Введите полный адрес первого файла: ";
			cin >> fileName;
			if (!(CheckFileName(fileName))) {
				cout << "Запрещенное имя файла." << endl;
				break;
			}
			ifstream finOne(fileName);

			if (!finOne.is_open()) // если файл не открыт
				cout << "\nФайл не может быть открыт!\n";
			else {
				cout << "Введите полный адрес второго файла: ";
				cin >> fileName;
				if (!(CheckFileName(fileName))) {
					cout << "Запрещенное имя файла." << endl;
					break;
				}
				ifstream finTwo(fileName);

				if (!finTwo.is_open()) // если файл не открыт
					cout << "\nФайл не может быть открыт!\n";
				else {
					//Тело
					int sizeOne, sizeTwo;
					cout << "Введите размер первого текста: ";
					while (!(cin >> sizeOne) || sizeOne < 1) {
						cin.clear();
						while (cin.get() != '\n');
						cout << "Некорректный размер текста." << endl;
					}

					cout << "Введите размер второго текста: ";
					while (!(cin >> sizeTwo) || sizeTwo < 1) {
						cin.clear();
						while (cin.get() != '\n');
						cout << "Некорректный размер текста." << endl;
					}
					char *textOne = new char[sizeOne + 1];
					char *textTwo = new char[sizeTwo + 1];
					int i = 0;
					char Buff;
					bool exitFile = false;

					//Cчитываем данные из 1 файла
					while (i < sizeOne) {
						if (finOne.get(Buff)) {
							if (Buff == '\n')
								Buff = ' ';
							textOne[i] = Buff;
							i++;
						}
						else {
							finOne.clear();
							cout << "Некорректный файл #1" << endl;
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

					//Cчитываем данные из 2 файла
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
							cout << "Некорректный файл #2" << endl;
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
					//Печатаем полученные строки
					cout << "#1  " << textOne << endl;
					cout << "#2  " << textTwo << endl;

					int count = -1, indexTextOne = 0, indexTextTwo = 0;
					SubstringSearch(textOne, textTwo, count, indexTextOne, indexTextTwo);
					if (count == 0) {
						cout << "Общей подстроки нет.";
						FileSaveInitial(textOne, 1);
						FileSaveInitial(textTwo, 2);
					}
					else {
						cout << "Общая последовательность, размером <"
							<< count << ">" << endl;
						cout << "Начинается с <" << indexTextOne + 1
							<< "> элемента первого текста и с <" << indexTextTwo + 1
							<< "> элемента второго текста." << endl;
						//Выделяем память подстроке на 1 больше её размера lkz \0
						char *subString = new char[count + 1];
						int j = 0;
						for (int i = indexTextOne; i < indexTextOne + count; i++) {
							subString[j] = textOne[i];
							j++;
						}
						subString[j] = '\0';

						cout << "Полученная общая строка(#3) <" << subString << ">" << endl;

						FileSaveInitial(textOne, 1);
						FileSaveInitial(textTwo, 2);
						FileSaveInitial(subString, 3);
						delete subString;
					}
					delete textOne;
					delete textTwo;
					//конец тела
				}
			}
			break;
		}
		case textPrintHands: {
			cout << "\n Вы выбрали меню ввода текста вручную." << endl;
			char *textOne = new char[256];
			char *textTwo = new char[256];
			int indexTextOne = 0, indexTextTwo = 0, count = 0;
			int i = 0;


			cout << "Введите первый текст (не больше 255 символов): ";
			cin.ignore(1);
			do {
				textOne[i] = getchar();
				i++;
			} while ((textOne[i - 1] != '\n') && i < 254);
			textOne[i] = '\0';


			i = 0;
			cout << "Введите второй текст (не больше 255 символов): ";
			do {
				textTwo[i] = getchar();
				i++;
			} while ((textTwo[i - 1] != '\n') && i < 254);
			textTwo[i] = '\0';


			cout << "#1  " << textOne << endl;
			cout << "#2  " << textTwo << endl;

			SubstringSearch(textOne, textTwo, count, indexTextOne, indexTextTwo);
			if (count == 0) {
				cout << "Общей подстроки нет.";
				FileSaveInitial(textOne, 1);
				FileSaveInitial(textTwo, 2);
			}
			else {
				cout << "Общая последовательность, размером <"
					<< count << ">" << endl;
				cout << "Начинается с <" << indexTextOne + 1
					<< "> элемента первого текста и с <" << indexTextTwo +1
					<< "> элемента второго текста." << endl;
				//Выделяем память подстроке на 1 больше её размера lkz \0
				char *subString = new char[count + 1];
				int j = 0;
				for (int i = indexTextOne; i < indexTextOne + count; i++) {
					subString[j] = textOne[i];
					j++;
				}
				subString[j] = '\0';

				cout << "Полученная общая подстрока(#3) <" << subString << ">" << endl;

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
			cout << "\nВсего хорошего." << endl;
			system("pause");
			return 0;
		}
		default: {
			cout << "Неверное значение, попробуйте еще раз" << endl;
			break;
		}
		} // конец кейсов
	} while (true);//конец программы
}

