#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	string commend;
	int element;
	stack<int> mystack;

	for (int i = 0; i < N; ++i)
	{
		cin >> commend;
		if (commend == "push")
		{
			cin >> element;
			mystack.push(element);
		}

		else if (commend == "top")
		{
			if (mystack.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << mystack.top() << "\n";
			}
		}
		
		else if (commend == "size")
		{
			cout << mystack.size() << "\n";
		}

		else if (commend == "pop")
		{
			if (mystack.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << mystack.top() << "\n";
				mystack.pop();
			}
		}

		else if (commend == "empty")
		{
			if (mystack.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
	}

	return 0;
}