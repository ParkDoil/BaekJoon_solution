#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int numeratorA = 0, denominatorA = 0;
	int numeratorB = 0, denominatorB = 0;

	cin >> numeratorA >> denominatorA;
	cin >> numeratorB >> denominatorB;

	int numeratorResult, denominatorResult;

	int gcd;
	int lcm;

	if (denominatorA == denominatorB)
	{
		numeratorResult = numeratorA + numeratorB;
		denominatorResult = denominatorA;

		int mini = min(numeratorResult, denominatorResult);
		for (int i = mini; i >= 2; --i)
		{
			if (numeratorResult % i == 0 && denominatorResult % i == 0)
			{
				numeratorResult = numeratorResult / i;
				denominatorResult = denominatorResult / i;
				break;
			}
		}
	}
	else
	{
		int bignum = (denominatorA > denominatorB ? denominatorA : denominatorB);

		for (int i = bignum; i > 0; --i)
		{
			if (denominatorA % i == 0 && denominatorB % i == 0)
			{
				gcd = i;
				break;
			}
		}

		lcm = denominatorA * denominatorB / gcd;

		numeratorResult = (numeratorA * (lcm / denominatorA)) + (numeratorB * (lcm / denominatorB));

		denominatorResult = lcm;

		int mini = min(numeratorResult, denominatorResult);
		for (int i = mini; i >= 2; --i)
		{
			if (numeratorResult % i == 0 && denominatorResult % i == 0)
			{
				numeratorResult = numeratorResult / i;
				denominatorResult = denominatorResult / i;
				break;
			}
		}
	}

	cout << numeratorResult << ' ' << denominatorResult << "\n";

	return 0;
}