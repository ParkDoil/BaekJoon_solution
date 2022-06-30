#include <iostream>

using namespace std;

int main()
{
	int num1, num2;

	cin >> num1 >> num2;

	int bignum = (num1 > num2 ? num1 : num2);

	int maxdiv = 0;
	int minmul = 0;


	for (int i = bignum; i > 0; --i)
	{
		if (num1 % i == 0 && num2 % i == 0)
		{
			maxdiv = i;
			break;
		}
	}

	cout << maxdiv << "\n";

	minmul = num1 * num2 / maxdiv;

	cout << minmul;

	return 0;
}