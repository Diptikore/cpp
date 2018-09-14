#include <iostream>
#include <cmath>
#include <algorithm>
#include <windows.h>
using namespace std;


//http://www.programmersforum.ru/showthread.php?t=117078

struct Point //��������� ��� ������� ������ ���������
{
	double x, y;

}point_1, point_2, circle, point_3, point_4; // 
//point_1 - ������ ���� point_2 - ����� ����
//point_3 � point_4 ����� �����������
//circle - ����� ����������


 int check_intersection(double radius, struct Point circle, struct Point point_1, struct Point point_2, struct Point &point_3, struct Point &point_4) {
	 double dx01 = point_1.x - circle.x, dy01 = point_1.y - circle.y, dx12 = point_2.x - point_1.x, dy12 = point_2.y - point_1.y;
	 double a = pow(dx12, 2) + pow(dy12, 2);
	 double k = dx01 * dx12 + dy01 * dy12;
	 double c = pow(dx01, 2) + pow(dy01, 2) - pow(radius, 2);
	 double d1 = pow(k, 2) - a * c;
	 int count = 0;
	 if (d1 < 0) {
		 cout << "��� �� ���������� ����������" << endl;
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
		 cout << "��� �� ���������� ����������." << endl;
	 }
	 else if (count == 2)
		 cout << "��� ���������� ���������� � ����� (" << point_3.x << "," << point_3.y << ")." << endl;
	 else if (count == 3)
		 cout << "��� ���������� ���������� � ����� (" << point_4.x << "," << point_4.y << ")." << endl;
	 else
		 cout << "��� ���������� ���������� � ����� (" << point_3.x << "," << point_3.y << ") � � ����� (" << point_4.x 
			<< "," << point_4.y << ")." << endl;
}


//������ �� ������
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
		cout << "������ ����.\n" <<  endl;
		cout << "������ �������� ������������ ���������, ������� ��� �������� ���������� � ���� � ���������" 
			<<"\n����������, ���������� �� ��� ����������." << endl;
		int output;
		do {
			cout << "\n������� ���������� ������ ����������\n";
			cout << "x = ";
			circle.x = inspection_stupid();
			cout << "y = ";
			circle.y = inspection_stupid();

			cout << "\n ������� ������ ����������\n";
			cout << "R = ";
			radius = inspection_stupid();
			cout << "\n ������� ���������� ����� ������ ����\n";
			cout << "x = ";
			point_1.x = inspection_stupid();
			cout << "y = ";
			point_1.y = inspection_stupid();

			cout << "\n ������� ���������� ������ ����� ����\n";
			cout << "x = ";
			point_2.x = inspection_stupid();
			cout << "y = ";
			point_2.y = inspection_stupid();

			//�������� ��������� ����
			if ((point_1.x == point_2.x) && (point_1.y == point_2.y)) {
				cout << "�������� ���������� ����. ����� ���������." << endl;
			}
			else {
				check_intersection(radius, circle, point_1, point_2, point_3, point_4);
			}
			
			cout << "����� ��������� ��������� ������� 0, ����� ���������� ������� ����� ����� : ";
			output = inspection_stupid();
		} while (output != 0);

		system("pause");
		return 0;

	}
