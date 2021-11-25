#include <iostream>
#include <cmath>

using namespace std;

double forNElement(int N, float x)
{
	return N * (N + 1) * pow(-x, N - 1) / 2;
}

float forX()
{
	float x;

	while (true)
	{
		cout << "Введите x: ";
		cin >> x;

		if (abs(x) <= 1) break;

		cout << "x должен находиться в интервале [-1; 1]" << endl;
	}
	return x;
}

int forN()
{
	int N;

	while (true)
	{
		cout << "Введите N: ";
		cin >> N;

		if (N >= 0) break;

		cout << "N не может быть меньше 0" << endl;
	}
	return N;
}

double sum(int N, float x, float e)
{
	double sum = 0;
	for (int i = 0; i <= N; i++) if (abs(forNElement(i, x)) > e) sum += forNElement(i, x);
	return sum;
}

char compare(float a, float b)
{
	float e = 0.001;
	if (b - a > e) return '<';
	else if (a - b > e) return '>';
	else return '=';
}

void firstTask()
{
	float x;
	int N;

	x = forX();
	N = forN();

	cout << "Частичная сумма ряда равна: " << sum(N, x, 0) << endl;
	cout << "Абсолютная погрешность полученного результата равна: " << fabs(1 / (pow(1 + x, 3) - sum(N, x, 0))) << endl;
	cout << "Абсолютная погрешность " << compare(fabs(1 / (pow(1 + x, 3) - sum(N, x, 0))), forNElement(N, x)) << " последнее слагаемое, включенное в частную сумму" << endl;
}

float forE()
{
	float E;
	while (true)
	{
		cout << "Введите E: ";
		cin >> E;

		if (E >= 0) break;
		
		cout << "E не может быть меньше 0" << endl;
	}
	return E;
}

int forN(float x, float E)
{
	int n = 0;
	int i = 0;
	while (fabs(forNElement(i++, x)) > E) n++;
	return n;
}

void secondTask()
{
	float x, E;

	x = forX();
	E = forE();

	cout << "Сумма слагаемых, которые по абсолютной велечине больше E, равна: " << sum(forN(x, E), x, E) << endl;
	cout << "Количевство таких слагаемых, равно: " << forN(x, E) << endl;
	cout << "Сумма всех слагаемых, больших чем Е/10, равна: " << sum(forN(x, E / 10), x, E / 10) << endl;
	cout << "Количество всех слагаемых, больших чем Е/10, равна: " << forN(x, E / 10) << endl;
}

void menu()
{
	while (true)
	{
		float check;
		cout << "1 - расчёт первой задачи;" << endl << "2 - расчёт второй задачи;" << endl << "0 - закрыть программу;" << endl << "Введите число для выбора действия: ";
		cin >> check;

		if (check == 1) firstTask();
		else if (check == 2) secondTask();
		else if (check == 0) break;
		else cout << "Введенно не коректное значение" << endl;
	}
}

int main()
{
	setlocale(0, "");
	menu();
}