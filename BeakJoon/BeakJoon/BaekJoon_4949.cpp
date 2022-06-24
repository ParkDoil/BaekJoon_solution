#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	stack<char> mystack;

	while(1)
	{
		bool isVPS = true;
		while (!mystack.empty())
		{
			mystack.pop();
		}

		string bracket;

		getline(cin, bracket);

		if (bracket.size() == 1 && bracket == ".")
		{
			break;
		}

		for (int j = 0; j < bracket.size(); ++j)
		{
			if (bracket[j] == '[' || bracket[j] == '(')
			{
				mystack.push(bracket[j]);
			}

			else if (bracket[j] == ']')
			{
				if (!mystack.empty() && mystack.top() == '[')
				{
					mystack.pop();
				}
				else
				{
					isVPS = false;
					break;
				}
			}

			else if (bracket[j] == ')')
			{
				if (!mystack.empty() && mystack.top() == '(')
				{
					mystack.pop();
				}
				else
				{
					isVPS = false;
					break;
				}
			}
		}

		if (mystack.empty() && isVPS)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
		
	}

	return 0;
}