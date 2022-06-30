#include <iostream>

using namespace std;

using ll = long long;



int func(ll num, ll mulCount, ll div)
{

	if (mulCount == 1)
	{
		return num % div;
	}

	ll temp = func(num, mulCount / 2, div);
	temp = temp * temp % div;

	if (mulCount % 2 == 0)
	{
		return temp;
	}
	else
	{
		return temp * num % div;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll num, multipleCount, div;

	cin >> num >> multipleCount >> div;

	cout << func(num, multipleCount, div);

	return 0;
}