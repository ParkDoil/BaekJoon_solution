#include <stdio.h>
#include <iostream>

using namespace std;


int get_gcd(int a, int b)
{
	int gcd = 1;
	int range = min(a, b);

	for (int i = range; i > 0; --i)
	{
		if (a % i == b % i)
		{
			gcd = i;
			break;
		}
	}

	return gcd;
}


int main()
{
	int N;
	scanf("%d", &N);

	int* num = new int[N];

	int gcd = 2;

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num[i]);

		if (i == 1)
		{
			gcd = get_gcd(num[i - 1], num[i]);
		}
	}


	for (int i = 2; i <= gcd; ++i)
	{
		bool isSame = true;

		for (int j = 1; j < N; ++j)
		{
			if (num[j] % i != num[0] % i)
			{
				isSame = false;
				break;
			}
		}

		if (isSame)
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}