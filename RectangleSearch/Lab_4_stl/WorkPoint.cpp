#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <cstring>
#include <stack>
#include  <vector>
#include "WorkPoint.h"
#include "Inspection.h"

using namespace std;

#define PI 3.14159265 

// Глобальная точка, необходимая для сортировки точек со ссылкой
// к первому пункту Используется в функции сравнения qsort ()
Point p0;
int FileSave(double *initialPoint, vector<double> points, double P, double S) {
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
							PrintToFile(fout, points, initialPoint, P, S);
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
							PrintToFile(fout, points, initialPoint, P, S);
							fout.close();
							cout << "Данные успешно сохранены." << endl;
							system("pause");
							return 0;
						}
						case (writeDownFile): {
							ofstream fout(fileName, ios_base::app);
							PrintToFile(fout, points, initialPoint, P, S);
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


void RectangleWork(double *pointX, double *pointY, int amountPoint, double &P, double &S, bool ModuleTest) {
	int i, j, indexMaxPointOne, indexMaxPointTwo, centerX, centerY;
	double tiltAngel = 0.0;
	int indexYOne, indexYTwo;
	double rectP = 0;
	for (i = 0; i < amountPoint - 1; i++) {


		//Ищем индексы наиболее удаленных друг от друга точек
		if (rectP < sqrt(pow((pointX[i] - pointX[i + 1]), 2) + pow((pointY[i] - pointY[i + 1]), 2))) {
			rectP = sqrt(pow((pointX[i] - pointX[i + 1]), 2) + pow((pointY[i] - pointY[i + 1]), 2));
			indexMaxPointOne = i;
			indexMaxPointTwo = i + 1;

		}
	}
	centerX = (pointX[indexMaxPointTwo] + pointX[indexMaxPointOne]) / 2;
	centerY = (pointY[indexMaxPointTwo] + pointY[indexMaxPointOne]) / 2;

	if (!ModuleTest)
		cout << "Центр наибольшей стороны выпуклой оболочки = " << centerX << " " << centerY << endl;

	//Угол наклона 
	if (pointY[indexMaxPointOne] != pointY[indexMaxPointTwo]) {
		tiltAngel = (pointY[indexMaxPointOne] - pointY[indexMaxPointTwo]) / (pointX[indexMaxPointOne] - pointX[indexMaxPointTwo]);
		tiltAngel = (atan(tiltAngel) * 180.0 / PI);
	}
	if (!ModuleTest)
		cout << "\nУгол между большой осью прямоугольника и ОХ: " << tiltAngel << " градусов." << endl;

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

	if (tiltAngel != 0 && tiltAngel != 90 && tiltAngel != -90)
		for (i = 0; i < amountPoint; i++) {
			double dublPoint;
			dublPoint = pointX[i];
			pointX[i] = (centerX + (pointX[i] - centerX) * cosTilt - (pointY[i] - centerY) * sinTilt);
			pointY[i] = (centerY + (pointY[i] - centerY) * cosTilt + (dublPoint - centerX) * sinTilt);
		}


	int indexRec[4] = { 0,0,0,0 };
	// 0 - самая левая
	// 1 - самая верх.
	// 2 - самая правая
	// 3 - самая ниж.

	for (i = 1; i < 4; i++) {
		if (pointX[i] < pointX[indexRec[0]])
			indexRec[0] = i;
		if (pointY[i] > pointY[indexRec[1]])
			indexRec[1] = i;
		if (pointX[i] > pointX[indexRec[2]])
			indexRec[2] = i;
		if (pointY[i] < pointY[indexRec[3]])
			indexRec[3] = i;
	}

	double *pointRecX = new double[4];
	double *pointRecY = new double[4];

	//Собираем координаты вершин прямоугольника
	pointRecX[0] = pointX[indexRec[0]];
	pointRecY[0] = pointY[indexRec[3]];

	pointRecX[1] = pointX[indexRec[0]];
	pointRecY[1] = pointY[indexRec[1]];

	pointRecX[2] = pointX[indexRec[2]];
	pointRecY[2] = pointY[indexRec[3]];

	pointRecX[3] = pointX[indexRec[2]];
	pointRecY[3] = pointY[indexRec[1]];

	//Поворачиваем назад
	tiltAngel = 360 - tiltAngel;
	intTiltAngel = tiltAngel;
	if (intTiltAngel == 90 || intTiltAngel == -90) {
		cosTilt = 0;
		sinTilt = 1;
	}
	else {
		cosTilt = cos(tiltAngel * PI / 180);
		sinTilt = sin(tiltAngel * PI / 180);
	}


	if (tiltAngel != 0 && tiltAngel != 90 && tiltAngel != -90)
		for (i = 0; i < 4; i++) {
			double dublPoint;
			dublPoint = pointRecX[i];
			pointRecX[i] = (centerX + (pointRecX[i] - centerX) * cosTilt - (pointRecY[i] - centerY) * sinTilt);
			pointRecY[i] = (centerY + (pointRecY[i] - centerY) * cosTilt + (dublPoint - centerX) * sinTilt);
		}


	//Округляем координаты в меньшую и большую сторону соответственно
	pointRecX[0] -= 0.49;
	pointRecY[0] -= 0.49;
	pointRecX[0] = round(pointRecX[0]);
	pointRecY[0] = round(pointRecY[0]);

	pointRecX[1] -= 0.49;
	pointRecX[1] = round(pointRecX[1]);
	pointRecY[1] += 0.49;
	pointRecY[1] = round(pointRecY[1]);

	pointRecY[2] -= 0.49;
	pointRecX[2] += 0.49;
	pointRecX[2] = round(pointRecX[2]);
	pointRecY[2] = round(pointRecY[2]);


	pointRecX[3] += 0.49;
	pointRecY[3] += 0.49;

	pointRecX[3] = round(pointRecX[3]);
	pointRecY[3] = round(pointRecY[3]);
	if (!ModuleTest)
		cout << "Точки находятся в прямоугольнике с координатами " << endl;
	double *pointsRec = new double[8];

	j = 0;
	for (i = 0; i < 4; i++) {
		if (pointRecX[i] == -0 || pointRecX[i] == +0)
			pointRecX[i] = 0;
		if (pointRecY[i] == -0 || pointRecY[i] == +0)
			pointRecY[i] = 0;
		if (!ModuleTest)
			cout << "[" << pointRecX[i] << "," << pointRecY[i] << "]";
		pointsRec[j] = pointRecX[i];
		j++;
		pointsRec[j] = pointRecY[i];
		j++;
	}
	if (!ModuleTest)
		cout << endl;
	double a, b;
	a = sqrt(pow(pointRecX[1] - pointRecX[0], 2) + pow(pointRecY[1] - pointRecY[0], 2));
	b = sqrt(pow(pointRecX[2] - pointRecX[0], 2) + pow(pointRecY[2] - pointRecY[0], 2));
	S = a*b;
	P = 2 * a + 2 * b;
	if (!ModuleTest) {
		cout << "Периметр прямоугольника = " << P << endl;
		cout << "Площадь прямоугольника = " << S << endl;

		vector<double> null;

		FileSave(pointsRec, null, P, S);
	}


}


void SquareWork(double *pointX, double *pointY, int amountPoint, double &P, double &S, bool ModuleTest) {
	int i, j, indexMaxPointOne, indexMaxPointTwo, centerX, centerY;
	double tiltAngel = 0.0;
	int indexYOne, indexYTwo;
	double rectP = 0;
	for (i = 0; i < amountPoint - 1; i++) {


		//Ищем индексы наиболее удаленных друг от друга точек
		if (rectP < sqrt(pow((pointX[i] - pointX[i + 1]), 2) + pow((pointY[i] - pointY[i + 1]), 2))) {
			rectP = sqrt(pow((pointX[i] - pointX[i + 1]), 2) + pow((pointY[i] - pointY[i + 1]), 2));
			indexMaxPointOne = i;
			indexMaxPointTwo = i + 1;

		}
	}
	centerX = (pointX[indexMaxPointTwo] + pointX[indexMaxPointOne]) / 2;
	centerY = (pointY[indexMaxPointTwo] + pointY[indexMaxPointOne]) / 2;

	if (!ModuleTest)
		cout << "Центр наибольшей стороны выпуклой оболочки = " << centerX << " " << centerY << endl;

	//Угол наклона 
	if (pointY[indexMaxPointOne] != pointY[indexMaxPointTwo]) {
		tiltAngel = (pointY[indexMaxPointOne] - pointY[indexMaxPointTwo]) / (pointX[indexMaxPointOne] - pointX[indexMaxPointTwo]);
		tiltAngel = (atan(tiltAngel) * 180.0 / PI);
	}
	if (!ModuleTest)
		cout << "\nУгол между большой осью квадрата и ОХ: " << tiltAngel << " градусов." << endl;

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

	if (tiltAngel != 0 && tiltAngel != 90 && tiltAngel != -90)
		for (i = 0; i < amountPoint; i++) {
			double dublPoint;
			dublPoint = pointX[i];
			pointX[i] = (centerX + (pointX[i] - centerX) * cosTilt - (pointY[i] - centerY) * sinTilt);
			pointY[i] = (centerY + (pointY[i] - centerY) * cosTilt + (dublPoint - centerX) * sinTilt);
		}

	rectP = 0;

	for (i = 0; i < amountPoint - 1; i++) {
	//Ищем индексы наиболее удаленных друг от друга точек
		if (rectP < sqrt(pow((pointX[i] - pointX[i + 1]), 2) + pow((pointY[i] - pointY[i + 1]), 2))) {
			rectP = sqrt(pow((pointX[i] - pointX[i + 1]), 2) + pow((pointY[i] - pointY[i + 1]), 2));
			indexMaxPointOne = i;
			indexMaxPointTwo = i + 1;
		}
	}


	int indexRec[4] = { 0,0,0,0 };
	// 0 - самая левая
	// 1 - самая верх.
	// 2 - самая правая
	// 3 - самая ниж.

	for (i = 1; i < 4; i++) {
		if (pointX[i] < pointX[indexRec[0]])
			indexRec[0] = i;
		if (pointY[i] > pointY[indexRec[1]])
			indexRec[1] = i;
		if (pointX[i] > pointX[indexRec[2]])
			indexRec[2] = i;
		if (pointY[i] < pointY[indexRec[3]])
			indexRec[3] = i;
	}

	double *pointRecX = new double[4];
	double *pointRecY = new double[4];

	//Собираем координаты вершин прямоугольника
	pointRecX[0] = pointX[indexRec[0]];
	pointRecY[0] = pointY[indexRec[3]];

	pointRecX[1] = pointX[indexRec[0]] ;
	pointRecY[1] = pointY[indexRec[3]] + pointX[indexRec[2]];

	pointRecX[2] = pointX[indexRec[2]];
	pointRecY[2] = pointY[indexRec[3]];

	pointRecX[3] = pointX[indexRec[2]];
	pointRecY[3] = pointY[indexRec[3]] + pointX[indexRec[2]];

	//Поворачиваем назад
	tiltAngel = 360 - tiltAngel;
	intTiltAngel = tiltAngel;
	if (intTiltAngel == 90 || intTiltAngel == -90) {
		cosTilt = 0;
		sinTilt = 1;
	}
	else {
		cosTilt = cos(tiltAngel * PI / 180);
		sinTilt = sin(tiltAngel * PI / 180);
	}


	if (tiltAngel != 0 && tiltAngel != 90 && tiltAngel != -90)
		for (i = 0; i < 4; i++) {
			double dublPoint;
			dublPoint = pointRecX[i];
			pointRecX[i] = (centerX + (pointRecX[i] - centerX) * cosTilt - (pointRecY[i] - centerY) * sinTilt);
			pointRecY[i] = (centerY + (pointRecY[i] - centerY) * cosTilt + (dublPoint - centerX) * sinTilt);
		}


	//Округляем координаты в меньшую и большую сторону соответственно
	pointRecX[0] -= 0.49;
	pointRecY[0] -= 0.49;
	pointRecX[0] = round(pointRecX[0]);
	pointRecY[0] = round(pointRecY[0]);

	pointRecX[1] -= 0.49;
	pointRecX[1] = round(pointRecX[1]);
	pointRecY[1] += 0.49;
	pointRecY[1] = round(pointRecY[1]);

	pointRecY[2] -= 0.49;
	pointRecX[2] += 0.49;
	pointRecX[2] = round(pointRecX[2]);
	pointRecY[2] = round(pointRecY[2]);


	pointRecX[3] += 0.49;
	pointRecY[3] += 0.49;

	pointRecX[3] = round(pointRecX[3]);
	pointRecY[3] = round(pointRecY[3]);
	if (!ModuleTest)
		cout << "Точки находятся в квадрате с координатами " << endl;
	double *pointsRec = new double[8];

	j = 0;
	for (i = 0; i < 4; i++) {
		if (pointRecX[i] == -0 || pointRecX[i] == +0)
			pointRecX[i] = 0;
		if (pointRecY[i] == -0 || pointRecY[i] == +0)
			pointRecY[i] = 0;
		if (!ModuleTest)
			cout << "[" << pointRecX[i] << "," << pointRecY[i] << "]";
		pointsRec[j] = pointRecX[i];
		j++;
		pointsRec[j] = pointRecY[i];
		j++;
	}
	if (!ModuleTest)
		cout << endl;
	double a;
	a = sqrt(pow(pointRecX[2] - pointRecX[0], 2) + pow(pointRecY[2] - pointRecY[0], 2));
	S = a*a;
	P = 4 * a;
	if (!ModuleTest) {
		cout << "Периметр квадрата = " << P << endl;
		cout << "Площадь квадрата = " << S << endl;

		vector<double> null;

		FileSave(pointsRec, null, P, S);
	}

}


void PrintToFile(ofstream &fout, vector<double> initialPoint, double *points,  double P, double S, bool initial ) {
	if (initial) {
		for (int i = 0; i < initialPoint.size(); i++) {
			fout << initialPoint[i] << " ";
		}
	}

	else {
		fout << "\nВершины прямоугольника ";
		int j = 0;
		for (int i = 0; i < 4; i++) {
			fout << "{" << points[j];
			j++;
			fout << "," << points[i] << "}   ";
			j++;
		}
		fout << "\nПериметр = " << P << endl;
		fout << "Площадь = " << S << endl;

	}
};


int FileSavePoint(vector<double> points) {
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
							PrintToFile(fout, points, 0, 0, 0, true);
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
							PrintToFile(fout, points, 0, 0, 0, true);
							fout.close();
							cout << "Данные успешно сохранены." << endl;
							system("pause");
							return 0;
						}
						case (writeDownFile): {
							ofstream fout(fileName, ios_base::app);
							PrintToFile(fout, points, 0, 0, 0, true);
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




// Утилита для поиска рядом с вершиной в стеке
Point nextToTop(stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

// Функция полезности для замены двух точек
void swap(Point &p1, Point &p2)
{
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

// Функция полезности для возврата квадрата расстояния
// между p1 и p2

int distSq(Point p1, Point p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y);
}

// Найти ориентацию упорядоченного триплета (p, q, r).
// Функция возвращает следующие значения
// 0 -> p, q и r коллинеарны
// 1 -> По часовой стрелке
// 2 -> против часовой стрелки
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}
// Функция, используемая библиотечной функцией qsort () для сортировки массива
// точки относительно первой точки
int compare(const void *vp1, const void *vp2)
{
	Point *p1 = (Point *)vp1;
	Point *p2 = (Point *)vp2;

	// Поиск ориентации
	int o = orientation(p0, *p1, *p2);
	if (o == 0)
		return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

	return (o == 2) ? -1 : 1;
}

// Печатает выпуклую оболочку множества из n точек.
void convexHull(vector<Point> points)
{
	// Найти ближайшую точку
	int ymin = points[0].y, min = 0;
	for (int i = 1; i < points.size(); i++)
	{
		int y = points[i].y;

		// Выберите самый нижний или выберите левый
		// Самое главное в случае связи
		if ((y < ymin) || (ymin == y &&
			points[i].x < points[min].x))
			ymin = points[i].y, min = i;
	}

	// Place the bottom-most point at first position
	swap(points[0], points[min]);

	// Отправляем n-1 точек относительно первой точки.
	// Точка p1 находится перед p2 в отсортированном выводе, если p2
	// имеет больший полярный угол (против часовой стрелки
	// направление), чем p1
	p0 = points[0];
	qsort(&points[1], points.size() - 1, sizeof(Point), compare);

	// Если две или более точки имеют одинаковый угол с p0,
	// Удалить все, кроме того, что находится дальше от p0
	// Помните, что при сортировке выше наши критерии были
	// держать самую дальнюю точку в конце, когда больше, чем
	// одно очко имеет одинаковый угол.
	int m = 1; // Инициализировать размер модифицированного массива
	for (int i = 1; i<points.size(); i++)
	{
		// Продолжаем удалять i, тогда как угол i и i + 1 одинаковый
		// по отношению к p0
		while (i < (points.size() - 1) && orientation(p0, points[i],
			points[i + 1]) == 0)
			i++;


		points[m] = points[i];
		m++;  // Обновить размер измененного массива

	}

	// Если модифицированный массив точек имеет менее 3 точек,
	// выпуклый корпус невозможен
	if (m < 3) {
		cout << "Не выполненно главное условие." << endl;
		cout << "Менее 3 точек не лежат на одной прямой." << endl;
		return;
	}

	// Создаем пустой стек и нажимаем первые три точки
	// к нему.
	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);
	int count = 3;
	// Обработка оставшихся n-3 точек
	for (int i = 3; i < m; i++)
	{
		// Продолжаем удалять верх, а угол, образованный
		// указывает точки сверху, сверху и точки [i] делает
		// без левого поворота
		while (orientation(nextToTop(S), S.top(), points[i]) != 2) {
			S.pop();
			count--;
		}
		count++;
		S.push(points[i]);
	}

	double *pointX = new double[count];
	double *pointY = new double[count];
	int rec = 0;

	cout << "Вершины выпуклой оболочки: " << endl;
	// Теперь стек имеет выходные точки, печатает содержимое стека
	while (!S.empty())
	{
		Point p = S.top();

		cout << "(" << p.x << ", " << p.y << ")" << endl;
		pointX[rec] = p.x;
		pointY[rec] = p.y;
		rec++;
		S.pop();
	}
	double p = 0, s = 0;
	cout << "Нажмите 1 если хотите построить прямоугольник." << endl;
	cout << "Нажмите 2 если хотите построить квадрат." << endl;
	int userSelect = IntInspectionStupid();
	bool select = true;
	do {
		switch (userSelect) {
		case 1: {
			RectangleWork(pointX, pointY, count, p, s);
			select = false;
			break;
		}

		case 2: {
			SquareWork(pointX, pointY, count, p, s);
			select = false;
			break;
		}
		default: {

			cout << "Неверное значение." << endl;
			break;
		}
		}
	} while (select);
}
