#include <iostream>
#include <cmath>
#include <algorithm>
#include <windows.h>
using namespace std;


//http://www.programmersforum.ru/showthread.php?t=117078

struct Point //Структура для удобной записи координат
{
	double x, y;

}point_1, point_2, circle, point_3, point_4; // 
//point_1 - начало луча point_2 - точка луча
//point_3 и point_4 точки пересечения
//circle - центр окрудности


 int check_intersection(double radius, struct Point circle, struct Point point_1, struct Point point_2, struct Point &point_3, struct Point &point_4) {
	 double dx01 = point_1.x - circle.x, dy01 = point_1.y - circle.y, dx12 = point_2.x - point_1.x, dy12 = point_2.y - point_1.y;
	 double a = pow(dx12, 2) + pow(dy12, 2);
	 double k = dx01 * dx12 + dy01 * dy12;
	 double c = pow(dx01, 2) + pow(dy01, 2) - pow(radius, 2);
	 double d1 = pow(k, 2) - a * c;
	 int count = 0;
	 if (d1 < 0) {
		 cout << "Луч не пересекает окружность" << endl;
		 return 0;
	 }
	 else if (fabs(d1) < 0)
	 {
		 float t = -k / a;
		 point_3.x = point_1.x + t * dx12;
		 point_3.y = point_1.y + t * dy12;

		 if ((((point_1.x >= point_3.x) && (point_1.y >= point_3.y)) && ((point_1.x > point_2.x) && (point_1.y > point_2.y)))
			 || (((point_1.x <= point_3.x) && (point_1.y <= point_3.y)) && ((point_1.x < point_2.x) && (point_1.y < point_2.y)))) {
			 count++;
			 
		 }
	 }
	 else {
		 double t1 = (-k + sqrt(d1)) / a, t2 = (-k - sqrt(d1)) / a;
		 if (t1 > t2)
			 swap(t1, t2);
		 point_3.x = point_1.x + t1 * dx12;
		 point_3.y = point_1.y + t1 * dy12;
		 point_4.x = point_1.x + t2 * dx12;
		 point_4.y = point_1.y + t2 * dy12;
		 if ((((point_1.x >= point_3.x) && (point_1.x >= point_2.x)) || ((point_1.x <= point_3.x) && (point_1.x <= point_2.x))) &&
			 (((point_1.y >= point_3.y) && (point_1.y >= point_2.y)) || ((point_1.y <= point_3.y) && (point_1.y <= point_2.y))))
			 count +=2;
		 if ((((point_1.x >= point_4.x) && (point_1.x >= point_2.x)) || ((point_1.x <= point_4.x) && (point_1.x <= point_2.x))) &&
			 (((point_1.y >= point_4.y) && (point_1.y >= point_2.y)) || ((point_1.y <= point_4.y) && (point_1.y <= point_2.y))))
			 count +=3;
	 }
	 if (count == 0) {
		 cout << "Луч не пересекает окружность." << endl;
	 }
	 else if (count == 2)
		 cout << "Луч пересекает окружность в точке (" << point_3.x << "," << point_3.y << ")." << endl;
	 else if (count == 3)
		 cout << "Луч пересекает окружность в точке (" << point_4.x << "," << point_4.y << ")." << endl;
	 else
		 cout << "Луч пересекает окружность в точке (" << point_3.x << "," << point_3.y << ") и в точке (" << point_4.x 
			<< "," << point_4.y << ")." << endl;
}


//Защита от дурака
double inspection_stupid() {
	double value;
	while (!(cin >> value))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Invalid input. Repeat." << endl;
	}
	return value;
};


	int main() {
		setlocale(LC_ALL, "RUS");
		double radius;
		cout << "Добрый день.\n" <<  endl;
		cout << "Вашему вниманию представлена программа, которая для заданной окружности и луча в плоскости" 
			<<"\nопределяет, пересекает ли луч окружность." << endl;
		int output;
		do {
			cout << "\nВведите координаты центра окружности\n";
			cout << "x = ";
			circle.x = inspection_stupid();
			cout << "y = ";
			circle.y = inspection_stupid();

			cout << "\n Введите радиус окружности\n";
			cout << "R = ";
			radius = inspection_stupid();
			cout << "\n Введите координаты точки начала луча\n";
			cout << "x = ";
			point_1.x = inspection_stupid();
			cout << "y = ";
			point_1.y = inspection_stupid();

			cout << "\n Введите координаты другой точки луча\n";
			cout << "x = ";
			point_2.x = inspection_stupid();
			cout << "y = ";
			point_2.y = inspection_stupid();

			//Проверка координат луча
			if ((point_1.x == point_2.x) && (point_1.y == point_2.y)) {
				cout << "Неверные координаты луча. Точки совпадают." << endl;
			}
			else {
				check_intersection(radius, circle, point_1, point_2, point_3, point_4);
			}
			
			cout << "Чтобы завершить программу введите 0, чтобы продолжить введите любое число : ";
			output = inspection_stupid();
		} while (output != 0);

		system("pause");
		return 0;

	}
