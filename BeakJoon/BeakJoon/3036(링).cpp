#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int* gear = new int[N];
	
	int maxRad = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> gear[i];
		if (i == 0)
		{
			maxRad = gear[0];
		}
		if (i > 0)
		{
			if (maxRad < gear[i])
			{
				maxRad = gear[i];
			}
		}
	}

	int div;
	for (int i = 1; i < N; ++i)
	{
		div = maxRad;
		while (1)
		{
			if (gear[0] % div == 0 && gear[i] % div == 0)
			{
				cout << gear[0] / div << "/" << gear[i] / div << "\n";
				break;
			}
			--div;
		}
	}

	return 0;
}