#include <iostream>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;

	cin >> n >> m;
	ll result = 1;

	for (int i = n; i > m; --i)
	{
		result = result * i;
	}

	cout << result << "\n";

	return 0;
}