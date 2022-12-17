#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

double standart(double x);
double arcsin_n(double x, int N);
double arcsin_eps(double x, double eps);

void main()
{
	setlocale(LC_ALL, "RU");
	double x;
	printf("Введите значение x: ");
	scanf("%lf", &x);
	printf("C помощью стандартной библиотеки языка Си\n");
	standart(x);
	arcsin_n(x,	10);
	arcsin_eps(x, 100);
}
double standart(double x)
{
	if (1 >= x && x>= -1)
		printf("%lf\n", asin(x));
	else
		printf("arcsin(%lf) не существует, так как область определения функции arcsin x: -1 <= x <= 1\n", x);
}
double arcsin_n(double x, int N)
{
	double y = 0;
	double z = 1, ch=1;
	for (int i = 1; i < N; i++)
	{
		ch *= (2 * i - 1);
		z *= 2 * i;
		y += ch/z * pow(x, 2 * i + 1) /(2 * i + 1);
	}
	y += x;
	printf("%lf\n", y);
}
double arcsin_eps(double x, double eps)
{
	double y = 0;
	double ch = 1;//числитель
	double zn = 1; //знаменатель
	for (int i = 1; i < eps; i++)
	{
		if (i % 2 == 0)
			zn *= i;
		else if (i%2!=0)
		{
			y += ch / zn * pow(x, i) / i;
			ch *= i;
		}
	}
	printf("%lf\n", y);
}