#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

void Create(double* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + (double)rand() / RAND_MAX * (High - Low);
}

void Print(double* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(8) << fixed << setprecision(2) << a[i];
	cout << endl;
}

double Min(double* a, const int size)
{
	double min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}


int FirstPositiveIndex(double* a, const int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] > 0)
			return i;
	return -1;
}


int LastPositiveIndex(double* a, const int size)
{
	for (int i = size - 1; i >= 0; i--)
		if (a[i] > 0)
			return i;
	return -1;
}


double SumBetween(double* a, const int first, const int last)
{
	double s = 0;
	for (int i = first + 1; i < last; i++)
		s += a[i];
	return s;
}


double SumBetweenFirstAndLastPositive(double* a, const int size)
{
	int first = FirstPositiveIndex(a, size);
	int last = LastPositiveIndex(a, size);
	if (first == -1 || first == last)
		return 0;
	return SumBetween(a, first, last);
}


void MoveZerosToFront(double* a, const int size)
{
	int k = 0;                     
	for (int i = 0; i < size; i++)
		if (a[i] == 0)
		{
			for (int j = i; j > k; j--)   
				a[j] = a[j - 1];
			a[k] = 0;
			k++;
		}
}

int main()
{
	srand((unsigned)time(NULL));   

	int n;
	cout << "n = ";
	cin >> n;

	int Low = -5;
	int High = 5;

	double* a = new double[n];     

	Create(a, n, Low, High);
	Print(a, n);

	cout << "Min = " << Min(a, n) << endl;
	cout << "Sum = " << SumBetweenFirstAndLastPositive(a, n) << endl;

	MoveZerosToFront(a, n);
	Print(a, n);

	delete[] a;                    
	return 0;
}