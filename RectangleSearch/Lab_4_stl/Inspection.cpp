#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX_LENGTH = 255;

int IntInspectionStupid() {
	int value;
	while (!(cin >> value)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Invalid input. Repeat." << endl;
	}
	return value;
};


double DoubleInspectionStupid() {
	double value;
	while (!(cin >> value)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Invalid input. Repeat." << endl;
	}
	return value;
};


bool InspectionPoint(double *pointX, double *pointY, int amountPoint) {
	int  i;
	for (i = 2; i < amountPoint; i++)
		if (!(((pointX[0] - pointX[i])*(pointY[1] - pointY[0]) - (pointX[1] - pointX[0])*(pointY[0] - pointY[i])) == 0))
			return true;
	return false;

}

// Функция проверки корректности имени файла; 
// Параметры: path - путь файла; 

// Структура пути файла; 
struct File_path {
	char *full_name = new char;
	char name[255] = {};
	char *expansion = new char;
};
// Функция проверки символа; 
// Параметры: t - символ для проверки; 
bool CheckChar(char t) {
	if ((t >= '0' && t <= '9') ||
		(t >= 'A' && t <= 'Z') ||
		(t >= 'a' && t <= 'z') ||
		(t >= 'А' && t <= 'Я') ||
		(t >= 'а' && t <= 'я'))
		return 1;
	else
		return 0;
}

bool CheckFileName(char path[]) {
	setlocale(LC_ALL, "Russian");
	char *reserved_names[] = { "CON", "PRN", "AUX", "NUL", "COM1",
		"COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8",
		"COM9", "LPT1", "LPT2", "LPT3", "LPT4", "LPT5", "LPT6",
		"LPT7", "LPT8", "LPT9" };
	File_path file;
	bool is_correct_name = false;
	int index_rslash = 0;
	int index_dot = 0;
	// Длина строки пути файла; 
	int length = strlen(path) - 1;
	// Индексы последнего вхождения '/' и '.'; 
	for (index_rslash = length; path[index_rslash] != '\\' && index_rslash > 0; index_rslash--);
	for (index_dot = length; path[index_dot] != '.' && index_dot > 0; index_dot--);
	// Парсинг пути файла; 

	if (index_rslash != index_dot &&
		index_rslash < index_dot &&
		CheckChar(path[0])) {
		// Решение: относительно какого индекса выделять имя 
		if (index_rslash == 0)
			file.full_name = &path[0];
		else
			file.full_name = &path[index_rslash + 1];
		// Формируем имя файла; 
		for (int i = 0; i < strrchr(file.full_name, '.') - file.full_name; i++)
			file.name[i] = file.full_name[i];
		// Формируем расширение файла; 
		file.expansion = &path[index_dot + 1];
		for (int i = 0; i < sizeof(reserved_names) / sizeof(*reserved_names); i++) {
			if (!_stricmp(file.name, reserved_names[i])) {
				is_correct_name = false;
				break;
			}
		}
		return 1;
	}
	return is_correct_name;
};