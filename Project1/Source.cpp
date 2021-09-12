#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	int ch;
	
	cout << "Введите кол-во товаров : ";
	cin >> ch;
	int* summ = new int[ch];
	cout << "Введите сумму каждого из товаров\n";
	for (int i = 0; i < ch; i++)
	{
		cout << i + 1 << " товар - cтоимость = ";
		cin >> summ[i];
		cout  << endl;
	}

	for (int i = 0; i < ch - 1; i++)
		for (int j = 0; j < ch - i - 1; j++)
		if (summ[j] > summ[j + 1])
		{
			int t = summ[j];
			summ[j] = summ[j + 1];
			summ[j + 1] = t;
		}

	int* mins = new int[(ch + 1)];
	int* maxs = new int[(ch+1) / 2];

	for (int i = 0; i < ch / 2; i++)
		mins[i] = summ[i];

	int c = 0;
	for (int i = ch / 2 ; i < ch; i++)
	{
		maxs[c] = summ[i];
		c++;
	}
	int result = 0;
	for (int i = 0; i < (ch + 1) / 2; i++)
		result += maxs[i];
	cout << "Максимальная сумма чека = " << result;
	return 0;
}