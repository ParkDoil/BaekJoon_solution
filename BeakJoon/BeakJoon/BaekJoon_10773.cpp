#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int K;
	cin >> K;

	int element;
	stack<int> mystack;

	for (int i = 0; i < K; ++i)
	{
		cin >> element;
		if (element == 0)
		{
			mystack.pop();
		}
		else
		{
			mystack.push(element);
		}
	}

	int result = 0;
	while (!mystack.empty())
	{
		result += mystack.top();
		mystack.pop();
	}

	cout << result << "\n";

	return 0;
}