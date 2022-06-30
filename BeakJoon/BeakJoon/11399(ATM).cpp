#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>;

using namespace std;

int person[1000] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> person[i];
	}

	sort(person, person + N);

	int resultTime = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			resultTime += person[j];
		}
	}

	cout << resultTime << "\n";
}