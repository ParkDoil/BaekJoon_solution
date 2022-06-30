#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int stone;
	cin >> stone;

	cout << (stone % 2 ? "SK\n" : "CY\n");
}