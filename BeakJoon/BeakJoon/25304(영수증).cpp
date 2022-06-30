#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cout.tie(nullptr);

	int totalPrice;
	cin >> totalPrice;

	int testCase;
	cin >> testCase;

	int sumPrice = 0;
	for (int i = 0; i < testCase; ++i)
	{
		int goods, price;
		cin >> goods >> price;

		sumPrice += goods * price;
	}

	if (totalPrice == sumPrice)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}

	return 0;
}