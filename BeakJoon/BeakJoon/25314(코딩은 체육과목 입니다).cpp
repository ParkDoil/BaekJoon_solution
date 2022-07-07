#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int repeatCount = N / 4;

	for (int i = 0; i < repeatCount; ++i)
	{
		cout << "long ";
	}

	cout << "int\n";

	return 0;
}