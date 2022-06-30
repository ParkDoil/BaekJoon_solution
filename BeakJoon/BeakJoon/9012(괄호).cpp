#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int K;
	cin >> K;

	stack<char> mystack;
	string bracket;

	for (int i = 0; i < K; ++i)
	{
		bool isVPS = true;
		while (!mystack.empty())
		{
			mystack.pop();
		}

		cin >> bracket;

		for (int j = 0; j < bracket.size(); ++j)
		{
			if (bracket[j] == '(')
			{
				if (!mystack.empty() && mystack.top() == ')')
				{
					mystack.pop();
				}
				else
				{
					mystack.push(bracket[j]);
				}
			}
			else if(bracket[j] == ')')
			{
				if (!mystack.empty() && mystack.top() == '(')
				{
					mystack.pop();
				}
				else if (!mystack.empty())
				{
					mystack.push(bracket[j]);
				}
				else if(mystack.empty())
				{
					isVPS = false;
					mystack.push(bracket[j]);
				}
			}
		}
		
		if (mystack.empty() && isVPS)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}